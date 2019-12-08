//---------------------------------------------------------------------------
#ifndef TFLH
#define TFLH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "VTFL.h"
//---------------------------------------------------------------------------
class VTTopologiaDMS;
class VTApl;
//---------------------------------------------------------------------------
struct EntradaFL;
//---------------------------------------------------------------------------
class TFL : public VTFL
{
public:
	// M�todos
		  __fastcall TFL(VTApl* apl);
		  __fastcall ~TFL(void);

	void __fastcall CriaObjTopologia();
	void __fastcall IniciaObjTopologia();
	void __fastcall ExecutaProcesso(EntradaFL* entradaFL);

	// Par�metros
	EntradaFL*     entradaFL;
	VTTopologiaDMS* topologiaDMS;
   VTApl*         apl;
};
//---------------------------------------------------------------------------
#endif
