//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TFL.h"
#include "TDMS.h"
#include <ProjetoEDPDMS\DLL_Inc\TopologiaDMS.h>
#include <ProjetoEDPDMS\Fontes\TopologiaDMS\VTTopologiaDMS.h>
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
VTFL* __fastcall NewObjFL(VTApl *apl)
{
	return(new TFL(apl));
}
//---------------------------------------------------------------------------
__fastcall TFL::TFL(VTApl* apl)
{
	this->apl = apl;
	tipoLocalizacao = algoLFindef;
	topologiaDMS = NULL;
	saidaFL = NULL;
	processoFL = NULL;
}
//---------------------------------------------------------------------------
__fastcall TFL::~TFL(void)
{
   // Destroi objetos
	if(topologiaDMS) delete topologiaDMS;
}
//---------------------------------------------------------------------------
void __fastcall TFL::ExecutaProcessoFL(Processo* processoFL)
{
	this->processoFL = processoFL;
	CriaObjTopologia();

	// Obt�m a topologia do Sinap, gera blocos radiais (baseados na classe VTBloco) e os ordena
	ObjTopologia_Inicia();

	// Prepara��o: defini��o do tipo de localiza��o "tipoLocalizacao"
	tipoLocalizacao = DefineTipoLocalizacao();

	// Determina a �rea de busca, no objeto de topologia
	ObjTopologia_DeterminaAreaBusca();

	// Chamada do algoritmo de localiza��o, em fun��o de "tipoLocalizacao"
	switch(tipoLocalizacao)
	{
		case algoLF1:
			LOCALIZACAO_algoLF1();
			break;

		case algoLF2:
			LOCALIZACAO_algoLF2();
			break;

		case algoLF3:
			LOCALIZACAO_algoLF3();
			break;

		default:
			break;
	}

	// Destroi o objeto de topologia e fecha as redes do Sinap
	ObjTopologia_Finaliza();
}
//---------------------------------------------------------------------------
void __fastcall TFL::LOCALIZACAO_algoLF1()
{
	if(!this->processoFL) return;


}
//---------------------------------------------------------------------------
void __fastcall TFL::LOCALIZACAO_algoLF2()
{
	if(!this->processoFL) return;


}
//---------------------------------------------------------------------------
void __fastcall TFL::LOCALIZACAO_algoLF3()
{
	if(!this->processoFL) return;



}
//---------------------------------------------------------------------------
int __fastcall TFL::DefineTipoLocalizacao()
{
	TList* listaAlarmes = processoFL->listaAlarmes;
	TList* listaAlarmesProtecao = new TList;
	int tipoAlgoritmoLF = -1;

	int numAlarmesRelig = 0;
	int numAlarmesLockout = 0;
	int numAlarmesLastGasp = 0;

	for(int i=0; i<listaAlarmes->Count; i++)
	{
		Alarme* alarme = (Alarme*) listaAlarmes->Items[i];
		if(alarme->tipoAlarme == 20)
		{
			numAlarmesRelig += 1;
			listaAlarmesProtecao->Add(alarme);
		}
		else if(alarme->tipoAlarme == 21)
		{
			numAlarmesLockout += 1;
			listaAlarmesProtecao->Add(alarme);
		}
		else if(alarme->tipoAlarme == 22)
			numAlarmesLastGasp += 1;
	}

	// Se h� pelo menos um alarme de atua��o de prote��o ==> FL1 ou FL2
	if(numAlarmesRelig > 0 || numAlarmesLockout > 0)
	{
		// Se houver pelo menos um alarme de atua��o de fun��o de prote��o de neutro ==> FL2
		for(int i=0; i<listaAlarmesProtecao->Count; i++)
		{
			Alarme* alarme = (Alarme*) listaAlarmesProtecao->Items[i];
			if(alarme->funcao50N || alarme->funcao51N)
			{
				tipoAlgoritmoLF = algoLF2;
				break;
			}
		}
		// N�o foi encontrado nenhuma atua��o de prote��o de sobrecorrente de neutro ==> FL1
		tipoAlgoritmoLF = algoLF1;
	}
	else if(numAlarmesLastGasp > 0 && numAlarmesRelig == 0 && numAlarmesLockout == 0)
	{
		// Se n�o h� alarmes de prote��o mas h� alarmes de Last Gasp ==> FL3
		tipoAlgoritmoLF = algoLF3;
	}

	delete listaAlarmesProtecao;
	return(tipoAlgoritmoLF);
}
//---------------------------------------------------------------------------
void __fastcall TFL::CriaObjTopologia()
{
	String codigoRede = processoFL->codigoAlimentador;
	topologiaDMS = DLL_NewTopologiaDMS(apl, codigoRede);
}
//---------------------------------------------------------------------------
void __fastcall TFL::ObjTopologia_Finaliza()
{
	topologiaDMS->FinalizaTopologiaRede();
}
//---------------------------------------------------------------------------
void __fastcall TFL::ObjTopologia_Inicia()
{
	topologiaDMS->IniciaTopologiaRede(processoFL);
}
//---------------------------------------------------------------------------
void __fastcall TFL::ObjTopologia_DeterminaAreaBusca()
{
	if(tipoLocalizacao == algoLF1 || tipoLocalizacao == algoLF2)
	{
		topologiaDMS->DeterminaAreaBuscaFalta();
	}
	else if(tipoLocalizacao == algoLF3)
	{
      topologiaDMS->DeterminaAreaBuscaRompCabo();
   }
}
//---------------------------------------------------------------------------
void __fastcall TFL::ObtemLocalizacao(SaidaFL* saidaFL)
{
   if(!saidaFL) return;

	// Objeto de sa�daFL (solu��es) � criado fora do TFL
	this->saidaFL = saidaFL;

	// Insere os par�metros gerais
	GeraObjetoSaida_Gerais();

	// Insere os par�metros do diagnost�co
	GeraObjetoSaida_Diagnostico();

	// Insere as solu��es individuais
	GeraObjetoSaida_Solucoes();
}
//---------------------------------------------------------------------------
void __fastcall TFL::GeraObjetoSaida_Gerais()
{
	if(!saidaFL) return;

	saidaFL->saidaGerais->timeStampEvento = "20191211105600";

	// ... demais par�metros gerais
}
//---------------------------------------------------------------------------
void __fastcall TFL::GeraObjetoSaida_Diagnostico()
{
	if(!saidaFL) return;

	saidaFL->saidaDiagnostico->tipoEvento = -1;

	// ... demais par�metros do diagnost�co
}
//---------------------------------------------------------------------------
void __fastcall TFL::GeraObjetoSaida_Solucoes()
{
	if(!saidaFL) return;

	SaidaFL_Solucao* solucao = new SaidaFL_Solucao;
	solucao->codigoChaveMontante = "RE1234";
	saidaFL->listaSolucoesFL->Add(solucao);
	// ... insere demais solu��es
}
//---------------------------------------------------------------------------
