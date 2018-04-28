// BtnActiveXPropPage.cpp : CBtnActiveXPropPage 属性页类的实现。

#include "stdafx.h"
#include "BtnActiveX.h"
#include "BtnActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CBtnActiveXPropPage, COlePropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CBtnActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CBtnActiveXPropPage, "BTNACTIVEX.BtnActiveXPropPage.1",
	0x6425f24a, 0x9a0a, 0x498d, 0x9b, 0xa1, 0xc7, 0x78, 0x64, 0, 0xf0, 0x4e)



// CBtnActiveXPropPage::CBtnActiveXPropPageFactory::UpdateRegistry -
// 添加或移除 CBtnActiveXPropPage 的系统注册表项

BOOL CBtnActiveXPropPage::CBtnActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_BTNACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CBtnActiveXPropPage::CBtnActiveXPropPage - 构造函数

CBtnActiveXPropPage::CBtnActiveXPropPage() :
	COlePropertyPage(IDD, IDS_BTNACTIVEX_PPG_CAPTION)
{
	m_Name = _T("");
	}



// CBtnActiveXPropPage::DoDataExchange - 在页和属性间移动数据

void CBtnActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDP_Text(pDX, IDC_EDIT1, m_Name, _T("Name") );
	DDP_PostProcessing(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_strName);
}



// CBtnActiveXPropPage 消息处理程序
