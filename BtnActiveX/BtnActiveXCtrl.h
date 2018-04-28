#pragma once

// BtnActiveXCtrl.h : CBtnActiveXCtrl ActiveX 控件类的声明。


// CBtnActiveXCtrl : 有关实现的信息，请参阅 BtnActiveXCtrl.cpp。

class CBtnActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CBtnActiveXCtrl)

// 构造函数
public:
	CBtnActiveXCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CBtnActiveXCtrl();

	DECLARE_OLECREATE_EX(CBtnActiveXCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CBtnActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CBtnActiveXCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CBtnActiveXCtrl)		// 类型名称和杂项状态

	// 子类控件支持
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
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

