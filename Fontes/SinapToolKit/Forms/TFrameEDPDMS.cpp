//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include "TFrameEDPDMS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#include <ProjetoEDPDMS\Dll_Inc\DMS.h>
#include <PlataformaSinap\Fontes\MultiMonitor\VTMultiPanel.h>
//---------------------------------------------------------------------------
__fastcall TFrameEDPDMS::TFrameEDPDMS(TComponent* Owner, VTApl *apl_owner)
	: TFrame(Owner)
{
   //salva ponteiro
   apl = apl_owner;
}
//---------------------------------------------------------------------------
__fastcall TFrameEDPDMS::~TFrameEDPDMS(void)
{
	//nada a fazer
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPDMS::PM_SetAtivo(bool ativo)
{
	//nada a fazer
}
//---------------------------------------------------------------------------
void __fastcall TFrameEDPDMS::ActionDMSExecute(TObject *Sender)
{
	TForm *Form;
	VTMultiPanel *MultiPanel = (VTMultiPanel*)apl->GetObject(__classid(VTMultiPanel));
	Form = DLL_NewFormDMS(this, apl, MultiPanel->PanelAtivo);
	Form->Show();
}
//---------------------------------------------------------------------------

