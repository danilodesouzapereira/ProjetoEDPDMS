//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <PlataformaSinap\DLL_Inc\Ordena.h>
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Bloco\VTBloco.h>
#include <PlataformaSinap\Fontes\Bloco\VTBlocos.h>
#include <PlataformaSinap\Fontes\Bloco\VTElo.h>
#include <PlataformaSinap\Fontes\Ordena\VTOrdena.h>
#include <PlataformaSinap\Fontes\Rede\VTChave.h>
#include <PlataformaSinap\Fontes\Rede\VTEqpto.h>
#include <PlataformaSinap\Fontes\Rede\VTLigacao.h>
#include <PlataformaSinap\Fontes\Rede\VTRedes.h>
#include "TBlocoDMS.h"
#include "TTopologiaDMS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TTopologiaDMS::TTopologiaDMS(VTApl* apl)
{
	this->apl = apl;
	redes = (VTRedes*) apl->GetObject(__classid(VTRedes));
	blocos = (VTBlocos*) apl->GetObject(__classid(VTBlocos));

	lisBlocosDMS = new TList;
}
//---------------------------------------------------------------------------
__fastcall TTopologiaDMS::~TTopologiaDMS()
{
   // Destroi objetos
	for(int i=lisBlocosDMS->Count-1; i>=0; i--) delete lisBlocosDMS->Items[i];
	delete lisBlocosDMS; lisBlocosDMS = NULL;
}
//---------------------------------------------------------------------------
// Cria a topologia necessária para os módulos do DMS, com base nos objetos
// de rede já carregados previamente.
void __fastcall TTopologiaDMS::IniciaTopologiaRede(VTRede* rede)
{
	// Certifica se tem ordenação
	ordena = (VTOrdena*) apl->GetObject(__classid(VTOrdena));
	if(!ordena) apl->Add(ordena = DLL_NewObjOrdena(apl));
   ordena->Executa(redes);

	// Gera um blocoDMS para cada VTBloco, com informações adicionais
	DeterminaBlocosDMS(rede);

	// Faz a ordenação dos blocos DMS (blcosDMS pais e lista de blocos DMS filhos)
	OrdenaBlocosDMS();
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::DeterminaBlocosDMS(VTRede* rede)
{
	if(!rede) return;
	TList* lisBlocos = blocos->LisBloco();
	for(int i=0; i<lisBlocos->Count; i++)
	{
		VTBloco* bloco = (VTBloco*) lisBlocos->Items[i];
		if(bloco->Rede != rede) continue;

		// Cria objeto de blocoFL
		TBlocoDMS* blocoDMS = new TBlocoDMS();
		blocoDMS->bloco = bloco;
		blocoDMS->chave = ChaveBloco(bloco);
		lisBlocosDMS->Add(blocoDMS);
	}
}
//---------------------------------------------------------------------------
VTChave* __fastcall TTopologiaDMS::ChaveBloco(VTBloco* bloco)
{
	if(!bloco) return(NULL);

	// analisa cada elo que circunda o bloco
	TList* lisElos = blocos->LisElo();
	for(int i=0; i<lisElos->Count; i++)
	{
		VTElo* elo = (VTElo*) lisElos->Items[i];
		if(!elo->ConectaBloco(bloco)) continue;

		// ligação pai do elo
		VTLigacao* ligaPai = elo->Chave->ligaPai;

		// se ligação pai é nula, é chave inicial do circuito
		if(ligaPai == NULL) return(elo->Chave);
		while(ligaPai->Tipo() == eqptoCHAVE)
		{
			ligaPai = ligaPai->ligaPai;
			if(ligaPai == NULL) return(elo->Chave);
		}

		// Se o trecho a montante está no próprio bloco, então não é chave montante.
		if(bloco->ExisteLigacao(ligaPai)) continue;

		return(elo->Chave);
	}
	return(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::OrdenaBlocosDMS()
{
	for(int i=0; i<lisBlocosDMS->Count; i++)
	{
		TBlocoDMS* blocoDMS = (TBlocoDMS*) lisBlocosDMS->Items[i];

		// Obtém o primeiro trecho à montante do blocoDMS
		VTLigacao* ligaPai = blocoDMS->chave->ligaPai;
		if(ligaPai == NULL) {blocoDMS->blocoDMSmontante = NULL; continue;}
		while(ligaPai->Tipo() == eqptoCHAVE)
		{
			ligaPai = ligaPai->ligaPai;
			if(ligaPai == NULL) {blocoDMS->blocoDMSmontante = NULL; continue;}
		}

		// Encontra o blocoDMS que tem aquele trecho
		TBlocoDMS* blocoDMS_pai = NULL;
		for(int j=0; j<lisBlocosDMS->Count; j++)
		{
			blocoDMS_pai = (TBlocoDMS*) lisBlocosDMS->Items[j];
			if(blocoDMS_pai == blocoDMS) {blocoDMS_pai = NULL; continue;}
			if(blocoDMS_pai->bloco->ExisteLigacao(ligaPai))break;
			else blocoDMS_pai = NULL;
		}
		if(blocoDMS_pai)
		{
			blocoDMS->blocoDMSmontante = blocoDMS_pai;
			blocoDMS_pai->lisBlocoDMSjusante->Add(blocoDMS);
		}
		else  blocoDMS->blocoDMSmontante = NULL;
	}
}
//---------------------------------------------------------------------------
