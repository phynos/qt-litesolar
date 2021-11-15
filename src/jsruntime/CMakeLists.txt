
include_directories("${CMAKE_SOURCE_DIR}/lib/")
include_directories("${CMAKE_SOURCE_DIR}/src/jscmodule/")

# 指定生成目标
add_library(JsRuntime SHARED js-runtime.c js-runtime.h)
target_link_libraries(JsRuntime 
    quickjs 
    m
    JsTest
    JsModbus
)
