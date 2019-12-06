//---------------------------------------------------------------------------
#ifndef TopologiaDMSH
#define TopologiaDMSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#define EXPORT extern "C++" __declspec(dllexport)
//-----------------------------------------------------------------------------
class TTopologiaDMS;
class VTApl;
//-----------------------------------------------------------------------------
EXPORT TTopologiaDMS* __fastcall DLL_NewTopologiaDMS(VTApl *apl_owner);
EXPORT void __fastcall DLL_DeleteTopologiaDMS(TTopologiaDMS* topologiaDMS);
//---------------------------------------------------------------------------
#endif
//eof
