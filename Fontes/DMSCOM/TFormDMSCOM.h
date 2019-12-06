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
class TFormDMSCOM : public TForm
{
__published:	// IDE-managed Components
	TClientSocket *ClientSocket1;
	TButton *Button1;
	TButton *Button2;
	TEdit *edtMsg;
	TMemo *Memo1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ClientSocket1Error(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFormDMSCOM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDMSCOM *FormDMSCOM;
//---------------------------------------------------------------------------
#endif
