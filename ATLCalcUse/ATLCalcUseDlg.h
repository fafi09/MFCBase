
// ATLCalcUseDlg.h : ͷ�ļ�
//

#pragma once


// CATLCalcUseDlg �Ի���
class CATLCalcUseDlg : public CDialogEx
{
// ����
public:
	CATLCalcUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ATLCALCUSE_DIALOG };

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
	afx_msg void OnClickedTest();
	afx_msg void OnClickedProgid();
	afx_msg void OnClickedCcomptr();
};
