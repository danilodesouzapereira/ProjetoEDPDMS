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

	// Inicia objeto de temporizador
	timer = new TTimer(NULL);
   timer->Enabled = false;
	timer->OnTimer = timerTimer;
	timerVerificaProcessoNovo = 0;
	passoVerificaProcessoNovo = 10;
	timerEstimadorEstados = 0;
   passoEstimadorEstados = 3600;

	// Cria processo de localização "reutilizável"
	processoFL = new Processo;
	idSolicitacao = 0;

	// Inicia conexão do socket client com o socket remoto (server)
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
		// Incrementa valor dos temporizadores individuais de localização e de estimação
		timerVerificaProcessoNovo += 1;
		timerEstimadorEstados += 1;

		if(timerVerificaProcessoNovo == passoVerificaProcessoNovo)
		{
			// Consulta novo processo no módulo de comunicação via socket
			COMUNICACAO_ConsultaProcessoNovo();
			statusSinc = sincSOLICIT_PROCESSO;

			// Resseta o timer de verificação de processo novo
			timerVerificaProcessoNovo = 0;

			// Resseta o objeto de processo de localização, para receber os parâmetros novos
			processoFL->Resseta();
		}

		if(timerEstimadorEstados == passoEstimadorEstados)
		{
			// Muda o status do sincronizador
			statusSinc = sincSOLICIT_PROCESSO;

			// Executa estimação de estados
			// ... método aqui

			// Resseta o timer de estimação de estados
			timerEstimadorEstados = 0;

			// Restaura o status do sincronizador para stand-by
			statusSinc = sincSTANDBY;
		}
	}
	else if(statusSinc == sincSOLICIT_PROCESSO)  // Em solicitação de novo processo de localização
	{

	}
	else if(statusSinc == sincLOCALIZACAO) // Execução do FL
	{
		// Chama a execução do módulo de LF com o processoLF
		SaidaFL* saidaFL = new SaidaFL;
		dms->ExecutaProcessoFL(processoFL, saidaFL);

		// Envia os dados de saída ao módulo de comunicação
		COMUNICACAO_RetornaSaidaFL(saidaFL);

		// Destroi o objeto de saída
      delete saidaFL;

		// Restaura o status do sincronizador para stand-by
		statusSinc = sincSTANDBY;
   }
}
//---------------------------------------------------------------------------
void __fastcall TSincronizador::clientSktRead(TObject *Sender, TCustomWinSocket *Socket)
{
	const int buffersize = 1000;

	// Recebe a resposta à solicitação de processo
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
			// Pega o conteúdo do alarme
			String conteudoAlarme = ValorCampo(texto, i, "#");

			// Insere dados no objeto de processo de localização
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

	// Adiciona o alarme à lista de alarmes do processo
	processoFL->listaAlarmes->Add(alarme);

	// Ao final do último alarme do processo, pega as características do processo,
	// que se baseiam no alarme mais antigo.
	if(idAlarme == totalAlarmes)
	{
		Alarme* alarme = AUXILIAR_AlarmeMaisAntigo(processoFL->listaAlarmes);
		processoFL->timeStamp = alarme->timeStamp;
		processoFL->codigoAlimentador = alarme->codigoAlimentador;

		// Altera o status do sincronizador, para que inicie o módulo de localização
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
	// Envia texto de consulta de novo evento. Campos: tipo de solicitação e
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

	// ... método para gerar uma string CSV com os parâmetros de saidaFL (soluções)

	clientSkt->Socket->SendText("2;DadosSaida");
}
//---------------------------------------------------------------------------
