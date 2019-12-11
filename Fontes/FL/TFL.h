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

	// :::::::::::::::::::: Parâmetros ::::::::::::::::::::
	int             tipoLocalizacao;
	Processo*       processoFL;
	SaidaFL*        saidaFL;
	VTApl*          apl;
	VTTopologiaDMS* topologiaDMS;



	// :::::::::::::::::::: Métodos ::::::::::::::::::::
	// Construtor e destrutor
		  __fastcall TFL(VTApl* apl);
		  __fastcall ~TFL(void);

	// Métodos principais
	void __fastcall CriaObjTopologia();
	void __fastcall ExecutaProcessoFL(Processo* processoFL);
	void __fastcall IniciaObjTopologia();

	// Geração do objetos de saída (solução da localização)
	void __fastcall GeraObjetoSaida_Diagnostico();
	void __fastcall GeraObjetoSaida_Gerais();
	void __fastcall GeraObjetoSaida_Solucoes();
	void __fastcall ObtemLocalizacao(SaidaFL* saidaFL);
};
//---------------------------------------------------------------------------
#endif
