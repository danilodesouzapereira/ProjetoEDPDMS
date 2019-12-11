//---------------------------------------------------------------------------
#ifndef VTFLH
#define VTFLH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TTopologiaDMS;
class VTApl;
//---------------------------------------------------------------------------
struct Processo;
struct SaidaFL;
//---------------------------------------------------------------------------
class VTFL : public TObject
{
public:

	// Parâmetros
	Processo*      processoFL;
	SaidaFL*       saidaFL;
	TTopologiaDMS* topologiaDMS;
	VTApl*         apl;


	// Métodos
		  __fastcall  VTFL(void) {};
		  __fastcall ~VTFL(void) {};

	virtual void __fastcall CriaObjTopologia() = 0;
	virtual void __fastcall ExecutaProcessoFL(Processo* processoFL) = 0;
	virtual void __fastcall IniciaObjTopologia() = 0;
	virtual void __fastcall ObtemLocalizacao(SaidaFL* saidaFL) = 0;
};
//---------------------------------------------------------------------------
VTFL* __fastcall NewObjFL(VTApl *apl);
//---------------------------------------------------------------------------
#endif