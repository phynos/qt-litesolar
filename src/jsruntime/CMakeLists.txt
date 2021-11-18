cmake_minimum_required(VERSION 3.16.0)
project(JsRuntime C)


# 指定生成目标
add_library(JsRuntime SHARED jsruntime.c jsruntime.h)
target_include_directories(JsRuntime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(JsRuntime 
    m
    event
    quickjs    
    JsTest
    JsModbus
)
