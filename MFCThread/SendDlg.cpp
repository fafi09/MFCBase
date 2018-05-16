// SendDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCThread.h"
#include "SendDlg.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(CSendDlg, CDialog)
END_MESSAGE_MAP()


// CSendDlg 消息处理程序
