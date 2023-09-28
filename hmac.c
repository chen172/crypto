// compile: gcc hmac.c -lcrypto
#include <stdio.h>
#include <string.h>

#include "hmac.h"
#include "sha1.h"

// n: hash code length
// 160 bit
#define SHA1_DIGEST_LENGTH 20

// b: number of bits in a block
// 512 bit
#define SHA1_BLOCK_LENGTH 64


// secret key, recommended length is >= n, if key length is greater than b, the key is input to the hash function to produce an n-bit key 
#define SECRET { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x31}

GLOBAL void __hmac_sha1(unsigned char *key, int len, const unsigned char *message, int message_len, unsigned char *digest) {
	int i = 0, j = 0;
	unsigned int outlen;	

	// 1.Append zeros to left end of K to create a b-bit string K+
	// K is for key, K+ is for appened key
	unsigned char k_ipad[SHA1_BLOCK_LENGTH];
	unsigned char k_opad[SHA1_BLOCK_LENGTH];
	// TODO: maybe 20
	//unsigned char digest[100];
	
	// init k_ipad, k_opad to K+
	for (i = 0; i < len; i++) {
		k_ipad[i] = key[i];
		k_opad[i] = key[i];
	}
	for (j = i; j < SHA1_BLOCK_LENGTH; j++) {
		k_ipad[j] = 0;
		k_opad[j] = 0;
	}

	// 2.XOR K+ with ipad to produce the b-bit block Si
	// 5.XOR K+ with opad to produce the b-bit block S0
	for (i = 0; i < SHA1_BLOCK_LENGTH; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5C;
	}

	unsigned char md_value[64];
	unsigned int md_len = 20;
	SHA1_CTX sha1_ctx;

	// sha1 hash
	/*******************************************************************/
	sha1_init(&sha1_ctx);
	// 3. Append M to Si
	// 4. Apply H to the stream generated in step 3
	sha1_update(&sha1_ctx, k_ipad, SHA1_BLOCK_LENGTH);
  sha1_update(&sha1_ctx, message, message_len);
  sha1_final(&sha1_ctx, md_value);
	/*******************************************************************/

	// sha1 hash
	/*******************************************************************/
	sha1_init(&sha1_ctx);
	// 6. Append the hash result from step 4 to S0
	// 7. Apply H to the stream generated in step 6 and output the result
	sha1_update(&sha1_ctx, k_opad, SHA1_BLOCK_LENGTH);
  sha1_update(&sha1_ctx, md_value, md_len);
  sha1_final(&sha1_ctx, digest);
	/*******************************************************************/
}
