#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QtDebug>
#include <QMessageBox>
#include <QLabel>
#include <QFile>
#include <QWidget>
#include <QMouseEvent>
#include <QTextCodec>

#include "../../menu/dialogsetting.h"
#include "../../menu/dialogabout.h"
#include "../../menu/dialogdevicedata.h"
#include "../../notify/notifymanager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowState(Qt::WindowNoState);
    setMinimumSize(800, 600);

    QFile file(":/qss/classic.qss");
    file.open(QFile::ReadOnly);
    QByteArray bytes = file.readAll();
    QString styleSheet = bytes.data();
    qApp->setStyleSheet(styleSheet);

    setupView();
    setupStateBar();
    QTreeWidgetTest();
    //QMessageBox::information(this,tr("asdfadsf"),tr("adsfasdf"),QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    NotifyManager *manager = new NotifyManager(this);
    manager->notify("新消息", "新消息新消息新消息新消息", "://img/message.png", "http://www.github.com");

}

void MainWindow::QTreeWidgetTest()
{
int a;
}

void MainWindow::removeAllDock()
{
}

void MainWindow::showDock(const QList<int> &index)
{
}

void MainWindow::setupView()
{
    //目录
    //系统设置
    //增加设备
    //删除设备
    //修改设备
int b;
    //实时曲线
    //历史曲线
    //历史数据
    //历史事件
    //发电统计
    //电视显示
}

void MainWindow::setupStateBar()
{
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionAbout_triggered()
{
    DialogAbout dialog(this);
    dialog.setModal(true);
    dialog.exec();
}

void MainWindow::on_action4_2_triggered()
{
    DialogDeviceData dialog(this);
    dialog.setModal(true);
    dialog.exec();
}

void MainWindow::on_actionSetting_triggered()
{
    DialogSetting dialog(this);
    dialog.setModal(true);
    dialog.exec();
}

void MainWindow::on_action_triggered()
{

}


