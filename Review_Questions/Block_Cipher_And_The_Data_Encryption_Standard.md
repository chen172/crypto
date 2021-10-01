# 1. Why is it important to study the Feistel cipher?
Several important symmetric block encryption algorithms in current use are based on a structure referred to as a Feistel 
block cipher.

# 2. What is the difference between a block cipher and a stream cipher?
1. A **stream cipher** is one that encrypts a digital data stream one bit or one byte at a time.
2. A **block cipher** is one in which a block of plaintext is treated as a whole and used to produce a ciphertext block of equal length.

# 3. Why is it not practical to use an arbitrary reversible substitution cipher?
An arbitrary reversible substitution cipher (the ideal block cipher) for a large block size is not practical, however, from an 
implementation and performance point of view.

# 4. What is a product cipher?
The execution of two or more simple ciphers in sequence in such a way that the final result or product is cryptographically 
stronger than any of the component ciphers.

# 5. What is the difference between diffusion and confusion?
1. In **diffusion**, the statistical structure of the plaintext is dissipated into long-range statistics of the ciphertext.
2. **confusion** seeks to make the relationship between the statistics of the ciphertext and the value of the encryption key as complex as possible, again to thwart attempts to discover the key.

# 6. Which parameters and design choices determine the actual algorithm of a Feistel cipher?
**Block size:** Larger block sizes mean greater security (all other things being equal) but reduced encryption/decryption speed for a given algorithm. The greater 
security is achieved by greater diffusion, Traditionally, a block size of 64 bits has been connsidered a tradeoff and was nearly universal in block cipher design.However, the newer AES uses a 128-bit block size.

**Key size:** Larger key size means greater security but may decrease encryption/decryption speed. The greater security is achieved by greater resistance to brute-force attacks and greater confusion. Key sizes of 64 bits or less are now widely considered to be inadequate, and 128 bits has become a common size.

**Number of round:** The essence of the Feistel cipher is that a single round offers inadequate security but that multiple rounds offer increasing security. A typical size is 16 rounds.

**Subkey generation algorithm:** Greater complexity in this algorithm should lead to greater difficulty of cryptanalysis.

**Round function F:** Again, greater complexity generally means greater resistance to cryptanalysis.

# 7. Explain the avalanche effect.
A small chanage in either the plaintext or the key should produce a significant change in the plaintext.
