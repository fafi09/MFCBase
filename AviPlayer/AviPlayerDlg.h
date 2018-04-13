
// AviPlayerDlg.h : 头文件
//

#pragma once


// CAviPlayerDlg 对话框
class CAviPlayerDlg : public CDialogEx
{
// 构造
public:
	CAviPlayerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_AVIPLAYER_DIALOG };

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
	CAnimateCtrl m_wndAnimate;
	CListBox m_wndHistory;
	CHotKeyCtrl m_wndHotKey;
	CButton m_wndLoop;
	CString m_strFilePath;
	afx_msg void OnOpen();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnLoop();
	afx_msg void OnDblclkHistory();
	afx_msg void OnSethotkey();
	CComboBox m_wndLoopNum;
};
