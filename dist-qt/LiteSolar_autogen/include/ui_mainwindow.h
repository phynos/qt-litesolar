/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBegin;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *actionOffical;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionStop;
    QAction *actionSetting;
    QAction *actionExit;
    QAction *actionNewUnit;
    QAction *actionEditUnit;
    QAction *action3;
    QAction *action4;
    QAction *action5;
    QAction *action6;
    QAction *action1_2;
    QAction *action2_2;
    QAction *action3_2;
    QAction *action4_2;
    QAction *action5_2;
    QAction *action7;
    QAction *actionDdfdf;
    QAction *actionExport;
    QAction *actionImport;
    QAction *actionModbus;
    QAction *actionMain;
    QAction *actionTree;
    QAction *actionDebug;
    QAction *actionPower;
    QAction *actionShow;
    QAction *actionHide;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDevice;
    QMenu *menuData;
    QMenu *menu_3;
    QMenu *menuHelp;
    QMenu *menu;
    QMenu *menuForm;
    QMenu *menuChart;
    QMenu *menu_2;
    QToolBar *toolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetTree;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;
    QDockWidget *dockWidgetOutput;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_2;
    QListView *listView;
    QDockWidget *dockWidgetAlarms;
    QWidget *dockWidgetContents_4;
    QGridLayout *gridLayout_5;
    QListView *listView_2;
    QDockWidget *dockWidgetMain;
    QWidget *dockWidgetContents_5;
    QGridLayout *gridLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1024, 768));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/prefix1/rc/ic_launcher.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDocumentMode(false);
        actionBegin = new QAction(MainWindow);
        actionBegin->setObjectName(QStringLiteral("actionBegin"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/rc/icon-play.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon1);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/rc/icon-stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon2);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/rc/edit-device.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon3);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/rc/iocn-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_4->setIcon(icon4);
        actionOffical = new QAction(MainWindow);
        actionOffical->setObjectName(QStringLiteral("actionOffical"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionSetting = new QAction(MainWindow);
        actionSetting->setObjectName(QStringLiteral("actionSetting"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNewUnit = new QAction(MainWindow);
        actionNewUnit->setObjectName(QStringLiteral("actionNewUnit"));
        actionEditUnit = new QAction(MainWindow);
        actionEditUnit->setObjectName(QStringLiteral("actionEditUnit"));
        action3 = new QAction(MainWindow);
        action3->setObjectName(QStringLiteral("action3"));
        action4 = new QAction(MainWindow);
        action4->setObjectName(QStringLiteral("action4"));
        action5 = new QAction(MainWindow);
        action5->setObjectName(QStringLiteral("action5"));
        action6 = new QAction(MainWindow);
        action6->setObjectName(QStringLiteral("action6"));
        action1_2 = new QAction(MainWindow);
        action1_2->setObjectName(QStringLiteral("action1_2"));
        action2_2 = new QAction(MainWindow);
        action2_2->setObjectName(QStringLiteral("action2_2"));
        action3_2 = new QAction(MainWindow);
        action3_2->setObjectName(QStringLiteral("action3_2"));
        action4_2 = new QAction(MainWindow);
        action4_2->setObjectName(QStringLiteral("action4_2"));
        action5_2 = new QAction(MainWindow);
        action5_2->setObjectName(QStringLiteral("action5_2"));
        action7 = new QAction(MainWindow);
        action7->setObjectName(QStringLiteral("action7"));
        actionDdfdf = new QAction(MainWindow);
        actionDdfdf->setObjectName(QStringLiteral("actionDdfdf"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionModbus = new QAction(MainWindow);
        actionModbus->setObjectName(QStringLiteral("actionModbus"));
        actionMain = new QAction(MainWindow);
        actionMain->setObjectName(QStringLiteral("actionMain"));
        actionTree = new QAction(MainWindow);
        actionTree->setObjectName(QStringLiteral("actionTree"));
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName(QStringLiteral("actionDebug"));
        actionPower = new QAction(MainWindow);
        actionPower->setObjectName(QStringLiteral("actionPower"));
        actionShow = new QAction(MainWindow);
        actionShow->setObjectName(QStringLiteral("actionShow"));
        actionHide = new QAction(MainWindow);
        actionHide->setObjectName(QStringLiteral("actionHide"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        centralWidget->setAutoFillBackground(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDevice = new QMenu(menuBar);
        menuDevice->setObjectName(QStringLiteral("menuDevice"));
        menuData = new QMenu(menuBar);
        menuData->setObjectName(QStringLiteral("menuData"));
        menu_3 = new QMenu(menuData);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuForm = new QMenu(menuBar);
        menuForm->setObjectName(QStringLiteral("menuForm"));
        menuChart = new QMenu(menuBar);
        menuChart->setObjectName(QStringLiteral("menuChart"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidgetTree = new QDockWidget(MainWindow);
        dockWidgetTree->setObjectName(QStringLiteral("dockWidgetTree"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        sizePolicy.setHeightForWidth(dockWidgetContents->sizePolicy().hasHeightForWidth());
        dockWidgetContents->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeWidget = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(100, 0));
        treeWidget->setMaximumSize(QSize(16777215, 16777215));
        treeWidget->setHeaderHidden(true);

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);

        dockWidgetTree->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetTree);
        dockWidgetOutput = new QDockWidget(MainWindow);
        dockWidgetOutput->setObjectName(QStringLiteral("dockWidgetOutput"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        sizePolicy.setHeightForWidth(dockWidgetContents_2->sizePolicy().hasHeightForWidth());
        dockWidgetContents_2->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(dockWidgetContents_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listView = new QListView(dockWidgetContents_2);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout_2->addWidget(listView, 0, 0, 1, 1);

        dockWidgetOutput->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetOutput);
        dockWidgetAlarms = new QDockWidget(MainWindow);
        dockWidgetAlarms->setObjectName(QStringLiteral("dockWidgetAlarms"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        gridLayout_5 = new QGridLayout(dockWidgetContents_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        listView_2 = new QListView(dockWidgetContents_4);
        listView_2->setObjectName(QStringLiteral("listView_2"));

        gridLayout_5->addWidget(listView_2, 0, 0, 1, 1);

        dockWidgetAlarms->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetAlarms);
        dockWidgetMain = new QDockWidget(MainWindow);
        dockWidgetMain->setObjectName(QStringLiteral("dockWidgetMain"));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        gridLayout_4 = new QGridLayout(dockWidgetContents_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        stackedWidget = new QStackedWidget(dockWidgetContents_5);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout_4->addWidget(stackedWidget, 0, 0, 1, 1);

        dockWidgetMain->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetMain);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDevice->menuAction());
        menuBar->addAction(menuChart->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menuData->menuAction());
        menuBar->addAction(menuForm->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionBegin);
        menuFile->addAction(actionStop);
        menuFile->addSeparator();
        menuFile->addAction(actionSetting);
        menuFile->addSeparator();
        menuFile->addAction(actionImport);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuDevice->addAction(actionNewUnit);
        menuDevice->addAction(actionEditUnit);
        menuDevice->addSeparator();
        menuDevice->addAction(action3);
        menuDevice->addAction(action4);
        menuDevice->addAction(action5);
        menuDevice->addSeparator();
        menuDevice->addAction(action6);
        menuData->addAction(action4_2);
        menuData->addAction(action5_2);
        menuData->addSeparator();
        menuData->addAction(menu_3->menuAction());
        menuData->addAction(action7);
        menu_3->addAction(actionDdfdf);
        menuHelp->addAction(actionOffical);
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menu->addAction(actionModbus);
        menuForm->addAction(actionMain);
        menuForm->addAction(actionTree);
        menuForm->addAction(actionDebug);
        menuForm->addSeparator();
        menuForm->addAction(actionShow);
        menuForm->addAction(actionHide);
        menuChart->addAction(action1_2);
        menuChart->addAction(action2_2);
        menuChart->addAction(action3_2);
        menu_2->addAction(actionPower);
        toolBar->addAction(action);
        toolBar->addAction(action_2);
        toolBar->addAction(action_3);
        toolBar->addSeparator();
        toolBar->addAction(action_4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LiteSolar", Q_NULLPTR));
        actionBegin->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\351\200\232\350\256\257", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBegin->setToolTip(QApplication::translate("MainWindow", "\345\274\200\345\247\213\351\200\232\350\256\257", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        action_4->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\350\256\276\345\244\207", Q_NULLPTR));
        actionOffical->setText(QApplication::translate("MainWindow", "\345\256\230\347\275\221", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        actionStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\351\200\232\350\256\257", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "\345\201\234\346\255\242\351\200\232\350\256\257", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSetting->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSetting->setToolTip(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionNewUnit->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\206\345\214\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionNewUnit->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\206\345\214\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionEditUnit->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\345\210\206\345\214\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionEditUnit->setToolTip(QApplication::translate("MainWindow", "\347\274\226\350\276\221\345\210\206\345\214\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action3->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\256\276\345\244\207", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action3->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\256\276\345\244\207", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action4->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\256\276\345\244\207", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action4->setToolTip(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\256\276\345\244\207", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action5->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\276\345\244\207", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action5->setToolTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\276\345\244\207", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action6->setText(QApplication::translate("MainWindow", "\346\211\271\351\207\217\345\210\240\351\231\244\350\256\276\345\244\207", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action6->setToolTip(QApplication::translate("MainWindow", "\346\211\271\351\207\217\345\210\240\351\231\244\350\256\276\345\244\207", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action1_2->setText(QApplication::translate("MainWindow", "\345\256\236\346\227\266\346\233\262\347\272\277", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action1_2->setToolTip(QApplication::translate("MainWindow", "\345\256\236\346\227\266\346\233\262\347\272\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action2_2->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\233\262\347\272\277", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action2_2->setToolTip(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\233\262\347\272\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action3_2->setText(QApplication::translate("MainWindow", "\345\217\221\347\224\265\347\273\237\350\256\241", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action3_2->setToolTip(QApplication::translate("MainWindow", "\345\217\221\347\224\265\347\273\237\350\256\241", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action4_2->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action4_2->setToolTip(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action5_2->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\344\272\213\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action5_2->setToolTip(QApplication::translate("MainWindow", "\345\216\206\345\217\262\344\272\213\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action7->setText(QApplication::translate("MainWindow", "\345\205\211\344\274\217\346\212\245\350\241\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action7->setToolTip(QApplication::translate("MainWindow", "\345\205\211\344\274\217\346\212\245\350\241\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionDdfdf->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\257\274\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDdfdf->setToolTip(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\257\274\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionExport->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", Q_NULLPTR));
        actionImport->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", Q_NULLPTR));
        actionModbus->setText(QApplication::translate("MainWindow", "Modbus\345\234\260\345\235\200\346\216\242\346\265\213", Q_NULLPTR));
        actionMain->setText(QApplication::translate("MainWindow", "\344\270\273\347\252\227\345\217\243", Q_NULLPTR));
        actionTree->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\346\240\221", Q_NULLPTR));
        actionDebug->setText(QApplication::translate("MainWindow", "\350\260\203\350\257\225\350\276\223\345\207\272\347\252\227\345\217\243", Q_NULLPTR));
        actionPower->setText(QApplication::translate("MainWindow", "\345\212\237\347\216\207\345\210\206\346\236\220", Q_NULLPTR));
        actionShow->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\211\200\346\234\211", Q_NULLPTR));
        actionHide->setText(QApplication::translate("MainWindow", "\351\232\220\350\227\217\346\211\200\346\234\211", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237", Q_NULLPTR));
        menuDevice->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", Q_NULLPTR));
        menuData->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\257\274\345\207\272", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", Q_NULLPTR));
        menuForm->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243", Q_NULLPTR));
        menuChart->setTitle(QApplication::translate("MainWindow", "\345\233\276\350\241\250", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\210\206\346\236\220", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        dockWidgetTree->setWindowTitle(QApplication::translate("MainWindow", "\350\256\276\345\244\207\346\240\221", Q_NULLPTR));
        dockWidgetOutput->setWindowTitle(QApplication::translate("MainWindow", "\350\260\203\350\257\225\350\276\223\345\207\272", Q_NULLPTR));
        dockWidgetAlarms->setWindowTitle(QApplication::translate("MainWindow", "\344\272\213\344\273\266\345\222\214\345\221\212\350\255\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
