#pragma once

#include <winsdkver.h>

#ifndef _WIN32_WINNT
// Modify the following define to target a prior platform. Refer to MSDN
// for the latest info on corresponding values for different platforms.
#define _WIN32_WINNT _WIN32_WINNT_MAXVER
#endif

#include <sdkddkver.h>
