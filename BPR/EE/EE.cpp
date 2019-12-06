#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <ProjetoEDPDMS\DLL_Inc\EE.h>
#include <ProjetoEDPDMS\Fontes\EE\TEE.h>
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
	TEE* estimador = new TEE(apl_owner);
   return(estimador);
}
//---------------------------------------------------------------------------
EXPORT void __fastcall DLL_DeleteEE(TEE* estimador)
{
   delete estimador;
}
//---------------------------------------------------------------------------
