헤더파일
void ErrorExit(const char* str);//progran exit
void ErrorMsg(const char* str);//monitor out put
void OKMsg(const char* str);
코딩작업
#include "MySocketError.h"

void ErrorExit(const char* str)
{
	LPVOID lpMsgBuf;
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_ALLOCATE_BUFFER
		, NULL, WSAGetLastError()
		, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
		, (char*)&lpMsgBuf, 0, NULL);
	printf("[%s]%s\n", str, (char*)lpMsgBuf);
	LocalFree(lpMsgBuf);
	exit(0);
}
void ErrorMsg(const char* str)
{
	LPVOID lpMsgBuf;
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_ALLOCATE_BUFFER
		, NULL, WSAGetLastError()
		, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
		, (char*)&lpMsgBuf, 0, NULL);
	printf("[%s]%s\n", str, (char*)lpMsgBuf);
	LocalFree(lpMsgBuf);
}
void OKMsg(const char* str)
{
	printf("[%s]successfully~~~\n", str);
}
