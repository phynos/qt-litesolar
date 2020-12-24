#include "dialogtv.h"
#include "ui_dialogtv.h"

#include <QPainter>
#include <QPen>


DialogTV::DialogTV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTV)
{
    ui->setupUi(this);
    //全屏显示
    this->setWindowFlags (Qt::Window);
    this->showFullScreen ();
    //背景黑色
    this->setStyleSheet("background-color: white;");
}

DialogTV::~DialogTV()
{
    delete ui;
}

void DialogTV::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::darkCyan);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawLine(6,6,44,44);

}
