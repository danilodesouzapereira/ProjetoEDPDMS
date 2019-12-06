//---------------------------------------------------------------------------
#pragma hdrstop
#include "TMetodosAuxiliares.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
