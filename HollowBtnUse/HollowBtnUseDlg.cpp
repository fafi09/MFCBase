
// HollowBtnUseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HollowBtnUse.h"
#include "HollowBtnUseDlg.h"
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


// CHollowBtnUseDlg 对话框




CHollowBtnUseDlg::CHollowBtnUseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHollowBtnUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHollowBtnUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHollowBtnUseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CHollowBtnUseDlg 消息处理程序

BOOL CHollowBtnUseDlg::OnInitDialog()
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
	SetBmpRgn(IDB_BITMAP1);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CHollowBtnUseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHollowBtnUseDlg::OnPaint()
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

		/*CClientDC dc(this);
		CRect dcRect;
		GetClientRect(&dcRect);
		dc.FillSolidRect(dcRect, RGB(255,128,64));*/
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHollowBtnUseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHollowBtnUseDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}
BEGIN_EVENTSINK_MAP(CHollowBtnUseDlg, CDialogEx)
	ON_EVENT(CHollowBtnUseDlg, IDC_HOLLOWBTN1CTRL1, DISPID_CLICK, CHollowBtnUseDlg::ClickHollowbtn1ctrl1, VTS_NONE)
END_EVENTSINK_MAP()


void CHollowBtnUseDlg::ClickHollowbtn1ctrl1()
{
	AfxMessageBox(TEXT("click"));
}


void CHollowBtnUseDlg::SetBmpRgn(int nID)
{
	//加载图片
	CClientDC dc(this);
	CBitmap bmp;
	bmp.LoadBitmap(nID);
	CDC dcBmp;
	dcBmp.CreateCompatibleDC(&dc);
	CBitmap *pOldBmp=dcBmp.SelectObject(&bmp);
	//创建区域
	CRect rcWnd;
	GetWindowRect(&rcWnd);
	CRgn rgnWnd;
	rgnWnd.CreateRectRgn(0,0,
		rcWnd.Width(),rcWnd.Height());
	//计算图片的区域
	for(int nX=0;nX<77;nX++)
	{
		for(int nY=0;nY<77;nY++)
		{
			//获取图片每一个点的颜色
			COLORREF nColor=dcBmp.GetPixel(nX,nY);
			//判断颜色是否为屏蔽色
			if(nColor==RGB(255,255,255))
			{
				CRgn rgnRect;
				rgnRect.CreateRectRgn(nX+50,nY+50,nX+51,nY+51);
				//减去屏蔽色的区域
				rgnWnd.CombineRgn(&rgnWnd,&rgnRect,
					RGN_XOR);
			}
		}

	}
	//设置窗口
	SetWindowRgn(rgnWnd,TRUE);
	dcBmp.SelectObject(pOldBmp);
}
