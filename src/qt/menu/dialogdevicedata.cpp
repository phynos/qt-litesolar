#include "dialogdevicedata.h"
#include "ui_dialogdevicedata.h"

#include <QStandardItemModel>

DialogDeviceData::DialogDeviceData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDeviceData)
{
    ui->setupUi(this);

    Qt::WindowFlags flag = Qt::Dialog;
    flag |= Qt::WindowCloseButtonHint;
    flag |= Qt::WindowMaximizeButtonHint;
    flag |= Qt::WindowMinimizeButtonHint;
    setWindowFlags(flag);

    QTableWidget *table = ui->tableWidget;
    loadDataFromCode(table);
}

DialogDeviceData::~DialogDeviceData()
{
    delete ui;
}

void DialogDeviceData::loadDataFromCode(QTableWidget *table)
{
    table->setColumnCount(3);
    table->setRowCount(5);
    QStringList headers;
    headers << "Line Number" << "ID" << "Name" << "Age" << "Sex";
    table->setHorizontalHeaderLabels(headers);
    table->setItem(0, 0, new QTableWidgetItem(QString("1")));
    table->setItem(1, 0, new QTableWidgetItem(QString("2")));
    table->setItem(2, 0, new QTableWidgetItem(QString("3")));
    table->setItem(3, 0, new QTableWidgetItem(QString("4")));
    table->setItem(4, 0, new QTableWidgetItem(QString("5")));
    table->setItem(0, 1, new QTableWidgetItem(tr("20100112")));
}

void DialogDeviceData::loadDataFromModel(QTableWidget *table)
{
    QStandardItemModel model(4,4);
    model.setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
    model.setHeaderData(1,Qt::Horizontal,QObject::tr("Birthday"));
    model.setHeaderData(2,Qt::Horizontal,QObject::tr("Job"));
    model.setHeaderData(3,Qt::Horizontal,QObject::tr("Income"));
}
