//---------------------------------------------------------------------------
#ifndef TMetodosAuxiliaresH
#define TMetodosAuxiliaresH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------

// Métodos envolvendo timestamp e datetime
TDateTime __fastcall Timestamp_To_DateTime(String timestamp);
String __fastcall DateTime_To_Timestamp(TDateTime dt);

// Métodos para processamento de linhas (formato CSV, por exemplo)
String __fastcall AlteraCampo(String linha, int iCampo, String separador, String novoValor);
int    __fastcall NumeroCampos(String linha, String separador);
String __fastcall ValorCampo(String linha, int iCampo, String separador);

// Método envolvendo números
double __fastcall Arredonda(double valIni, int ndigitos);

bool __fastcall AlimentadoresIguais(String codigo1, String codigo2);
bool __fastcall AlimentadorPertenceSubestacao(String codigoSE, String codigoAlimentador);
bool __fastcall ChavesIguais(String codigo1, String codigo2);
bool __fastcall TrafosIguais(String codigo1, String codigo2);
void __fastcall NomesArquivosDiretorio(String folder, String extensaoArquivos, TStringList* listaArquivos);

void __fastcall CopiaObjetos(TList* lisOri, TList* lisFinal);
//---------------------------------------------------------------------------
#endif
