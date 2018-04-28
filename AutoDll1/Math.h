
#pragma once


// CMath ÃüÁîÄ¿±ê

class CMath : public CCmdTarget
{
	DECLARE_DYNCREATE(CMath)

public:
	CMath();
	virtual ~CMath();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMath)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	void Add(long nAdd1, long nAdd2, long* pnAdd);
protected:
	void Sub(LONG nSub1, LONG nSub2, LONG* pnSub);

	enum 
	{
		dispidSub = 1L
	};
};


