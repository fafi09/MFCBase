#pragma once


// CRecvDlg �Ի���

class CRecvDlg : public CDialog
{
	DECLARE_DYNAMIC(CRecvDlg)

public:
	CRecvDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRecvDlg();

// �Ի�������
	enum { IDD = IDD_DLG_RECV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnRecv();
	CListBox m_wndData;
	static UINT RecvThread(LPVOID pParam);
	CMsgQueue* m_pQueue;
};
