cmake_minimum_required(VERSION 3.16.0)
project(sqlite3 C)


#第一个参数为你需要构建的dll的名字，第二个为类型
add_library(sqlite3 SHARED sqlite3.c sqlite3.h)  
target_include_directories(sqlite3 PUBLIC ./sqlite3.h)

if(WIN32) 

else()
    TARGET_LINK_LIBRARIES(sqlite3 
    pthread
    dl
    )
endif()
