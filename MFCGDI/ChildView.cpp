
// ChildView.cpp : CChildView ���ʵ��
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



// CChildView ��Ϣ�������

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
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	
	// TODO: �ڴ˴������Ϣ����������
	
	// ��ҪΪ������Ϣ������ CWnd::OnPaint()
}



void CChildView::OnFont()
{
	CFont font;
	font.CreatePointFont(600, TEXT("����"));

	CClientDC dc(this);
	
	CFont* pOldFont = dc.SelectObject(&font);

	dc.TextOutW(120, 120, TEXT("����"));

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
	//CPen, CBrush��Ϊһ����ʼ����������ʼ��
	//��һ��Ϊ������ʼ��,����Ϊһ����ʼ��,
	//������ʼ����һ����ʼ������ȫ
	//һ����ʼ����ҪУ������ĺϷ��ԣ�����
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
	//���ӵ�λͼ����
	CBitmap bmp;
	bmp.Attach(hBitmap);

	//��ÿͻ���dc
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

	//������ɫ��
	CPalette palette;
	palette.CreatePalette(pLogPalette);
	free( pLogPalette );

	CClientDC dc(this);

	CPalette* pOldPalette = dc.SelectPalette(&palette, FALSE);

	//���ص�ɫ��
	dc.RealizePalette();

	//��ͼ
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
	//��������
	rgnLeft.CreateEllipticRgn(100, 100, 200, 200);
	rgnRight.CreateEllipticRgn( 400, 100, 500, 200 );
	rgnMid.CreateRectRgn(150, 130, 450, 170 );

	//����ϲ�
	rgnMid.CombineRgn( &rgnMid, &rgnLeft, RGN_OR);
	rgnMid.CombineRgn( &rgnMid, &rgnRight, RGN_OR);
	/*rgnMid.CombineRgn( &rgnMid, &rgnLeft, RGN_XOR);
	rgnMid.CombineRgn( &rgnMid, &rgnRight, RGN_XOR);*/

	//��������
	CClientDC dc(this);

	CBrush brush1(HS_DIAGCROSS, RGB( 100, 100, 100 ));
	CBrush brush2( RGB( 100, 100, 100 ));

	//�������
	dc.FillRgn( &rgnMid, &brush1);
	//�������⻭�߿�
	dc.FrameRgn(&rgnMid, &brush2, 2, 2);
}
