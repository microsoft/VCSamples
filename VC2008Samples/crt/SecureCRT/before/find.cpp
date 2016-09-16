/********************************************************************
	find.cpp
	
	Usage: find <pattern> <file>
	
	Command line app which prints out every line in <file> which
	contains <pattern>

*********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <sys/stat.h>
#include "BoyerMoore.h"

#define MAXLINE			1000
#define MAXPATH			20		/* This is obviously much too small */

void main(int argc, char *argv[])
{
	FILE *fp;
	char path[MAXPATH], pattern[MAXLINE], line[MAXLINE], out[MAXLINE];
	char lineno[20], filename[MAXPATH], outfile[MAXPATH];
	char fname[MAXPATH], fext[MAXPATH];
	char * outExt;
	int linenum = 0;
	int fh;

	// Verify correct number of args
	if (argc != 3)
	{
		printf("Usage: find <pattern> <file>\n");
	}
	else
	{
		/* Copy args */
		strcpy(pattern, *++argv);
		strcpy(path, *++argv);
		
		/* Open File */
		if ((fp = fopen(path, "r")) == NULL)
		{
			printf("Error - Could not open file: %s", filename);
		}
		else
		{
			/* Create a BoyerMoore search object based on pattern */
			BoyerMoore myPattern(pattern);
			
			/* Split out the filename */ 
			_splitpath(path, NULL, NULL, fname, fext);
			sprintf(filename, "%s%s", fname, fext);
			
			/* Open an output file - check the OutputExt environment variable
			   for a file extension, default to ".match" if not set */
			#pragma warning (suppress: 6412 6054)
			memcpy(outfile, filename, strlen(filename) + 1);
			if ((outExt = getenv("OutputExt")) != NULL)
			{
				strcat(outfile, outExt);
			}
			else
			{
				/* This is trouble.  It's an easy mistake to make.  It should be:
				   strncat(outfile, ".match", MAXPATH - strlen(outfile) - 1) */
				strncat(outfile, ".match", 6);
			}
			
			if ((fh = _creat(outfile, _S_IWRITE)) == -1)
			{
				printf("Could not open output file: %s\n", outfile);
			}
			else
			{
				sprintf(out, "*** File: %s\n", path);
				#pragma warning (suppress: 6054)
				_write(fh, out, (int) strlen(out));
			
				/* Read a line of input and search it for <pattern> using Boyer-Moore
				   Print the line if a match is found */
				while (!feof(fp))
				{
					if (fgets(line, MAXLINE, fp) != NULL)
					{
						++linenum;
						if ( myPattern.Match(line) != NULL)
						{
							itoa(linenum, lineno, 10);
							sprintf(out, "%s [%s]: %s", filename, lineno, line);
							_write(fh, out, (int) strlen(out));
						}
					}
					else
					{
						printf("Error reading file\n");
					}
				}
				
				printf("Done - output in: %s\n", outfile);
				
				_close(fh);
				fclose(fp);
			}
		}
	}
}