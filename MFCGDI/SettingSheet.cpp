// SettingSheet.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCGDI.h"
#include "SettingSheet.h"


// CSettingSheet

IMPLEMENT_DYNAMIC(CSettingSheet, CPropertySheet)

CSettingSheet::CSettingSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CSettingSheet::CSettingSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CSettingSheet::CSettingSheet(CContext* pContext)
{
	m_pContext = pContext;
}

CSettingSheet::~CSettingSheet()
{
}


BEGIN_MESSAGE_MAP(CSettingSheet, CPropertySheet)
END_MESSAGE_MAP()


// CSettingSheet 消息处理程序


void CSettingSheet::Setting(void)
{
	AddPage(&m_penPage);
	AddPage(&m_brushPage);

	if(IDOK != DoModal())
	{
		return;
	}
}


void CSettingSheet::SettingWizard(void)
{
	AddPage(&m_penPage);
	AddPage(&m_brushPage);

	SetWizardMode();

	if(ID_WIZFINISH != DoModal())
	{
		return;
	}
}
