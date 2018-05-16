// SendThread.cpp : 实现文件
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
	// TODO: 在此执行任意逐线程初始化
	CSendDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return TRUE;
}

int CSendThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CSendThread, CWinThread)
END_MESSAGE_MAP()


// CSendThread 消息处理程序


void CSendThread::SetQueue(CMsgQueue* pQueue)
{
	((CSendDlg*)m_pMainWnd)->m_pQueue = pQueue;
}
