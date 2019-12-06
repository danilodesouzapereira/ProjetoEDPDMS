//---------------------------------------------------------------------------
#ifndef TTopologiaDMSH
#define TTopologiaDMSH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class VTApl;
class VTBloco;
class VTBlocos;
class VTChave;
class VTOrdena;
class VTRede;
class VTRedes;
//---------------------------------------------------------------------------
class TTopologiaDMS : public TObject
{
public:
	// Parãmetros
	TList*    lisBlocosDMS;
	VTApl*    apl;
	VTBlocos* blocos;
   VTOrdena* ordena;
	VTRedes*  redes;


	// Métodos
		  __fastcall TTopologiaDMS(VTApl* apl);
		  __fastcall ~TTopologiaDMS();

	VTChave* __fastcall ChaveBloco(VTBloco* bloco);
	void     __fastcall DeterminaBlocosDMS(VTRede* rede);
	void     __fastcall IniciaTopologiaRede(VTRede* rede);
	void     __fastcall OrdenaBlocosDMS();

};
//---------------------------------------------------------------------------
#endif
