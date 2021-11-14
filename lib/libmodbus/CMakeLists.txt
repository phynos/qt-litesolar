
file(GLOB SRCS "*.c" "*.cpp")
file(GLOB PUBLIC_HEADERS "*.h")
#第一个参数为你需要构建的dll的名字，第二个为类型
ADD_LIBRARY (libmodbus SHARED ${SRCS} ${PUBLIC_HEADERS})  
include_directories(./)  
TARGET_LINK_LIBRARIES(libmodbus 
    Ws2_32
)
#为你的dll设置linker
SET_TARGET_PROPERTIES(libmodbus PROPERTIES LINKER_LANGUAGE C)