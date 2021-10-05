/*--------------------------------------------------------------------*/
/* intmath.h (Version 3) */
/* Author: Ameya Vaidya */
/*--------------------------------------------------------------------*/

/* Return the greatest common divisor of positive integers iFirst and
iSecond. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/* 
    Str_getLength is a method that returns the length 
    of the pcSrc char array (equivalent to length of string).
    The value returned is the length of the char[] arr 
    (as a size_t).
    The parameter pcSrc[] is the character array passed into
    the method. 

*/
size_t Str_getLength(const char pcSrc[]);

/*
    The Str_copy method copies the string pcSrc to the 
    string pcDest. It will overlap pcSrc if needed.

    It returns the length of the string as a size_t

    The two parameters are both character arrays
    that represent the src and dest strings.
*/
char* Str_copy(char pcDest[], const char pcSrc[]);

/*
    The Str_concat method appends the pcSrc string 
    to the pcDest string and overwrites the null 
    byte at the end of pcDest. 

    It returns char* which will be the string
    after pcSrc is appended to pcDest.

    The two parameters are both character arrays
    that represent the src and dest strings.
*/
char* Str_concat(char pcDest[], const char pcSrc[]);

/*
    The Str_compare function compares the strings s1
    and s2 lexigraphically. It will return a value
    less than, equal to, or greater than zero if 
    s1 is less than, equal to, or greater than s2 
    respectively. 

    It returns either -1, 0, or 1, depending on 
    whether s1 is greater than, equal to, 
    or less than s2.

    The two parameters are both character arrays
    that represent the s1 and s2 strings.
*/
int Str_compare(const char s1[], const char s2[]);


/*
    The Str_search finds the first occurence of the 
    substring pcNeedle in the string pcHaystack. 

    The return value is a char* that points to the 
    beggining of the substring if found and 
    will point to NULL if not found. 
    
    The two parameters are both character arrays
    that represent the pcHaystack and pcNeedle strings.

*/
char* Str_search(const char *pcHaystack, const char *pcNeedle);
