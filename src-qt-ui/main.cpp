#include <QApplication>
#include <QFile>
#include <QTextCodec>

#include <qstyle.h>
#include <qstylefactory.h>
#include <qdebug.h>

#include "main/classic/mainwindow.h"
#include "main/modern/uidemo08.h"
#include "main/modern/appinit.h"

#include "js/jstestwindow.h"

#define APP 2

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //加载样式表 lightblue  flatwhite psblack
    QFile file(":/qss/psblack.css");
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
     a.setFont(QFont("Microsoft Yahei", 9));
#if APP == 1
    MainWindow w;
    w.show();
#elif APP == 2   
    AppInit::Instance()->start();
    UIDemo08 w;
    w.show();
#else
    JsTestWindow w;
    w.show();
#endif
    return a.exec();
}
