#include "str.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#ifndef S_SPLINT_S
#include <sys/resource.h>
#endif


size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char* Str_copy(char pcDest[], const char pcSrc[]) {
    assert(pcSrc != NULL);
    assert(pcDest != NULL);

    size_t curr = 0;

    while (pcSrc[curr] != '\0') {
        pcDest[curr] = pcSrc[curr];
        curr++;
    }

    pcDest[curr] = '\0';
    return pcDest;
}

char * Str_concat(char pcDest[], const char pcSrc[]) {
    assert(pcSrc != NULL);
    assert(pcDest != NULL);

    size_t curr;
    curr = Str_getLength(pcDest);

    size_t i = 0;

    while (pcSrc[i] != '\0') {
        pcDest[curr] = pcSrc[i];
        i++;
        curr++;
    }

    pcDest[curr] = '\0';
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

    size_t i;
    for (i = 0; i < max_length; i++) {
        if (s1[i] == '\0') {
            if (s2[i] == '\0') {
                return 0;
            } else {
                return -1;
            }
            return 1;
        } else if (s2[i] == '\0') {
            return 1;
        }

        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
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

    if (needleLength == 0) {
        return haystack;
    }
    
    size_t needleStart = -1;
    size_t needleIndex = 0;

    size_t i = 0;
    size_t j = 0;


    while (haystack[i] != '\0') {
        j = i;
        needleStart = -1;
        needleIndex = 0;

        while (haystack[j] != '\0') {
            if (haystack[j] == needle[needleIndex]) {
                if (needleIndex == 0) {
                    needleStart = j;
                }
                needleIndex++;
            } else {
                break;
            }

            j++;
        }
        
        if (needleIndex == needleLength) {
            return &haystack[needleStart];
        }
        i++;
    }

    return NULL;

}
