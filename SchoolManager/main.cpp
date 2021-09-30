#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWidgets>
#include <QQmlContext>
#include <QQuickItem>

#include "configmanager.h"
#include "hourmanager.h"
#include "filemanager.h"

QQmlApplicationEngine* appEngine;

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    appEngine = &engine;

    ConfigManager::instance();
    HourManager::instance();
    FileManager::instance();

    return app.exec();
}
