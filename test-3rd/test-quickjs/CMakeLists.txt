# 指定生成目标
add_executable(TestJS test.c)



IF(WIN32)
    target_link_libraries(TestJS 
        JsRuntime        
    )
ELSEIF()
    target_link_libraries(TestJS 
    JsRuntime        
    )
ENDIF()
