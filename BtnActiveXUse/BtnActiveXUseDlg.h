
// BtnActiveXUseDlg.h : ͷ�ļ�
//

#pragma once
#include "cdbtnactivex.h"


// CBtnActiveXUseDlg �Ի���
class CBtnActiveXUseDlg : public CDialogEx
{
// ����
public:
	CBtnActiveXUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BTNACTIVEXUSE_DIALOG };

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
	CDBtnActiveX m_wndButton;
	afx_msg void OnBtnactivexctrl1();
	DECLARE_EVENTSINK_MAP()
	void ClickBtnactivexctrl1();
	void MyClickBtnactivexctrl1();
	void MyClick2Btnactivexctrl1();
};
