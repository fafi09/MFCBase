#pragma once


// CPenPage �Ի���

class CPenPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CPenPage)

public:
	CPenPage();
	virtual ~CPenPage();

// �Ի�������
	enum { IDD = IDD_PEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
