// ButtonXp.cpp : 实现文件
//

#include "stdafx.h"
#include "ButtonXp.h"


// CButtonXp

IMPLEMENT_DYNAMIC(CButtonXp, CButton)

CButtonXp::CButtonXp()
{

}

CButtonXp::~CButtonXp()
{
}


BEGIN_MESSAGE_MAP(CButtonXp, CButton)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CButtonXp 消息处理程序




void CButtonXp::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类

	CButton::PreSubclassWindow();

	ModifyStyle(NULL, BS_OWNERDRAW);
}


void CButtonXp::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	if(m_bMouseOver == TRUE)
	{
		if(lpDrawItemStruct->itemState & ODS_SELECTED)
		{
			dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(255,255,255));
		}
		else
		{
			dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(255,255,0));
		}
	}
	else
	{
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(155,155,0));
	}
	

	dc.Detach();
	
}


void CButtonXp::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_bMouseOver == FALSE)
	{
		m_bMouseOver = TRUE;
		Invalidate(FALSE);
	}

	//触发鼠标离开消息
	TRACKMOUSEEVENT EventTrack;
	EventTrack.cbSize = sizeof(TRACKMOUSEEVENT);
	EventTrack.dwFlags = TME_LEAVE;
	EventTrack.hwndTrack = m_hWnd;
	EventTrack.dwHoverTime = HOVER_DEFAULT;

	_TrackMouseEvent(&EventTrack);

	CButton::OnMouseMove(nFlags, point);
}


void CButtonXp::OnMouseLeave()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_bMouseOver = FALSE;
	Invalidate(FALSE);
	CButton::OnMouseLeave();
}
