#pragma once

// BtnActiveXPropPage.h : CBtnActiveXPropPage 属性页类的声明。


// CBtnActiveXPropPage : 有关实现的信息，请参阅 BtnActiveXPropPage.cpp。

class CBtnActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CBtnActiveXPropPage)
	DECLARE_OLECREATE_EX(CBtnActiveXPropPage)

// 构造函数
public:
	CBtnActiveXPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_BTNACTIVEX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_strName;
	CString m_Name;
};

