#include <QApplication>
#include <QFile>
#include <QTextCodec>

#include <qstyle.h>
#include <qstylefactory.h>
#include <qdebug.h>

#include "main/classic/mainwindow.h"
#include "main/modern/uidemo08.h"
#include "main/modern/appinit.h"

#define APP 2

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if APP == 1
    MainWindow w;
    w.show();
#else
    //加载样式表
    QFile file(":/qss/flatwhite.css");
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
    a.setFont(QFont("Microsoft Yahei", 9));
    AppInit::Instance()->start();
    UIDemo08 w;
    w.show();
#endif
    return a.exec();
}
