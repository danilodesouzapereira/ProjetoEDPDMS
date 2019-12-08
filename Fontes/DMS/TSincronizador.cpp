//---------------------------------------------------------------------------
#pragma hdrstop
#include "TSincronizador.h"
#include "TDMS.h"
#include "TFormDMS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TSincronizador::TSincronizador(TDMS* dms)
{
	// Salva parâmetros
	this->dms = dms;
	this->formDMS = dms->formDMS;

	// Inicia conexão do socket client com o socket remoto (server)
	clientSkt = new TClientSocket(NULL);
	clientSkt->OnRead = clientSktRead;
	clientSkt->OnError = clientSktError;
	clientSkt->Port = 2000;
	clientSkt->Host = "192.168.199.129";
	clientSkt->Open();

//	// Envia texto
//	AnsiString str = "Texto enviado pelo client.";
//	clientSkt->Socket->SendText(str);
}
//---------------------------------------------------------------------------
__fastcall TSincronizador::~TSincronizador()
{
	if(clientSkt->Active)
	{
		clientSkt->Active = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::clientSktRead(TObject *Sender, TCustomWinSocket *Socket)
{
//	formDMS->memoResposta->Text = "Resposta: " + Socket->ReceiveText() + "\r\n";

	AnsiString textoRecebido = Socket->ReceiveText();
   formDMS->memoResposta->Lines->Add(textoRecebido);
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::clientSktError(TObject *Sender, TCustomWinSocket *Socket,
			 TErrorEvent ErrorEvent, int &ErrorCode)
{
	ErrorCode = 0;
	clientSkt->Active = false;
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::CONSULTA_COMUNICACAO_ConsultaEventoNovo()
{
	// Envia texto de consulta de novo evento = 1
	clientSkt->Socket->SendText("1");
}
//---------------------------------------------------------------------------
