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
	STDMETHOD_(LONG, AddRef)();
};

