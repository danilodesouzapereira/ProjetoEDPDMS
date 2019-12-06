//---------------------------------------------------------------------------
#pragma hdrstop
#include "TTopologiaDMS.h"
#include "TBlocoRad.h"
#include "TReligadora.h"

#include "TTestes.h"
//---------------------------------------------------------------------------
#include <PlataformaSinap\DLL_Inc\Bloco.h>
#include <PlataformaSinap\DLL_Inc\Ordena.h>
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Bloco\VTBloco.h>
#include <PlataformaSinap\Fontes\Bloco\VTBlocos.h>
#include <PlataformaSinap\Fontes\Bloco\VTElo.h>
#include <PlataformaSinap\Fontes\Ordena\VTOrdena.h>
#include <PlataformaSinap\Fontes\Rede\VTChave.h>
#include <PlataformaSinap\Fontes\Rede\VTLigacao.h>
#include <PlataformaSinap\Fontes\Rede\VTRede.h>
#include <PlataformaSinap\Fontes\Rede\VTRedes.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TTopologiaDMS::TTopologiaDMS(VTApl* apl, VTRede* rede)
{
	// Obtém parâmetros elementares
	this->apl = apl;
	this->rede = rede;

	// Inicializações
	disjuntor = NULL;
	lisBlocoRad = new TList;
	lisReligadoras = new TList;

	IniciaTopologiaRede();
}
//---------------------------------------------------------------------------
__fastcall TTopologiaDMS::~TTopologiaDMS()
{
	// Destroi objetos
	DestroiEqptosTopologia();
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::DestroiEqptosTopologia()
{
	// Destroi objetos de religadoras
	for(int i=lisReligadoras->Count-1; i>=0; i--)
	{
		TReligadora* religadora = (TReligadora*)lisReligadoras->Items[i];
		delete religadora;
	}
	delete lisReligadoras;

	if(disjuntor) delete disjuntor;

	// Destroi objetos de bloco radial
	for(int i=lisBlocoRad->Count-1; i>=0; i--)
	{
		TBlocoRad* blocoRad = (TBlocoRad*)lisBlocoRad->Items[i];
		delete blocoRad;
	}
	delete lisBlocoRad;
}
//---------------------------------------------------------------------------
// Cria a topologia necessária para os módulos do DMS, com base nos objetos
// de rede já carregados previamente.
void __fastcall TTopologiaDMS::IniciaTopologiaRede()
{
	// Certifica se tem ordenação
	VTOrdena* ordena = (VTOrdena*) apl->GetObject(__classid(VTOrdena));
	if(!ordena)
	{
		apl->Add(ordena = DLL_NewObjOrdena(apl));
		VTRedes* redes = (VTRedes*) apl->GetObject(__classid(VTRedes));
		ordena->Executa(redes);
	}

	// Gera um bloco radial (TBlocoRad) para cada VTBloco, com informações adicionais
	DeterminaBlocosRadiais();

	// Faz a ordenação dos blocos radiais (blocos radiais pais e lista de blocos radiais filhos)
	OrdenaBlocosRadiais();
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::DeterminaBlocosRadiais()
{
	VTBlocos* blocos = (VTBlocos*) apl->GetObject(__classid(VTBlocos));
	if(!blocos)
	{
		VTRedes* redes = (VTRedes*) apl->GetObject(__classid(VTRedes));
		apl->Add(blocos = DLL_NewObjBlocos());
		blocos->Executa(redes);
	}
	TList* lisBlocos = blocos->LisBloco();

	for(int i=0; i<lisBlocos->Count; i++)
	{
		VTBloco* bloco = (VTBloco*) lisBlocos->Items[i];
		if(bloco->Rede != rede) continue;

		// Cria objeto de TBlocoRad
		TBlocoRad* blocoRad = new TBlocoRad(apl);
		blocoRad->bloco = bloco;
		blocoRad->chavePai = ChaveBloco(bloco);
		lisBlocoRad->Add(blocoRad);
	}
}
//---------------------------------------------------------------------------
// Método para fazer a ordenação dos blocos radiais (blocos radiais pais e lista
// de blocos radiais filhos)
void __fastcall TTopologiaDMS::OrdenaBlocosRadiais()
{
	for(int i=0; i<lisBlocoRad->Count; i++)
	{
		TBlocoRad* blocoRad = (TBlocoRad*) lisBlocoRad->Items[i];

		// Obtém o primeiro trecho à montante do bloco radial
		VTLigacao* ligaPai = blocoRad->chavePai->ligaPai;
		if(ligaPai == NULL) {blocoRad->blocoRadPai = NULL; continue;}
		while(ligaPai->Tipo() == eqptoCHAVE)
		{
			ligaPai = ligaPai->ligaPai;
			if(ligaPai == NULL) {blocoRad->blocoRadPai = NULL; continue;}
		}

		// Encontra o bloco radial que tem aquele trecho
		TBlocoRad* blocoRad_pai = NULL;
		for(int j=0; j<lisBlocoRad->Count; j++)
		{
			blocoRad_pai = (TBlocoRad*) lisBlocoRad->Items[j];
			if(blocoRad_pai == blocoRad) {blocoRad_pai = NULL; continue;}
			if(blocoRad_pai->bloco->ExisteLigacao(ligaPai))break;
			else blocoRad_pai = NULL;
		}
		if(blocoRad_pai)
		{
			blocoRad->blocoRadPai = blocoRad_pai;
			blocoRad_pai->lisBlocoRadFilho->Add(blocoRad);
		}
		else  blocoRad->blocoRadPai = NULL;
	}
}
//---------------------------------------------------------------------------
VTChave* __fastcall TTopologiaDMS::ChaveBloco(VTBloco* bloco)
{
	if(!bloco) return(NULL);

	// Analisa cada elo que circunda o bloco
	VTBlocos* blocos = (VTBlocos*) apl->GetObject(__classid(VTBlocos));
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
void __fastcall TTopologiaDMS::BUSCA_BlocosRadJusanteLigacao(String codigoLigacao, TList* lisEXT)
{
	if(codigoLigacao == "" || !lisEXT) return;

	TList* lisLigacao = rede->LisLigacao();
	VTLigacao* ligacao = NULL;
	for(int i=0; i<lisLigacao->Count; i++)
	{
		ligacao = (VTLigacao*) lisLigacao->Items[i];
		if(ligacao->Codigo.AnsiCompare(codigoLigacao) == 0)
			break;
		else
			ligacao = NULL;
	}
	if(!ligacao) return;

	BUSCA_BlocosRadJusanteLigacao(ligacao, lisEXT);
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::BUSCA_BlocosRadJusanteLigacao(VTLigacao* ligacao, TList* lisEXT)
{
	if(!ligacao || !lisEXT) return;

	TBlocoRad* blocoRad = NULL;
	for(int i=0; i<lisBlocoRad->Count; i++)
	{
		blocoRad = (TBlocoRad*) lisBlocoRad->Items[i];

		if(blocoRad->chavePai == ligacao)
         break;

		if(blocoRad->bloco->LisLigacao()->IndexOf(ligacao) != -1)
			break;
		else
			blocoRad = NULL;
	}
	if(!blocoRad) return;

	TList* listaBlocosRadAnalisar = new TList;
	TList* listaBlocosRadAdicionar = new TList;

	for(int i=0; i<blocoRad->lisBlocoRadFilho->Count; i++)
	{
		TBlocoRad* blocoRadFilho = (TBlocoRad*) blocoRad->lisBlocoRadFilho->Items[i];
		listaBlocosRadAnalisar->Add(blocoRadFilho);
		lisEXT->Add(blocoRadFilho);
	}

	while(listaBlocosRadAnalisar->Count > 0)
	{
		for(int i=listaBlocosRadAnalisar->Count-1; i>=0; i--)
		{
			TBlocoRad* blocoRad = (TBlocoRad*) listaBlocosRadAnalisar->Items[i];
			for(int j=0; j<blocoRad->lisBlocoRadFilho->Count; j++)
			{
				TBlocoRad* blocoRadFilho = (TBlocoRad*)blocoRad->lisBlocoRadFilho->Items[j];
				listaBlocosRadAdicionar->Add(blocoRadFilho);
			}
			listaBlocosRadAnalisar->Remove(blocoRad);
		}

		for(int i=listaBlocosRadAdicionar->Count-1; i>=0; i--)
		{
			TBlocoRad* blocoRad = (TBlocoRad*) listaBlocosRadAdicionar->Items[i];
			lisEXT->Add(blocoRad);

			listaBlocosRadAdicionar->Remove(blocoRad);
			listaBlocosRadAnalisar->Add(blocoRad);
		}
	}


	delete listaBlocosRadAnalisar;
	delete listaBlocosRadAdicionar;
}
//---------------------------------------------------------------------------
