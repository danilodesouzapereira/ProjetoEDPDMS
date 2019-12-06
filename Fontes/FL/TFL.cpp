//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <ProjetoEDPDMS\Fontes\TopologiaDMS\TTopologiaDMS.h>
#include <ProjetoEDPDMS\Fontes\DMS\Modelos.h>
#include "TFL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TFL::TFL(TTopologiaDMS* topologiaDMS)
{
	this->topologiaDMS = topologiaDMS;
}
//---------------------------------------------------------------------------
__fastcall TFL::~TFL()
{

}
//---------------------------------------------------------------------------
void __fastcall TFL::IniciarProcesso(EntradaFL* entradaFL)
{
	this->entradaFL = entradaFL;
}
//---------------------------------------------------------------------------
