#pragma once
class CContext
{
public:
	CContext(void);
	virtual ~CContext(void);
	COLORREF m_nPenColor;
	int      m_nPenWidth;
	COLORREF m_nBrushColor;
};

