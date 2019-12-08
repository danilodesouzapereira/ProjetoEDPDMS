
//---------------------------------------------------------------------------
#ifndef VTFLH
#define VTFLH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TTopologiaDMS;
class VTApl;
//---------------------------------------------------------------------------
struct EntradaFL;
//---------------------------------------------------------------------------
class VTFL : public TObject
{
public:
	// Métodos
		  __fastcall  VTFL(void) {};
		  __fastcall ~VTFL(void) {};

	virtual void __fastcall CriaObjTopologia() = 0;
	virtual void __fastcall IniciaObjTopologia() = 0;
	virtual void __fastcall ExecutaProcesso(EntradaFL* entradaFL) = 0;

	// Parãmetros
	EntradaFL*     entradaFL;
	TTopologiaDMS* topologiaDMS;
   VTApl*         apl;
};
//---------------------------------------------------------------------------
VTFL* __fastcall NewObjFL(VTApl *apl);
//---------------------------------------------------------------------------
#endif