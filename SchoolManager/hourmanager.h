#ifndef HOURMANAGER_H
#define HOURMANAGER_H

#include <QObject>

#include "Config.h"

class HourManager :public QObject
{
    Q_OBJECT
    SINGLETON(HourManager);
public:
    QString ActualHour;
};

#endif // HOURMANAGER_H
