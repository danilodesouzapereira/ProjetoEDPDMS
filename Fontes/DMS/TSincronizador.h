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
	// Par�metros
	TDMS* dms;
	TFormDMS* formDMS;
	TClientSocket *clientSkt;

	// M�todos
	__fastcall TSincronizador(TDMS* dms);
	__fastcall ~TSincronizador();

	// Intera��es com o m�dulo de comunica��o
	void __fastcall CONSULTA_COMUNICACAO_ConsultaEventoNovo();

	// Eventos do client socket
	void __fastcall clientSktRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall clientSktError(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
			 int &ErrorCode);

};
//---------------------------------------------------------------------------
#endif
