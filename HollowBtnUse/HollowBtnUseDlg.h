
// HollowBtnUseDlg.h : ͷ�ļ�
//

#pragma once


// CHollowBtnUseDlg �Ի���
class CHollowBtnUseDlg : public CDialogEx
{
// ����
public:
	CHollowBtnUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HOLLOWBTNUSE_DIALOG };

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
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_EVENTSINK_MAP()
	void ClickHollowbtn1ctrl1();
	void SetBmpRgn(int nID);
};
