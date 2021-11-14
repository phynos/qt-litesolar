#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "solar.h"
#include "solar_log.h"
#include "solar_rwlock.h"
#include "solar_alarm.h"

#include "sqlite3.h"

#define TAG "solar_alarm"

//基于单向链表实现的队列-节点
struct solar_alarm_queue_node {
	struct solar_alarm *item;
	struct solar_alarm_queue_node *next;
};

//基于链表实现的队列
struct solar_alarm_queue {
	struct solar_alarm_queue_node *head;
	struct solar_alarm_queue_node *last;
	int count;//当前队列的元素个数
	int capacity;//最大容量，预留
};

//核心上下文
static struct solar_context *_ctx;
//告警数据队列
static struct solar_alarm_queue _queue;
//告警回调函数
static solar_alarm_callback _callback;

static int _insert_into_db(struct solar_alarm *alarm);
static struct solar_alarm_queue_node * _queue_node_malloc(struct solar_alarm *item);
static void _enqueue(struct solar_alarm *alarm);

void solar_alarm_init(struct solar_context *ctx){
	_ctx = ctx;
	_callback = NULL;
	//初始化 队列(头节点的值一定为空节点)
	_queue.last = _queue.head = _queue_node_malloc(NULL);
	_queue.count = 0;
	//启动线程定时去处理告警队列

}

void solar_alarm_release(){
	//停止插入业务

	//清空任务队列，释放内存

	//释放sqltie资源
}

void solar_alarm_register_callback(solar_alarm_callback callback){
	_callback = callback;
}

int solar_alarm_obtain(struct solar_alarm **alarm){
	*alarm = (struct solar_alarm*)malloc(sizeof(struct solar_alarm));
	(*alarm)->alarm_type = 0;
	(*alarm)->device_id = 0;
	(*alarm)->signal_id = 0;
	(*alarm)->time = 3434;
	(*alarm)->value = "";
	(*alarm)->describe = "solar alarm message";
	return 1;
}

/**
* 将告警插入队列-这里要保证线程安全
**/
int solar_alarm_enqueue(struct solar_alarm *alarm){
	//读写锁，将数据插入队列
	_enqueue(alarm);
}

void solar_alarm_debug(){
	struct solar_alarm_queue_node *t;
	struct solar_alarm *alarm;
	solar_log_output(TAG,"begin print alarm queue...");
	//先打印 队列元素个数
	printf("queue count:%d\n",_queue.count);	
	//遍历队列并打印
	


	solar_log_output(TAG,"end print alarm queue...");
}

static void _handle(){
	
}

static int _insert_into_db(struct solar_alarm *alarm){
	//根据数据构造sql语句	
    // const char *sql_create_table="insert into tbAlert";
    // char *errmsg = 0;
    // int ret = 0;
    // sqlite3 *db = 0;
    // //打开sqlite
    // ret = sqlite3_open(_ctx->db_alarm,&db);
    // if(ret != SQLITE_OK){
    //     fprintf(stderr,"Cannot open db: %s\n",sqlite3_errmsg(db));
    //     return 1;
    // }
    // printf("Open database\n");
    // ret = sqlite3_exec(db,sql_create_table,NULL,NULL,&errmsg);
    // if(ret != SQLITE_OK){
    //     fprintf(stderr,"create table fail: %s\n",errmsg);
    // }
    // sqlite3_free(errmsg);
    // sqlite3_close(db);
    return 1;
}

static void _callback_invoke(struct solar_alarm *alarm){
	if(_callback != NULL){
		_callback(alarm);
	}
}

//将告警插入队列
static void _enqueue(struct solar_alarm *alarm){
	//创建节点
	struct solar_alarm_queue_node *node = _queue_node_malloc(alarm);
	//插入队列
	_queue.last->next = node;
	_queue.count++;
}

//将告警从队列移除
static struct solar_alarm * _dequeue(){
	struct solar_alarm_queue_node *head,*first;
	struct solar_alarm *x;
	//
	head = _queue.head;
	//	
	if(_queue.count == 0){
		return NULL;
	}
	assert(head->item == NULL); 
	first = head->next;	
	//舍弃原来的head节点
	free(head);
	_queue.count--;
	//返回的结果
	x = first->item;
	//第一个节点变为head节点
	_queue.head = first;
	first->item = NULL;	
	return x;
}

/**
* 创建一个 队列节点
**/
static struct solar_alarm_queue_node * _queue_node_malloc(struct solar_alarm *item){
	struct solar_alarm_queue_node *node = (struct solar_alarm_queue_node *)malloc(sizeof(struct solar_alarm_queue_node));
	node->item = item;
	node->next = NULL;
	return node;
}