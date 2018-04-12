#include "stdafx.h"

class CMyModelessDlg : public CDialog
{
public:
	virtual void OnOK();
};


class CMyWinApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

CMyWinApp theApp;

BOOL CMyWinApp::InitInstance()
{
	CMyModelessDlg* dlg = new CMyModelessDlg();
	dlg->Create(IDD_DIALOG1);
	m_pMainWnd = dlg;

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

void CMyModelessDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialog::OnOK();

	DestroyWindow();
}
