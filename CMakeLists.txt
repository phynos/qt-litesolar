
cmake_minimum_required(VERSION 3.16.0)

project(QtLiteSolar)


#set(CMAKE_INSTALL_PREFIX ./dist)

# 存放静态库的文件夹位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-temp)
# 存放动态库的文件夹位置
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# 存放可执行软件的目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(lib)
#add_subdirectory(test)
#add_subdirectory(test-3rd)
add_subdirectory(src)
add_subdirectory(src-qt-ui)
