#pragma once

// HollowBtn1PropPage.h : CHollowBtn1PropPage 属性页类的声明。


// CHollowBtn1PropPage : 有关实现的信息，请参阅 HollowBtn1PropPage.cpp。

class CHollowBtn1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CHollowBtn1PropPage)
	DECLARE_OLECREATE_EX(CHollowBtn1PropPage)

// 构造函数
public:
	CHollowBtn1PropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_HOLLOWBTN1 };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

