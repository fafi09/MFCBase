// BtnActiveXCtrl.cpp : CBtnActiveXCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "BtnActiveX.h"
#include "BtnActiveXCtrl.h"
#include "BtnActiveXPropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CBtnActiveXCtrl, COleControl)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CBtnActiveXCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CBtnActiveXCtrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// ����ӳ��

BEGIN_DISPATCH_MAP(CBtnActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CBtnActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_NOTIFY_ID(CBtnActiveXCtrl, "Name", dispidName, m_Name, OnNameChanged, VT_BSTR)
	DISP_FUNCTION_ID(CBtnActiveXCtrl, "SetButtonName", dispidSetButtonName, SetButtonName, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION_ID(CBtnActiveXCtrl, "MyClick", dispidMyClick, MyClick, VT_EMPTY, VTS_NONE)
	DISP_STOCKFUNC_DOCLICK()
END_DISPATCH_MAP()



// �¼�ӳ��

BEGIN_EVENT_MAP(CBtnActiveXCtrl, COleControl)
	EVENT_STOCK_CLICK()
	EVENT_CUSTOM_ID("MyClick1", eventidMyClick1, MyClick1, VTS_NONE)
	EVENT_CUSTOM_ID("MyClick2", eventidMyClick2, FireClick, VTS_NONE)
END_EVENT_MAP()



// ����ҳ

// TODO: ����Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CBtnActiveXCtrl, 1)
	PROPPAGEID(CBtnActiveXPropPage::guid)
END_PROPPAGEIDS(CBtnActiveXCtrl)



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CBtnActiveXCtrl, "BTNACTIVEX.BtnActiveXCtrl.1",
	0xa0a55f2e, 0x2c98, 0x4d8b, 0x8e, 0x29, 0x70, 0xa, 0x30, 0x3d, 0x71, 0xb7)



// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CBtnActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)



// �ӿ� ID

const IID IID_DBtnActiveX = { 0x84AADE30, 0x6172, 0x4082, { 0x9B, 0xDE, 0x81, 0xDF, 0x5A, 0x35, 0x6D, 0x5 } };
const IID IID_DBtnActiveXEvents = { 0xEDA4C9AC, 0x6883, 0x4D73, { 0x82, 0xD8, 0xC5, 0x96, 0xB5, 0x9A, 0x82, 0x32 } };


// �ؼ�������Ϣ

static const DWORD _dwBtnActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CBtnActiveXCtrl, IDS_BTNACTIVEX, _dwBtnActiveXOleMisc)



// CBtnActiveXCtrl::CBtnActiveXCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CBtnActiveXCtrl ��ϵͳע�����

BOOL CBtnActiveXCtrl::CBtnActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

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



// CBtnActiveXCtrl::CBtnActiveXCtrl - ���캯��

CBtnActiveXCtrl::CBtnActiveXCtrl()
	: m_strButtonName(_T(""))
{
	InitializeIIDs(&IID_DBtnActiveX, &IID_DBtnActiveXEvents);
	// TODO: �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}



// CBtnActiveXCtrl::~CBtnActiveXCtrl - ��������

CBtnActiveXCtrl::~CBtnActiveXCtrl()
{
	// TODO: �ڴ�����ؼ���ʵ�����ݡ�
}



// CBtnActiveXCtrl::OnDraw - ��ͼ����

void CBtnActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	DoSuperclassPaint(pdc, rcBounds);
}



// CBtnActiveXCtrl::DoPropExchange - �־���֧��

void CBtnActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
	PX_String(pPX,_T("Name"),m_Name,_T(""));
}



// CBtnActiveXCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CBtnActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO: �ڴ��������������ؼ�״̬��
}



// CBtnActiveXCtrl::AboutBox - ���û���ʾ�����ڡ���

void CBtnActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_BTNACTIVEX);
	dlgAbout.DoModal();
}



// CBtnActiveXCtrl::PreCreateWindow - �޸� CreateWindowEx �Ĳ���

BOOL CBtnActiveXCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	return COleControl::PreCreateWindow(cs);
}



// CBtnActiveXCtrl::IsSubclassedControl - ����һ������ؼ�

BOOL CBtnActiveXCtrl::IsSubclassedControl()
{
	return TRUE;
}



// CBtnActiveXCtrl::OnOcmCommand - ����������Ϣ

LRESULT CBtnActiveXCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO: �ڴ˽�ͨ wNotifyCode��

	return 0;
}



// CBtnActiveXCtrl ��Ϣ�������


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

	// TODO: �ڴ���ӵ��ȴ���������
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
