//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "TFormDMSCOM.h"
#include "TModuloComunicacao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDMSCOM *FormDMSCOM;
//---------------------------------------------------------------------------
__fastcall TFormDMSCOM::TFormDMSCOM(TComponent* Owner)
	: TForm(Owner)
{
	moduloCom = new TModuloComunicacao(this);
}
//---------------------------------------------------------------------------
__fastcall TFormDMSCOM::~TFormDMSCOM(void)
{
   delete moduloCom;
}
//---------------------------------------------------------------------------
void __fastcall TFormDMSCOM::Button1Click(TObject *Sender)
{
	moduloCom->AdicionarAlarme();
}
//---------------------------------------------------------------------------

