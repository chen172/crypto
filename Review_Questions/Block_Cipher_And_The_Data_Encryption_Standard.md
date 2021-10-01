# 1. Why is it important to study the Feistel cipher?
Several important symmetric block encryption algorithms in current use are based on a structure referred to as a Feistel 
block cipher.

# 2. What is the difference between a block cipher and a stream cipher?
1. A **stream cipher** is one that encrypts a digital data stream one bit or one byte at a time.
2. A **block cipher** is one in which a block of plaintext is treated as a whole and used to produce a ciphertext block of equal length.

# Why is it not practical to use an arbitrary reversible substitution cipher?
An arbitrary reversible substitution cipher (the ideal block cipher) for a large block size is not practical, however, from an 
implementation and performance point of view.

# What is a product cipher?
The execution of two or more simple ciphers in sequence in such a way that the final result or product is cryptographically 
stronger than any of the component ciphers.

# What is the difference between diffusion and confusion?
1. In **diffusion**, the statistical structure of the plaintext is dissipated into long-range statistics of the ciphertext.
2. **confusion** seeks to make the relationship between the statistics of the ciphertext and the value of the encryption key as complex as possible, again to thwart attempts to discover the key.

# Which parameters and design choices determine the actual algorithm of a Feistel cipher?
