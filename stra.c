#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

size_t Str_getLength(const char str[]) {
    assert(str != NULL);

    int length = 0;

    while(str[length] != '\0') {
        length++;
    }
    return length;
}


char *Str_copy(char a[], const char b[]) {
    assert(a != NULL);
    assert(b != NULL);

    for (int i = 0 ; i < Str_getLength(b); i++){
        a[i] = b[i];
    }
    a[Str_getLength(b)+1] = '\0';
    return a;
}

char *Str_concat(char a[], const char b[]) {
    assert(a != NULL);
    assert(b != NULL);

    int ogLength = Str_getLength(a);

    for (int i = 0 ; i < Str_getLength(b); i++){
        a[i+ogLength] = b[i];
    }
    return a;
}

int Str_compare(const char a[], const char b[]) {
    assert(a != NULL);
    assert(b != NULL);

    int i = 0;

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
    assert(a != NULL);
    assert(b != NULL);

    if (b[0] == '\0') {
        return (char*)a;
    }

    for (int i = 0; i < Str_getLength(a) - Str_getLength(b); i++) {
        int works = 1;
        for (int j = 0; j < Str_getLength(b); j++) {
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



int main() {
    char a[40] = "qwerty";
    char b[40] = "abcdqwertyabcd";

    printf("%s", Str_copy(b, a));
}