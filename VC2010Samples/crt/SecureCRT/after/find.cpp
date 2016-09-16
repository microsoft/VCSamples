/********************************************************************
	find.cpp
	
	Usage: find <pattern> <file>
	
	Command line app which prints out every line in <file> which
	contains <pattern>

*********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <share.h>
#include <io.h>
#include <sys/stat.h>
#include "BoyerMoore.h"

#define MAXLINE			1000
#define MAXPATH			20		/* This is obviously much too small */

/* Custom invalid parameter handler.  This handler is executed instead
   of the default handler when the CRT encounters invalid parameters*/

void myInvalidParameterHandler(const wchar_t* expression,
					   const wchar_t* function, 
                       const wchar_t* file, 
                       unsigned int line, 
                       uintptr_t pReserved)
{
	wprintf(L"Invalid parameter detected in function %s."
			L" File: %s Line: %d\n", function, file, line);
	wprintf(L"Expression: %s\n", expression);
	exit(1);
}


void main(int argc, char *argv[])
{
	FILE *fp;
	char path[MAXPATH], pattern[MAXLINE], line[MAXLINE], out[MAXLINE];
	char lineno[20], filename[MAXPATH], outfile[MAXPATH];
	char fname[MAXPATH], fext[MAXPATH];
	char outExt[MAXPATH];
	int linenum = 0;
	int fh;
	size_t envSize = 0;

	/* Set the invalid paramter handler, save the old one */
	_invalid_parameter_handler oldHandler, newHandler;
    newHandler = myInvalidParameterHandler;
    oldHandler = _set_invalid_parameter_handler(newHandler);

	// Verify correct number of args
	if (argc != 3) 
	{
		printf("Usage: find <pattern> <file>\n");
	}
	else
	{
		/* Copy args */
		/* strcpy_s and strncpy_s are typical _s functions which require you
		   to specify the destination buffer size and return an errcode value which
		   corresponds to the errno set by the function. */
		if (strcpy_s(pattern, MAXLINE, *++argv) != 0)
		{
			printf("Please limit the length of <pattern> to %d\n.", MAXLINE);
			exit(1);
		}

		if (strcpy_s(path, MAXPATH, *++argv) != 0)
		{
			printf("Please limit the length of <path> to %d\n.", MAXPATH);
			exit(1);
		}

		/* Open File */
		/* fopen_s requires you to pass **FILE parameter to hold the file pointer
		   and returns an errcode */
		if (fopen_s(&fp, path, "r") != 0)
		{
			printf("Error - Could not open file: %s", filename);
			exit(1);
		}
		else
		{
			/* Create a BoyerMoore search object based on pattern */
			BoyerMoore myPattern(pattern);
			
			/* Split out the filename */ 
			/* _splitpath_s and sprintf_s follow the typical pattern of requiring
			   a buffer size (or many buffer sizes in the case of _splitpath_s) and
			   returning an errcode */
			_splitpath_s(path, NULL, 0, NULL, 0, fname, MAXPATH, fext, MAXPATH);
			sprintf_s(filename, MAXPATH, "%s%s", fname, fext);
			
			/* Open an output file - check the OutputExt environment variable
			   for a file extension, default to ".match" if not set */

			/* memcpy_s also requires a buffersize and returns an errcode.  
			   strnlen requires a buffer size, but returns the length of the
			   string rather than an errcode */
			memcpy_s(outfile, MAXPATH, filename, strnlen(filename, MAXPATH) + 1);

			/* getenv_s does not return a pointer to the CRT's global environment.
			   Instead, you need to provide a buffer (and its size) to store the 
			   value of the environment variable as well as a size_t parameter to
			   store the size of the environment variable (useful for determining
			   how big your buffer needs to be).  */
			getenv_s(&envSize ,outExt, MAXPATH, "OutputExt");
			if (envSize != 0)
			{
				/* strcat_s is typical, requiring a buffer size and returning an 
				errcode */
				strcat_s(outfile, MAXPATH, outExt);
			}
			else
			{
				/* strncat_s is typical, requiring a buffer size and returning an 
				errcode */
				strncat_s(outfile, MAXPATH, ".match", 6);
			}
			
			/* _creat has been deprecate in favor of _sopen_s.  Passing 
			   _O_CREAT | _O_TRUNC | _O_RDWR for the oflag parameter best reproduces 
			   the behavior of _creat.  See the documentation for _sopen_s for 
			   more details. */
			if (_sopen_s(&fh, outfile, _O_CREAT | _O_TRUNC | _O_RDWR, _SH_DENYNO, 
						_S_IREAD | _S_IWRITE) != 0)
			{
				printf("Could not open output file: %s\n", outfile);
				fclose(fp);
				exit(1);
			}
			else
			{
				/* change sprintf to sprintf_s */
				sprintf_s(out, MAXLINE, "*** File: %s\n", path);
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
							/* _itoa_s requires a buffer size and returns an errcode. */
							_itoa_s(linenum, lineno, 20, 10);
							/* change sprintf to sprintf_s */
							sprintf_s(out, MAXLINE, "%s [%s]: %s", filename, lineno, line);
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