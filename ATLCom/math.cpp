#include "stdafx.h"
#include "math.h"

CComModule _Module;

CMath::CMath()
{

}

CMath::~CMath()
{

}

STDMETHODIMP CMath::Add(int nAdd1, int nAdd2, int* pnAdd)
{
	*pnAdd = nAdd1 + nAdd2;

	return S_OK;
}

STDMETHODIMP CMath::Sub(int nSub1, int nSub2, int* pnSub)
{
	*pnSub = nSub1 - nSub2;
	return S_OK;
}