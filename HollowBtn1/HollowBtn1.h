#pragma once

// HollowBtn1.h : HollowBtn1.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// CHollowBtn1App : �й�ʵ�ֵ���Ϣ������� HollowBtn1.cpp��

class CHollowBtn1App : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

