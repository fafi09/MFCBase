#pragma once



// CRecvThread

class CRecvThread : public CWinThread
{
	DECLARE_DYNCREATE(CRecvThread)

protected:
	CRecvThread();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CRecvThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void SetQueue(CMsgQueue* pQueue);
};


