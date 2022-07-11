cmake_minimum_required(VERSION 3.16.0)

project(freemodbus C)


set(FREEMODBUS_SRC 
	modbus/mb.c
	modbus/functions/mbfunccoils.c
	modbus/functions/mbfuncdiag.c
	modbus/functions/mbfuncdisc.c
	modbus/functions/mbfuncholding.c
	modbus/functions/mbfuncinput.c
	modbus/functions/mbfuncother.c
	modbus/functions/mbutils.c
	modbus/functions/mbutils.c
)

set(FREEMODBUS_SRC ${FREEMODBUS_SRC} 
    modbus/tcp/mbtcp.c
)

set(FREEMODBUS_PLATFORM
    demo/LINUXTCP/port/porttcp.c
    demo/LINUXTCP/port/portevent.c
    demo/LINUXTCP/port/portother.c
    demo/LINUXTCP/demo.c
)

message(STATUS "CMAKE_BINARY_DIR:         ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR:         ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
if(WIN32) 
    MESSAGE("freemodbus WIN32...")
else()    
    add_executable(freemodbus)
    target_compile_definitions(freemodbus PUBLIC 
    MB_TCP_ENABLED
    )
    target_sources(freemodbus PRIVATE ${FREEMODBUS_SRC} ${FREEMODBUS_PLATFORM})
    target_link_libraries(freemodbus
    pthread
    dl
    )
    target_include_directories(freemodbus PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/demo/LINUXTCP/port
    ${CMAKE_CURRENT_SOURCE_DIR}/modbus/include
    ${CMAKE_CURRENT_SOURCE_DIR}/modbus/tcp    
    )
endif()