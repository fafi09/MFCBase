#pragma once

// BtnActiveXCtrl.h : CBtnActiveXCtrl ActiveX �ؼ����������


// CBtnActiveXCtrl : �й�ʵ�ֵ���Ϣ������� BtnActiveXCtrl.cpp��

class CBtnActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CBtnActiveXCtrl)

// ���캯��
public:
	CBtnActiveXCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CBtnActiveXCtrl();

	DECLARE_OLECREATE_EX(CBtnActiveXCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CBtnActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CBtnActiveXCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CBtnActiveXCtrl)		// �������ƺ�����״̬

	// ����ؼ�֧��
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

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
		eventidMyClick2 = 3L,
		eventidMyClick1 = 2L,
		dispidMyClick = 1L,
		dispidSetButtonName = 2L,
		dispidName = 1
	};
protected:
	void OnNameChanged(void);
	CString m_Name;
	void SetButtonName(LPCTSTR pszName);
	void MyClick(void);

	void MyClick1(void)
	{
		FireEvent(eventidMyClick1, EVENT_PARAM(VTS_NONE));
	}

	void FireClick(void)
	{
		FireEvent(eventidMyClick2, EVENT_PARAM(VTS_NONE));
	}
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CString m_strButtonName;
};

