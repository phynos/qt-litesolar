#include "formdevice.h"
#include "ui_formdevice.h"

FormDevice::FormDevice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDevice)
{
    ui->setupUi(this);
}

FormDevice::~FormDevice()
{
    delete ui;
}
