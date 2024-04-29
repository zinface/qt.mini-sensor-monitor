#ifndef SIMPLESENSORMONITOR_H
#define SIMPLESENSORMONITOR_H

#include "minifloatingicon.h"
#include "qlabel.h"
#include <QWidget>
#include <qmenu.h>

class SensorsMonitor;
class SimpleSensorMonitor : public MiniFloatingIcon
{
    Q_OBJECT
public:
    explicit SimpleSensorMonitor(QWidget *parent = nullptr);

    void resetConfig();
    void restoreConfig();

public slots:
    void slotSensorUpdated(float value);

    void slotDisplaySettingDialog();
    void slotExit();

    // QWidget interface
protected:
    void contextMenuEvent(QContextMenuEvent *event);

private:
    QLabel *m_lable;
    SensorsMonitor *m_monitor;

    QMenu m_contextMenu;


    QString m_identifier;
    QString m_classunit;
};

#endif // SIMPLESENSORMONITOR_H
