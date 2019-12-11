//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <PlataformaSinap\Fontes\Apl\VTApl.h>
#include <ProjetoEDPDMS\Fontes\DMS\TDMS.h>
#include <ProjetoEDPDMS\Fontes\DMS\TSincronizador.h>
//---------------------------------------------------------------------------
#include "TFormDMS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDMS *FormDMS;
//---------------------------------------------------------------------------
__fastcall TFormDMS::TFormDMS(TComponent *Owner, VTApl *apl_owner, TWinControl *parent)
	: TForm(Owner)
{
	// Salva apl
	apl = apl_owner;

	// Cria objeto de DMS. Demais gerenciamentos a partir de dms.
	dms = new TDMS(apl, this);
}
//---------------------------------------------------------------------------
__fastcall TFormDMS::~TFormDMS()
{
	// Destroi objetos
   delete dms;
}
//---------------------------------------------------------------------------
