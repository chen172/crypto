# 1. What are the essential ingredients of a symmetric cipher?
**Plaintext:** This is the original intelligible message or data that is fed into the algorithm as input.

**Encryption algorithm:** The encryption algorithm performs various substitutions and transformations on the plaintext.

**Secret key:** The secret key is also input to the algorithm. The key is a value independent of the plaintext and of the algorithm. The algorithm will produce a different output depending on the specific key being used at the time. The exact 
substitutions and transformations performed by the algorithm depend on the key.

**Ciphertext:** This is the scrambled message produced as output. It depends on the plaintext and the secret key. For a
given message, two different keys will produce two different Ciphertext. The Ciphertext is an apparently random stream of 
data and, as it stands, is unintelligible.

**Decryption algorithm:** This is essentially the encryption algorithm run in reverse. It takes the ciphertext and the secret 
key and produces the original plaintext.

# 2. What are the two basic functions used in encryption algorithm?
**Substitution:** in which  each element in the plaintext (bit, letter, group of bits or letters) is mapped into another element.

**Transposition:** in which elements in the plaintext are rearranged.

# 3, How many keys are required for two people to communicate via a cipher?
- single key for symmetric encryption.
- two key for asymmetric encryption.

# 4, What is the difference between a block cipher and a stream cipher?
A **block cipher** processes the input one block of elements at a time, producing an output block for each input block. A **stream cipher** processes the input elements continuously, producing output one element at a time, as it goes long.

# 5. What are two general approaches to attacking a cipher?
**Cryptanalysis:** Cryptanalytic attacks rely on the nature of the algorithm plus perhaps some knowledge of the general 
characteristics of the plaintext or even some sample plaintext-ciphertext pairs, This type of attack exploits the characteristics of the algorithm to attempt to deduce a specific plaintext or to deduce the key being used.

**Brute-force attack:** The attacker tries every possible key on a piece of Ciphertext until an intelligible translation into
plaintext is obtained. On average, half of all possible keys must be tried to achieve success.

# 6. List and briefly define types of cryptanalytic attacks based on what is known to the attack.
1. Ciphertext Only
- Encryption algorithm 
- Ciphertext 

2. Known Plaintext
- Encryption algorithm 
- Ciphertext 
- One or more plaintext-ciphertext pairs formed with secret key

3. Chosen Plaintext 
- Encryption algorithm 
- Ciphertext 
- Plaintext message chosen by cryptanalyst, together with its corresponding Ciphertext generated with the secret key.

4. Chosen Ciphertext 
- Encryption algorithm 
- Ciphertext 
- Ciphertext Chosen by cryptanalyst, together with its corresponding decryptd plaintext generated with the secret key.

5. Chosen Text
- Encryption algorithm 
- Ciphertext 
- Plaintext message chosen by cryptanalyst, together with its corresponding Ciphertext generated with the secret key.
- Ciphertext Chosen by cryptanalyst, together with its corresponding decryptd plaintext generated with the secret key.
