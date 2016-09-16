#pragma once

#ifndef IFC
#define IFC(expr) if (FAILED(expr)) return FALSE;
#endif

#ifndef RELEASE
#define RELEASE(x) if (x != NULL) x.Detach()->Release();
#endif