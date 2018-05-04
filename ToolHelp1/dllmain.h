// dllmain.h : 模块类的声明。

class CToolHelp1Module : public ATL::CAtlDllModuleT< CToolHelp1Module >
{
public :
	DECLARE_LIBID(LIBID_ToolHelp1Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TOOLHELP1, "{8CF2A3C6-5EAD-4C72-97D4-5C2E1B83133E}")
};

extern class CToolHelp1Module _AtlModule;
