
// MFCdllTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCdllTestApp:
// �йش����ʵ�֣������ MFCdllTest.cpp
//

class CMFCdllTestApp : public CWinApp
{
public:
	CMFCdllTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCdllTestApp theApp;