/********************************************************************************
** Form generated from reading UI file 'dialogdevicedata.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDEVICEDATA_H
#define UI_DIALOGDEVICEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogDeviceData
{
public:
    QWidget *gridLayoutWidget;
    QFormLayout *formLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *DialogDeviceData)
    {
        if (DialogDeviceData->objectName().isEmpty())
            DialogDeviceData->setObjectName(QStringLiteral("DialogDeviceData"));
        DialogDeviceData->resize(400, 300);
        gridLayoutWidget = new QWidget(DialogDeviceData);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 20, 264, 194));
        formLayout = new QFormLayout(gridLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(gridLayoutWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, tableWidget);


        retranslateUi(DialogDeviceData);

        QMetaObject::connectSlotsByName(DialogDeviceData);
    } // setupUi

    void retranslateUi(QDialog *DialogDeviceData)
    {
        DialogDeviceData->setWindowTitle(QApplication::translate("DialogDeviceData", "\345\216\206\345\217\262\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogDeviceData: public Ui_DialogDeviceData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDEVICEDATA_H
