#-------------------------------------------------
#
# Project created by QtCreator 2016-11-11T11:05:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LiteSolar
TEMPLATE = app


TRANSLATIONS = chinese.ts english.ts

SOURCES += main.cpp\
        mainwindow.cpp \
    menu/dialogabout.cpp \
    menu/dialoghistoryline.cpp \
    menu/dialogdevicedata.cpp \
    menu/dialogdeviceevents.cpp \
    tv/dialogtv.cpp \
    device/formdevice.cpp \
    menu/dialogevents.cpp \
    notifymanager.cpp \
    notify.cpp

HEADERS  += mainwindow.h \
    menu/dialogabout.h \
    menu/dialoghistoryline.h \
    menu/dialogdevicedata.h \
    menu/dialogdeviceevents.h \
    tv/dialogtv.h \
    device/formdevice.h \
    menu/dialogevents.h \
    menu/colordefines.h \
    notifymanager.h \
    notify.h

FORMS    += mainwindow.ui \
    menu/dialogabout.ui \
    menu/dialogsetting.ui \
    menu/dialoghistoryline.ui \
    menu/dialogdevicedata.ui \
    menu/dialogdeviceevents.ui \
    tv/dialogtv.ui \
    device/formdevice.ui \
    menu/dialogevents.ui

RESOURCES += \
    solar.qrc

RC_FILE = logo.rc

OTHER_FILES += \
    rc/css.qss

CONFIG += c++11
