
// ATLCalcUse.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CATLCalcUseApp:
// �йش����ʵ�֣������ ATLCalcUse.cpp
//

class CATLCalcUseApp : public CWinApp
{
public:
	CATLCalcUseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CATLCalcUseApp theApp;