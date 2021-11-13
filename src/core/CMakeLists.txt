
file(GLOB SRCS "*.c" "*.cpp")
file(GLOB PUBLIC_HEADERS "*.h")
#第一个参数为你需要构建的dll的名字，第二个为类型
ADD_LIBRARY (solarcore SHARED ${SRCS} ${PUBLIC_HEADERS})  
include_directories(
    ./
    "${CMAKE_SOURCE_DIR}/lib/sqlite-3.24.0/"    
)  
#为你的dll设置linker
SET_TARGET_PROPERTIES(solarcore PROPERTIES LINKER_LANGUAGE C)