//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TTrafo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TTrafo::TTrafo(VTApl* apl, VTCarga* carga) : TEqptoTopologia(apl)
{
   this->carga = carga;
}
//---------------------------------------------------------------------------
__fastcall TTrafo::~TTrafo()
{

}
//---------------------------------------------------------------------------
