# 1. What characteristics are needed in a secure hash function?
1. Variable input size: H can be applied to a block of data of any size.
2. Fixed output size: H produces a fixed-length output.
3. Efficiency: H(x) is relatively easy to compute for any given x, making both hardware and software implementations practical.
4. Preimage resistant (one-way property): For any given hash value h, it is computationally infeasible to find y such that H(y) = h.
5. Second preimage resistant (weak collision resistant): For any given block x, it is computationally infeasible to find y!= with H(y) = H(x).
6. Collision resistant (strong collision resistant): It is computationally infeasible to find any pair (x,y) with x!=y, such that H(x) = H(y).
7. Pseudorandomness: Output of H meets standard tests for pseudorandomness.

# 2. What is the difference between weak and strong collision resistance?
ref Question 1

# 3. What is the role of a compression function in a hash function?
The hash algorithm involves repeated use of a **compression function**, f, that takes two inputs (an n-bit input from the previous step, called the chaining variable, and a b-bit block) and produces an n-bit output.

