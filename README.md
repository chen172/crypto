# crypto
crypto algorithm

# Build
nvcc hmacCuda.cu hmac.cu sha1.cu -rdc=true -o hmacCuda

# CPU vs GPU
1. Measure-Command {start-process .\hmacCuda.exe -wait}
2. Measure-Command {start-process .\hmacCPU.exe -wait}

# Ref
https://cuda-tutorial.readthedocs.io/en/latest/tutorials/tutorial01/
