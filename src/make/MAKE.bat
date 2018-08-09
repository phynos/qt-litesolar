@echo off
color 0a

:loop
echo 当前支持以下构建：
echo 0=所有
echo 1=libmodbus
echo 2=duktape
echo 3=lua
echo 4=libmodbus_lua
echo 5=sqlite3
echo .  
set /p target=请选择构建目标：
if /i "%target%" == "0" goto all
if /i "%target%" == "1" goto libmodbus
if /i "%target%" == "2" goto duktape
if /i "%target%" == "3" goto lua
if /i "%target%" == "4" goto libmodbus_lua
if /i "%target%" == "5" goto sqlite3
echo 你必须选择一个目标 goto loop

:all
mingw32-make -f MAKE
goto end

:libmodbus
echo 开始构建libmodbus动态库
mingw32-make -f MAKE libmodbus
goto end

:duktape
echo 开始构建duktape动态库
mingw32-make -f MAKE duk-all
goto end

:lua
echo 开始构建lua动态库
mingw32-make -f MAKE lua
goto end

:libmodbus_lua
echo 开始构建libmodbus-lua动态库
mingw32-make -f MAKE libmodbus_lua
goto end

:sqlite3
echo 开始构建sqlite3动态库
mingw32-make -f MAKE sqlite3
goto end


:end
pause