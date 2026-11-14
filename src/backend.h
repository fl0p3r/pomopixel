#pragma once

#include <QDate>
#include <QObject>
#include <QString>
#include <QTimer>

class ConfigManager;

class Backend : public QObject {
    Q_OBJECT
    Q_PROPERTY(int mode READ mode NOTIFY modeChanged)
    Q_PROPERTY(QString modeName READ modeName NOTIFY modeChanged)
    Q_PROPERTY(int secondsRemaining READ secondsRemaining NOTIFY timerTicked)
    Q_PROPERTY(int totalSeconds READ totalSeconds NOTIFY modeChanged)
    Q_PROPERTY(QString formattedTime READ formattedTime NOTIFY timerTicked)
    Q_PROPERTY(qreal progress READ progress NOTIFY timerTicked)
    Q_PROPERTY(bool isRunning READ isRunning NOTIFY runningChanged)
    Q_PROPERTY(int completedCycles READ completedCycles NOTIFY statsChanged)
    Q_PROPERTY(bool isMascotResting READ isMascotResting NOTIFY modeChanged)

public:
    enum Mode {
        ModeFocus = 0,
        ModeShortBreak = 1,
        ModeLongBreak = 2
    };
    Q_ENUM(Mode)

    explicit Backend(ConfigManager *config, QObject *parent = nullptr);
    ~Backend() override = default;

    int mode() const { return m_mode; }
    QString modeName() const;
    int secondsRemaining() const { return m_secondsRemaining; }
    int totalSeconds() const { return m_totalSeconds; }
    QString formattedTime() const;
    qreal progress() const;
    bool isRunning() const { return m_isRunning; }
    int completedCycles() const { return m_completedCycles; }
    bool isMascotResting() const { return m_mode != ModeFocus; }

    Q_INVOKABLE void toggle();
    Q_INVOKABLE void start();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void reset();
    Q_INVOKABLE void skip();
    Q_INVOKABLE void setMode(int mode);
    Q_INVOKABLE void playClick();

signals:
    void modeChanged();
    void timerTicked();
    void runningChanged();
    void statsChanged();

private slots:
    void onTick();
    void onConfigChanged();

private:
    void applyModeDurations();
    void timerFinished();
    void playAudio(const QString &type);
    void sendNotification(const QString &title, const QString &body);
    void loadStats();
    void saveStats();

    ConfigManager *m_config;
    Mode m_mode = ModeFocus;
    int m_secondsRemaining = 25 * 60;
    int m_totalSeconds = 25 * 60;
    bool m_isRunning = false;
    int m_completedCycles = 0;
    int m_consecutiveFocusCycles = 0;

    QTimer m_timer;
    QDate m_today;
    QString m_statsFile;
};
