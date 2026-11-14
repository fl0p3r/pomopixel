#pragma once

#include <QColor>
#include <QFileSystemWatcher>
#include <QMap>
#include <QObject>
#include <QProcess>
#include <QString>
#include <QTimer>

class Theme : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString accent READ accent NOTIFY changed)
    Q_PROPERTY(QString background READ background NOTIFY changed)
    Q_PROPERTY(QString darkBackground READ darkBackground NOTIFY changed)
    Q_PROPERTY(QString darkerBackground READ darkerBackground NOTIFY changed)
    Q_PROPERTY(QString lighterBackground READ lighterBackground NOTIFY changed)
    Q_PROPERTY(QString foreground READ foreground NOTIFY changed)
    Q_PROPERTY(QString brightForeground READ brightForeground NOTIFY changed)
    Q_PROPERTY(QString muted READ muted NOTIFY changed)
    Q_PROPERTY(QString red READ red NOTIFY changed)
    Q_PROPERTY(QString green READ green NOTIFY changed)
    Q_PROPERTY(QString yellow READ yellow NOTIFY changed)
    Q_PROPERTY(QString blue READ blue NOTIFY changed)
    Q_PROPERTY(QString magenta READ magenta NOTIFY changed)
    Q_PROPERTY(QString orange READ orange NOTIFY changed)
    Q_PROPERTY(QString cyan READ cyan NOTIFY changed)
    Q_PROPERTY(int radius READ radius NOTIFY changed)

public:
    explicit Theme(const QString &stateDirectory = QString(), QObject *parent = nullptr);
    ~Theme() override;

    QString accent() const { return m_colors.value("accent", "#FF8DA1"); }
    QString background() const { return m_colors.value("background", "#1A1A24"); }
    QString darkBackground() const { return m_colors.value("dark_background", "#14141E"); }
    QString darkerBackground() const { return m_colors.value("darker_background", "#0E0E16"); }
    QString lighterBackground() const { return m_colors.value("lighter_background", "#262636"); }
    QString foreground() const { return m_colors.value("foreground", "#E2E0EC"); }
    QString brightForeground() const { return m_colors.value("bright_foreground", "#FFFFFF"); }
    QString muted() const { return m_colors.value("muted", "#6A6680"); }
    QString red() const { return m_colors.value("red", "#FF5555"); }
    QString green() const { return m_colors.value("green", "#50FA7B"); }
    QString yellow() const { return m_colors.value("yellow", "#F1FA8C"); }
    QString blue() const { return m_colors.value("blue", "#8BE9FD"); }
    QString magenta() const { return m_colors.value("magenta", "#FF79C6"); }
    QString orange() const { return m_colors.value("orange", "#FFB86C"); }
    QString cyan() const { return m_colors.value("cyan", "#8BE9FD"); }
    int radius() const { return m_radius; }

    Q_INVOKABLE QString color(const QString &key, const QString &fallback = "#FFFFFF") const {
        return m_colors.value(key, fallback);
    }

signals:
    void changed();

private slots:
    void reload();
    void refreshRounding();

private:
    void loadColorsFromFile(const QString &path);

    QString m_directory;
    QMap<QString, QString> m_colors;
    QFileSystemWatcher m_watcher;
    QTimer m_debounce;

    QString m_hyprctl;
    int m_radius = 8;
    QProcess m_roundingProcess;
    QTimer m_roundingPoll;
    QTimer m_roundingTimeout;
};
