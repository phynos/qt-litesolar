#ifndef SOLAR_STATION_H
#define SOLAR_STATION_H


typedef struct _solar_unit {
	int id;
	char *name;
	char *remark
} solar_unit;

struct solar_station
{
	int id;
	char *name;
	int capacity
};

void solar_start();

void solar_stop();

void solar_init();

void solar_destroy();

int solar_add_unit();

int solar_remove_unit();

#endif /* SOLAR_STATION_H  */