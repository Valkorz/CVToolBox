#include "encode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/// @brief TEMPORARY FUNCTION REMOVE LATER
/// @param _data as in number of bits
/// @return returns the binary-converted input stream
unsigned int* binary(const unsigned char* _data){
    int count = strlen(_data) * 8, i, c, num_data;
    int* data_bin = (int*)malloc(sizeof(char) * count);
    int* char_data = (int*)malloc(sizeof(char) * 8);

    for(i = 0, c = 0; i < count; i++){
        if(i > 0 && (i % 0) > 0){
            c++;
        }

        num_data = (unsigned int)*(_data + c);
        

    }

    free(char_data);
    return NULL;
}

/// @brief Converts unsigned int to binary array
/// @param _data input data
/// @param n_size as in number of bits
/// @return binary array
unsigned int* uint_to_bin(unsigned int _data, unsigned int n_size)
{
    unsigned int* bin = (unsigned int*)malloc(sizeof(unsigned int) * n_size);
    if(bin == NULL){
        return NULL;
    }

    double div_start = (double)_data, div_next;
    int i, r;

    div_next = div_start;
    for(i = 0; i < n_size; i++){
        *(bin + n_size - 1 - i) = (div_next <= 0? 0 : (int)(div_next) % 2);
        div_next /= 2;
    }
    
    return bin;
}

/// @brief Converts a binary array to int
/// @param _data the binary data
/// @param n_size as in number of bits
/// @return 
unsigned int bin_to_uint(unsigned int* _data, unsigned int n_size){
    int res = 0, i,c;
    for(i = n_size - 1, c = 0; i >= 0; i--, c++){
        // printf("%d", *(_data + c));
        res += (int)pow(2, c) * (*(_data + i));
    }
    return res;
}