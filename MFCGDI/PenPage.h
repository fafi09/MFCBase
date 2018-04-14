#pragma once


// CPenPage 对话框

class CPenPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CPenPage)

public:
	CPenPage();
	virtual ~CPenPage();

// 对话框数据
	enum { IDD = IDD_PEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnOK();
	afx_msg void OnChangeEditWidth();
public:
	int m_penWidth;
//	CString m_nPenWidth;
	int m_nPenWidth;
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	virtual BOOL OnWizardFinish();
};
