
project(quickjs)

# #define OPTIMIZE 1 是否优化
# #define SHORT_OPCODES 1 是否生成短小的操作码
#/* dump object free */
#//#define DUMP_FREE
#//#define DUMP_CLOSURE
#/* dump the bytecode of the compiled functions: combination of bits
#   1: dump pass 3 final byte code
#   2: dump pass 2 code
#   4: dump pass 1 code
#   8: dump stdlib functions
#  16: dump bytecode in hex
#  32: dump line number table
# */
#//#define DUMP_BYTECODE  (1)
#/* dump the occurence of the automatic GC */
#//#define DUMP_GC
#/* dump objects freed by the garbage collector */
#//#define DUMP_GC_FREE
#/* dump objects leaking when freeing the runtime */
#//#define DUMP_LEAKS  1
#/* dump memory usage before running the garbage collector */
#//#define DUMP_MEM
#//#define DUMP_OBJECTS    /* dump objects in JS_FreeContext */
#//#define DUMP_ATOMS      /* dump atoms in JS_FreeContext */
#//#define DUMP_SHAPES     /* dump shapes in JS_FreeContext */
#//#define DUMP_MODULE_RESOLVE
#//#define DUMP_PROMISE
#//#define DUMP_READ_OBJECT

add_compile_options(
        -g
        -Wall -Wextra -Wno-sign-compare -Wno-missing-field-initializers -Wundef -Wuninitialized -Wunused -Wno-unused-parameter -Wwrite-strings -Wchar-subscripts
        -funsigned-char
        -D_GNU_SOURCE -DCONFIG_VERSION=\"2020-03-16\" 
        -DCONFIG_BIGNUM
        # 打印编译后的字节码
    #    -DDUMP_BYTECODE=111111
    #    -DFORCE_GC_AT_MALLOC
    #    -DDUMP_GC # dump the occurence of the automatic GC
    #    -DDUMP_GC_FREE # dump objects freed by the garbage collector
#        -DDUMP_LEAKS  1
#        -DDUMP_MEM
#        -DDUMP_OBJECTS
#        -DDUMP_ATOMS
#        -DDUMP_SHAPES # dump shapes in JS_FreeContext
#        -DDUMP_MODULE_RESOLVE
#        -DDUMP_PROMISE
#        -DDUMP_READ_OBJECT
#        -DDUMP_FREE
#        -DDUMP_CLOSURE
#        -DOPTIMIZE=0
#        -DSHORT_OPCODES=0
         -DCONFIG_LTO)

add_library(quickjs SHARED quickjs.c libregexp.c libunicode.c cutils.c quickjs-libc.c libbf.c)

add_executable(qjsc qjsc.c)
target_link_libraries(qjsc quickjs m)
if(WIN32) 
    MESSAGE("QUICKJS WIN32...")
else()
    TARGET_LINK_LIBRARIES(qjsc
    dl
    )
endif()

# add_custom_target(repl.c
#        COMMAND ./qjsc -c -o ../repl.c -m ../repl.js
#        DEPENDS qjsc)
# add_custom_target(qjscalc.c
#        COMMAND ./qjsc -fbignum -c -o ../qjscalc.c ../qjscalc.js
#        DEPENDS qjsc)

#生成qjs需要用上面的命令动态生成c文件
add_executable(qjs qjs.c repl.c qjscalc.c)
target_link_libraries(qjs quickjs m)
if(WIN32) 
    MESSAGE("QUICKJS WIN32...")
else()
    TARGET_LINK_LIBRARIES(qjs
    dl
    )
endif()
