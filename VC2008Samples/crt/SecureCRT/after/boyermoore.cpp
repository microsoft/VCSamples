#include "BoyerMoore.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Constructor */

BoyerMoore::BoyerMoore(char *pattern)
{
	if (pattern != NULL)
	{
		m_pattern = _strdup(pattern);
		if (m_pattern != NULL)
		{
			m_patternLen = (int) strlen(m_pattern);
			
			m_prefix = new int[m_patternLen];
			m_revPrefix = new int[m_patternLen];
			m_suffix = new int[m_patternLen + 1];
			
			compute_prefix(m_prefix, m_pattern);
			compute_prefix(m_revPrefix, _strrev(_strdup(m_pattern)));
			
			compute_good_suffix();
			compute_last_occurence();
		}
		else
		{
			printf("Error allocating memory\n");
			m_pattern = NULL;
			m_patternLen = 0;
		}
	}
	else
	{
		m_pattern = NULL;
		m_patternLen = 0;
	}
}

/* Destructor */

BoyerMoore::~BoyerMoore()
{
	if (m_pattern != NULL)
	{
		free(m_pattern);
		delete [] m_prefix;
		delete [] m_suffix;
		delete [] m_revPrefix;
	}
}

/* Returns pointer to m_pattern */

const char *BoyerMoore::Pattern()
{
	return (const char *) m_pattern;
}

/* Find the first occurence of m_pattern in source and return a pointer to it
   return NULL if m_pattern is not found */

char *BoyerMoore::Match(char *source)
{
	if (source != NULL && m_pattern != NULL)
	{
		int sLen = (int) strlen(source);
		int patternPos = 0;
		int shift = 0;
		
		while (shift <= sLen - m_patternLen)
		{
			patternPos = m_patternLen;
			while (patternPos > 0 && m_pattern[patternPos - 1] == source[shift + patternPos - 1])
			{
				--patternPos;
			}
			if (patternPos == 0)
			{
				return &source[shift];
			}
			else
			{
				shift += __max(m_suffix[patternPos], patternPos - m_lastOccurence[source[shift + patternPos - 1]]);
			}
		}
	}
	
	return NULL;
}

/* Generates the array used in Boyer-Moore to find the last occurence of
   a given character in <pattern> */

void BoyerMoore::compute_last_occurence()
{
	int i;
	for (i = 0; i < ALPHABETSIZE; ++i)
	{
		m_lastOccurence[i] = 0;
	}
	
	for (i = 0; i < m_patternLen; ++i)
	{
		m_lastOccurence[m_pattern[i]] = i + 1;
	}	
}

/* Generates the prefix arrays used in compute_good_suffix to generate
   the good_suffix array */

void BoyerMoore::compute_prefix(int *prefix, char *pattern)
{
	int i, pos = 0;

	prefix[0] = 0;
	for (i = 1; i < m_patternLen; ++i)
	{
		while (pos > 0 && pattern[pos] != pattern[i])
		{
			pos = prefix[pos - 1];
		}
		if (pattern[pos] == pattern[i])
		{
			++pos;
		}
		prefix[i] = pos;
	}
}

/* Generates the good_suffix array used in Boyer-Moore to help determine how far
   "over" it can shift the pattern for the next compare */

void BoyerMoore::compute_good_suffix()
{
	int i, j;
	
	for (i = 0; i <= m_patternLen; ++i)
	{
		m_suffix[i] = m_patternLen - m_prefix[m_patternLen - 1];
	}
	for (i = 1; i <= m_patternLen; ++i)
	{
		j = m_patternLen - m_revPrefix[i - 1];
		if (m_suffix[j] > i - m_revPrefix[i - 1])
		{
			m_suffix[j] = i - m_revPrefix[i - 1];
		}
	}
}