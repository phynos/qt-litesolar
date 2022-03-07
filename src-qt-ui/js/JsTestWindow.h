#ifndef JSTESTWINDOW_H
#define JSTESTWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <qtreewidget.h>

#include "qtjsruntime.h"

namespace Ui {
class JsTestWindow;
}

class JsTestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit JsTestWindow(QWidget *parent = 0);
    ~JsTestWindow();

    void QTreeWidgetTest();

private slots:
    void on_pushButton_clicked();
    void receiveMsgFromThread(QString);

    void showJsFile(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::JsTestWindow *ui;

    QFileSystemModel *fsModel;

    QtJsRuntime *qtJsRuntime;

signals:
    void runJsExpr(QString);
    void runJsIndexFile();
};

#endif // JSTESTWINDOW_H
