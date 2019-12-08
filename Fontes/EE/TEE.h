//---------------------------------------------------------------------------
#ifndef TEEH
#define TEEH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "VTEE.h"
//---------------------------------------------------------------------------
class VTApl;
class VTRedes;
//---------------------------------------------------------------------------
class TEE : public VTEE
{
public:
	// Par�metros
	VTApl* apl;
	VTRedes* redes;

	// M�todos
		  __fastcall TEE(VTApl* apl);
		  __fastcall ~TEE();

	// Principais
	void __fastcall ExecutaEstimacaoDiaria();

	// Auxiliares

};
//---------------------------------------------------------------------------
#endif
