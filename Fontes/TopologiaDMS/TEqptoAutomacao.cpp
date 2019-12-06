//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "enumeradores.h"
#include "TEqptoAutomacao.h"
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TEqptoAutomacao::TEqptoAutomacao(VTApl* apl) : TEqptoTopologia(apl)
{
	tipo = topoAUTOMACAO;
}
//---------------------------------------------------------------------------
__fastcall TEqptoAutomacao::~TEqptoAutomacao()
{

}
//---------------------------------------------------------------------------
