// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 MQTT_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// MQTT_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifndef _MQTT_H_
#define _MQTT_H_

#ifdef MQTT_EXPORTS
#define MQTT_API __declspec(dllexport)
#else
#define MQTT_API __declspec(dllimport)
#endif

#define SUCCESS 0

	typedef void(*On_Message)(char * topic, int topic_len, char * message, int msg_len, void * obj);//回调函数

#ifdef __cplusplus
extern "C"
{
#endif

	MQTT_API void * Init(char * username, char * IP, int port, On_Message onMessage);
	MQTT_API int publish(void * obj, char * topic, char * message, bool retain);
	MQTT_API int subscribe(void * obj, char * topic);
	MQTT_API int FInit(void * obj);


#ifdef __cplusplus
};
#endif

#endif