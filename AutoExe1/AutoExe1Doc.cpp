
// AutoExe1Doc.cpp : CAutoExe1Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// 注意: 我们添加了对 IID_IAutoExe1 的支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {ED925030-AE8A-4FEC-B775-EFFA64A325CF}
static const IID IID_IAutoExe1 =
{ 0xED925030, 0xAE8A, 0x4FEC, { 0xB7, 0x75, 0xEF, 0xFA, 0x64, 0xA3, 0x25, 0xCF } };

BEGIN_INTERFACE_MAP(CAutoExe1Doc, CDocument)
	INTERFACE_PART(CAutoExe1Doc, IID_IAutoExe1, Dispatch)
END_INTERFACE_MAP()


// CAutoExe1Doc 构造/析构

CAutoExe1Doc::CAutoExe1Doc()
{
	// TODO: 在此添加一次性构造代码

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

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CAutoExe1Doc 序列化

void CAutoExe1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CAutoExe1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CAutoExe1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CAutoExe1Doc 诊断

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


// CAutoExe1Doc 命令


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
