
// AutoExe1Doc.cpp : CAutoExe1Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "AutoExe1.h"
#endif

#include "AutoExe1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAutoExe1Doc

IMPLEMENT_DYNCREATE(CAutoExe1Doc, CDocument)

BEGIN_MESSAGE_MAP(CAutoExe1Doc, CDocument)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAutoExe1Doc, CDocument)
	DISP_FUNCTION_ID(CAutoExe1Doc, "SetVisible", dispidSetVisible, SetVisible, VT_EMPTY, VTS_I2)
	DISP_FUNCTION_ID(CAutoExe1Doc, "TypeText", dispidTypeText, TypeText, VT_EMPTY, VTS_BSTR)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_IAutoExe1 ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {ED925030-AE8A-4FEC-B775-EFFA64A325CF}
static const IID IID_IAutoExe1 =
{ 0xED925030, 0xAE8A, 0x4FEC, { 0xB7, 0x75, 0xEF, 0xFA, 0x64, 0xA3, 0x25, 0xCF } };

BEGIN_INTERFACE_MAP(CAutoExe1Doc, CDocument)
	INTERFACE_PART(CAutoExe1Doc, IID_IAutoExe1, Dispatch)
END_INTERFACE_MAP()


// CAutoExe1Doc ����/����

CAutoExe1Doc::CAutoExe1Doc()
{
	// TODO: �ڴ����һ���Թ������

	EnableAutomation();

	AfxOleLockApp();
}

CAutoExe1Doc::~CAutoExe1Doc()
{
	AfxOleUnlockApp();
}

BOOL CAutoExe1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CAutoExe1Doc ���л�

void CAutoExe1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CAutoExe1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CAutoExe1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CAutoExe1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CAutoExe1Doc ���

#ifdef _DEBUG
void CAutoExe1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAutoExe1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CAutoExe1Doc ����


void CAutoExe1Doc::SetVisible(SHORT bShow)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	AfxGetMainWnd()->ShowWindow(SW_SHOWNORMAL);
}


void CAutoExe1Doc::TypeText(LPCTSTR pszText)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	((CFrameWnd*)AfxGetMainWnd())->GetActiveView()->SetWindowTextW(pszText);
}
