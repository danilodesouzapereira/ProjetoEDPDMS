//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TDisjuntor.h"
#include "TEqptoAutomacao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TDisjuntor::TDisjuntor(VTApl* apl, VTChave* chave) : TEqptoAutomacao(apl)
{
	tipoAutomacao = automacaoDISJUNTOR;
	this->chave = chave;
}
//---------------------------------------------------------------------------
__fastcall TDisjuntor::~TDisjuntor()
{

}
//---------------------------------------------------------------------------
