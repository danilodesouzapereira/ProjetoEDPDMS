#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include <ProjetoEDPDMS\DLL_Inc\FL.h>
#include <ProjetoEDPDMS\Fontes\FL\TFL.h>
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
EXPORT TFL* __fastcall DLL_NewFL(TTopologiaDMS* topoDMS)
{
	TFL* localizador = new TFL(topoDMS);
   return(localizador);
}
//---------------------------------------------------------------------------
EXPORT void __fastcall DLL_DeleteFL(TFL* localizador)
{
   delete localizador;
}
//---------------------------------------------------------------------------
