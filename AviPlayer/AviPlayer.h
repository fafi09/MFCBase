
// AviPlayer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAviPlayerApp:
// �йش����ʵ�֣������ AviPlayer.cpp
//

class CAviPlayerApp : public CWinApp
{
public:
	CAviPlayerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAviPlayerApp theApp;