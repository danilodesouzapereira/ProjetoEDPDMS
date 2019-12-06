//---------------------------------------------------------------------------
#ifndef TBlocoDMSH
#define TBlocoDMSH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class VTBloco;
class VTChave;
//---------------------------------------------------------------------------
class TBlocoDMS : public TObject
{
public:

	// Dados
	VTBloco*   bloco;
	TBlocoDMS* blocoDMSmontante;
	VTChave*   chave;
	TList*     lisBlocoDMSjusante;

	// Métodos
	__fastcall TBlocoDMS();
	__fastcall ~TBlocoDMS();
};
//---------------------------------------------------------------------------
#endif
