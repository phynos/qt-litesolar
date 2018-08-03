#include <stdio.h>
#include <stdlib.h>

#include "../core/solar_alarm.h"


int main(int argc, char **argv){
	int a;
	struct solar_context ctx;
	struct solar_alarm *alarm1,*alarm2;
	ctx.db_alarm = "db/alarm.db";
	solar_alarm_init(&ctx);
	
	solar_alarm_obtain(&alarm1);
	alarm1->device_id = 1;
	solar_alarm_enqueue(alarm1);
	
	solar_alarm_obtain(&alarm2);
	alarm2->device_id = 2;
	solar_alarm_enqueue(alarm2);

	solar_alarm_debug();

	scanf("input number to exit! ",&a);

	return 0;
}