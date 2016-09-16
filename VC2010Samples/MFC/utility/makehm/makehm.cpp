// makehm.cpp : A simple utility to create .HM (Help Map) files from
//              .H (resource header files).
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

//  This utility creates a .HM file from a header file (usually
//  resource.h) which allows one to maintain the help mappings
//  without a lot of manual effort on the part of the programmer
//  or help author.
//
//  This is done by naming convention, the naming convention used
//  being that normally accepted as standard Windows and MFC
//  programming practices.

#include <ctype.h>
#include <afxcoll.h>    // also includes <afx.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

#define SIGNON_VER 10
#define SIGNON_REV 0

/////////////////////////////////////////////////////////////////////////////

void UsageErr(const TCHAR* szErrorMessage = NULL,
			  const TCHAR* szErrorParam = NULL)
{
	_ftprintf(stderr,
		_T("\nMicrosoft (R) Help Maintenance Utility   Version %d.%02d\n")
		_T("Copyright (c) Microsoft Corporation.  All rights reserved.\n\n"),
		SIGNON_VER, SIGNON_REV);

	if (szErrorMessage != NULL)
	{
		_ftprintf(stderr, _T("makehm: error: "));
		_ftprintf(stderr, szErrorMessage, szErrorParam);
		_ftprintf(stderr, _T(".\n\n"));
	}

	_ftprintf(stderr, _T("makehm usage:\n\n")
	_T("  makehm [/h [/a <file.h> [/I <path>]]] <from>,<to>,<add>... <resource.h> [output.hm]\n")
	_T("\n")
	_T("    /h     - generates an include file (.h) for HTML help instead of\n")
	_T("             a normal (.hm) WinHelp map file.\n")
	_T("    /a     - copies the contents of the specified <file.h> file to the\n")
	_T("             output.\n")
	_T("    /I     - additional path to search for the file.h file.  The program will\n")
	_T("             first look in the current directory, then the path specified by the\n")
	_T("             /I option and then in the path specified by the INCLUDE\n")
	_T("             environment variable.\n")
	_T("\n")
	_T("    <from>,<to>,<add> fields must appear as one argument and\n")
	_T("       are separated by commas.  A set of these arguments may\n")
	_T("       appear more than once.\n")
	_T("    <from> - identifies the symbol prefix to map from (e.g., ID_)\n")
	_T("    <to>   - identifies the symbol prefix to map to (e.g., HID_)\n")
	_T("    <add>  - identifies a numeric offset to be used (e.g., 0x10000)\n")
	_T("\n")
	_T("    <resource.h> - identifies the input header file (e.g., resource.h).\n")
	_T("    [output.hm] - identifies the output help map file.  If not\n")
	_T("       supplied, output is written to stdout.\n"));

	exit(1);
}

/////////////////////////////////////////////////////////////////////////////

class CLineFile : public CStdioFile
{
public:
	BOOL ReadLine(CString& stringLine);
	void WriteLine(const CString& stringLine);
	void SafeOpen(const CString& string, UINT nStyleFlags);
};

BOOL CLineFile::ReadLine(CString& str)
{
	UINT nMax = 512;
	for (;;)
	{
		ULONGLONG pos = GetPosition();
		if (!ReadString(str.GetBuffer(nMax), nMax))
			return FALSE;
		str.ReleaseBuffer();
		if (str.GetLength() < (int)nMax-1)
			return TRUE;
		nMax += 128;
		Seek(pos, CFile::begin);
	}
}

void CLineFile::WriteLine(const CString& str)
{
	ASSERT(str[str.GetLength()-1] == _T('\n'));
	WriteString(str);
}

void CLineFile::SafeOpen(const CString& name, UINT nStyleFlags)
{
	BOOL fSuccess = Open(name, nStyleFlags);
	if (!fSuccess)
		UsageErr(_T("unable to open file \"%s\""), name);
}

/////////////////////////////////////////////////////////////////////////////

BOOL IsValidSymbol(const TCHAR* psz)
{
#ifdef UNICODE
	if (!__iswcsymf(*psz))
#else
	if (!__iscsymf(*psz))
#endif
		return FALSE;

	ASSERT(*psz != 0);
	++psz;
	while (*psz)
	{
#ifdef UNICODE
		if (!__iswcsym(*psz))
#else
		if (!__iscsym(*psz))
#endif
			return FALSE;
		++psz;
	}
	return TRUE;
}

#define isodigit(i) (_T('0') <= (i) && (i) <= _T('7'))

BOOL IsValidValue(const TCHAR* psz, DWORD& dwValue)
{
	if (*psz == 0 || !_istdigit(*psz))
		return FALSE;

	DWORD dw = 0;
	if (psz[0] == '0' && (psz[1] == 'x' || psz[1] == 'X'))
	{
		if (psz[1] == 0)
			return FALSE;
		psz += 2;
		while (_istxdigit(*psz))
		{
			dw *= 16;
			dw += _istdigit(*psz) ? *psz - '0' : 10 + (*psz|0x20) - 'a';
			++psz;
		}
	}
	else if (psz[0] == '0')
	{
		while (isodigit(*psz))
		{
			dw *= 8;
			dw += *psz - '0';
			++psz;
		}
	}
	else
	{
		while (_istdigit(*psz))
		{
			dw *= 10;
			dw += *psz - '0';
			++psz;
		}
	}

	if (*psz != 0)
		return FALSE;

	dwValue = dw;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////

CPtrArray aMap;

struct CMapInfo
{
	TCHAR* pszPrefixFrom;
	TCHAR* pszPrefixTo;
	DWORD dwAddTo;
};

void AddToMap(TCHAR* pszArg)
{
	ENSURE(pszArg != NULL);
	TCHAR* psz = _tcsdup(pszArg);
	if (psz == NULL)
	{
		AfxThrowMemoryException();
	}
	ASSERT(_tcschr(psz, _T(',')) != NULL);

	TCHAR* pszPrefixFrom;
	TCHAR* pszPrefixTo;
	TCHAR* pszAddTo;
	DWORD dwAddTo;
	CMapInfo* pInfo;
	TCHAR* pContext=NULL;

	// parse each field out of the argument.
	pszPrefixFrom = _tcstok_s(psz, _T(","), &pContext);
	pszPrefixTo = _tcstok_s(NULL, _T(","), &pContext);
	if (pszPrefixTo == NULL)
		goto ParmError;
	pszAddTo = _tcstok_s(NULL, _T(","), &pContext);
	if (pszAddTo == NULL)
		goto ParmError;

	// make sure they are valid symbols/values.
	if (!IsValidSymbol(pszPrefixFrom) || !IsValidSymbol(pszPrefixTo))
		goto ParmError;
	if (!IsValidValue(pszAddTo, dwAddTo))
		goto ParmError;

	// add them to the map.
	pInfo = new CMapInfo;
	ASSERT(pInfo);
	pInfo->pszPrefixFrom = pszPrefixFrom;
	pInfo->pszPrefixTo = pszPrefixTo;
	pInfo->dwAddTo = dwAddTo;
	aMap.Add(pInfo);
	return;

ParmError:
	UsageErr(_T("parameter \"%s\" not correctly formed."), pszArg);
	ASSERT(FALSE);
}

CMapInfo* FindInMap(const TCHAR* psz)
{
	ENSURE(psz != NULL);
	ENSURE(*psz != 0);
	int nMax = (int)aMap.GetSize();
	for (int i = 0; i < nMax; i++)
	{
		CMapInfo* pInfo = (CMapInfo*)aMap.GetAt(i);
		size_t nLen = _tcslen(pInfo->pszPrefixFrom);
		if (_tcsncmp(pInfo->pszPrefixFrom, psz, nLen) == 0)
			return pInfo;
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////

BOOL
MapNameValue(const TCHAR* pszName, CString& strNewName, DWORD& dwValue)
{
	CMapInfo* pInfo = FindInMap(pszName);
	if (pInfo == NULL)
		return FALSE;

	CString strName = pszName;
	strNewName = (CString)pInfo->pszPrefixTo +
		strName.Right(strName.GetLength()-(int)_tcslen(pInfo->pszPrefixFrom));
	dwValue += pInfo->dwAddTo;
	return TRUE;
}

CString StringFromDword(DWORD dwValue)
{
	TCHAR buf[sizeof _T("0x12345678")];
	_stprintf_s(buf, sizeof _T("0x12345678"), _T("0x%lX"), dwValue);
	return CString(buf);
}

BOOL MapLine(CString& strLine, BOOL fHTMLFormat )
{
	static TCHAR szWhiteSpace1[] = _T("\t ");
	static TCHAR szWhiteSpace2[] = _T("\t\n ");
	static TCHAR szDefine[] = _T("#define");

	TCHAR* pszCopy = _tcsdup(strLine);
	if (pszCopy == NULL)
	{
		AfxThrowMemoryException();
	}

	TCHAR* psz;
	TCHAR* pszSymbol;
	TCHAR* pszValue;
	DWORD dwValue;
	CString strNewName;
	TCHAR* pContext=NULL;

	// '//{{NOHELP}}' can be placed on the line and it will not be included
	if (_tcsstr(strLine, _T("//{{NOHELP}}")) != NULL)
		goto RetFalse;

	psz = _tcstok_s(pszCopy, szWhiteSpace1, &pContext);
	if (psz == NULL)
		goto RetFalse;
	if (_tcscmp(psz, szDefine) != 0)
		goto RetFalse;
	pszSymbol = _tcstok_s(NULL, szWhiteSpace1, &pContext);
	if (pszSymbol == NULL)
		goto RetFalse;
	pszValue = _tcstok_s(NULL, szWhiteSpace2, &pContext);
	if (pszValue == NULL)
		goto RetFalse;

	if (!IsValidSymbol(pszSymbol))
		goto RetFalse;
	if (!IsValidValue(pszValue, dwValue))
		goto RetFalse;
	if (!MapNameValue(pszSymbol, strNewName, dwValue))
		goto RetFalse;

	//BLOCK: format output line
	{
		CString strPad(_T(' '), 40-strNewName.GetLength());
		if (strPad.IsEmpty())
			strPad = _T('\t');
		if( fHTMLFormat )
			strLine = _T("#define ") + strNewName + strPad + StringFromDword(dwValue) + _T("\n");
		else
			strLine = strNewName + strPad + StringFromDword(dwValue) + _T("\n");
	}

	ASSERT(pszCopy != NULL);
	free(pszCopy);
	return TRUE;

RetFalse:
	ASSERT(pszCopy != NULL);
	free(pszCopy);
	return FALSE;
}

void AddPath( CStringList& strrgPathList, const CString& strIncludePath )
{
	CString strPath;
	int curPos = 0;

	strPath = strIncludePath.Tokenize(_T(";"), curPos );

	while( ! strPath.IsEmpty() )
	{
		strPath.TrimLeft();
		strPath.TrimRight();
		strrgPathList.AddTail( strPath );
		strPath = strIncludePath.Tokenize(_T(";"), curPos );
	}
}

BOOL FileExists( const TCHAR *pszFileName )
{
	BOOL r = FALSE;
	CStdioFile file;
	if( file.Open( pszFileName, CLineFile::modeRead ) )
	{
		file.Close();
		r = TRUE;
	}

	return r;
}

CString FindIncludeFile( const TCHAR *pszIncludeFilename, const TCHAR *pszIncludePath )
{
	CString strEnvInclude;
	CStringList strrgPathList;
	
	if( FileExists( pszIncludeFilename ) )
		return CString(pszIncludeFilename);
	
	// add current directory to path list;
	strrgPathList.AddTail( ".\\" );
	
	// add path specified in the command line (/I option)
	if( pszIncludePath )
		AddPath( strrgPathList, pszIncludePath );
	
	// add path specified in the INCLUDE variable
	if( strEnvInclude.GetEnvironmentVariable( _T("INCLUDE") ) )
		AddPath( strrgPathList, strEnvInclude );
	
	POSITION pos = strrgPathList.GetHeadPosition();
	for (int i=0;i < strrgPathList.GetCount();i++)
	{
		CString strPath = strrgPathList.GetNext(pos);
		CString tmp = strPath.Right(1);
		if( tmp != ":" && tmp != "\\" )
			strPath += '\\';
		
		strPath += pszIncludeFilename;
		
		if( FileExists( strPath ) )
			return CString(strPath);
	}

	return CString("");
}

/////////////////////////////////////////////////////////////////////////////

int _tmain(int argc, TCHAR** argv)
{
	int iFirstParam = 1;

	// Turn on the "termination on heap corruption" flag.
	(void)HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	// generate output for HTML Help format
	BOOL fHTMLFormat = FALSE;

	// <include.h> filename to be copied
	const TCHAR *pszIncludeFilename = NULL;

	// additional include path
	const TCHAR *pszIncludePath = NULL;

	if( argc > 1 && _tcsicmp(argv[1], _T("/h")) == 0 )
	{
		fHTMLFormat = TRUE;
		iFirstParam++;

		if( ( argc > 3 ) && _tcsicmp(argv[2], _T("/a")) == 0 ) // copy file operation
		{
			pszIncludeFilename = argv[3];
			iFirstParam += 2;

			if( argc > 5 && _tcsicmp(argv[4], _T("/i")) == 0 )
			{
				pszIncludePath = argv[5];
				iFirstParam += 2;
			}
		}
	}

	// add symbol mappings to the map.
	BOOL fAddedToMap = FALSE;
	int i;
	for (i = iFirstParam; i < argc && _tcschr(argv[i], _T(',')) != NULL; i++)
	{
		AddToMap(argv[i]);
		fAddedToMap = TRUE;
	}

	// must only have 1-2 parms left on command line.
	if (!fAddedToMap || i < argc-2 || i > argc-1)
	{
		UsageErr(NULL, NULL);
		ASSERT(FALSE);
	}

	// open input file.
	CLineFile fileIn;
	fileIn.SafeOpen(argv[i], CLineFile::modeRead);

	// open/hook up output file.
	CLineFile fileOut;
	if (i+1 < argc)
		fileOut.SafeOpen(argv[i+1], CLineFile::modeWrite | CLineFile::modeCreate);
	else
		fileOut.m_pStream = stdout;

	// process the file.
	CString strLine;
	while (fileIn.ReadLine(strLine))
	{
		if (MapLine(strLine, fHTMLFormat))
		{
			fileOut.WriteLine(strLine);
		}
	}

	// close input file.
	fileIn.Close();

	if( pszIncludeFilename != NULL )
	{
		CString strIncludeFilePath = FindIncludeFile( pszIncludeFilename, pszIncludePath );
		if( strIncludeFilePath.IsEmpty() )
		{
			_ftprintf(stderr, _T("Error: Additional include file %s not found\n\n"), pszIncludeFilename );
			fileOut.Close();
			exit(1);
		}

		fileIn.SafeOpen(strIncludeFilePath, CLineFile::modeRead);

		while (fileIn.ReadLine(strLine))
		{
			fileOut.WriteLine(strLine);
		}
	}

	// close output file.
	fileOut.Close();

	return 0;
}

/////////////////////////////////////////////////////////////////////////////
