cmake_minimum_required(VERSION 3.16.0)
project(sqlite3 C)


#第一个参数为你需要构建的dll的名字，第二个为类型
add_library(sqlite3 SHARED)  
target_sources(sqlite3 PRIVATE sqlite3.c)
target_include_directories(sqlite3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(WIN32) 

else()
target_link_libraries(sqlite3 
    pthread
    dl
    )
endif()
