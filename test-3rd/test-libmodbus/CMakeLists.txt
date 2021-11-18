

# 指定生成目标
add_executable(TestLibmodbus test.c)

TARGET_LINK_LIBRARIES(TestLibmodbus 
    modbus
)

if(WIN32)
    TARGET_LINK_LIBRARIES(TestLibmodbus 
        Ws2_32
    )
endif()