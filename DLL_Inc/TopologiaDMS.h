//---------------------------------------------------------------------------
#ifndef TopologiaDMSH
#define TopologiaDMSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#define EXPORT extern "C++" __declspec(dllexport)
//-----------------------------------------------------------------------------
class TTopologiaDMS;
class VTApl;
class VTRede;
//-----------------------------------------------------------------------------
EXPORT TTopologiaDMS* __fastcall DLL_NewTopologiaDMS(VTApl *apl_owner, VTRede* rede);
EXPORT void __fastcall DLL_DeleteTopologiaDMS(TTopologiaDMS* topologiaDMS);
//---------------------------------------------------------------------------
#endif
//eof
