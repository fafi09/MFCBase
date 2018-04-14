#pragma once


// CBrushPage 对话框

class CBrushPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CBrushPage)

public:
	CBrushPage();
	virtual ~CBrushPage();

// 对话框数据
	enum { IDD = IDD_BRUSH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnOK();
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardBack();
	virtual BOOL OnWizardFinish();
};
