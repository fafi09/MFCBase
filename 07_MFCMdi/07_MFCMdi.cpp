// 07_MFCMdi.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"

class CMdiDoc : public CDocument
{
public:
	DECLARE_DYNCREATE( CMdiDoc )
};

IMPLEMENT_DYNCREATE( CMdiDoc, CDocument )

class CMdiView : public CEditView
{
public:
	DECLARE_DYNCREATE( CMdiView )
};

IMPLEMENT_DYNCREATE( CMdiView, CEditView )

class CChileFrameWnd: public CMDIChildWnd
{
public:
	DECLARE_DYNCREATE( CChileFrameWnd )
};

IMPLEMENT_DYNCREATE( CChileFrameWnd, CMDIChildWnd )

class CMainFrameWnd: public CMDIFrameWnd
{
public:
	DECLARE_DYNCREATE( CMainFrameWnd )
};

IMPLEMENT_DYNCREATE( CMainFrameWnd, CMDIFrameWnd )

class CMdiWinApp : public CWinApp
{
public:
	virtual BOOL InitInstance( );

	DECLARE_MESSAGE_MAP( )
public:
	afx_msg void OnNew( );
};

BEGIN_MESSAGE_MAP( CMdiWinApp, CWinApp )
	ON_COMMAND( ID_NEW1, OnNew )
END_MESSAGE_MAP( )


CMdiWinApp theApp;

void CMdiWinApp::OnNew( )
{
	OnFileNew( );
}

BOOL CMdiWinApp::InitInstance( )
{
	CMultiDocTemplate* temp 
		= new CMultiDocTemplate( 
			IDC_MY07_MFCMDI1, 
			RUNTIME_CLASS( CMdiDoc ),
			RUNTIME_CLASS( CChileFrameWnd ),
			RUNTIME_CLASS( CMdiView ));

	AddDocTemplate( temp );

	CMainFrameWnd* pMainFrame =  new CMainFrameWnd();

	pMainFrame->LoadFrame( IDC_MY07_MFCMDI );

	m_pMainWnd = pMainFrame;

	m_pMainWnd->ShowWindow( SW_SHOW );

	m_pMainWnd->UpdateWindow( );

	OnFileNew( );

	return TRUE;
}