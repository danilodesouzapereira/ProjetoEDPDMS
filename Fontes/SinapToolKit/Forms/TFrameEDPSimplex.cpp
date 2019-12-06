//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include "TFrameEDPSimplex.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#include <ModulosOpcionais\DLL_Inc\ExtratorOcorrencias.h>
#include <ProjetoEDP\Dll_Inc\ManutencaoInsp.h>
#include <ProjetoEDP\Dll_Inc\ManutencaoObras.h>
#include <ProjetoEDP\Dll_Inc\ManutencaoObrasAuto.h>
#include <ProjetoEDP\Dll_Inc\ManutencaoObrasPre.h>
#include <ProjetoEDP\Dll_Inc\SimplexExpansao.h>
#include <ProjetoEDP\Dll_Inc\MedicoesSimplex.h>
#include <ProjetoEDP\Dll_Inc\AjudaSimplex.h>
#include <PlataformaSinap\DLL_Inc\CalcIndCont.h>
#include <PlataformaSinap\Fontes\MultiMonitor\VTMultiPanel.h>
//---------------------------------------------------------------------------
__fastcall TFrameEDPSimplex::TFrameEDPSimplex(TComponent* Owner, VTApl *apl_owner)
	: TFrame(Owner)
{
   //salva ponteiro
   apl = apl_owner;
}
//---------------------------------------------------------------------------
__fastcall TFrameEDPSimplex::~TFrameEDPSimplex(void)
{
	//nada a fazer
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::PM_SetAtivo(bool ativo)
{
	//nada a fazer
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::ActionManutencaoInspExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormManutencaoInsp(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::ActionOcorrenciasExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormExtratorDados(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::ActionMedicoesExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormMedicoesSimplex(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::ActionCalcIndContExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
   Form = DLL_NewFormCalcIndCont(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::ActionExpansaoExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
   Form = DLL_NewFormExpansao(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::ActionManutencaoObrasExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormManutencaoObras(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::ActionAjudaExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormAjudaSimplex(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::ActionManutencaoObrasPreExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormManutencaoObrasPre(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPSimplex::ActionManutencaoObrasAutoExecute(TObject *Sender)
{
//	TForm *Form;
//	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
//	Form = DLL_NewFormManutencaoObrasAuto(this, apl, MultiPanel->PanelAtivo);
//	Form->Show();

   DLL_IniciaManutencaoObrasAuto(this, apl, true, true);
}
//---------------------------------------------------------------------------


