TEMPLATE = subdirs

#大项目包含的各个子项目
SUBDIRS += \
    src-qt-ui \
    lib \
    test-3rd \

#CONFIG选项要求各个子项目按顺序编译，子目录的编译顺序在SUBDIRS中指明
CONFIG += ordered 
