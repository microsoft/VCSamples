/*****************************************************************
 * 		    ©2000 Microsoft Corporation                  *
 *  CRT_DBG1                                                     *
 *  This simple program illustrates the basic debugging features *
 *  of the C runtime libraries, and the kind of debug output     *
 *  that these features generate.                                *
 *****************************************************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <crtdbg.h>
	
// Disable deprecation warnings.  The unsecure version of strcpy is
// used intentionally to show off debugging features.
#pragma warning (disable : 4996)

// This routine place comments at the head of a section of debug output
void OutputHeading( const char * explanation )
{
   _RPT1( _CRT_WARN, "\n\n%s:\n**************************************\
************************************\n", explanation );
}

// The following macros set and clear, respectively, given bits
// of the C runtime library debug flag, as specified by a bitmask.
#ifdef   _DEBUG
#define  SET_CRT_DEBUG_FIELD(a) \
            _CrtSetDbgFlag((a) | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#define  CLEAR_CRT_DEBUG_FIELD(a) \
            _CrtSetDbgFlag(~(a) & _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#else
#define  SET_CRT_DEBUG_FIELD(a)   ((void) 0)
#define  CLEAR_CRT_DEBUG_FIELD(a) ((void) 0)
#endif


int main( )
{
   char *p1, *p2;
   _CrtMemState s1, s2, s3;

#ifndef _DEBUG
printf("Skipping this for non-debug mode.\n");
return 2;
#endif

   // Send all reports to STDOUT
   _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
   _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
   _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
   _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
   _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
   _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );

   // Allocate 2 memory blocks and store a string in each
   p1 = malloc( 34 );
   strcpy( p1, "This is the p1 string (34 bytes)." );

   p2 = malloc( 34 );
   strcpy( p2, "This is the p2 string (34 bytes)." );


   OutputHeading( 
      "Use _ASSERTE to check that the two strings are identical" );
   _ASSERTE( strcmp( p1, p2 ) == 0 );

   OutputHeading( 
      "Use a _RPT macro to report the string contents as a warning" );
   _RPT2( _CRT_WARN, "p1 points to '%s' and \np2 points to '%s'\n", p1, p2 );

   OutputHeading( 
      "Use _CRTMemDumpAllObjectsSince to check the p1 and p2 allocations" );
   _CrtMemDumpAllObjectsSince( NULL );

   free( p2 );

   OutputHeading( 
      "Having freed p2, dump allocation information about p1 only" );
   _CrtMemDumpAllObjectsSince( NULL );

   // Store a memory checkpoint in the s1 memory-state structure
   _CrtMemCheckpoint( &s1 );

   // Allocate another block, pointed to by p2
   p2 = malloc( 38 );
   strcpy( p2, "This new p2 string occupies 38 bytes.");

   // Store a 2nd memory checkpoint in s2
   _CrtMemCheckpoint( &s2 );

   OutputHeading( 
      "Dump the changes that occurred between two memory checkpoints" );
   if ( _CrtMemDifference( &s3, &s1, &s2 ) )
      _CrtMemDumpStatistics( &s3 );

   // Free p2 again and store a new memory checkpoint in s2
   free( p2 );
   _CrtMemCheckpoint( &s2 );

   OutputHeading( 
      "Now the memory state at the two checkpoints is the same" );
   if ( _CrtMemDifference( &s3, &s1, &s2 ) )
      _CrtMemDumpStatistics( &s3 );

   strcpy( p1, "This new p1 string is over 34 bytes" );
   OutputHeading( "Free p1 after overwriting the end of the allocation" );
   free( p1 );

   // Set the debug-heap flag so that freed blocks are kept on the
   // linked list, to catch any inadvertent use of freed memory
   SET_CRT_DEBUG_FIELD( _CRTDBG_DELAY_FREE_MEM_DF );

   p1 = malloc( 10 );
   free( p1 );
   strcpy( p1, "Oops" );

   OutputHeading( "Perform a memory check after corrupting freed memory" );
   _CrtCheckMemory( );

   // Use explicit calls to _malloc_dbg to save file name and line number
   // information, and also to allocate Client type blocks for tracking
   p1 = _malloc_dbg( 40, _NORMAL_BLOCK, __FILE__, __LINE__ );
   p2 = _malloc_dbg( 40, _CLIENT_BLOCK, __FILE__, __LINE__ );
   strcpy( p1, "p1 points to a Normal allocation block" );
   strcpy( p2, "p2 points to a Client allocation block" );

   // You must use _free_dbg to free a Client block
   OutputHeading( 
      "Using free( ) to free a Client block causes an assertion failure" );
   free( p1 );
   free( p2 );

   p1 = malloc( 10 );
   OutputHeading( "Examine outstanding allocations (dump memory leaks)" );
   _CrtDumpMemoryLeaks( );

   // Set the debug-heap flag so that memory leaks are reported when
   // the process terminates. Then, exit.
   OutputHeading( "Program exits without freeing a memory block" );
   SET_CRT_DEBUG_FIELD( _CRTDBG_LEAK_CHECK_DF );
}