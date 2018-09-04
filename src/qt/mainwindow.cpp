#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QMessageBox>
#include <QLabel>
#include <QFile>
#include <QWidget>
#include <QMouseEvent>

#include "menu/dialogsetting.h"
#include "menu/dialogabout.h"
#include "menu/dialogdevicedata.h"
#include "notify/notifymanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowState(Qt::WindowNoState);
    setMinimumSize(800,600);

    QFile file(":/qss/rc/css.qss");
    file.open(QFile::ReadOnly);
    QByteArray bytes = file.readAll();
    QString styleSheet = bytes.data();
    qApp->setStyleSheet(styleSheet);

    setupView();
    setupStateBar();
    QTreeWidgetTest();
    //QMessageBox::information(this,tr("asdfadsf"),tr("adsfasdf"),QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    setCentralWidget(ui->dockWidgetMain);

    //允许嵌套dock
    //setDockNestingEnabled(true);
    //记录所有的dock指针
    //m_docks.append(ui->dockWidget_2);

    //splitDockWidget(ui->dockWidget,ui->dockWidget_2,Qt::Horizontal);

    NotifyManager *manager = new NotifyManager(this);
    manager->notify("新消息", "新消息新消息新消息新消息", "://img/message.png", "http://www.github.com");
}

void MainWindow::QTreeWidgetTest()
{
    QTreeWidgetItem *rootItem_1 = new QTreeWidgetItem(ui->treeWidget);
    QTreeWidgetItem *childItem_1_1 = new QTreeWidgetItem();
    QTreeWidgetItem *childItem_1_2 = new QTreeWidgetItem();

    QTreeWidgetItem *childItem_1_2_1 = new QTreeWidgetItem();

    QTreeWidgetItem *rootItem_2 = new QTreeWidgetItem(ui->treeWidget);
    QTreeWidgetItem *childItem_2_1 = new QTreeWidgetItem();
    QTreeWidgetItem *childItem_2_2 = new QTreeWidgetItem();
    QTreeWidgetItem *childItem_2_3 = new QTreeWidgetItem();

    rootItem_1->setText(0,QObject::tr("常用文件夹"));
    childItem_1_1->setText(0,QObject::tr("所有未读"));
    childItem_1_2->setText(0,QObject::tr("置顶邮件"));
    childItem_1_2_1->setText(0,QObject::tr("测试"));
    childItem_1_2_1->setForeground(0,QBrush(QColor(Qt::blue)));

    rootItem_2->setText(0,QObject::tr("我的邮箱"));
    childItem_2_1->setText(0,QObject::tr("收件箱"));
    childItem_2_2->setText(0,QObject::tr("草稿箱"));
    childItem_2_3->setText(0,QObject::tr("发件箱"));

    ui->treeWidget->addTopLevelItem(rootItem_1);
    rootItem_1->addChild(childItem_1_1);
    rootItem_1->addChild(childItem_1_2);
    childItem_1_2->addChild(childItem_1_2_1);
    ui->treeWidget->addTopLevelItem(rootItem_2);
    rootItem_2->addChild(childItem_2_1);
    rootItem_2->addChild(childItem_2_2);
    rootItem_2->addChild(childItem_2_3);
}

void MainWindow::removeAllDock()
{
    for(int i=0;i < m_docks.size();++i)
    {
        removeDockWidget(m_docks[i]);
    }
}

void MainWindow::showDock(const QList<int> &index)
{
    if (index.isEmpty())
     {
         for(int i=0;i<m_docks.size();++i)
         {
             m_docks[i]->show();
         }
     }
     else
     {
         foreach (int i, index) {
             m_docks[i]->show();
         }
     }
}

void MainWindow::setupView()
{
    //目录
    //系统设置
    //增加设备
    //删除设备
    //修改设备

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
