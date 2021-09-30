#ifndef CONFIG_H
#define CONFIG_H

#include <QQmlApplicationEngine>
#include <QQmlContext>

#define SINGLETON( NAME )    \
 public:                        \
    NAME( const NAME& ) = delete; \
    static NAME& instance()      \
    {                            \
       static NAME _instance;    \
       return _instance;         \
    }                            \
 private:                       \
    NAME();

#define config(NAME) constexpr const char* NAME = #NAME;

constexpr const char* filepath = "./Files/";
constexpr const char* fileconfig = "./Files/config.json";

constexpr const char* config = "./config.json";

inline QString stdWorkingDirectory()
{
    QString name = qgetenv("USER");
    if (name.isEmpty())
       name = qgetenv("USERNAME");
    QString data = QString("C:/Users/") + name + QString("/Documents/SchoolManager/");
    return data;
}

constexpr const char* stdDateFormat = "dd.MM.yyyy_hh:mm:ss";

namespace configElements {
    config(WorkingDirectory)
    config(DateFormat)
}

extern QQmlApplicationEngine* appEngine;

#endif // CONFIG_H
