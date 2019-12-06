//---------------------------------------------------------------------------
#ifndef TMetodosAuxiliaresH
#define TMetodosAuxiliaresH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------


// M�todos para processamento de linhas (formato CSV, por exemplo)
String __fastcall AlteraCampo(String linha, int iCampo, String separador, String novoValor);
int    __fastcall NumeroCampos(String linha, String separador);
String __fastcall ValorCampo(String linha, int iCampo, String separador);

// M�todo envolvendo n�meros
double __fastcall Arredonda(double valIni, int ndigitos);


//---------------------------------------------------------------------------
#endif
