// Calc.cpp : CCalc ��ʵ��

#include "stdafx.h"
#include "Calc.h"


// CCalc



STDMETHODIMP CCalc::Sub(LONG nSub1, LONG nSub2, LONG* pnSub)
{
	// TODO: �ڴ����ʵ�ִ���
	*pnSub = nSub1 - nSub2;
	return S_OK;
}


STDMETHODIMP CCalc::Add(long nAdd1, long nAdd2, long* pnAdd)
{
	// TODO: �ڴ����ʵ�ִ���
	*pnAdd = nAdd1 + nAdd2;
	return S_OK;
}
