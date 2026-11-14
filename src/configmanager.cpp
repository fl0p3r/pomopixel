#include "configmanager.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QStandardPaths>

ConfigManager::ConfigManager(QObject *parent)
    : QObject(parent) {
    m_configDir = QDir::homePath() + "/.config/pomopixel";
    m_configFile = m_configDir + "/config.json";

    QDir().mkpath(m_configDir);

    m_debounce.setSingleShot(true);
    m_debounce.setInterval(150);
    connect(&m_watcher, &QFileSystemWatcher::fileChanged, this, [this] { m_debounce.start(); });
    connect(&m_debounce, &QTimer::timeout, this, &ConfigManager::loadConfig);

    if (!QFileInfo::exists(m_configFile)) {
        createDefaultConfig(m_configFile);
    }

    loadConfig();

    if (QFileInfo::exists(m_configFile)) {
        m_watcher.addPath(m_configFile);
    }
}

QString ConfigManager::configFilePath() const {
    return m_configFile;
}

void ConfigManager::createDefaultConfig(const QString &path) {
    QJsonObject root;

    QJsonObject durations;
    durations["focus"] = 25;
    durations["short_break"] = 5;
    durations["long_break"] = 15;
    durations["long_break_interval"] = 4;
    root["durations"] = durations;

    root["mascot"] = "claude_critter"; // "claude_critter", "blob", "tux", "ghost"

    QJsonObject sound;
    sound["enabled"] = true;
    sound["volume"] = 0.8;
    sound["finish_sound"] = ""; // Empty for built-in 8-bit retro chime, or path to custom .wav/.mp3
    sound["start_sound"] = "";  // Empty for built-in 8-bit ping, or path
    sound["click_sound"] = "";  // Empty for built-in 8-bit blip, or path
    root["sound"] = sound;

    root["notifications"] = true;

    QJsonObject behavior;
    behavior["auto_start_breaks"] = false;
    behavior["auto_start_focus"] = false;
    root["behavior"] = behavior;

    QJsonObject window;
    window["width"] = 360;
    window["height"] = 580;
    window["always_on_top"] = false;
    root["window"] = window;

    QJsonObject theme;
    theme["use_omarchy_theme"] = true;
    theme["custom_accent"] = ""; // Optional hex override (e.g. "#FF79C6")
    root["theme"] = theme;

    QJsonDocument doc(root);
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
    }
}

void ConfigManager::loadConfig() {
    QFile file(m_configFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isObject())
        return;

    QJsonObject root = doc.object();

    if (root.contains("durations") && root["durations"].isObject()) {
        auto d = root["durations"].toObject();
        m_focusDuration = d.value("focus").toInt(25);
        m_shortBreakDuration = d.value("short_break").toInt(5);
        m_longBreakDuration = d.value("long_break").toInt(15);
        m_longBreakInterval = d.value("long_break_interval").toInt(4);
    }

    if (root.contains("mascot") && root["mascot"].isString()) {
        m_mascot = root["mascot"].toString();
    }

    if (root.contains("sound") && root["sound"].isObject()) {
        auto s = root["sound"].toObject();
        m_soundEnabled = s.value("enabled").toBool(true);
        m_volume = s.value("volume").toDouble(0.8);
        m_finishSound = s.value("finish_sound").toString();
        m_startSound = s.value("start_sound").toString();
        m_clickSound = s.value("click_sound").toString();
    }

    m_notificationsEnabled = root.value("notifications").toBool(true);

    if (root.contains("behavior") && root["behavior"].isObject()) {
        auto b = root["behavior"].toObject();
        m_autoStartBreaks = b.value("auto_start_breaks").toBool(false);
        m_autoStartFocus = b.value("auto_start_focus").toBool(false);
    }

    if (root.contains("window") && root["window"].isObject()) {
        auto w = root["window"].toObject();
        m_windowWidth = w.value("width").toInt(360);
        m_windowHeight = w.value("height").toInt(580);
        m_alwaysOnTop = w.value("always_on_top").toBool(false);
    }

    if (root.contains("theme") && root["theme"].isObject()) {
        auto t = root["theme"].toObject();
        m_useOmarchyTheme = t.value("use_omarchy_theme").toBool(true);
        m_customAccent = t.value("custom_accent").toString();
    }

    emit changed();
}

void ConfigManager::setMascot(const QString &mascot) {
    if (m_mascot != mascot) {
        m_mascot = mascot;
        saveConfig();
        emit changed();
    }
}

void ConfigManager::nextMascot() {
    static const QStringList list = { "claude_critter", "blob", "tux", "ghost" };
    int idx = list.indexOf(m_mascot);
    idx = (idx + 1) % list.size();
    setMascot(list[idx]);
}

void ConfigManager::saveConfig() {
    QJsonObject root;

    QJsonObject durations;
    durations["focus"] = m_focusDuration;
    durations["short_break"] = m_shortBreakDuration;
    durations["long_break"] = m_longBreakDuration;
    durations["long_break_interval"] = m_longBreakInterval;
    root["durations"] = durations;

    root["mascot"] = m_mascot;

    QJsonObject sound;
    sound["enabled"] = m_soundEnabled;
    sound["volume"] = m_volume;
    sound["finish_sound"] = m_finishSound;
    sound["start_sound"] = m_startSound;
    sound["click_sound"] = m_clickSound;
    root["sound"] = sound;

    root["notifications"] = m_notificationsEnabled;

    QJsonObject behavior;
    behavior["auto_start_breaks"] = m_autoStartBreaks;
    behavior["auto_start_focus"] = m_autoStartFocus;
    root["behavior"] = behavior;

    QJsonObject window;
    window["width"] = m_windowWidth;
    window["height"] = m_windowHeight;
    window["always_on_top"] = m_alwaysOnTop;
    root["window"] = window;

    QJsonObject theme;
    theme["use_omarchy_theme"] = m_useOmarchyTheme;
    theme["custom_accent"] = m_customAccent;
    root["theme"] = theme;

    QFile file(m_configFile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        file.write(QJsonDocument(root).toJson(QJsonDocument::Indented));
    }
}
