// Math.cpp : 实现文件
//

#include "stdafx.h"
#include "AutoDll1.h"
#include "Math.h"


// CMath

IMPLEMENT_DYNCREATE(CMath, CCmdTarget)


CMath::CMath()
{
	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	
	AfxOleLockApp();
}

CMath::~CMath()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}


void CMath::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CMath, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CMath, CCmdTarget)
	DISP_FUNCTION_ID(CMath, "Sub", dispidSub, Sub, VT_EMPTY, VTS_I4 VTS_I4 VTS_PI4)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IMath 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {AC39E5B6-F623-4066-81DD-438539CABEE0}
static const IID IID_IMath =
{ 0xAC39E5B6, 0xF623, 0x4066, { 0x81, 0xDD, 0x43, 0x85, 0x39, 0xCA, 0xBE, 0xE0 } };

BEGIN_INTERFACE_MAP(CMath, CCmdTarget)
	INTERFACE_PART(CMath, IID_IMath, Dispatch)
END_INTERFACE_MAP()

// {E8DF1F38-70BB-4150-9A32-CB2B15424E95}
IMPLEMENT_OLECREATE_FLAGS(CMath, "AutoDll1.Math", afxRegApartmentThreading, 0xe8df1f38, 0x70bb, 0x4150, 0x9a, 0x32, 0xcb, 0x2b, 0x15, 0x42, 0x4e, 0x95)


// CMath 消息处理程序


void CMath::Add(long nAdd1, long nAdd2, long* pnAdd)
{
	*pnAdd = nAdd1 + nAdd2;
}


void CMath::Sub(LONG nSub1, LONG nSub2, LONG* pnSub)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pnSub = nSub1 - nSub2;
}
