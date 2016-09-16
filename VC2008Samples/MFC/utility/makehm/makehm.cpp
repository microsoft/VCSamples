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

#define SIGNON_VER 7
#define SIGNON_REV 0

/////////////////////////////////////////////////////////////////////////////

void UsageErr(const char* szErrorMessage = NULL,
			  const char* szErrorParam = NULL)
{
	fprintf(stderr,
		"\nMicrosoft (R) Help Maintainence Utility   Version %d.%02d\n"
		"Copyright (c) Microsoft Corporation.  All rights reserved.\n\n",
		SIGNON_VER, SIGNON_REV);

	if (szErrorMessage != NULL)
	{
		fprintf(stderr, "makehm: error: ");
		fprintf(stderr, szErrorMessage, szErrorParam);
		fprintf(stderr, ".\n\n");
	}

	fprintf(stderr, "makehm usage:\n\n"
	"  makehm [/h [/a <file.h> [/I <path>]]] <from>,<to>,<add>... <resource.h> [output.hm]\n"
	"\n"
	"    /h     - generates an include file (.h) for HTML help instead of\n"
	"             a normal (.hm) WinHelp map file\n"
	"    /a     - copy the contents of the specified <file.h> file to the\n"
	"             output.\n"
	"    /I     - additional path to look for the file.h file.  The program will\n"
	"             first look in the current directory, then path specified by the\n"
	"             /I option and then in the path specified by the\n"
	"             INCLUDE environment variable\n"
	"\n"
	"    <from>,<to>,<add> fields must appear as one argument and\n"
	"       are separated by commas.  A set of these arguments may\n"
	"       appear more than once.\n"
	"    <from> - identifies the symbol prefix to map from (ie. ID_)\n"
	"    <to>   - identifies the symbol prefix to map to (ie. HID_)\n"
	"    <add>  - identifies a numeric offset to be used (ie. 0x10000)\n"
	"\n"
	"    <resource.h> - identifies the input header file (ie. resource.h).\n"
	"    [output.hm] - identifies the output help map file.  If not\n"
	"       supplied, output is written to stdout.\n");

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
	ASSERT(str[str.GetLength()-1] == '\n');
	WriteString(str);
}

void CLineFile::SafeOpen(const CString& name, UINT nStyleFlags)
{
	BOOL fSuccess = Open(name, nStyleFlags, 0);
	if (!fSuccess)
		UsageErr("unable to open file \"%s\"", name);
}

/////////////////////////////////////////////////////////////////////////////

BOOL IsValidSymbol(const char* psz)
{
	if (!__iscsymf((unsigned char)*psz))
		return FALSE;

	ASSERT(*psz != 0);
	++psz;
	while (*psz)
	{
		if (!__iscsym((unsigned char)*psz))
			return FALSE;
		++psz;
	}
	return TRUE;
}

#define isodigit(i) ('0' <= (i) && (i) <= '7')

BOOL IsValidValue(const char* psz, DWORD& dwValue)
{
	if (*psz == 0 || !isdigit((unsigned char)*psz))
		return FALSE;

	DWORD dw = 0;
	if (psz[0] == '0' && (psz[1] == 'x' || psz[1] == 'X'))
	{
		if (psz[1] == 0)
			return FALSE;
		psz += 2;
		while (isxdigit((unsigned char)*psz))
		{
			dw *= 16;
			dw += isdigit((unsigned char)*psz) ? *psz - '0' : 10 + (*psz|0x20) - 'a';
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
		while (isdigit((unsigned char)*psz))
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
	char* pszPrefixFrom;
	char* pszPrefixTo;
	DWORD dwAddTo;
};

void AddToMap(char* pszArg)
{
	ENSURE(pszArg != NULL);
	char* psz = _strdup(pszArg);
	if (psz == NULL)
	{
		AfxThrowMemoryException();
	}
	ASSERT(strchr(psz, ',') != NULL);

	char* pszPrefixFrom;
	char* pszPrefixTo;
	char* pszAddTo;
	DWORD dwAddTo;
	CMapInfo* pInfo;
	char* pContext=NULL;

	// parse each field out of the argument.
	pszPrefixFrom = strtok_s(psz, ",", &pContext);
	pszPrefixTo = strtok_s(NULL, ",", &pContext);
	if (pszPrefixTo == NULL)
		goto ParmError;
	pszAddTo = strtok_s(NULL, ",", &pContext);
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
	UsageErr("parameter \"%s\" not correctly formed.", pszArg);
	ASSERT(FALSE);
}

CMapInfo* FindInMap(const char* psz)
{
	ENSURE(psz != NULL);
	ENSURE(*psz != 0);
	int nMax = (int)aMap.GetSize();
	for (int i = 0; i < nMax; i++)
	{
		CMapInfo* pInfo = (CMapInfo*)aMap.GetAt(i);
		size_t nLen = strlen(pInfo->pszPrefixFrom);
		if (strncmp(pInfo->pszPrefixFrom, psz, nLen) == 0)
			return pInfo;
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////

BOOL
MapNameValue(const char* pszName, CString& strNewName, DWORD& dwValue)
{
	CMapInfo* pInfo = FindInMap(pszName);
	if (pInfo == NULL)
		return FALSE;

	CString strName = pszName;
	strNewName = (CString)pInfo->pszPrefixTo +
		strName.Right(strName.GetLength()-(int)strlen(pInfo->pszPrefixFrom));
	dwValue += pInfo->dwAddTo;
	return TRUE;
}

CString StringFromDword(DWORD dwValue)
{
	char buf[sizeof "0x12345678"];
	sprintf_s(buf, sizeof "0x12345678", "0x%lX", dwValue);
	return CString(buf);
}

BOOL MapLine(CString& strLine, BOOL fHTMLFormat )
{
	static char szWhiteSpace1[] = "\t ";
	static char szWhiteSpace2[] = "\t\n ";
	static char szDefine[] = "#define";

	char* pszCopy = _strdup(strLine);
	if (pszCopy == NULL)
	{
		AfxThrowMemoryException();
	}

	char* psz;
	char* pszSymbol;
	char* pszValue;
	DWORD dwValue;
	CString strNewName;
	char* pContext=NULL;

	// '//{{NOHELP}}' can be placed on the line and it will not be included
	if (strstr(strLine, "//{{NOHELP}}") != NULL)
		goto RetFalse;

	psz = strtok_s(pszCopy, szWhiteSpace1, &pContext);
	if (psz == NULL)
		goto RetFalse;
	if (strcmp(psz, szDefine) != 0)
		goto RetFalse;
	pszSymbol = strtok_s(NULL, szWhiteSpace1, &pContext);
	if (pszSymbol == NULL)
		goto RetFalse;
	pszValue = strtok_s(NULL, szWhiteSpace2, &pContext);
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
		CString strPad(' ', 40-strNewName.GetLength());
		if (strPad.IsEmpty())
			strPad = '\t';
		if( fHTMLFormat )
			strLine = "#define " + strNewName + strPad + StringFromDword(dwValue) + "\n";
		else
			strLine = strNewName + strPad + StringFromDword(dwValue) + "\n";
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

	strPath = strIncludePath.Tokenize( ";", curPos );

	while( ! strPath.IsEmpty() )
	{
		strPath.TrimLeft();
		strPath.TrimRight();
		strrgPathList.AddTail( strPath );
		strPath = strIncludePath.Tokenize( ";", curPos );
	}
}

BOOL FileExists( const char *pszFileName )
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

CString FindIncludeFile( const char *pszIncludeFilename, const char *pszIncludePath )
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
	if( strEnvInclude.GetEnvironmentVariable( "INCLUDE" ) )
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

int main(int argc, char** argv)
{
	int iFirstParam = 1;

	// Turn on the "termination on heap corruption" flag.
	(void)HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	// generate output for HTML Help format
	BOOL fHTMLFormat = FALSE;

	// <include.h> filename to be copied
	const char *pszIncludeFilename = NULL;

	// additional include path
	const char *pszIncludePath = NULL;

	if( argc > 1 && _stricmp(argv[1], "/h") == 0 )
	{
		fHTMLFormat = TRUE;
		iFirstParam++;

		if( ( argc > 3 ) && _stricmp(argv[2], "/a") == 0 ) // copy file operation
		{
			pszIncludeFilename = argv[3];
			iFirstParam += 2;

			if( argc > 5 && _stricmp(argv[4], "/i" ) == 0 )
			{
				pszIncludePath = argv[5];
				iFirstParam += 2;
			}
		}
	}

	// add symbol mappings to the map.
	BOOL fAddedToMap = FALSE;
	int i;
	for (i = iFirstParam; i < argc && strchr(argv[i], ',') != NULL; i++)
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
			fprintf(stderr, "Error: Additional include file %s not found\n\n", pszIncludeFilename );
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
