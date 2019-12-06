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
	// Parâmetros elementares
	TList* lisBlocoRad;

	// Métodos
	__fastcall TArea(VTApl* apl);
	__fastcall ~TArea();
};

//---------------------------------------------------------------------------
#endif
