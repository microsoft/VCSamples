/* ©2000 Microsoft Corporation
 * DFACOBJS.C
 * This program allocates some CLIENT type blocks of memory
 * and then calls _CrtDoForAllClientObjects to print out the contents
 * of each client block found on the heap.
 */

#include <crtdbg.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*
 * My Memory Block linked-list data structure
 */
typedef struct MyMemoryBlockStruct
{
   struct MyMemoryBlockStruct *NextPtr;
   int blockType;
   int allocNum;
} aMemoryBlock;
aMemoryBlock *HeadPtr;
aMemoryBlock *TailPtr;

/* 
 * CreateMemoryBlock
 * allocates a block of memory, fills in the data structure 
 * and adds the new block to the linked list
 * Returns 1 if successful, otherwise 0
 */
int CreateMemoryBlock(
   int allocNum,
   int blockType
   )
{
   aMemoryBlock *blockPtr;
   size_t size;

   size = sizeof( struct MyMemoryBlockStruct );
   if ( blockType == _CLIENT_BLOCK )
      blockPtr = (aMemoryBlock *) _malloc_dbg( size, _CLIENT_BLOCK, __FILE__, __LINE__ );
   else
      blockPtr = (aMemoryBlock *) _malloc_dbg( size, _NORMAL_BLOCK, __FILE__, __LINE__ );

   if ( blockPtr == NULL )
      return(0);

   blockPtr->allocNum = allocNum;
   blockPtr->blockType = blockType;

   blockPtr->NextPtr = NULL;
   if ( HeadPtr == NULL )
      HeadPtr = blockPtr;
   else
      TailPtr->NextPtr = blockPtr;
   TailPtr = blockPtr;
   return(1);
}

/*
 * RestoreMemoryToHeap
 * restores all of the memory that we allocated on the heap
 */
void RestoreMemoryToHeap( )
{
   aMemoryBlock *blockPtr;

   if (!HeadPtr)
      return;

   while ( HeadPtr->NextPtr != NULL )
   {
      blockPtr = HeadPtr->NextPtr;
      if  ( HeadPtr->blockType == _CLIENT_BLOCK )
         _free_dbg( HeadPtr, _CLIENT_BLOCK );
      else
         _free_dbg( HeadPtr, _NORMAL_BLOCK );

      HeadPtr = blockPtr;
   }
}
	
/*
 * MyClientObjectHook
 * A hook function for performing some action on all
 * client blocks found on the heap - In this case, print
 * out the value stored at each memory address.
 */                     
void __cdecl MyClientObjectHook(
   void * pUserData, 
   void * ignored
   )
{
   aMemoryBlock *blockPtr;
   long allocReqNum = 0;
   int success;

   blockPtr = (aMemoryBlock *) pUserData;

   /*
    * Let's retrieve the actual object allocation order request number
    * and see if it's different from the allocation number we stored in
    * in our data structure.
    */
   success = _CrtIsMemoryBlock((const void *) blockPtr,
            (unsigned int) sizeof( struct MyMemoryBlockStruct ), &allocReqNum,
            NULL, NULL );
   if ( success )
   printf( "Block #%d \t Type: %d \t Allocation Number: %d\n", blockPtr->allocNum,
           blockPtr->blockType, allocReqNum); 
   else
   {
          printf("ERROR: not a valid memory block.\n");        
          exit( 1 );
   }
}

int main( void )
{
   div_t div_result;
   int i, success, tmpFlag;
#ifndef _DEBUG
printf("Skipping this for non-debug mode.\n");
return 2;
#endif


   /*
    * Set the _crtDbgFlag to turn debug type allocations.
    * This will enable us to specify that blocks of type
    * _CLIENT_BLOCK can be allocated and tracked separately.
    * Turn off checking for internal CRT blocks.
    */
   tmpFlag = _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG );
   tmpFlag |= _CRTDBG_ALLOC_MEM_DF;
   tmpFlag |= _CRTDBG_CHECK_CRT_DF;
   _CrtSetDbgFlag( tmpFlag );

   /*
    * We're going to allocate 22 blocks and every other block is
    * going to be of type _CLIENT_BLOCK.
    * Blocks numbered 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, and 22
    * should all be _CLIENT_BLOCKS.
    */
   HeadPtr = NULL;
   printf("Allocating the memory ");
   for (i=1; i < 23; i++)
   {
          div_result = div( i, 2);
   if ( div_result.rem > 0 )
      success = CreateMemoryBlock( i, _NORMAL_BLOCK );
   else
      success = CreateMemoryBlock( i, _CLIENT_BLOCK );
        
   if ( !success )
   {
         printf(" ERROR.\n");        
            exit( 1 );
      }
   else
      printf(".");
   }
   printf(" done.\n");
     
   /*
    * We're going to call _CrtDoForAllClientObjects to
    * make sure that only blocks numbered 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, and 22
    * got allocated as _CLIENT_BLOCKS.
    */
   _CrtDoForAllClientObjects( MyClientObjectHook, NULL );

   /*
    * Restore the memory to the heap
    */
   RestoreMemoryToHeap();
   exit( 0 );
}
