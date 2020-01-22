//---------------------------------------------------------------------------
#ifndef TRecepcaoAlarmesH
#define TRecepcaoAlarmesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
struct Alarme;
class TFormDMSCOM;
class TModuloComunicacao;
struct Processo;
//---------------------------------------------------------------------------
class TRecepcaoAlarmes : TObject
{
public:

	// Parâmetros
	TFormDMSCOM* formDMSCOM;
   TModuloComunicacao* moduloComunicacao;

   TTimer* timer;
	int passo;
	int contadorTempo;
	TStringList* lisNomesArqAlarmesAnalisados;

	// Construtor e destrutor
	__fastcall TRecepcaoAlarmes(TFormDMSCOM* formDMSCOM, TModuloComunicacao* moduloComunicacao);
	__fastcall ~TRecepcaoAlarmes();

	void __fastcall Inicia();
	void __fastcall TimerOnTimer(TObject *Sender);
	void __fastcall VerificaAlarmesArquivo(String pathDiretorio, String nomeArquivo);
	void __fastcall VerificaNovosAlarmes();

	// Auxiliares
	bool __fastcall AlarmesProximos(Alarme* alarmeExist, Alarme* alarme);
	Processo* __fastcall EncontraProcesso(Alarme* alarme);
	void __fastcall NomesArquivosDiretorio(String folder, String extensaoArquivos, TStringList* listaArquivos);
};
//---------------------------------------------------------------------------
#endif
