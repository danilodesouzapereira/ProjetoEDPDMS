//---------------------------------------------------------------------------
#ifndef TTrafoH
#define TTrafoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TEqptoTopologia.h"
//---------------------------------------------------------------------------
class VTCarga;
//---------------------------------------------------------------------------
class TTrafo : public TEqptoTopologia
{
public:
	// Par�metros
	VTCarga* carga;

	// M�todos
	__fastcall TTrafo(VTApl* apl, VTCarga* carga);
	__fastcall ~TTrafo();
};
//---------------------------------------------------------------------------
#endif
