#include "sensorsconfig.h"
#include "sensorsettingdialog.h"
#include "sensorsmonitor.h"
#include "simplesensormonitor.h"

#include <QContextMenuEvent>

SimpleSensorMonitor::SimpleSensorMonitor(QWidget *parent)
    : MiniFloatingIcon{parent},
    m_identifier("#"),
    m_classunit("#")
{
    setWindowIcon(QIcon("://sensor_icon.png"));

    m_lable = new QLabel;
    m_lable->setStyleSheet("background-color: #c9eefe;color: #2278b1;");
    m_lable->setAlignment(Qt::AlignmentFlag::AlignCenter);
    setWidget(m_lable);

    iconWidget()->setStyleSheet("background-color: #e8f6fe;");

    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    m_monitor = new SensorsMonitor;
//    m_monitor->setMonitorAdapterSensor("", "");
    resetConfig();
    connect(m_monitor, &SensorsMonitor::sensorUpdated, this, &SimpleSensorMonitor::slotSensorUpdated);
    m_monitor->start();

    m_contextMenu.addAction("设置传感器", this, &SimpleSensorMonitor::slotDisplaySettingDialog);
    m_contextMenu.addAction("退出", this, &SimpleSensorMonitor::slotExit);
}

void SimpleSensorMonitor::resetConfig()
{
    m_monitor->setMonitorAdapterSensor(SensorsConfig::getAdapter(), SensorsConfig::getSensor());
    m_monitor->setInterval(SensorsConfig::getDelay());

    auto identifier = SensorsConfig::getIdentifier();
    auto classunit = SensorsConfig::getClassUnit();

    m_identifier = identifier.isEmpty()?"#":identifier;
    m_classunit = classunit.isEmpty()?"#":classunit;

//    m_monitor->setMonitorAdapterSensor("ACPI interface", "temp1_input");
}

void SimpleSensorMonitor::slotSensorUpdated(float value)
{
    QString sensor_icon = ":/sensors/sensor_100.png";
    if (value < 90) sensor_icon = ":/sensors/sensor_90.png";
    if (value < 80) sensor_icon = ":/sensors/sensor_80.png";
    if (value < 70) sensor_icon = ":/sensors/sensor_70.png";
    if (value < 60) sensor_icon = ":/sensors/sensor_60.png";
    if (value < 55) sensor_icon = ":/sensors/sensor_55.png";
    if (value < 50) sensor_icon = ":/sensors/sensor_50.png";
    if (value < 45) sensor_icon = ":/sensors/sensor_45.png";
    if (value < 40) sensor_icon = ":/sensors/sensor_40.png";
    if (value < 35) sensor_icon = ":/sensors/sensor_35.png";
    if (value < 30) sensor_icon = ":/sensors/sensor_30.png";

    if (value == -1) sensor_icon = "://sensor_sad.png";

    if (m_identifier == "风扇") {
        auto fan = ((value / 3800.0) * 80);
        sensor_icon = ":/fan/icons/fans/100.png";
        if (fan < 90) sensor_icon = ":/fan/icons/fans/90.png";
        if (fan < 80) sensor_icon = ":/fan/icons/fans/80.png";
        if (fan < 70) sensor_icon = ":/fan/icons/fans/70.png";
        if (fan < 60) sensor_icon = ":/fan/icons/fans/60.png";
        if (fan < 55) sensor_icon = ":/fan/icons/fans/50.png";
        if (fan < 50) sensor_icon = ":/fan/icons/fans/40.png";
        if (fan < 45) sensor_icon = ":/fan/icons/fans/30.png";
        if (fan < 40) sensor_icon = ":/fan/icons/fans/20.png";
        if (fan < 35) sensor_icon = ":/fan/icons/fans/10.png";
    }

    if (m_identifier == "电流" || m_identifier == "电压" || m_identifier == "功耗") {
        sensor_icon = ":/electricity/icons/electricity/electricity.png";
    }

    setIcon(sensor_icon);
    m_lable->setText(QString("%2: %1%3").arg(value, 0, 'f', 1).arg(m_identifier).arg(m_classunit));
}

void SimpleSensorMonitor::slotDisplaySettingDialog()
{
    SensorSettingDialog dialog;
    if (dialog.exec() == QDialog::Accepted) {
        QString adapter = dialog.getAdapter();
        QString sensor = dialog.getSensor();
        QString identifier = dialog.getIdentifier();
        QString classunit = dialog.getClassUnit();
        int delay = dialog.getDelay();

        m_monitor->setMonitorAdapterSensor(adapter, sensor);
        m_monitor->setInterval(delay);

        m_identifier = identifier;
        m_classunit = classunit;

        SensorsConfig::setAdapter(adapter);
        SensorsConfig::setSensor(sensor);
        SensorsConfig::setIdentifier(identifier);
        SensorsConfig::setClassUnit(classunit);
        SensorsConfig::setDelay(delay);
    }
}

void SimpleSensorMonitor::slotExit()
{
    this->close();
}

void SimpleSensorMonitor::contextMenuEvent(QContextMenuEvent *event)
{
    m_contextMenu.move(event->globalPos());
    m_contextMenu.show();
}
