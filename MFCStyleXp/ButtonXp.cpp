// ButtonXp.cpp : ʵ���ļ�
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



// CButtonXp ��Ϣ�������




void CButtonXp::PreSubclassWindow()
{
	// TODO: �ڴ����ר�ô����/����û���

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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(m_bMouseOver == FALSE)
	{
		m_bMouseOver = TRUE;
		Invalidate(FALSE);
	}

	//��������뿪��Ϣ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bMouseOver = FALSE;
	Invalidate(FALSE);
	CButton::OnMouseLeave();
}
