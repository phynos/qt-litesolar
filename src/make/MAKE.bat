@echo off
color 0a

mingw32-make -version
If errorlevel 1 (
    echo 没有安装mingw，请安装
    goto end
) Else (
    echo 环境检测成功！
	cls
    call :showLogo                                                  
)

:loop
echo 当前支持以下构建：
echo 0=清理
echo 1=所有
echo 2=sqlite3
echo 3=duktape
echo 4=lua
echo 5=libmodbus
echo 6=freemodbus
echo 401=lsqlite3
echo 402=lmodbus
echo 999=退出
echo .  
set /p target=请选择构建目标：
if /i "%target%" == "0" goto clean
if /i "%target%" == "1" goto all
if /i "%target%" == "2" goto sqlite3
if /i "%target%" == "3" goto duktape
if /i "%target%" == "4" goto lua
if /i "%target%" == "5" goto libmodbus
if /i "%target%" == "6" goto freemodbus
if /i "%target%" == "401" goto lsqlite3
if /i "%target%" == "402" goto lmodbus
if /i "%target%" == "999" goto end
echo 你必须选择一个目标 goto loop

:clean
cls
echo 暂不支持
echo:
goto loop

:all
mingw32-make -f MAKE.mk
goto end

:freemodbus
echo 暂不支持
echo:
goto loop

:libmodbus
echo 开始构建libmodbus动态库
mingw32-make -f MAKE.mk libmodbus
pause
cls
goto loop

:duktape
echo 开始构建duktape动态库
mingw32-make -f MAKE.mk duk-all
pause
cls
goto loop

:lua
echo 开始构建lua动态库
mingw32-make -f MAKE.mk lua
pause
cls
goto loop

:libmodbus_lua
echo 开始构建libmodbus-lua动态库
mingw32-make -f MAKE.mk libmodbus_lua
pause
cls
goto loop

:sqlite3
echo 开始构建sqlite3动态库
mingw32-make -f MAKE.mk sqlite3
pause
cls
goto loop

:lsqlite3
echo 开始构建lsqlite3动态库
mingw32-make -f MAKE.mk lsqlite3
pause
cls
goto loop

:lmodbus
echo 开始构建lmodbus动态库
mingw32-make -f MAKE.mk lmodbus
pause
cls
goto loop

:other
echo 暂时不支持
goto loop

:showLogo
echo:
echo "  _       _   _            ____            _                    "
echo " | |     (_) | |_    ___  / ___|    ___   | |   __ _   _ __     "
echo " | |     | | | __|  / _ \ \___ \   / _ \  | |  / _` | | '__|    "
echo " | |___  | | | |_  |  __/  ___) | | (_) | | | | (_| | | |       "
echo " |_____| |_|  \__|  \___| |____/   \___/  |_|  \__,_| |_|       "
echo:      
goto :eof

:end
pause