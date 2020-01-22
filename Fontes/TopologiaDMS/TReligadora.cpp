//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TReligadora.h"
#include "TEqptoAutomacao.h"
#include "TReleReligadora.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TReligadora::TReligadora(VTApl* apl, VTChave* chave) : TEqptoAutomacao(apl)
{
   this->chave = chave;
	tipoAutomacao = automacaoRELIGADORA;
	rele = NULL;

	// Listas de objetos TBlocoRad
	lisBlocosRad_Jusante = new TList;
	lisBlocosRad_ZonaProtecao = new TList;
}
//---------------------------------------------------------------------------
__fastcall TReligadora::~TReligadora()
{
	delete lisBlocosRad_Jusante;
	delete lisBlocosRad_ZonaProtecao;
}
//---------------------------------------------------------------------------
