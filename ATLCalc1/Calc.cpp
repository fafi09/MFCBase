// Calc.cpp : CCalc 的实现

#include "stdafx.h"
#include "Calc.h"


// CCalc



STDMETHODIMP CCalc::Sub(LONG nSub1, LONG nSub2, LONG* pnSub)
{
	// TODO: 在此添加实现代码
	*pnSub = nSub1 - nSub2;
	return S_OK;
}


STDMETHODIMP CCalc::Add(long nAdd1, long nAdd2, long* pnAdd)
{
	// TODO: 在此添加实现代码
	*pnAdd = nAdd1 + nAdd2;
	return S_OK;
}
