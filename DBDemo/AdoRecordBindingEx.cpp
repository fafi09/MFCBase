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


// //ͨ���󶨸������ݿ�
BOOL CAdoRecordBindingEx::Update(void)
{
	if(FAILED(m_piBinding->Update(this)))
	{
		return FALSE;
	}
	return TRUE;
}


// //ͨ��������¼�¼
BOOL CAdoRecordBindingEx::AddNew(void)
{
	if(FAILED(m_piBinding->AddNew(this)))
	{
		return FALSE;
	}
	return TRUE;
}
