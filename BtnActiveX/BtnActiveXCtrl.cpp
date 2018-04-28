// BtnActiveXCtrl.cpp : CBtnActiveXCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "BtnActiveX.h"
#include "BtnActiveXCtrl.h"
#include "BtnActiveXPropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CBtnActiveXCtrl, COleControl)



// 消息映射

BEGIN_MESSAGE_MAP(CBtnActiveXCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CBtnActiveXCtrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// 调度映射

BEGIN_DISPATCH_MAP(CBtnActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CBtnActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_NOTIFY_ID(CBtnActiveXCtrl, "Name", dispidName, m_Name, OnNameChanged, VT_BSTR)
	DISP_FUNCTION_ID(CBtnActiveXCtrl, "SetButtonName", dispidSetButtonName, SetButtonName, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION_ID(CBtnActiveXCtrl, "MyClick", dispidMyClick, MyClick, VT_EMPTY, VTS_NONE)
	DISP_STOCKFUNC_DOCLICK()
END_DISPATCH_MAP()



// 事件映射

BEGIN_EVENT_MAP(CBtnActiveXCtrl, COleControl)
	EVENT_STOCK_CLICK()
	EVENT_CUSTOM_ID("MyClick1", eventidMyClick1, MyClick1, VTS_NONE)
	EVENT_CUSTOM_ID("MyClick2", eventidMyClick2, FireClick, VTS_NONE)
END_EVENT_MAP()



// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CBtnActiveXCtrl, 1)
	PROPPAGEID(CBtnActiveXPropPage::guid)
END_PROPPAGEIDS(CBtnActiveXCtrl)



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CBtnActiveXCtrl, "BTNACTIVEX.BtnActiveXCtrl.1",
	0xa0a55f2e, 0x2c98, 0x4d8b, 0x8e, 0x29, 0x70, 0xa, 0x30, 0x3d, 0x71, 0xb7)



// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CBtnActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)



// 接口 ID

const IID IID_DBtnActiveX = { 0x84AADE30, 0x6172, 0x4082, { 0x9B, 0xDE, 0x81, 0xDF, 0x5A, 0x35, 0x6D, 0x5 } };
const IID IID_DBtnActiveXEvents = { 0xEDA4C9AC, 0x6883, 0x4D73, { 0x82, 0xD8, 0xC5, 0x96, 0xB5, 0x9A, 0x82, 0x32 } };


// 控件类型信息

static const DWORD _dwBtnActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CBtnActiveXCtrl, IDS_BTNACTIVEX, _dwBtnActiveXOleMisc)



// CBtnActiveXCtrl::CBtnActiveXCtrlFactory::UpdateRegistry -
// 添加或移除 CBtnActiveXCtrl 的系统注册表项

BOOL CBtnActiveXCtrl::CBtnActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_BTNACTIVEX,
			IDB_BTNACTIVEX,
			afxRegApartmentThreading,
			_dwBtnActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CBtnActiveXCtrl::CBtnActiveXCtrl - 构造函数

CBtnActiveXCtrl::CBtnActiveXCtrl()
	: m_strButtonName(_T(""))
{
	InitializeIIDs(&IID_DBtnActiveX, &IID_DBtnActiveXEvents);
	// TODO: 在此初始化控件的实例数据。
}



// CBtnActiveXCtrl::~CBtnActiveXCtrl - 析构函数

CBtnActiveXCtrl::~CBtnActiveXCtrl()
{
	// TODO: 在此清理控件的实例数据。
}



// CBtnActiveXCtrl::OnDraw - 绘图函数

void CBtnActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	DoSuperclassPaint(pdc, rcBounds);
}



// CBtnActiveXCtrl::DoPropExchange - 持久性支持

void CBtnActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
	PX_String(pPX,_T("Name"),m_Name,_T(""));
}



// CBtnActiveXCtrl::OnResetState - 将控件重置为默认状态

void CBtnActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}



// CBtnActiveXCtrl::AboutBox - 向用户显示“关于”框

void CBtnActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_BTNACTIVEX);
	dlgAbout.DoModal();
}



// CBtnActiveXCtrl::PreCreateWindow - 修改 CreateWindowEx 的参数

BOOL CBtnActiveXCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	return COleControl::PreCreateWindow(cs);
}



// CBtnActiveXCtrl::IsSubclassedControl - 这是一个子类控件

BOOL CBtnActiveXCtrl::IsSubclassedControl()
{
	return TRUE;
}



// CBtnActiveXCtrl::OnOcmCommand - 处理命令消息

LRESULT CBtnActiveXCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO: 在此接通 wNotifyCode。

	return 0;
}



// CBtnActiveXCtrl 消息处理程序


void CBtnActiveXCtrl::OnNameChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	SetWindowTextW(m_Name);

	SetModifiedFlag();
}


void CBtnActiveXCtrl::SetButtonName(LPCTSTR pszName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_strButtonName = pszName;
	SetWindowTextW(pszName);
	
}


void CBtnActiveXCtrl::MyClick(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
}


int CBtnActiveXCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetWindowTextW(m_Name);

	return 0;
}


void CBtnActiveXCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	FireClick();

	COleControl::OnLButtonDown(nFlags, point);
}
