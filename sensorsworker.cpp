#include "sensorsworker.h"

#include <QProcess>

SensorsWorker::SensorsWorker(SensorsManager *parent)
    : QObject{parent},
    manager(parent)
{

}

void SensorsWorker::slotRequestSensor(QString &adapter, QString &sensor)
{
    QProcess process;
    process.start("sensors -u");
    process.waitForFinished(2000);

    QString standardOutput = process.readAllStandardOutput();

    QString sensorValue = "";

    QStringList contents = standardOutput.split("\n\n");
    foreach (QString content, contents) {
        bool findAdapter = false;
        QStringList lines = content.split("\n");
        foreach (QString line, lines) {
            if ((line.startsWith("Adapter: ") && line.contains(adapter)) || findAdapter) {
                findAdapter = true;

                QStringList split = line.split(": ");
                if (split.length() == 2 && split[0].contains(sensor)) {
                    sensorValue = split[1];
                    break;
                }
            }
        }
    }

    emit manager->onRequestSensor(sensor, sensorValue);
}
