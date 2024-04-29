#ifndef CONFIGUTIL_H
#define CONFIGUTIL_H

#include <qstring.h>

class ConfigUtil
{
public:
    static QString homeDir();
    static QString configDir();

    static void mkdir(QString &dirPath);

    static QString execDir();

    static QString appConfigDir();
    static QString configPath();
};

#endif // CONFIGUTIL_H
