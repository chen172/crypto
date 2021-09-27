# 1.What are the principal elements of a public_key cryptosystem?
**Plaintext:** This is the readable message or data that is fed into the algorithm as input.

**Encryption algorithm:** The encryption algorithm performs various transformations on the plaintext.

**Public and private keys:** This is a pair of keys that have been selected so that if one is used for encryption, the other is
used for decryption. The exact transformations performed by the algorithm depend on the public or private key that is provided.
as input.

**Ciphertext:** This is the encrypted message produced as output. It depends on the plaintext and the key. For a given message,
two different keys will produce two different Ciphertext.

**Decryption algorithm:** This algorithm accepts the Ciphertext and the matching key and produces the original plaintext.

# 2.What are the roles of the public and private key?
- One is used for encryption, the other is used for decryption.
- All participants have access to public keys, and private keys are generated locally by each participant and therefore 
need never be distributed.
- At any time, a system can change its private key and publish the companion public key to replace its old public key.

# 3.What are three broad categories of applications of public-key ycryptosystems?
**Encryption/decryption:** The sender encryption message with the recipient's public key, and the recipient decryptd 
the message with the recipient's private key.

**Digital signature:** The sender “signs“ a message with its private key. Signing is achieved by a cryptographic 
algorithm applied to the message or to a small block of data that is a function of the message.

**Key exchange:** Two sides cooperate to exchange a session key, which is a secret key for symmetric encryption generated 
for use for a particular transaction (or session) and valid for a short period of time.

# 4.What requirements must a public-key cryptosystems fulfill to be a secure algorithm?
- It is computationally infeasible for an adversary, knowing the public key, to determine the private key.
- It is computationally infeasible for an adversary, knowing the public key, and a ciphertext, to recover the original message. 
