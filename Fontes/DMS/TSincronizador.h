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
	// ::::::::::::::::::::::: Parâmetros :::::::::::::::::::::::

	TClientSocket* clientSkt;
	TDMS*          dms;
	TFormDMS*      formDMS;
	TTimer*        timer;

	int            timerVerificaProcessoNovo;
	int            timerEstimadorEstados;

	int            passoVerificaProcessoNovo;  //< passo de verificação de processo novo no mód. de comunicação
	int            passoEstimadorEstados;  //< passo de execução do estimador de estados
	int            statusSinc;  //< estado do sincronizador

	Processo*      processoFL;  //< processo de localização
	String         timestampProcesso;
   int            idSolicitacao; //< contador de solicitações


	// ::::::::::::::::::::::: Métodos :::::::::::::::::::::::
	__fastcall TSincronizador(TDMS* dms);
	__fastcall ~TSincronizador();
	void __fastcall AtualizaObjProcessoFL(String conteudoAlarme);


   // Métodos auxiliares
	Alarme* __fastcall AUXILIAR_AlarmeMaisAntigo(TList* listaAlarmes);

	// Interações com o módulo de comunicação
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
