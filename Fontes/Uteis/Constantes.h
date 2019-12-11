#include <Classes.hpp>
//---------------------------------------------------------------------------
// Status do sincronizador
enum enumStatusSinc
{
	sincSTANDBY=0,
	sincSOLICIT_PROCESSO,
	sincLOCALIZACAO,
	sincESTIMACAO,
	sincSELFHEALING
};
//---------------------------------------------------------------------------
// Identificadores dos tipos de localiza��o
enum enumTipoLocalizacao
{
	algoLFindef = -1,
	algoLF1, // Localiza��o de faltas que n�o envolvem a terra (3F e 2F)
	algoLF2, // Localiza��o de faltas que envolvem a terra (2FT e FT)
	algoLF3  // Localiza��o de rompimento de cabo
};
//---------------------------------------------------------------------------
