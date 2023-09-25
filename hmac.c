// compile: gcc hmac.c -lcrypto
#include <stdio.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <openssl/err.h>
#include <string.h>

#include "sha1.h"

// n: hash code length
// 160 bit
#define SHA1_DIGEST_LENGTH 20

// b: number of bits in a block
// 512 bit
#define SHA1_BLOCK_LENGTH 64


// secret key, recommended length is >= n, if key length is greater than b, the key is input to the hash function to produce an n-bit key 
#define SECRET { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x31}

#if 0
void 
get_the_key(uint8_t key[]) {
	int len = sizeof(key);
	
	if (len < SHA1_DIGEST_LENGTH)
		printf("warnning, secret key length less than hash code length!\n");
	
	// 
	if (len > SHA1_BLOCK_LENGTH)
		sha1(key[]);
}
#endif
void 
hmac_sha1() {
	int i = 0, j = 0;
	unsigned int outlen;	
	//uint8_t key[] = SECRET;
	// keylen = blocklen
	#if 0
	uint8_t key[64];
	for (i = 0; i < 64; i++)
		key[i] = i;
	#endif
	// keylen < blocklen
	#if 1
	uint8_t key[20];
	for (i = 0; i < 20; i++)
		key[i] = i;
	#endif
	int len = sizeof(key);
	for (i = 0; i < len; i++)
		printf("%02x", key[i]);
	printf("\n");
	// 1.Append zeros to left end of K to create a b-bit string K+
	//uint8_t key_plus[SHA1_BLOCK_LENGTH];
	uint8_t k_ipad[SHA1_BLOCK_LENGTH];
	uint8_t k_opad[SHA1_BLOCK_LENGTH];
	uint8_t digest[100];
	char *message = "Sample message for keylen<blocklen";
	int message_len = strlen(message);

	#if 1
	// init k_ipad, k_opad to K+
	for (i = 0; i < len; i++) {
		k_ipad[i] = key[i];
		k_opad[i] = key[i];
	}
	for (j = i; j < SHA1_BLOCK_LENGTH; j++) {
		k_ipad[j] = 0;
		k_opad[j] = 0;
	}
	#endif


	#if 0	
	// init k_ipad, k_opad to K+
	for (i = 0; i < len; i++) {
		k_ipad[SHA1_BLOCK_LENGTH-i] = key[len-i];
		k_opad[SHA1_BLOCK_LENGTH-i] = key[len-i];
	}
	for (j = i; j < SHA1_BLOCK_LENGTH; j++) {
		k_ipad[SHA1_BLOCK_LENGTH-j] = 0;
		k_opad[SHA1_BLOCK_LENGTH-j] = 0;
	}
	#endif


	// 2.XOR K+ with ipad to produce the b-bit block Si
	// 5.XOR K+ with opad to produce the b-bit block S0
	for (i = 0; i < SHA1_BLOCK_LENGTH; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5C;
	}

	OpenSSL_add_all_algorithms();
	ERR_load_crypto_strings();

	unsigned char md_value[EVP_MAX_MD_SIZE];
	unsigned int md_len;
	EVP_MD_CTX *hashctx;
	hashctx = EVP_MD_CTX_new();
	const EVP_MD *hashptr = EVP_get_digestbyname("SHA1");

	EVP_MD_CTX_init(hashctx);
	EVP_DigestInit_ex(hashctx, hashptr, NULL);
	// 3. Append M to Si
	// 4. Apply H to the stream generated in step 3
	EVP_DigestUpdate(hashctx, k_ipad, SHA1_BLOCK_LENGTH);
	EVP_DigestUpdate(hashctx, message, message_len);
	EVP_DigestFinal_ex(hashctx, md_value, &md_len);

	
	EVP_MD_CTX_init(hashctx);
	EVP_DigestInit_ex(hashctx, hashptr, NULL);
	// 6. Append the hash result from step 4 to S0
	// 7. Apply H to the stream generated in step 6 and output the result
	EVP_DigestUpdate(hashctx, k_opad, SHA1_BLOCK_LENGTH);
	EVP_DigestUpdate(hashctx, md_value, md_len);
	EVP_DigestFinal_ex(hashctx, digest, &md_len);
	EVP_MD_CTX_free(hashctx);
	//EVP_MD_CTX_clean(hashctx);
	printf("digest len is %d\n", md_len);
	for (i = 0; i < md_len; i++)
		printf("%02x", digest[i]);
	printf("\n");
}

void 
__hmac_sha1(uint8_t *key, int len, char *message, int message_len) {
	int i = 0, j = 0;
	unsigned int outlen;	

	// 1.Append zeros to left end of K to create a b-bit string K+
	// K is for key, K+ is for appened key
	uint8_t k_ipad[SHA1_BLOCK_LENGTH];
	uint8_t k_opad[SHA1_BLOCK_LENGTH];
	uint8_t digest[100];
	
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

	OpenSSL_add_all_algorithms();

	unsigned char md_value[EVP_MAX_MD_SIZE];
	unsigned int md_len;
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

	printf("digest len is %d\n", md_len);
	for (i = 0; i < md_len; i++)
		printf("%02x", digest[i]);
	printf("\n");
}
int main()
{
	hmac_sha1();
	return 0;
}
