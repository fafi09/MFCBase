
// MFCDCView.cpp : CMFCDCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCDC.h"
#endif

#include "MFCDCDoc.h"
#include "MFCDCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDCView

IMPLEMENT_DYNCREATE(CMFCDCView, CView)

BEGIN_MESSAGE_MAP(CMFCDCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCDCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CDC, &CMFCDCView::OnCdc)
	ON_COMMAND(ID_CCLIENTDC, &CMFCDCView::OnCclientdc)
	ON_COMMAND(ID_CWINDOWDC, &CMFCDCView::OnCwindowdc)
	ON_COMMAND(ID_CMETAFILEDC, &CMFCDCView::OnCmetafiledc)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCDCView 构造/析构

CMFCDCView::CMFCDCView()
{
	// TODO: 在此处添加构造代码

}

CMFCDCView::~CMFCDCView()
{
}

BOOL CMFCDCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDCView 绘制

void CMFCDCView::OnDraw(CDC* /*pDC*/)
{
	CMFCDCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCDCView 打印


void CMFCDCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCDCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCDCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCDCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCDCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCDCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCDCView 诊断

#ifdef _DEBUG
void CMFCDCView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDCDoc* CMFCDCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDCDoc)));
	return (CMFCDCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDCView 消息处理程序


void CMFCDCView::OnCdc()
{
	CDC dc;
	//创建显示器dc
	dc.CreateDC( TEXT("DISPLAY"),NULL,NULL,NULL );
	//画矩形
	dc.Rectangle( 50, 50, 100, 100 );

	//删除dc
	dc.DeleteDC( );
}


void CMFCDCView::OnCclientdc()
{
	//客户区DC
	/*CClientDC dc(this);
	dc.Rectangle(50, 50, 100, 100);*/

	//使用CWnd提供的GetDC
	//获取客户区DC
	CDC* pDC = GetDC( );
	pDC->Rectangle(50,50,100,100);
	ReleaseDC( pDC );
}


void CMFCDCView::OnCwindowdc()
{
	//窗口DC
	CWindowDC dc(this);
	dc.Rectangle(50, 50, 100, 100);
}


void CMFCDCView::OnCmetafiledc()
{
	CMetaFileDC dc;
	//创建DC
	dc.Create(TEXT("D:\\meta.dat"));
	dc.FillSolidRect(100, 100, 150, 150, RGB(0, 0, 255));

	//关闭DC，并获得metafile句柄
	HMETAFILE hFile = dc.Close( );

	//建立客户DC，显示metafile
	CClientDC dcClient(this);
	dcClient.PlayMetaFile( hFile );

	//删除metafile文件句柄
	DeleteMetaFile( hFile );
}


void CMFCDCView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CView::OnPaint()
	dc.FillSolidRect(0,0,50,50, RGB(0,255,0));
}
