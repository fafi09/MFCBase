#pragma once


// CButtonXp

class AFX_EXT_CLASS CButtonXp : public CButton
{
	DECLARE_DYNAMIC(CButtonXp)

public:
	CButtonXp();
	virtual ~CButtonXp();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	BOOL m_bMouseOver;
};


