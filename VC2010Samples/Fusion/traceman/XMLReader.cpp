#include "StdAfx.h"

#include <atlbase.h> 
#include <strsafe.h>
#include <cassert>
#include <shlwapi.h>

#include "XMLReader.h"


XMLReader::XMLReader(void)
{	
	typedef HRESULT (STDAPICALLTYPE *XMLReaderFunc)(__in REFIID riid, __out void ** ppvObject, __in_opt IMalloc * pMalloc);

	HINSTANCE hInst = ::GetModuleHandleA("XMLLITE.DLL");
	
	if (NULL == hInst) {
		m_nError = S_FALSE;		
	}

	XMLReaderFunc pfReader = reinterpret_cast<XMLReaderFunc>(GetProcAddress(hInst, "CreateXmlReader"));

	if (NULL == pfReader) {
		m_nError = S_FALSE;		
	}
		
	m_nError = pfReader(__uuidof(IXmlReader), (void**) &m_pReader, NULL); 
}

XMLReader::~XMLReader(void)
{
}

HRESULT XMLReader::GetLastError(void)
{
	return m_nError;
}

HRESULT XMLReader::SetProperty(UINT nPropety, LONG_PTR pValue)
{	
	m_nError = m_pReader->SetProperty(nPropety, pValue);

	return m_nError;
}

HRESULT XMLReader::SetInput(IUnknown *pInput)
{
	assert(pInput != NULL);

	m_nError = m_pReader->SetInput(pInput);

	return m_nError;
}

HRESULT XMLReader::Read(NodeType *nNodeType)
{
	m_nError = m_pReader->Read((XmlNodeType *)nNodeType);
 
	return m_nError;
}

std::wstring XMLReader::GetValue()
{
	const WCHAR *pwszTmp;

	m_nError = m_pReader->GetValue(&pwszTmp, NULL);

	return std::wstring(pwszTmp);
}

std::wstring XMLReader::GetLocalName()
{
	const WCHAR *pwszTmp;

	m_nError = m_pReader->GetLocalName(&pwszTmp, NULL);
	
	return std::wstring(pwszTmp);
}

std::wstring XMLReader::GetPrefix()
{
	const WCHAR *pwszTmp;
	
	m_nError = m_pReader->GetPrefix(&pwszTmp, NULL);

	return std::wstring(pwszTmp);
}

UINT XMLReader::GetDepth()
{
	UINT nDepth = 0;

	m_nError = m_pReader->GetDepth(&nDepth);

	return nDepth;
}

UINT XMLReader::GetAttributeCount(void)
{
	UINT nCount = 0;

	m_nError = m_pReader->GetAttributeCount(&nCount);

	return nCount;
}

bool XMLReader::IsEmptyElement(void)
{
	return (m_pReader->IsEmptyElement() ? true : false);
}

HRESULT XMLReader::MoveToFirstAttribute(void)
{
	m_nError = m_pReader->MoveToFirstAttribute();

	return m_nError;
}

HRESULT XMLReader::MoveToNextAttribute(void)
{
	m_nError = m_pReader->MoveToNextAttribute();

	return m_nError;
}


HRESULT XMLReader::MoveToAttributeByName(const std::wstring& sName)
{
	m_nError = m_pReader->MoveToAttributeByName(sName.c_str(), NULL);

	return m_nError;
}

HRESULT XMLReader::LoadFromFile(const std::wstring& sFileName)
{
	CComPtr<IStream> pFileStream;
	m_nError = S_OK;

	if (!FAILED(m_nError = SHCreateStreamOnFile(sFileName.c_str(), STGM_READ, &pFileStream)))
    {   		
		SetInput(pFileStream);
    }	

	return m_nError;	
}

HRESULT XMLReader::LoadFromBuffer(const BYTE* pBuffer, UINT nLen)
{
	CComPtr<IStream> pFileStream;
	m_nError = S_OK;

	//on ia64 there is no definiton of SHCreateMemStream therfore 
	//we load it dynamicly from dll file
	typedef struct IStream *(STDAPICALLTYPE *CreateMemStream)(__in_bcount_opt(cbInit) const BYTE *pInit, UINT cbInit);

	HINSTANCE hInst = ::GetModuleHandleA("SHLWAPI.DLL");

	if (NULL == hInst) {
		m_nError = S_FALSE;		
		return m_nError;
	}
	
	//12 it's an ordinal for SHCreateMemStream function
	CreateMemStream pfMemStream = reinterpret_cast<CreateMemStream>(GetProcAddress(hInst, reinterpret_cast<LPCSTR>(LOWORD(12))));

	if (NULL == pfMemStream) {
		m_nError = S_FALSE;
		return m_nError;
	}

	pFileStream = (*pfMemStream)(pBuffer, nLen);

	if (NULL == pFileStream) {
		m_nError = S_FALSE;
	}
	else {
		SetInput(pFileStream);
	}

	return m_nError;	
}
