#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QList>
#include <QFile>
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>

#include "Config.h"
#include "configmanager.h"

class FileManager: public QObject
{
    Q_OBJECT
    SINGLETON(FileManager);
public slots:
    void create(QString type);

private:
    QFile configFile;
    QJsonObject configJSON;
    QList<QString> files;
    QList<QString> extensions;
};

#endif // FILEMANAGER_H
