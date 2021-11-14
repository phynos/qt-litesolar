/********************************************************************************
** Form generated from reading UI file 'formdevice.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDEVICE_H
#define UI_FORMDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormDevice
{
public:

    void setupUi(QWidget *FormDevice)
    {
        if (FormDevice->objectName().isEmpty())
            FormDevice->setObjectName(QStringLiteral("FormDevice"));
        FormDevice->resize(400, 300);

        retranslateUi(FormDevice);

        QMetaObject::connectSlotsByName(FormDevice);
    } // setupUi

    void retranslateUi(QWidget *FormDevice)
    {
        FormDevice->setWindowTitle(QApplication::translate("FormDevice", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormDevice: public Ui_FormDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDEVICE_H
