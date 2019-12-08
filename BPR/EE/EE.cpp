#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <ProjetoEDPDMS\DLL_Inc\EE.h>
#include <ProjetoEDPDMS\Fontes\EE\VTEE.h>
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
EXPORT VTEE* __fastcall DLL_NewEE(VTApl *apl_owner)
{
	return(NewObjEE(apl_owner));
}
//---------------------------------------------------------------------------
