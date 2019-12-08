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
//---------------------------------------------------------------------------
class TModuloComunicacao : TObject
{
public:
	// Parâmetros
	TFormDMSCOM* formDMSCOM;
	TServerSocket *serverSkt;
	TStringList* lisAux_Processos;
	TStringList* lisAux_Processos_lidos;
	int numProcessos;


	// Métodos
	__fastcall TModuloComunicacao(TFormDMSCOM* formDMSCOM);
	__fastcall ~TModuloComunicacao();
	void __fastcall AdicionarProcesso();
	void __fastcall IniciaServerSocket();

	// Comunicação com o DMS
	AnsiString __fastcall CONSULTACLIENT_SolicitacaoProcessoNaoLido();

	// Eventos do server socket
	void __fastcall serverSktClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall serverSktClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall serverSktClientRead(TObject *Sender, TCustomWinSocket *Socket);

};
//---------------------------------------------------------------------------
#endif
