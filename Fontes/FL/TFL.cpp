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
	// Inicializa��es
	this->processoFL = processoFL;
	CriaObjTopologia();
	IniciaObjTopologia();

	// Prepara��o
	// ... m�todo para defini��o do tipo de localiza��o: "tipoLocalizacao"

	// Execu��o
	// ... m�todo para chamada do algoritmo de localiza��o, em fun��o de "tipoLocalizacao"
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
