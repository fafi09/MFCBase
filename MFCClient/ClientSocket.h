#pragma once

// CClientSocket ����Ŀ��

class CClientSocket : public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();
	BOOL InitClient(TCHAR* pszIP, WORD nPort);
	// �����ļ�
	BOOL SendFile(CString strPath);
	// ��������
	BOOL SendData(LPBYTE pData, DWORD nLen);
};


