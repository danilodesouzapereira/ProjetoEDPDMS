#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <ProjetoEDPDMS\DLL_Inc\FL.h>
#include <ProjetoEDPDMS\Fontes\FL\VTFL.h>
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
EXPORT VTFL* __fastcall DLL_NewFL(VTApl* apl)
{
	return(NewObjFL(apl));
}
//---------------------------------------------------------------------------
