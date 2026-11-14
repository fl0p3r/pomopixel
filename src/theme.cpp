#include "theme.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>
#include <QStandardPaths>

Theme::Theme(const QString &stateDirectory, QObject *parent)
    : QObject(parent),
      m_directory(stateDirectory.isEmpty() ? QDir::homePath() + "/.local/state/omarchy/current" : stateDirectory) {

    m_debounce.setSingleShot(true);
    m_debounce.setInterval(100);
    connect(&m_watcher, &QFileSystemWatcher::directoryChanged, this, [this] { m_debounce.start(); });
    connect(&m_watcher, &QFileSystemWatcher::fileChanged, this, [this] { m_debounce.start(); });
    connect(&m_debounce, &QTimer::timeout, this, &Theme::reload);

    if (stateDirectory.isEmpty() && !qEnvironmentVariableIsEmpty("HYPRLAND_INSTANCE_SIGNATURE")) {
        m_hyprctl = QStandardPaths::findExecutable("hyprctl");
    }

    m_roundingTimeout.setSingleShot(true);
    m_roundingTimeout.setInterval(500);
    connect(&m_roundingTimeout, &QTimer::timeout, &m_roundingProcess, &QProcess::kill);
    connect(&m_roundingProcess, &QProcess::errorOccurred, this, [this] { m_roundingTimeout.stop(); });
    connect(&m_roundingProcess, &QProcess::finished, this, [this](int code, QProcess::ExitStatus status) {
        m_roundingTimeout.stop();
        const auto value = QJsonDocument::fromJson(m_roundingProcess.readAllStandardOutput()).object().value("int");
        if (code != 0 || status != QProcess::NormalExit || !value.isDouble() || value.toInt(-1) < 0)
            return;
        if (value.toInt() != m_radius) {
            m_radius = value.toInt();
            emit changed();
        }
    });

    m_roundingPoll.setInterval(2000);
    connect(&m_roundingPoll, &QTimer::timeout, this, &Theme::refreshRounding);
    if (!m_hyprctl.isEmpty()) {
        m_roundingPoll.start();
    }

    reload();
}

Theme::~Theme() {
    if (m_roundingProcess.state() != QProcess::NotRunning) {
        m_roundingProcess.kill();
        m_roundingProcess.waitForFinished(500);
    }
}

void Theme::refreshRounding() {
    if (m_hyprctl.isEmpty() || m_roundingProcess.state() != QProcess::NotRunning)
        return;
    m_roundingProcess.start(m_hyprctl, {"-j", "getoption", "decoration:rounding"});
    m_roundingTimeout.start();
}

void Theme::loadColorsFromFile(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // Matches lines like: key = "#123456" or key = "dark"
    static const QRegularExpression regex(R"(^\s*([a-zA-Z0-9_-]+)\s*=\s*["']([^"']+)["'])");
    while (!file.atEnd()) {
        QString line = QString::fromUtf8(file.readLine()).trimmed();
        auto match = regex.match(line);
        if (match.hasMatch()) {
            m_colors[match.captured(1)] = match.captured(2);
        }
    }
}

void Theme::reload() {
    refreshRounding();

    const auto paths = m_watcher.files() + m_watcher.directories();
    if (!paths.isEmpty())
        m_watcher.removePaths(paths);

    // Watch parent ancestors so theme switching (symlink swap) triggers reload
    QString ancestor = m_directory;
    while (!QFileInfo::exists(ancestor) && ancestor != "/")
        ancestor = QFileInfo(ancestor).absolutePath();

    QStringList candidates{
        ancestor,
        QFileInfo(ancestor).absolutePath(),
        m_directory,
        m_directory + "/theme",
        m_directory + "/theme/colors.toml"
    };
    candidates.removeDuplicates();

    for (const auto &path : candidates) {
        if (QFileInfo::exists(path))
            m_watcher.addPath(path);
    }

    m_colors.clear();
    // Default fallback retro synthwave/cyberpunk palette
    m_colors["accent"] = "#FF79C6";
    m_colors["background"] = "#1E1E2E";
    m_colors["dark_background"] = "#181825";
    m_colors["darker_background"] = "#11111B";
    m_colors["lighter_background"] = "#313244";
    m_colors["foreground"] = "#CDD6F4";
    m_colors["bright_foreground"] = "#FFFFFF";
    m_colors["muted"] = "#6C7086";
    m_colors["red"] = "#F38BA8";
    m_colors["green"] = "#A6E3A1";
    m_colors["yellow"] = "#F9E2AF";
    m_colors["blue"] = "#89B4FA";
    m_colors["magenta"] = "#F5C2E7";
    m_colors["orange"] = "#FAB387";
    m_colors["cyan"] = "#94E2D5";

    loadColorsFromFile(m_directory + "/theme/colors.toml");

    emit changed();
}
