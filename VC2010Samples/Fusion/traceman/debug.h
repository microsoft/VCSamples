#pragma once

#include <cstdio>

#define _D(x) wprintf(L"%s\n", x)

//#define NO_MSG
//#define SHOW_ALL_MSG

#ifdef NO_MSG
#define _NOMSG()
#define _NOTIMPL()
#define _MSG()
#else
#define _NOMSG()	printf("NO MSG: %d file: %s\n", __LINE__, __FILE__)
#define _NOTIMPL()	printf("NOT IMPL: %d file: %s\n", __LINE__, __FILE__)

#ifdef SHOW_ALL_MSG
#define _MSG()		printf("MSG line: %d file: %s\n", __LINE__, __FILE__)
#else
#define _MSG()
#endif

#endif

