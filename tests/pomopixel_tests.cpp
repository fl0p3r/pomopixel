#include <QSignalSpy>
#include <QTest>
#include <QTemporaryDir>

#include "backend.h"
#include "configmanager.h"
#include "theme.h"

class PomopixelTests : public QObject {
    Q_OBJECT

private slots:
    void testBackendInitialState() {
        ConfigManager config;
        Backend backend(&config);

        QCOMPARE(backend.mode(), Backend::ModeFocus);
        QCOMPARE(backend.modeName(), QString("FOCUS TIME"));
        QCOMPARE(backend.secondsRemaining(), 25 * 60);
        QCOMPARE(backend.formattedTime(), QString("25:00"));
        QCOMPARE(backend.isRunning(), false);
        QCOMPARE(backend.isMascotResting(), false);
    }

    void testModeSwitching() {
        ConfigManager config;
        Backend backend(&config);

        backend.setMode(Backend::ModeShortBreak);
        QCOMPARE(backend.mode(), Backend::ModeShortBreak);
        QCOMPARE(backend.modeName(), QString("SHORT BREAK"));
        QCOMPARE(backend.secondsRemaining(), 5 * 60);
        QCOMPARE(backend.formattedTime(), QString("05:00"));
        QCOMPARE(backend.isMascotResting(), true);

        backend.setMode(Backend::ModeLongBreak);
        QCOMPARE(backend.mode(), Backend::ModeLongBreak);
        QCOMPARE(backend.modeName(), QString("LONG BREAK"));
        QCOMPARE(backend.secondsRemaining(), 15 * 60);
        QCOMPARE(backend.formattedTime(), QString("15:00"));
        QCOMPARE(backend.isMascotResting(), true);
    }

    void testTimerToggle() {
        ConfigManager config;
        Backend backend(&config);

        backend.toggle();
        QCOMPARE(backend.isRunning(), true);

        backend.toggle();
        QCOMPARE(backend.isRunning(), false);
    }

    void testThemeParsing() {
        QTemporaryDir tempDir;
        QDir themeDir(tempDir.path() + "/theme");
        themeDir.mkpath(".");

        QFile colorsFile(themeDir.path() + "/colors.toml");
        QVERIFY(colorsFile.open(QIODevice::WriteOnly | QIODevice::Text));
        colorsFile.write(
            "accent = \"#AABBCC\"\n"
            "background = \"#112233\"\n"
            "red = \"#FF0000\"\n"
        );
        colorsFile.close();

        Theme theme(tempDir.path());
        QCOMPARE(theme.accent(), QString("#AABBCC"));
        QCOMPARE(theme.background(), QString("#112233"));
        QCOMPARE(theme.red(), QString("#FF0000"));
    }
};

QTEST_MAIN(PomopixelTests)
#include "pomopixel_tests.moc"
