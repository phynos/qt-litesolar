

if(WIN32)
    # 指定生成目标
    add_executable(WindowExample WIN32 main.c)
    #设置静态编译
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static -fexec-charset=GBK")
    TARGET_LINK_LIBRARIES(WindowExample 
        gdi32
        libgcc.a
        libstdc++.a
        libpthread.a
    )
else()
    message("该程序只支持win32")
endif()

