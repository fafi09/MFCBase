
// ChildView.cpp : CChildView 类的实现
//

#include "stdafx.h"
#include "MFCGDI.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FONT, &CChildView::OnFont)
	ON_COMMAND(ID_PEN, &CChildView::OnPen)
	ON_COMMAND(ID_BRUSH, &CChildView::OnBrush)
	ON_COMMAND(ID_BITMAP, &CChildView::OnBitmap)
	ON_COMMAND(ID_BITMAPEX, &CChildView::OnBitmapex)
	ON_COMMAND(ID_PALETTE, &CChildView::OnPalette)
	ON_COMMAND(ID_REGION, &CChildView::OnRegion)
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	
	// 不要为绘制消息而调用 CWnd::OnPaint()
}



void CChildView::OnFont()
{
	CFont font;
	font.CreatePointFont(600, TEXT("宋体"));

	CClientDC dc(this);
	
	CFont* pOldFont = dc.SelectObject(&font);

	dc.TextOutW(120, 120, TEXT("字体"));

	dc.SelectObject( pOldFont );
}


void CChildView::OnPen()
{
	CPen _pen;
	_pen.CreatePen(PS_SOLID, 10, RGB(0, 0, 255));

	CClientDC dc(this);
	CPen* _pOldPen = dc.SelectObject(&_pen);

	dc.Rectangle(10,10,60,60);

	dc.SelectObject(_pOldPen);
}


void CChildView::OnBrush()
{
	//CPen, CBrush分为一步初始化和两步初始化
	//上一个为两步初始化,下面为一步初始化,
	//两步初始化较一步初始化更安全
	//一步初始化需要校验参数的合法性，如下
	try
	{
		CBrush brush( HS_CROSS, RGB( 0, 255, 0 ) );

		CClientDC dc( this );

		CBrush* oldBrush = dc.SelectObject( &brush );

		dc.Rectangle( 60, 60, 110, 110 );

		dc.SelectObject( oldBrush );
	}
	catch (CResourceException* e)
	{
		e->ReportError( );
		e->Delete( );
	}
}


void CChildView::OnBitmap()
{
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDR_MAINFRAME);

	CDC dc;
	CClientDC clientDC(this);

	dc.CreateCompatibleDC(&clientDC);

	CBitmap* pOldBitmap = dc.SelectObject(&bitmap);

	clientDC.BitBlt(400,400, 100, 100, &dc, 0, 0, SRCCOPY);

	dc.SelectObject(pOldBitmap);
}


void CChildView::OnBitmapex()
{
	HBITMAP hBitmap 
		= (HBITMAP)LoadImage(
			NULL, 
			TEXT("D:\\project\\win32\\win32\\wnd\\all\\all\\bg.bmp"),
			IMAGE_BITMAP,0,0,LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	BITMAP  bitmap = {0};
	GetObject(hBitmap, sizeof(bitmap), &bitmap);
	//附加到位图对象
	CBitmap bmp;
	bmp.Attach(hBitmap);

	//获得客户区dc
	CClientDC dc(this);

	CDC bmpDC;
	bmpDC.CreateCompatibleDC(&dc);
	CBitmap* pOldBitmap = bmpDC.SelectObject(&bmp);

	dc.BitBlt(0,0,bitmap.bmWidth,bitmap.bmHeight, &bmpDC, 0, 0, SRCCOPY);

	bmpDC.SelectObject(pOldBitmap);

}


void CChildView::OnPalette()
{
	LOGPALETTE* pLogPalette = NULL;

	int nLen = sizeof(LOGPALETTE) + sizeof(PALETTEENTRY) * 255;

	pLogPalette = (LOGPALETTE*)malloc(nLen);

	pLogPalette->palNumEntries = 256;
	pLogPalette->palVersion = 0x300;

	for(int i = 0; i < 256; i++)
	{
		pLogPalette->palPalEntry[i].peRed = 0;
		pLogPalette->palPalEntry[i].peGreen = 0;
		pLogPalette->palPalEntry[i].peBlue = i;
	}

	//创建调色板
	CPalette palette;
	palette.CreatePalette(pLogPalette);
	free( pLogPalette );

	CClientDC dc(this);

	CPalette* pOldPalette = dc.SelectPalette(&palette, FALSE);

	//加载调色板
	dc.RealizePalette();

	//绘图
	CRect rcClient;
	GetClientRect(&rcClient);

	for(int i = 0; i < 256; i++ )
	{
		int nX1 = 0;
		int nY1 = rcClient.Height() * i / 256;
		int nX2 = rcClient.Width();
		int nY2 = rcClient.Height() * (i + 1) / 256;
		dc.FillSolidRect(nX1, nY1, nX2 - nX1, nY2 - nY1 , PALETTEINDEX(255 - i));
	}


	dc.SelectObject(pOldPalette);
}


void CChildView::OnRegion()
{
	CRgn rgnLeft;
	CRgn rgnMid;
	CRgn rgnRight;
	//创建区域
	rgnLeft.CreateEllipticRgn(100, 100, 200, 200);
	rgnRight.CreateEllipticRgn( 400, 100, 500, 200 );
	rgnMid.CreateRectRgn(150, 130, 450, 170 );

	//区域合并
	rgnMid.CombineRgn( &rgnMid, &rgnLeft, RGN_OR);
	rgnMid.CombineRgn( &rgnMid, &rgnRight, RGN_OR);
	/*rgnMid.CombineRgn( &rgnMid, &rgnLeft, RGN_XOR);
	rgnMid.CombineRgn( &rgnMid, &rgnRight, RGN_XOR);*/

	//绘制区域
	CClientDC dc(this);

	CBrush brush1(HS_DIAGCROSS, RGB( 100, 100, 100 ));
	CBrush brush2( RGB( 100, 100, 100 ));

	//填充区域
	dc.FillRgn( &rgnMid, &brush1);
	//在区域外画边框
	dc.FrameRgn(&rgnMid, &brush2, 2, 2);
}
