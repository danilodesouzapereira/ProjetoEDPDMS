//---------------------------------------------------------------------------
#ifndef TDisjuntorH
#define TDisjuntorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TEqptoAutomacao.h"
//---------------------------------------------------------------------------
class VTChave;
//---------------------------------------------------------------------------
class TDisjuntor : public TEqptoAutomacao
{
public:
	// Par�metros
	VTChave* chave;

	// M�todos
	__fastcall TDisjuntor(VTApl* apl, VTChave* chave);
	__fastcall ~TDisjuntor();
};
//---------------------------------------------------------------------------
#endif
