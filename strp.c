#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


size_t Str_getLength(const char *str) {
    const char* end;

    assert(str != NULL);

    end = str;
    while (*end != '\0') {
        end++;
    }
    return end - str;
}

char *Str_copy(char *a, const char *b) {
    char *temp;

    assert(a != NULL);
    assert(b != NULL);

    temp = a;

    while (*b != '\0') {
        *temp = *b;
        temp++;
        b++;
    }
    *temp = '\0';
    return a;
}

char *Str_concat(char *a, const char *b) {
    char* enda;
    const char* endb;

    assert(a != NULL);
    assert(b != NULL);

    enda = a;
    endb = b;

    while (*enda != '\0') {
        enda++;
    }
    
    while (*endb != '\0') {
        *enda = *endb;
        enda++;
        endb++;
    }
    *enda = '\0';

    return a;
}

int Str_compare(const char *a, const char *b) {
    const char *enda;
    const char *endb;

    assert(a != NULL);
    assert(b != NULL);

    enda = a;
    endb = b;

    while (*enda != '\0' && *endb != '\0') {
        if (*enda != *endb) {
            return *enda -  *endb;
        }
        enda++;
        endb++;
    }

    
    if (*enda != *endb) {
        return *enda - *endb;
    }

    return 0;
}


char* Str_search(const char *a, const char *b) {
    char* subStart;

    assert(a != NULL);
    assert(b != NULL);

    if (b[0] == '\0') {
        return (char*)a;
    }

    subStart = (char*) a;

    while (*subStart != '\0') {
        int works = 1;
        char* subend = (char*) subStart;
        char* bend = (char*) b;

        while (*bend != '\0') {
            if ((*subend) == '\0') {
                return NULL;
            } 
            if (*subend != *bend) {
                works = 0;
                break;
            }
            subend++;
            bend++;
        }

        if (works) {
            return subStart;
        }
        subStart++;
    }

    return NULL;
}