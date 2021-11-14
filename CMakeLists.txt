
cmake_minimum_required(VERSION 3.16.0)

project(QtLiteSolar)


#set(CMAKE_INSTALL_PREFIX ./dist)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#add_subdirectory(example)
add_subdirectory(lib)
add_subdirectory(test-3rd)
add_subdirectory(src)