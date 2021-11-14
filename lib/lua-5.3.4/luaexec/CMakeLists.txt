ADD_EXECUTABLE(luaexec luaexec/lua.c)
target_link_libraries(luaexec lua)
set_target_properties(luaexec PROPERTIES OUTPUT_NAME lua)