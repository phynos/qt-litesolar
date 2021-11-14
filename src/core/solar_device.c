#include "solar_device.h"


struct solar_device {
	int id;
	long createDateTime;
	char *name;
	int deviceTypeId;
	int protocolId;
	long devcieInstallDateTime;

	int portType;
	int writeDBInterval;

	char *ip;
	int port;

	char *com;
	int baudrate;
	int dataBit;
	int stopBit;
	int parity;

	int writeTimeout;
	int readTimeout;

	int slaveId;

	/* 设备通讯中断判定方式 */
	int interruptType
};