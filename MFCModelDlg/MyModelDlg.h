#pragma once


// CMyModelDlg 对话框

class CMyModelDlg : public CDialog
{
	DECLARE_DYNAMIC(CMyModelDlg)

public:
	CMyModelDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyModelDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
