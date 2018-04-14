// BrushPage.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCGDI.h"
#include "BrushPage.h"
#include "afxdialogex.h"
#include "SettingSheet.h"
#include <afxwin.h>
// CBrushPage 对话框

IMPLEMENT_DYNAMIC(CBrushPage, CPropertyPage)

CBrushPage::CBrushPage()
	: CPropertyPage(CBrushPage::IDD)
{

}

CBrushPage::~CBrushPage()
{
}

void CBrushPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBrushPage, CPropertyPage)
END_MESSAGE_MAP()


// CBrushPage 消息处理程序


void CBrushPage::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	AfxMessageBox(TEXT("penpage ok"));
	CPropertyPage::OnOK();
	
}


BOOL CBrushPage::OnSetActive()
{
	CSettingSheet* pSheet = (CSettingSheet*)GetParent();
	pSheet->SetWizardButtons(PSWIZB_FINISH | PSWIZB_BACK);
	//pSheet->SetWizardButtons(PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}


LRESULT CBrushPage::OnWizardBack()
{
	
	AfxMessageBox( TEXT("CBrushPage::OnWizardBack") );
	return CPropertyPage::OnWizardBack();
}


BOOL CBrushPage::OnWizardFinish()
{
	AfxMessageBox( TEXT("CBrushPage::OnWizardFinish") );

	return CPropertyPage::OnWizardFinish();
}
