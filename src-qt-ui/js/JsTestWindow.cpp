#include "JsTestWindow.h"
#include "ui_JsTestWindow.h"

#include <QDebug>
#include <QTextCodec>

JsTestWindow::JsTestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JsTestWindow)
{
    ui->setupUi(this);

    qtJsRuntime = new QtJsRuntime();
    qtJsRuntime->startThread();
    //
    connect(qtJsRuntime, &QtJsRuntime::sendMsgToMain, this, &JsTestWindow::receiveMsgFromThread);
    //
    connect(this, &JsTestWindow::runJsExpr, qtJsRuntime, &QtJsRuntime::runJsExpr);
    connect(this, &JsTestWindow::runJsIndexFile, qtJsRuntime, &QtJsRuntime::runJsIndexFile);


    fsModel = new QFileSystemModel(this);
    QDir dir = QDir::current();
    QString currPath = dir.absoluteFilePath("js");
    fsModel->setRootPath(currPath);
    fsModel->setNameFilters(QStringList() << "*.js");
    ui->treeView->setModel(fsModel);
    ui->treeView->setRootIndex(fsModel->index(currPath));
    //
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(showJsFile(QModelIndex)));   
}

JsTestWindow::~JsTestWindow()
{
    delete ui;
}

void JsTestWindow::on_pushButton_clicked()
{
    QString LogInfo;
    LogInfo.sprintf("主线程：%p", QThread::currentThread());
    ui->listWidget->addItem(LogInfo);
    emit runJsIndexFile();
}

void JsTestWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
}

void JsTestWindow::showJsFile(const QModelIndex &index)
{
    QFileInfo fileInfo = fsModel->fileInfo(index);
    if (fileInfo.isFile())
    {
        QFile file(fileInfo.absoluteFilePath());
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextCodec *codec = QTextCodec::codecForName("UTF8");
        QString a = codec->fromUnicode(file.readAll());
        ui->textBrowser->setText(a);
        file.close();
    }
}

//接收线程函数
void JsTestWindow::receiveMsgFromThread(QString msg)
{
    qDebug() << msg;
    ui->listWidget->addItem(msg);
    ui->listWidget->scrollToBottom();
}
