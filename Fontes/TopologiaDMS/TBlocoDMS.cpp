//---------------------------------------------------------------------------
#pragma hdrstop
#include "TBlocoDMS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//--------------------------------------------------------------------------
__fastcall TBlocoDMS::TBlocoDMS()
{
	lisBlocoDMSjusante = new TList;
}
//--------------------------------------------------------------------------
__fastcall TBlocoDMS::~TBlocoDMS()
{
	for(int i=lisBlocoDMSjusante->Count-1; i>=0; i--) delete lisBlocoDMSjusante->Items[i];
   delete lisBlocoDMSjusante; lisBlocoDMSjusante = NULL;
}
//--------------------------------------------------------------------------
