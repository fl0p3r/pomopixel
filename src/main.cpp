#include <QGuiApplication>
#include <QFontDatabase>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QUrl>

#include "backend.h"
#include "configmanager.h"
#include "theme.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    app.setApplicationName("pomopixel");
    app.setApplicationDisplayName("Pomopixel");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("omarchy");

    // Wayland app_id and .desktop matching
    app.setDesktopFileName("pomopixel");
    app.setWindowIcon(QIcon(":/icons/pomopixel.svg"));

    // Add pixel font
    int fontId = QFontDatabase::addApplicationFont(":/fonts/PressStart2P.ttf");
    if (fontId != -1) {
        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
        if (!fontFamilies.isEmpty()) {
            QFont pixelFont(fontFamilies.first());
            pixelFont.setPixelSize(12);
            app.setFont(pixelFont);
        }
    }

    QQuickStyle::setStyle("Basic");

    Theme theme;
    ConfigManager config;
    Backend backend(&config);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("theme", &theme);
    engine.rootContext()->setContextProperty("config", &config);
    engine.rootContext()->setContextProperty("backend", &backend);

    const QUrl url("qrc:/Main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
