//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Diretorio\VTPath.h>
//---------------------------------------------------------------------------
#include <ProjetoEDPDMS\DLL_Inc\EE.h>
#include <ProjetoEDPDMS\DLL_Inc\FL.h>
#include <ProjetoEDPDMS\Fontes\DMS\Modelos.h>
#include <ProjetoEDPDMS\Fontes\EE\VTEE.h>
#include <ProjetoEDPDMS\Fontes\FL\VTFL.h>
//---------------------------------------------------------------------------
#include "TDMS.h"
#include "TFormDMS.h"
#include "TSincronizador.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TDMS::TDMS(VTApl* apl, TFormDMS* formDMS)
{
	this->apl = apl;
	this->formDMS = formDMS;
	path = (VTPath*) apl->GetObject(__classid(VTPath));

	// Inicializa a aplicação (EXE) de comunicação
	AnsiString comando = path->DirDat() + "\\..\\Bin\\DMSCOM.exe";
	comando = "C:\\Projetos\\SINAPgrid\\PlataformaSinap\\Tmp\\Bin\\Win32\\Debug\\DMSCOM.exe";
	wchar_t* wchar_comando = new wchar_t[comando.Length()];
	comando.WideChar(wchar_comando, comando.Length());
//	std::system(comando.c_str());
//   ShellExecute(0, "open", "cmd.exe", comando, 0, SW_HIDE);
//	ShellExecute(0, NULL, L"C:\\Sinapsis\\SINAPgrid\\Bin\\DMSCOM.exe", L"-l", 0, SW_SHOW);
	ShellExecute(0, NULL, wchar_comando, L"-l", 0, SW_SHOW);


	sinc = new TSincronizador(this);
}
//---------------------------------------------------------------------------
__fastcall TDMS::~TDMS()
{
	// Destroi objetos
   delete sinc;
}
//---------------------------------------------------------------------------
void __fastcall TDMS::IniciaProcessoFL()
{
	EntradaFL* entradaFL = new EntradaFL();
	entradaFL->codigoRede = "ALE06";

	// Cria objeto de localizador, executa e destroi objeto
	localizador = DLL_NewFL(apl);
	localizador->ExecutaProcesso(entradaFL);

	// Destroi objetos
	delete entradaFL;
	delete localizador;
}
//---------------------------------------------------------------------------
void __fastcall TDMS::IniciaProcessoEstimacao()
{
	estimador = DLL_NewEE(apl);
	estimador->ExecutaEstimacaoDiaria();
	delete estimador;
}
//---------------------------------------------------------------------------
void __fastcall TDMS::CONSULTA_COMUNICACAO_ConsultaEventoNovo()
{
   sinc->CONSULTA_COMUNICACAO_ConsultaEventoNovo();
}
//---------------------------------------------------------------------------

