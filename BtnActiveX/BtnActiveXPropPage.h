#pragma once

// BtnActiveXPropPage.h : CBtnActiveXPropPage ����ҳ���������


// CBtnActiveXPropPage : �й�ʵ�ֵ���Ϣ������� BtnActiveXPropPage.cpp��

class CBtnActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CBtnActiveXPropPage)
	DECLARE_OLECREATE_EX(CBtnActiveXPropPage)

// ���캯��
public:
	CBtnActiveXPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_BTNACTIVEX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_strName;
	CString m_Name;
};

