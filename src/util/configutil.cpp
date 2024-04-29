#include "configutil.h"

#include <QApplication>
#include <QDir>


QString ConfigUtil::homeDir()
{
    return QDir::homePath() + QDir::separator();
}
QString ConfigUtil::configDir()
{
    QString path = homeDir() + ".config";
    return path + QDir::separator();
}

void ConfigUtil::mkdir(QString &dirPath)
{
    if (!QDir(dirPath).exists()) {
        QDir(dirPath).mkpath("");
    }
}

QString ConfigUtil::execDir()
{
    QString path = QApplication::applicationDirPath();
    return path + QDir::separator();
}

QString ConfigUtil::appConfigDir()
{
    QString path = configDir() + "simple-sensor-monitor";
    mkdir(path);
    return path + QDir::separator();
}

QString ConfigUtil::configPath()
{
#ifdef QT_DEBUG
    return execDir() + "config.ini";
#else
    return appConfigDir() + "config.ini";
#endif
}
