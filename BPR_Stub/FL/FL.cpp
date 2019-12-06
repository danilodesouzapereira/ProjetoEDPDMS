#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <FL.h>
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
EXPORT TFL* __fastcall DLL_NewFL(TTopologiaDMS* topoDMS)
{
	return(NULL);
}
//---------------------------------------------------------------------------
EXPORT void __fastcall DLL_DeleteFL(TFL* localizador)
{
}
//---------------------------------------------------------------------------
