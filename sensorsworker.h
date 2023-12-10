#ifndef SENSORSWORKER_H
#define SENSORSWORKER_H

#include "sensorsmanager.h"
#include <QObject>

class SensorsWorker : public QObject
{
    Q_OBJECT
public:
    explicit SensorsWorker(SensorsManager *parent);

public slots:
    void slotRequestSensor(QString &adapter, QString &sensor);


private:
    SensorsManager *manager;
};

#endif // SENSORSWORKER_H
