#ifndef STR_H
#define STR_H

#include <stddef.h>


size_t Str_getLength(const char str[]);
char *Str_copy(char a[], const char b[]);
char *Str_concat(char a[], const char b[]);
int Str_compare(const char a[], const char b[]);
char* Str_search(const char a[], const char b[]);

#endif