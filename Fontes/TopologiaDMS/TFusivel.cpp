//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TFusivel.h"
#include "TEqptoAutomacao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TFusivel::TFusivel(VTApl* apl, VTChave* chave) : TEqptoAutomacao(apl)
{
	tipoAutomacao = automacaoFUSIVEL;
	this->chave = chave;

	// Listas de objetos TBlocoRad
	lisBlocosRad_Jusante = new TList;
	lisBlocosRad_ZonaProtecao = new TList;
}
//---------------------------------------------------------------------------
__fastcall TFusivel::~TFusivel()
{
	delete lisBlocosRad_Jusante;
	delete lisBlocosRad_ZonaProtecao;
}
//---------------------------------------------------------------------------
