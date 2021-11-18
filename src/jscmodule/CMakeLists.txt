
# 指定生成目标
add_library(JsTest SHARED js-test.c js-cmodule.h)
target_include_directories(JsTest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(JsTest 
    quickjs 
    m)

# 指定生成目标
add_library(JsModbus SHARED js-modbus-slave.c js-cmodule.h)
target_include_directories(JsModbus INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(JsModbus 
    modbus
    quickjs 
    m)