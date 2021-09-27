# What are the principal elements of a public_key cryptosystem?
**Plaintext:** This is the readable message or data that is fed into the algorithm as input.

**Encryption algorithm:** The encryption algorithm performs various transformations on the plaintext.

**Public and private keys:** This is a pair of keys that have been selected so that if one is used for encryption, the other is
used for decryption. The exact transformations performed by the algorithm depend on the public or private key that is provided 
as input.

**Ciphertext:** This is the encrypted message produced as output. It depends on the plaintext and the key. For a given message,
two different keys will produce two different Ciphertext.

**Decryption algorithm:** This algorithm accepts the Ciphertext and the matching key and produces the original plaintext.
