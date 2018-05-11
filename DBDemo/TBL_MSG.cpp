// TBL_MSG.h : CTBL_MSG ���ʵ��



// CTBL_MSG ʵ��

// ���������� 2018��5��11��, 14:55

#include "stdafx.h"
#include "TBL_MSG.h"
IMPLEMENT_DYNAMIC(CTBL_MSG, CRecordset)

CTBL_MSG::CTBL_MSG(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_MSG_ID = L"";
	m_MSG_SENDER = L"";
	m_MSG_RECEIVER = L"";
	m_MSG_DATE = L"";
	m_MSG_CONTENT = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CTBL_MSG::GetDefaultConnect()
{
	return _T("DSN=TEST");
}

CString CTBL_MSG::GetDefaultSQL()
{
	return _T("[TBL_MSG]");
}

void CTBL_MSG::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[MSG_ID]"), m_MSG_ID);
	RFX_Text(pFX, _T("[MSG_SENDER]"), m_MSG_SENDER);
	RFX_Text(pFX, _T("[MSG_RECEIVER]"), m_MSG_RECEIVER);
	RFX_Text(pFX, _T("[MSG_DATE]"), m_MSG_DATE);
	RFX_Text(pFX, _T("[MSG_CONTENT]"), m_MSG_CONTENT);

}
/////////////////////////////////////////////////////////////////////////////
// CTBL_MSG ���

#ifdef _DEBUG
void CTBL_MSG::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTBL_MSG::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


