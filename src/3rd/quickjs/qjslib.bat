gcc -Wall -Wno-array-bounds -D_GNU_SOURCE -DCONFIG_VERSION=\"2020-04-12\" -std=c99 -O2 -flto -c -I ./ -o obj/quickjs.o ./quickjs.c

gcc -Wall -Wno-array-bounds -D_GNU_SOURCE -DCONFIG_VERSION=\"2020-04-12\" -O2 -flto -c -I ./ -o obj/libunicode.o ./libunicode.c

gcc -Wall -Wno-array-bounds -D_GNU_SOURCE -DCONFIG_VERSION=\"2020-04-12\" -O2 -flto -c -I ./ -o obj/quickjs-libc.o ./quickjs-libc.c

gcc -Wall -Wno-array-bounds -D_GNU_SOURCE -DCONFIG_VERSION=\"2020-04-12\" -O2 -flto -c -I ./ -o obj/libregexp.o ./libregexp.c

gcc -Wall -Wno-array-bounds -D_GNU_SOURCE -DCONFIG_VERSION=\"2020-04-12\" -O2 -flto -c -I ./ -o obj/cutils.o ./cutils.c

gcc -Wall -O2 -flto -c -I ./ -o obj/libqjs.o ./libqjs.c 

gcc -shared -o lib/libqjs.dll -Wl,--out-implib,lib/libqjs.lib obj/quickjs.o obj/libregexp.o obj/libunicode.o obj/cutils.o obj/quickjs-libc.o obj/libqjs.o -lm


pause