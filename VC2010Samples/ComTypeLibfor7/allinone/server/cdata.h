/////////////////////////////////////////////////////////////////////////////
// cdata.h :
//

#if !defined(__CDATA_H__)
#define __CDATA_H__

#include "idata.h"

class CMyStruct : public tagIMyStruct
{
public:
	CMyStruct() { m_str = NULL; }
	virtual ~CMyStruct() { if (m_str) ::SysFreeString(m_str); }

// Operations
public:
	void Format(CString& str)
	{
	str.Format(_T("{%i, %.4f, %s}"), m_int, m_float, (LPCTSTR) (CString) m_str);
	}
};

class CMyObject : public CObject, public CMyStruct
{
	DECLARE_SERIAL(CMyObject)
public:
	CMyObject() {}
	virtual ~CMyObject() {}

// Implementation
public:
	virtual void Serialize(CArchive& ar);
};

#endif // __CDATA_H__

/////////////////////////////////////////////////////////////////////////////
