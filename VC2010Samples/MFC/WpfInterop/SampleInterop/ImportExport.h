#pragma once

#ifdef InteropDll_Export
# define InteropDll_ImportExport __declspec(dllexport)
#else
# define InteropDll_ImportExport __declspec(dllimport)
#endif
