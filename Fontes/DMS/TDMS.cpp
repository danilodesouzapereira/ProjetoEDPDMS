//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Diretorio\VTPath.h>
//---------------------------------------------------------------------------
#include <ProjetoEDPDMS\DLL_Inc\EE.h>
#include <ProjetoEDPDMS\DLL_Inc\FL.h>
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
	// Salva par�metros
	this->apl = apl;
	this->formDMS = formDMS;
	path = (VTPath*) apl->GetObject(__classid(VTPath));

	// Inicializa a aplica��o (EXE) de comunica��o
	AnsiString comando = "C:\\Projetos\\SINAPgrid\\PlataformaSinap\\Tmp\\Bin\\Win32\\Debug\\DMSCOM.exe";
	wchar_t* wchar_comando = new wchar_t[comando.Length()];
	comando.WideChar(wchar_comando, comando.Length());
	ShellExecute(0, NULL, wchar_comando, L"-l", 0, SW_SHOW);

	// Cria objeto sincronizador
	sinc = new TSincronizador(this);
}
//---------------------------------------------------------------------------
__fastcall TDMS::~TDMS()
{
	// Finaliza aplica��o (EXE) de comunica��o
	system("taskkill /IM DMSCOM.exe");

	// Destroi objetos
   delete sinc;
}
//---------------------------------------------------------------------------
void __fastcall TDMS::ExecutaProcessoFL(Processo* processoFL, SaidaFL* saidaFL_EXT)
{
	// Cria objeto de localizador e executa processo de localiza��o
	localizador = DLL_NewFL(apl);
	localizador->ExecutaProcessoFL(processoFL);

	// Obt�m os resultados (sa�da)
	localizador->ObtemLocalizacao(saidaFL_EXT);

	// Destroi objeto de localiza��o
	delete localizador;
}
//---------------------------------------------------------------------------
void __fastcall TDMS::IniciaProcessoEstimacao()
{
	// Cria objeto de estima��o de estados (EE) e executa a EE
	estimador = DLL_NewEE(apl);
	estimador->ExecutaEstimacaoDiaria();

	// Destroi objeto de EE
	delete estimador;
}
//---------------------------------------------------------------------------

