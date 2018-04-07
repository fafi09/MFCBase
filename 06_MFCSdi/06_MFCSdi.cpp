// 06_MFCSdi.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"

class CSdiDocument: public CDocument
{
public:
	DECLARE_DYNCREATE( CSdiDocument )
};

IMPLEMENT_DYNCREATE( CSdiDocument, CDocument )

class CSdiView : public CEditView
{
public:
	DECLARE_DYNCREATE( CSdiView )
};

IMPLEMENT_DYNCREATE( CSdiView, CEditView )

class CSdiFrame : public CFrameWnd
{
public:
	DECLARE_DYNCREATE( CSdiFrame )
};

IMPLEMENT_DYNCREATE( CSdiFrame, CFrameWnd )

class CSdiWinApp : public CWinApp
{
public:
	virtual BOOL InitInstance( );
};

CSdiWinApp theApp;

BOOL CSdiWinApp::InitInstance( )
{
	CSingleDocTemplate* docTemplate 
		= new CSingleDocTemplate(
			IDC_MY06_MFCSDI,
			RUNTIME_CLASS( CSdiDocument ),
			RUNTIME_CLASS( CSdiFrame ),
			RUNTIME_CLASS( CSdiView ));

	AddDocTemplate( docTemplate );

	OnFileNew( );

	m_pMainWnd->ShowWindow( SW_SHOW );

	m_pMainWnd->UpdateWindow( );
	return TRUE;

}