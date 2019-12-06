//---------------------------------------------------------------------------
#ifndef TAreaH
#define TAreaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TEqptoTopologia.h"
//---------------------------------------------------------------------------
class VTApl;
//---------------------------------------------------------------------------
class TArea : public TEqptoTopologia
{
public:
	// Par�metros elementares
	TList* lisBlocoRad;

	// M�todos
	__fastcall TArea(VTApl* apl);
	__fastcall ~TArea();
};

//---------------------------------------------------------------------------
#endif
