//---------------------------------------------------------------------------
#pragma hdrstop
#include "TFormDMSCOM.h"
#include "TLeitorXML.h"
#include "TModuloComunicacao.h"
#include "TRecepcaoAlarmes.h"
#include "..\Uteis\TMetodosAuxiliares.h"
#include "..\Uteis\Modelos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TRecepcaoAlarmes::TRecepcaoAlarmes(TFormDMSCOM* formDMSCOM, TModuloComunicacao* moduloComunicacao)
{
	this->formDMSCOM = formDMSCOM;
	this->moduloComunicacao = moduloComunicacao;
	timer = new TTimer(NULL);
	timer->OnTimer = TimerOnTimer;
	timer->Enabled = false;
	lisNomesArqAlarmesAnalisados = new TStringList;
}
//---------------------------------------------------------------------------
__fastcall TRecepcaoAlarmes::~TRecepcaoAlarmes()
{
	delete lisNomesArqAlarmesAnalisados;
}
//---------------------------------------------------------------------------
void __fastcall TRecepcaoAlarmes::Inicia()
{
	timer->Enabled = true;
	passo = 5;
	contadorTempo = 0;
}
//---------------------------------------------------------------------------
void __fastcall TRecepcaoAlarmes::TimerOnTimer(TObject *Sender)
{
	// Incrementa o contador de tempo
	contadorTempo += 1;

	// Se estiver dentro do passo, retorna
	if(contadorTempo < passo) return;

	// Se atingir o passo, resseta o contador
	contadorTempo = 0;

   // Verifica se existem novos alarmes
	VerificaNovosAlarmes();
}
//---------------------------------------------------------------------------
void __fastcall TRecepcaoAlarmes::VerificaAlarmesArquivo(String pathDiretorio, String nomeArquivo)
{
	TList* listaAux_Alarmes = new TList;

	TLeitorXML* leitorXML = new TLeitorXML(pathDiretorio, formDMSCOM);
	leitorXML->LeAlarmes_StringCSV(nomeArquivo, listaAux_Alarmes);

	for(int i=0; i<listaAux_Alarmes->Count; i++)
	{
		Alarme* alarme = (Alarme*)listaAux_Alarmes->Items[i];

		Processo* processo = EncontraProcesso(alarme);

		if(processo)
		{
			processo->timeStamp = alarme->timeStamp;
			processo->codigoAlimentador = alarme->codigoAlimentador;
			processo->listaAlarmes->Add(alarme);
		}
		else
		{
			processo = new Processo;
			moduloComunicacao->listaProcessos->Add(processo);
			processo->timeStamp = alarme->timeStamp;
			processo->codigoAlimentador = alarme->codigoAlimentador;
			processo->listaAlarmes->Add(alarme);
			formDMSCOM->Memo2->Lines->Add(processo->timeStamp);
		}
	}

	delete listaAux_Alarmes;
}
//---------------------------------------------------------------------------
Processo* __fastcall TRecepcaoAlarmes::EncontraProcesso(Alarme* alarme)
{
	if(!alarme) return(NULL);

	for(int i=0; i<moduloComunicacao->listaProcessos->Count; i++)
	{
		Processo* processo = (Processo*)moduloComunicacao->listaProcessos->Items[i];
		for(int j=0; j<processo->listaAlarmes->Count; j++)
		{
			Alarme* alarmeExist = (Alarme*)processo->listaAlarmes->Items[j];

			if(alarmeExist->codigoAlimentador != alarme->codigoAlimentador) continue;
			if(!AlarmesProximos(alarmeExist, alarme)) continue;

			return(processo);
		}
	}
	return(NULL);
}
//---------------------------------------------------------------------------
bool __fastcall TRecepcaoAlarmes::AlarmesProximos(Alarme* alarmeExist, Alarme* alarme)
{
	if(!alarmeExist || !alarme) return(false);

	double totalMinutos;
	String ts1, ts2;
	TDateTime dt1, dt2, deltadt;
	unsigned short h, m, s, ms;

	ts1 = alarmeExist->timeStamp;
	ts2 = alarme->timeStamp;

	dt1 = Timestamp_To_DateTime(ts1);
	dt2 = Timestamp_To_DateTime(ts2);

	deltadt = (dt2 > dt1) ? dt2 - dt1 : dt1 - dt2;
	deltadt.DecodeTime(&h, &m, &s, &ms);
	totalMinutos = (h * 3600 + m * 60) / 60.;

	// Retorna se a diferença de tempo é menor que 3 minutos
	return(totalMinutos < 3.);
}
//---------------------------------------------------------------------------
void __fastcall TRecepcaoAlarmes::VerificaNovosAlarmes()
{
	TStringList* lisNomesArquivos = new TStringList;
	String caminhoPasta = "c:\\users\\sinapsis\\desktop";

	NomesArquivosDiretorio(caminhoPasta, "xml", lisNomesArquivos);
	for(int i=0; i<lisNomesArquivos->Count; i++)
	{
		String nomeArquivo = lisNomesArquivos->Strings[i];
		if(lisNomesArqAlarmesAnalisados->IndexOf(nomeArquivo) != -1) continue;

		lisNomesArqAlarmesAnalisados->Add(nomeArquivo);
		VerificaAlarmesArquivo(caminhoPasta, nomeArquivo);
   }

	delete lisNomesArquivos;
}
//---------------------------------------------------------------------------
void __fastcall TRecepcaoAlarmes::NomesArquivosDiretorio(String folder, String extensaoArquivos, TStringList* listaArquivos)
{
	if(listaArquivos == NULL) return;

	String search_path = folder + "/*." + extensaoArquivos;
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
   if(hFind != INVALID_HANDLE_VALUE) {
      do {
         // read all (real) files in current folder
         // , delete '!' read other 2 default folder . and ..
         if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
         listaArquivos->Add(fd.cFileName);
      	}
      }while(::FindNextFile(hFind, &fd));
      ::FindClose(hFind);
   }
}
//---------------------------------------------------------------------------
