//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TBlocoRad.h"
#include "TEqptoTopologia.h"
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Bloco\VTBloco.h>
#include <PlataformaSinap\Fontes\Rede\VTChave.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TBlocoRad::TBlocoRad(VTApl* apl) : TEqptoTopologia(apl)
{
	tipo = topoBLOCORAD;
	chavePai = NULL;
	bloco = NULL;
	blocoRadPai = NULL;
	lisBlocoRadFilho = new TList;
}
//---------------------------------------------------------------------------
__fastcall TBlocoRad::~TBlocoRad()
{
	// Destroi objetos
   delete lisBlocoRadFilho;
}
//---------------------------------------------------------------------------
