//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include "TFrameEDP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#include <ModulosOpcionais\DLL_Inc\ExtratorOcorrencias.h>
#include <ProjetoEDP\Dll_Inc\ManutencaoInsp.h>
#include <ProjetoEDP\Dll_Inc\ManutencaoObras.h>
#include <ProjetoEDP\Dll_Inc\ManutencaoObrasPre.h>
#include <ProjetoEDP\Dll_Inc\SimplexExpansao.h>
#include <ProjetoEDP\Dll_Inc\MedicoesSimplex.h>
#include <ProjetoEDP\Dll_Inc\AjudaSimplex.h>
#include <PlataformaSinap\DLL_Inc\CalcIndCont.h>
#include <PlataformaSinap\Fontes\MultiMonitor\VTMultiPanel.h>
//---------------------------------------------------------------------------
__fastcall TFrameEDP::TFrameEDP(TComponent* Owner, VTApl *apl_owner)
	: TFrame(Owner)
{
   //salva ponteiro
   apl = apl_owner;
}
//---------------------------------------------------------------------------
__fastcall TFrameEDP::~TFrameEDP(void)
{
	//nada a fazer
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDP::PM_SetAtivo(bool ativo)
{
	//nada a fazer
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDP::ActionManutencaoInspExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormManutencaoInsp(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDP::ActionOcorrenciasExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormExtratorDados(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDP::ActionMedicoesExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormMedicoesSimplex(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDP::ActionCalcIndContExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
   Form = DLL_NewFormCalcIndCont(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDP::ActionExpansaoExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
   Form = DLL_NewFormExpansao(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDP::ActionManutencaoObrasExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormManutencaoObras(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDP::ActionAjudaExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormAjudaSimplex(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDP::ActionManutencaoObrasPreExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormManutencaoObrasPre(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------


