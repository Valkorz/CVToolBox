#ifndef TYPEMATCH_H
#define TYPEMATCH_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringToInt(char* str);
float stringToFloat(char* str);
double stringToDouble(char* str);
int stringToBool(char* str);
char* strchr_until(const char* _Str, int _Val);
char* strcut(const char* _Str, int _Count);

int stringToInt(char* str){
    int i, len = strlen(str);
    // printf("\n strlen for int: %d", len);
    float res = 0.0;
    for(i = 0; i < len; i++){
        char current = *(str + len - i - 1);
        if(current < '0' || current > '9') continue;
        res += (current - '0') * (pow(10,i));
    }

    return (int)res;
}

//Converts string to float. Figured I'd make this for converting values stored in the data structures I made
//but apparently string.h already has functions for converting strings to other data types so I just wasted
//my fucking time LMFAOOOOOOOOOOOOOO anyway I'll still keep the code cuz why not, guess I'm kinda proud of it
//(even though floating point precision still fucks the result a bit).
float stringToFloat(char* str){
    printf("\n Converting string to float: %s", str);
    int i, len = strlen(str), z, b;

    //Split the fraction into whole and decimal
    char* float_part = strcut(strchr(str, '.'), 1);
    char* int_part = strchr_until(str, '.');

    int result_partial_int = stringToInt(int_part);

    for(i = 0, z = 0, b = 0; i < strlen(float_part); i++) 
    {
        if(*(float_part + i) == '0') z++;
        else b++;
    }

    //the decimal part of the number is the int (whole numbers) multiplied by 10^x (the fraction)
    float result_partial_float = (float)stringToInt(float_part) * (float)pow(10, -(z + b));
    float sum = (float)result_partial_int + result_partial_float;

    return sum;   
}

double stringToDouble(char* str){
    //todo
}

int stringToBool(char* str){
    //todo
}

//Reads string until specified character is found. Returns resulting string.
char* strchr_until(const char* _Str, int _Val)
{
    int i, c;
    char* newStr, *buffer = (char*)malloc(sizeof(char) * strlen(_Str));
    for(i = 0; i < strlen(_Str); i++){
        char current = *(_Str + i);
        if(current != (char)_Val){
            *(buffer + i) = current;
            // printf("\n %d: Added %c to buffer because it isn't equal to %c.", i, current, (char)_Val);
        }
        else break;
    }

    newStr = (char*)malloc(sizeof(char) * (i + i));

    for(c = 0; c < i; c++){
        *(newStr + c) = *(buffer + c);
    }

    *(newStr + i) = '\0'; 
    // printf("\n allocaed newStr with size: %d, strlen: %d", i, strlen(newStr));

    free(buffer);
    return newStr;
}

//Cuts a number of characters from the string (left-to-right and returns a new string.)
//Will return NULL if _Count is larger than the string size.
char* strcut(const char* _Str, int _Count){
    int i, c, len = strlen(_Str);
    if(_Count > len){
        fprintf(stderr, "Count is larger than string length!");
        return NULL;
    }

    //The loop starts reading the string after i >= _Count.
    //Characters are stored in the buffer, which are then transferred 
    //to newStr.
    char* newStr, *buffer = (char*)malloc(sizeof(char) * len);

    for(i = 0; i < len; i++){
        if(i < _Count) continue;

        *(buffer + i - _Count) = *(_Str + i);
    }

    newStr = (char*)malloc(sizeof(char) * (len - _Count));

    for(c = 0; c < i - _Count; c++){
        *(newStr + c) = *(buffer + c);
    }

    *(newStr + i - _Count) = '\0'; 

    free(buffer);
    return newStr;
}

#endif