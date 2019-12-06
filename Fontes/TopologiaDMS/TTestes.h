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
	// Par�metros elementares
	VTApl* apl;
	VTGrafico* grafico;
	VTRedes* redes;

	// M�todos
				__fastcall TTestes(VTApl* apl);
				__fastcall ~TTestes();

	void __fastcall MostrarLigacoes(String pathArquivoLigacoes);

};
//---------------------------------------------------------------------------
#endif
