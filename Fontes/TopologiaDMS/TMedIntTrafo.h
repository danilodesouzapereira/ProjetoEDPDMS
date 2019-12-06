//---------------------------------------------------------------------------
#ifndef TMedIntTrafoH
#define TMedIntTrafoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TMedInt.h"
//---------------------------------------------------------------------------
class TTrafo;
//---------------------------------------------------------------------------
class TMedIntTrafo : public TMedInt
{
public:
	// Parâmetros elementares
	TTrafo* trafo;

	// Métodos
	__fastcall TMedIntTrafo(VTApl* apl, TTrafo* trafo);
	__fastcall ~TMedIntTrafo();
};
//---------------------------------------------------------------------------
#endif
