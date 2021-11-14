/********************************************************************************
** Form generated from reading UI file 'dialogdeviceevents.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDEVICEEVENTS_H
#define UI_DIALOGDEVICEEVENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogDeviceEvents
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogDeviceEvents)
    {
        if (DialogDeviceEvents->objectName().isEmpty())
            DialogDeviceEvents->setObjectName(QStringLiteral("DialogDeviceEvents"));
        DialogDeviceEvents->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogDeviceEvents);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogDeviceEvents);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogDeviceEvents, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogDeviceEvents, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogDeviceEvents);
    } // setupUi

    void retranslateUi(QDialog *DialogDeviceEvents)
    {
        DialogDeviceEvents->setWindowTitle(QApplication::translate("DialogDeviceEvents", "\345\216\206\345\217\262\344\272\213\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogDeviceEvents: public Ui_DialogDeviceEvents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDEVICEEVENTS_H
