//---------------------------------------------------------------------------
#pragma hdrstop
#include "TMetodosAuxiliares.h"
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TDateTime __fastcall Timestamp_To_DateTime(String timestamp)
{
	if(timestamp == "") return(NULL);
	unsigned short yr, mth, day, hr, min, seg, mseg;

	yr = timestamp.SubString(1,4).ToInt();
	mth = timestamp.SubString(5,2).ToInt();
	day = timestamp.SubString(7,2).ToInt();
	hr = timestamp.SubString(9,2).ToInt();
	min = timestamp.SubString(11,2).ToInt();
	seg = timestamp.SubString(13,2).ToInt();
	mseg = 0;

	TDateTime dt = TDateTime(yr, mth, day, hr, min, seg, mseg);
	return(dt);
}
//---------------------------------------------------------------------------
String __fastcall DateTime_To_Timestamp(TDateTime dt)
{
	unsigned short yr, mth, day, hr, min, seg, mseg;

	dt.DecodeDate(&yr, &mth, &day);
	dt.DecodeTime(&hr, &min, &seg, &mseg);

	String timestamp = String(yr);
	if(mth < 10) timestamp += "0" + String(mth); else timestamp += String(mth);
	if(day < 10) timestamp += "0" + String(day); else timestamp += String(day);
	if(hr < 10) timestamp += "0" + String(hr); else timestamp += String(hr);
	if(min < 10) timestamp += "0" + String(min); else timestamp += String(min);
	if(seg < 10) timestamp += "0" + String(seg); else timestamp += String(seg);
	return(timestamp);
}
//---------------------------------------------------------------------------
int __fastcall NumeroCampos(String linha, String separador)
{
	if(linha.SubString(linha.Length(), 1) != separador)
		linha = linha + separador;

	int cont = 0;
	for(int i=0; i<=linha.Length(); i++)
	{
		String substr = linha.SubString(i,1);
		if(substr == separador) cont += 1;
	}

	return cont;
}
//---------------------------------------------------------------------------
String __fastcall ValorCampo(String linha, int iCampo, String separador)
{
	String res = "";
	int cont = -1;
	int qtde = 0;
	int pos = 0;

	//Insere separador ao final da linha
	linha += separador;

	for(int i=0; i<=linha.Length(); i++)
	{
		String substr = linha.SubString(i,1);
		if(substr == separador)
		{
			cont += 1;
			if(cont == iCampo)
			{
				qtde = i - pos;
				break;
			}
			else pos = i + 1;
		}
	}
	res = linha.SubString(pos, qtde);
	if(res.SubString(res.Length(),1) == separador)
		res = res.SubString(0, res.Length()-1);

	return res;
}
//---------------------------------------------------------------------------
String __fastcall AlteraCampo(String linha, int iCampo, String separador, String novoValor)
{
   // Proteção
   int NCampos = NumeroCampos(linha, ";");
   if(iCampo >= NCampos) return(linha);

   String linhaFinal = "";
   for(int i=0; i<NCampos; i++)
   {
      String campo = ValorCampo(linha, i, ";");
      if(i == iCampo) linhaFinal = linhaFinal + novoValor + ";";
      else linhaFinal = linhaFinal + campo + ";";
   }
   return(linhaFinal);
}
//---------------------------------------------------------------------------
double __fastcall Arredonda(double valIni, int ndigitos)
{
	double resp;
	double base = 1.;
	for(int i=0; i<ndigitos; i++) base *= 10.;

	resp = (long)(valIni * base)/base;
   return resp;
}
//---------------------------------------------------------------------------
bool __fastcall AlimentadoresIguais(String codigo1, String codigo2)
{
	if(codigo1 == "" || codigo2 == "") return(false);

	codigo1 = ReplaceStr(codigo1, "-", "");
	codigo1 = ReplaceStr(codigo1, " ", "");
	if(codigo1.Length() == 8 && codigo1.SubString(1,1).UpperCase() == "R")
		codigo1 = codigo1.SubString(2, codigo1.Length()-1);

	codigo2 = ReplaceStr(codigo2, "-", "");
	codigo2 = ReplaceStr(codigo2, " ", "");
	if(codigo2.Length() == 8 && codigo2.SubString(1,1).UpperCase() == "R")
		codigo2 = codigo2.SubString(2, codigo2.Length()-1);

	return(codigo1 == codigo2);
}
//---------------------------------------------------------------------------
bool __fastcall ChavesIguais(String codigo1, String codigo2)
{
	if(codigo1 == "" || codigo2 == "") return(false);

	if(codigo1.Length() == 14) codigo1 = codigo1.SubString(1,13);
	if(codigo2.Length() == 14) codigo2 = codigo2.SubString(1,13);

	return(codigo1 == codigo2);
}
//---------------------------------------------------------------------------
bool __fastcall TrafosIguais(String codigo1, String codigo2)
{
	if(codigo1 == "" || codigo2 == "") return(false);

	if(codigo1.Length() == 14) codigo1 = codigo1.SubString(1,13);
	if(codigo2.Length() == 14) codigo2 = codigo2.SubString(1,13);

	return(codigo1 == codigo2);
}
//---------------------------------------------------------------------------
void __fastcall CopiaObjetos(TList* lisOri, TList* lisFinal)
{
	if(!lisOri || !lisFinal) return;
	for(int i=0; i<lisOri->Count; i++)
	{
		TObject* obj = (TObject*)lisOri->Items[i];
		lisFinal->Add(obj);
   }
}
//---------------------------------------------------------------------------
bool __fastcall AlimentadorPertenceSubestacao(String codigoSE, String codigoAlimentador)
{
	if(codigoSE == "" || codigoAlimentador == "") return(false);

	// Exemplo: SE: BIR, Alimentador: RBIR-1302
	// Exemplo: SE: VVE, Alimentador: VVE03

	return(AnsiContainsStr(codigoAlimentador, codigoSE));
}
//---------------------------------------------------------------------------
void __fastcall NomesArquivosDiretorio(String folder, String extensaoArquivos, TStringList* listaArquivos)
{
	if(listaArquivos == NULL) return;

	String search_path = folder + "/*." + extensaoArquivos;
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
   if(hFind != INVALID_HANDLE_VALUE) {
      do {
         // read all (real) files in current folder
         // , delete '!' read other 2 default folder . and ..
         if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
         listaArquivos->Add(fd.cFileName);
      	}
      }while(::FindNextFile(hFind, &fd));
      ::FindClose(hFind);
   }
}
//---------------------------------------------------------------------------
