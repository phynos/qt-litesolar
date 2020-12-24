#include "dialogdeviceevents.h"
#include "ui_dialogdeviceevents.h"

DialogDeviceEvents::DialogDeviceEvents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDeviceEvents)
{
    ui->setupUi(this);

    Qt::WindowFlags flag = Qt::Dialog;
    flag |= Qt::WindowCloseButtonHint;
    setWindowFlags(flag);
}

DialogDeviceEvents::~DialogDeviceEvents()
{
    delete ui;
}
