//---------------------------------------------------------------------------
#ifndef TMetodosAuxiliaresH
#define TMetodosAuxiliaresH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------


// Métodos para processamento de linhas (formato CSV, por exemplo)
String __fastcall AlteraCampo(String linha, int iCampo, String separador, String novoValor);
int    __fastcall NumeroCampos(String linha, String separador);
String __fastcall ValorCampo(String linha, int iCampo, String separador);

// Método envolvendo números
double __fastcall Arredonda(double valIni, int ndigitos);


//---------------------------------------------------------------------------
#endif
