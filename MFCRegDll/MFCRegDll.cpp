// MFCRegDll.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "MFCRegDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CMFCRegDllApp

BEGIN_MESSAGE_MAP(CMFCRegDllApp, CWinApp)
END_MESSAGE_MAP()


// CMFCRegDllApp 构造

CMFCRegDllApp::CMFCRegDllApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMFCRegDllApp 对象

CMFCRegDllApp theApp;


// CMFCRegDllApp 初始化

BOOL CMFCRegDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

#include "RegDlg.h"

void ShowDlg()
{
	/*
	在DLL中：
	MFC查找资源，需要获取资源HINSTANCE时，
	默认会获得当前EXE的HINSTANCE。所以，
	如果在EXE的HINSTANCE中，查找DLL
	资源的ID，会查找失败或者获取错误的
	资源数据。
	因此，需要在DLL的函数开始，增加

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	作用是将当前的默认资源HINSTANCE，由
	原来的EXE替换为当前所在DLL的HINSTANCE。
	*/
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RegDlg dlg;
	dlg.DoModal();

}