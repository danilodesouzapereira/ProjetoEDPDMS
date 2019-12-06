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
	// Par�metros elementares
	VTApl* apl;
	int    tipo;


	// M�todos
	__fastcall TEqptoDado(VTApl* apl);
	__fastcall ~TEqptoDado();

};
//---------------------------------------------------------------------------
#endif
