// RecvDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCMsgQueue.h"
#include "RecvDlg.h"
#include "afxdialogex.h"
#include "MsgQueue.h"

// CRecvDlg 对话框

IMPLEMENT_DYNAMIC(CRecvDlg, CDialog)

CRecvDlg::CRecvDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecvDlg::IDD, pParent)
{

}

CRecvDlg::~CRecvDlg()
{
}

void CRecvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_wndData);
}


BEGIN_MESSAGE_MAP(CRecvDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_RECV, &CRecvDlg::OnBnClickedBtnRecv)
END_MESSAGE_MAP()


// CRecvDlg 消息处理程序


void CRecvDlg::OnBnClickedBtnRecv()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxBeginThread(RecvThread,this);
}


UINT CRecvDlg::RecvThread(LPVOID pParam)
{
	CRecvDlg* pThis = (CRecvDlg*)pParam;
	while(1)
	{
		TCHAR szText[100] = {0};
		pThis->m_pQueue->Pop(szText);
		pThis->m_wndData.AddString(szText);
	}
	return 0;
}
