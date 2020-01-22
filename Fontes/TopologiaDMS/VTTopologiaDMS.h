//---------------------------------------------------------------------------
#ifndef VTTopologiaDMSH
#define VTTopologiaDMSH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TDisjuntor;
class VTApl;
class VTBloco;
class VTChave;
class VTLigacao;
class VTRede;
struct Processo;
//---------------------------------------------------------------------------
class VTTopologiaDMS : public TObject
{
public:
	// Parâmetros elementares
	VTApl* apl;
	VTRede* rede;

	TList* lisBlocoRad;
	TDisjuntor* disjuntor;
	TList* lisReligadoras;

	// Métodos
				__fastcall  VTTopologiaDMS(void) {};
				__fastcall ~VTTopologiaDMS(void) {};

	virtual VTChave* __fastcall ChaveBloco(VTBloco* bloco) = 0;
	virtual void     __fastcall DestroiEqptosTopologia() = 0;
	virtual void     __fastcall DeterminaAreaBuscaFalta() = 0;
	virtual void     __fastcall DeterminaAreaBuscaRompCabo(Processo* processoFL) = 0;
	virtual void     __fastcall DeterminaBlocosRadiais() = 0;
	virtual VTRede*  __fastcall DeterminaObjRede(String codigoRede) = 0;
	virtual void     __fastcall IniciaTopologiaRede(Processo* processoFL) = 0;
	virtual void     __fastcall FinalizaTopologiaRede() = 0;
	virtual void     __fastcall OrdenaBlocosRadiais() = 0;

	// Métodos de busca
	virtual void     __fastcall BUSCA_BlocosRadJusanteLigacao(String codigoLigacao, TList* lisEXT) = 0;
	virtual void     __fastcall BUSCA_BlocosRadJusanteLigacao(VTLigacao* ligacao, TList* lisEXT) = 0;
};
//---------------------------------------------------------------------------
VTTopologiaDMS* __fastcall  NewObjTopologiaDMS(VTApl* apl, String codigoRede);
//---------------------------------------------------------------------------
#endif