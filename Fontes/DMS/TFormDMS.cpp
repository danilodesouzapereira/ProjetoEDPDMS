//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <ProjetoEDPDMS\Fontes\DMS\TDMS.h>
#include <ProjetoEDPDMS\Fontes\DMS\TSincronizador.h>
//---------------------------------------------------------------------------
#include "TFormDMS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDMS *FormDMS;
//---------------------------------------------------------------------------
__fastcall TFormDMS::TFormDMS(TComponent *Owner, VTApl *apl_owner, TWinControl *parent)
	: TForm(Owner)
{
	apl = apl_owner;

	sinc = new TSincronizador();
	dms = new TDMS(apl);

}
//---------------------------------------------------------------------------
__fastcall TFormDMS::~TFormDMS()
{
	// Destroi objetos
	delete sinc;
   delete dms;
}
//---------------------------------------------------------------------------
void __fastcall TFormDMS::Button1Click(TObject *Sender)
{
	if(ServerSocket1->Active == false)
	{
		ServerSocket1->Active = true;
      Button1->Caption = "Desativar";
	}
	else
	{
		ServerSocket1->Active = false;
		Button1->Caption = "Ativar";
   }
}
//---------------------------------------------------------------------------
void __fastcall TFormDMS::ServerSocket1ClientConnect(TObject *Sender, TCustomWinSocket *Socket)
{
	Socket->SendText("Conectado ao server.");
	Memo1->Text = "Cliente conectado";
}
//---------------------------------------------------------------------------
void __fastcall TFormDMS::ServerSocket1ClientRead(TObject *Sender, TCustomWinSocket *Socket)
{
	char* buffer = new char[200];
	Socket->ReceiveBuf(buffer, 200);
	Memo1->Lines->Add(AnsiString(buffer));
	delete[] buffer;


	// ==== LENDO PARA UMA ESTRUTURA DE CARACTERES: =========
//	struct StrDados
//	{
//		char val1;
//		char val2;
//		char val3;
//		char val4;
//		char val5;
//		char val6;
//	};
//	StrDados* dados = new StrDados;
//	char* buffer2 = new char[5];
//	Socket->ReceiveBuf(buffer2, 5);
//	memcpy(dados, buffer2, 5);
//	delete[] buffer2;

}
//---------------------------------------------------------------------------


void __fastcall TFormDMS::ServerSocket1ClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	Memo1->Text = "Cliente desconectado";
}
//---------------------------------------------------------------------------

