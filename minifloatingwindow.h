#ifndef MINIFLOATINGWINDOW_H
#define MINIFLOATINGWINDOW_H

#include <QWidget>

namespace Ui {
class MiniFloatingWindow;
}

class MiniFloatingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MiniFloatingWindow(QWidget *parent = nullptr);
    ~MiniFloatingWindow();

    void setIconWidget(QWidget *icon);
    void setContainerWidget(QWidget *container);

private:
    QString execDir();
    void resetLocaltion();
    void restoreLocaltion();

private:
    Ui::MiniFloatingWindow *ui;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint position() const;
    void setPosition(QPoint newPosition);
    bool drag() const;
    void setDrag(bool newDrag);

    QPoint m_position;
    bool m_drag;
};

#endif // MINIFLOATINGWINDOW_H
