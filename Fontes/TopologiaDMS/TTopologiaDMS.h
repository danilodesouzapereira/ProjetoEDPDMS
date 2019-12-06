//---------------------------------------------------------------------------
#ifndef TTopologiaDMSH
#define TTopologiaDMSH
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
//---------------------------------------------------------------------------
class TTopologiaDMS : public TObject
{
public:
	// Parâmetros elementares
	VTApl* apl;
	VTRede* rede;

	TList* lisBlocoRad;
	TDisjuntor* disjuntor;
	TList* lisReligadoras;

	// Métodos
				__fastcall TTopologiaDMS(VTApl* apl, VTRede* rede);
				__fastcall ~TTopologiaDMS();

	VTChave* __fastcall ChaveBloco(VTBloco* bloco);
	void     __fastcall DestroiEqptosTopologia();
	void     __fastcall DeterminaBlocosRadiais();
	void     __fastcall IniciaTopologiaRede();
	void     __fastcall OrdenaBlocosRadiais();

	// Métodos de busca
	void     __fastcall BUSCA_BlocosRadJusanteLigacao(String codigoLigacao, TList* lisEXT);
	void     __fastcall BUSCA_BlocosRadJusanteLigacao(VTLigacao* ligacao, TList* lisEXT);
};
//---------------------------------------------------------------------------
#endif
