#include "configutil.h"
#include "sensorsconfig.h"

#include <QSettings>

#define KEY_ADAPTER      "adapter"
#define KEY_SENSOR       "sensor"
#define KEY_IDENTIFIER   "identifier"
#define KEY_CLASSUNIT    "classunit"
#define KEY_DELAY        "delay"

#define KEY_X            "x"
#define KEY_Y            "y"

QString SensorsConfig::getAdapter()
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    return config.value(KEY_ADAPTER).toString();
}

QString SensorsConfig::getSensor()
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    return config.value(KEY_SENSOR).toString();
}

QString SensorsConfig::getIdentifier()
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    return config.value(KEY_IDENTIFIER).toString();
}

QString SensorsConfig::getClassUnit()
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    return config.value(KEY_CLASSUNIT).toString();
}

int SensorsConfig::getDelay()
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);

    bool ok = true;
    int delay = config.value(KEY_DELAY).toInt(&ok);
    if (!ok) {
        delay = 500;
    }

    return delay;
}

void SensorsConfig::setAdapter(QString &adapter)
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    config.setValue(KEY_ADAPTER, adapter);
}

void SensorsConfig::setSensor(QString &sensor)
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    config.setValue(KEY_SENSOR, sensor);
}

void SensorsConfig::setIdentifier(QString &identifier)
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    config.setValue(KEY_IDENTIFIER, identifier);
}

void SensorsConfig::setClassUnit(QString &classunit)
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    config.setValue(KEY_CLASSUNIT, classunit);
}

void SensorsConfig::setDelay(int delay)
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    config.setValue(KEY_DELAY, delay);
}

// Location
int SensorsConfig::x()
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    return config.value(KEY_X).toInt();
}

int SensorsConfig::y()
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    return config.value(KEY_Y).toInt();
}

void SensorsConfig::setX(int x)
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    config.setValue(KEY_X, x);
}

void SensorsConfig::setY(int y)
{
    QSettings config = QSettings(configPath(), QSettings::IniFormat);
    config.setValue(KEY_Y, y);
}


QString SensorsConfig::configPath()
{
    return ConfigUtil::configPath();
}
