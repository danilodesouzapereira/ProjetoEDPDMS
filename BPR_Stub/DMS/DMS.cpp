#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <DMS.h>
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
EXPORT TForm* __fastcall DLL_NewFormDMS(TComponent *Owner, VTApl *apl_owner, TWinControl *parent)
{
	return(NULL);
}
//---------------------------------------------------------------------------
