#pragma once

// CServerSocket ����Ŀ��

class CServerSocket : public CAsyncSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
	virtual void OnAccept(int nErrorCode);
	// ��ʼ��������
	BOOL InitServer(WORD nPort);
	// �����ļ�
	BOOL RecvFile(CSocket & client, CString strFile, DWORD nLen);
	// ��������
	BOOL RecvData(CSocket & client, LPBYTE pData, DWORD nLen);
};


