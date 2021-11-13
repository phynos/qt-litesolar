QT -= gui

TEMPLATE = lib


CONFIG += c++11

#定义项目编译之后生成的结果文件的存放路径
DESTDIR = ../../

SOURCES += \
    duktape.c


HEADERS += \
    duktape.h \
    duk_config.h
