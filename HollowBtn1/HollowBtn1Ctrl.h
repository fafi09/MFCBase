#pragma once

// HollowBtn1Ctrl.h : CHollowBtn1Ctrl ActiveX �ؼ����������


// CHollowBtn1Ctrl : �й�ʵ�ֵ���Ϣ������� HollowBtn1Ctrl.cpp��

class CHollowBtn1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CHollowBtn1Ctrl)

// ���캯��
public:
	CHollowBtn1Ctrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CHollowBtn1Ctrl();

	DECLARE_OLECREATE_EX(CHollowBtn1Ctrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CHollowBtn1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CHollowBtn1Ctrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CHollowBtn1Ctrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
	};
	void SetBmpRgn(int nID);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

