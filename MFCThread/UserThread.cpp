// UserThread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCThread.h"
#include "UserThread.h"
#include "TestDlg.h"

// CUserThread

IMPLEMENT_DYNCREATE(CUserThread, CWinThread)

CUserThread::CUserThread()
{
}

CUserThread::~CUserThread()
{
}

BOOL CUserThread::InitInstance()
{
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	CTestDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	return TRUE;
}

int CUserThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUserThread, CWinThread)
END_MESSAGE_MAP()


// CUserThread ��Ϣ�������
