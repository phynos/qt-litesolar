#ifndef SOLAR_ALARM_H
#define SOLAR_ALARM_H

#include "solar.h"

struct solar_alarm {
	int alarm_type;
	int device_id;
	int signal_id;
	long time;
	char *value;
	char *describe;
};

typedef void (*solar_alarm_callback)(struct solar_alarm *alarm);

void solar_alarm_init(struct solar_context *ctx);

void solar_alarm_release();

/**
* 创建一个告警结构体消息，并为其分配内存
**/
int solar_alarm_obtain(struct solar_alarm **);

int solar_alarm_enqueue(struct solar_alarm *alarm);

/**
* 遍历当前队列，并打印
**/
void solar_alarm_debug();

/**
* 告警处理回调
* 回调函数执行上下文为告警消息处理线程，最好不要再回调里面处理过多内容
**/
void solar_alarm_register_callback(solar_alarm_callback callback);

#endif /* SOLAR_ALARM_H */