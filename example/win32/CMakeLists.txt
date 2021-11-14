

if(WIN32)
    # 指定生成目标
    add_executable(WindowExample WIN32 main.c)

    TARGET_LINK_LIBRARIES(WindowExample 
        gdi32
    )
else()
    message("该程序只支持win32")
endif()

