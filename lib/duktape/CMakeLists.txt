
file(GLOB SRCS "*.c" "*.cpp")
file(GLOB PUBLIC_HEADERS "*.h")
#第一个参数为你需要构建的dll的名字，第二个为类型
ADD_LIBRARY (duktape SHARED ${SRCS} ${PUBLIC_HEADERS})  
include_directories(./)  



ADD_LIBRARY (duktape-console SHARED "./extras/console/duk_console.c")  
include_directories(./ "./extras/console/")  
IF (WIN32)
    add_definitions(-DDUK_F_DLL_BUILD) 
ENDIF()
TARGET_LINK_LIBRARIES(duktape-console 
    duktape
)

ADD_LIBRARY (duktape-module-node SHARED "./extras/module-node/duk_module_node")
include_directories(./ "./extras/module-node/")  
IF (WIN32)
    add_definitions(-DDUK_F_DLL_BUILD)
ENDIF()
TARGET_LINK_LIBRARIES(duktape-module-node 
    duktape
)