@echo off
color 0a

:loop
echo 当前支持以下构建：
echo 0=所有
echo 1=libmodbus
echo 2=duktape
echo 3=lua
echo 4=暂缺
echo 5=sqlite3
echo 21=lsqlite3
echo 22=lmodbus
echo 100=退出
echo .  
set /p target=请选择构建目标：
if /i "%target%" == "0" goto all
if /i "%target%" == "1" goto libmodbus
if /i "%target%" == "2" goto duktape
if /i "%target%" == "3" goto lua
if /i "%target%" == "4" goto other
if /i "%target%" == "5" goto sqlite3
if /i "%target%" == "21" goto lsqlite3
if /i "%target%" == "22" goto lmodbus
if /i "%target%" == "100" goto end
echo 你必须选择一个目标 goto loop

:all
mingw32-make -f MAKE
goto end

:libmodbus
echo 开始构建libmodbus动态库
mingw32-make -f MAKE libmodbus
pause
cls
goto loop

:duktape
echo 开始构建duktape动态库
mingw32-make -f MAKE duk-all
pause
cls
goto loop

:lua
echo 开始构建lua动态库
mingw32-make -f MAKE lua
pause
cls
goto loop

:libmodbus_lua
echo 开始构建libmodbus-lua动态库
mingw32-make -f MAKE libmodbus_lua
pause
cls
goto loop

:sqlite3
echo 开始构建sqlite3动态库
mingw32-make -f MAKE sqlite3
pause
cls
goto loop

:lsqlite3
echo 开始构建lsqlite3动态库
mingw32-make -f MAKE lsqlite3
pause
cls
goto loop

:lmodbus
echo 开始构建lmodbus动态库
mingw32-make -f MAKE lmodbus
pause
cls
goto loop

:other
echo 暂时不支持
goto loop

:end
pause