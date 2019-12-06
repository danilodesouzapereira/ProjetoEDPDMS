#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <EE.h>
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
EXPORT TEE* __fastcall DLL_NewEE(VTApl *apl_owner)
{
	return(NULL);
}
//---------------------------------------------------------------------------
EXPORT void __fastcall DLL_DeleteEE(TEE* estimador)
{
}
//---------------------------------------------------------------------------
