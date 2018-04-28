
// AutoWord1Dlg.h : 头文件
//

#pragma once


// CAutoWord1Dlg 对话框
class CAutoWord1Dlg : public CDialogEx
{
// 构造
public:
	CAutoWord1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_AUTOWORD1_DIALOG };

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
	afx_msg void OnClickedAutoexe();
	afx_msg void OnClickedAutodll();
	afx_msg void OnClickedWord();
};
