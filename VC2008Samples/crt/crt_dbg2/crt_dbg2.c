/*****************************************************************
 * 		   ©2000 Microsoft Corporation                   *
 *  CRT_DBG2                                                     *
 *  ----------                                                   *
 *  This program illustrates several ways to use debugging hook  *
 *  functions with the new debug versions of the C runtime       *
 *  libraries. To add some realism, it has a few elements of an  *
 *  actual application, including two bugs.                      *
 *                                                               *
 *  The program stores birthdate information in a linked list    *
 *  of Client blocks. A Client-dump hook function validates the  *
 *  birthday data and reports the contents of the Client blocks. *
 *  An allocation hook function logs heap operations to a text   *
 *  file, and the report hook function logs reports to the same  *
 *  text file.                                                   *
 *                                                               *
 *  NOTE: The allocation hook function explicitly excludes CRT   *
 *        blocks (the memory allocated internally by the C       *
 *        runtime library) from its log. It is important to      *
 *        understand why! The hook function uses fprintf( ) to   *
 *        write to the log file, and fprintf( ) allocates a CRT  *
 *        block. If CRT blocks were not excluded in this case,   *
 *        an endless loop would be created in which fprintf( )   *
 *        would cause the hook function to be called, and the    *
 *        hook would in turn call fprintf( ), which would cause  *
 *        the hook to be called again, and so on. The moral is:  *
 *                                                               *
 *   -->  IF YOUR ALLOCATION HOOK USES ANY C RUNTIME FUNCTION    *
 *        THAT ALLOCATES MEMORY, THE HOOK MUST IGNORE CRT-TYPE   *
 *        ALLOCATION OPERATIONS!                                 *
 *                                                               *
 *  HINT: If you want to be able to report CRT-type blocks in    *
 *        your allocation hook, use Windows API functions for    *
 *        formatting and output, instead of C runtime functions. *
 *        Since the Windows APIs do not use the CRT heap, they   *
 *        will not trap your hook in an endless loop.            *
 *                                                               *
 *  BUGS: There are two bugs in the program below, which the     *
 *        debug heap features identify in several ways. One bug  *
 *        is that the birthDay.Name field is not large enough    *
 *        to hold several of the test names. The field should    *
 *        be larger, and strncpy( ) should be used in place of   *
 *        strcpy( ). The second bug is that the while( ) loop    *
 *        in the printRecords( ) function should not end until   *
 *        HeadPtr itself == NULL. This bug results not only in   *
 *        an incomplete display of birthdays, but also in a      *
 *        memory leak. In addition to these two bugs, Gauss'     *
 *        birthday data is out of range (April 30, not 32).      *
 *                                                               *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <crtdbg.h>
	
// Disable deprecation warning.  The unsecure version of strcpy is
// used intentionally to illustrate bad coding practices.
#pragma warning (disable : 4996)

/*****************************************************************
 *  DATA DECLARATIONS AND DEFINES                                *
 *****************************************************************/

// The following arrays provide test data for the example program:
const char * Names[] =
{
   "George Washington",
   "Thomas Jefferson",
   "Carl Friedrich Gauss",
   "Ludwig van Beethoven",
   "Thomas Carlyle"
} ;
 
const int Dates[] =
{
   1732,  2, 11,
   1743,  4, 13,
   1777,  4, 32,
   1795, 12,  4,
   1770, 12, 16
} ;

#define  TIME_STR_LENGTH      10
#define  DATE_STR_LENGTH      10
#define  TEST_RECS            5
// A generic sort of linked-list data structure, in this case for birthdays:
typedef struct BirthdayStruct
{
   struct BirthdayStruct * NextRec;
   int   Year;
   int   Month;
   int   Day;
   char  Name[20];
} birthDay;

birthDay * HeadPtr;
birthDay * TailPtr;

#define  FILE_IO_ERROR        0
#define  OUT_OF_MEMORY        1

#define  TRUE                 7
#define  FALSE                0

// Macros for setting or clearing bits in the CRT debug flag 
#ifdef _DEBUG
#define  SET_CRT_DEBUG_FIELD(a)   _CrtSetDbgFlag((a) | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#define  CLEAR_CRT_DEBUG_FIELD(a) _CrtSetDbgFlag(~(a) & _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#else
#define  SET_CRT_DEBUG_FIELD(a)   ((void) 0)
#define  CLEAR_CRT_DEBUG_FIELD(a) ((void) 0)
#endif


/*****************************************************************
 *  SPECIAL-PURPOSE ROUTINES                                     *
 *****************************************************************/

/* ERROR HANDLER
   -------------
   Handling serious errors gracefully is a real test of craftsmanship.
   This function is just a stub; it doesn't really handle errors.
*/
void FatalError( int ErrType )
{
   exit( ErrType );
}


/* MEMORY ALLOCATION FUNCTION
   --------------------------
   The createRecord function allocates memory for a new birthday record,
   fills in the structure members, and then adds the record to a linked list.
   In debug builds, it makes these allocations in Client blocks. If memory 
   is not available, it calls the error handler. 
*/
void createRecord(
   const int    Year,
   const int    Month,
   const int    Day,
   const char * Name
#ifdef _DEBUG
,  const char * szFileName, int nLine
#endif
   )
{
   birthDay * ptr;
   size_t n;

   n = sizeof( struct BirthdayStruct );
   ptr = (birthDay *) _malloc_dbg( n, _CLIENT_BLOCK, szFileName, nLine );
   if( ptr == NULL )
      FatalError( OUT_OF_MEMORY );
   ptr->Year = Year;
   ptr->Month = Month;
   ptr->Day = Day;
   strcpy( ptr->Name, Name );

   ptr->NextRec = NULL;
   if ( HeadPtr == NULL )     // If this is the first record in the linked list
      HeadPtr = ptr;
   else
      TailPtr->NextRec = ptr;
   TailPtr = ptr;
}


/* BIRTHDAY DISPLAY FUNCTION
   -------------------------
   This function traverses the linked list, displays the birthday data,
   and then frees the memory blocks used to store the birthdays.
*/
void printRecords( )
{
   birthDay * ptr;
   char *months[] = { 
      "", "January", "February", "March", "April", "May", "June", "July",
      "August", "September", "October", "November", "December" };

   if ( HeadPtr == NULL )        // Do nothing if list is empty
      return;

   printf( "\n\nThis is the birthday list:\n" );
   while ( HeadPtr->NextRec != NULL )
   {
      printf( "   %s was born on %s %d, %d.\n", 
              HeadPtr->Name, months[HeadPtr->Month], HeadPtr->Day, HeadPtr->Year );
      ptr = HeadPtr->NextRec;
      _free_dbg( HeadPtr, _CLIENT_BLOCK );
      HeadPtr = ptr;
   }
}


/*****************************************************************
 *  DEBUG C RUNTIME LIBRARY HOOK FUNCTIONS AND DEFINES           *
 *****************************************************************/
#ifdef _DEBUG
#define  createRecord(a, b, c, d) \
         createRecord(a, b, c, d, __FILE__, __LINE__)
FILE *logFile;                // Used to log allocation information
const char lineStr[] = { "---------------------------------------\
--------------------------------------\n"  };

/* CLIENT DUMP HOOK FUNCTION
   -------------------------
   A hook function for dumping a Client block usually reports some
   or all of the contents of the block in question.  The function
   below also checks the data in several ways, and reports corruption
   or inconsistency as an assertion failure.
*/
void __cdecl MyDumpClientHook(
   void * pUserData,
   size_t nBytes
   )
{
   birthDay * bday;

   bday = (birthDay *) pUserData;

   _RPT4( _CRT_WARN, "   The birthday of %s is %d/%d/%d.\n", 
          bday->Name, bday->Month, bday->Day, bday->Year );
   _ASSERTE( ( bday->Day > 0 ) && ( bday->Day < 32 ) );
   _ASSERTE( ( bday->Month > 0 ) && ( bday->Month < 13 ) );
   _ASSERTE( ( bday->Year > 0 ) && ( bday->Year < 1996 ) );
}


/* ALLOCATION HOOK FUNCTION
   -------------------------
   An allocation hook function can have many, many different
   uses. This one simply logs each allocation operation in a file.
*/
int __cdecl MyAllocHook(
   int      nAllocType,
   void   * pvData,
   size_t   nSize,
   int      nBlockUse,
   long     lRequest,
   const unsigned char * szFileName,
   int      nLine
   )
{
   char *operation[] = { "", "allocating", "re-allocating", "freeing" };
   char *blockType[] = { "Free", "Normal", "CRT", "Ignore", "Client" };

   if ( nBlockUse == _CRT_BLOCK )   // Ignore internal C runtime library allocations
      return( TRUE );

   _ASSERT( ( nAllocType > 0 ) && ( nAllocType < 4 ) );
   _ASSERT( ( nBlockUse >= 0 ) && ( nBlockUse < 5 ) );

   fprintf( logFile, 
            "Memory operation in %s, line %d: %s a %d-byte '%s' block (#%ld)\n",
            szFileName, nLine, operation[nAllocType], nSize, 
            blockType[nBlockUse], lRequest );
   if ( pvData != NULL )
      fprintf( logFile, " at %p", pvData );

   return( TRUE );         // Allow the memory operation to proceed
}


/* REPORT HOOK FUNCTION
   --------------------
   Again, report hook functions can serve a very wide variety of purposes.
   This one logs error and assertion failure debug reports in the
   log file, along with 'Damage' reports about overwritten memory.

   By setting the retVal parameter to zero, we are instructing _CrtDbgReport
   to return zero, which causes execution to continue. If we want the function
   to start the debugger, we should have _CrtDbgReport return one.
*/
int MyReportHook(
   int   nRptType,
   char *szMsg,
   int  *retVal
   )
{
   char *RptTypes[] = { "Warning", "Error", "Assert" };

   if ( ( nRptType > 0 ) || ( strstr( szMsg, "HEAP CORRUPTION DETECTED" ) ) )
      fprintf( logFile, "%s: %s", RptTypes[nRptType], szMsg );

   retVal = 0;

   return( TRUE );         // Allow the report to be made as usual
   
}
#endif                     // End of #ifdef _DEBUG



/*****************************************************************
 *  MAIN FUNCTION                                                *
 *****************************************************************/
int main( )
{
   int i, j;
#ifndef _DEBUG
printf("Skipping this for non-debug mode.\n");
return 2;
#endif


#ifdef _DEBUG
   _CrtMemState checkPt1;
   char timeStr[TIME_STR_LENGTH], dateStr[DATE_STR_LENGTH];         // Used to set up log file


   // Send all reports to STDOUT, since this example is a console app
   _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
   _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
   _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

   // Set the debug heap to report memory leaks when the process terminates,
   // and to keep freed blocks in the linked list.
   SET_CRT_DEBUG_FIELD( _CRTDBG_LEAK_CHECK_DF | _CRTDBG_DELAY_FREE_MEM_DF );

   // Open a log file for the hook functions to use 
   fopen_s( &logFile, "MEM-LOG.TXT", "w" );
   if ( logFile == NULL )
      FatalError( FILE_IO_ERROR );
   _strtime_s( timeStr, TIME_STR_LENGTH );
   _strdate_s( dateStr, DATE_STR_LENGTH );
   fprintf( logFile, 
            "Memory Allocation Log File for Example Program, run at %s on %s.\n",
            timeStr, dateStr );
   fputs( lineStr, logFile );

   // Install the hook functions
   _CrtSetDumpClient( MyDumpClientHook );
   _CrtSetAllocHook( MyAllocHook );
   _CrtSetReportHook( MyReportHook );

#endif                     // End of #ifdef _DEBUG

   HeadPtr = NULL;

   // Create a trial birthday record.
   createRecord( 1749, 3, 23, "Pierre de Laplace" );

   // Check the debug heap, and dump the new birthday record. --Note that 
   // debug C runtime library functions such as _CrtCheckMemory( ) and 
   // _CrtMemDumpAllObjectsSince( ) automatically disappear in a release build.
   _CrtMemDumpAllObjectsSince( NULL );
   _CrtCheckMemory( );
   _CrtMemCheckpoint( &checkPt1 );

   // Since everything has worked so far, create more records
   for ( i = 0, j = 0; i < TEST_RECS; i++, j+=3 )
      createRecord( Dates[j], Dates[j+1], Dates[j+2], Names[i] );

   // Examine the results
   _CrtMemDumpAllObjectsSince( &checkPt1 );
   _CrtMemCheckpoint( &checkPt1 );
   _CrtMemDumpStatistics( &checkPt1 );
   _CrtCheckMemory( );

#ifdef _DEBUG
   // This fflush needs to be removed...
   fflush( logFile );
#endif

   // Now try displaying the records, which frees the memory being used
   printRecords( );

   // OK, time to go. Did I forget to turn out any lights? I could check
   // explicitly using _CrtDumpMemoryLeaks( ), but I have set 
   // _CRTDBG_LEAK_CHECK_DF, so the C runtime library debug heap will
   // automatically alert me at exit of any memory leaks.

#ifdef _DEBUG
   fclose( logFile );
#endif
}
