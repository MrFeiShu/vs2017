// dllmain.h : Declaration of module class.

class CtestModule : public CAtlDllModuleT< CtestModule >
{
public :
	DECLARE_LIBID(LIBID_testLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TEST, "{5500E74C-620A-434A-A739-09C814E7FFD2}")
};

extern class CtestModule _AtlModule;
