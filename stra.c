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
    size_t length1 = sizeof(s1) / sizeof(s1[0]);
    size_t length2 = sizeof(s2) / sizeof(s2[0]);

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


    size_t needleLength = 0;
    while (needle[needleLength] != '\0') 
        needleLength++;
    
    size_t needleStart = -1;
    size_t needleIndex = 0;

    size_t i = 0;
    while (haystack[i] != '\0') {
        if (needleIndex == needleLength) {
            break;
        }

        if (haystack[i] == needle[needleIndex]) {
            if (needleIndex == 0) {
                needleStart = i;
            }
            needleIndex++;
        } else {
            needleStart = -1;
        }

        i++;
    }



    if (needleStart == -1 || needleIndex != needleLength) {
        return NULL;
    } else {
        return &haystack[needleStart];
    }

}

int main() {
      const char acHaystack[] = "abcde";
      const char acNeedle[] = "bcdef";
    char* pcResult1 = Str_search(acHaystack, acNeedle);
    char* pcResult2 = strstr(acHaystack, acNeedle);
    printf("%s\n", pcResult1);
    printf("%s\n", pcResult2);
    return 0;
   
}