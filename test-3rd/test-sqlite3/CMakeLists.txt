

# 指定生成目标
add_executable(TestSqlite3 test-sqlite3.c)
target_link_libraries(TestSqlite3 sqlite3)

if(WIN32)
    # C的解决办法
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")
    # C++ 的解决办法
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
endif()