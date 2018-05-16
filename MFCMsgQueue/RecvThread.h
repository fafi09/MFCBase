#pragma once



// CRecvThread

class CRecvThread : public CWinThread
{
	DECLARE_DYNCREATE(CRecvThread)

protected:
	CRecvThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CRecvThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void SetQueue(CMsgQueue* pQueue);
};


