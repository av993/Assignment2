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
    assert(pcSrc != NULL);
    assert(pcDest != NULL);

    char *srcPtr;
    char *destPtr;

    srcPtr = pcSrc;
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
    assert(pcSrc != NULL);
    assert(pcDest != NULL);

    size_t destLength;
    destLength = Str_getLength(pcDest);
    
    char *srcPtr;
    char *destPtr;
    srcPtr = pcSrc;
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
    assert(s1 != NULL);
    assert(s2 != NULL);

    size_t max_length = 0;

    size_t length1; 
    length1 = Str_getLength(s1);
    size_t length2;
    length2 = Str_getLength(s2);

    if (length1 < length2) {
        max_length = length2;
    } else {
        max_length = length1;
    }

    const char *s1Ptr;
    const char *s2Ptr;

    size_t i;
    for (i = 0; i < max_length; i++) {
        if (*s1Ptr == '\0') {
            if (*s2Ptr  == '\0') {
                return 0;
            } else {
                return -1;
            }
            return 1;
        } else if (*s2Ptr == '\0') {
            return 1;
        }

        if (*s1Ptr < *s2Ptr) {
            return -1;
        } else if (*s1Ptr > *s2Ptr) {
            return 1;
        }
    }

    return 0;
}

char *Str_search(const char *haystack, const char *needle) {
    assert(haystack != NULL);
    assert(needle != NULL);

    size_t needleLength;
    needleLength = Str_getLength(needle);

    size_t i = 0;
    size_t j = 0;
    
    const char *haystackPtr;
    const char *innerHaystackPtr;
    const char *needlePtr;
    const char *needleStart;

    while (*haystackPtr != '\0') {
        innerHaystackPtr = haystackPtr;
        needleStart = NULL;
        needlePtr = needle;

        while (*innerHaystackPtr != '\0') {
            if (*innerHaystackPtr == *needlePtr) {
                if (needlePtr == needle) {
                    needleStart = innerHaystackPtr;
                }
                needlePtr++;
            } else {
                break;
            }

            innerHaystackPtr++;
        }
        
        if (*needlePtr == "\0") {
            return needleStart;
        }

        haystackPtr++;
    }
    return NULL;
}


