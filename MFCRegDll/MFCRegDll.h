// MFCRegDll.h : MFCRegDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCRegDllApp
// �йش���ʵ�ֵ���Ϣ������� MFCRegDll.cpp
//

class CMFCRegDllApp : public CWinApp
{
public:
	CMFCRegDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
