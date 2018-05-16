#pragma once


// CRecvDlg 对话框

class CRecvDlg : public CDialog
{
	DECLARE_DYNAMIC(CRecvDlg)

public:
	CRecvDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRecvDlg();

// 对话框数据
	enum { IDD = IDD_DLG_RECV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnRecv();
	CListBox m_wndData;
	static UINT RecvThread(LPVOID pParam);
	CMsgQueue* m_pQueue;
};
