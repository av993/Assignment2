/*--------------------------------------------------------------------*/
/* strp.c                                                          */
/* Author: Ameya Vaidya                                               */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

char* Str_copy(char pcDest[], const char pcSrc[]) {

    char *srcPtr;
    char *destPtr;

    assert(pcSrc != NULL);
    assert(pcDest != NULL);

    srcPtr = (char*)pcSrc;
    destPtr = pcDest;

    while (*srcPtr != '\0') {
        *destPtr = *srcPtr;
        srcPtr++;
        destPtr++;
    }

    *destPtr = *srcPtr;
    return pcDest;
}

char * Str_concat(char pcDest[], const char pcSrc[]) {

    size_t destLength;
    char *srcPtr;
    char *destPtr;

    assert(pcSrc != NULL);
    assert(pcDest != NULL);

    destLength = Str_getLength(pcDest);
    srcPtr = (char*)pcSrc;
    destPtr = pcDest;
    destPtr += destLength;

    while (*srcPtr != '\0') {
        *destPtr = *srcPtr;
        srcPtr++;
        destPtr++;
    }

    *destPtr = '\0';
    return pcDest;
}


int Str_compare(const char s1[], const char s2[]) {

    size_t max_length = 0;
    size_t length1; 
    size_t length2;
    const char *s1Ptr;
    const char *s2Ptr;
    size_t i;

    assert(s1 != NULL);
    assert(s2 != NULL);

    length1 = Str_getLength(s1);
    length2 = Str_getLength(s2);

    /* This attempts to find the longest length between 
    the strings s1 and s2 and set equal to max_length*/
    if (length1 < length2) {
        max_length = length2;
    } else {
        max_length = length1;
    }

    s1Ptr = s1;
    s2Ptr = s2;

    for (i = 0; i < max_length; i++) {
    
        /* If both have null bytes at the
        same point then they are the same and 
        if s1 ends before s2, then return -1 
        and vice versa */

        if (*s1Ptr == '\0') {
            if (*s2Ptr  == '\0') {
                return 0;
            } else {
                return -1;
            }
        } else if (*s2Ptr == '\0') {
            return 1;
        }

        /* If the character in s1 
        is smaller than the character in s2, then
        return -1 and vice versa */
        if (*s1Ptr < *s2Ptr) {
            return -1;
        } else if (*s1Ptr > *s2Ptr) {
            return 1;
        }

        s1Ptr++;
        s2Ptr++;
    }

    return 0;
}

char *Str_search(const char *pcHaystack, const char *pcNeedle) {

    size_t needleLength;
    const char *haystackPtr;
    const char *innerHaystackPtr;
    const char *needlePtr;
    const char *needleStart;

    assert(pcHaystack != NULL);
    assert(pcNeedle != NULL);

    needleLength = Str_getLength(pcNeedle);

    if (needleLength == 0) {
        return (char*)pcHaystack;
    }

    haystackPtr = pcHaystack;
    innerHaystackPtr = pcHaystack;
    needlePtr = pcNeedle;
    needleStart = NULL;

    /*
        This outer loop runs for each character until the
        end of pcHaystack.
    */
    while (*haystackPtr != '\0') {
        innerHaystackPtr = haystackPtr;
        needleStart = NULL;
        needlePtr = pcNeedle;

        /*
            This inner loop runs for every character of pcHaystack
            in order to find where the Str_search algorithmn ends
        */
        while (*innerHaystackPtr != '\0') {

            /*
                If characters of pcNeedle match characters of
                pcHaystack, then indicate where the 
                match was found and continue looping so that you can 
                find whether the next couple of characters match the 
                needle string.
            */
            if (*innerHaystackPtr == *needlePtr) {
                if (needlePtr == pcNeedle) {
                    needleStart = innerHaystackPtr;
                }
                needlePtr++;
            } else {
                break;
            }

            innerHaystackPtr++;
        }
        
        /*
            If the needle was found, then return an
            address to the beggining of the needle in the haystack.
        */
        if (*needlePtr == '\0') {
            return (char*)needleStart;
        }

        haystackPtr++;
    }
    return NULL;
}
