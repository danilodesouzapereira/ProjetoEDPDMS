//---------------------------------------------------------------------------
#ifndef TFLH
#define TFLH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "VTFL.h"
//---------------------------------------------------------------------------
class VTTopologiaDMS;
class VTApl;
//---------------------------------------------------------------------------
struct Processo;
struct SaidaFL;
//---------------------------------------------------------------------------
class TFL : public VTFL
{
public:

	// :::::::::::::::::::: Par�metros ::::::::::::::::::::
	int             tipoLocalizacao;
	Processo*       processoFL;
	SaidaFL*        saidaFL;
	VTApl*          apl;
	VTTopologiaDMS* topologiaDMS;

	// :::::::::::::::::::: M�todos ::::::::::::::::::::
	// Construtor e destrutor
		  __fastcall TFL(VTApl* apl);
		  __fastcall ~TFL(void);

	// M�todos principais
	void __fastcall CriaObjTopologia();
	int  __fastcall DefineTipoLocalizacao();
	void __fastcall ExecutaProcessoFL(Processo* processoFL);

   // Chamadas diretas ao objeto de topologia
	void __fastcall ObjTopologia_DeterminaAreaBusca();
	void __fastcall ObjTopologia_Finaliza();
	void __fastcall ObjTopologia_Inicia();

	// M�todos de localiza��o
	void __fastcall LOCALIZACAO_algoLF1();
	void __fastcall LOCALIZACAO_algoLF2();
	void __fastcall LOCALIZACAO_algoLF3();

	// Gera��o do objetos de sa�da (solu��o da localiza��o)
	void __fastcall GeraObjetoSaida_Diagnostico();
	void __fastcall GeraObjetoSaida_Gerais();
	void __fastcall GeraObjetoSaida_Solucoes();
	void __fastcall ObtemLocalizacao(SaidaFL* saidaFL);
};
//---------------------------------------------------------------------------
#endif
