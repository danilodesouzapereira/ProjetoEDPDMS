//---------------------------------------------------------------------------
#pragma hdrstop
#include "TTestes.h"
#include <PlataformaSinap\DLL_Inc\Grafico.h>
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Grafico\VTGrafico.h>
#include <PlataformaSinap\Fontes\Rede\VTLigacao.h>
#include <PlataformaSinap\Fontes\Rede\VTRedes.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TTestes::TTestes(VTApl* apl)
{
	this->apl = apl;
	grafico = (VTGrafico*) apl->GetObject(__classid(VTGrafico));
	if(!grafico)
	{
		grafico = DLL_NewObjGrafico(apl);
	}
	redes = (VTRedes*) apl->GetObject(__classid(VTRedes));
}
//---------------------------------------------------------------------------
__fastcall TTestes::~TTestes()
{
	grafico->DestacaEqpto(NULL, clBlue, 20.);
}
//---------------------------------------------------------------------------
void __fastcall TTestes::MostrarLigacoes(String pathArquivoLigacoes)
{
	if(pathArquivoLigacoes == "") return;

	TStringList* lisLinhas = new TStringList;
	lisLinhas->LoadFromFile(pathArquivoLigacoes);

	TList* lisTodasLigacoes = new TList;
	TList* lisEqptos = new TList;
	redes->LisLigacao(lisTodasLigacoes, eqptoLIGACAO);
	for(int i=0; i<lisLinhas->Count; i++)
	{
		String codLigacao = lisLinhas->Strings[i];
		VTLigacao* liga = NULL;
		for(int j=0; j<lisTodasLigacoes->Count; j++)
		{
			liga = (VTLigacao*) lisTodasLigacoes->Items[j];
			if(liga->Codigo == codLigacao)
				break;
			else
				liga = NULL;
		}
		if(!liga) continue;
		lisEqptos->Add(liga);
	}

	grafico->DestacaEqpto(NULL, clBlue, 20.);
	grafico->DestacaEqpto(lisEqptos, clBlue, 20.);

	delete lisLinhas;
	delete lisTodasLigacoes;
	delete lisEqptos;
}
//---------------------------------------------------------------------------
