#include "filemanager.h"

FileManager::FileManager()
    :configFile(fileconfig)
{
    QDir dir;
    if (!dir.exists(filepath)) dir.mkdir(filepath);

    if (!QFile::exists(fileconfig))
    {
        configFile.open(QFile::ReadWrite|QFile::Text);
        QJsonObject json;
        json["docx"] = "Vorlage";
        json["xlsx"] = "Vorlage";
        json["pptx"] = "Vorlage";
        QJsonDocument jsonDocument(json);
        configFile.write(jsonDocument.toJson());
        configFile.close();
    }

    configFile.open(QFile::ReadOnly|QFile::Text);

    QString jsonString = configFile.readAll();
    configFile.close();

    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
    qDebug() << "Parse JSON File config: " << error.errorString();
    configJSON = jsonDocument.object();

    int num = 0;

    for(auto obj = configJSON.begin(); num < configJSON.count(); ++obj){
        files.emplace_back(QString(filepath) + obj.value().toString() + QString(".") + QString(obj.key().toStdString().c_str()));
        extensions.emplace_back(QString(".") + QString(obj.key().toStdString().c_str()));
        ++num;
    }

    QObject* cbDokument = appEngine->rootObjects().at(0)->findChild<QObject*>("cbDokument", Qt::FindChildrenRecursively);
    if (cbDokument) cbDokument->setProperty("model", extensions);
    else qDebug() << "ERROR TEST";

    QObject::connect(cbDokument, SIGNAL(create(QString)),
                     this, SLOT(create(QString)));
}

/// FILE NAMES CAN'T CONTAIN ANY '.'
void FileManager::create(QString type)
{
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString(ConfigManager::instance().DateFormat);
    qDebug() << ConfigManager::instance().WorkingDirectory + QString("FSST/") + formattedTime + QString(".docx");
    //QFile::copy(files.filter(type).at(0), ConfigManager::instance().WorkingDirectory + formattedTime + QString(".docx"));
}
