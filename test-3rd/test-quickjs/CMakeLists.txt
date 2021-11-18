# 指定生成目标
add_executable(TestJS test.c)

target_link_libraries(TestJS 
    JsRuntime        
)
