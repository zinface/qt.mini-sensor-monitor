#include "sensorsmanager.h"
#include "sensorsmonitor.h"

SensorsMonitor::SensorsMonitor(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer;
    m_timer->setInterval(500);
    m_manager = new SensorsManager;
    connect(m_timer, &QTimer::timeout, this, &SensorsMonitor::slotTimeout);
    connect(m_manager, &SensorsManager::onRequestSensor, this, &SensorsMonitor::slotOnRequestSensor);
    m_manager->start();
}

void SensorsMonitor::start()
{
    m_timer->start();
}

void SensorsMonitor::stop()
{
    m_timer->stop();
}

void SensorsMonitor::slotTimeout()
{
    emit m_manager->requestSensor(m_adapter, m_sensor);
}

void SensorsMonitor::slotOnRequestSensor(const QString &sensor, const QString &value)
{
    bool ok = false;
    float v = value.toFloat(&ok);
    if (!ok) {
        v = -1;
    }
    emit sensorUpdated(v);
}

QString SensorsMonitor::sensor() const
{
    return m_sensor;
}

void SensorsMonitor::setSensor(const QString &newSensor)
{
    m_sensor = newSensor;
}

void SensorsMonitor::setMonitorAdapterSensor(const QString &adapter, const QString &sensor)
{
    setAdapter(adapter);
    setSensor(sensor);
}

QString SensorsMonitor::adapter() const
{
    return m_adapter;
}

void SensorsMonitor::setAdapter(const QString &newAdapter)
{
    m_adapter = newAdapter;
}
