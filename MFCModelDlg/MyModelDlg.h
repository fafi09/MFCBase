#pragma once


// CMyModelDlg �Ի���

class CMyModelDlg : public CDialog
{
	DECLARE_DYNAMIC(CMyModelDlg)

public:
	CMyModelDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyModelDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
