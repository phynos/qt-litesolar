#include "mainwindow.h"
#include "js/JsTestWindow.h"
#include <QApplication>

#include <QTextCodec>

#include <qstyle.h>
#include <qstylefactory.h>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QStringList ss = QStyleFactory::keys();
    foreach (QString s , ss) {
        qDebug() << s;
    }

    QApplication::setStyle("WindowsXP");

    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    JsTestWindow j;
    j.show();

    return a.exec();
}
