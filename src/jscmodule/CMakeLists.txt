
include_directories("${CMAKE_SOURCE_DIR}/lib/")

# 指定生成目标
add_library(JsTest SHARED js-test.c js-cmodule.h)
target_link_libraries(JsTest 
    quickjs 
    m)

# 指定生成目标
add_library(JsModbus SHARED js-modbus-slave.c js-cmodule.h)
target_link_libraries(JsModbus 
    libmodbus
    quickjs 
    m)