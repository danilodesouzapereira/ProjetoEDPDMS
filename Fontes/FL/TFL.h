//---------------------------------------------------------------------------
#ifndef TFLH
#define TFLH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TTopologiaDMS;
struct EntradaFL;
//---------------------------------------------------------------------------
class TFL : public TObject
{
public:
	// Métodos
		  __fastcall TFL(TTopologiaDMS* topoDMS);
		  __fastcall ~TFL();
	void __fastcall IniciarProcesso(EntradaFL* entradaFL);


	// Parãmetros
	EntradaFL*     entradaFL;
	TTopologiaDMS* topoDMS;
};
//---------------------------------------------------------------------------
#endif
