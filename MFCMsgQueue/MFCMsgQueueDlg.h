
// MFCMsgQueueDlg.h : ͷ�ļ�
//

#pragma once


// CMFCMsgQueueDlg �Ի���
class CMFCMsgQueueDlg : public CDialogEx
{
// ����
public:
	CMFCMsgQueueDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCMSGQUEUE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedRcv();
	void Init(void);
	CMsgQueue m_Queue;
};
