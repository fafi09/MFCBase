// 14_UseComInterface.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../14_ComInterface/math_h.h"
#include "../14_ComInterface/math_i.c"

typedef IUnknown*(*CREATEINSTANCE)();
HMODULE hModule = NULL;

IMath* GetMath()
{
	hModule = LoadLibrary(TEXT("14_ComInterface.dll"));

	CREATEINSTANCE CreateInstance 
		= (CREATEINSTANCE)GetProcAddress(hModule, "CreateInstance");

	IUnknown* piUnknown = CreateInstance();

	IMath* pMath = NULL;

	piUnknown->QueryInterface(IID_IMath, (LPVOID*)&pMath);

	piUnknown->Release();

	return pMath;
	
}


int _tmain(int argc, _TCHAR* argv[])
{
	IMath* pMath = GetMath();

	long nResult = 0;

	pMath->Add(4,5, &nResult);

	printf("result = %ld\n",nResult);

	FreeLibrary(hModule);

	getch();
	return 0;
}

