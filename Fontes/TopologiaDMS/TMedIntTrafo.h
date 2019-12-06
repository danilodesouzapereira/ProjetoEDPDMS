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
	// Par�metros elementares
	TTrafo* trafo;

	// M�todos
	__fastcall TMedIntTrafo(VTApl* apl, TTrafo* trafo);
	__fastcall ~TMedIntTrafo();
};
//---------------------------------------------------------------------------
#endif
