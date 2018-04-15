#pragma once


// CTreeDlg �Ի���

class CTreeDlg : public CDialog
{
	DECLARE_DYNAMIC(CTreeDlg)

public:
	CTreeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTreeDlg();

// �Ի�������
	enum { IDD = IDD_TREE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedTreeDel();
	CImageList m_imgNormal;
	CImageList m_imgState;
	CTreeCtrl m_wndTree;
	virtual BOOL OnInitDialog();
	void InitTreeCtrl(void);
	void ShowTree(void);
	afx_msg void OnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEndlabeleditTree1(NMHDR *pNMHDR, LRESULT *pResult);
};
