#pragma once



// CUserThread

class CUserThread : public CWinThread
{
	DECLARE_DYNCREATE(CUserThread)

protected:
	CUserThread();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUserThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


