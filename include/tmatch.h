#ifndef TMATCH_H
#define TMATCH_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

int stringToInt(char* str);
float stringToFloat(char* str);
double stringToDouble(char* str);
int stringToBool(char* str);
char* strchr_until(const char* _Str, int _Val, int _endLine);
char* strcut(const char* _Str, int _Count);
char** strsplit(const char* _Str, char _Sep, int *_Len);
int strcount(const char* _StrSrc, const char* _StrRef);
int isUpper(char c);
double upperRatio(const char* _StrSrc);
int wordcount(const char* _StrSrc);
// char* strformat(const char* _Str, int *_Len); gotta add that later

#endif