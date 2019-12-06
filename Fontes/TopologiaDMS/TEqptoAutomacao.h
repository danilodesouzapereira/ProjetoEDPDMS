//---------------------------------------------------------------------------
#ifndef TEqptoAutomacaoH
#define TEqptoAutomacaoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TEqptoTopologia.h"
//---------------------------------------------------------------------------
class TEqptoAutomacao : public TEqptoTopologia
{
public:
	// Parâmetros
	int tipoAutomacao;


	// Métodos
	__fastcall TEqptoAutomacao(VTApl* apl);
	__fastcall ~TEqptoAutomacao();
};
//---------------------------------------------------------------------------
#endif
