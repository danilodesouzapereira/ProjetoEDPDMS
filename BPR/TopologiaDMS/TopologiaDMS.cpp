
#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <ProjetoEDPDMS\DLL_Inc\TopologiaDMS.h>
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <ProjetoEDPDMS\Fontes\TopologiaDMS\TTopologiaDMS.h>
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
	TTopologiaDMS* topoDMS = new TTopologiaDMS(apl_owner);
	return(topoDMS);
}
//---------------------------------------------------------------------------
EXPORT void __fastcall DLL_DeleteTopologiaDMS(TTopologiaDMS* topologiaDMS)
{
	delete topologiaDMS;
}
//---------------------------------------------------------------------------
