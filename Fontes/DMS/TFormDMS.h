//---------------------------------------------------------------------------
#ifndef TFormDMSH
#define TFormDMSH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
class TDMS;
class TSincronizador;
class VTApl;
//---------------------------------------------------------------------------
class TFormDMS : public TForm
{
__published:	// IDE-managed Components
	TServerSocket *ServerSocket1;
	TButton *Button1;
	TMemo *Memo1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ServerSocket1ClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);



private:	// User declarations
public:		// User declarations

	// Parâmetros
	TDMS*           dms;
	TSincronizador* sinc;
	VTApl*          apl;


	// Métodos
	__fastcall TFormDMS(TComponent *Owner, VTApl *apl_owner, TWinControl *parent);
   __fastcall ~TFormDMS();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDMS *FormDMS;
//---------------------------------------------------------------------------
#endif
