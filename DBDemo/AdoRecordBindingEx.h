#pragma once
#include <icrsint.h>
class CAdoRecordBindingEx :
	public CADORecordBinding
{
public:
	CAdoRecordBindingEx(void);
	~CAdoRecordBindingEx(void);
	IADORecordBinding* m_piBinding;
	// //ͨ���󶨸������ݿ�
	BOOL Update(void);
	// //ͨ��������¼�¼
	BOOL AddNew(void);
};

