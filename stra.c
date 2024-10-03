#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

size_t Str_getLength(const char str[]) {
    size_t length;

    assert(str != NULL);

    length = 0;

    while(str[length] != '\0') {
        length++;
    }
    return length;
}


char *Str_copy(char a[], const char b[]) {
    size_t i;

    assert(a != NULL);
    assert(b != NULL);

    for (i = 0 ; i < Str_getLength(b); i++){
        a[i] = b[i];
    }
    a[i] = '\0';
    return a;
}

char *Str_concat(char a[], const char b[]) {
    size_t i;
    size_t ogLength;

    assert(a != NULL);
    assert(b != NULL);

    ogLength = Str_getLength(a);
    
    for (i = 0; i < Str_getLength(b); i++){
        a[i+ogLength] = b[i];
    }
    a[i+ogLength] = '\0';

    return a;
}

int Str_compare(const char a[], const char b[]) {
    size_t i;

    assert(a != NULL);
    assert(b != NULL);

    i = 0;

    while (a[i] != '\0' && b[i] != '\0'){ 
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
        i++;
    }
    if (a[i] != b[i]) {
        return a[i] - b[i];
    }

    return 0;
}

char* Str_search(const char a[], const char b[]) {
    size_t i;

    assert(a != NULL);
    assert(b != NULL);

    if (Str_getLength(b) > Str_getLength(a)) {
        return NULL;
    }

    for (i = 0; i < Str_getLength(a) - Str_getLength(b); i++) {
        int works = 1;
        size_t j;
        for (j = 0; j < Str_getLength(b); j++) {
            if (a[i + j] != b[j]) {
                works = 0;
                break;
            }
        }
        if (works) {
            return (char*) &a[i];
            
        }
    }

    return NULL;
}
