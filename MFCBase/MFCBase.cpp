#include "stdafx.h"

class CMyApp : public CWinApp
{
public:
	CMyApp( );
	virtual BOOL InitInstance();
};

class CMyFrameWnd: public CFrameWnd
{
public:
	CMyFrameWnd();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	/*afx_msg LRESULT OnCreate(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP( )*/
};

//LRESULT CMyFrameWnd::OnCreate(WPARAM wParam, LPARAM lParam)
//{
//	AfxMessageBox(TEXT("OnCreate"));
//	return 0;
//}
//
//
//BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
//	ON_MESSAGE(WM_CREATE, OnCreate)
//END_MESSAGE_MAP( )


LRESULT CMyFrameWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	/*switch(message)
	{
	case WM_CREATE:
		AfxMessageBox(TEXT("wm_create"));
		break;
	case WM_PAINT:
		PAINTSTRUCT ps = {0};
		HDC hDC = ::BeginPaint(m_hWnd, &ps);

		TCHAR szText[] = TEXT("Hello MFC");
		TextOut(hDC, 100,1000, szText, wcslen(szText));
		::EndPaint(m_hWnd, &ps);
		break;
	}*/

	return CFrameWnd::WindowProc(message, wParam, lParam);

}

CMyApp theApp;

CMyApp::CMyApp()
{

}


BOOL CMyApp::InitInstance()
{
	CMyFrameWnd* pWnd = new CMyFrameWnd();

	pWnd->Create(NULL, TEXT("myapp"));

	pWnd->ShowWindow(SW_SHOW);

	m_pMainWnd = pWnd;

	return TRUE;

}