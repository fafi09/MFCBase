// PenPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCGDI.h"
#include "PenPage.h"
#include "afxdialogex.h"


// CPenPage �Ի���

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


// CPenPage ��Ϣ�������


void CPenPage::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//AfxMessageBox(TEXT("penpage ok"));
	UpdateData(TRUE);

	CPropertyPage::OnOK();
}


void CPenPage::OnChangeEditWidth()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//ʹapply��ť��Ч
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
