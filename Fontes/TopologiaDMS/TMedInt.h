//---------------------------------------------------------------------------
#ifndef TMedIntH
#define TMedIntH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TEqptoDado.h"
//---------------------------------------------------------------------------
class TMedInt : public TEqptoDado
{
public:
	// Par�metros elementares
	int tipoMedInt;

	// M�todos
	__fastcall TMedInt(VTApl* apl);
	__fastcall ~TMedInt();
};
//---------------------------------------------------------------------------
#endif
