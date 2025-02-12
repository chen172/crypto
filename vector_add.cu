#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <cuda.h>
#include <cuda_runtime.h>

#include "hmac.h"
#include "sha1.h"

#define N 10000000
#define MAX_ERR 1e-6

__global__ void vector_add(float *out, float *a, float *b, int n) {
    for(int i = 0; i < n; i ++){
        out[i] = a[i] + b[i];
    }
}

#define KEY_LEN 20
#define MESSAGE_LEN 34
// TODO: maybe 20
#define DIGEST_LEN 20
int main(){
  //unsigned char key[20];
  //unsigned char message[34];

    unsigned char *key, *message, *digest;
    unsigned char *d_key, *d_message, *d_digest;

    // Allocate host memory
    key = (unsigned char*)malloc(sizeof(unsigned char) * KEY_LEN);
    message = (unsigned char*)malloc(sizeof(unsigned char) * MESSAGE_LEN);
    digest = (unsigned char*)malloc(sizeof(unsigned char) * DIGEST_LEN);

    // Initialize host arrays
    for (int i = 0; i < KEY_LEN; i++)
		  key[i] = i;
    
    char *messageStr = "Sample message for keylen<blocklen";\
    for (int i = 0; i < MESSAGE_LEN; i++)
      message[i] = messageStr[i];

    // Allocate device memory
    cudaMalloc((void**)&d_key, sizeof(unsigned char) * KEY_LEN);
    cudaMalloc((void**)&d_message, sizeof(unsigned char) * MESSAGE_LEN);
    cudaMalloc((void**)&d_digest, sizeof(unsigned char) * DIGEST_LEN);

    // Transfer data from host to device memory
    cudaMemcpy(d_key, key, sizeof(unsigned char) * KEY_LEN, cudaMemcpyHostToDevice);
    cudaMemcpy(d_message, message, sizeof(unsigned char) * MESSAGE_LEN, cudaMemcpyHostToDevice);

    // Executing kernel
for (int i = 0; i < 1000000; i++)
    __hmac_sha1<<<1,1>>>(d_key, KEY_LEN, d_message, MESSAGE_LEN, d_digest);

    // Transfer data back to host memory
    cudaMemcpy(digest, d_digest, sizeof(unsigned char) * DIGEST_LEN, cudaMemcpyDeviceToHost);

    // Verification
    for(int i = 0; i < DIGEST_LEN; i++){
        printf("%02x", digest[i]);
    }
    printf("\n");

    // Deallocate device memory
    cudaFree(d_key);
    cudaFree(d_message);
    cudaFree(d_digest);

    // Deallocate host memory
    free(key); 
    free(message); 
    free(digest);
#if 0
    float *a, *b, *out;
    float *d_a, *d_b, *d_out; 

    // Allocate host memory
    a   = (float*)malloc(sizeof(float) * N);
    b   = (float*)malloc(sizeof(float) * N);
    out = (float*)malloc(sizeof(float) * N);

    // Initialize host arrays
    for(int i = 0; i < N; i++){
        a[i] = 1.0f;
        b[i] = 2.0f;
    }

    // Allocate device memory
    cudaMalloc((void**)&d_a, sizeof(float) * N);
    cudaMalloc((void**)&d_b, sizeof(float) * N);
    cudaMalloc((void**)&d_out, sizeof(float) * N);

    // Transfer data from host to device memory
    cudaMemcpy(d_a, a, sizeof(float) * N, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, sizeof(float) * N, cudaMemcpyHostToDevice);

    // Executing kernel 
    vector_add<<<1,1>>>(d_out, d_a, d_b, N);
    
    // Transfer data back to host memory
    cudaMemcpy(out, d_out, sizeof(float) * N, cudaMemcpyDeviceToHost);

    // Verification
    for(int i = 0; i < N; i++){
        assert(fabs(out[i] - a[i] - b[i]) < MAX_ERR);
    }
    printf("out[0] = %f\n", out[0]);
    printf("PASSED\n");

    // Deallocate device memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_out);

    // Deallocate host memory
    free(a); 
    free(b); 
    free(out);
#endif
}
