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

	// Lista de alarmes associados à religadora
	lisAlarmes = new TList;
}
//---------------------------------------------------------------------------
__fastcall TReleReligadora::~TReleReligadora()
{
	delete lisAlarmes;
}
//---------------------------------------------------------------------------
