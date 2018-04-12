#include "stdafx.h"

class CModelDialog : public CDialog
{
public:
	CModelDialog();

	virtual BOOL OnInitDialog();
	virtual	void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
public:
	//与编辑框绑定
	CString m_Text;
	//与按钮绑定
	CWnd m_Button;
public:
	afx_msg void OnPaint();
	afx_msg void OnIdok();
	afx_msg void OnButton1();
};

BEGIN_MESSAGE_MAP(CModelDialog, CDialog)
	ON_WM_PAINT()
	ON_COMMAND(IDOK, &CModelDialog::OnIdok)
	ON_COMMAND(IDC_BUTTON1, &CModelDialog::OnButton1)
END_MESSAGE_MAP()


CModelDialog::CModelDialog():CDialog(IDD_DIALOG1)
{
	m_Text = "data exchange";
}

void CModelDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, m_Text);
	DDX_Control(pDX, IDC_BUTTON1, m_Button);

}

void CModelDialog::OnButton1()
{
	//UpdateData函数会调用DoDataExchange
	//TRUE  - 将数据从控件放置到变量
	//FALSE - 将数据从变量放置到控件
	UpdateData(TRUE);

	//m_Button.SetWindowTextW(m_Text);
	m_Button.GetWindowTextW(m_Text);
	UpdateData(FALSE);
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
