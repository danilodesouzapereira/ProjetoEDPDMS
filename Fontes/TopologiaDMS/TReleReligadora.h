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
	// Par�metros elementares
	TReligadora* religadora;
	TList*       lisAlarmes;

	// M�todos
	__fastcall TReleReligadora(VTApl* apl, TReligadora* religadora);
	__fastcall ~TReleReligadora();
};
//---------------------------------------------------------------------------
#endif
