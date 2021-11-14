

include_directories("${CMAKE_SOURCE_DIR}/lib/lua-5.3.4/")

# 指定生成目标
add_executable(TestLua test-lua.c)

TARGET_LINK_LIBRARIES(TestLua 
    lua
)

if(WIN32)
    # C的解决办法
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")
    # C++ 的解决办法
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
endif()