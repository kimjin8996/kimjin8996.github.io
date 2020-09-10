#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define SERVER_PORT 9001 //well-known port만 아니면 돼 
#include "MySocketError.h"   //winsock2.h ->제일 먼저 #include 해야 한다.
#pragma comment(lib,"ws2_32.lib")
int main(void) {
	int result = -1;
	//WSAStartup
	 WSADATA wData = { 0 };
	result=WSAStartup (MAKEWORD(2, 2) ,&wData);
	if (!result)OKMsg("WSAStartup");
	else ErrorExit("WSAStartup");
	//socket
	SOCKET serversocket;
	serversocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serversocket == INVALID_SOCKET)
		ErrorExit("serversoket");
	else OKMsg("serversoket");
	//AF_INET
	//bind
	SOCKADDR_IN serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(SERVER_PORT);
	serverAddress.sin_addr.s_addr = inet_addr("192.168.0.4");
	result = bind(serversocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress));
	if (result == SOCKET_ERROR)
		ErrorMsg("bind");
	else OKMsg("bind");
	//listen
	result = listen(serversocket, 5);
	if (result == SOCKET_ERROR)
		ErrorMsg("listen");
	else OKMsg("listen");
	//accept
	SOCKET clientsocket;
	SOCKADDR_IN clientAddress = { 0 };
	int sizeclientAddress = sizeof(clientAddress);
	clientsocket = accept(serversocket, (SOCKADDR*)&clientAddress, &sizeclientAddress);
	if (result == INVALID_SOCKET)
		ErrorMsg("accept");
	else OKMsg("accept");
	printf("client(IP:%s,PORT:%d)accepted\n",
		inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
	//send(보내고 싶을 때 작성),recv(받는 정보가 있을때 작성)
	char data[] = "i`m 26years old";
	result = send(clientsocket, (char*)&data, sizeof(data), 0);
	if (result == SOCKET_ERROR)
		ErrorMsg("closesocket");
	else OKMsg("closesocket");
	memset(data, 0, 20);
	result = recv(clientsocket, (char*)data, sizeof(data), 0);
	if (result == SOCKET_ERROR) ErrorMsg("closesocket");
	else OKMsg("closesocket");
	//closesocket
	result = closesocket(clientsocket);
		if (result == SOCKET_ERROR)
			ErrorMsg("closesocket-server");
		else OKMsg("closesocket-server");
	//closesocket
		result = closesocket(serversocket);
		if (result == SOCKET_ERROR)
			ErrorMsg("closesocket-server");
		else OKMsg("closesocket-server");
	//WSACleanup
	result = WSACleanup();
	if (result == SOCKET_ERROR)
		ErrorMsg("WSACleanup");
	else OKMsg("WSACleanup");
	return 0;
}
