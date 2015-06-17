
#include "RC4.h"
#define BIT_SIZE 256


byte S[BIT_SIZE];
unsigned int i, j;

void rc4_init(char* key)  {
    for (int i = 0; i < BIT_SIZE; i++)
        S[i] = i;                                                  // Initialization bytes chain
    
    int j = 0;
    for (int i = 0; i < BIT_SIZE; i++)  {                          // Mix bytes chain
        j = (j + key[i % strlen(key)] + S[i]) % BIT_SIZE;
        rc4_swap(S, i, j);
    }
    i = j = 0;
}

byte rc4_give_byte()  {                                            // This function create a pseudo-random
    i = (i + 1) % BIT_SIZE;                                        // byte using elements from bytes chain
    j = (j + S[i]) % BIT_SIZE;                                     // and return this pseudo-random byte
    rc4_swap(S, i, j);
    return S[(S[j] + S[i]) % BIT_SIZE];
}

void rc4_swap(byte* a, int i, int j)  {                            // Swap 2 elements in bytes chain
    unsigned char temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}
