#ifndef ENCODE_H
#define ENCODE_H
#include <stdio.h>
#include <stdlib.h>

unsigned int* binary(const unsigned char* _data);
unsigned int* uint_to_bin(unsigned int _data, unsigned int n_size);
unsigned int bin_to_uint(unsigned int* _data, unsigned int n_size);


#endif