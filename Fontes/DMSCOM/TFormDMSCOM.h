//---------------------------------------------------------------------------

#ifndef TFormDMSCOMH
#define TFormDMSCOMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
class TModuloComunicacao;
//---------------------------------------------------------------------------
class TFormDMSCOM : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TButton *Button1;
	TGroupBox *GroupBox1;
	TMemo *Memo1;
	TGroupBox *GroupBox2;
	TMemo *Memo2;
	void __fastcall Button1Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TFormDMSCOM(TComponent* Owner);
   __fastcall ~TFormDMSCOM(void);

	TModuloComunicacao* moduloCom;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDMSCOM *FormDMSCOM;
//---------------------------------------------------------------------------
#endif
