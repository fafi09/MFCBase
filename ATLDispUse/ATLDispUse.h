
// ATLDispUse.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CATLDispUseApp:
// �йش����ʵ�֣������ ATLDispUse.cpp
//

class CATLDispUseApp : public CWinApp
{
public:
	CATLDispUseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CATLDispUseApp theApp;