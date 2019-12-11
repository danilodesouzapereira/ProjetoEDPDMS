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
		}

//		// Verificação
//		if(TimeStamp == "" || CodAlimentador == "" || TipoEqpto == -1 || TipoAlarme == -1 || CodEqpto == "")
//			continue;

		// Cria obj de struct Alarme
		Alarme* alarme = new Alarme;
		alarme->timeStamp = TimeStamp;
		alarme->codigoEqpto = CodigoEqpto;
		alarme->codigoAlimentador = CodigoAlimentador;
		alarme->tipoAlarme = TipoAlarme;
		alarme->tipoEqpto = TipoEqpto;

		lisEXT->Add(alarme);
	}
	delete docXMLalarme;
}
//---------------------------------------------------------------------------
