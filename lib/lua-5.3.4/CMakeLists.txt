cmake_minimum_required(VERSION 3.6)

GET_FILENAME_COMPONENT(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME})
#message(${PROJECT_NAME})

AUX_SOURCE_DIRECTORY(. ALL_SRC)
INCLUDE_DIRECTORIES(.)

# remove the lua.c/luac.c from teh all file lists
SET(LIB_SRC ${ALL_SRC})

# this is the file I want to exclude / remove from the list
LIST(REMOVE_ITEM LIB_SRC "lua.c" "luac.c")

ADD_LIBRARY(lua SHARED ${LIB_SRC})