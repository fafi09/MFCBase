#pragma once


// RegDlg �Ի���

class RegDlg : public CDialog
{
	DECLARE_DYNAMIC(RegDlg)

public:
	RegDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RegDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
