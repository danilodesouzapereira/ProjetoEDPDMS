//---------------------------------------------------------------------------
#ifndef TReleDisjuntorH
#define TReleDisjuntorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TRele.h"
//---------------------------------------------------------------------------
class TDisjuntor;
//---------------------------------------------------------------------------
class TReleDisjuntor : public TRele
{
public:
	// Parâmetros elementares
	TDisjuntor* disjuntor;
	TList*      lisAlarmes;

	// Métodos
	__fastcall TReleDisjuntor(VTApl* apl, TDisjuntor* disjuntor);
	__fastcall ~TReleDisjuntor();
};
//---------------------------------------------------------------------------
#endif
