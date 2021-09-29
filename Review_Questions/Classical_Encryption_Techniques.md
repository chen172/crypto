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
