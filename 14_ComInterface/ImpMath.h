#pragma once
#include "math_h.h"

class CImpMath :
	public IMath
{
public:
	CImpMath(void);
	virtual ~CImpMath(void);

public:
	STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppiObject);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();
public:
	STDMETHOD(Add)(long nAdd1, long nAdd2, long* pnAdd);
	STDMETHOD(Sub)(long nSub1, long nSub2, long* pnSub);
public:
	LONG m_nRef;
};

