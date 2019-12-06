//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <PlataformaSinap\Fontes\Diretorio\VTPath.h>
#include <PlataformaSinap\Fontes\Rede\VTRede.h>
#include <PlataformaSinap\Fontes\Rede\VTRedes.h>
#include <PlataformaSinap\Fontes\Rede\VTTipoRede.h>
//---------------------------------------------------------------------------
#include <ProjetoEDPDMS\DLL_Inc\EE.h>
#include <ProjetoEDPDMS\DLL_Inc\FL.h>
#include <ProjetoEDPDMS\DLL_Inc\TopologiaDMS.h>
#include <ProjetoEDPDMS\Fontes\DMS\Modelos.h>
#include <ProjetoEDPDMS\Fontes\EE\TEE.h>
#include <ProjetoEDPDMS\Fontes\FL\TFL.h>
#include <ProjetoEDPDMS\Fontes\TopologiaDMS\TTopologiaDMS.h>
//---------------------------------------------------------------------------
#include "TDMS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TDMS::TDMS(VTApl* apl)
{
	this->apl = apl;
	path = (VTPath*) apl->GetObject(__classid(VTPath));

	// Cria objetos principais da solução de DMS
	VTRedes* redes = (VTRedes*) apl->GetObject(__classid(VTRedes));
	VTRede* rede = NULL;
	for(int i=0; i<redes->LisRede()->Count; i++)
	{
		rede = (VTRede*) redes->LisRede()->Items[i];
		if(!rede->Carregada || rede->TipoRede->Segmento != redePRI) continue;
		break;
   }
	topologia = DLL_NewTopologiaDMS(apl, rede);


	estimador = DLL_NewEE(apl);
	localizador = DLL_NewFL(topologia);

	// Inicializa a aplicação (EXE) de comunicação
	AnsiString comando = path->DirDat() + "\\..\\Bin\\DMSCOM.exe";
	comando = "C:\\Sinapsis\\SINAPgrid\\Bin\\DMSCOM.exe";
	wchar_t* wchar_comando = new wchar_t[comando.Length()];
	comando.WideChar(wchar_comando, comando.Length());
//	std::system(comando.c_str());
//   ShellExecute(0, "open", "cmd.exe", comando, 0, SW_HIDE);
//	ShellExecute(0, NULL, L"C:\\Sinapsis\\SINAPgrid\\Bin\\DMSCOM.exe", L"-l", 0, SW_SHOW);
	ShellExecute(0, NULL, wchar_comando, L"-l", 0, SW_SHOW);
}
//---------------------------------------------------------------------------
__fastcall TDMS::~TDMS()
{
	// Destroi objetos
	DLL_DeleteFL(localizador);
	DLL_DeleteEE(estimador);
	DLL_DeleteTopologiaDMS(topologia);
}
//---------------------------------------------------------------------------
void __fastcall TDMS::IniciaProcessoFL()
{
	EntradaFL* entradaFL = new EntradaFL();
	entradaFL->codigoRede = "VIT01";
	localizador->IniciarProcesso(entradaFL);
	delete entradaFL; entradaFL = NULL;
}
//---------------------------------------------------------------------------
