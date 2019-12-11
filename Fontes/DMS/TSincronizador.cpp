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
	// Salva par�metros
	this->dms = dms;
	this->formDMS = dms->formDMS;

	// Inicia objeto de temporizador
	timer = new TTimer(NULL);
   timer->Enabled = false;
	timer->OnTimer = timerTimer;
	timerVerificaProcessoNovo = 0;
	passoVerificaProcessoNovo = 10;
	timerEstimadorEstados = 0;
   passoEstimadorEstados = 3600;

	// Cria processo de localiza��o "reutiliz�vel"
	processoFL = new Processo;
	idSolicitacao = 0;

	// Inicia conex�o do socket client com o socket remoto (server)
	clientSkt = new TClientSocket(NULL);
	clientSkt->OnRead = clientSktRead;
	clientSkt->OnError = clientSktError;
	clientSkt->Port = 2000;
	clientSkt->Host = "192.168.199.129";
	clientSkt->Open();

	timer->Enabled = true;
	statusSinc = sincSTANDBY;
}
//---------------------------------------------------------------------------
__fastcall TSincronizador::~TSincronizador()
{
	if(clientSkt->Active)
	{
		clientSkt->Active = false;
	}
	delete processoFL;
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::timerTimer(TObject *Sender)
{
	if(statusSinc == sincSTANDBY)  // Stand-by
	{
		// Incrementa valor dos temporizadores individuais de localiza��o e de estima��o
		timerVerificaProcessoNovo += 1;
		timerEstimadorEstados += 1;

		if(timerVerificaProcessoNovo == passoVerificaProcessoNovo)
		{
			// Consulta novo processo no m�dulo de comunica��o via socket
			COMUNICACAO_ConsultaProcessoNovo();
			statusSinc = sincSOLICIT_PROCESSO;

			// Resseta o timer de verifica��o de processo novo
			timerVerificaProcessoNovo = 0;

			// Resseta o objeto de processo de localiza��o, para receber os par�metros novos
			processoFL->Resseta();
		}

		if(timerEstimadorEstados == passoEstimadorEstados)
		{
			// Muda o status do sincronizador
			statusSinc = sincSOLICIT_PROCESSO;

			// Executa estima��o de estados
			// ... m�todo aqui

			// Resseta o timer de estima��o de estados
			timerEstimadorEstados = 0;

			// Restaura o status do sincronizador para stand-by
			statusSinc = sincSTANDBY;
		}
	}
	else if(statusSinc == sincSOLICIT_PROCESSO)  // Em solicita��o de novo processo de localiza��o
	{

	}
	else if(statusSinc == sincLOCALIZACAO) // Execu��o do FL
	{
		// Chama a execu��o do m�dulo de LF com o processoLF
		SaidaFL* saidaFL = new SaidaFL;
		dms->ExecutaProcessoFL(processoFL, saidaFL);

		// Envia os dados de sa�da ao m�dulo de comunica��o
		COMUNICACAO_RetornaSaidaFL(saidaFL);

		// Destroi o objeto de sa�da
      delete saidaFL;

		// Restaura o status do sincronizador para stand-by
		statusSinc = sincSTANDBY;
   }
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::clientSktRead(TObject *Sender, TCustomWinSocket *Socket)
{
	const int buffersize = 1000;

	// Recebe a resposta � solicita��o de processo
	char buffer[buffersize];
	memset(buffer, 0, sizeof(buffer));
	Socket->ReceiveBuf(buffer, sizeof(buffer));
	AnsiString texto = AnsiString(buffer);

	// Verifica 1a parte da resposta
	int numeroCampos = NumeroCampos(texto, "#");
	if(numeroCampos == 0) return;

	String parte1 = ValorCampo(texto, 0, "#");
	int tipoSolicitacao = ValorCampo(parte1, 0, ";").ToInt();
	int idSolicitacao = ValorCampo(parte1, 1, ";").ToInt();
	if(tipoSolicitacao == 1 && idSolicitacao == this->idSolicitacao)
	{
		for(int i=1; i<numeroCampos; i++)
		{
			// Pega o conte�do do alarme
			String conteudoAlarme = ValorCampo(texto, i, "#");

			// Insere dados no objeto de processo de localiza��o
			AtualizaObjProcessoFL(conteudoAlarme);
		}
	}

	formDMS->memoResposta->Lines->Add(texto);
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::clientSktError(TObject *Sender, TCustomWinSocket *Socket,
			 TErrorEvent ErrorEvent, int &ErrorCode)
{
	ErrorCode = 0;
	clientSkt->Active = false;
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::AtualizaObjProcessoFL(String conteudoAlarme)
{
	if(conteudoAlarme == "") return;

	int indice = 0;

	// Id do alarme
	int idAlarme = ValorCampo(conteudoAlarme, indice++, ";").ToInt();

	// Total de alarmes
	int totalAlarmes = ValorCampo(conteudoAlarme, indice++, ";").ToInt();

	// Cria objeto de alarme
	Alarme* alarme = new Alarme;
	alarme->timeStamp = ValorCampo(conteudoAlarme, indice++, ";");
	alarme->codigoAlimentador = ValorCampo(conteudoAlarme, indice++, ";");
	alarme->codigoEqpto = ValorCampo(conteudoAlarme, indice++, ";");
	alarme->tipoEqpto = ValorCampo(conteudoAlarme, indice++, ";").ToInt();
	alarme->tipoAlarme = ValorCampo(conteudoAlarme, indice++, ";").ToInt();

	// Adiciona o alarme � lista de alarmes do processo
	processoFL->listaAlarmes->Add(alarme);

	// Ao final do �ltimo alarme do processo, pega as caracter�sticas do processo,
	// que se baseiam no alarme mais antigo.
	if(idAlarme == totalAlarmes)
	{
		Alarme* alarme = AUXILIAR_AlarmeMaisAntigo(processoFL->listaAlarmes);
		processoFL->timeStamp = alarme->timeStamp;
		processoFL->codigoAlimentador = alarme->codigoAlimentador;

		// Altera o status do sincronizador, para que inicie o m�dulo de localiza��o
		statusSinc = sincLOCALIZACAO;
	}
}
//---------------------------------------------------------------------------
Alarme* __fastcall TSincronizador::AUXILIAR_AlarmeMaisAntigo(TList* listaAlarmes)
{
	if(!listaAlarmes) return(NULL);

	Alarme* alarme_mais_antigo = NULL;
	for(int i=0; i<listaAlarmes->Count; i++)
	{
		Alarme* alarme = (Alarme*)listaAlarmes->Items[i];
		if(!alarme_mais_antigo)
		{
			alarme_mais_antigo = alarme;
			continue;
		}

		TDateTime dt1 = Timestamp_To_DateTime(alarme_mais_antigo->timeStamp);
		TDateTime dt2 = Timestamp_To_DateTime(alarme->timeStamp);

		if(dt2 < dt1) alarme_mais_antigo = alarme;
	}
	return(alarme_mais_antigo);
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::COMUNICACAO_ConsultaProcessoNovo()
{
	// Envia texto de consulta de novo evento. Campos: tipo de solicita��o e
	// timestamp
	String timestamp = DateTime_To_Timestamp(Now());
	idSolicitacao++;
	if(idSolicitacao == 1000) idSolicitacao = 1;
	clientSkt->Socket->SendText("1;" + String(idSolicitacao) + ";");
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::COMUNICACAO_RetornaSaidaFL(SaidaFL* saidaFL)
{
	if(!saidaFL) return;

	// ... m�todo para gerar uma string CSV com os par�metros de saidaFL (solu��es)

	clientSkt->Socket->SendText("2;DadosSaida");
}
//---------------------------------------------------------------------------
