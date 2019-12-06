//---------------------------------------------------------------------------
#ifndef TTestesH
#define TTestesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class VTApl;
class VTGrafico;
class VTRedes;
//---------------------------------------------------------------------------
class TTestes
{
public:
	// Parâmetros elementares
	VTApl* apl;
	VTGrafico* grafico;
	VTRedes* redes;

	// Métodos
				__fastcall TTestes(VTApl* apl);
				__fastcall ~TTestes();

	void __fastcall MostrarLigacoes(String pathArquivoLigacoes);

};
//---------------------------------------------------------------------------
#endif
