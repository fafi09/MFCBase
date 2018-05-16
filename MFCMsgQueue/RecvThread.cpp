// RecvThread.cpp : 实现文件
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
	// TODO: 在此执行任意逐线程初始化
	CRecvDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	return TRUE;
}

int CRecvThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CRecvThread, CWinThread)
END_MESSAGE_MAP()


// CRecvThread 消息处理程序


void CRecvThread::SetQueue(CMsgQueue* pQueue)
{
	((CRecvDlg*)m_pMainWnd)->m_pQueue = pQueue;
}
