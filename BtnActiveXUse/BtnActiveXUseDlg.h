
// BtnActiveXUseDlg.h : 头文件
//

#pragma once
#include "cdbtnactivex.h"


// CBtnActiveXUseDlg 对话框
class CBtnActiveXUseDlg : public CDialogEx
{
// 构造
public:
	CBtnActiveXUseDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BTNACTIVEXUSE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CDBtnActiveX m_wndButton;
	afx_msg void OnBtnactivexctrl1();
	DECLARE_EVENTSINK_MAP()
	void ClickBtnactivexctrl1();
	void MyClickBtnactivexctrl1();
	void MyClick2Btnactivexctrl1();
};
