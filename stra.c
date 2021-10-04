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

    size_t curr = 0;

    while (pcDest[curr] != '\0') 
        curr++;

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
    size_t length1 = sizeof(s1) / sizeof(int);
    size_t length2 = sizeof(s2) / sizeof(int);

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

    size_t needleStart = -1;
    size_t needleIndex = 0;

    size_t i;
    for (i = 0; i < sizeof(haystack)  / sizeof(int); i++) {
        if (haystack[i] == needle[needleIndex]) {
            if (needleIndex == 0) {
                needleStart = i;
            }
            needleIndex++;
        } else {
            needleIndex = 0;
        }
    }

    if (needleStart == -1) {
        return NULL;
    } else {
        return &haystack[needleStart];
    }

}

int main() {
       
    const char acSrc1[] = {'R', 'u', 't', 'h', '\0', 'x'};
    const char acSrc2[] = {'R', 'o', 't', 'h', '\0', 'y'};
    int iResult1 = Str_compare(acSrc1, acSrc2);
    int iResult2 = strcmp(acSrc1, acSrc2);
    printf("%d\n", iResult1);
    printf("%d\n", iResult2);
    return 0;
   
}