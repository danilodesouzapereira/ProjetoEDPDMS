//---------------------------------------------------------------------------
#ifndef FLH
#define FLH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#define EXPORT extern "C++" __declspec(dllexport)
//-----------------------------------------------------------------------------
class TFL;
class TTopologiaDMS;
//-----------------------------------------------------------------------------
EXPORT TFL* __fastcall DLL_NewFL(TTopologiaDMS* topologiaDMS);
EXPORT void __fastcall DLL_DeleteFL(TFL* localizador);
//---------------------------------------------------------------------------
#endif
//eof
