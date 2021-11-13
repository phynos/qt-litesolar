QT -= gui

TEMPLATE = lib
TARGET = zlib
# CONFIG += staticlib
CONFIG += warn_off
CONFIG += c++11

#定义项目编译之后生成的结果文件的存放路径
DESTDIR = ../../

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    adler32.c\
    crc32.c \
    gzclose.c \
    gzread.c \
    infback.c \
    inflate.c \
    trees.c \
    zutil.c \
    compress.c \
    deflate.c \
    gzlib.c \
    gzwrite.c \
    inffast.c \
    inftrees.c \
    uncompr.c

