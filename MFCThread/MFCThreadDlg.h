
// MFCThreadDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFCThreadDlg �Ի���
class CMFCThreadDlg : public CDialogEx
{
// ����
public:
	CMFCThreadDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCTHREAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	static UINT TimeThread(LPVOID pParam);
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
	afx_msg void OnStnClickedStaticTime();
	afx_msg void OnBnClickedWkTdStart();
	afx_msg void OnBnClickedUserTdStart();
	CStatic m_wndTime;
};
