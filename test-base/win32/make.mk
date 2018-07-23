main.exe: main.c
	gcc -fexec-charset=GBK -mwindows main.c -o main.exe -lgdi32

