// BtnActiveXPropPage.cpp : CBtnActiveXPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "BtnActiveX.h"
#include "BtnActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CBtnActiveXPropPage, COlePropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CBtnActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CBtnActiveXPropPage, "BTNACTIVEX.BtnActiveXPropPage.1",
	0x6425f24a, 0x9a0a, 0x498d, 0x9b, 0xa1, 0xc7, 0x78, 0x64, 0, 0xf0, 0x4e)



// CBtnActiveXPropPage::CBtnActiveXPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CBtnActiveXPropPage ��ϵͳע�����

BOOL CBtnActiveXPropPage::CBtnActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_BTNACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CBtnActiveXPropPage::CBtnActiveXPropPage - ���캯��

CBtnActiveXPropPage::CBtnActiveXPropPage() :
	COlePropertyPage(IDD, IDS_BTNACTIVEX_PPG_CAPTION)
{
	m_Name = _T("");
	}



// CBtnActiveXPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CBtnActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDP_Text(pDX, IDC_EDIT1, m_Name, _T("Name") );
	DDP_PostProcessing(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_strName);
}



// CBtnActiveXPropPage ��Ϣ�������
