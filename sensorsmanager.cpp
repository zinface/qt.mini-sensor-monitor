#include "sensorsmanager.h"
#include "sensorsworker.h"

SensorsManager::SensorsManager(QObject *parent)
    : QObject{parent}
{

}

void SensorsManager::start()
{
    stop();
    SensorsWorker *worker = new SensorsWorker(this);
    worker->moveToThread(&m_thread);
    connect(this, &SensorsManager::requestSensor, worker, &SensorsWorker::slotRequestSensor);
    connect(&m_thread, &QThread::finished, worker, &SensorsWorker::deleteLater);
    m_thread.start();
}

void SensorsManager::stop()
{
    if (m_thread.isRunning()) {
        m_thread.quit();
        m_thread.wait();
    }
}
