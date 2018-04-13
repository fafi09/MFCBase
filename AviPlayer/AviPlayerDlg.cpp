
// AviPlayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AviPlayer.h"
#include "AviPlayerDlg.h"
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


// CAviPlayerDlg 对话框




CAviPlayerDlg::CAviPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAviPlayerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strFilePath = _T("");
}

void CAviPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ANIMATE, m_wndAnimate);
	DDX_Control(pDX, IDC_HISTORY, m_wndHistory);
	DDX_Control(pDX, IDC_HOTKEY, m_wndHotKey);
	DDX_Control(pDX, IDC_LOOP, m_wndLoop);
	DDX_Text(pDX, IDC_PATH, m_strFilePath);
	DDX_Control(pDX, IDC_LOOPNUM, m_wndLoopNum);
}

BEGIN_MESSAGE_MAP(CAviPlayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, &CAviPlayerDlg::OnOpen)
	ON_COMMAND(IDC_START, &CAviPlayerDlg::OnStart)
	ON_COMMAND(IDC_STOP, &CAviPlayerDlg::OnStop)
	ON_BN_CLICKED(IDC_LOOP, &CAviPlayerDlg::OnLoop)
	ON_LBN_DBLCLK(IDC_HISTORY, &CAviPlayerDlg::OnDblclkHistory)
	ON_BN_CLICKED(IDC_SETHOTKEY_BTN, &CAviPlayerDlg::OnSethotkey)
END_MESSAGE_MAP()


// CAviPlayerDlg 消息处理程序

BOOL CAviPlayerDlg::OnInitDialog()
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
	//初始化播放循环的状态
	OnLoop();
	//初始化循环次数
	m_wndLoopNum.SetCurSel(0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAviPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAviPlayerDlg::OnPaint()
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
HCURSOR CAviPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAviPlayerDlg::OnOpen()
{
	TCHAR szFilter[] = TEXT("AVI(*.avi)|*.avi||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if(IDOK != dlg.DoModal())
	{
		return;
	}

	CString fileName = dlg.GetFileName();
	m_strFilePath = dlg.GetPathName();

	UpdateData(FALSE);

	//将文件名增加到历史列表
	int idx = m_wndHistory.AddString(fileName);

	CString* pfileName = new CString;
	*pfileName = dlg.GetFileName();

	m_wndHistory.SetItemData(idx, (DWORD)pfileName);


	 
}


void CAviPlayerDlg::OnStart()
{
	m_wndAnimate.Open(m_strFilePath);
	if(m_wndLoop.GetCheck())
	{
		int selIdx = m_wndLoopNum.GetCurSel();
		switch(selIdx)
		{
		case 0:
			m_wndAnimate.Play(0, -1, -1);
			break;
		case 1:
			m_wndAnimate.Play(0, -1, 1);
			break;
		case 2:
			m_wndAnimate.Play(0, -1, 2);
			break;
		}
	}
	else
	{
		m_wndAnimate.Play(0, -1, -1);
	}
}


void CAviPlayerDlg::OnStop()
{
	m_wndAnimate.Stop();
	m_wndAnimate.Close();
}


void CAviPlayerDlg::OnLoop()
{
	//得到播放是否循环的状态
	int nCheck = m_wndLoop.GetCheck();
	//设置combo是否可用
	m_wndLoopNum.EnableWindow(nCheck);

}


void CAviPlayerDlg::OnDblclkHistory()
{
	int idxSel = m_wndHistory.GetCurSel();
	CString* fileName = (CString*)m_wndHistory.GetItemData(idxSel);
	m_strFilePath = *fileName;

	UpdateData(FALSE);

}


void CAviPlayerDlg::OnSethotkey()
{
	//获取热键
	DWORD nHotKey = m_wndHotKey.GetHotKey();
	//设置程序热键
	SendMessage(WM_SETHOTKEY, nHotKey);
}
