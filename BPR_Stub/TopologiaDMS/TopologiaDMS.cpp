#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <TopologiaDMS.h>
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
EXPORT TTopologiaDMS* __fastcall DLL_NewTopologiaDMS(VTApl *apl_owner)
{
	return(NULL);
}
//---------------------------------------------------------------------------
EXPORT void __fastcall DLL_DeleteTopologiaDMS(TTopologiaDMS* topologia)
{
}
//---------------------------------------------------------------------------
