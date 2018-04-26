
// ATLDispUseDlg.h : 头文件
//

#pragma once


// CATLDispUseDlg 对话框
class CATLDispUseDlg : public CDialogEx
{
// 构造
public:
	CATLDispUseDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ATLDISPUSE_DIALOG };

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
	afx_msg void OnClickedNoparam();
	afx_msg void OnClickedParam();
	afx_msg void OnClickedProp();
	afx_msg void OnClickedTypelib();
	IDispatch* GetDispatch(void);
};
