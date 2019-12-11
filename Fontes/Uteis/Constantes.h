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
// Identificadores dos tipos de localização
enum enumTipoLocalizacao
{
	algoLFindef = -1,
	algoLF1, // Localização de faltas que não envolvem a terra (3F e 2F)
	algoLF2, // Localização de faltas que envolvem a terra (2FT e FT)
	algoLF3  // Localização de rompimento de cabo
};
//---------------------------------------------------------------------------
