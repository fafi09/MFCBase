#include "stdafx.h"
#include "ImpMath.h"

CImpMath::CImpMath()
{
	m_nRef = 0;
}

CImpMath::~CImpMath()
{

}

STDMETHODIMP CImpMath::QueryInterface(REFIID iid, LPVOID* ppiObject)
{
	if(iid == IID_IUnknown)
	{
		*ppiObject = static_cast<IUnknown*>(this);
	}
	else if(iid == IID_IMath)
	{
		*ppiObject = static_cast<IMath*>(this);
	}
	else
	{
		*ppiObject = NULL;
		return E_NOINTERFACE;
	}
	AddRef();

	return S_OK;
}

STDMETHODIMP_(ULONG) CImpMath::AddRef()
{
	InterlockedIncrement(&m_nRef);
	return m_nRef;
}

STDMETHODIMP_(ULONG) CImpMath::Release()
{
	InterlockedDecrement(&m_nRef);
	if(m_nRef == 0)
	{
		delete this;
	}
	return m_nRef;
}

STDMETHODIMP CImpMath::Add(long nAdd1, long nAdd2, long* pnAdd)
{
	if(pnAdd == NULL)
	{
		return E_INVALIDARG;
	}

	*pnAdd = nAdd1 + nAdd2;

	return S_OK;
}

STDMETHODIMP CImpMath::Sub(long nSub1, long nSub2, long* pnSub)
{
	if(pnSub == NULL)
	{
		return E_INVALIDARG;
	}

	*pnSub = nSub1 - nSub2;

	return S_OK;
}