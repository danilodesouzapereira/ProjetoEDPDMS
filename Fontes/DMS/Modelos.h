//#include <Classes.hpp>
//---------------------------------------------------------------------------
struct Alarme : public TObject
{
	AnsiString timeStamp;
	AnsiString codigoEqpto;
	AnsiString localInstalacao;
	int        tipoEqpto;
	int        tipoAlarme;
	__fastcall Alarme()
	{
		timeStamp = ""; codigoEqpto = "";
		localInstalacao = ""; tipoEqpto = -1; tipoAlarme = -1;
	}
};
//---------------------------------------------------------------------------
struct EntradaFL : public TObject
{
	AnsiString codigoRede;
	TList* listaAlarmes;
	__fastcall EntradaFL() {listaAlarmes = new TList; codigoRede = "";}
	__fastcall ~EntradaFL()
	{
		for(int i=listaAlarmes->Count-1; i>=0; i--) delete listaAlarmes->Items[i];
		delete listaAlarmes;
	}
};
//---------------------------------------------------------------------------
struct SaidaFL_Gerais : public TObject
{
	AnsiString timeStampEvento;
	AnsiString codigoAlimentador;
	__fastcall SaidaFL_Gerais() {timeStampEvento = ""; codigoAlimentador = "";}
};
//---------------------------------------------------------------------------
struct SaidaFL_Diagnostico : public TObject
{
	int tipoEvento;
	int numSolucoes;
	int numErros;
	__fastcall SaidaFL_Diagnostico() {tipoEvento = -1; numSolucoes = 0; numErros = 0;}
};
//---------------------------------------------------------------------------
struct SaidaFL_Solucao : public TObject
{
	AnsiString codigoChaveMontante;
	double coordX_metros;
	double coordY_metros;

};
//---------------------------------------------------------------------------
struct SaidaFL : public TObject
{
	SaidaFL_Gerais* saidaGerais;
	SaidaFL_Diagnostico* saidaDiagnostico;

	TList* listaAlarmes;
	TList* listaSolucoesFL;

	__fastcall SaidaFL()
	{
		listaAlarmes = new TList;
		listaSolucoesFL = new TList;
	}
	__fastcall ~SaidaFL()
	{
		for(int i=listaAlarmes->Count-1; i>=0; i--) delete listaAlarmes->Items[i];
		for(int i=listaSolucoesFL->Count-1; i>=0; i--) delete listaSolucoesFL->Items[i];
		delete listaAlarmes; delete listaSolucoesFL;
   }
};
//---------------------------------------------------------------------------
