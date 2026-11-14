#include <QGuiApplication>
#include <QFontDatabase>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>
#include <QTimer>
#include <QImage>

#include "../src/backend.h"
#include "../src/configmanager.h"
#include "../src/theme.h"

int main(int argc, char *argv[]) {
    qputenv("QT_QPA_PLATFORM", "offscreen");
    QGuiApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/PressStart2P.ttf");

    Theme theme;
    ConfigManager config;
    Backend backend(&config);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("theme", &theme);
    engine.rootContext()->setContextProperty("config", &config);
    engine.rootContext()->setContextProperty("backend", &backend);

    engine.load(QUrl("qrc:/Main.qml"));
    if (engine.rootObjects().isEmpty())
        return 1;

    auto *window = qobject_cast<QQuickWindow *>(engine.rootObjects().first());
    if (!window)
        return 2;

    QTimer::singleShot(250, [&]() {
        QImage img = window->grabWindow();
        img.save("/tmp/pomopixel_preview.png");
        app.quit();
    });

    return app.exec();
}
