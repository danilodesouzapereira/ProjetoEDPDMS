//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Rede\VTRedes.h>
#include "TEE.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TEE::TEE(VTApl* apl)
{
	this->apl = apl;
	redes = (VTRedes*) apl->GetObject(__classid(VTRedes));
}
//---------------------------------------------------------------------------
__fastcall TEE::~TEE()
{

}
//---------------------------------------------------------------------------
void __fastcall TEE::ExecutaEstimacaoDiaria()
{

}
//---------------------------------------------------------------------------
