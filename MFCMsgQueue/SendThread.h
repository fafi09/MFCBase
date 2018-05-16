#pragma once



// CSendThread

class CSendThread : public CWinThread
{
	DECLARE_DYNCREATE(CSendThread)

protected:
	CSendThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CSendThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void SetQueue(CMsgQueue* pQueue);
};


