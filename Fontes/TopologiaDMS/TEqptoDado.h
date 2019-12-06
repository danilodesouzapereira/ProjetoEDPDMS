//---------------------------------------------------------------------------
#ifndef TEqptoDadoH
#define TEqptoDadoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class VTApl;
//---------------------------------------------------------------------------
class TEqptoDado : public TObject
{
public:
	// Parâmetros elementares
	VTApl* apl;
	int    tipo;


	// Métodos
	__fastcall TEqptoDado(VTApl* apl);
	__fastcall ~TEqptoDado();

};
//---------------------------------------------------------------------------
#endif
