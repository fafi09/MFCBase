// 13_UseDllInterface.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "../13_DllInterface/math.h"

typedef IMath1* (* CREATEINSTANCE )( );
HMODULE hModule = NULL;
IMath1* CreateInstance()
{
	hModule = LoadLibrary(TEXT("13_DllInterface.dll"));

	CREATEINSTANCE createInstance = (CREATEINSTANCE)GetProcAddress(hModule, "createInstance");

	IMath1* pMath = createInstance();

	return pMath;
}



int _tmain(int argc, _TCHAR* argv[])
{
	IMath1* pMath = CreateInstance();

	int nResult = pMath->Add(3,4);

	printf("result = %d \n", nResult);

	IMath2* pMath2 = NULL;

	pMath->QueryInterface(IID_IMath2, (void**)&pMath2);

	nResult = pMath2->Mul(4,5);

	printf("result = %d \n", nResult);

	pMath2->Release();

	pMath->Release();


	FreeLibrary(hModule);
	getch();
	return 0;
}

