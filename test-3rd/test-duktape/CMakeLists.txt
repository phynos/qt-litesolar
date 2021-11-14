

include_directories("${CMAKE_SOURCE_DIR}/lib/duktape/")

# 指定生成目标
add_executable(TestDuktape test-duktape.c)

TARGET_LINK_LIBRARIES(TestDuktape 
    duktape
    duk-module-node
    duk-console
)

if(WIN32)
    # C的解决办法
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK -finput-charset=utf8")
    # C++ 的解决办法
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK -finput-charset=utf8")
endif()