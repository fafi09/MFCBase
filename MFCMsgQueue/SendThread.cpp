// SendThread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCMsgQueue.h"
#include "SendThread.h"
#include "SendDlg.h"

// CSendThread

IMPLEMENT_DYNCREATE(CSendThread, CWinThread)

CSendThread::CSendThread()
{
}

CSendThread::~CSendThread()
{
}

BOOL CSendThread::InitInstance()
{
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	CSendDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return TRUE;
}

int CSendThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CSendThread, CWinThread)
END_MESSAGE_MAP()


// CSendThread ��Ϣ�������


void CSendThread::SetQueue(CMsgQueue* pQueue)
{
	((CSendDlg*)m_pMainWnd)->m_pQueue = pQueue;
}
