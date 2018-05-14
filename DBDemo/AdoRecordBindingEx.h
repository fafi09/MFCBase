#pragma once
#include <icrsint.h>
class CAdoRecordBindingEx :
	public CADORecordBinding
{
public:
	CAdoRecordBindingEx(void);
	~CAdoRecordBindingEx(void);
	IADORecordBinding* m_piBinding;
	// //通过绑定更新数据库
	BOOL Update(void);
	// //通过绑定添加新记录
	BOOL AddNew(void);
};

