//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TMedIntTrafo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TMedIntTrafo::TMedIntTrafo(VTApl* apl, TTrafo* trafo) : TMedInt(apl)
{
   this->trafo = trafo;
	tipoMedInt = eqptomedintTRAFO;

	// Lista de alarmes associados ao medidor inteligente
	lisAlarmes = new TList;
}
//---------------------------------------------------------------------------
__fastcall TMedIntTrafo::~TMedIntTrafo()
{
	delete lisAlarmes;
}
//---------------------------------------------------------------------------
