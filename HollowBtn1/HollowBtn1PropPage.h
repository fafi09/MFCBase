#pragma once

// HollowBtn1PropPage.h : CHollowBtn1PropPage ����ҳ���������


// CHollowBtn1PropPage : �й�ʵ�ֵ���Ϣ������� HollowBtn1PropPage.cpp��

class CHollowBtn1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CHollowBtn1PropPage)
	DECLARE_OLECREATE_EX(CHollowBtn1PropPage)

// ���캯��
public:
	CHollowBtn1PropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_HOLLOWBTN1 };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

