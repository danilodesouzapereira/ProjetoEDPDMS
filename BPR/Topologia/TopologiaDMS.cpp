
#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <ProjetoEDPDMS\DLL_Inc\TopologiaDMS.h>
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <ProjetoEDPDMS\Fontes\TopologiaDMS\VTTopologiaDMS.h>
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
EXPORT VTTopologiaDMS* __fastcall DLL_NewTopologiaDMS(VTApl *apl_owner, String codigoRede)
{
	return(NewObjTopologiaDMS(apl_owner, codigoRede));
}
//---------------------------------------------------------------------------
