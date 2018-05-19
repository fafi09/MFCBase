// socketclient.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <conio.h>

#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

void TCPClient()
{
	SOCKET cliSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in cliAddr = {0};
	

	cliAddr.sin_family = AF_INET;
	cliAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	cliAddr.sin_port = htons(5678);

	int nlen = sizeof(sockaddr);
	connect(cliSocket, (sockaddr*)&cliAddr, nlen);

	char szText[] = "hello server";
	send(cliSocket, szText, sizeof(szText), 0);

	char szServer[100] = {0};
	recv(cliSocket, szServer, 100, 0);

	printf("%s\n",szServer);

	closesocket(cliSocket);
}

void UDPClient()
{
	SOCKET sockSvr = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	struct sockaddr_in svrAddr = {0};
	svrAddr.sin_family = AF_INET;
	//svrAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	svrAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	svrAddr.sin_port = htons(5678);

	//bind(sockSvr, (sockaddr*)&svrAddr, sizeof(svrAddr));

	char szText[100] = "hello server";
	
	//send(sockSvr, szText, 100, 0);
	sendto(sockSvr, szText, sizeof(szText), 0, (sockaddr*)&svrAddr, sizeof(svrAddr));



	printf("send over\n");
	closesocket(sockSvr);
}


int _tmain(int argc, _TCHAR* argv[])
{

	WSADATA wsa = {0};
	WSAStartup(MAKEWORD(2,2), &wsa);

	//TCPClient();
	UDPClient();

	getch();
	return 0;
}

