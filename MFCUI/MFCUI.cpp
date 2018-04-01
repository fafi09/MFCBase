// MFCUI.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"

UINT g_nRegMsg = RegisterWindowMessage(TEXT("MyRegMsg"));
static UINT BASED_CODE indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	IDS_TIME,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL
};

class CMyView : public CView
{
public:
	virtual void OnDraw( CDC* pDC );
	virtual void OnInitialUpdate( );
	DECLARE_DYNCREATE( CMyView )
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg void OnPaint( );
	afx_msg void OnWriteHanzi( );
};

IMPLEMENT_DYNCREATE( CMyView, CView )

BEGIN_MESSAGE_MAP( CMyView, CView )
	ON_WM_PAINT( )
	ON_COMMAND( ID_WRITE, OnWriteHanzi )
END_MESSAGE_MAP( )

void CMyView::OnInitialUpdate( )
{
	AfxMessageBox(TEXT("CMyView is created onInitupdate"));
}

void CMyView::OnWriteHanzi( )
{
	AfxMessageBox(TEXT("hanzi"));
}

void CMyView::OnDraw( CDC* pDC )
{
	pDC->TextOutW(100,100, TEXT("hello ondraw"));
}

void CMyView::OnPaint( )
{
	PAINTSTRUCT ps = {0};
	HDC hDC = ::BeginPaint(m_hWnd, &ps);
	
	COLORREF cRef = SetBkColor(hDC, RGB(255,255,0));

	TCHAR szText[] = TEXT("hello view");
	TextOut(hDC, 100, 100, szText, wcslen(szText));

	SetBkColor(hDC, cRef);
	::EndPaint(m_hWnd, &ps);
}

class CMyHtmlView : public CHtmlView
{
public:
	virtual void OnInitialUpdate( );

	DECLARE_DYNCREATE( CMyHtmlView )

	DECLARE_MESSAGE_MAP( )
};

IMPLEMENT_DYNCREATE( CMyHtmlView, CHtmlView )

BEGIN_MESSAGE_MAP( CMyHtmlView, CHtmlView )
END_MESSAGE_MAP( )



void CMyHtmlView::OnInitialUpdate( )
{
	//AfxMessageBox(TEXT("CMyHtmlView is created onInitupdate"));
	//Navigate2(TEXT("c:\\"));
}

class CMyFrameWnd : public CFrameWnd
{
public:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL PreCreateWindow( CREATESTRUCT& cs );
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual int OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	afx_msg LRESULT OnPaint( WPARAM wParam, LPARAM lParam );
	afx_msg void OnTest( );
	afx_msg void OnExit( );
	afx_msg LRESULT OnRegMsg( WPARAM wParam, LPARAM lParam );
	afx_msg void OnToolBtn01( );
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnToolBarCheck( );
	afx_msg void OnUpdateToolBarV( CCmdUI* pCmdUI);
public:
	CToolBar m_ToolBar;
	CStatusBar m_StatusBar;
	CMyView* m_View;
	CSplitterWnd m_wndSpliter;
	CSplitterWnd m_wndRightSpliter;
};

BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	//ON_MESSAGE( WM_CREATE, OnCreate)
	ON_WM_CREATE( )
	ON_MESSAGE( WM_PAINT, OnPaint)
	ON_COMMAND( ID_TEST, OnTest )
	ON_COMMAND( ID_EXIT, OnExit )
	ON_COMMAND( ID_BUTTON40005, OnToolBtn01 )
	ON_WM_TIMER( )
	ON_COMMAND( ID_TOOLBARV, OnToolBarCheck )
	ON_UPDATE_COMMAND_UI( ID_TOOLBARV, OnUpdateToolBarV )
	//ON_REGISTERED_MESSAGE(g_nRegMsg, OnRegMsg)
END_MESSAGE_MAP( )

int CMyFrameWnd::OnCreateClient( LPCREATESTRUCT lpcs, CCreateContext* pContext )
{
	//静态切分
	m_wndSpliter.CreateStatic( this, 1, 2 );
	m_wndRightSpliter.CreateStatic(&m_wndSpliter, 2, 1, WS_CHILD | WS_VISIBLE, m_wndSpliter.IdFromRowCol(0,1));
	
	m_wndSpliter.CreateView(0, 0, RUNTIME_CLASS(CMyView), CSize(200, 200), pContext);
	m_wndRightSpliter.CreateView(0,0, RUNTIME_CLASS(CMyView), CSize(200,200), pContext);
	m_wndRightSpliter.CreateView(1,0, RUNTIME_CLASS(CMyHtmlView), CSize(200,200), pContext);
	
	CMyHtmlView* htmlView = (CMyHtmlView*)m_wndRightSpliter.GetPane(1,0);
	htmlView->Navigate2(TEXT("D:\\1"));

	//动态切分
	/*CCreateContext context;
	context.m_pNewViewClass = RUNTIME_CLASS( CMyView );
	m_wndSpliter.Create(this, 2, 2, CSize(50,50),&context);*/

	return TRUE;
}

LRESULT CMyFrameWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	/*switch(message)
	{
	case WM_CREATE:
		AfxMessageBox(TEXT("wm_create"));
		break;

	case WM_PAINT:

		PAINTSTRUCT ps = {0};
		HDC hDC = ::BeginPaint(this->m_hWnd, &ps);

		TCHAR szText[] = TEXT("hello mfc");
		TextOut(hDC, 100, 100, szText, wcslen(szText));

		::EndPaint(this->m_hWnd, &ps);
		break;
	}*/
	return CFrameWnd::WindowProc(message, wParam, lParam);
}


BOOL CMyFrameWnd::OnCmdMsg( UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo )
{
	return CFrameWnd::OnCmdMsg( nID, nCode, pExtra, pHandlerInfo );
}

BOOL CMyFrameWnd::PreCreateWindow( CREATESTRUCT& cs )
{
	CFrameWnd::PreCreateWindow(cs);

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;

	return TRUE;
}

void CMyFrameWnd::OnUpdateToolBarV( CCmdUI* pCmdUI )
{
	pCmdUI->SetCheck(m_ToolBar.IsWindowVisible());
}

void CMyFrameWnd::OnToolBarCheck( )
{
	if(m_ToolBar.IsWindowVisible())
	{
		ShowControlBar(&m_ToolBar, FALSE, FALSE);
	}
	else
	{
		ShowControlBar(&m_ToolBar, TRUE, FALSE);
	}
}

void CMyFrameWnd::OnTimer(UINT_PTR nIDEvent)
{
	//CTime tmCurrent = CTime::GetCurrentTime();
	CTime tmCurrent = CTime::GetTickCount();
	CString strTime = tmCurrent.Format(TEXT("%Y-%m-%d %H:%M:%S"));

	m_StatusBar.SetPaneText(1,strTime,TRUE);
	
}

void CMyFrameWnd::OnToolBtn01( )
{
	AfxMessageBox(TEXT("button0005"));
}

LRESULT CMyFrameWnd::OnRegMsg( WPARAM wParam, LPARAM lParam )
{
	AfxMessageBox(TEXT("OnRegMsg"));
	return 0;
}

void CMyFrameWnd::OnExit( )
{
	::PostQuitMessage( 0 );
}

void CMyFrameWnd::OnTest( )
{
	//AfxMessageBox(TEXT("OnTest"));
	SendMessage(g_nRegMsg);
}

//LRESULT CMyFrameWnd::OnCreate(WPARAM wParam, LPARAM lParam)
int CMyFrameWnd::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	//AfxMessageBox(TEXT("msg map create"));
	CFrameWnd::OnCreate(lpCreateStruct);

	//创建view
	/*m_View = new CMyView();

	m_View->Create(NULL, TEXT("View"), WS_CHILD | WS_VISIBLE | WS_BORDER ,
		CRect(100,100,200,200),this, AFX_IDW_PANE_FIRST);
	
	SetActiveView( m_View );*/

	ModifyStyleEx(WS_EX_CLIENTEDGE,0);

	if(FALSE == m_ToolBar.CreateEx(
		this, 
		TBSTYLE_FLAT,
		WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP|
		CBRS_GRIPPER|CBRS_TOOLTIPS))
	{
		return 1;
	}

	m_ToolBar.LoadToolBar(IDR_MAINFRM);

	m_ToolBar.EnableDocking( CBRS_ALIGN_ANY );

	EnableDocking( CBRS_ALIGN_ANY );

	DockControlBar( &m_ToolBar );


	//状态栏
	m_StatusBar.Create(this);

	m_StatusBar.SetIndicators(indicators, 
		sizeof(indicators)/sizeof(UINT));

	m_StatusBar.SetPaneInfo(1, 1002, SBPS_NORMAL, 200);
	SetTimer(1, 1000, NULL);
	return 1;
}

LRESULT CMyFrameWnd::OnPaint( WPARAM wParam, LPARAM lParam )
{
	PAINTSTRUCT ps = {0};
	HDC hDC = ::BeginPaint(this->m_hWnd, &ps);

	TCHAR szText[] = TEXT("msg map hello");

	TextOut(hDC, 100, 100, szText, wcslen(szText));

	::EndPaint(this->m_hWnd, &ps);

	return 0;
}

class CMyApp : public CWinApp
{
public:
	CMyApp();
	virtual BOOL InitInstance();
};

CMyApp theApp;

CMyApp::CMyApp( )
{

}

BOOL CMyApp::InitInstance()
{
	CMyFrameWnd* pWnd = new CMyFrameWnd();

	//pWnd->Create(NULL,TEXT("myapp"));
	pWnd->Create(
		NULL, 
		TEXT("myapp"), 
		WS_OVERLAPPEDWINDOW, 
		CFrameWnd::rectDefault, 
		NULL, 
		MAKEINTRESOURCE(IDR_MAINFRM));

	this->m_pMainWnd = pWnd;

	pWnd->ShowWindow(SW_SHOW);

	pWnd->UpdateWindow();

	return TRUE;

}