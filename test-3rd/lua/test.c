#include <stdio.h>
#include <string.h>

#include <windows.h>
 
#include "../../3rd/lua-5.3.4/src/lua.h"
#include "../../3rd/lua-5.3.4/src/lauxlib.h"
#include "../../3rd/lua-5.3.4/src/lualib.h"


int average(lua_State *L);
LUALIB_API int regFuncLib(lua_State *L);

const luaL_Reg myLib[]= {  
    {"average", average},  
    {NULL, NULL}  
};


int main()
{
    lua_State *L = luaL_newstate();
    luaopen_base(L); //
    luaopen_table(L); //
    luaopen_package(L); //
    luaopen_io(L); //
    luaopen_string(L); //
 
    luaL_openlibs(L); //打开以上所有的lib    
    //
    lua_register(L, "average", average);  
    //载入模块
    luaL_requiref(L,"MyMath",regFuncLib,0);     

    //2.加载Lua文件  
    int err = luaL_loadfile(L,"test.lua"); 
    if(err) {
        printf("load file error:%d \r\n",err);
        system("pause");
        return 0;
    }
    //3.运行Lua文件 
    err = lua_pcall(L,0,0,0);
    if(err) {
        printf("call file error:%d \r\n",err);
        system("pause");
        return 0;
    }
    
    //调用 业务初始化函数
    lua_getglobal(L, "MyExInit");  
    lua_pcall(L, 0, 0, 0);
    //大循环
    while(1){        
        printf("do loop\r\n");
        //每隔30毫秒，调用一次
        lua_getglobal(L, "MyExLoop");  
        err = lua_pcall(L, 0, 0, 0);// 调用函数，调用完成以后，会将返回值压入栈中，2表示参数个数，1表示返回结果个数。
        if(err){
            lua_pop(L, 1); // 从栈中弹出错误消息
        }
        //        
        Sleep(1500);
    }
}

int average(lua_State *L){
    int n = lua_gettop(L); //参赛个数
    double sum = 0;  
    int i;
    /* 循环求参数之和 */  
    for (i = 1; i <= n; i++)  
        sum += lua_tonumber(L, i);
    lua_pushnumber(L, sum / n);     //压入平均值  
    return 1;//返回一个结果
}

void runLua(){
    char buff[256] = {0};
    int error;
    lua_State *L = luaL_newstate(); // 打开Lua
    luaL_openlibs(L); // 打开标准库
    while (fgets(buff, sizeof(buff), stdin) != NULL)
    {
        error = luaL_loadbuffer(L, buff, strlen(buff), "line")
            || lua_pcall(L, 0, 0, 0);
        if (error)
        {
            fprintf(stderr, "%s", lua_tostring(L, -1));
            lua_pop(L, 1); // 从栈中弹出错误消息
        }
    }
    lua_close(L);
}


//调用纯空Lua函数
void mylua_call_void_func(lua_State *L,const char* name){
    int err;
    char *err_info;
    lua_getglobal(L,name);//加载函数
    err = lua_pcall(L, 0, 0, 0);// 调用函数，调用完成以后，会将返回值压入栈中，2表示参数个数，1表示返回结果个数。
    if(err){
        //err_info = lua_tostring(L, -1);//打印错误结果 
        lua_pop(L, 1);
    }
}

//调用返回整数的无参函数
int mylua_call_int_func(lua_State *L,const char* name){
    int err,r;
    char *err_info;
    lua_getglobal(L,name);//加载函数
    err = lua_pcall(L, 0, 1, 0);// 调用函数，调用完成以后，会将返回值压入栈中，2表示参数个数，1表示返回结果个数。
    if(err){
        //err_info = lua_tostring(L, -1);//打印错误结果 
        lua_pop(L, 1);
    }
    r = lua_tointeger(L,-1);
    lua_pop(L,1);
    return r;
}

typedef int (*aaaaa)();

//向Lua注册C函数
void regFunc(lua_State *L,const char* name,aaaaa address)
{
    lua_register(L,name,address);
}

//注册函数库
LUALIB_API int regFuncLib(lua_State *L) {  
  luaL_newlib(L, myLib);  
  return 1;  
}  