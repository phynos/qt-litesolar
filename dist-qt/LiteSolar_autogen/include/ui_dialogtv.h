/********************************************************************************
** Form generated from reading UI file 'dialogtv.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTV_H
#define UI_DIALOGTV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogTV
{
public:

    void setupUi(QDialog *DialogTV)
    {
        if (DialogTV->objectName().isEmpty())
            DialogTV->setObjectName(QStringLiteral("DialogTV"));
        DialogTV->resize(400, 300);

        retranslateUi(DialogTV);

        QMetaObject::connectSlotsByName(DialogTV);
    } // setupUi

    void retranslateUi(QDialog *DialogTV)
    {
        DialogTV->setWindowTitle(QApplication::translate("DialogTV", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogTV: public Ui_DialogTV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTV_H
