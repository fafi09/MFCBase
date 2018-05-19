// ClientSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCClient.h"
#include "ClientSocket.h"


// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// ��ʼ��Socket
typedef struct _tagHeader
{
	DWORD nLen;
	TCHAR szFile[MAX_PATH];
}HEADER,*LPHEADER;

BOOL CClientSocket::InitClient(TCHAR* pszIP, WORD nPort)
{
	if(Create() != TRUE)
	{
		return FALSE;
	}

	if(!Connect(pszIP, nPort))
	{
		return FALSE;
	}
	return TRUE;
}


// �����ļ�
BOOL CClientSocket::SendFile(CString strPath)
{
	CFile file;
	file.Open(strPath, CFile::modeRead);

	DWORD nLen = file.GetLength();

	LPBYTE pData = (LPBYTE) malloc(nLen);

	file.Read(pData, nLen);
	file.Close();

	HEADER header = {0};
	header.nLen = nLen;
	wcscpy(header.szFile, strPath);

	SendData((LPBYTE)&header, sizeof(header));

	SendData(pData, nLen);

	free(pData);

	return TRUE;
}


// ��������
BOOL CClientSocket::SendData(LPBYTE pData, DWORD nLen)
{
	LPBYTE pTmpData = pData;

	DWORD nLeft = nLen;

	while(nLeft > 0)
	{
		int nSend = Send(pData, nLeft, 0);

		if(nSend == SOCKET_ERROR)
			return FALSE;

		nLeft = nLeft - nSend;
		pTmpData = pTmpData + nSend;
	}

	return TRUE;
}
