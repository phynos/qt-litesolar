QT -= gui

TEMPLATE = lib

TARGET = libmodbus

CONFIG += c++11

#定义项目编译之后生成的结果文件的存放路径
DESTDIR = ../../

SOURCES += \
    modbus.c \
    modbus-data.c \
    modbus-rtu.c \
    modbus-tcp.c

HEADERS += \
    modbus.h \
    config.h \
    modbus-private.h \
    modbus-rtu.h \
    modbus-rtu-private.h \
    modbus-tcp.h \
    modbus-tcp-private.h \
    modbus-version.h

#表示Windows环境的特殊设置，这个大括号不能单独放在下一行，否则编译会报错
win32 {
    LIBS += -lWs2_32
}


unix { #表示Linux环境的特殊设置，这个大括号不能单独放在下一行，否则编译会报错

}
