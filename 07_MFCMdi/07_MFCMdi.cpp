// 07_MFCMdi.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"

class CMdiDoc : public CDocument
{
public:
	DECLARE_DYNCREATE( CMdiDoc )
public:
	CString m_text;
};

IMPLEMENT_DYNCREATE( CMdiDoc, CDocument )

class CMdiView : public CEditView
{
public:
	virtual void OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint );
	DECLARE_DYNCREATE( CMdiView )
public:
	afx_msg BOOL OnEnChange( );
	DECLARE_MESSAGE_MAP( )
};

IMPLEMENT_DYNCREATE( CMdiView, CEditView )
BEGIN_MESSAGE_MAP( CMdiView, CEditView )
	ON_CONTROL_REFLECT_EX( EN_CHANGE, OnEnChange )
END_MESSAGE_MAP( )

BOOL CMdiView::OnEnChange( )
{
	//获取文档
	CMdiDoc* pDoc = ( CMdiDoc* )GetDocument();

	//将数据保存到文档
	GetWindowText( pDoc->m_text );

	//通知所有该文档关联的所有视图
	pDoc->UpdateAllViews( this );
	return TRUE;
}

void CMdiView::OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint )
{
	//此方法由pDoc->UpdateAllViews( this );触发

	//取得文档
	CMdiDoc* pDoc = ( CMdiDoc* )GetDocument();
	SetWindowText( pDoc->m_text );
}

class CChileFrameWnd: public CMDIChildWnd
{
public:
	DECLARE_DYNCREATE( CChileFrameWnd )
public:
	afx_msg void OnNewView( );

	DECLARE_MESSAGE_MAP( )
};

IMPLEMENT_DYNCREATE( CChileFrameWnd, CMDIChildWnd )

BEGIN_MESSAGE_MAP( CChileFrameWnd, CMDIChildWnd )
	ON_COMMAND( ID_NEW_VIEW, OnNewView )
END_MESSAGE_MAP( )

void CChileFrameWnd::OnNewView( )
{
	//AfxMessageBox(TEXT("OnNewView"));
	CFrameWnd* pFrame = GetActiveFrame( );
	if( FALSE == pFrame->IsKindOf(RUNTIME_CLASS(CChileFrameWnd)) )
	{
		return;
	}

	CChileFrameWnd* pChildFrame = (CChileFrameWnd*)pFrame; 

	//取得活动的view
	CMdiView* pActiveView = ( CMdiView* )pChildFrame->GetActiveView( );
	//通过活的view取得doc
	CMdiDoc* pActiveDoc = ( CMdiDoc* )pActiveView->GetDocument( );

	//取得所在的app对象
	CWinApp* pWinApp = AfxGetApp( );
	//取得文档模板
	POSITION pos = pWinApp->GetFirstDocTemplatePosition( );
	CDocTemplate* docTemp = pWinApp->GetNextDocTemplate(pos);


	//文档模板创建窗口
	CChileFrameWnd* pNewChildWnd = 
	( CChileFrameWnd* )docTemp->CreateNewFrame( pActiveDoc, NULL);

	//等同于pNewChildWnd的视图更新
	docTemp->InitialUpdateFrame( pNewChildWnd, pActiveDoc );


	
}

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