#pragma once

// HollowBtn1Ctrl.h : CHollowBtn1Ctrl ActiveX 控件类的声明。


// CHollowBtn1Ctrl : 有关实现的信息，请参阅 HollowBtn1Ctrl.cpp。

class CHollowBtn1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CHollowBtn1Ctrl)

// 构造函数
public:
	CHollowBtn1Ctrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CHollowBtn1Ctrl();

	DECLARE_OLECREATE_EX(CHollowBtn1Ctrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CHollowBtn1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CHollowBtn1Ctrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CHollowBtn1Ctrl)		// 类型名称和杂项状态

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
	};
	void SetBmpRgn(int nID);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

