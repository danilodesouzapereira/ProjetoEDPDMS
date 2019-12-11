//---------------------------------------------------------------------------
#ifndef TLeitorXMLH
#define TLeitorXMLH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Xml.XMLDoc.hpp>
//---------------------------------------------------------------------------
class TLeitorXML
{
public:
	// Dados
	String diretorio;
	TForm* formParent;

	// Construtor e destrutor
	__fastcall TLeitorXML(String diretorio, TForm* formParent);
	__fastcall ~TLeitorXML();

	void __fastcall LeAlarmes_StringCSV(String nomeArquivo, TList* lisEXT); //< Gera objeto com os parâmetros do alarme

//	// Métodos
//	TAlarme* __fastcall GetAlarme(String CodArquivoAlarme);
//	void     __fastcall GetAtualizacoesAlarmes(String pathArqAlarme, TList* lisEXT);
//	void     __fastcall GetCadSensores(String CodArquivoCadSensores, TList* lisEXT);
//	void     __fastcall GetReqResponse(String CodArquivoResponse, TXMLComunicacao* xmlRequest, TList* lisEXT);
//	void     __fastcall SetLogErros(TLog* logErros);
//
//	// Métodos internos
//	String __fastcall GetCodEqpto(TXMLComunicacao* xmlRequest, String responseID);
//	String __fastcall GetResponseErro(_di_IXMLNodeList nodeResponse, String &Mensagem);
//	String __fastcall GetResponseID(_di_IXMLNodeList nodeResponse);
//	int    __fastcall GetRequestType(TXMLComunicacao* xmlRequest, String responseID);
//	int    __fastcall GetTipoEqpto(TXMLComunicacao* xmlRequest, String responseID);
//	String __fastcall GetTimeStampEvento(TXMLComunicacao* xmlRequest, String responseID);
//
//	void            __fastcall GetReqResponse_LeXML(String CodArquivoResponse, TXMLComunicacao* xmlRequest, TList* lisEXT);
//	StrReqResponse* __fastcall FindRespGeral(TList* lisEXT, String CodEqpto, String TipoEqpto);
//	void            __fastcall PreencheResp(StrReqResponse* respIni, StrReqResponse* respFin, String TipoEqpto);
//	void            __fastcall DefineEqpto(TList* lisEXT);
//	String          __fastcall GetCodChaveQualimetro(String CodQualimetro);
//	String          __fastcall GetCodChaveSensor(String CodSensor);
};
//---------------------------------------------------------------------------
#endif
