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
	// Inicializações
	this->processoFL = processoFL;
	CriaObjTopologia();
	IniciaObjTopologia();

	// Preparação
	// ... método para definição do tipo de localização: "tipoLocalizacao"

	// Execução
	// ... método para chamada do algoritmo de localização, em função de "tipoLocalizacao"
}
//---------------------------------------------------------------------------
void __fastcall TFL::CriaObjTopologia()
{
	String codigoRede = processoFL->codigoAlimentador;
	topologiaDMS = DLL_NewTopologiaDMS(apl, codigoRede);
}
//---------------------------------------------------------------------------
void __fastcall TFL::IniciaObjTopologia()
{
	topologiaDMS->IniciaTopologiaRede();
}
//---------------------------------------------------------------------------
void __fastcall TFL::ObtemLocalizacao(SaidaFL* saidaFL)
{
   if(!saidaFL) return;

	// Objeto de saídaFL (soluções) é criado fora do TFL
	this->saidaFL = saidaFL;

	// Insere os parâmetros gerais
	GeraObjetoSaida_Gerais();

	// Insere os parâmetros do diagnostíco
	GeraObjetoSaida_Diagnostico();

	// Insere as soluções individuais
	GeraObjetoSaida_Solucoes();
}
//---------------------------------------------------------------------------
void __fastcall TFL::GeraObjetoSaida_Gerais()
{
	if(!saidaFL) return;

	saidaFL->saidaGerais->timeStampEvento = "20191211105600";

	// ... demais parâmetros gerais
}
//---------------------------------------------------------------------------
void __fastcall TFL::GeraObjetoSaida_Diagnostico()
{
	if(!saidaFL) return;

	saidaFL->saidaDiagnostico->tipoEvento = -1;

	// ... demais parâmetros do diagnostíco
}
//---------------------------------------------------------------------------
void __fastcall TFL::GeraObjetoSaida_Solucoes()
{
	if(!saidaFL) return;

	SaidaFL_Solucao* solucao = new SaidaFL_Solucao;
	solucao->codigoChaveMontante = "RE1234";
	saidaFL->listaSolucoesFL->Add(solucao);
	// ... insere demais soluções
}
//---------------------------------------------------------------------------
