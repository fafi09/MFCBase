
// MFCdllTestDlg.h : 头文件
//

#pragma once
#include "../MFCStyleXp/ButtonXp.h"
#pragma comment(lib, "../lib/MFCStyleXp.lib")

// CMFCdllTestDlg 对话框
class CMFCdllTestDlg : public CDialogEx
{
// 构造
public:
	CMFCdllTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCDLLTEST_DIALOG };

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
	afx_msg void OnClickedTestBtn();
	DECLARE_MESSAGE_MAP()
public:
	CButtonXp m_wndBtnXp;
};
