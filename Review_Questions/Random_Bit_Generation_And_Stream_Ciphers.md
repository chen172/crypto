# 1.What is the difference between statisical randomness and unpredictability?
Randomness and unpredictability are two distinct and not necessarily compatible 
requirements for a sequence of random numbers.

**Randomness** Traditionally, the concern in the gerneration of a sequence of 
allegedly random numbers has been that the sequence of numbers be random in some 
well-defined statistical sense.The following two criteria are used to validate
that a sequence of numbers is random:
- Uniform distribution: The distribution of bits in the sequence should be uniform;
that is, the frequency of occurrence of ones and zeros should be approximately equal.
- Independence: No one subsequene in the sequence can be inferred from the others.

**Unpredictability** The successive numbers of sequence are unpredictable. Care must be 
taken that an opponent not be able to predict future elements of the sequence on the 
basis of earlier elements.

# 2. List important design considerations for a stream cipher.
- The encryption sequence should have a large period. A pseudorandom number generator 
uses a function that produces a deterministic stream of bits that eventually repeats.
The longer the period of repeat the more difficult it will be to do cryptanalysis.
- The keystream should approximate the properties of a true random number stream as 
close as possible. For example, there should be an approximately equal number of 1s and
0s. If the keysream is treated as a stream of bytes, then all of the 256 possible byte
values should appear approximately equally often.
- The key needs to be sufficiently long. With current technology, a key length of at least 
128 bits is desirable.
