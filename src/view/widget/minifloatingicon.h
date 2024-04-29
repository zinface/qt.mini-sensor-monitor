#ifndef MINIFLOATINGICON_H
#define MINIFLOATINGICON_H

#include "minifloatingwindow.h"

#include <QLabel>
#include <QWidget>

class MiniFloatingIcon : public MiniFloatingWindow
{
    Q_OBJECT
public:
    explicit MiniFloatingIcon(QWidget *parent = nullptr);

    void setIcon(const QString &icon);
    void setIcon(const QIcon &icon);
    void setIcon(const QPixmap &pixmap);
    void setWidget(QWidget *widget);
    QLabel *iconWidget();

signals:

private:
    QLabel *m_icon;
};

#endif // MINIFLOATINGICON_H
