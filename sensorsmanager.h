#ifndef SENSORSMANAGER_H
#define SENSORSMANAGER_H

#include <QObject>
#include <QThread>

class SensorsManager : public QObject
{
    Q_OBJECT
public:
    explicit SensorsManager(QObject *parent = nullptr);
    void start();
    void stop();

signals:
    void requestSensor(const QString &adapter, const QString &sensor);
    void onRequestSensor(const QString &sensor, const QString &value);

private:
    QThread m_thread;

};

#endif // SENSORSMANAGER_H
