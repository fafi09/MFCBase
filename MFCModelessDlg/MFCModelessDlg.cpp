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
	// TODO: �ڴ����ר�ô����/����û���

	CDialog::OnOK();

	DestroyWindow();
}
