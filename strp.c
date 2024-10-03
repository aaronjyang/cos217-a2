#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


size_t Str_getLength(const char *str) {
    assert(str != NULL);
    const char* end = str;
    while (*end != '\0') {
        end++;
    }
    return end - str;
}

char *Str_copy(char *a, const char *b) {
    assert(a != NULL);
    assert(b != NULL);

    char *temp = a;

    while (*b != '\0') {
        *temp = *b;
        temp++;
        b++;
    }
    *temp = '\0';
    return a;
}

char *Str_concat(char *a, const char *b) {
    assert(a != NULL);
    assert(b != NULL);

    char* enda = a;
    const char* endb = b;

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
    assert(a != NULL);
    assert(b != NULL);

    int i = 0;

    const char *enda = a;
    const char *endb = b;

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
    assert(a != NULL);
    assert(b != NULL);

    if (b[0] == '\0') {
        return (char*)a;
    }

    char* subStart = (char*) a;

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



int main() {
    char a[40] = "qwerty";
    char b[40] = "e";

    printf("%s", Str_search(a, b));
}