test.exe: test.c
	gcc -mconsole test.c lua53.dll -o test.exe
# -fexec-charset=GBK