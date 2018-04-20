// 13_DllInterface.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "math.h"

class CMath : public IMath1,
	public IMath2
{
public:
	CMath( );
	virtual int AddRef( );
	virtual int Release( );
	virtual int QueryInterface( GUID iid, void** ppiInterface );
	virtual int Add(int nAdd1, int nAdd2);
	virtual int Sub(int nSub1, int nSub2);
	virtual int Mul(int nMul1, int nMul2);
	virtual int Div(int nDiv1, int nDiv2);
public:
	LONG m_nRef;
};

CMath::CMath( )
{
	m_nRef = 0;
}

int CMath::AddRef()
{
	InterlockedIncrement( &m_nRef );
	return m_nRef;
}

int CMath::Release( )
{
	InterlockedDecrement( &m_nRef );
	if(m_nRef == 0)
	{
		delete this;
	}
	return m_nRef;
}

int CMath::Add(int nAdd1, int nAdd2)
{
	return nAdd1 + nAdd2;
}

int CMath::Sub(int nSub1, int nSub2)
{
	return nSub1 - nSub2;
}

int CMath::Mul(int nMul1, int nMul2)
{
	return nMul1 * nMul2;
}

int CMath::Div(int nDiv1, int nDiv2)
{
	return nDiv1 / nDiv2;
}

int CMath::QueryInterface( GUID iid, void** ppiInterface )
{
	if(iid == IID_IMath1)
	{
		*ppiInterface = static_cast<IMath1*>(this);
		AddRef();
	}
	else if(iid == IID_IMath2)
	{
		*ppiInterface = static_cast<IMath2*>(this);
		AddRef();
	}
	else if(iid == IID_IBase)
	{
		*ppiInterface = static_cast<IMath1*>(this);
		AddRef();
	}
	return 0;
}

IMath1* createInstance()
{
	IMath1* pMath = new CMath;
	pMath->AddRef();
	return pMath;
}