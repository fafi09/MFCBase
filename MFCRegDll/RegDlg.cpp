// RegDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCRegDll.h"
#include "RegDlg.h"
#include "afxdialogex.h"


// RegDlg 对话框

IMPLEMENT_DYNAMIC(RegDlg, CDialog)

RegDlg::RegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RegDlg::IDD, pParent)
{

}

RegDlg::~RegDlg()
{
}

void RegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RegDlg, CDialog)
END_MESSAGE_MAP()


// RegDlg 消息处理程序
