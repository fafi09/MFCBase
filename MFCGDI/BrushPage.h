#pragma once


// CBrushPage �Ի���

class CBrushPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CBrushPage)

public:
	CBrushPage();
	virtual ~CBrushPage();

// �Ի�������
	enum { IDD = IDD_BRUSH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnOK();
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardBack();
	virtual BOOL OnWizardFinish();
};
