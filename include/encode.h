#ifndef ENCODE_H
#define ENCODE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct SFreq_Node{
    int symbol;
    int frequency;
}SFreq_Node;

unsigned int* binary(const unsigned char* _data);
unsigned int* uint_to_bin(unsigned int _data, unsigned int n_size);
unsigned int bin_to_uint(unsigned int* _data, unsigned int n_size);


#endif