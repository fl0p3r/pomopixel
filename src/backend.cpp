#include "backend.h"
#include "configmanager.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QProcess>
#include <QStandardPaths>

Backend::Backend(ConfigManager *config, QObject *parent)
    : QObject(parent), m_config(config) {
    m_today = QDate::currentDate();

    QString dataDir = QDir::homePath() + "/.local/share/pomopixel";
    QDir().mkpath(dataDir);
    m_statsFile = dataDir + "/stats.json";

    loadStats();

    connect(&m_timer, &QTimer::timeout, this, &Backend::onTick);
    m_timer.setInterval(1000);

    if (m_config) {
        connect(m_config, &ConfigManager::changed, this, &Backend::onConfigChanged);
    }

    applyModeDurations();
}

QString Backend::modeName() const {
    switch (m_mode) {
    case ModeFocus:
        return "FOCUS TIME";
    case ModeShortBreak:
        return "SHORT BREAK";
    case ModeLongBreak:
        return "LONG BREAK";
    }
    return "POMODORO";
}

QString Backend::formattedTime() const {
    int minutes = m_secondsRemaining / 60;
    int seconds = m_secondsRemaining % 60;
    return QString("%1:%2")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));
}

qreal Backend::progress() const {
    if (m_totalSeconds <= 0)
        return 0.0;
    qreal passed = m_totalSeconds - m_secondsRemaining;
    return qBound(0.0, passed / static_cast<qreal>(m_totalSeconds), 1.0);
}

void Backend::applyModeDurations() {
    int durationMinutes = 25;
    if (m_config) {
        switch (m_mode) {
        case ModeFocus:
            durationMinutes = m_config->focusDuration();
            break;
        case ModeShortBreak:
            durationMinutes = m_config->shortBreakDuration();
            break;
        case ModeLongBreak:
            durationMinutes = m_config->longBreakDuration();
            break;
        }
    }
    m_totalSeconds = durationMinutes * 60;
    m_secondsRemaining = m_totalSeconds;
    emit timerTicked();
    emit modeChanged();
}

void Backend::onConfigChanged() {
    if (!m_isRunning) {
        applyModeDurations();
    }
}

void Backend::toggle() {
    if (m_isRunning) {
        pause();
    } else {
        start();
    }
}

void Backend::start() {
    if (!m_isRunning) {
        m_isRunning = true;
        m_timer.start();
        emit runningChanged();
        playAudio("start");
    }
}

void Backend::pause() {
    if (m_isRunning) {
        m_isRunning = false;
        m_timer.stop();
        emit runningChanged();
        playAudio("click");
    }
}

void Backend::reset() {
    m_timer.stop();
    m_isRunning = false;
    emit runningChanged();
    applyModeDurations();
    playAudio("click");
}

void Backend::skip() {
    m_timer.stop();
    m_isRunning = false;
    emit runningChanged();

    if (m_mode == ModeFocus) {
        m_consecutiveFocusCycles++;
        int interval = m_config ? m_config->longBreakInterval() : 4;
        if (m_consecutiveFocusCycles >= interval) {
            m_mode = ModeLongBreak;
            m_consecutiveFocusCycles = 0;
        } else {
            m_mode = ModeShortBreak;
        }
    } else {
        m_mode = ModeFocus;
    }

    applyModeDurations();
    playAudio("click");
}

void Backend::setMode(int mode) {
    if (mode < 0 || mode > 2 || mode == m_mode)
        return;
    m_timer.stop();
    m_isRunning = false;
    m_mode = static_cast<Mode>(mode);
    emit runningChanged();
    applyModeDurations();
    playAudio("click");
}

void Backend::playClick() {
    playAudio("click");
}

void Backend::onTick() {
    if (m_secondsRemaining > 0) {
        m_secondsRemaining--;
        emit timerTicked();
    }

    if (m_secondsRemaining <= 0) {
        timerFinished();
    }
}

void Backend::timerFinished() {
    m_timer.stop();
    m_isRunning = false;
    emit runningChanged();

    playAudio("finish");

    if (m_mode == ModeFocus) {
        m_completedCycles++;
        m_consecutiveFocusCycles++;
        saveStats();
        emit statsChanged();

        sendNotification("Pomopixel", "Focus session complete! Take a well-deserved rest.");

        int interval = m_config ? m_config->longBreakInterval() : 4;
        if (m_consecutiveFocusCycles >= interval) {
            m_mode = ModeLongBreak;
            m_consecutiveFocusCycles = 0;
        } else {
            m_mode = ModeShortBreak;
        }

        applyModeDurations();
        if (m_config && m_config->autoStartBreaks()) {
            start();
        }
    } else {
        sendNotification("Pomopixel", "Break is over! Ready to focus?");
        m_mode = ModeFocus;
        applyModeDurations();
        if (m_config && m_config->autoStartFocus()) {
            start();
        }
    }
}

void Backend::playAudio(const QString &type) {
    if (!m_config || !m_config->soundEnabled())
        return;

    QString soundPath;
    if (type == "finish")
        soundPath = m_config->finishSound();
    else if (type == "start")
        soundPath = m_config->startSound();
    else if (type == "click")
        soundPath = m_config->clickSound();

    if (soundPath.isEmpty() || !QFileInfo::exists(soundPath)) {
        // Fallback search in standard paths
        QStringList candidates = {
            "/usr/share/pomopixel/sounds/" + type + ".wav",
            QDir::homePath() + "/.local/share/pomopixel/sounds/" + type + ".wav",
            QCoreApplication::applicationDirPath() + "/../assets/" + type + ".wav",
            QCoreApplication::applicationDirPath() + "/assets/" + type + ".wav"
        };
        for (const auto &c : candidates) {
            if (QFileInfo::exists(c)) {
                soundPath = c;
                break;
            }
        }
    }

    if (!soundPath.isEmpty() && QFileInfo::exists(soundPath)) {
        qreal vol = m_config ? m_config->volume() : 0.8;
        vol = qBound(0.0, vol, 1.0);

        QString player = QStandardPaths::findExecutable("pw-play");
        if (!player.isEmpty()) {
            QProcess::startDetached(player, {
                "--volume",
                QString::number(vol, 'f', 2),
                soundPath
            });
        } else {
            player = QStandardPaths::findExecutable("paplay");
            if (!player.isEmpty()) {
                int paVol = static_cast<int>(vol * 65536);
                QProcess::startDetached(player, {
                    QString("--volume=%1").arg(paVol),
                    soundPath
                });
            }
        }
    }
}

void Backend::sendNotification(const QString &title, const QString &body) {
    if (!m_config || !m_config->notificationsEnabled())
        return;

    QString notifySend = QStandardPaths::findExecutable("notify-send");
    if (!notifySend.isEmpty()) {
        QProcess::startDetached(notifySend, {
            "-a", "Pomopixel",
            "-i", "pomopixel",
            "-u", "normal",
            title,
            body
        });
    }
}

void Backend::loadStats() {
    QFile file(m_statsFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        m_completedCycles = 0;
        return;
    }

    QJsonObject obj = QJsonDocument::fromJson(file.readAll()).object();
    QString savedDate = obj.value("date").toString();
    QString todayStr = m_today.toString(Qt::ISODate);

    if (savedDate == todayStr) {
        m_completedCycles = obj.value("completed").toInt(0);
    } else {
        m_completedCycles = 0;
    }
}

void Backend::saveStats() {
    QJsonObject obj;
    obj["date"] = m_today.toString(Qt::ISODate);
    obj["completed"] = m_completedCycles;

    QFile file(m_statsFile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        file.write(QJsonDocument(obj).toJson(QJsonDocument::Compact));
    }
}
