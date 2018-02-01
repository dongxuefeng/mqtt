// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MQTT_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MQTT_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifndef _MQTT_H_
#define _MQTT_H_

#ifdef MQTT_EXPORTS
#define MQTT_API __declspec(dllexport)
#else
#define MQTT_API __declspec(dllimport)
#endif

#define SUCCESS 0

	typedef void(*On_Message)(char * topic, int topic_len, char * message, int msg_len, void * obj);//�ص�����

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