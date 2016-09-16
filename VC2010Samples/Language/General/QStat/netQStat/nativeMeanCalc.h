#include "stdafx.h"

#ifdef _DEBUG
#import "..\server\debug\qstat.dll" raw_interfaces_only
#else
#import "..\server\release\qstat.dll" raw_interfaces_only
#endif

using namespace QStat;
class nativeMeanCalc {
public:
	IMeanCalcPtr pMeanCalc;
};