// RecvDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCThread.h"
#include "RecvDlg.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(CRecvDlg, CDialog)
END_MESSAGE_MAP()


// CRecvDlg 消息处理程序
