//---------------------------------------------------------------------------
#pragma hdrstop
#include "TModuloComunicacao.h"
#include "TFormDMSCOM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TModuloComunicacao::TModuloComunicacao(TFormDMSCOM* formDMSCOM)
{
	this->formDMSCOM = formDMSCOM;
	IniciaServerSocket();

	lisAux_Processos = new TStringList;
	lisAux_Processos_lidos = new TStringList;
	numProcessos = 0;
}
//---------------------------------------------------------------------------
__fastcall TModuloComunicacao::~TModuloComunicacao()
{
	delete lisAux_Processos;
	delete lisAux_Processos_lidos;
}
//---------------------------------------------------------------------------
void __fastcall TModuloComunicacao::AdicionarProcesso()
{
	String codigoProcesso = "Processo_" + String(1 + numProcessos++);
	lisAux_Processos->Add(codigoProcesso);

	// Atualiza memo de processos
	formDMSCOM->Memo2->Lines->Clear();
	for(int i=0; i<lisAux_Processos->Count; i++)
	{
		String strProcesso = lisAux_Processos->Strings[i];
		formDMSCOM->Memo2->Lines->Add(strProcesso);
	}
}
//---------------------------------------------------------------------------
void __fastcall TModuloComunicacao::IniciaServerSocket()
{
	serverSkt = new TServerSocket(NULL);
	serverSkt->OnClientConnect = serverSktClientConnect;
	serverSkt->OnClientDisconnect = serverSktClientDisconnect;
	serverSkt->OnClientRead = serverSktClientRead;
	serverSkt->Port = 2000;
	serverSkt->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TModuloComunicacao::serverSktClientConnect(TObject *Sender, TCustomWinSocket *Socket)
{
	formDMSCOM->Memo1->Text = "Cliente conectado";
}
//---------------------------------------------------------------------------
void __fastcall TModuloComunicacao::serverSktClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)
{
	formDMSCOM->Memo1->Text = "Cliente desconectado";
}
//---------------------------------------------------------------------------
void __fastcall TModuloComunicacao::serverSktClientRead(TObject *Sender, TCustomWinSocket *Socket)
{
	AnsiString mensagemRecebida = Socket->ReceiveText();
	formDMSCOM->Memo1->Lines->Add("RX: " + mensagemRecebida);

	if(mensagemRecebida == "1") // Client consulta se há processo não lido
	{
		AnsiString strProcesso = CONSULTACLIENT_SolicitacaoProcessoNaoLido();
		Socket->SendText(strProcesso);
   }
}
//---------------------------------------------------------------------------
AnsiString __fastcall TModuloComunicacao::CONSULTACLIENT_SolicitacaoProcessoNaoLido()
{
	if(lisAux_Processos->Count == 0) return("");

	// Lê a string do processo e a transfere para a lista de processos lidos
	String strProcesso = lisAux_Processos->Strings[0];
	lisAux_Processos->Delete(0);
	lisAux_Processos_lidos->Add(strProcesso);

	// Atualiza memo de processos
	formDMSCOM->Memo2->Lines->Clear();
	for(int i=0; i<lisAux_Processos->Count; i++)
	{
		String strProcesso = lisAux_Processos->Strings[i];
		formDMSCOM->Memo2->Lines->Add(strProcesso);
	}

	// Retorna a string do processo
   return(strProcesso);
}
//---------------------------------------------------------------------------
