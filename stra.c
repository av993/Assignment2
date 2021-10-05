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

    size_t curr;
    curr = 0;

    assert(pcSrc != NULL);
    assert(pcDest != NULL);

    while (pcSrc[curr] != '\0') {
        pcDest[curr] = pcSrc[curr];
        curr++;
    }

    pcDest[curr] = '\0';
    return pcDest;
}

char* Str_concat(char pcDest[], const char pcSrc[]) {
    
    size_t curr;
    size_t i;

    assert(pcSrc != NULL);
    assert(pcDest != NULL);

    i = 0;
    curr = Str_getLength(pcDest);

    while (pcSrc[i] != '\0') {
        pcDest[curr] = pcSrc[i];
        i++;
        curr++;
    }

    pcDest[curr] = '\0';
    return pcDest;
}


int Str_compare(const char s1[], const char s2[]) {

    size_t max_length;
    size_t length1; 
    size_t length2;
    size_t i;


    assert(s1 != NULL);
    assert(s2 != NULL);

    length1 = Str_getLength(s1);
    length2 = Str_getLength(s2);

    if (length1 < length2) {
        max_length = length2;
    } else {
        max_length = length1;
    }

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

char *Str_search(const char *pcHaystack, const char *pcNeedle) {

    size_t pcNeedleLength;
    size_t pcNeedleStart;
    size_t pcNeedleIndex;
    size_t i;
    size_t j;

    assert(pcHaystack != NULL);
    assert(pcNeedle != NULL);

    pcNeedleStart = -1;
    pcNeedleIndex = 0;
    i = 0;
    j = 0;

    pcNeedleLength = Str_getLength(pcNeedle);

    if (pcNeedleLength == 0) {
        return (char*)pcHaystack;
    }

    while (pcHaystack[i] != '\0') {
        j = i;
        pcNeedleStart = -1;
        pcNeedleIndex = 0;

        while (pcHaystack[j] != '\0') {
            if (pcHaystack[j] == pcNeedle[pcNeedleIndex]) {
                if (pcNeedleIndex == 0) {
                    pcNeedleStart = j;
                }
                pcNeedleIndex++;
            } else {
                break;
            }

            j++;
        }
        
        if (pcNeedleIndex == pcNeedleLength) {
            return (char*)&pcHaystack[pcNeedleStart];
        }
        i++;
    }

    return NULL;

}
