
CC	= gcc
CCOPTS += -I../../3rd/lua-5.3.4/src  # for combined sources

test.exe: test.c
	$(CC)  -fexec-charset=GBK -mconsole $(CCOPTS) test.c lua53.dll -o test.exe
# -fexec-charset=GBK
# -finput-charset=utf8