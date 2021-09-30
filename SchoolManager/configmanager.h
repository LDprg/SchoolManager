#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QObject>
#include <QList>
#include <QFile>
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

#include "Config.h"

class ConfigManager: public QObject
{
    Q_OBJECT
    SINGLETON(ConfigManager)
public:
    QString WorkingDirectory;
    QString DateFormat;

private:
    QFile configFile;
    QJsonObject configJSON;
};

#endif // CONFIGMANAGER_H
