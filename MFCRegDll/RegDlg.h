#pragma once


// RegDlg 对话框

class RegDlg : public CDialog
{
	DECLARE_DYNAMIC(RegDlg)

public:
	RegDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RegDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
