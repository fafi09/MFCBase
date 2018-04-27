// DataType.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "conio.h"

#include <atlbase.h>
#include <comdef.h>

void StringCom()
{
	//����BSTR�ַ��� atlbase.h
	BSTR bstrText = SysAllocString(TEXT("hello bstr"));
	
	wprintf(TEXT("BSTR:%s\n"), bstrText);

	//�ͷ��ַ���
	SysFreeString(bstrText);

	//atl��
	CComBSTR bstrText2("atl ComBstr");

	wprintf(TEXT("atl comBstr: %s\n"), bstrText2);

	//c++��
	_bstr_t bstrText3;  //comdef.h
	bstrText3 = "c++ _bstr_t";

	printf("c++ _bstr_t: %s\n", (LPCSTR)bstrText3);
}

void VariantCom()
{
	VARIANT var1 = {0};
	VARIANT var2 = {0};

	//����
	var1.vt = VT_I4;
	var1.lVal = 23;

	long tstArray[] = {2,3};
	var2.vt = VT_I4 | VT_BYREF; //����ָ��
	var2.plVal = tstArray;

	//atl��
	CComVariant comVar;
	comVar = 56;

	//c++��
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
		VT_I4, //����
		2, //ά��
		rgsaBound);

	//��ֵ
	for(int nY = 0; nY < 10; nY++)
	{
		for(int nX = 0; nX < 10; nX++)
		{
			LONG nInd[2] = {nY,nX};
			LONG nValue = nY*100 + nX;
			SafeArrayPutElement(psa, nInd, &nValue);
		}
	}

	//ȡֵ
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

