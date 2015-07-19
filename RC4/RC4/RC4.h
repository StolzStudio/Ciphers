
#ifndef __RC4__RC4__
#define __RC4__RC4__

#include <stdio.h>
#include <string.h>

#ifndef BYTE_POSSIBLE_COUNT
#define BYTE_POSSIBLE_COUNT 256

#endif

#endif



typedef unsigned char byte;

void rc4_init(char* key);

unsigned char rc4_give_byte();

void rc4_swap(byte* a, int i, int j);