
// CntrItem.cpp : CEmbWord1CntrItem 类的实现
//

#include "stdafx.h"
#include "EmbWord1.h"

#include "EmbWord1Doc.h"
#include "EmbWord1View.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEmbWord1CntrItem 的实现

IMPLEMENT_SERIAL(CEmbWord1CntrItem, COleClientItem, 0)

CEmbWord1CntrItem::CEmbWord1CntrItem(CEmbWord1Doc* pContainer)
	: COleClientItem(pContainer)
{
	// TODO: 在此添加一次性构造代码
}

CEmbWord1CntrItem::~CEmbWord1CntrItem()
{
	// TODO: 在此处添加清理代码
}

void CEmbWord1CntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleClientItem::OnChange(nCode, dwParam);

	// 在编辑某项时(就地编辑或完全打开进行编辑)，
	//  该项将就其自身状态的更改
	//  或其内容的可视外观状态的更改发送 OnChange 通知。

	// TODO: 通过调用 UpdateAllViews 使该项无效
	//  (包括适合您的应用程序的提示)

	GetDocument()->UpdateAllViews(NULL);
		// 现在只更新所有视图/无提示
}

BOOL CEmbWord1CntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// 就地激活期间，服务器调用 CEmbWord1CntrItem::OnChangeItemPosition
	//  以更改就地窗口的位置。
	//  这通常是由于服务器
	//  文档中的数据更改而导致范围改变或是
	//  就地调整大小所引起的。
	//
	// 此处的默认设置调用基类，该基类将调用
	//  COleClientItem::SetItemRects 以将该项
	//  移动到新的位置。

	if (!COleClientItem::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: 更新该项的矩形/范围可能存在的任何缓存

	return TRUE;
}

BOOL CEmbWord1CntrItem::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
	CFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CFrameWndEx, pFrameWnd);

	if (pMainFrame != NULL)
	{
		ASSERT_VALID(pMainFrame);
		return pMainFrame->OnShowPanes(bShow);
	}

	return FALSE;
}

void CEmbWord1CntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// 就地激活期间，将调用 CEmbWord1CntrItem::OnGetItemPosition
	//  以决定该项的位置。通常，
	//  该矩形会反映与激活所用视图 
	//  相关项的当前位置。调用 
	//  CEmbWord1CntrItem::GetActiveView 可得到视图。

	// TODO: 返回 rPosition 中的正确矩形(以像素表示)

	CSize size;
	rPosition.SetRectEmpty();
	if (GetExtent(&size, m_nDrawAspect))
	{
		CEmbWord1View* pView = GetActiveView();
		ASSERT_VALID(pView);
		if (!pView)
			return;
		CDC *pDC = pView->GetDC();
		ASSERT(pDC);
		if (!pDC)
			return;
		pDC->HIMETRICtoLP(&size);
		rPosition.SetRect(10, 10, size.cx + 10, size.cy + 10);
	}
	else
		rPosition.SetRect(10, 10, 210, 210);
}

void CEmbWord1CntrItem::OnActivate()
{
    // 每个框架只能有一个就地激活项
    CEmbWord1View* pView = GetActiveView();
    ASSERT_VALID(pView);
	if (!pView)
		return;
    COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
    if (pItem != NULL && pItem != this)
        pItem->Close();
    
    COleClientItem::OnActivate();
}

void CEmbWord1CntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void CEmbWord1CntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// 首先调用基类以读取 COleClientItem 数据。
	// 因为这样会设置从 CEmbWord1CntrItem::GetDocument 返回的 m_pDocument 指针，
	//  所以最好先调用
	//  基类 Serialize。
	COleClientItem::Serialize(ar);

	// 现在存储/检索特定于 CEmbWord1CntrItem 的数据
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CEmbWord1CntrItem 诊断

#ifdef _DEBUG
void CEmbWord1CntrItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void CEmbWord1CntrItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif



IDispatch* CEmbWord1CntrItem::GetDispatch(void)
{
	IDispatch * piDispatch=NULL;
	m_lpObject->QueryInterface(IID_IDispatch,
		(LPVOID*)&piDispatch);

	return piDispatch;
}
