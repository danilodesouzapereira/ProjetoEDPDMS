//---------------------------------------------------------------------------
#ifndef TFormDMSH
#define TFormDMSH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDMS;
class VTApl;
//---------------------------------------------------------------------------
class TFormDMS : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TMemo *memoResposta;




private:	// User declarations
public:		// User declarations

	// Parâmetros
	TDMS*           dms;
	VTApl*          apl;


	// Métodos
	__fastcall TFormDMS(TComponent *Owner, VTApl *apl_owner, TWinControl *parent);
	__fastcall ~TFormDMS();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDMS *FormDMS;
//---------------------------------------------------------------------------
#endif
