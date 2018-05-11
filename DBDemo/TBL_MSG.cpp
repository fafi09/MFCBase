// TBL_MSG.h : CTBL_MSG 类的实现



// CTBL_MSG 实现

// 代码生成在 2018年5月11日, 14:55

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

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[MSG_ID]"), m_MSG_ID);
	RFX_Text(pFX, _T("[MSG_SENDER]"), m_MSG_SENDER);
	RFX_Text(pFX, _T("[MSG_RECEIVER]"), m_MSG_RECEIVER);
	RFX_Text(pFX, _T("[MSG_DATE]"), m_MSG_DATE);
	RFX_Text(pFX, _T("[MSG_CONTENT]"), m_MSG_CONTENT);

}
/////////////////////////////////////////////////////////////////////////////
// CTBL_MSG 诊断

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


