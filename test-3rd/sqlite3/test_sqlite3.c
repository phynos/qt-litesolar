/*
        
    用到的接口： 
        打开数据库：sqlite3_open()
        关闭数据库：sqlite3_close()
        执行语句 ：sqlite3_exec()
*/

#include <stdio.h>
#include <sqlite3.h>    // sqlite3 API库

// sqlite3_exec()中使用的回调函数
static int callback_selectAll(void *, int, char **, char **);

int main(void)
{
    // 用来存储数据库名称
    int a = 0;
    const char * db_name = "db/company.db";
    
    // 打开数据库，如果没有该数据库则创建
    sqlite3 * pdb = NULL;
    sqlite3_open(db_name, &pdb);
    
    // 创建一个表格
    sqlite3_exec(pdb, "create table person(id integer primary key autoincrement, name char(32) )", NULL, NULL, NULL);    
    
    // 在表格中插入数据
    sqlite3_exec(pdb, "insert into person (name) values (\"shang\")", NULL, NULL, NULL);
    sqlite3_exec(pdb, "insert into person (name) values (\"guan\")", NULL, NULL, NULL);
    sqlite3_exec(pdb, "insert into person (name) values (\"yuan\")", NULL, NULL, NULL);
    sqlite3_exec(pdb, "insert into person (name) values (\"xia\")", NULL, NULL, NULL);
    
    // 用select * 来全部显示
    sqlite3_exec(pdb, "select * from person", callback_selectAll, NULL, NULL);
    
    // 关闭数据库
    sqlite3_close(pdb);

    scanf("%d",&a);

    return 0;
}

// 回调函数中有两个参数没有用到
// n_clumn 存储列数 (id, name)共两列
// column_value 列值 例如 1 shang，2 guan
// 其他两个参数没有用到
int callback_selectAll(void * params, int n_clumn, char **column_value, char ** column_name)
{
    int i = 0;
    
    // 打印表中的值
    for (; i<n_clumn; i++)
    {
        printf("%s    ", column_value[i]);
    }
    printf("\n");
    
    return 0;
}