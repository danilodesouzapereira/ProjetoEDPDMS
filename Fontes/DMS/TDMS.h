//---------------------------------------------------------------------------
#ifndef TDMSH
#define TDMSH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TEE;
class TFL;
class TTopologiaDMS;
class VTApl;
class VTPath;
//---------------------------------------------------------------------------
class TDMS : public TObject
{
public:
	// Parâmetros
	TEE*           estimador;
	TFL*           localizador;
	TTopologiaDMS* topologia;
	VTApl*         apl;
	VTPath*        path;


	// Mètodos
		  __fastcall TDMS(VTApl* apl);
		  __fastcall ~TDMS();
	void __fastcall IniciaProcessoFL();
};
//---------------------------------------------------------------------------
#endif
