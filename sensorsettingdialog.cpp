#include "sensorsconfig.h"
#include "sensorsettingdialog.h"
#include "ui_sensorsettingdialog.h"

SensorSettingDialog::SensorSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SensorSettingDialog)
{
    ui->setupUi(this);

    ui->edit_adapter->setText(SensorsConfig::getAdapter());
    ui->edit_sensor->setText(SensorsConfig::getSensor());
    ui->spinbox_delay->setValue(SensorsConfig::getDelay());

    ui->groupBox_2->hide();
    ui->label_3->setPixmap(QIcon("://sensor_u_helper.png").pixmap(409, 200));
}

SensorSettingDialog::~SensorSettingDialog()
{
    delete ui;
}

QString SensorSettingDialog::getAdapter()
{
    return ui->edit_adapter->text();
}

QString SensorSettingDialog::getSensor()
{
    return ui->edit_sensor->text();
}

QString SensorSettingDialog::getIdentifier()
{
    switch (ui->comboBox->currentIndex()) {
    case 0:
        return "温度";
        break;
    case 1:
        return "电压";
        break;
    case 2:
        return "电流";
        break;
    case 3:
        return "功耗";
        break;
    default:
        break;
    }
    return "#";
}

QString SensorSettingDialog::getClassUnit()
{
    switch (ui->comboBox->currentIndex()) {
    case 0:
        return "°C";
        break;
    case 1:
        return " V";
        break;
    case 2:
        return " A";
        break;
    case 3:
        return " W";
        break;
    default:
        break;
    }
    return "#";
}

int SensorSettingDialog::getDelay()
{
    return ui->spinbox_delay->value();
}

void SensorSettingDialog::on_pushButton_clicked()
{
    if (ui->groupBox->isHidden()) {
        ui->groupBox_2->hide();
        ui->groupBox->show();
    } else {
        ui->groupBox->hide();
        ui->groupBox_2->show();
    }

}

