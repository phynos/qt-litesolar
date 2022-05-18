project(lua C)
cmake_minimum_required(VERSION 3.16.0)

set(LUA_SRC_CORE src/lapi.c src/lcode.c src/ldebug.c src/ldo.c src/ldump.c src/lfunc.c src/lgc.c src/llex.c
        src/lmem.c src/lobject.c src/lopcodes.c src/lparser.c src/lstate.c src/lstring.c src/ltable.c
        src/ltm.c src/lundump.c src/lvm.c src/lzio.c)
set(LUA_SRC_LIB src/lauxlib.c src/lbaselib.c src/ldblib.c src/liolib.c src/lcorolib.c src/lutf8lib.c
        src/lmathlib.c src/loslib.c src/lstrlib.c src/ltablib.c src/loadlib.c src/linit.c src/lctype.c)

add_library(liblua ${LUA_SRC_CORE} ${LUA_SRC_LIB})
set_target_properties(liblua PROPERTIES OUTPUT_NAME lua)
target_include_directories(liblua PUBLIC src ${CMAKE_CURRENT_BINARY_DIR})

add_library(libluadll SHARED)
set_target_properties(libluadll PROPERTIES OUTPUT_NAME lua54)
target_sources(libluadll PUBLIC ${LUA_SRC_CORE} ${LUA_SRC_LIB})
target_include_directories(libluadll PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src)
IF (WIN32)
MESSAGE("lua win...")
        target_compile_definitions(libluadll PRIVATE _CRT_SECURE_NO_WARNINGS LUA_BUILD_AS_DLL)
ELSEIF (UNIX)
        MESSAGE("lua linux...")
        target_compile_definitions(libluadll PRIVATE 
                LUA_USE_LINUX)
        target_link_libraries(libluadll dl m)
ENDIF()

add_executable(lua)
target_link_libraries(lua libluadll)
target_sources(lua PRIVATE src/lua.c)
target_include_directories(lua PRIVATE src ${CMAKE_CURRENT_BINARY_DIR})

add_executable(luac)
target_link_libraries(luac liblua)
target_sources(luac PRIVATE src/luac.c)
target_include_directories(luac PRIVATE src ${CMAKE_CURRENT_BINARY_DIR})