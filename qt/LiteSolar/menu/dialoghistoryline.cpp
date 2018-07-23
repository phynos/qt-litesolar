#include "dialoghistoryline.h"
#include "ui_dialoghistoryline.h"


DialogHistoryLine::DialogHistoryLine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHistoryLine)
{
    ui->setupUi(this);

    Qt::WindowFlags flag = Qt::Dialog;
    flag |= Qt::WindowCloseButtonHint;
    setWindowFlags(flag);

    setupView();
}

DialogHistoryLine::~DialogHistoryLine()
{
    delete ui;
}

void DialogHistoryLine::setupView()
{

}
