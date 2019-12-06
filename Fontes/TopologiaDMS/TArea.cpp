//---------------------------------------------------------------------------
#pragma hdrstop
#include "enumeradores.h"
#include "TArea.h"
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Bloco\VTBloco.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TArea::TArea(VTApl* apl) : TEqptoTopologia(apl)
{
	tipo = topoAREA;
	lisBlocoRad = new TList;
}
//---------------------------------------------------------------------------
__fastcall TArea::~TArea()
{
	// Destroi objetos
	delete lisBlocoRad;
}
//---------------------------------------------------------------------------
