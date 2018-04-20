#ifndef _MATH_H_
#define _MATH_H_

#include "objbase.h"

static const GUID IID_IBase = 
{ 0x6e51f315, 0xdc0, 0x4df2, { 0x8e, 0x43, 0xd4, 0x2d, 0x76, 0x70, 0x48, 0xf4 } };

interface IBase
{
public:
	virtual int AddRef( ) = 0;
	virtual int Release( ) = 0;
	virtual int QueryInterface( GUID iid, void** ppiInterface ) = 0;
};

// {7890883E-BF9A-4C1F-A429-FEBB16413B52}
static const GUID IID_IMath1 = 
{ 0x7890883e, 0xbf9a, 0x4c1f, { 0xa4, 0x29, 0xfe, 0xbb, 0x16, 0x41, 0x3b, 0x52 } };


interface IMath1 : IBase
{
public:
	virtual int Add(int nAdd1, int nAdd2) = 0;
	virtual int Sub(int nSub1, int nSub2) = 0;
};

// {CE449767-2689-44F6-959F-757738C09411}
static const GUID IID_IMath2 = 
{ 0xce449767, 0x2689, 0x44f6, { 0x95, 0x9f, 0x75, 0x77, 0x38, 0xc0, 0x94, 0x11 } };

interface IMath2 : IBase
{
public:
	virtual int Mul(int nMul1, int nMul2) = 0;
	virtual int Div(int nDiv1, int nDiv2) = 0;
};



#endif //_MATH_H_