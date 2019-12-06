//---------------------------------------------------------------------------
#ifndef TFrameEDPSimplexH
#define TFrameEDPSimplexH
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
class TFrameEDPSimplex : public TFrame
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionManutencaoInsp;
	TImageList *ImageList1;
	TAction *ActionMedicoes;
	TAction *ActionExpansao;
	TAction *ActionManutencaoObras;
	TAction *ActionAjuda;
	TAction *ActionManutencaoObrasPre;
   TAction *ActionManutencaoObrasAuto;
	void __fastcall ActionManutencaoInspExecute(TObject *Sender);
	void __fastcall ActionOcorrenciasExecute(TObject *Sender);
	void __fastcall ActionMedicoesExecute(TObject *Sender);
	void __fastcall ActionCalcIndContExecute(TObject *Sender);
	void __fastcall ActionExpansaoExecute(TObject *Sender);
	void __fastcall ActionManutencaoObrasExecute(TObject *Sender);
	void __fastcall ActionAjudaExecute(TObject *Sender);
	void __fastcall ActionManutencaoObrasPreExecute(TObject *Sender);
   void __fastcall ActionManutencaoObrasAutoExecute(TObject *Sender);

public:      //property
   __property bool Ativo = {write=PM_SetAtivo};

public:		// User declarations
	__fastcall TFrameEDPSimplex(TComponent* Owner, VTApl *apl_owner);
   __fastcall ~TFrameEDPSimplex(void);

private:   //metodos
   void __fastcall PM_SetAtivo(bool ativo);

private:   //objetos externos
   VTApl *apl;
};
//---------------------------------------------------------------------------
#endif
