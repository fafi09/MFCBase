
// EmbWord1View.cpp : CEmbWord1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EmbWord1.h"
#endif

#include "EmbWord1Doc.h"
#include "CntrItem.h"
#include "resource.h"
#include "EmbWord1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEmbWord1View

IMPLEMENT_DYNCREATE(CEmbWord1View, CView)

BEGIN_MESSAGE_MAP(CEmbWord1View, CView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, &CEmbWord1View::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &CEmbWord1View::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &CEmbWord1View::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEmbWord1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TEST, &CEmbWord1View::OnTest)
END_MESSAGE_MAP()

// CEmbWord1View ����/����

CEmbWord1View::CEmbWord1View()
{
	m_pSelection = NULL;
	// TODO: �ڴ˴���ӹ������

}

CEmbWord1View::~CEmbWord1View()
{
}

BOOL CEmbWord1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEmbWord1View ����

void CEmbWord1View::OnDraw(CDC* pDC)
{
	if (!pDC)
		return;

	CEmbWord1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	// TODO: ͬʱ�����ĵ��е����� OLE ��

	// ������λ�û���ѡ���һ��
	//  ʵ���������Ļ��ƴ����Ӧ�Ƴ��˴��롣��λ��
	//  �� CEmbWord1CntrItem ���صľ�����ȫ��Ӧ��
	//  �Ӷ������͵ر༭��Ч����

	// TODO: ���ջ��ƴ�����ɺ��Ƴ��˴��롣
	if (m_pSelection != NULL)
	{
		CSize size;
		CRect rect(10, 10, 210, 210);
		
		if (m_pSelection->GetExtent(&size, m_pSelection->m_nDrawAspect))
		{
			pDC->HIMETRICtoLP(&size);
			rect.right = size.cx + 10;
			rect.bottom = size.cy + 10;
		}
		m_pSelection->Draw(pDC, rect);
	}
}

void CEmbWord1View::OnInitialUpdate()
{
	CView::OnInitialUpdate();


	// TODO: д������ѡ��ģʽ����֮���Ƴ��˴���
	m_pSelection = NULL;    // ��ʼ����ѡ����
	EmWord();
}


// CEmbWord1View ��ӡ


void CEmbWord1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CEmbWord1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEmbWord1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEmbWord1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CEmbWord1View::OnDestroy()
{
	// ����ʱͣ�ô������
	// ʹ�ò����ͼʱ�ǳ���Ҫ 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CView::OnDestroy();
}



// OLE �ͻ���֧�ֺ�����

BOOL CEmbWord1View::IsSelected(const CObject* pDocItem) const
{
	// �����ѡ����ֻ����
	//  CEmbWord1CntrItem ����������ʵ�־��㹻�ˡ���Ҫ��������ѡ����ƣ�
	//  ��Ӧ�滻�˴���ʵ��

	// TODO: ʵ�ֶ���ѡ OLE �ͻ�������в��Եĺ���

	return pDocItem == m_pSelection;
}

void CEmbWord1View::OnInsertObject()
{
	// ���ñ�׼�ġ�������󡱶Ի����Ի���й�
	//  �� CEmbWord1CntrItem �������Ϣ
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CEmbWord1CntrItem* pItem = NULL;
	TRY
	{
		// ��������ĵ������ӵ�����
		CEmbWord1Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CEmbWord1CntrItem(pDoc);
		ASSERT_VALID(pItem);

		// ͨ���Ի������ݳ�ʼ������
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // �κ��쳣�������¸ý��
		ASSERT_VALID(pItem);
		
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);
		// ��Ϊ�����û�������ƣ���Ὣ��ѡ����
		//  ����Ϊ��������һ��

		// TODO: ����ʵ����ѡ���ݣ�ʹ���ʺ�������Ӧ�ó���
		m_pSelection = pItem;   // ����ѡ��������Ϊ��������һ��
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// �������������ṩ�˱�׼����
//  �û�������ȡ���͵ر༭�Ự���˴���
//  ����(�����Ƿ�����)������ͣ��
void CEmbWord1View::OnCancelEditCntr()
{
	// �رմ���ͼ�е��κξ͵ػ�
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// �ھ͵ر༭һ������ʱ��������Ҫ�� OnSetFocus �� OnSize 
//  �������⴦��
void CEmbWord1View::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// ��������ͬһ��ͼ�У�����Ҫ���������õ�����
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // ��Ҫ���û���
			return;
		}
	}

	CView::OnSetFocus(pOldWnd);
}

void CEmbWord1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

void CEmbWord1View::OnFilePrint()
{
	//Ĭ������£�Ҫ���ĵ�ʹ�� IOleCommandTarget ��ӡ����
	//�������Ҫ����Ϊ��
	//���Ƴ��� COleDocObjectItem::DoDefaultPrinting ���á�
	//�������ĳ��ԭ�����ʧ�ܣ��򽫳���ʹ�� IPrint �ӿڴ�ӡ
	//���ĵ�����
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != NULL); 
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;
	
	CView::OnFilePrint();

}


void CEmbWord1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CEmbWord1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CEmbWord1View ���

#ifdef _DEBUG
void CEmbWord1View::AssertValid() const
{
	CView::AssertValid();
}

void CEmbWord1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEmbWord1Doc* CEmbWord1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEmbWord1Doc)));
	return (CEmbWord1Doc*)m_pDocument;
}
#endif //_DEBUG

void CEmbWord1View::EmWord()
{
	//����һ������
	CEmbWord1CntrItem *pItem=NULL;
	CEmbWord1Doc *pDoc=GetDocument();
	pItem=new CEmbWord1CntrItem(pDoc);
	//����Automation������
	CLSID clsid={0};
	CLSIDFromProgID(L"Word.Document",&clsid);
	pItem->CreateNewItem(clsid);
	//��ʾ
	pItem->DoVerb(OLEIVERB_SHOW,this);

	CRect rcClient;
	GetClientRect(&rcClient);
	pItem->SetItemRects(&rcClient);
	m_pSelection=pItem;

}

// CEmbWord1View ��Ϣ�������

#include "CApplication.h"
#include "CDocument0.h"
#include "CSelection.h"

void CEmbWord1View::OnTest()
{
	// TODO: Add your command handler code here
	//��ȡWord.Document�Ľӿ�
	CDocument0 doc=
		m_pSelection->GetDispatch();
	CApplication app=
		doc.get_Application();
	CSelection sel=app.get_Selection();

	//��������
	sel.TypeText(TEXT("hello world"));
}



