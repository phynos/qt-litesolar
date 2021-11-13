

QT -= gui

TEMPLATE = lib

TARGET = libmodbus

CONFIG += c++11


INCLUDEPATH += ./snmp_include\
               ./quazip\
               ./list\
               ./other

SOURCES += main.cpp\
        mainwindow.cpp \
    inital.cpp \
    net_thread.cpp \
    data_thread.cpp \
    event_thread.cpp \
    api.cpp \
    childform.cpp \
    alarmmsgform.cpp \
    usercontrolform.cpp \
    adddevdialog.cpp \
    datalogform.cpp \
    logindlg.cpp\
    smtp.cpp \
    rteventform.cpp \
    rtdataform.cpp \
    rateinfoform.cpp \
    setinfoform.cpp \
    eventlogform.cpp \
    usersetdialog.cpp \
    changepwdialog.cpp \
    comsource/posix_qextserialport.cpp \
    comsource/qextserialbase.cpp \
    comsource/qextserialport.cpp \
    comsource/win_qextserialport.cpp \
    mapshowform.cpp \
    widget.cpp \
    screen.cpp \
    borderlayout.cpp \
    tablewidget.cpp \
    rtreewidget.cpp \
    qcustlabel.cpp \
    mapsetdialog.cpp \
    SysSourceFile.cpp \
    snmp_thread.cpp \
    smarthomemsg.cpp \
    qbattery.cpp \
    psshowslider.cpp \
    dynamicchart.cpp \
    datachart.cpp \
    rtsinglegraphform.cpp \
    chartform.cpp \
    rtthreegraphform.cpp \
    threedynamicchart.cpp \
    sms_thread.cpp \
    aboutdialog.cpp \
    exitform.cpp \
    imagewidget.cpp \
    qmylabel.cpp \
    cleardialog.cpp \
    interface/authdialog.cpp \
    interface/prosetform.cpp \
    interface/syssetform.cpp \
    interface/emailsetdialog.cpp \
    interface/paramsetdlg.cpp \
    quazip/zip.c \
    quazip/unzip.c \
    quazip/quazipnewinfo.cpp \
    quazip/quazipfile.cpp \
    quazip/quazip.cpp \
    quazip/ioapi.c \
    interface/usm.cpp \
    interface/usmadduser.cpp \
    interface/emaileventselectdialog.cpp \
    interface/emailaddressdialog.cpp \
    interface/smseventdialog.cpp \
    interface/smssetdialog.cpp \
    interface/smsphonenumberdialog.cpp \
    interface/smsphonedlg.cpp

HEADERS  += mainwindow.h \
    globalvar.h \
    net_thread.h \
    data_thread.h \
    event_thread.h \
    childform.h \
    alarmmsgform.h \
    usercontrolform.h \
    adddevdialog.h \
    datalogform.h \
    logindlg.h\
    smtp.h \
    rteventform.h \
    rtdataform.h \
    rateinfoform.h \
    setinfoform.h \
    eventlogform.h \
    usersetdialog.h \
    changepwdialog.h \
    comsource/posix_qextserialport.h \
    comsource/qextserialbase.h \
    comsource/qextserialport.h \
    comsource/win_qextserialport.h \
    mapshowform.h \
    widget.h \
    screen.h \
    borderlayout.h \
    tablewidget.h \
    rtreewidget.h \
    qcustlabel.h \
    mapsetdialog.h \
    snmp_thread.h \
    smarthomemsg.h \
    qbattery.h \
    psshowslider.h \
    dynamicchart.h \
    datachart.h \
    rtsinglegraphform.h \
    chartform.h \
    rtthreegraphform.h \
    threedynamicchart.h \
    sms_thread.h \
    aboutdialog.h \
    exitform.h \
    imagewidget.h \
    qmylabel.h \
    cleardialog.h \
    interface/authdialog.h \
    interface/prosetform.h \
    interface/syssetform.h \
    interface/emailsetdialog.h \
    interface/paramsetdlg.h \
    quazip/zlib.h \
    quazip/zip.h \
    quazip/zconf.h \
    quazip/unzip.h \
    quazip/quazipnewinfo.h \
    quazip/quazipfileinfo.h \
    quazip/quazipfile.h \
    quazip/quazip.h \
    quazip/ioapi.h \
    quazip/gojobzip.h \
    quazip/crypt.h \
    interface/usm.h \
    interface/usmadduser.h \
    interface/emaileventselectdialog.h \
    interface/emailaddressdialog.h \
    interface/smseventdialog.h \
    interface/smssetdialog.h \
    interface/smsphonenumberdialog.h \
    interface/smsphonedlg.h



#message($$PWD)
#CONFIG += release
# Activate either libtomcrypt or libdes:
unix {
  #指定uic命令寵i文件转化成ui_*.h文件的存放的目录
  UI_DIR += $$PWD/tmp
  #指定rcc命令寱rc文件转换成qrc_*.h文件的存放目庒CC_DIR += $$PWD/tmp
  #指定moc命令将含Q_OBJECT的头文件转换成标冨文件的存放目廠 MOC_DIR += $$PWD/tmp
  #指定目标文件(obj)的存放目序BJECTS_DIR += $$PWD/tmp
  LIBS += $$PWD/lib/libsnmp/linux/libsnmp_l32_3330.a \
          $$PWD/lib/libopenssl/linux/libcrypto_l101e.a \
          $$PWD/lib/libopenssl/linux/libssl_l101e.a
  #LIBS += $$PWD/lib/libsnmp/linux/libsnmp_l64_3330.a
          #$$PWD/lib/libopenssl/linux/libcrypto_l101e_64.a \
          #$$PWD/lib/libopenssl/linux/libssl_l101e_64.a
}
win32 {
  LIBS += $$PWD/lib/libsnmp/windows/libsnmp_w32_3330.a \
          $$PWD/lib/libsnmp/windows/WS2_32.LIB \
          $$PWD/lib/libopenssl/windows/libssl_m101e.a \
          $$PWD/lib/libopenssl/windows/libcrypto_m101e.a \
          $$PWD/lib/libopenssl/windows/libeay32_m101e.a \
          $$PWD/lib/libopenssl/windows/libssl32_m101e.a \
          $$PWD/lib/libopenssl/windows/GDI32.LIB
}
