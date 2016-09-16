#pragma once

#include "stdafx.h"

// if this header is missing then you have to install xmllite library
#include <xmllite.h>
#include <string>
#include <memory>

class XMLReader
{
public:	
	enum NodeType {
		XML_NODE_NONE = 0,
		XML_NODE_ELEMENT = 1,
		XML_NODE_ATTRIBUTE = 2,
		XML_NODE_TEXT = 3,
		XML_NODE_CDATA = 4,
		XML_NODE_PROCESSING_INSTRUCTION = 7,
		XML_NODE_COMMENT = 8,
		XML_NODE_DOCUMENT_TYPE = 10,
		XML_NODE_WHITESPACE = 13,
		XML_NODE_END_ELEMENT = 15,
		XML_NODE_DECLARATION = 17
	};

	XMLReader(void);
	virtual ~XMLReader(void);
	
	virtual HRESULT LoadFromFile(const std::wstring& sFileName);
	virtual HRESULT LoadFromBuffer(const BYTE* pBuffer, UINT nLen);	

	virtual HRESULT GetLastError(void);
	virtual HRESULT SetProperty(UINT nPropety, LONG_PTR pValue); 
	virtual HRESULT SetInput(IUnknown *pInput);

	virtual HRESULT Read(NodeType *nNodeType);

	virtual std::wstring GetValue();
	virtual std::wstring GetLocalName();
	virtual std::wstring GetPrefix();

	virtual UINT GetDepth();
	virtual UINT GetAttributeCount();
	virtual bool IsEmptyElement(void);
	virtual HRESULT MoveToFirstAttribute(void);
	virtual HRESULT MoveToNextAttribute(void);
	virtual HRESULT MoveToAttributeByName(const std::wstring& sName);	
protected:	
	HRESULT m_nError;
	std::tr1::shared_ptr<IXmlReader> m_pReader;
};
