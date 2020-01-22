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
	// Par�metros elementares
	TDisjuntor* disjuntor;
	TList*      lisAlarmes;

	// M�todos
	__fastcall TReleDisjuntor(VTApl* apl, TDisjuntor* disjuntor);
	__fastcall ~TReleDisjuntor();
};
//---------------------------------------------------------------------------
#endif
