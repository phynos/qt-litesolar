

# 指定生成目标
add_executable(WindowExample WIN32 main.c)

TARGET_LINK_LIBRARIES(WindowExample 
    gdi32
)