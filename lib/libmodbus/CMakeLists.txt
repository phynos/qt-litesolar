cmake_minimum_required(VERSION 3.16.0)

project(libmodbus C)

file(GLOB SRCS "*.c" "*.cpp")
file(GLOB PUBLIC_HEADERS "*.h")


#第一个参数为你需要构建的dll的名字，第二个为类型
add_library (modbus SHARED)  
target_include_directories(modbus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(modbus PRIVATE ${SRCS})

if(WIN32)
    target_link_libraries(modbus 
        Ws2_32
    )
endif()

#为你的dll设置linker
SET_TARGET_PROPERTIES(modbus PROPERTIES LINKER_LANGUAGE C)