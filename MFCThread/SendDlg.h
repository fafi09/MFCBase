#pragma once


// CSendDlg �Ի���

class CSendDlg : public CDialog
{
	DECLARE_DYNAMIC(CSendDlg)

public:
	CSendDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSendDlg();

// �Ի�������
	enum { IDD = IDD_DLG_SEND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};