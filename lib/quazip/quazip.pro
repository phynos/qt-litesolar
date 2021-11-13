QT -= gui

TEMPLATE = lib
TARGET = quazip

#CONFIG += staticlib
CONFIG += warn_off

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    JlCompress.cpp \
    quagzipfile.cpp \
    quazipfile.cpp \
    qioapi.cpp \
    quaziodevice.cpp \
    quazipfileinfo.cpp \
    quaadler32.cpp \
    quazip.cpp \
    quazipnewinfo.cpp \
    quacrc32.cpp \
    quazipdir.cpp \
    zip.c \
    unzip.c



HEADERS += \
    quazipfile.h \
    quazip.h


INCLUDEPATH += \
    ../zlib/ \

LIBS += \
    -L$$OUT_PWD/../../ \

#表示Windows环境的特殊设置，这个大括号不能单独放在下一行，否则编译会报错
win32 {
    LIBS += \
        -lzlib \
}

