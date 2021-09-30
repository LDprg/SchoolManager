#include "configmanager.h"

ConfigManager::ConfigManager()
    :configFile(config)
{
    if (!QFile::exists(config))
    {
        configFile.open(QFile::ReadWrite|QFile::Text);
        QJsonObject json;
        json[configElements::WorkingDirectory] = stdWorkingDirectory();
        json[configElements::DateFormat] = stdDateFormat;
        QJsonDocument jsonDocument(json);
        configFile.write(jsonDocument.toJson());
        configFile.close();
    }

    QDir dir;
    if (!dir.exists(stdWorkingDirectory()))
        dir.mkdir(stdWorkingDirectory());

    configFile.open(QFile::ReadOnly|QFile::Text);

    QString jsonString = configFile.readAll();
    configFile.close();

    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
    qDebug() << "Parse JSON config: " << error.errorString();
    configJSON = jsonDocument.object();

    WorkingDirectory = configJSON[configElements::WorkingDirectory].toString();
    DateFormat = configJSON[configElements::DateFormat].toString();

    if (!dir.exists(WorkingDirectory))
    {
        qDebug() << "WorkingDirectory does not exist!";
        QMessageBox msg;
        msg.setWindowTitle("ERROR");
        msg.setIcon(QMessageBox::Critical);
        msg.setText(QString(configElements::WorkingDirectory) + QString( ": ") + WorkingDirectory + " does not exist!\nEdit config or create Directory to Fix!");
        msg.exec();
        emit appEngine->quit();
    }
}
