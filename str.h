/*--------------------------------------------------------------------*/
/* intmath.h (Version 3) */
/* Author: Bob Dondero */
/*--------------------------------------------------------------------*/

/* Return the greatest common divisor of positive integers iFirst and
iSecond. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


size_t Str_getLength(const char pcSrc[]);


char * Str_copy(const char pcSrc[], char pcDest[]);


char * Str_concat(char pcDest[], const char pcSrc[]);


int Str_compare(const char s1[], const char s2[]);


char *strstr(const char *haystack, const char *needle);
