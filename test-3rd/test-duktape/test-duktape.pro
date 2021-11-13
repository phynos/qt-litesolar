TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TARGET = TestDuktape

#定义项目编译之后生成的结果文件的存放路径
DESTDIR = ../../

SOURCES += js_test.c\

INCLUDEPATH += \
    ../../lib/duktape/\

LIBS += -L$$OUT_PWD/../../

#表示Windows环境的特殊设置，这个大括号不能单独放在下一行，否则编译会报错
win32 {
    LIBS += \
        -lduktape \
        -lduktape-module-node \
        -lduktape-console \
}
