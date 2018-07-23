#ifndef SOLAR_H
#define SOLAR_H


#define SOLAR_DEBUG 1


struct solar_context {
	const char* db_alarm;
	const char* db_energy;
	const char* db_power;
};

void solar_error(struct solar_context * context, const char *msg, ...);

const char * solar_command(struct solar_context * context, const char * cmd , const char * parm);

#endif /* SOLAR_H   */