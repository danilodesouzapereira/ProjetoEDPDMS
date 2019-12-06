//---------------------------------------------------------------------------
#ifndef TEEH
#define TEEH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class VTApl;
class VTRedes;
//---------------------------------------------------------------------------
class TEE : public TObject
{
public:
	// Parãmetros
	VTApl* apl;
	VTRedes* redes;

	// Métodos
		  __fastcall TEE(VTApl* apl);
		  __fastcall ~TEE();

	// Principais
	void __fastcall ExecutaEstimacaoDiaria();

	// Auxiliares

};
//---------------------------------------------------------------------------
#endif
