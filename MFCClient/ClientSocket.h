#pragma once

// CClientSocket 命令目标

class CClientSocket : public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();
	BOOL InitClient(TCHAR* pszIP, WORD nPort);
	// 发送文件
	BOOL SendFile(CString strPath);
	// 发送数据
	BOOL SendData(LPBYTE pData, DWORD nLen);
};


