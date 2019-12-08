//---------------------------------------------------------------------------
#ifndef TDMSH
#define TDMSH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
class TFormDMS;
class TSincronizador;
class VTEE;
class VTFL;
class VTApl;
class VTPath;
//---------------------------------------------------------------------------
class TDMS : public TObject
{
public:
	// Parâmetros
	VTEE*           estimador;
	VTFL*           localizador;
	VTApl*          apl;
	VTPath*         path;

	// Parâmetros elementares
	TSincronizador* sinc;
	TFormDMS*       formDMS;


	// Mètodos
		  __fastcall TDMS(VTApl* apl, TFormDMS* formDMS);
		  __fastcall ~TDMS();

	void __fastcall CONSULTA_COMUNICACAO_ConsultaEventoNovo();
	void __fastcall IniciaProcessoEstimacao();
	void __fastcall IniciaProcessoFL();
};
//---------------------------------------------------------------------------
#endif
