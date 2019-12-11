//---------------------------------------------------------------------------
#ifndef TSincronizadorH
#define TSincronizadorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
struct Alarme;
struct Processo;
struct SaidaFL;
//---------------------------------------------------------------------------
class TDMS;
class TFormDMS;
//---------------------------------------------------------------------------
class TSincronizador
{
public:
	// ::::::::::::::::::::::: Par�metros :::::::::::::::::::::::

	TClientSocket* clientSkt;
	TDMS*          dms;
	TFormDMS*      formDMS;
	TTimer*        timer;

	int            timerVerificaProcessoNovo;
	int            timerEstimadorEstados;

	int            passoVerificaProcessoNovo;  //< passo de verifica��o de processo novo no m�d. de comunica��o
	int            passoEstimadorEstados;  //< passo de execu��o do estimador de estados
	int            statusSinc;  //< estado do sincronizador

	Processo*      processoFL;  //< processo de localiza��o
	String         timestampProcesso;
   int            idSolicitacao; //< contador de solicita��es


	// ::::::::::::::::::::::: M�todos :::::::::::::::::::::::
	__fastcall TSincronizador(TDMS* dms);
	__fastcall ~TSincronizador();
	void __fastcall AtualizaObjProcessoFL(String conteudoAlarme);


   // M�todos auxiliares
	Alarme* __fastcall AUXILIAR_AlarmeMaisAntigo(TList* listaAlarmes);

	// Intera��es com o m�dulo de comunica��o
	void __fastcall COMUNICACAO_ConsultaProcessoNovo();
	void __fastcall COMUNICACAO_RetornaSaidaFL(SaidaFL* saidaFL);

	// Evento do timer
	void __fastcall timerTimer(TObject *Sender);

	// Eventos do client socket
	void __fastcall clientSktRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall clientSktError(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
			 int &ErrorCode);

};
//---------------------------------------------------------------------------
#endif
