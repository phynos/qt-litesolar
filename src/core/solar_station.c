#include "solar_station.h"
#include "solar_device.h"


/* 分组列表 */
struct solar_unit_list {
	struct solar_unit *unit;
	struct solar_unit_list *next;
};

/* 设备列表 */
struct solar_device_list {
	struct solar_device *device;
	struct solar_device_list *next;
};

/* 串口信道设备分类 列表 */
struct _solar_com_list {
	struct _solar_com_list *next;
};

/* 使用tcp信道，但是不能并行的设备ip分类 列表 */
struct _solar_tcp_list {
	struct _solar_tcp_list *next;
};

/* 可以并发使用信道的设备列表 */
struct _solar_device_list {
	struct solar_device *device;
	struct solar_device_list *next;
};

void solar_start();

void solar_stop();

void solar_init();

void solar_destroy();

int solar_add_unit();

int solar_remove_unit();