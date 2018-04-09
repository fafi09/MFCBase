
// MFCDCView.h : CMFCDCView ��Ľӿ�
//

#pragma once


class CMFCDCView : public CView
{
protected: // �������л�����
	CMFCDCView();
	DECLARE_DYNCREATE(CMFCDCView)

// ����
public:
	CMFCDCDoc* GetDocument() const;

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
	virtual ~CMFCDCView();
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
public:
	afx_msg void OnCdc();
	afx_msg void OnCclientdc();
	afx_msg void OnCwindowdc();
	afx_msg void OnCmetafiledc();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCDCView.cpp �еĵ��԰汾
inline CMFCDCDoc* CMFCDCView::GetDocument() const
   { return reinterpret_cast<CMFCDCDoc*>(m_pDocument); }
#endif

