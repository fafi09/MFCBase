
// ATLDispUseDlg.h : ͷ�ļ�
//

#pragma once


// CATLDispUseDlg �Ի���
class CATLDispUseDlg : public CDialogEx
{
// ����
public:
	CATLDispUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ATLDISPUSE_DIALOG };

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
	afx_msg void OnClickedNoparam();
	afx_msg void OnClickedParam();
	afx_msg void OnClickedProp();
	afx_msg void OnClickedTypelib();
	IDispatch* GetDispatch(void);
};
