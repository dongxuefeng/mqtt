// mqtt.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "mqtt.h"
#include "mosquitto.h"


void * Init(char * username, char * IP, int port, On_Message onMessage)
{
	void * userdata = NULL;
	mosquitto_lib_init();
	userdata = mosquitto_new(username, false, userdata);
	return userdata;
}
int publish(void * obj, char * topic, char * message, bool retain)
{

	return 0;
}
int subscribe(void * obj, char * topic)
{

	return 0;
}
int FInit(void * obj)
{
	mosquitto_lib_cleanup();
	return 0;
}