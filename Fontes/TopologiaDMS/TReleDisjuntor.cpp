//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TReleDisjuntor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TReleDisjuntor::TReleDisjuntor(VTApl* apl, TDisjuntor* disjuntor) : TRele(apl)
{
   this->disjuntor = disjuntor;
	tipoEqptoDadoRele = eqptodadoreleDISJUNTOR;
}
//---------------------------------------------------------------------------
__fastcall TReleDisjuntor::~TReleDisjuntor()
{
}
//---------------------------------------------------------------------------
