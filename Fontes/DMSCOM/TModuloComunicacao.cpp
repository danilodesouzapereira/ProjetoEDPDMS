//---------------------------------------------------------------------------
#pragma hdrstop
#include "TModuloComunicacao.h"
#include "TLeitorXML.h"
#include "TFormDMSCOM.h"
#include "..\Uteis\Modelos.h"
#include "..\Uteis\TMetodosAuxiliares.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TModuloComunicacao::TModuloComunicacao(TFormDMSCOM* formDMSCOM)
{
	this->formDMSCOM = formDMSCOM;
	IniciaServerSocket();

	// Lista para os novos alarmes (via WS, por exemplo)
	listaAlarmes = new TList;

	// Lista de processos
	listaProcessos = new TList;
	listaProcessos_lidos = new TList;
	numAlarmes = 0;

	// :::::::::::::: TESTE: geração de um alarme através de leitura de XML
	// Criação de obj de processo
	Processo* processo = new Processo;
	listaProcessos->Add(processo);
	// Leitura dos alarmes a partir de XML
	leitorXML = new TLeitorXML("C:\\Users\\Sinapsis\\Desktop", formDMSCOM);
	leitorXML->LeAlarmes_StringCSV("Alarme1.xml", listaAlarmes);
	// Lê o 1o alarme
	Alarme* alarme = (Alarme*)listaAlarmes->Items[0];
	processo->timeStamp = alarme->timeStamp;
	processo->codigoAlimentador = alarme->codigoAlimentador;
	processo->listaAlarmes->Add(alarme);
	// Lê o 2o alarme
	alarme = (Alarme*)listaAlarmes->Items[1];
	processo->listaAlarmes->Add(alarme);
	formDMSCOM->Memo2->Lines->Add(processo->timeStamp);
}
//---------------------------------------------------------------------------
__fastcall TModuloComunicacao::~TModuloComunicacao()
{
	delete listaAlarmes;
	delete listaProcessos;
	delete listaProcessos_lidos;
	delete leitorXML;
}
//---------------------------------------------------------------------------
void __fastcall TModuloComunicacao::AdicionarAlarme()
{
//	String codigoAlarme = "Alarme_" + String(1 + numAlarmes++);
//	lisAux_Alarmes->Add(codigoAlarme);
//
//	// Atualiza memo de alarmes
//	formDMSCOM->Memo2->Lines->Clear();
//	for(int i=0; i<lisAux_Alarmes->Count; i++)
//	{
//		String strAlarme = lisAux_Alarmes->Strings[i];
//		formDMSCOM->Memo2->Lines->Add(strAlarme);
//	}
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

	String tipoSolicitacao = ValorCampo(mensagemRecebida, 0, ";");
	String codigoSolicitacao = ValorCampo(mensagemRecebida, 1, ";");

	if(tipoSolicitacao == "1") // Client consulta se há processo não lido
	{
		// Obtém as linhas correspondentes aos parâmetros de cada alarme
		// (uma linha por alarme)
		TStringList* lisStrResposta = new TStringList;
		CONSULTACLIENT_SolicitacaoProcessoNaoLido(lisStrResposta);

		// Envia prefácio com as seguintes informações: tipo de solicitação e
		// codigoSolicitação (identificador da solicitação)
		AnsiString linha = "1;" + codigoSolicitacao + "#";

		for(int i=0; i<lisStrResposta->Count; i++)
		{
			// Insere índice do alarme e total de alarmes
			linha += String(i+1) + ";" + String(lisStrResposta->Count) + ";";

			// Insere as características do alarme
			linha += lisStrResposta->Strings[i];
		}

		// Envia a string através do socket
		char* linhaChar = new char[linha.Length() + 1];
		strcpy(linhaChar, linha.c_str());
		Socket->SendText(linhaChar);

		delete[] linhaChar;
		delete lisStrResposta;
   }
}
//---------------------------------------------------------------------------
// Método executado a partir de comando de solicitação do socket client do DMS
// Formato: TIMESTAMP;CÓD. ALIMENTADOR;CÓD. EQPTO;TIPO EQPTO;TIPO ALARME;
void __fastcall TModuloComunicacao::CONSULTACLIENT_SolicitacaoProcessoNaoLido(TStringList* lisEXT)
{
	if(!lisEXT || listaProcessos->Count == 0) return;

	// Lê o alarme mais antigo e o transfere para a lista de alarmes lidos
	Processo* processo = (Processo*) listaProcessos->Items[0];

	// Gera uma linha CSV com os parâmetros dos alarmes do processo
	for(int i=0; i<processo->listaAlarmes->Count; i++)
	{
		Alarme* alarme = (Alarme*) processo->listaAlarmes->Items[i];

		String linhaAlarme = alarme->timeStamp;                   // 0: timestamp
		linhaAlarme += ";" + alarme->codigoAlimentador;     // 1: cód. alimentador
		linhaAlarme += ";" + alarme->codigoEqpto;           // 2: cód. eqpto
		linhaAlarme += ";" + String(alarme->tipoEqpto);     // 3: tipo eqpto
		linhaAlarme += ";" + String(alarme->tipoAlarme);    // 4: tipo alarme
		if(i < processo->listaAlarmes->Count-1) linhaAlarme += "#";
		lisEXT->Add(linhaAlarme);
	}

	// Remove o processo da lista de processos e o insere na lista de processos lidos
	listaProcessos->Remove(processo);
	listaProcessos_lidos->Add(processo);

	// Atualiza memo de processos
	formDMSCOM->Memo2->Lines->Clear();
	for(int i=0; i<listaProcessos->Count; i++)
	{
		Processo* processo = (Processo*) listaProcessos->Items[i];
		formDMSCOM->Memo2->Lines->Add(processo->timeStamp);
	}
}
//---------------------------------------------------------------------------
