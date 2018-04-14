#pragma once
#include "stdafx.h"
#include "PenPage.h"
#include "BrushPage.h"

// CSettingSheet

class CSettingSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSettingSheet)

public:
	CSettingSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSettingSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSettingSheet(CContext* pContext);
	virtual ~CSettingSheet();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CPenPage m_penPage;
	CBrushPage m_brushPage;
	CContext* m_pContext;
	void Setting(void);
	void SettingWizard(void);
};


