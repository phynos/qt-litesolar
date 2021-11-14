project(example)

# 存放可执行软件的目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-example)

add_subdirectory(console)
add_subdirectory(win32)