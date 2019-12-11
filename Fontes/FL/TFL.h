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
	void __fastcall ExecutaProcessoFL(Processo* processoFL);
	void __fastcall IniciaObjTopologia();

	// Gera��o do objetos de sa�da (solu��o da localiza��o)
	void __fastcall GeraObjetoSaida_Diagnostico();
	void __fastcall GeraObjetoSaida_Gerais();
	void __fastcall GeraObjetoSaida_Solucoes();
	void __fastcall ObtemLocalizacao(SaidaFL* saidaFL);
};
//---------------------------------------------------------------------------
#endif
