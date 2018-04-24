// ATLComUse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../ATLCom/math.h"
#include "../ATLCom/ATLCom_i.c"

HMODULE hModule = NULL;
typedef IUnknown*(*MYCREATEINSTANCE)();
typedef IUnknown*(*MYCREATEINSTANCE2)(CLSID clsid);

IMath* GetMath()
{
	hModule = LoadLibrary(TEXT("ATLCom.dll"));
	MYCREATEINSTANCE MyCreate 
		= (MYCREATEINSTANCE)GetProcAddress( hModule, "MyCreateInstance");

	IUnknown* piUnknown = MyCreate();

	IMath* piMath = NULL;

	piUnknown->QueryInterface(IID_IMath, (LPVOID*)&piMath);

	piUnknown->Release();

	return piMath;
}

IMath* GetMath2()
{
	hModule = LoadLibrary(TEXT("ATLCom.dll"));
	MYCREATEINSTANCE2 MyCreate 
		= (MYCREATEINSTANCE2)GetProcAddress( hModule, "MyCreateInstance2");

	IUnknown* piUnknown = MyCreate(CLSID_ComObj);

	IMath* piMath = NULL;

	piUnknown->QueryInterface(IID_IMath, (LPVOID*)&piMath);

	piUnknown->Release();

	return piMath;
}


int _tmain(int argc, _TCHAR* argv[])
{
	IMath* piMath = GetMath();

	int nResult = 0;
	piMath->Add(5,5,&nResult);

	printf("nResult=%d\n", nResult);

	piMath = GetMath2();
	piMath->Add(5,4,&nResult);
	printf("nResult=%d\n", nResult);

	FreeLibrary(hModule);

	getch();
	return 0;
}

