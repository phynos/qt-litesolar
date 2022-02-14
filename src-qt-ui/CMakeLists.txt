project(LiteSolar)

SET(CMAKE_CXX_STANDARD 14)

# QT安装路径
set(CMAKE_PREFIX_PATH $ENV{Qt5_DIR})
# Qt特有的编译器需要打开，默认是关闭的
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
# 有些项目会动态生成头文件，项目中需要引入它，因此需要将output目录也include进来
# 等同于INCLUDE_DIRECTORY(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(QT Core Gui Widgets Sql Xml)

MESSAGE("Qt5_DIR:"$ENV{Qt5_DIR})
FIND_PACKAGE(Qt5 COMPONENTS ${QT} REQUIRED)

# 源码
set(LiteSolar_SOURCES     
    main.cpp

    main/classic/mainwindow.cpp
    main/modern/uidemo08.cpp
    main/modern/appinit.cpp

    device/formdevice.cpp
    tv/dialogtv.cpp
    notify/notify.cpp
    notify/notifymanager.cpp

    menu/dialogsetting.cpp
    menu/dialoghistoryline.cpp
    menu/dialogevents.cpp
    menu/dialogdeviceevents.cpp
    menu/dialogdevicedata.cpp
    menu/dialogabout.cpp

    util/iconhelper.cpp
    )
# 头文件
set(LiteSolar_HEADERS 
    
    main/classic/mainwindow.h
    main/modern/uidemo08.h
    main/modern/appinit.h

    device/formdevice.h
    tv/dialogtv.h
    notify/notify.h
    notify/notifymanager.h

    menu/colordefines.h

    menu/dialogsetting.h
    menu/dialoghistoryline.h
    menu/dialogevents.h
    menu/dialogdeviceevents.ui
    menu/dialogdevicedata.h
    menu/dialogabout.h

    util/iconhelper.h
    )
# UI文件配置
set(LiteSolar_FORMS 
    main/classic/mainwindow.ui
    main/modern/uidemo08.ui

    device/formdevice.ui
    tv/dialogtv.ui
    
    menu/dialogsetting.ui
    menu/dialoghistoryline.ui
    menu/dialogevents.ui
    menu/dialogdeviceevents.ui
    menu/dialogdevicedata.ui
    menu/dialogabout.ui
    )
# RC文件配置
set(LiteSolar_RESOURCES 
    solar.qrc
    logo.rc
    main.qrc
    qss.qrc
    )

    include_directories("${CMAKE_SOURCE_DIR}/lib/")

if(WIN32) 
    # 这里如果不加WIN32，会导致编译的可执行文件运行时候会同时弹出一个命令行终端
    add_executable(${CMAKE_PROJECT_NAME} WIN32 ${LiteSolar_SOURCES} ${LiteSolar_HEADERS} ${LiteSolar_FORMS} ${LiteSolar_RESOURCES})
else()
    # 这是Windows的特性，对于其它平台得去掉WIN32
    add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
endif()

# 链接设置
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE 
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets    
)
