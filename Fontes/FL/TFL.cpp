//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TFL.h"
#include <ProjetoEDPDMS\DLL_Inc\TopologiaDMS.h>
#include <ProjetoEDPDMS\Fontes\TopologiaDMS\VTTopologiaDMS.h>
#include <ProjetoEDPDMS\Fontes\DMS\Modelos.h>
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
VTFL* __fastcall NewObjFL(VTApl *apl)
{
	return(new TFL(apl));
}
//---------------------------------------------------------------------------
__fastcall TFL::TFL(VTApl* apl)
{
	this->apl = apl;
}
//---------------------------------------------------------------------------
__fastcall TFL::~TFL(void)
{
   // Destroi objetos
	delete topologiaDMS;
}
//---------------------------------------------------------------------------
void __fastcall TFL::ExecutaProcesso(EntradaFL* entradaFL)
{
	this->entradaFL = entradaFL;
	CriaObjTopologia();
	IniciaObjTopologia();
}
//---------------------------------------------------------------------------
void __fastcall TFL::CriaObjTopologia()
{
	String codigoRede = entradaFL->codigoRede;
	topologiaDMS = DLL_NewTopologiaDMS(apl, codigoRede);
}
//---------------------------------------------------------------------------
void __fastcall TFL::IniciaObjTopologia()
{
	topologiaDMS->IniciaTopologiaRede();
}
//---------------------------------------------------------------------------
