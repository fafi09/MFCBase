// PenPage.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCGDI.h"
#include "PenPage.h"
#include "afxdialogex.h"


// CPenPage 对话框

IMPLEMENT_DYNAMIC(CPenPage, CPropertyPage)

CPenPage::CPenPage()
	: CPropertyPage(CPenPage::IDD)
{

	//  m_nPenWidth = _T("");
	m_nPenWidth = 0;
}

CPenPage::~CPenPage()
{
}

void CPenPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_WIDTH, m_nPenWidth);
	DDX_Text(pDX, IDC_EDIT_WIDTH, m_nPenWidth);
	DDV_MinMaxInt(pDX, m_nPenWidth, 1, 10);
}


BEGIN_MESSAGE_MAP(CPenPage, CPropertyPage)
	ON_EN_CHANGE(IDC_EDIT_WIDTH, &CPenPage::OnChangeEditWidth)
END_MESSAGE_MAP()


// CPenPage 消息处理程序


void CPenPage::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//AfxMessageBox(TEXT("penpage ok"));
	UpdateData(TRUE);

	CPropertyPage::OnOK();
}


void CPenPage::OnChangeEditWidth()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CPropertyPage::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	//使apply按钮生效
	SetModified(TRUE);
}


BOOL CPenPage::OnSetActive()
{
	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
	pSheet->SetWizardButtons(PSWIZB_NEXT);

	return CPropertyPage::OnSetActive();
}


LRESULT CPenPage::OnWizardNext()
{
	
	AfxMessageBox(TEXT("CPenPage::OnWizardNext"));
	return CPropertyPage::OnWizardNext();
}


BOOL CPenPage::OnWizardFinish()
{
	
	AfxMessageBox(TEXT("CPenPage::OnWizardFinish"));
	return CPropertyPage::OnWizardFinish();
}
