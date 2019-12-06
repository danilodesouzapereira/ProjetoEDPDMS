//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TFormDMSCOM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDMSCOM *FormDMSCOM;
//---------------------------------------------------------------------------
__fastcall TFormDMSCOM::TFormDMSCOM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDMSCOM::Button1Click(TObject *Sender)
{
	if(!ClientSocket1->Socket->Connected)
	{
		ClientSocket1->Address = "192.168.199.129";
		ClientSocket1->Active = true;
		Button1->Caption = "Desconectar";
	}
	else
	{
		ClientSocket1->Active = false;
		Button1->Caption = "Conectar";
   }
}
//---------------------------------------------------------------------------
void __fastcall TFormDMSCOM::Button2Click(TObject *Sender)
{
	AnsiString str = edtMsg->Text;
	ClientSocket1->Socket->SendText(str);
}
//---------------------------------------------------------------------------
void __fastcall TFormDMSCOM::ClientSocket1Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	ErrorCode = 0;
	ClientSocket1->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormDMSCOM::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)

{
   Memo1->Text = "Resposta: " + Socket->ReceiveText() + "\r\n";
}
//---------------------------------------------------------------------------

void __fastcall TFormDMSCOM::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(ClientSocket1->Active)
	{
		ClientSocket1->Active = false;
   }
}
//---------------------------------------------------------------------------

