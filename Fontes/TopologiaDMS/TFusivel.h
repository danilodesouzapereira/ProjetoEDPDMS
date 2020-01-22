//---------------------------------------------------------------------------
#ifndef TFusivelH
#define TFusivelH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TEqptoAutomacao.h"
//---------------------------------------------------------------------------
class VTChave;
//---------------------------------------------------------------------------
class TFusivel : public TEqptoAutomacao
{
public:
	// Parâmetros
	VTChave* chave;

	TList* lisBlocosRad_Jusante;
	TList* lisBlocosRad_ZonaProtecao;

	// Métodos
	__fastcall TFusivel(VTApl* apl, VTChave* chave);
	__fastcall ~TFusivel();
};
//---------------------------------------------------------------------------
#endif
