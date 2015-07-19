
#include "RC4.h"


byte S[BYTE_POSSIBLE_COUNT];
unsigned int i, j;

void rc4_init(char* key)  {
    for (int i = 0; i < BYTE_POSSIBLE_COUNT; i++)
        S[i] = i;                                                  // Initialization bytes chain
    
    int j = 0;
    for (int i = 0; i < BYTE_POSSIBLE_COUNT; i++)  {               // Mix bytes chain
        j = (j + key[i % strlen(key)] + S[i]) % BYTE_POSSIBLE_COUNT;
        rc4_swap(S, i, j);
    }
    i = j = 0;
}

byte rc4_give_byte()  {                                            // This function create a pseudo-random
    i = (i + 1) % BYTE_POSSIBLE_COUNT;                             // byte using elements from bytes chain
    j = (j + S[i]) % BYTE_POSSIBLE_COUNT;                          // and return this pseudo-random byte
    rc4_swap(S, i, j);
    return S[(S[j] + S[i]) % BYTE_POSSIBLE_COUNT];
}

void rc4_swap(byte* a, int i, int j)  {                            // Swap 2 elements in bytes chain
    unsigned char temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}
