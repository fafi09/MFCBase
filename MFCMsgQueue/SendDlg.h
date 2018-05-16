#pragma once


// CSendDlg 对话框

class CSendDlg : public CDialog
{
	DECLARE_DYNAMIC(CSendDlg)

public:
	CSendDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSendDlg();

// 对话框数据
	enum { IDD = IDD_DLG_SEND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSend();
	CListBox m_wndSend;
	static UINT SendThread(LPVOID pParam);
	CMsgQueue* m_pQueue;
};
