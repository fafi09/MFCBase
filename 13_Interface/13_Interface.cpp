// 13_Interface.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "objbase.h"

interface IMath
{
public:
	virtual int add(int nAdd1, int nAdd2) = 0;
	virtual int sub(int nSub1, int nSub2) = 0;
};

class CImpMath1 : public IMath
{
public:
	virtual int add(int nAdd1, int nAdd2);
	virtual int sub(int nSub1, int nSub2);
};

class CImpMath2 : public IMath
{
public:
	virtual int add(int nAdd1, int nAdd2);
	virtual int sub(int nSub1, int nSub2);
};

int CImpMath1::add(int nAdd1, int nAdd2)
{
	return nAdd1 + nAdd2;
}

int CImpMath1::sub(int nSub1, int nSub2)
{
	return nSub1 - nSub2;
}

int CImpMath2::add(int nAdd1, int nAdd2)
{
	return nAdd1 + nAdd2;
}

int CImpMath2::sub(int nSub1, int nSub2)
{
	return nSub1 - nSub2;
}

IMath* createInstance( )
{
	return new CImpMath2;
}


int _tmain(int argc, _TCHAR* argv[])
{
	IMath* pMath = createInstance( );
	int nResult = pMath->add(5,4);

	printf("result=%d\n",nResult);
	getch();

	return 0;
}

