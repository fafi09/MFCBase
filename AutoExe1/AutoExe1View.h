
// AutoExe1View.h : CAutoExe1View ��Ľӿ�
//

#pragma once


class CAutoExe1View : public CView
{
protected: // �������л�����
	CAutoExe1View();
	DECLARE_DYNCREATE(CAutoExe1View)

// ����
public:
	CAutoExe1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CAutoExe1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // AutoExe1View.cpp �еĵ��԰汾
inline CAutoExe1Doc* CAutoExe1View::GetDocument() const
   { return reinterpret_cast<CAutoExe1Doc*>(m_pDocument); }
#endif

