//---------------------------------------------------------------------------
#ifndef TReleH
#define TReleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TEqptoDado.h"
//---------------------------------------------------------------------------
class TRele : public TEqptoDado
{
public:
	// Par�metros elementares
	int tipoEqptoDadoRele;

	// M�todos
	__fastcall TRele(VTApl* apl);
	__fastcall ~TRele();
};
//---------------------------------------------------------------------------
#endif
