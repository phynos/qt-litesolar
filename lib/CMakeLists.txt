project(libs)


SET(EVENT__DISABLE_OPENSSL TRUE)

add_subdirectory(sqlite-3.24.0)
add_subdirectory(libmodbus)
add_subdirectory(freemodbus-v1.5.0)
add_subdirectory(quickjs)
#add_subdirectory(zlib)
#add_subdirectory(libevent)
#add_subdirectory(mqtt)
#add_subdirectory(lua-5.4.4)