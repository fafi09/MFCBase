// HollowBtn1PropPage.cpp : CHollowBtn1PropPage 属性页类的实现。

#include "stdafx.h"
#include "HollowBtn1.h"
#include "HollowBtn1PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CHollowBtn1PropPage, COlePropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CHollowBtn1PropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CHollowBtn1PropPage, "HOLLOWBTN1.HollowBtn1PropPage.1",
	0x424d704c, 0x4b25, 0x4391, 0x9d, 0x1a, 0xa8, 0xcf, 0x18, 0x79, 0x3f, 0x50)



// CHollowBtn1PropPage::CHollowBtn1PropPageFactory::UpdateRegistry -
// 添加或移除 CHollowBtn1PropPage 的系统注册表项

BOOL CHollowBtn1PropPage::CHollowBtn1PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_HOLLOWBTN1_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CHollowBtn1PropPage::CHollowBtn1PropPage - 构造函数

CHollowBtn1PropPage::CHollowBtn1PropPage() :
	COlePropertyPage(IDD, IDS_HOLLOWBTN1_PPG_CAPTION)
{
}



// CHollowBtn1PropPage::DoDataExchange - 在页和属性间移动数据

void CHollowBtn1PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CHollowBtn1PropPage 消息处理程序
