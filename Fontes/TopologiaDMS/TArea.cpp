//---------------------------------------------------------------------------
#pragma hdrstop
#include "enumeradores.h"
#include "TArea.h"
#include "TBlocoRad.h"
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
__fastcall TArea::TArea(VTApl* apl, TList* lisBlocosRad) : TEqptoTopologia(apl)
{
	tipo = topoAREA;
	lisBlocoRad = new TList;

	for(int i=0; i<lisBlocosRad->Count; i++)
	{
		TBlocoRad* blocoRad = (TBlocoRad*)lisBlocosRad->Items[i];
		lisBlocoRad->Add(blocoRad);
   }
}
//---------------------------------------------------------------------------
__fastcall TArea::~TArea()
{
	// Destroi objetos
	delete lisBlocoRad;
}
//---------------------------------------------------------------------------
