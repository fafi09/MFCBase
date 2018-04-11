#include "stdafx.h"

class CModelDialog : public CDialog
{
public:
	CModelDialog();

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnIdok();
};

CModelDialog::CModelDialog():CDialog(IDD_DIALOG1)
{

}

class CMyWinApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
	CMyWinApp();
};

CMyWinApp theApp;

CMyWinApp::CMyWinApp()
{

}

BOOL CMyWinApp::InitInstance()
{
	CModelDialog dlg;
	m_pMainWnd = &dlg;
	if(dlg.DoModal() == IDOK)
	{
		AfxMessageBox(TEXT("ok"));
	}
	else
	{
		AfxMessageBox(TEXT("cancel"));
	}
	return TRUE;
}

BOOL CModelDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	AfxMessageBox(TEXT("OnInitDialog"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
BEGIN_MESSAGE_MAP(CModelDialog, CDialog)
	ON_WM_PAINT()
	ON_COMMAND(IDOK, &CModelDialog::OnIdok)
END_MESSAGE_MAP()


void CModelDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()

	dc.Rectangle(0,0,100,100);
}


void CModelDialog::OnIdok()
{
	CDialog::OnOK();
}
