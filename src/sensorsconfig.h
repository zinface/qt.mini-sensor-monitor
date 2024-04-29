#ifndef SENSORSCONFIG_H
#define SENSORSCONFIG_H

#include <QString>

class SensorsConfig
{
public:
    // 应用配置封装
    static QString getAdapter();
    static QString getSensor();
    static QString getIdentifier();
    static QString getClassUnit();
    static int getDelay();

    static void setAdapter(QString &adapter);
    static void setSensor(QString &sensor);
    static void setIdentifier(QString &identifier);
    static void setClassUnit(QString &classunit);
    static void setDelay(int delay);

    // Location
    static int x();
    static int y();
    static void setX(int x);
    static void setY(int y);


private:
    static QString configPath();
};

#endif // SENSORSCONFIG_H
