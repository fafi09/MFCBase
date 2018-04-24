#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>
#include "ATLCom_h.h"

//增加类厂实现
extern const CLSID CLSID_ComObj;

class CMath :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CMath, &CLSID_ComObj>,  ////增加类厂实现
	public IMath
{
public:
	CMath();
	virtual ~CMath();
	//增加类厂实现 添加注册表资源的宏
	DECLARE_REGISTRY_RESOURCE(0)
public:
	BEGIN_COM_MAP(CMath)
		COM_INTERFACE_ENTRY(IMath)
	END_COM_MAP()
public:
	STDMETHOD(Add)(int nAdd1, int nAdd2, int* pnAdd);
	STDMETHOD(Sub)(int nSub1, int nSub2, int* pnSub);
};