
// BtnActiveXUse.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBtnActiveXUseApp:
// �йش����ʵ�֣������ BtnActiveXUse.cpp
//

class CBtnActiveXUseApp : public CWinApp
{
public:
	CBtnActiveXUseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBtnActiveXUseApp theApp;