
// DBDemoDlg.h : ͷ�ļ�
//

#pragma once


// CDBDemoDlg �Ի���
class CDBDemoDlg : public CDialogEx
{
// ����
public:
	CDBDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DBDEMO_DIALOG };

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
	CListCtrl m_wndDatas;
	afx_msg void OnClickedBindOdbc();
	afx_msg void OnClickedShowAdo();
	afx_msg void OnClickedShowOdbc();
};
