// HollowBtn1Ctrl.cpp : CHollowBtn1Ctrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "HollowBtn1.h"
#include "HollowBtn1Ctrl.h"
#include "HollowBtn1PropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CHollowBtn1Ctrl, COleControl)



// 消息映射

BEGIN_MESSAGE_MAP(CHollowBtn1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// 调度映射

BEGIN_DISPATCH_MAP(CHollowBtn1Ctrl, COleControl)
	DISP_FUNCTION_ID(CHollowBtn1Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// 事件映射

BEGIN_EVENT_MAP(CHollowBtn1Ctrl, COleControl)
	EVENT_STOCK_CLICK()
END_EVENT_MAP()



// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CHollowBtn1Ctrl, 1)
	PROPPAGEID(CHollowBtn1PropPage::guid)
END_PROPPAGEIDS(CHollowBtn1Ctrl)



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CHollowBtn1Ctrl, "HOLLOWBTN1.HollowBtn1Ctrl.1",
	0xc304fc76, 0xc811, 0x4745, 0xbd, 0x11, 0xb8, 0x9e, 0x99, 0x96, 0x90, 0xeb)



// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CHollowBtn1Ctrl, _tlid, _wVerMajor, _wVerMinor)



// 接口 ID

const IID IID_DHollowBtn1 = { 0x661B853F, 0x8E12, 0x4F9E, { 0xA3, 0x69, 0x1B, 0xAF, 0x99, 0xCC, 0x53, 0x26 } };
const IID IID_DHollowBtn1Events = { 0x232480A8, 0xC14C, 0x44DA, { 0x99, 0xE9, 0x6, 0x6A, 0xA2, 0xDF, 0x41, 0x5E } };


// 控件类型信息

static const DWORD _dwHollowBtn1OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CHollowBtn1Ctrl, IDS_HOLLOWBTN1, _dwHollowBtn1OleMisc)



// CHollowBtn1Ctrl::CHollowBtn1CtrlFactory::UpdateRegistry -
// 添加或移除 CHollowBtn1Ctrl 的系统注册表项

BOOL CHollowBtn1Ctrl::CHollowBtn1CtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_HOLLOWBTN1,
			IDB_HOLLOWBTN1,
			afxRegApartmentThreading,
			_dwHollowBtn1OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CHollowBtn1Ctrl::CHollowBtn1Ctrl - 构造函数

CHollowBtn1Ctrl::CHollowBtn1Ctrl()
{
	InitializeIIDs(&IID_DHollowBtn1, &IID_DHollowBtn1Events);
	// TODO: 在此初始化控件的实例数据。
}



// CHollowBtn1Ctrl::~CHollowBtn1Ctrl - 析构函数

CHollowBtn1Ctrl::~CHollowBtn1Ctrl()
{
	// TODO: 在此清理控件的实例数据。
}



// CHollowBtn1Ctrl::OnDraw - 绘图函数

void CHollowBtn1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: 用您自己的绘图代码替换下面的代码。
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);

	CDC dc;
	dc.CreateCompatibleDC(pdc);

	CBitmap* oldBitMap = dc.SelectObject(&bitmap);

	BITMAP hBitmap;
	bitmap.GetBitmap(&hBitmap);

	/*pdc->BitBlt(0,0,hBitmap.bmWidth,hBitmap.bmHeight, &dc, 0, 0, SRCCOPY);*/

	//窗户对客户区坐标偏移
	CRect rcWnd = rcBounds;
	if(::IsWindow(m_hWnd))
	{
	GetWindowRect(&rcWnd);
	ScreenToClient(&rcWnd);
	}
	pdc->BitBlt(rcWnd.left, rcWnd.top, hBitmap.bmWidth,hBitmap.bmHeight, &dc, 0, 0, SRCCOPY);

	//CRect rcWnd;
	//GetWindowRect(&rcWnd);

	//CRgn rgnWnd;
	//rgnWnd.CreateRectRgn(0,0,rcWnd.Width(), rcWnd.Height());

	//for(int nX = 0; nX < 77; nX++)
	//{
	//	for(int nY = 0; nY < 77; nY++)
	//	{
	//		//获取每一个像素的颜色
	//		COLORREF nColor = dc.GetPixel(nX,nY);
	//		//判断颜色是否为屏蔽色
	//		if(nColor == RGB(255,255,255))
	//		{
	//			CRgn rgnRect;
	//			rgnRect.CreateRectRgn(nX+90, nY+90, nX+91, nY+91);
	//			rgnWnd.CombineRgn(&rgnWnd, &rgnRect, RGN_XOR);
	//		}
	//	}
	//}

	//SetWindowRgn(rgnWnd, TRUE);

	dc.SelectObject(oldBitMap);
}



// CHollowBtn1Ctrl::DoPropExchange - 持久性支持

void CHollowBtn1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}



// CHollowBtn1Ctrl::OnResetState - 将控件重置为默认状态

void CHollowBtn1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}



// CHollowBtn1Ctrl::AboutBox - 向用户显示“关于”框

void CHollowBtn1Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_HOLLOWBTN1);
	dlgAbout.DoModal();
}



// CHollowBtn1Ctrl 消息处理程序


void CHollowBtn1Ctrl::SetBmpRgn(int nID)
{
	CBitmap bitmap;
	bitmap.LoadBitmapW(nID);

	CClientDC dc(this);

	CDC bmpDC;
	bmpDC.CreateCompatibleDC(&dc);

	CBitmap* OldBitMap = bmpDC.SelectObject(&bitmap);

	//创建区域
	CRect rcWnd;
	GetWindowRect(&rcWnd);

	CRgn rgnWnd;
	rgnWnd.CreateRectRgn(0,0,rcWnd.Width(), rcWnd.Height());

	for(int nX = 0; nX < 77; nX++)
	{
		for(int nY = 0; nY < 77; nY++)
		{
			//获取每一个像素的颜色
			COLORREF nColor = bmpDC.GetPixel(nX,nY);
			//判断颜色是否为屏蔽色
			if(nColor == RGB(255,255,255))
			{
				CRgn rgnRect;
				rgnRect.CreateRectRgn(nX+90, nY+90, nX+91, nY+91);
				//rgnRect.CreateRectRgn(nX, nY, nX+1, nY+1);
				rgnWnd.CombineRgn(&rgnWnd, &rgnRect, RGN_XOR);
			}
		}
	}

	SetWindowRgn(rgnWnd, TRUE);



	bmpDC.SelectObject(OldBitMap);
}


int CHollowBtn1Ctrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetBmpRgn(IDB_BITMAP1);
	return 0;
}


void CHollowBtn1Ctrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	SetBmpRgn(IDB_BITMAP1);
}


void CHollowBtn1Ctrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC pdc(this);
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP2);

	CDC dc;
	dc.CreateCompatibleDC(&pdc);

	CBitmap* oldBitMap = dc.SelectObject(&bitmap);

	BITMAP hBitmap;
	bitmap.GetBitmap(&hBitmap);

	/*pdc->BitBlt(0,0,hBitmap.bmWidth,hBitmap.bmHeight, &dc, 0, 0, SRCCOPY);*/

	//窗户对客户区坐标偏移
	CRect rcWnd ;
	GetWindowRect(&rcWnd);
	ScreenToClient(&rcWnd);

	pdc.BitBlt(rcWnd.left, rcWnd.top, hBitmap.bmWidth,hBitmap.bmHeight, &dc, 0, 0, SRCCOPY);

	dc.SelectObject(oldBitMap);

	Invalidate(FALSE);
	COleControl::OnLButtonDown(nFlags, point);
}
