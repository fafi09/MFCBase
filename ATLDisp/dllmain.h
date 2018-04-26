// dllmain.h : 模块类的声明。

class CATLDispModule : public ATL::CAtlDllModuleT< CATLDispModule >
{
public :
	DECLARE_LIBID(LIBID_ATLDispLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLDISP, "{D860BB43-11CA-4D30-93D7-67423F74CC1E}")
};

extern class CATLDispModule _AtlModule;
