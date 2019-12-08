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
class TDMS;
class TFormDMS;
//---------------------------------------------------------------------------
class TSincronizador
{
public:
	// Parâmetros
	TDMS* dms;
	TFormDMS* formDMS;
	TClientSocket *clientSkt;

	// Métodos
	__fastcall TSincronizador(TDMS* dms);
	__fastcall ~TSincronizador();

	// Interações com o módulo de comunicação
	void __fastcall CONSULTA_COMUNICACAO_ConsultaEventoNovo();

	// Eventos do client socket
	void __fastcall clientSktRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall clientSktError(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
			 int &ErrorCode);

};
//---------------------------------------------------------------------------
#endif
