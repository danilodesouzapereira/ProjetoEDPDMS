//---------------------------------------------------------------------------
#pragma hdrstop
#include "enumeradores.h"
#include "TMedInt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TMedInt::TMedInt(VTApl* apl) : TEqptoDado(apl)
{
	tipo = eqptodadoMEDINT;
}
//---------------------------------------------------------------------------
__fastcall TMedInt::~TMedInt()
{
}
//---------------------------------------------------------------------------
