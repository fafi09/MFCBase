
// ATLDispUseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ATLDispUse.h"
#include "ATLDispUseDlg.h"
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


// CATLDispUseDlg 对话框




CATLDispUseDlg::CATLDispUseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CATLDispUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CATLDispUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CATLDispUseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NOPARAM, &CATLDispUseDlg::OnClickedNoparam)
	ON_BN_CLICKED(IDC_PARAM, &CATLDispUseDlg::OnClickedParam)
	ON_BN_CLICKED(IDC_PROP, &CATLDispUseDlg::OnClickedProp)
	ON_BN_CLICKED(IDC_TYPELIB, &CATLDispUseDlg::OnClickedTypelib)
END_MESSAGE_MAP()


// CATLDispUseDlg 消息处理程序

BOOL CATLDispUseDlg::OnInitDialog()
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

void CATLDispUseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CATLDispUseDlg::OnPaint()
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
HCURSOR CATLDispUseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#include "../ATLDisp/ATLDisp_i.c"
IDispatch* CATLDispUseDlg::GetDispatch(void)
{
	IDispatch* pDispatch = NULL;

	CoCreateInstance(CLSID_Fruit,NULL,CLSCTX_INPROC_SERVER, IID_IDispatch, (LPVOID*)&pDispatch);

	return pDispatch;
}


void CATLDispUseDlg::OnClickedNoparam()
{
	IDispatch* pDispatch = NULL;

	pDispatch = GetDispatch();

	DISPID dispid = {0};
	TCHAR* psczName[] = {TEXT("ShowMsg")};


	pDispatch->GetIDsOfNames(IID_NULL, psczName, 1, LOCALE_USER_DEFAULT, &dispid);

	DISPPARAMS params = {0};
	VARIANT result = {0};
	pDispatch->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &result, NULL, NULL);


	pDispatch->Release();
}


void CATLDispUseDlg::OnClickedParam()
{
	IDispatch* pDispatch = NULL;

	pDispatch = GetDispatch();

	DISPID dispid = {0};
	TCHAR* psczName[] = {TEXT("Add")};


	pDispatch->GetIDsOfNames(IID_NULL, psczName, 1, LOCALE_USER_DEFAULT, &dispid);

	long nAdd = 0;
	VARIANT args[3] = {0}; //参数的顺序从右到左
	args[0].vt = VT_BYREF|VT_I4;
	args[0].plVal = &nAdd;
	args[1].vt = VT_I4;
	args[1].lVal = 6;
	args[2].vt = VT_I4;
	args[2].lVal = 5;

	DISPPARAMS params = {0};
	params.cArgs = 3;
	params.rgvarg = args;


	VARIANT result = {0};
	pDispatch->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &result, NULL, NULL);

	CString strValue;
	strValue.Format(TEXT("%ld"),nAdd);
	AfxMessageBox(strValue);

	pDispatch->Release();
}


void CATLDispUseDlg::OnClickedProp()
{
	IDispatch* pDispatch = NULL;

	pDispatch = GetDispatch();

	DISPID dispid = {0};
	TCHAR* psczName[] = {TEXT("eye")};


	pDispatch->GetIDsOfNames(IID_NULL, psczName, 1, LOCALE_USER_DEFAULT, &dispid);

	long nAdd = 0;
	VARIANT argNum = {0}; //参数的顺序从右到左
	argNum.vt = VT_I4;
	argNum.lVal = 9;

	DISPID nDispID = DISPID_PROPERTYPUT;

	DISPPARAMS params = {0};
	params.cArgs = 1;
	params.rgvarg = &argNum;
	params.cNamedArgs = 1;
	params.rgdispidNamedArgs = &nDispID;


	VARIANT result = {0};
	pDispatch->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYPUT, &params, &result, NULL, NULL);

	//获取属性
	DISPPARAMS params1 = {0};
	VARIANT varValue = {0};
	pDispatch->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &params1, &varValue, NULL, NULL);

	CString strValue;
	strValue.Format(TEXT("%ld"),varValue.lVal);
	AfxMessageBox(strValue);

	pDispatch->Release();
}

#include "CFruit.h"
void CATLDispUseDlg::OnClickedTypelib()
{
	CFruit fruit;
	fruit.CreateDispatch(TEXT("ATLDisp.Fruit"));
	fruit.ShowMsg();
}



