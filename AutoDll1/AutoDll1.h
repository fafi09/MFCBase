// AutoDll1.h : AutoDll1 DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAutoDll1App
// �йش���ʵ�ֵ���Ϣ������� AutoDll1.cpp
//

class CAutoDll1App : public CWinApp
{
public:
	CAutoDll1App();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
