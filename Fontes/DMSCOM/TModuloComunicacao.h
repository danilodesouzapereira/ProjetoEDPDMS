//---------------------------------------------------------------------------
#ifndef TModuloComunicacaoH
#define TModuloComunicacaoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
class TFormDMSCOM;
class TLeitorXML;
class TRecepcaoAlarmes;
//---------------------------------------------------------------------------
class TModuloComunicacao : TObject
{
public:
	// Parâmetros
	TFormDMSCOM* formDMSCOM;
	TServerSocket *serverSkt;
	int numAlarmes;
	TLeitorXML* leitorXML;
	TRecepcaoAlarmes* recepcaoAlarmes;

	TList* listaAlarmes;  //< lista com os novos alarmes enviados pelo front-end
	TList* listaProcessos; //< lista com os processos ainda não lidos pelo DMS
	TList* listaProcessos_lidos; //< lista com os processos lidos pelo DMS


	// Métodos
	__fastcall TModuloComunicacao(TFormDMSCOM* formDMSCOM);
	__fastcall ~TModuloComunicacao();
	void __fastcall AdicionarAlarme();
	void __fastcall IniciaServerSocket();

	// Comunicação com o DMS
	void __fastcall CONSULTACLIENT_SolicitacaoProcessoNaoLido(TStringList* lisEXT);

	// Eventos do server socket
	void __fastcall serverSktClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall serverSktClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall serverSktClientRead(TObject *Sender, TCustomWinSocket *Socket);

};
//---------------------------------------------------------------------------
#endif
