

# 项目信息，参数是 main，该命令表示项目的名称是 main 。
include_directories("${CMAKE_SOURCE_DIR}/lib/libevent/")


# 指定生成目标
add_executable(TestLibevent test.c)

TARGET_LINK_LIBRARIES(TestLibevent 
    event
)