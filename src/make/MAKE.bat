@echo off
color 0a

mingw32-make -version
If errorlevel 1 (
    echo û�а�װmingw���밲װ
    goto end
) Else (
    echo �������ɹ���
	cls
    call :showLogo                                                  
)

:loop
echo ��ǰ֧�����¹�����
echo 0=����
echo 1=����
echo 2=sqlite3
echo 3=duktape
echo 4=lua
echo 5=libmodbus
echo 6=freemodbus
echo 401=lsqlite3
echo 402=lmodbus
echo 999=�˳�
echo .  
set /p target=��ѡ�񹹽�Ŀ�꣺
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
echo �����ѡ��һ��Ŀ�� goto loop

:clean
cls
echo �ݲ�֧��
echo:
goto loop

:all
mingw32-make -f MAKE.mk
goto end

:freemodbus
echo �ݲ�֧��
echo:
goto loop

:libmodbus
echo ��ʼ����libmodbus��̬��
mingw32-make -f MAKE.mk libmodbus
pause
cls
goto loop

:duktape
echo ��ʼ����duktape��̬��
mingw32-make -f MAKE.mk duk-all
pause
cls
goto loop

:lua
echo ��ʼ����lua��̬��
mingw32-make -f MAKE.mk lua
pause
cls
goto loop

:libmodbus_lua
echo ��ʼ����libmodbus-lua��̬��
mingw32-make -f MAKE.mk libmodbus_lua
pause
cls
goto loop

:sqlite3
echo ��ʼ����sqlite3��̬��
mingw32-make -f MAKE.mk sqlite3
pause
cls
goto loop

:lsqlite3
echo ��ʼ����lsqlite3��̬��
mingw32-make -f MAKE.mk lsqlite3
pause
cls
goto loop

:lmodbus
echo ��ʼ����lmodbus��̬��
mingw32-make -f MAKE.mk lmodbus
pause
cls
goto loop

:other
echo ��ʱ��֧��
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