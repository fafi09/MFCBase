// dllmain.h : 模块类的声明。

class CATLCalc1Module : public ATL::CAtlDllModuleT< CATLCalc1Module >
{
public :
	DECLARE_LIBID(LIBID_ATLCalc1Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLCALC1, "{4DD60866-AA9E-47C0-846F-1FE528D53245}")
};

extern class CATLCalc1Module _AtlModule;
