#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtreewidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void QTreeWidgetTest();

private slots:
    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_action4_2_triggered();

private:
    Ui::MainWindow *ui;

    void setupView();
    void setupStateBar();

};

#endif // MAINWINDOW_H
