
// EmbWord1View.h : CEmbWord1View ��Ľӿ�
//

#pragma once

class CEmbWord1CntrItem;

class CEmbWord1View : public CView
{
protected: // �������л�����
	CEmbWord1View();
	DECLARE_DYNCREATE(CEmbWord1View)

// ����
public:
	CEmbWord1Doc* GetDocument() const;
	// m_pSelection ����ѡ���ݱ����ڵ�ǰ�� CEmbWord1CntrItem �С�
	// �������Ӧ�ó������ֳ�Ա����������
	//  ��ʾĳ��ѡ�������ڲ����� CEmbWord1CntrItem �Ķ�����
	//  ѡ����һ�����������ṩ����ѡ��
	//  ���Ƶ�Ŀ��ֻ�ǰ���������

	// TODO: ���ʺ�Ӧ�ó����ѡ������滻��ѡ�����
	CEmbWord1CntrItem* m_pSelection;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// ����֧��

// ʵ��
public:
	virtual ~CEmbWord1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
	void EmWord(void);
};

#ifndef _DEBUG  // EmbWord1View.cpp �еĵ��԰汾
inline CEmbWord1Doc* CEmbWord1View::GetDocument() const
   { return reinterpret_cast<CEmbWord1Doc*>(m_pDocument); }
#endif

