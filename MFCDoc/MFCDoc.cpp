// MFCDoc.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "MFCDoc.h"

class CMyDoc : public CDocument
{
public:
	CMyDoc( );
	CString m_stext;
	DECLARE_DYNCREATE( CMyDoc )
};

IMPLEMENT_DYNCREATE( CMyDoc, CDocument )

CMyDoc::CMyDoc( )
{
	m_stext = "hello doc";
}

class CMyView : public CEditView
{
public:
	CMyView( );
	virtual void OnDraw(CDC* pDC);
	virtual void OnInitialUpdate( );
	DECLARE_DYNCREATE( CMyView )
};

IMPLEMENT_DYNCREATE( CMyView, CEditView )

CMyView::CMyView( )
{

}

void CMyView::OnInitialUpdate( )
{
	CDocument* pDoc = GetDocument( );
	if( FALSE == pDoc->IsKindOf(RUNTIME_CLASS(CMyDoc)) )
	{
		return;
	}
	CMyDoc* pMyDoc = (CMyDoc*)pDoc;

	SetWindowText(pMyDoc->m_stext);
}

void CMyView::OnDraw( CDC* pDC )
{
	//pDC->TextOutW(100, 100, TEXT("hello view"));
}

class CMyFrameWnd : public CFrameWnd
{
public:
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg void OnExit( );
};

BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_COMMAND( IDM_EXIT, OnExit)
END_MESSAGE_MAP( )

void CMyFrameWnd::OnExit( )
{
	PostQuitMessage( 0 );
}


class CMyWinApp : public CWinApp
{
public:
	virtual BOOL InitInstance( );
};

CMyWinApp theApp;

BOOL CMyWinApp::InitInstance( )
{
	CMyFrameWnd* pWnd = new CMyFrameWnd( );

	CCreateContext context;
	context.m_pNewViewClass = RUNTIME_CLASS( CMyView );
	context.m_pCurrentDoc = new CMyDoc();

	pWnd->LoadFrame( IDC_MFCDOC, WS_OVERLAPPEDWINDOW, NULL, &context);

	this->m_pMainWnd = pWnd;

	pWnd->ShowWindow( SW_SHOW );

	pWnd->UpdateWindow( );

	//更新当前所有的view,否则view的Oninitialupdate不执行，
	//原因：在loadframe里如果ccreatecontext为空就发送initialupdate消息，否则不发送
	pWnd->InitialUpdateFrame(NULL, TRUE);
	return TRUE;
}