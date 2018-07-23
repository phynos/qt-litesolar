#include "dialogevents.h"
#include "ui_dialogevents.h"

DialogEvents::DialogEvents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEvents)
{
    ui->setupUi(this);
}

DialogEvents::~DialogEvents()
{
    delete ui;
}
