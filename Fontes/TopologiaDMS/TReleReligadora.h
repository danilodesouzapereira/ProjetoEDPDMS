//---------------------------------------------------------------------------
#ifndef TReleReligadoraH
#define TReleReligadoraH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TRele.h"
//---------------------------------------------------------------------------
class TReligadora;
//---------------------------------------------------------------------------
class TReleReligadora : public TRele
{
public:
	// Parâmetros elementares
	TReligadora* religadora;
	TList*       lisAlarmes;

	// Métodos
	__fastcall TReleReligadora(VTApl* apl, TReligadora* religadora);
	__fastcall ~TReleReligadora();
};
//---------------------------------------------------------------------------
#endif
