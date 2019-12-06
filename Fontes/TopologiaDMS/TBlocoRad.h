//---------------------------------------------------------------------------
#ifndef TBlocoRadH
#define TBlocoRadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TEqptoTopologia.h"
//---------------------------------------------------------------------------
class VTApl;
class VTBloco;
class VTChave;
//---------------------------------------------------------------------------
class TBlocoRad : public TEqptoTopologia
{
public:
	// Parâmetros
	VTBloco* bloco;
	VTChave* chavePai;
	TBlocoRad* blocoRadPai;
	TList* lisBlocoRadFilho;

	// Métodos
	__fastcall TBlocoRad(VTApl* apl);
	__fastcall ~TBlocoRad();

};
//---------------------------------------------------------------------------
#endif
