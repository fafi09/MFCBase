// RecvThread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCMsgQueue.h"
#include "RecvThread.h"
#include "RecvDlg.h"

// CRecvThread

IMPLEMENT_DYNCREATE(CRecvThread, CWinThread)

CRecvThread::CRecvThread()
{
}

CRecvThread::~CRecvThread()
{
}

BOOL CRecvThread::InitInstance()
{
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	CRecvDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	return TRUE;
}

int CRecvThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CRecvThread, CWinThread)
END_MESSAGE_MAP()


// CRecvThread ��Ϣ�������


void CRecvThread::SetQueue(CMsgQueue* pQueue)
{
	((CRecvDlg*)m_pMainWnd)->m_pQueue = pQueue;
}
