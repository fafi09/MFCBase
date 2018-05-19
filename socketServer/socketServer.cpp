// socketServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <conio.h>

#include <WinSock2.h>

#pragma comment(lib,"Ws2_32.lib")


void TCPServer()
{
	SOCKET socketSvr = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in addr = {0};

	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(5678);


	bind(socketSvr, (struct sockaddr*)&addr, sizeof(addr));

	listen(socketSvr, SOMAXCONN);

	struct sockaddr_in cliAddr = {0};

	int nlen = sizeof(cliAddr);

	printf("wait for client...\n");

	SOCKET cliSocket =  accept(socketSvr, (struct sockaddr*)&cliAddr, &nlen);

	printf("client is connected\n");


	char szText[100] = {0};

	recv(cliSocket, szText, 100, 0);
	
	printf("%s\n",szText);
	
	char szSend[] = "hello client";

	send(cliSocket, szSend, sizeof(szSend), 0);

	closesocket(cliSocket);
	closesocket(socketSvr);
}

void UDPServer()
{
	SOCKET sockSvr = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	struct sockaddr_in svrAddr = {0};
	svrAddr.sin_family = AF_INET;
	svrAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	svrAddr.sin_port = htons(5678);

	bind(sockSvr, (sockaddr*)&svrAddr, sizeof(svrAddr));

	char szText[100] = {0};
	getch();

	struct sockaddr_in cliAddr = {0};
	int nlen = sizeof(cliAddr);

	recvfrom(sockSvr, szText, 100, 0, (sockaddr*)&cliAddr, &nlen);
	//recv(sockSvr, szText, 100, 0);
	printf("%ld\n", GetLastError());
	printf("%s\n", szText);

	closesocket(sockSvr);
}


int _tmain(int argc, _TCHAR* argv[])
{

	//初始化socket库

	WSADATA wsa = {0};
	WSAStartup(MAKEWORD(2,2), &wsa);

	//TCPServer();
	UDPServer();

	getch();
	return 0;
}

