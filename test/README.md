
## 生成汇编代码
gcc -S -masm=intel -std=c99 asm.c

## 生成windows窗体程序
test_windows.exe: test_windows.c
	gcc -fexec-charset=GBK -mwindows test_windows.c -o test_windows.exe -lgdi32

## 生成命令行程序
check-app.exe: check-app.c
	gcc -fexec-charset=GBK -mconsole -o check-app.exe check-app.c

## 其他
test_lib.a: test_lib.o
	ar rcs libtest_lib.a test_lib.o
test_lib.o: test_lib.c
	gcc -c test_lib.c