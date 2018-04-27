// DataType.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "conio.h"

#include <atlbase.h>
#include <comdef.h>

void StringCom()
{
	//创建BSTR字符串 atlbase.h
	BSTR bstrText = SysAllocString(TEXT("hello bstr"));
	
	wprintf(TEXT("BSTR:%s\n"), bstrText);

	//释放字符串
	SysFreeString(bstrText);

	//atl库
	CComBSTR bstrText2("atl ComBstr");

	wprintf(TEXT("atl comBstr: %s\n"), bstrText2);

	//c++库
	_bstr_t bstrText3;  //comdef.h
	bstrText3 = "c++ _bstr_t";

	printf("c++ _bstr_t: %s\n", (LPCSTR)bstrText3);
}

void VariantCom()
{
	VARIANT var1 = {0};
	VARIANT var2 = {0};

	//整型
	var1.vt = VT_I4;
	var1.lVal = 23;

	long tstArray[] = {2,3};
	var2.vt = VT_I4 | VT_BYREF; //整型指针
	var2.plVal = tstArray;

	//atl库
	CComVariant comVar;
	comVar = 56;

	//c++库
	_variant_t var4;
	var4 = "test4";
}

void SafeArray()
{
	SAFEARRAY *psa;

	SAFEARRAYBOUND rgsaBound[2];
	rgsaBound[0].lLbound = 0;
	rgsaBound[0].cElements = 10;
	rgsaBound[1].lLbound = 0;
	rgsaBound[1].cElements = 10;

	psa = SafeArrayCreate(
		VT_I4, //类型
		2, //维度
		rgsaBound);

	//赋值
	for(int nY = 0; nY < 10; nY++)
	{
		for(int nX = 0; nX < 10; nX++)
		{
			LONG nInd[2] = {nY,nX};
			LONG nValue = nY*100 + nX;
			SafeArrayPutElement(psa, nInd, &nValue);
		}
	}

	//取值
	for(int nY = 0; nY < 10; nY++)
	{
		for(int nX = 0; nX < 10; nX++)
		{
			LONG nInd[2] = {nY,nX};
			LONG nValue = 0;
			SafeArrayGetElement(psa,nInd,&nValue);
			printf("%d:%d->%ld\n",nY,nX,nValue);
		}
	}

	SafeArrayDestroy(psa);


}

int _tmain(int argc, _TCHAR* argv[])
{
	StringCom();
	VariantCom();
	SafeArray();
	getch();
	return 0;
}

