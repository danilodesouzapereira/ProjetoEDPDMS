//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TDisjuntor.h"
#include "TEqptoAutomacao.h"
#include "TReleDisjuntor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TDisjuntor::TDisjuntor(VTApl* apl, VTChave* chave) : TEqptoAutomacao(apl)
{
	tipoAutomacao = automacaoDISJUNTOR;
	this->chave = chave;
	rele = NULL;

	// Listas de objetos TBlocoRad
	lisBlocosRad_Jusante = new TList;
	lisBlocosRad_ZonaProtecao = new TList;
}
//---------------------------------------------------------------------------
__fastcall TDisjuntor::~TDisjuntor()
{
	delete lisBlocosRad_Jusante;
	delete lisBlocosRad_ZonaProtecao;
}
//---------------------------------------------------------------------------
