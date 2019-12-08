
//---------------------------------------------------------------------------
#ifndef VTEEH
#define VTEEH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class VTApl;
class VTRedes;
//---------------------------------------------------------------------------
class VTEE : public TObject
{
public:
	// Parãmetros
	VTApl* apl;
	VTRedes* redes;

	// Métodos
		  __fastcall  VTEE(void) {};
		  __fastcall ~VTEE(void) {};

	// Principais
	virtual void __fastcall ExecutaEstimacaoDiaria() = 0;

	// Auxiliares

};
//---------------------------------------------------------------------------
VTEE* __fastcall NewObjEE(VTApl* apl);
//---------------------------------------------------------------------------
#endif