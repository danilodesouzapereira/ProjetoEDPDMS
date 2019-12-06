// ---------------------------------------------------------------------------
#ifndef TFormStkChildH
#define TFormStkChildH

// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <System.Actions.hpp>

// ---------------------------------------------------------------------------
class VTApl;
class TFrameEDPSimplex;
// ---------------------------------------------------------------------------
class TFormStkChild : public TForm
{
__published: // IDE-managed Components

	TActionList *ActionList;
	TAction *ActionImportaRedeGIS;
	TAction *ActionGateway;
	TAction *ActionOcorrencias;
	TAction *ActionEnumeracao;
	TAction *ActionAlocaChaves;
	TImageList *ImageList;
	TActionList *ActionListEnerq;
	TAction *ActionSimuladorServer;
	TAction *ActionSimuladorClient;
	TAction *ActionImportaAccess;
	TActionList *ActionList1;
	TAction *ActionRedeCarregada;

	void __fastcall ActionImportaRedeGISExecute(TObject *Sender);
	void __fastcall ActionGatewayExecute(TObject *Sender);
	void __fastcall ActionOcorrenciasExecute(TObject *Sender);
	void __fastcall ActionEnumeracaoExecute(TObject *Sender);
	void __fastcall ActionAlocaChavesExecute(TObject *Sender);
	void __fastcall ActionSimuladorServerExecute(TObject *Sender);
	void __fastcall ActionSimuladorClientExecute(TObject *Sender);
	void __fastcall ActionImportaAccessExecute(TObject *Sender);
	void __fastcall ActionRedeCarregadaExecute(TObject *Sender);

public: // User declarations
	__fastcall TFormStkChild(TComponent *Owner, VTApl *apl, int stk_option);
	__fastcall ~TFormStkChild(void);
	void __fastcall Atualiza(void);

private: // métodos
	TWinControl* __fastcall SelecionaParentParaJanela(void);

	// objetos externos
	VTApl *apl;
	TFrameEDPSimplex *FrameEDPSimplex;
};

// ---------------------------------------------------------------------------
#endif
// eof
