// FileArray.h - definition of CFileArray
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#pragma once

template< typename E, class ETraits = CElementTraits< E > >
class CFileArray
{
public:
	typedef typename ETraits::INARGTYPE INARGTYPE;
	typedef typename ETraits::OUTARGTYPE OUTARGTYPE;

public:
	CFileArray() throw()
	{
		m_pData = new E;
		ATLASSERT( m_pData != NULL );
		m_nDataOffset = NULL;
		m_nDataSize = 0;
		m_hFile = INVALID_HANDLE_VALUE;
		m_nSize = 0;
		m_nBookmarkOffset = NULL;
	}

	bool OpenFile( LPCTSTR lpFileName, size_t nDataOffset, size_t nDataSize, size_t nBookmarkOffset ) throw()
	{
		ATLASSERT( m_hFile == INVALID_HANDLE_VALUE );

		m_nDataOffset = nDataOffset;
		m_nDataSize = nDataSize;
		m_nBookmarkOffset = nBookmarkOffset;

		// open the file
		m_hFile = ::CreateFile( lpFileName, 
								GENERIC_READ, // dwDesiredAccess
								FILE_SHARE_READ, // dwShareMode
								NULL, // lpSecurityAttributes
								OPEN_EXISTING, // dwCreationDisposition
								FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, // dwFlagsAndAttributes
								NULL );

		if( m_hFile == INVALID_HANDLE_VALUE )
		{
			AtlTrace( "Failed to open file\n" );
			return false;
		}

		// calculate the array size

		DWORD dwFileSizeHi = 0;
		DWORD dwFileSizeLo = ::GetFileSize( m_hFile, &dwFileSizeHi );
		ATLASSERT( dwFileSizeHi == 0 ); // we restrict file size to 4GB
		ATLASSERT( ( dwFileSizeLo % m_nDataSize ) == 0 );
		m_nSize = dwFileSizeLo / m_nDataSize;
		m_nCurrentIndex = 0xffffffff;

		AtlTrace( "File contains %d elements of %d (0x%08x) bytes each.\n", m_nSize, m_nDataSize, m_nDataSize );

		return true;
	}

	void CloseFile() throw()
	{
		ATLVERIFY( ::CloseHandle( m_hFile ) );
		m_hFile = INVALID_HANDLE_VALUE;
	}

	size_t GetCount() const throw()
	{
		return m_nSize;
	}

	bool IsEmpty() const throw()
	{
		return ( m_nSize == 0 ) ? true : false;
	}

	void SetAt( size_t iElement, INARGTYPE element )
	{
		EnsureElementLoaded( iElement );
		return *m_pData;
	}

	E& GetAt( size_t iElement ) throw()
	{
		EnsureElementLoaded( iElement );
		return *m_pData;
	}

	E& operator[]( size_t iElement ) throw()
	{
		EnsureElementLoaded( iElement );
		return *m_pData;
	}

	void RemoveAll() throw()
	{
	}

#ifdef _DEBUG
	void AssertValid() const
	{
	}
#endif  // _DEBUG

// Implementation
private:
	HANDLE	m_hFile;						// handle to file containing the array data
	E*		m_pData;						// the address of our virtual memory block
	size_t	m_nSize;						// current array size
	size_t	m_nDataOffset;					// offset of the data (loaded from file) within the E structure
	size_t	m_nDataSize;					// size of the data withing the E structure
	size_t	m_nBookmarkOffset;				// offset of the DBBKMARK element in the E structure
	size_t  m_nCurrentIndex;				// current element index

private:
	void EnsureElementLoaded( size_t iElement ) throw()
	{
		if( m_nCurrentIndex == iElement )
			return;

		ATLASSERT( iElement >= 0 && iElement < m_nSize );
		
		size_t dwFileOffset = iElement * m_nDataSize;
		DWORD dwr = ::SetFilePointer( m_hFile, (LONG)dwFileOffset, NULL, FILE_BEGIN );
		if( dwr != INVALID_SET_FILE_POINTER )
		{
			DWORD nBytesRead;
			BOOL brc = ::ReadFile( m_hFile, ((BYTE*)m_pData) + m_nDataOffset, (DWORD)m_nDataSize, &nBytesRead, NULL );
			ATLENSURE(brc);
			ATLASSERT( nBytesRead > 0 );
			DBBKMARK *pBookmark = (DBBKMARK*)(((BYTE*)m_pData) + m_nBookmarkOffset);
			*pBookmark = (DBBKMARK)iElement;
			m_nCurrentIndex = iElement;
		}
	}

public:
	~CFileArray() throw()
	{
		CloseFile();
		delete m_pData;
	}

private:
	// Private to prevent use
	CFileArray( const CFileArray& ) throw();
	CFileArray& operator=( const CFileArray& ) throw();
};

