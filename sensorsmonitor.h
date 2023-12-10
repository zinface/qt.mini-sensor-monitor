#ifndef SENSORSMONITOR_H
#define SENSORSMONITOR_H

#include <QObject>
#include <QTimer>

class SensorsManager;
class SensorsMonitor : public QObject
{
    Q_OBJECT
public:
    explicit SensorsMonitor(QObject *parent = nullptr);

    void start();
    void stop();

    QString adapter() const;
    void setAdapter(const QString &newAdapter);

    QString sensor() const;
    void setSensor(const QString &newSensor);

    void setMonitorAdapterSensor(const QString &adapter, const QString &sensor);

public slots:
    void slotTimeout();
    void slotOnRequestSensor(const QString &sensor, const QString &value);

signals:
    void sensorUpdated(float value);

private:
    QTimer *m_timer;
    SensorsManager *m_manager;

    QString m_adapter;
    QString m_sensor;
};

#endif // SENSORSMONITOR_H
