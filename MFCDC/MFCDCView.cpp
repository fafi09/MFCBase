
// MFCDCView.cpp : CMFCDCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMFCDCView ����/����

CMFCDCView::CMFCDCView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCDCView::~CMFCDCView()
{
}

BOOL CMFCDCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCDCView ����

void CMFCDCView::OnDraw(CDC* /*pDC*/)
{
	CMFCDCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCDCView ��ӡ


void CMFCDCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCDCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCDCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCDCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CMFCDCView ���

#ifdef _DEBUG
void CMFCDCView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDCDoc* CMFCDCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDCDoc)));
	return (CMFCDCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDCView ��Ϣ�������


void CMFCDCView::OnCdc()
{
	CDC dc;
	//������ʾ��dc
	dc.CreateDC( TEXT("DISPLAY"),NULL,NULL,NULL );
	//������
	dc.Rectangle( 50, 50, 100, 100 );

	//ɾ��dc
	dc.DeleteDC( );
}


void CMFCDCView::OnCclientdc()
{
	//�ͻ���DC
	/*CClientDC dc(this);
	dc.Rectangle(50, 50, 100, 100);*/

	//ʹ��CWnd�ṩ��GetDC
	//��ȡ�ͻ���DC
	CDC* pDC = GetDC( );
	pDC->Rectangle(50,50,100,100);
	ReleaseDC( pDC );
}


void CMFCDCView::OnCwindowdc()
{
	//����DC
	CWindowDC dc(this);
	dc.Rectangle(50, 50, 100, 100);
}


void CMFCDCView::OnCmetafiledc()
{
	CMetaFileDC dc;
	//����DC
	dc.Create(TEXT("D:\\meta.dat"));
	dc.FillSolidRect(100, 100, 150, 150, RGB(0, 0, 255));

	//�ر�DC�������metafile���
	HMETAFILE hFile = dc.Close( );

	//�����ͻ�DC����ʾmetafile
	CClientDC dcClient(this);
	dcClient.PlayMetaFile( hFile );

	//ɾ��metafile�ļ����
	DeleteMetaFile( hFile );
}


void CMFCDCView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
	dc.FillSolidRect(0,0,50,50, RGB(0,255,0));
}
