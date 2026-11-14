#pragma once

#include <QFileSystemWatcher>
#include <QJsonObject>
#include <QObject>
#include <QString>
#include <QTimer>

class ConfigManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(int focusDuration READ focusDuration NOTIFY changed)
    Q_PROPERTY(int shortBreakDuration READ shortBreakDuration NOTIFY changed)
    Q_PROPERTY(int longBreakDuration READ longBreakDuration NOTIFY changed)
    Q_PROPERTY(int longBreakInterval READ longBreakInterval NOTIFY changed)
    Q_PROPERTY(QString mascot READ mascot WRITE setMascot NOTIFY changed)
    Q_PROPERTY(bool soundEnabled READ soundEnabled NOTIFY changed)
    Q_PROPERTY(qreal volume READ volume NOTIFY changed)
    Q_PROPERTY(QString finishSound READ finishSound NOTIFY changed)
    Q_PROPERTY(QString startSound READ startSound NOTIFY changed)
    Q_PROPERTY(QString clickSound READ clickSound NOTIFY changed)
    Q_PROPERTY(bool notificationsEnabled READ notificationsEnabled NOTIFY changed)
    Q_PROPERTY(bool autoStartBreaks READ autoStartBreaks NOTIFY changed)
    Q_PROPERTY(bool autoStartFocus READ autoStartFocus NOTIFY changed)
    Q_PROPERTY(int windowWidth READ windowWidth NOTIFY changed)
    Q_PROPERTY(int windowHeight READ windowHeight NOTIFY changed)
    Q_PROPERTY(bool alwaysOnTop READ alwaysOnTop NOTIFY changed)
    Q_PROPERTY(bool useOmarchyTheme READ useOmarchyTheme NOTIFY changed)
    Q_PROPERTY(QString customAccent READ customAccent NOTIFY changed)

public:
    explicit ConfigManager(QObject *parent = nullptr);
    ~ConfigManager() override = default;

    int focusDuration() const { return m_focusDuration; }
    int shortBreakDuration() const { return m_shortBreakDuration; }
    int longBreakDuration() const { return m_longBreakDuration; }
    int longBreakInterval() const { return m_longBreakInterval; }
    QString mascot() const { return m_mascot; }
    bool soundEnabled() const { return m_soundEnabled; }
    qreal volume() const { return m_volume; }
    QString finishSound() const { return m_finishSound; }
    QString startSound() const { return m_startSound; }
    QString clickSound() const { return m_clickSound; }
    bool notificationsEnabled() const { return m_notificationsEnabled; }
    bool autoStartBreaks() const { return m_autoStartBreaks; }
    bool autoStartFocus() const { return m_autoStartFocus; }
    int windowWidth() const { return m_windowWidth; }
    int windowHeight() const { return m_windowHeight; }
    bool alwaysOnTop() const { return m_alwaysOnTop; }
    bool useOmarchyTheme() const { return m_useOmarchyTheme; }
    QString customAccent() const { return m_customAccent; }

    Q_INVOKABLE void setMascot(const QString &mascot);
    Q_INVOKABLE void nextMascot();
    Q_INVOKABLE void saveConfig();
    Q_INVOKABLE QString configFilePath() const;

signals:
    void changed();

private slots:
    void loadConfig();

private:
    void createDefaultConfig(const QString &path);

    QString m_configDir;
    QString m_configFile;
    QFileSystemWatcher m_watcher;
    QTimer m_debounce;

    int m_focusDuration = 25;
    int m_shortBreakDuration = 5;
    int m_longBreakDuration = 15;
    int m_longBreakInterval = 4;
    QString m_mascot = "claude_critter";
    bool m_soundEnabled = true;
    qreal m_volume = 0.8;
    QString m_finishSound = "";
    QString m_startSound = "";
    QString m_clickSound = "";
    bool m_notificationsEnabled = true;
    bool m_autoStartBreaks = false;
    bool m_autoStartFocus = false;
    int m_windowWidth = 360;
    int m_windowHeight = 580;
    bool m_alwaysOnTop = false;
    bool m_useOmarchyTheme = true;
    QString m_customAccent = "";
};
