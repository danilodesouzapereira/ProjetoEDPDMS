#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <ProjetoEDPDMS\DLL_Inc\DMS.h>
#include <ProjetoEDPDMS\Fontes\DMS\TFormDMS.h>
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
	TForm *form;
	form = new TFormDMS(Owner, apl_owner, parent);
	return(form);
}
//---------------------------------------------------------------------------
