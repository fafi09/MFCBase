
// DBDemoDlg.h : ͷ�ļ�
//

#pragma once

#import "C:\Program Files (x86)\Common Files\System\ado\msado15.dll" no_namespace 				rename("EOF","adoEOF")
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
	void AdoMethod1(void);
	void AdoMethod2(void);
	void AdoMethod3(void);
	afx_msg void OnClickedAddAdo();
	afx_msg void OnClickedDelAdo();
	afx_msg void OnClickedUpdAdo();
	void PrintProviderError(_ConnectionPtr pConnection);
	void PrintComError(_com_error &e);
	afx_msg void OnBnClickedBinaryAdo();
};
