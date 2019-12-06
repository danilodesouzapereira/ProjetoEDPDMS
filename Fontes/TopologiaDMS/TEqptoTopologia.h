//---------------------------------------------------------------------------
#ifndef TEqptoTopologiaH
#define TEqptoTopologiaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class VTApl;
//---------------------------------------------------------------------------
class TEqptoTopologia : public TObject
{
public:
	// Par�metros elementares
	VTApl* apl;
	int    tipo;


	// M�todos
	__fastcall TEqptoTopologia(VTApl* apl);
	__fastcall ~TEqptoTopologia();

};
//---------------------------------------------------------------------------
#endif
