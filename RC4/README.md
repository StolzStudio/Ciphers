#RC4

  RC4 (Rivest cipher, another name - Ron's code, also known as ARC4 or ARCFOUR) - it's the most widely used stream cipher. It   uses in most popular Internet protocols such as TLS. Algorithm was designed by Ron Rivest of RSA Security ( American computer   and network security company ) in 1987.
  
#Description

  RC4 generates a pseudorandom stream of bits ( a keystream ). To generate the keystream, the cipher makes of a secret internal   state which consists of two parts:
  
    1. A permutation of all 256 possible bytes;
    
    2. Two 8-bit index-pointers ( "i" and "j" ).
    
  The permutation is intialized with a variable length key, using the key-scheduling algorithm ( KSA ).
  Once this has been completed, the stream of bits is generated using the pseudo-random generation algorithm (PRGA).
  
#Security
  
  Unlike a modern stream cipher, RC4 does not take a separate nonce alongside the key. This means that if a single long-term key is to be used to securely encrypt multiple streams, the protocol must specify how to combine the nonce and the long-term key to generate the stream key for RC4. One approach to addressing this is to generate a "fresh" RC4 key by hashing a long-term key with a nonce.
  
  However, many applications that use RC4 simply concatenate key and nonce; RC4's weak key schedule then gives rise to related key attacks, like the Fluhrer, Mantin and Shamir attack ( i will not describing them ).
#In my program
  
    "rc4_init" function realizes a KSA.
    
    "rc4_give_byte" function realizes a PRGA.

