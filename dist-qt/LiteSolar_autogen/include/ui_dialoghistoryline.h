/********************************************************************************
** Form generated from reading UI file 'dialoghistoryline.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGHISTORYLINE_H
#define UI_DIALOGHISTORYLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogHistoryLine
{
public:

    void setupUi(QDialog *DialogHistoryLine)
    {
        if (DialogHistoryLine->objectName().isEmpty())
            DialogHistoryLine->setObjectName(QStringLiteral("DialogHistoryLine"));
        DialogHistoryLine->resize(400, 300);

        retranslateUi(DialogHistoryLine);

        QMetaObject::connectSlotsByName(DialogHistoryLine);
    } // setupUi

    void retranslateUi(QDialog *DialogHistoryLine)
    {
        DialogHistoryLine->setWindowTitle(QApplication::translate("DialogHistoryLine", "\345\216\206\345\217\262\346\233\262\347\272\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogHistoryLine: public Ui_DialogHistoryLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGHISTORYLINE_H
