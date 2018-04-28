
// AutoExe1View.cpp : CAutoExe1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "AutoExe1.h"
#endif

#include "AutoExe1Doc.h"
#include "AutoExe1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAutoExe1View

IMPLEMENT_DYNCREATE(CAutoExe1View, CView)

BEGIN_MESSAGE_MAP(CAutoExe1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAutoExe1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CAutoExe1View ����/����

CAutoExe1View::CAutoExe1View()
{
	// TODO: �ڴ˴���ӹ������

}

CAutoExe1View::~CAutoExe1View()
{
}

BOOL CAutoExe1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CAutoExe1View ����

void CAutoExe1View::OnDraw(CDC* /*pDC*/)
{
	CAutoExe1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CAutoExe1View ��ӡ


void CAutoExe1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CAutoExe1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CAutoExe1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CAutoExe1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CAutoExe1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAutoExe1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAutoExe1View ���

#ifdef _DEBUG
void CAutoExe1View::AssertValid() const
{
	CView::AssertValid();
}

void CAutoExe1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAutoExe1Doc* CAutoExe1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoExe1Doc)));
	return (CAutoExe1Doc*)m_pDocument;
}
#endif //_DEBUG


// CAutoExe1View ��Ϣ�������
