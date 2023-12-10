#include "configutil.h"
#include "minifloatingwindow.h"
#include "ui_minifloatingwindow.h"

#include <QDir>
#include <QMouseEvent>
#include <QSettings>

MiniFloatingWindow::MiniFloatingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniFloatingWindow),
    m_drag(false)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    resetLocaltion();
}

MiniFloatingWindow::~MiniFloatingWindow()
{
    delete ui;
}

void MiniFloatingWindow::setIconWidget(QWidget *icon)
{
    ui->icon->addWidget(icon);
}

void MiniFloatingWindow::setContainerWidget(QWidget *container)
{
    ui->container->addWidget(container);
}

QString MiniFloatingWindow::execDir()
{
    return QApplication::applicationDirPath() + QDir::separator();
}

void MiniFloatingWindow::resetLocaltion()
{
//    QSettings config(execDir() + "location.ini", QSettings::IniFormat);
    QSettings config(ConfigUtil::configPath(), QSettings::IniFormat);
    move(config.value("x").toInt(), config.value("y").toInt());
}

void MiniFloatingWindow::restoreLocaltion()
{
//    QSettings config(execDir() + "location.ini", QSettings::IniFormat);
    //    QSettings config(execDir() + "location.ini", QSettings::IniFormat);
    QSettings config(ConfigUtil::configPath(), QSettings::IniFormat);
    config.setValue("x", x());
    config.setValue("y", y());
}

void MiniFloatingWindow::mousePressEvent(QMouseEvent *event)
{
    setDrag(true);
    m_position = event->pos();
}

void MiniFloatingWindow::mouseReleaseEvent(QMouseEvent *event)
{
    setDrag(false);
    restoreLocaltion();
}

void MiniFloatingWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (drag()) {
        move(event->globalPos() - m_position);
    }
}

bool MiniFloatingWindow::drag() const
{
    return m_drag;
}

void MiniFloatingWindow::setDrag(bool newDrag)
{
    m_drag = newDrag;
}

QPoint MiniFloatingWindow::position() const
{
    return m_position;
}

void MiniFloatingWindow::setPosition(QPoint newPosition)
{
    m_position = newPosition;
}
