#include "minifloatingicon.h"

#include <QIcon>

MiniFloatingIcon::MiniFloatingIcon(QWidget *parent)
    : MiniFloatingWindow{parent}
{
    m_icon = new QLabel;
    setIconWidget(m_icon);
}

void MiniFloatingIcon::setIcon(const QString &icon)
{
    if (icon.startsWith(":/")) {
        setIcon(QIcon(icon));
    }
}

void MiniFloatingIcon::setIcon(const QIcon &icon)
{
    setIcon(icon.pixmap(45, 40));
}

void MiniFloatingIcon::setIcon(const QPixmap &pixmap)
{
    m_icon->setPixmap(pixmap);
}

void MiniFloatingIcon::setWidget(QWidget *widget)
{
    setContainerWidget(widget);
}

QLabel *MiniFloatingIcon::iconWidget()
{
    return m_icon;
}
