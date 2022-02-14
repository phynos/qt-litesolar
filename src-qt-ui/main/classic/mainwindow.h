#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>


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

    //移除并隐藏所有dock
    void removeAllDock();
    //显示dock窗口
    void showDock(const QList<int>& index = QList<int>());

private slots:
    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_action4_2_triggered();

    void on_actionSetting_triggered();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;

    void setupView();
    void setupStateBar();
};

#endif // MAINWINDOW_H
