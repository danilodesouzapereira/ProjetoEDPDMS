//---------------------------------------------------------------------------
#ifndef TReligadoraH
#define TReligadoraH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TEqptoAutomacao.h"
//---------------------------------------------------------------------------
class TReleReligadora;
class VTChave;
//---------------------------------------------------------------------------
class TReligadora : public TEqptoAutomacao
{
public:
	// Parâmetros
	VTChave* chave;
	TReleReligadora* rele;

	TList* lisBlocosRad_Jusante;
	TList* lisBlocosRad_ZonaProtecao;

	// Métodos
	__fastcall TReligadora(VTApl* apl, VTChave* chave);
	__fastcall ~TReligadora();
};
//---------------------------------------------------------------------------
#endif
