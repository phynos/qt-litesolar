
file(GLOB SRCS "*.c" "*.cpp")
file(GLOB PUBLIC_HEADERS "*.h")
#第一个参数为你需要构建的dll的名字，第二个为类型
ADD_LIBRARY (sqlite3 SHARED sqlite3.c sqlite3.h)  
include_directories(./sqlite3.h)

if(WIN32) 

else()
    TARGET_LINK_LIBRARIES(sqlite3 
    pthread
    dl
    )
endif()
