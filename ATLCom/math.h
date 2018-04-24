#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>
#include "ATLCom_h.h"

//�����೧ʵ��
extern const CLSID CLSID_ComObj;

class CMath :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CMath, &CLSID_ComObj>,  ////�����೧ʵ��
	public IMath
{
public:
	CMath();
	virtual ~CMath();
	//�����೧ʵ�� ���ע�����Դ�ĺ�
	DECLARE_REGISTRY_RESOURCE(0)
public:
	BEGIN_COM_MAP(CMath)
		COM_INTERFACE_ENTRY(IMath)
	END_COM_MAP()
public:
	STDMETHOD(Add)(int nAdd1, int nAdd2, int* pnAdd);
	STDMETHOD(Sub)(int nSub1, int nSub2, int* pnSub);
};