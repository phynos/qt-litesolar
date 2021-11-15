
include_directories("${CMAKE_SOURCE_DIR}/lib/")
include_directories("${CMAKE_SOURCE_DIR}/src/jsruntime/")

# 指定生成目标
add_executable(TestJS test.c)

target_link_libraries(TestJS 
    JsRuntime        
)