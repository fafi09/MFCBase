// HollowBtn1Ctrl.cpp : CHollowBtn1Ctrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "HollowBtn1.h"
#include "HollowBtn1Ctrl.h"
#include "HollowBtn1PropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CHollowBtn1Ctrl, COleControl)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CHollowBtn1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// ����ӳ��

BEGIN_DISPATCH_MAP(CHollowBtn1Ctrl, COleControl)
	DISP_FUNCTION_ID(CHollowBtn1Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// �¼�ӳ��

BEGIN_EVENT_MAP(CHollowBtn1Ctrl, COleControl)
	EVENT_STOCK_CLICK()
END_EVENT_MAP()



// ����ҳ

// TODO: ����Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CHollowBtn1Ctrl, 1)
	PROPPAGEID(CHollowBtn1PropPage::guid)
END_PROPPAGEIDS(CHollowBtn1Ctrl)



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CHollowBtn1Ctrl, "HOLLOWBTN1.HollowBtn1Ctrl.1",
	0xc304fc76, 0xc811, 0x4745, 0xbd, 0x11, 0xb8, 0x9e, 0x99, 0x96, 0x90, 0xeb)



// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CHollowBtn1Ctrl, _tlid, _wVerMajor, _wVerMinor)



// �ӿ� ID

const IID IID_DHollowBtn1 = { 0x661B853F, 0x8E12, 0x4F9E, { 0xA3, 0x69, 0x1B, 0xAF, 0x99, 0xCC, 0x53, 0x26 } };
const IID IID_DHollowBtn1Events = { 0x232480A8, 0xC14C, 0x44DA, { 0x99, 0xE9, 0x6, 0x6A, 0xA2, 0xDF, 0x41, 0x5E } };


// �ؼ�������Ϣ

static const DWORD _dwHollowBtn1OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CHollowBtn1Ctrl, IDS_HOLLOWBTN1, _dwHollowBtn1OleMisc)



// CHollowBtn1Ctrl::CHollowBtn1CtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CHollowBtn1Ctrl ��ϵͳע�����

BOOL CHollowBtn1Ctrl::CHollowBtn1CtrlFactory::UpdateRegistry(BOOL bRegister)
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



// CHollowBtn1Ctrl::CHollowBtn1Ctrl - ���캯��

CHollowBtn1Ctrl::CHollowBtn1Ctrl()
{
	InitializeIIDs(&IID_DHollowBtn1, &IID_DHollowBtn1Events);
	// TODO: �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}



// CHollowBtn1Ctrl::~CHollowBtn1Ctrl - ��������

CHollowBtn1Ctrl::~CHollowBtn1Ctrl()
{
	// TODO: �ڴ�����ؼ���ʵ�����ݡ�
}



// CHollowBtn1Ctrl::OnDraw - ��ͼ����

void CHollowBtn1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: �����Լ��Ļ�ͼ�����滻����Ĵ��롣
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

	//�����Կͻ�������ƫ��
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
	//		//��ȡÿһ�����ص���ɫ
	//		COLORREF nColor = dc.GetPixel(nX,nY);
	//		//�ж���ɫ�Ƿ�Ϊ����ɫ
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



// CHollowBtn1Ctrl::DoPropExchange - �־���֧��

void CHollowBtn1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}



// CHollowBtn1Ctrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CHollowBtn1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO: �ڴ��������������ؼ�״̬��
}



// CHollowBtn1Ctrl::AboutBox - ���û���ʾ�����ڡ���

void CHollowBtn1Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_HOLLOWBTN1);
	dlgAbout.DoModal();
}



// CHollowBtn1Ctrl ��Ϣ�������


void CHollowBtn1Ctrl::SetBmpRgn(int nID)
{
	CBitmap bitmap;
	bitmap.LoadBitmapW(nID);

	CClientDC dc(this);

	CDC bmpDC;
	bmpDC.CreateCompatibleDC(&dc);

	CBitmap* OldBitMap = bmpDC.SelectObject(&bitmap);

	//��������
	CRect rcWnd;
	GetWindowRect(&rcWnd);

	CRgn rgnWnd;
	rgnWnd.CreateRectRgn(0,0,rcWnd.Width(), rcWnd.Height());

	for(int nX = 0; nX < 77; nX++)
	{
		for(int nY = 0; nY < 77; nY++)
		{
			//��ȡÿһ�����ص���ɫ
			COLORREF nColor = bmpDC.GetPixel(nX,nY);
			//�ж���ɫ�Ƿ�Ϊ����ɫ
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

	// TODO:  �ڴ������ר�õĴ�������
	SetBmpRgn(IDB_BITMAP1);
	return 0;
}


void CHollowBtn1Ctrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	SetBmpRgn(IDB_BITMAP1);
}


void CHollowBtn1Ctrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC pdc(this);
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP2);

	CDC dc;
	dc.CreateCompatibleDC(&pdc);

	CBitmap* oldBitMap = dc.SelectObject(&bitmap);

	BITMAP hBitmap;
	bitmap.GetBitmap(&hBitmap);

	/*pdc->BitBlt(0,0,hBitmap.bmWidth,hBitmap.bmHeight, &dc, 0, 0, SRCCOPY);*/

	//�����Կͻ�������ƫ��
	CRect rcWnd ;
	GetWindowRect(&rcWnd);
	ScreenToClient(&rcWnd);

	pdc.BitBlt(rcWnd.left, rcWnd.top, hBitmap.bmWidth,hBitmap.bmHeight, &dc, 0, 0, SRCCOPY);

	dc.SelectObject(oldBitMap);

	Invalidate(FALSE);
	COleControl::OnLButtonDown(nFlags, point);
}
