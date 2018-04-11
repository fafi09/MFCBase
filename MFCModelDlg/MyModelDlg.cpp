// MyModelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyModelDlg.h"
#include "afxdialogex.h"


// CMyModelDlg 对话框

IMPLEMENT_DYNAMIC(CMyModelDlg, CDialog)

CMyModelDlg::CMyModelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyModelDlg::IDD, pParent)
{

}

CMyModelDlg::~CMyModelDlg()
{
}

void CMyModelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyModelDlg, CDialog)
END_MESSAGE_MAP()


// CMyModelDlg 消息处理程序
