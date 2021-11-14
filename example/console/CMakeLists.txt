
if(WIN32)
    # 指定生成目标
    add_executable(ConsoleExample main.c)
else()
    message("该程序只支持win32")
endif()