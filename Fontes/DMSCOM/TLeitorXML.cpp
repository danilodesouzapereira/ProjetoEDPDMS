//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "..\Uteis\Modelos.h"
#include <XMLDoc.hpp>
#include <StrUtils.hpp>
#include "TLeitorXML.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TLeitorXML::TLeitorXML(String diretorio, TForm* formParent)
{
	// Inicializações
	this->diretorio = diretorio;
	this->formParent = formParent;
}
//---------------------------------------------------------------------------
__fastcall TLeitorXML::~TLeitorXML()
{

}
//---------------------------------------------------------------------------
void __fastcall TLeitorXML::LeAlarmes_StringCSV(String nomeArquivo, TList* lisEXT)
{
	if(!lisEXT || nomeArquivo == "") return;

	bool f50A, f50B, f50C, f50N, f51A, f51B, f51C, f51N;
   double correnteFalta;
	int TipoEqpto, TipoAlarme;
	String TimeStamp, CodigoEqpto, CodigoAlimentador;
	TXMLDocument* docXMLalarme;

	// Carrega arquivo XML
	docXMLalarme = new TXMLDocument(formParent);
	docXMLalarme->LoadFromFile(diretorio + "\\" + nomeArquivo);

	// Nó raiz
	IXMLNode *rootNode = docXMLalarme->DocumentElement;
	IXMLNodeList *listaAlarmes = rootNode->ChildNodes;

	// Percorre os nós
	for(int i=0; i<listaAlarmes->GetCount(); i++)
	{
		// Percorrendo os nós de alarmes
		_di_IXMLNodeList nodeAlarme = listaAlarmes[0].Get(i)->ChildNodes;

		for(int j=0; j<nodeAlarme->Count; j++)
		{
			_di_IXMLNode atributo = nodeAlarme->Get(j);

			if(atributo->NodeName == "TimeStamp")
			{
				TimeStamp = atributo->Text;
			}
			else if(atributo->NodeName == "TipoEqpto")
			{
				TipoEqpto = atributo->Text.ToInt();
			}
			else if(atributo->NodeName == "CodigoEqpto")
			{
				CodigoEqpto = atributo->Text;
			}
			else if(atributo->NodeName == "CodigoAlimentador")
			{
				CodigoAlimentador = atributo->Text;
			}
			else if(atributo->NodeName == "TipoAlarme")
			{
				TipoAlarme = atributo->Text.ToInt();
			}

			else if(atributo->NodeName == "Funcao50A")
			{
				f50A = (atributo->Text == "True") ? true : false;
			}
			else if(atributo->NodeName == "Funcao50B")
			{
				f50B = (atributo->Text == "True") ? true : false;
			}
			else if(atributo->NodeName == "Funcao50C")
			{
				f50C = (atributo->Text == "True") ? true : false;
			}
			else if(atributo->NodeName == "Funcao50N")
			{
				f50N = (atributo->Text == "True") ? true : false;
			}
			else if(atributo->NodeName == "Funcao51A")
			{
				f51A = (atributo->Text == "True") ? true : false;
			}
			else if(atributo->NodeName == "Funcao51B")
			{
				f51B = (atributo->Text == "True") ? true : false;
			}
			else if(atributo->NodeName == "Funcao51C")
			{
				f51C = (atributo->Text == "True") ? true : false;
			}
			else if(atributo->NodeName == "Funcao51N")
			{
				f51N = (atributo->Text == "True") ? true : false;
			}
			else if(atributo->NodeName == "CorrenteFalta")
			{
				correnteFalta = atributo->Text.ToDouble();
			}
		}

		// Cria obj de struct Alarme
		Alarme* alarme = new Alarme;

		// Insere dados gerais
		alarme->timeStamp = TimeStamp;
		alarme->codigoEqpto = CodigoEqpto;
		alarme->codigoAlimentador = CodigoAlimentador;
		alarme->tipoAlarme = TipoAlarme;
		alarme->tipoEqpto = TipoEqpto;

		// Insere funções de proteção
		alarme->funcao50A = f50A;
		alarme->funcao50B = f50B;
		alarme->funcao50C = f50C;
		alarme->funcao50N = f50N;
		alarme->funcao51A = f51A;
		alarme->funcao51B = f51B;
		alarme->funcao51C = f51C;
		alarme->funcao51N = f51N;

		// Corrente de curto-circuito detectada
		alarme->correnteFalta = correnteFalta;

		lisEXT->Add(alarme);
	}
	delete docXMLalarme;
}
//---------------------------------------------------------------------------
