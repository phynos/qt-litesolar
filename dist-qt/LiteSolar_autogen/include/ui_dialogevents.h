/********************************************************************************
** Form generated from reading UI file 'dialogevents.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEVENTS_H
#define UI_DIALOGEVENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogEvents
{
public:

    void setupUi(QDialog *DialogEvents)
    {
        if (DialogEvents->objectName().isEmpty())
            DialogEvents->setObjectName(QStringLiteral("DialogEvents"));
        DialogEvents->resize(400, 300);

        retranslateUi(DialogEvents);

        QMetaObject::connectSlotsByName(DialogEvents);
    } // setupUi

    void retranslateUi(QDialog *DialogEvents)
    {
        DialogEvents->setWindowTitle(QApplication::translate("DialogEvents", "\345\216\206\345\217\262\344\272\213\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogEvents: public Ui_DialogEvents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEVENTS_H
