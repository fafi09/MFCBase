#pragma once

// CServerSocket 命令目标

class CServerSocket : public CAsyncSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
	virtual void OnAccept(int nErrorCode);
	// 初始化服务器
	BOOL InitServer(WORD nPort);
	// 接收文件
	BOOL RecvFile(CSocket & client, CString strFile, DWORD nLen);
	// 接收数据
	BOOL RecvData(CSocket & client, LPBYTE pData, DWORD nLen);
};


