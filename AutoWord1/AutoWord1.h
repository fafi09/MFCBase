
// AutoWord1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAutoWord1App:
// �йش����ʵ�֣������ AutoWord1.cpp
//

class CAutoWord1App : public CWinApp
{
public:
	CAutoWord1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAutoWord1App theApp;