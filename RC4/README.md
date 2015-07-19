RC4
  RC4 (Rivest cipher, another name - Ron's code, also known as ARC4 or ARCFOUR) - it's the most widely used stream cipher. It's   used in most popular Internet protocols such as TLS. Algorithm was designed by Ron Rivest of RSA Security ( American computer   and network security company ) in 1987.
Description:
  RC4 generates a pseudorandom stream of bits ( a keystream ). To generate the keystream, the cipher makes of a secret internal   state which consists of two parts:
    1. A permutation of all 256 possible bytes;
    2. Two 8-bit index-pointers ( "i" and "j" ).
  The permutation is intialized with a variable length key, using the key-scheduling algorithm ( KSA ). 
  In my program: 
    "rc4_init" function realizes a KSA.
    "rc4_give_byte" function realizes a PRGA ( pseudo-random generation algorithm )

