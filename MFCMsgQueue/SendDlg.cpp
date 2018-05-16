// SendDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCMsgQueue.h"
#include "SendDlg.h"
#include "afxdialogex.h"
#include "MsgQueue.h"

// CSendDlg 对话框

IMPLEMENT_DYNAMIC(CSendDlg, CDialog)

CSendDlg::CSendDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendDlg::IDD, pParent)
{

}

CSendDlg::~CSendDlg()
{
}

void CSendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_wndSend);
}


BEGIN_MESSAGE_MAP(CSendDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_SEND, &CSendDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()


// CSendDlg 消息处理程序


void CSendDlg::OnBnClickedBtnSend()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxBeginThread(SendThread, this);
}


UINT CSendDlg::SendThread(LPVOID pParam)
{
	CSendDlg* dlg = (CSendDlg*)pParam;
	TCHAR szText[] = TEXT("hello send");
	while(1)
	{
		dlg->m_pQueue->Push(szText);
		dlg->m_wndSend.AddString(szText);
		Sleep(1000);
	}
	return 0;
}
