#ifndef __VCOPTION_H__
#define __VCOPTION_H__

enum ERRTYPE {NOERROR, WARNING, FATAL};

class VCOption
{
public:
	string vc;
	bool space;
	ERRTYPE error;
};

#endif