//---------------------------------------------------------------------------
#pragma hdrstop
#include "enumeradores.h"
#include "TTopologiaDMS.h"
#include "TArea.h"
#include "TBlocoRad.h"
#include "TDisjuntor.h"
#include "TFusivel.h"
#include "TMedIntTrafo.h"
#include "TReligadora.h"
#include "TReleDisjuntor.h"
#include "TReleReligadora.h"
#include "TTrafo.h"
#include "..\Uteis\TMetodosAuxiliares.h"
#include "..\Uteis\Modelos.h"

#include "TTestes.h"
//---------------------------------------------------------------------------
#include <PlataformaSinap\DLL_Inc\Bloco.h>
#include <PlataformaSinap\DLL_Inc\Ordena.h>
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Diretorio\VTPath.h>
#include <PlataformaSinap\Fontes\BD\VTBD.h>
#include <PlataformaSinap\Fontes\BD\Rede\VTBDeqpto.h>
#include <PlataformaSinap\Fontes\BDihm\VTAbre.h>
#include <PlataformaSinap\Fontes\Bloco\VTBloco.h>
#include <PlataformaSinap\Fontes\Bloco\VTBlocos.h>
#include <PlataformaSinap\Fontes\Bloco\VTElo.h>
#include <PlataformaSinap\Fontes\Curvas\VTCurvas.h>
#include <PlataformaSinap\Fontes\Edita\VTEdita.h>
#include <PlataformaSinap\Fontes\Grafico\VTGrafico.h>
#include <PlataformaSinap\Fontes\Ordena\VTOrdena.h>
#include <PlataformaSinap\Fontes\Planejamento\VTPlanejamento.h>
#include <PlataformaSinap\Fontes\Potencia\VTDemanda.h>
#include <PlataformaSinap\Fontes\Rede\VTCarga.h>
#include <PlataformaSinap\Fontes\Rede\VTChave.h>
#include <PlataformaSinap\Fontes\Rede\VTDominio.h>
#include <PlataformaSinap\Fontes\Rede\VTLigacao.h>
#include <PlataformaSinap\Fontes\Rede\VTRede.h>
#include <PlataformaSinap\Fontes\Rede\VTRedes.h>
#include <PlataformaSinap\Fontes\Rede\VTTipoRede.h>

#include <PlataformaSinap\DLL_Inc\BDihm.h>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
VTTopologiaDMS* __fastcall NewObjTopologiaDMS(VTApl* apl, String codigoRede)
{
	return(new TTopologiaDMS(apl, codigoRede));
}
//---------------------------------------------------------------------------
__fastcall TTopologiaDMS::TTopologiaDMS(VTApl* apl, String codigoRede)
{
	// Obtém parâmetros elementares
	this->apl = apl;
	path = (VTPath*)apl->GetObject(__classid(VTPath));
	protecoesCoordenadas = true;

	// Inicializações
   area = NULL;
	disjuntor = NULL;
	lisBlocoRad = new TList;
	lisReligadoras = new TList;
	lisFusiveis = new TList;
	lisTrafos = new TList;
	lisCodSEs = new TStringList;  //< lista com os códigos das SEs presentes no MDB

	// Carrega redes do Sinap para extrair a topologia
	AbreRedesSinap(codigoRede);

	// Determina a rede MT em questão
	rede = DeterminaObjRede(codigoRede);
}
//---------------------------------------------------------------------------
__fastcall TTopologiaDMS::~TTopologiaDMS(void)
{
	// Destroi objetos
	DestroiEqptosTopologia();
   delete lisCodSEs;
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::Verifica_VTOrdena()
{
	VTOrdena* ordena = (VTOrdena*) apl->GetObject(__classid(VTOrdena));
	if(!ordena)
	{
		apl->Add(ordena = DLL_NewObjOrdena(apl));
		VTRedes* redes = (VTRedes*) apl->GetObject(__classid(VTRedes));
		ordena->Executa(redes);
	}
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::AbreRedesSinap(String codigoAlimentador)
{
	if(codigoAlimentador == "") return;

	// Pega os nomes de todos os MDBs disponíveis
	TStringList* lisAux_nomesMDBs = new TStringList;
	String pathDirRedes = path->DirRedes();
	NomesArquivosDiretorio(pathDirRedes, "mdb", lisAux_nomesMDBs);

	String nomeArquivo = "";
	String codSE = "";
	for(int i=0; i<lisAux_nomesMDBs->Count; i++)
	{
		nomeArquivo = lisAux_nomesMDBs->Strings[i];

		// Carrega os códigos das subestações presentes no MDB
		String pathMDB = pathDirRedes + "\\" + nomeArquivo;
		CarregaCodigosSubestacoes(pathMDB, false);

		codSE = "";
		for(int j=0; j<lisCodSEs->Count; j++)
		{
			codSE = lisCodSEs->Strings[j];
			if(AlimentadorPertenceSubestacao(codSE, codigoAlimentador))
				break;
			else
				codSE = "";
		}
		if(codSE == "") nomeArquivo = "";
		else break;
	}

	// Abre a rede MT em questão
	if(nomeArquivo != "")
	{
		String pathMDB = pathDirRedes + "\\" + nomeArquivo;
		CarregaRede(pathMDB, codSE, codigoAlimentador);
	}

	delete lisAux_nomesMDBs;
}
//---------------------------------------------------------------------------
bool __fastcall TTopologiaDMS::CarregaRede(AnsiString arq_mdb, AnsiString codigoSE, AnsiString codigoAlimentador)
{
   bool         sucesso = false;
   VTAbre       *abre;
	VTGrafico    *grafico = (VTGrafico*)apl->GetObject(__classid(VTGrafico));
	VTPath       *path    = (VTPath*)apl->GetObject(__classid(VTPath));
	VTRedes      *redes   = (VTRedes*)apl->GetObject(__classid(VTRedes));
   VTEdita      *edita   = (VTEdita*)apl->GetObject(__classid(VTEdita));
   VTDemanda    *demanda = (VTDemanda*)apl->GetObject(__classid(VTDemanda));
   VTCurvas     *curvas  = (VTCurvas*)apl->GetObject(__classid(VTCurvas));

   try
   {
		if (! FileExists(arq_mdb)) return(false);

		//reinicia o objeto VTRedes (destrói todas as redes carregadas)
		edita->UndoCompleto();
		redes->Clear();

      path->ArqRede = arq_mdb;

      if ((abre = DLL_NewObjAbre(NULL, apl)) != NULL)
      {
         abre->IniciaConexao(NULL);
         abre->ValidaBaseRede();

         redes = (VTRedes*) abre->apl->GetObject(__classid(VTRedes));

         if(redes->LisDominio()->Count == 0)
            return(false);
         VTDominio* dominio = (VTDominio*) redes->LisDominio()->Items[0];
         VTPlanejamento *planejamento = (VTPlanejamento*)abre->apl->GetObject(__classid(VTPlanejamento));
         VTEstudo* estudo_zero = planejamento->InsereEstudoRedeOriginal();
         VTBD *bd = (VTBD*)abre->apl->GetObject(__classid(VTBD));
         bd->Eqpto->LeListaRede(estudo_zero, dominio);

         // Seleciona as redes (SE e redes MT)
         for(int i=0; i<dominio->LisRede()->Count; i++)
         {
            VTRede* rede = (VTRede*) dominio->LisRede()->Items[i];

            if(rede->TipoRede->Segmento == redeETD && codigoSE.AnsiCompare(rede->Codigo) == 0)
            {
               abre->SelecaoInsereRede(rede);
            }
				else if(rede->TipoRede->Segmento == redePRI &&
						  AnsiContainsStr(rede->Codigo, codigoSE) &&
						  AlimentadoresIguais(rede->Codigo, codigoAlimentador))
				{
               abre->SelecaoInsereRede(rede);
            }
         }
         abre->CarregaRedeSelecionada();

         //define mês de referência de Curvas (para corrigir fator de correção de energia)
         curvas->DataReferencia = redes->DataReferencia;
         //define mês de referência da Demanda (para determinar dias do mês no cálculo da demanda média)
         demanda->DataReferencia = redes->DataReferencia;

         //destrói objeto
         delete abre;
      }

      grafico->AreaRedeDefine();
   }
   catch(Exception &e)
   {
      sucesso = false;
   }
   grafico->Refresh();

	return(sucesso);
}
//---------------------------------------------------------------------------
bool __fastcall TTopologiaDMS::CarregaCodigosSubestacoes(AnsiString arq_mdb, bool atualiza_grafico)
{
	VTAbre         *abre;
	VTBD           *bd;
	VTDominio      *dominio;
	VTEstudo       *estudo_zero;
	VTPlanejamento *planejamento;
	VTRedes        *redes;

	path = (VTPath*)apl->GetObject(__classid(VTPath));
	path->ArqRede = arq_mdb;
	lisCodSEs->Clear();

	if ((abre = DLL_NewObjAbre(NULL, apl)) != NULL)
	{
		if(abre->IniciaConexao(NULL))
		{
			abre->ValidaBaseRede();
		}
		redes = (VTRedes*) abre->apl->GetObject(__classid(VTRedes));

      if(redes->LisDominio()->Count == 0)
         return(false);

      dominio = (VTDominio*) redes->LisDominio()->Items[0];
      planejamento = (VTPlanejamento*)abre->apl->GetObject(__classid(VTPlanejamento));
      estudo_zero = planejamento->InsereEstudoRedeOriginal();
      bd = (VTBD*)abre->apl->GetObject(__classid(VTBD));
      bd->Eqpto->LeListaRede(estudo_zero, dominio);

      // Guarda structs com as redes por SE
      for(int i=0; i<dominio->LisRede()->Count; i++)
      {
         VTRede* redeSE = (VTRede*) dominio->LisRede()->Items[i];
         if(redeSE->TipoRede->Segmento != redeETD) continue;

         String codigoSE = redeSE->Codigo;
         lisCodSEs->Add(codigoSE);
      }
   }
   delete abre;
}
//---------------------------------------------------------------------------
VTRede* __fastcall TTopologiaDMS::DeterminaObjRede(String codigoRede)
{
	VTRedes* redes = (VTRedes*)apl->GetObject(__classid(VTRedes));
	TList* lisRedes = redes->LisRede();
	for(int i=0; i<lisRedes->Count; i++)
	{
		VTRede* rede = (VTRede*) lisRedes->Items[i];
		if(!rede->Carregada || rede->TipoRede->Segmento != redePRI) continue;
		if(rede->Codigo.AnsiCompare(codigoRede) == 0)
			return(rede);
	}
	return(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::DestroiEqptosTopologia()
{
	// Destroi objetos de trafos
	for(int i=lisTrafos->Count-1; i>=0; i--)
	{
		TTrafo* trafo = (TTrafo*)lisTrafos->Items[i];
		delete trafo;
	}
	delete lisTrafos;

	// Destroi objetos de religadoras
	for(int i=lisReligadoras->Count-1; i>=0; i--)
	{
		TReligadora* religadora = (TReligadora*)lisReligadoras->Items[i];
		delete religadora;
	}
	delete lisReligadoras;

	// Destroi objetos de fusíveis
	for(int i=lisFusiveis->Count-1; i>=0; i--)
	{
		TFusivel* fusivel = (TFusivel*)lisFusiveis->Items[i];
		delete fusivel;
	}
	delete lisFusiveis;

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
void __fastcall TTopologiaDMS::IniciaTopologiaRede(Processo* processoFL)
{
	// Certifica se tem ordenação
	Verifica_VTOrdena();

	// Gera um bloco radial (TBlocoRad) para cada VTBloco, com informações adicionais
	DeterminaBlocosRadiais();

	// Faz a ordenação dos blocos radiais (blocos radiais pais e lista de blocos radiais filhos)
	OrdenaBlocosRadiais();

	// Instancia objetos que modelam equipamentos de automação (TDisjuntor e TReligadora)
	CriaObjEqptosAutomacao();

	// Determina os blocos radiais (TBlocoRad) à jusante de cada TDisjuntor, TReligadora e TFusivel
	DeterminaBlocosRadJusanteEqptosAutomacao();

	// Determina os blocos radiais (TBlocoRad) da zona de proteção de cada TDisjuntor, TReligadora e TFusivel
	DeterminaBlocosRadZonaProtecaoEqptosAutomacao();

	// Instancia objetos que modelam trafos MT/BT e cargas A4 (TTrafo)
	CriaObjEqptosTrafos();

	// Instancia objetos de relés e medidores inteligentes
	CriaObjEqptosDado(processoFL);
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::DeterminaBlocosRadJusanteEqptosAutomacao()
{
	VTLigacao* ligacao;

	// DISJUNTOR
	ligacao = disjuntor->chave;
	BUSCA_BlocosRadJusanteLigacao(ligacao, disjuntor->lisBlocosRad_Jusante);

	// RELIGADORAS
	for(int i=0; i<lisReligadoras->Count; i++)
	{
		TReligadora* religadora = (TReligadora*) lisReligadoras->Items[i];
		ligacao = religadora->chave;
		BUSCA_BlocosRadJusanteLigacao(ligacao, religadora->lisBlocosRad_Jusante);
	}

	// FUSÍVEIS
	for(int i=0; i<lisFusiveis->Count; i++)
	{
		TFusivel* fusivel = (TFusivel*) lisFusiveis->Items[i];
		ligacao = fusivel->chave;
		BUSCA_BlocosRadJusanteLigacao(ligacao, fusivel->lisBlocosRad_Jusante);
	}
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::DeterminaBlocosRadZonaProtecaoEqptosAutomacao()
{
	// Copia todos os blocos radiais para a lista da zona de proteção
	CopiaObjetos(disjuntor->lisBlocosRad_Jusante, disjuntor->lisBlocosRad_ZonaProtecao);
	for(int i=0; i<lisReligadoras->Count; i++)
	{
		TReligadora* religadora = (TReligadora*) lisReligadoras->Items[i];
		CopiaObjetos(religadora->lisBlocosRad_Jusante, religadora->lisBlocosRad_ZonaProtecao);
	}
	for(int i=0; i<lisFusiveis->Count; i++)
	{
		TFusivel* fusivel = (TFusivel*) lisFusiveis->Items[i];
		CopiaObjetos(fusivel->lisBlocosRad_Jusante, fusivel->lisBlocosRad_ZonaProtecao);
	}

	// Remove os blocos radiais das proteções à jusante
	RemoveBlocosRad_ProtJusanteDisjuntor();
	for(int i=0; i<lisReligadoras->Count; i++)
	{
		TReligadora* religadora = (TReligadora*) lisReligadoras->Items[i];
		RemoveBlocosRad_ProtJusanteReligadora(religadora);
	}
	for(int i=0; i<lisFusiveis->Count; i++)
	{
		TFusivel* fusivel = (TFusivel*) lisFusiveis->Items[i];
		RemoveBlocosRad_ProtJusanteFusivel(fusivel);
	}
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::RemoveBlocosRad_ProtJusanteDisjuntor()
{
	for(int i=0; i<lisReligadoras->Count; i++)
	{
		TReligadora* religadora = (TReligadora*) lisReligadoras->Items[i];
		SubtraiBlocosRad(disjuntor->lisBlocosRad_ZonaProtecao, religadora->lisBlocosRad_Jusante);
	}
	for(int i=0; i<lisFusiveis->Count; i++)
	{
		TFusivel* fusivel = (TFusivel*) lisFusiveis->Items[i];
		SubtraiBlocosRad(disjuntor->lisBlocosRad_ZonaProtecao, fusivel->lisBlocosRad_Jusante);
	}
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::RemoveBlocosRad_ProtJusanteReligadora(TReligadora* religadora)
{
	// Remove os blocos radiais dos fusíveis à jusante
	for(int j=0; j<lisFusiveis->Count; j++)
	{
		TFusivel* fusivel = (TFusivel*) lisFusiveis->Items[j];

		if(fusivel->lisBlocosRad_Jusante->Count < religadora->lisBlocosRad_Jusante->Count)
		{
			SubtraiBlocosRad(religadora->lisBlocosRad_ZonaProtecao, fusivel->lisBlocosRad_Jusante);
		}
	}

	// Remove os blocos radiais das religadoras à jusante
	for(int j=0; j<lisReligadoras->Count; j++)
	{
		TReligadora* religadora2 = (TReligadora*) lisReligadoras->Items[j];
		if(religadora2 == religadora) continue;

		if(religadora2->lisBlocosRad_Jusante->Count < religadora->lisBlocosRad_Jusante->Count)
		{
			SubtraiBlocosRad(religadora->lisBlocosRad_ZonaProtecao, religadora2->lisBlocosRad_Jusante);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::RemoveBlocosRad_ProtJusanteFusivel(TFusivel* fusivel)
{
	// Remove os blocos radiais dos fusíveis à jusante
	for(int j=0; j<lisFusiveis->Count; j++)
	{
		TFusivel* fusivel2 = (TFusivel*) lisFusiveis->Items[j];
		if(fusivel2 == fusivel) continue;

		if(fusivel2->lisBlocosRad_Jusante->Count < fusivel->lisBlocosRad_Jusante->Count)
		{
			SubtraiBlocosRad(fusivel->lisBlocosRad_ZonaProtecao, fusivel2->lisBlocosRad_Jusante);
		}
	}

	// Remove os blocos radiais das religadoras à jusante
	for(int j=0; j<lisReligadoras->Count; j++)
	{
		TReligadora* religadora = (TReligadora*) lisReligadoras->Items[j];
		if(religadora->lisBlocosRad_Jusante->Count < fusivel->lisBlocosRad_Jusante->Count)
		{
			SubtraiBlocosRad(fusivel->lisBlocosRad_ZonaProtecao, religadora->lisBlocosRad_Jusante);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::SubtraiBlocosRad(TList* lisBlocosRad_maior, TList* lisBlocosRad_menor)
{
	if(!lisBlocosRad_maior || !lisBlocosRad_menor) return;
	for(int j=0; j<lisBlocosRad_menor->Count; j++)
	{
		TBlocoRad* blocoRad = (TBlocoRad*) lisBlocosRad_menor->Items[j];
		if(lisBlocosRad_maior->IndexOf(blocoRad) >= 0)
			lisBlocosRad_maior->Remove(blocoRad);
	}
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::CriaObjEqptosAutomacao()
{
	TFusivel* fusivel;
	TReligadora* religadora;

	// Para cada disjuntor/religadora/fusível da rede, cria um objeto:
	// TDisjuntor, TReligadora ou TFusivel
	for(int i=0; i<lisBlocoRad->Count; i++)
	{
		TBlocoRad* blocoRad = (TBlocoRad*)lisBlocoRad->Items[i];

		if(blocoRad->chavePai->TipoDisjuntor)
		{
			disjuntor = new TDisjuntor(apl, blocoRad->chavePai);
		}
		else if(blocoRad->chavePai->TipoReligadora)
		{
			religadora = new TReligadora(apl, blocoRad->chavePai);
			lisReligadoras->Add(religadora);
		}
		else if(blocoRad->chavePai->TipoBaseFusivel)
		{
			fusivel = new TFusivel(apl, blocoRad->chavePai);
			lisFusiveis->Add(fusivel);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::CriaObjEqptosTrafos()
{
	TList* lisCargasRede = new TList;
	rede->LisEqpto(lisCargasRede, eqptoCARGA);

	// Para cada carga equivalente (trafo MT/BT), gera um objeto
	// de TTrafo
	for(int i=0; i<lisCargasRede->Count; i++)
	{
		VTCarga* carga = (VTCarga*)lisCargasRede->Items[i];

		// Pega trafos MT/BT
		if(AnsiContainsStr(carga->Codigo, "ET"))
		{
			TTrafo* trafo = new TTrafo(apl, carga);
			lisTrafos->Add(trafo);
		}
   }
	delete lisCargasRede;
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::CriaObjEqptosDado(Processo* processoFL)
{
	if(!processoFL) return;

	for(int i=0; i<processoFL->listaAlarmes->Count; i++)
	{
		Alarme* alarme = (Alarme*)processoFL->listaAlarmes->Items[i];

		if(alarme->tipoEqpto == 10) // Disjuntor
		{
			disjuntor->rele = new TReleDisjuntor(apl, disjuntor);
			disjuntor->rele->lisAlarmes->Add(alarme);
		}
		else if(alarme->tipoEqpto == 11) // Religadora
		{
			TReligadora* religadora = Religadora_Codigo(alarme->codigoEqpto);
			if(religadora)
			{
				religadora->rele = new TReleReligadora(apl, religadora);
				religadora->rele->lisAlarmes->Add(alarme);
			}
		}
		else if(alarme->tipoEqpto == 12) // Medidor inteligente de transformador
		{
			TTrafo* trafo = Trafo_Codigo(alarme->codigoEqpto);
			if(trafo)
			{
				trafo->medIntTrafo = new TMedIntTrafo(apl, trafo);
            trafo->medIntTrafo->lisAlarmes->Add(alarme);
			}
		}
	}
}
//---------------------------------------------------------------------------
TReligadora* __fastcall TTopologiaDMS::Religadora_Codigo(String codigoReligadora)
{
	if(codigoReligadora == "") return(NULL);
	for(int i =0; i<lisReligadoras->Count; i++)
	{
		TReligadora* religadora = (TReligadora*) lisReligadoras->Items[i];
		if(ChavesIguais(religadora->chave->Codigo, codigoReligadora))
			return(religadora);
	}
	return(NULL);
}
//---------------------------------------------------------------------------
TTrafo* __fastcall TTopologiaDMS::Trafo_Codigo(String codigoTrafo)
{
	if(codigoTrafo == "") return(NULL);
	for(int i =0; i<lisTrafos->Count; i++)
	{
		TTrafo* trafo = (TTrafo*) lisTrafos->Items[i];
		if(TrafosIguais(trafo->carga->Codigo, codigoTrafo))
			return(trafo);
	}
	return(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::AnalisaTiposAlarmesProtecao(TList* lisAux_Eqptos_Lockout, TList* lisAux_Eqptos_TentRelig)
{
	// Disjuntor
	for(int i=0; i<disjuntor->rele->lisAlarmes->Count; i++)
	{
		Alarme* alarme = (Alarme*)disjuntor->rele->lisAlarmes->Items[i];
		if(alarme->tipoAlarme == 20 && lisAux_Eqptos_TentRelig->IndexOf(disjuntor) == -1) // relig
			lisAux_Eqptos_TentRelig->Add(disjuntor);
		else if(alarme->tipoAlarme == 21 && lisAux_Eqptos_Lockout->IndexOf(disjuntor) == -1) // lock-out
			lisAux_Eqptos_Lockout->Add(disjuntor);
	}

	// Religadoras
	for(int i=0; i<lisReligadoras->Count; i++)
	{
		TReligadora* religadora = (TReligadora*)lisReligadoras->Items[i];

		for(int j=0; j<religadora->rele->lisAlarmes->Count; j++)
		{
			Alarme* alarme = (Alarme*)religadora->rele->lisAlarmes->Items[j];
			if(alarme->tipoAlarme == 20 && lisAux_Eqptos_TentRelig->IndexOf(religadora) == -1) // relig
				lisAux_Eqptos_TentRelig->Add(religadora);
			else if(alarme->tipoAlarme == 21 && lisAux_Eqptos_Lockout->IndexOf(religadora) == -1) // lock-out
				lisAux_Eqptos_Lockout->Add(religadora);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::DeterminaAreaBuscaFalta()
{

	TList* lisAux_Eqptos_Lockout = new TList;
	TList* lisAux_Eqptos_TentRelig = new TList;

	// Disjuntores e religadoras atuantes:
	AnalisaTiposAlarmesProtecao(lisAux_Eqptos_Lockout, lisAux_Eqptos_TentRelig);

	if(protecoesCoordenadas)  // Considerando que há coordenação entre as proteções
	{
		if(lisAux_Eqptos_Lockout->Count == 1)
		{
			TEqptoAutomacao* eqptoAutomacao = (TEqptoAutomacao*)lisAux_Eqptos_Lockout->Items[0];
			if(eqptoAutomacao->tipoAutomacao == automacaoDISJUNTOR)
			{
				TDisjuntor* disjuntor = (TDisjuntor*) eqptoAutomacao;
				area = new TArea(apl, disjuntor->lisBlocosRad_ZonaProtecao);
			}
			else if(eqptoAutomacao->tipoAutomacao == automacaoRELIGADORA)
			{
				TReligadora* religadora = (TReligadora*) eqptoAutomacao;
				area = new TArea(apl, religadora->lisBlocosRad_ZonaProtecao);
			}
      }
	}
	else // Considerando que não há coordenação entre as proteções
	{

	}

	delete lisAux_Eqptos_Lockout;  delete lisAux_Eqptos_TentRelig;
}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::DeterminaAreaBuscaRompCabo(Processo* processoFL)
{
//	if(!processoFL) return;
//	if(!AlimentadoresIguais(processoFL->codigoAlimentador, rede->Codigo)) return;


}
//---------------------------------------------------------------------------
void __fastcall TTopologiaDMS::FinalizaTopologiaRede()
{
   VTEdita      *edita   = (VTEdita*)apl->GetObject(__classid(VTEdita));
   VTRedes      *redes   = (VTRedes*)apl->GetObject(__classid(VTRedes));
	VTGrafico    *grafico = (VTGrafico*)apl->GetObject(__classid(VTGrafico));

   edita->UndoCompleto();
   redes->Clear();
   grafico->AreaRedeDefine();
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
