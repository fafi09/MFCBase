
// MFCdllTestDlg.h : ͷ�ļ�
//

#pragma once
#include "../MFCStyleXp/ButtonXp.h"
#pragma comment(lib, "../lib/MFCStyleXp.lib")

// CMFCdllTestDlg �Ի���
class CMFCdllTestDlg : public CDialogEx
{
// ����
public:
	CMFCdllTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCDLLTEST_DIALOG };

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
	CButtonXp m_wndBtnXp;
};
