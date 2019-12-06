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
class VTChave;
//---------------------------------------------------------------------------
class TReligadora : public TEqptoAutomacao
{
public:
	// Parâmetros
	VTChave* chave;

	// Métodos
	__fastcall TReligadora(VTApl* apl, VTChave* chave);
	__fastcall ~TReligadora();
};
//---------------------------------------------------------------------------
#endif
