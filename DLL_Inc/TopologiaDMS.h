//---------------------------------------------------------------------------
#ifndef TopologiaDMSH
#define TopologiaDMSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#define EXPORT extern "C++" __declspec(dllexport)
//-----------------------------------------------------------------------------
class VTTopologiaDMS;
class VTApl;
class VTRede;
//-----------------------------------------------------------------------------
EXPORT VTTopologiaDMS* __fastcall DLL_NewTopologiaDMS(VTApl *apl_owner, String codigoRede);
//---------------------------------------------------------------------------
#endif
//eof
