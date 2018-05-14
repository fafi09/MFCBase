#include "StdAfx.h"
#include "AdoRecordBindingEx.h"


CAdoRecordBindingEx::CAdoRecordBindingEx(void)
{
}


CAdoRecordBindingEx::~CAdoRecordBindingEx(void)
{
	if(m_piBinding != NULL)
	{
		m_piBinding->Release();
	}
}


// //通过绑定更新数据库
BOOL CAdoRecordBindingEx::Update(void)
{
	if(FAILED(m_piBinding->Update(this)))
	{
		return FALSE;
	}
	return TRUE;
}


// //通过绑定添加新记录
BOOL CAdoRecordBindingEx::AddNew(void)
{
	if(FAILED(m_piBinding->AddNew(this)))
	{
		return FALSE;
	}
	return TRUE;
}
