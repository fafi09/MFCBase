// ServerSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCServer.h"
#include "ServerSocket.h"


// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// CServerSocket 成员函数
typedef struct _tagHeader
{
	DWORD nlen;
	TCHAR szFile[MAX_PATH];
} HEADER, *LPHEADER ;

void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	CSocket client;
	Accept(client);

	HEADER header={0};

	RecvData(client, (LPBYTE)&header, sizeof(header));

	//获取文件名
	CString strFileName=header.szFile;
	int nFind=strFileName.ReverseFind('\\');
	strFileName=strFileName.Mid(nFind+1);
	//文件路径
	CString strPath=TEXT("C:\\");
	strPath=strPath+strFileName;
	AfxMessageBox(strPath);

	RecvFile(client, strPath, header.nlen);

	CAsyncSocket::OnAccept(nErrorCode);
}


// 初始化服务器
BOOL CServerSocket::InitServer(WORD nPort)
{
	if(Create(nPort) != TRUE )
	{
		return FALSE;
	}

	return Listen();
}

// 接收文件
BOOL CServerSocket::RecvFile(CSocket & client, CString strFile, DWORD nLen)
{
	LPBYTE pData = (LPBYTE)malloc(nLen);
	memset(pData, 0 , nLen);

	int nRecv = client.Receive(pData, nLen);

	if(nRecv == SOCKET_ERROR)
	{
		return FALSE;
	}

	CFile file;
	file.Open(strFile, CFile::modeCreate | CFile::modeWrite);

	file.Write(pData, nLen);

	file.Close();


	free(pData);
}


// 接收数据
BOOL CServerSocket::RecvData(CSocket & client, LPBYTE pData, DWORD nLen)
{
	LPBYTE pTmpData = pData;

	DWORD nLeft = nLen;

	while(nLeft > 0)
	{
		int nRecv = client.Receive(pTmpData, nLeft);
		if(nRecv == SOCKET_ERROR)
			return FALSE;
		nLeft = nLeft - nRecv;
		pTmpData = pTmpData + nRecv;
	}

	return TRUE;
}
