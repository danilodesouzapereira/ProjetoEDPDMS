//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TReligadora.h"
#include "TEqptoAutomacao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TReligadora::TReligadora(VTApl* apl, VTChave* chave) : TEqptoAutomacao(apl)
{
   this->chave = chave;
	tipoAutomacao = automacaoRELIGADORA;
}
//---------------------------------------------------------------------------
__fastcall TReligadora::~TReligadora()
{

}
//---------------------------------------------------------------------------
