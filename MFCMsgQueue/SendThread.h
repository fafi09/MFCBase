#pragma once



// CSendThread

class CSendThread : public CWinThread
{
	DECLARE_DYNCREATE(CSendThread)

protected:
	CSendThread();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CSendThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void SetQueue(CMsgQueue* pQueue);
};


