#pragma once
#include "resource.h"

// CListDlg �Ի���

class CListDlg : public CDialog
{
	DECLARE_DYNAMIC(CListDlg)

public:
	CListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CListDlg();

// �Ի�������
	enum { IDD = IDD_LIST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CImageList m_imgNormal;
	CImageList m_imgSmall;
	CComboBox m_wndCombo;
	CListCtrl m_wndList;
//	afx_msg void OnListDlg();
	void InitListCtrl(void);
	void ShowList(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnClickedOrder();
	afx_msg void OnClickedDel();
	afx_msg void OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEndlabeleditList(NMHDR *pNMHDR, LRESULT *pResult);
};
