#include "mainwindow.h"
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
    MainWindow w;
    w.show();

    return a.exec();
}
