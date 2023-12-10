#ifndef SENSORSETTINGDIALOG_H
#define SENSORSETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class SensorSettingDialog;
}

class SensorSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SensorSettingDialog(QWidget *parent = nullptr);
    ~SensorSettingDialog();

    QString getAdapter();
    QString getSensor();
    QString getIdentifier();
    QString getClassUnit();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SensorSettingDialog *ui;
};

#endif // SENSORSETTINGDIALOG_H
