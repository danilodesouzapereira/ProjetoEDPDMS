//---------------------------------------------------------------------------
#ifndef TFrameEDPDMSH
#define TFrameEDPDMSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class VTApl;
//---------------------------------------------------------------------------
class TFrameEDPDMS : public TFrame
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TImageList *ImageList1;
	TAction *ActionDMS;
	void __fastcall ActionDMSExecute(TObject *Sender);

public:      //property
   __property bool Ativo = {write=PM_SetAtivo};

public:		// User declarations
	__fastcall TFrameEDPDMS(TComponent* Owner, VTApl *apl_owner);
   __fastcall ~TFrameEDPDMS(void);

private:   //metodos
   void __fastcall PM_SetAtivo(bool ativo);

private:   //objetos externos
   VTApl *apl;
};
//---------------------------------------------------------------------------
#endif
