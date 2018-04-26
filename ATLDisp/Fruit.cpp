// Fruit.cpp : CFruit ��ʵ��

#include "stdafx.h"
#include "Fruit.h"


// CFruit



STDMETHODIMP CFruit::Add(long nAdd1, long nAdd2, long* pnAdd)
{
	*pnAdd = nAdd1 + nAdd2;

	return S_OK;
}



STDMETHODIMP CFruit::get_eye(LONG* pVal)
{
	*pVal = m_nEye;

	return S_OK;
}


STDMETHODIMP CFruit::put_eye(LONG newVal)
{
	m_nEye = newVal;

	return S_OK;
}


STDMETHODIMP CFruit::ShowMsg(void)
{
	// TODO: �ڴ����ʵ�ִ���
	MessageBox(NULL,TEXT("show msg"),TEXT("ShowMsg"),MB_OK);
	return S_OK;
}
