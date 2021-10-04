# 1. What characteristics are needed in a secure hash function?
1. Variable input size: H can be applied to a block of data of any size.
2. Fixed output size: H produces a fixed-length output.
3. Efficiency: H(x) is relatively easy to compute for any given x, making both hardware and software implementations practical.
4. Preimage resistant (one-way property): For any given hash value h, it is computationally infeasible to find y such that H(y) = h.
5. Second preimage resistant (weak collision resistant): For any given block x, it is computationally infeasible to find y!= with H(y) = H(x).
6. Collision resistant (strong collision resistant): It is 
