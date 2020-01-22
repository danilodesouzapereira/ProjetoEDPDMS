//---------------------------------------------------------------------------
#ifndef TTopologiaDMSH
#define TTopologiaDMSH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "VTTopologiaDMS.h"
//---------------------------------------------------------------------------
class TArea;
class TDisjuntor;
class TEqptoAutomacao;
class TFusivel;
class TReligadora;
class TTrafo;
class VTApl;
class VTBloco;
class VTChave;
class VTLigacao;
class VTPath;
class VTRede;
struct Processo;
//---------------------------------------------------------------------------
class TTopologiaDMS : public VTTopologiaDMS
{
public:
	// Parâmetros elementares
	VTApl*       apl;
	VTPath*      path;
	VTRede*      rede;
	TStringList* lisCodSEs;
	bool         protecoesCoordenadas;

	TArea*      area;           //< Contém objetos BlocoRad relativos à área de busca
	TList*      lisBlocoRad;    //< Lista com todos os objetos BlocoRad do alimentador

	TDisjuntor* disjuntor;
	TList*      lisReligadoras;
	TList*      lisFusiveis;
	TList*      lisTrafos;

	// Métodos
				__fastcall TTopologiaDMS(VTApl* apl, String codigoRede);
				__fastcall ~TTopologiaDMS(void);

	VTChave* __fastcall ChaveBloco(VTBloco* bloco);
	void     __fastcall CriaObjEqptosAutomacao();
	void     __fastcall CriaObjEqptosDado(Processo* processoFL);
	void     __fastcall CriaObjEqptosTrafos();
	void     __fastcall DestroiEqptosTopologia();
	void     __fastcall DeterminaAreaBuscaFalta();
	void     __fastcall DeterminaAreaBuscaRompCabo(Processo* processoFL);
	void     __fastcall DeterminaBlocosRadiais();
	void     __fastcall DeterminaBlocosRadJusanteEqptosAutomacao();
	void     __fastcall DeterminaBlocosRadZonaProtecaoEqptosAutomacao();
	VTRede*  __fastcall DeterminaObjRede(String codigoRede);
	void     __fastcall FinalizaTopologiaRede();
	void     __fastcall IniciaTopologiaRede(Processo* processoFL);
	void     __fastcall OrdenaBlocosRadiais();

	void     __fastcall RemoveBlocosRad_ProtJusanteDisjuntor();
	void     __fastcall RemoveBlocosRad_ProtJusanteReligadora(TReligadora* religadora);
	void     __fastcall RemoveBlocosRad_ProtJusanteFusivel(TFusivel* fusivel);

	// Métodos de busca
	void     __fastcall BUSCA_BlocosRadJusanteLigacao(String codigoLigacao, TList* lisEXT);
	void     __fastcall BUSCA_BlocosRadJusanteLigacao(VTLigacao* ligacao, TList* lisEXT);

	// Abertura de redes do Sinap
	void __fastcall AbreRedesSinap(String codigoAlimentador);
	bool __fastcall CarregaCodigosSubestacoes(AnsiString arq_mdb, bool atualiza_grafico);
	bool __fastcall CarregaRede(AnsiString arq_mdb, AnsiString codigoSE, AnsiString codigoAlimentador);

	// Auxiliares
	void         __fastcall AnalisaTiposAlarmesProtecao(TList* lisAux_Eqptos_Lockout, TList* lisAux_Eqptos_TentRelig);
	TReligadora* __fastcall Religadora_Codigo(String codigoReligadora);
	void         __fastcall SubtraiBlocosRad(TList* lisBlocosRad_maior, TList* lisBlocosRad_menor);
	TTrafo*      __fastcall Trafo_Codigo(String codigoTrafo);
	void         __fastcall Verifica_VTOrdena();
};
//---------------------------------------------------------------------------
#endif
