//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TReleReligadora.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TReleReligadora::TReleReligadora(VTApl* apl, TReligadora* religadora) : TRele(apl)
{
   this->religadora = religadora;
	tipoEqptoDadoRele = eqptodadoreleRELIGADORA;
}
//---------------------------------------------------------------------------
__fastcall TReleReligadora::~TReleReligadora()
{
}
//---------------------------------------------------------------------------
