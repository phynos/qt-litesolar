
file(GLOB SRCS "*.c" "*.cpp")
file(GLOB PUBLIC_HEADERS "*.h")
#第一个参数为你需要构建的dll的名字，第二个为类型
ADD_LIBRARY (duktape SHARED ${SRCS} ${PUBLIC_HEADERS})  
include_directories(./)  
# 指定dll的生成目录这里目录是D:/mylib，注意linux下是LIBRARY DESTINATION  windows下是 RUNTIME DESTINATION
INSTALL(TARGETS duktape RUNTIME DESTINATION D:/lupc)
#为你的dll设置linker
SET_TARGET_PROPERTIES(duktape PROPERTIES LINKER_LANGUAGE C)