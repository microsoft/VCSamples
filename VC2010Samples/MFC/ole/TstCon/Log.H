// File: Log.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

class CTestContainer98Item;

class CLog :
   public CObject
{
   DECLARE_DYNAMIC( CLog );

public:
   CLog();
   ~CLog();

   CLog& operator<<( COleVariant& var );
   CLog& operator<<( int n );
   virtual CLog& operator<<( LPCTSTR pszString ) = NULL;
};

class CNullLog :
   public CLog
{
   DECLARE_DYNAMIC( CNullLog );

public:
   CNullLog();
   ~CNullLog();

   CLog& operator<<( LPCTSTR pszString );
};

class CDebugLog : public CLog
{
   DECLARE_DYNAMIC( CDebugLog );

public:
   CDebugLog();
   ~CDebugLog();

   CLog& operator<<( LPCTSTR pszString );

protected:
   BOOL m_tStartOfLine;
};

class CFileLog :
   public CLog
{
   DECLARE_DYNAMIC( CFileLog );

public:
   CFileLog();
   ~CFileLog();

   CLog& operator<<( LPCTSTR pszString );

public:
   BOOL Create( LPCTSTR pszFileName );
   CString GetFileName() const;

protected:
   CStdioFile m_file;
};

class COutputWindowLog : public CLog
{
   DECLARE_DYNAMIC( COutputWindowLog );

public:
   COutputWindowLog( CEdit* pEditBox );
   ~COutputWindowLog();

   CLog& operator<<( LPCTSTR pszString );

protected:
   CEdit* m_pEditBox;
};
