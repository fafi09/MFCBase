
// AutoWord1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AutoWord1.h"
#include "AutoWord1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAutoWord1Dlg 对话框




CAutoWord1Dlg::CAutoWord1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAutoWord1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoWord1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAutoWord1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AUTOEXE, &CAutoWord1Dlg::OnClickedAutoexe)
	ON_BN_CLICKED(IDC_AUTODLL, &CAutoWord1Dlg::OnClickedAutodll)
	ON_BN_CLICKED(IDC_WORD, &CAutoWord1Dlg::OnClickedWord)
END_MESSAGE_MAP()


// CAutoWord1Dlg 消息处理程序

BOOL CAutoWord1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAutoWord1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAutoWord1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAutoWord1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#include "CAutoExe1.h"

void CAutoWord1Dlg::OnClickedAutoexe()
{
	CAutoExe1 exe;
	exe.CreateDispatch(TEXT("AutoExe1.Document"));

	exe.SetVisible(TRUE);
	exe.TypeText(TEXT("hello AutoExe"));

	exe.DetachDispatch();
}

#include "CMath.h"
void CAutoWord1Dlg::OnClickedAutodll()
{
	CMath math;
	math.CreateDispatch(TEXT("AutoDll1.Math"));

	LONG nAdd = 0;
	math.Sub(10, 4, &nAdd);


	math.DetachDispatch();
	CString strText;
	strText.Format(TEXT("%d"),nAdd);
	AfxMessageBox(strText);

}

#include "CApplication.h"
#include "CDocument0.h"
#include "CSelection.h"
#include "CDocuments.h"

void CAutoWord1Dlg::OnClickedWord()
{
	CApplication app;
	app.CreateDispatch(TEXT("Word.Application"));
	app.put_Visible(TRUE);

	CDocuments docs = app.get_Documents();

	COleVariant templateDoc(_T(""));
	COleVariant newTemplateDoc(0L);
	COleVariant doctype(0L);
	COleVariant varVisiable;


	CDocument0 doc = docs.Add(&templateDoc, &newTemplateDoc, &doctype, &varVisiable);

	CSelection sel = app.get_Selection();
	sel.TypeText(TEXT("hello world"));

	doc.Save();
	app.DetachDispatch();
}
