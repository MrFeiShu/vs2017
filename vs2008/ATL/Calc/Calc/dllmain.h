// dllmain.h : Declaration of module class.

class CCalcModule : public CAtlDllModuleT< CCalcModule >
{
public :
	DECLARE_LIBID(LIBID_CalcLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CALC, "{63F1E898-47FB-4AE3-BF30-3FE76653853C}")
};

extern class CCalcModule _AtlModule;
