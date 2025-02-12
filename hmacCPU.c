// compile: gcc hmac.c -lcrypto
#include <stdio.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <openssl/err.h>
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

#if 0
typedef unsigned int u32;
typedef struct sha1_ctx
{
  u32 h[5];

  u32 w0[4];
  u32 w1[4];
  u32 w2[4];
  u32 w3[4];

  int len;

} sha1_ctx_t;

typedef enum sha1_constants
{
  SHA1M_A=0x67452301U,
  SHA1M_B=0xefcdab89U,
  SHA1M_C=0x98badcfeU,
  SHA1M_D=0x10325476U,
  SHA1M_E=0xc3d2e1f0U,

  SHA1C00=0x5a827999U,
  SHA1C01=0x6ed9eba1U,
  SHA1C02=0x8f1bbcdcU,
  SHA1C03=0xca62c1d6U

} sha1_constants_t;

void sha1_init (sha1_ctx_t *ctx)
{
  ctx->h[0] = SHA1M_A;
  ctx->h[1] = SHA1M_B;
  ctx->h[2] = SHA1M_C;
  ctx->h[3] = SHA1M_D;
  ctx->h[4] = SHA1M_E;

  ctx->w0[0] = 0;
  ctx->w0[1] = 0;
  ctx->w0[2] = 0;
  ctx->w0[3] = 0;
  ctx->w1[0] = 0;
  ctx->w1[1] = 0;
  ctx->w1[2] = 0;
  ctx->w1[3] = 0;
  ctx->w2[0] = 0;
  ctx->w2[1] = 0;
  ctx->w2[2] = 0;
  ctx->w2[3] = 0;
  ctx->w3[0] = 0;
  ctx->w3[1] = 0;
  ctx->w3[2] = 0;
  ctx->w3[3] = 0;

  ctx->len = 0;
}

#define SHA1_STEP_S(f,a,b,c,d,e,x)    \
{                                     \
  e += K;                             \
  e  = hc_add3_S (e, x, f (b, c, d)); \
  e += hc_rotl32_S (a,  5u);          \
  b  = hc_rotl32_S (b, 30u);          \
}

void sha1_transform (const u32 w0[4], const u32 w1[4], const u32 w2[4], const u32 w3[4], u32 digest[5])
{
  u32 a = digest[0];
  u32 b = digest[1];
  u32 c = digest[2];
  u32 d = digest[3];
  u32 e = digest[4];

  u32 w0_t = w0[0];
  u32 w1_t = w0[1];
  u32 w2_t = w0[2];
  u32 w3_t = w0[3];
  u32 w4_t = w1[0];
  u32 w5_t = w1[1];
  u32 w6_t = w1[2];
  u32 w7_t = w1[3];
  u32 w8_t = w2[0];
  u32 w9_t = w2[1];
  u32 wa_t = w2[2];
  u32 wb_t = w2[3];
  u32 wc_t = w3[0];
  u32 wd_t = w3[1];
  u32 we_t = w3[2];
  u32 wf_t = w3[3];

  #undef K
  #define K SHA1C00

  SHA1_STEP_S (SHA1_F0o, a, b, c, d, e, w0_t);
  SHA1_STEP_S (SHA1_F0o, e, a, b, c, d, w1_t);
  SHA1_STEP_S (SHA1_F0o, d, e, a, b, c, w2_t);
  SHA1_STEP_S (SHA1_F0o, c, d, e, a, b, w3_t);
  SHA1_STEP_S (SHA1_F0o, b, c, d, e, a, w4_t);
  SHA1_STEP_S (SHA1_F0o, a, b, c, d, e, w5_t);
  SHA1_STEP_S (SHA1_F0o, e, a, b, c, d, w6_t);
  SHA1_STEP_S (SHA1_F0o, d, e, a, b, c, w7_t);
  SHA1_STEP_S (SHA1_F0o, c, d, e, a, b, w8_t);
  SHA1_STEP_S (SHA1_F0o, b, c, d, e, a, w9_t);
  SHA1_STEP_S (SHA1_F0o, a, b, c, d, e, wa_t);
  SHA1_STEP_S (SHA1_F0o, e, a, b, c, d, wb_t);
  SHA1_STEP_S (SHA1_F0o, d, e, a, b, c, wc_t);
  SHA1_STEP_S (SHA1_F0o, c, d, e, a, b, wd_t);
  SHA1_STEP_S (SHA1_F0o, b, c, d, e, a, we_t);
  SHA1_STEP_S (SHA1_F0o, a, b, c, d, e, wf_t);
  w0_t = rotl32_S ((wd_t ^ w8_t ^ w2_t ^ w0_t), 1u); SHA1_STEP_S (SHA1_F0o, e, a, b, c, d, w0_t);
  w1_t = rotl32_S ((we_t ^ w9_t ^ w3_t ^ w1_t), 1u); SHA1_STEP_S (SHA1_F0o, d, e, a, b, c, w1_t);
  w2_t = rotl32_S ((wf_t ^ wa_t ^ w4_t ^ w2_t), 1u); SHA1_STEP_S (SHA1_F0o, c, d, e, a, b, w2_t);
  w3_t = rotl32_S ((w0_t ^ wb_t ^ w5_t ^ w3_t), 1u); SHA1_STEP_S (SHA1_F0o, b, c, d, e, a, w3_t);

  #undef K
  #define K SHA1C01

  w4_t = rotl32_S ((w1_t ^ wc_t ^ w6_t ^ w4_t), 1u); SHA1_STEP_S (SHA1_F1, a, b, c, d, e, w4_t);
  w5_t = rotl32_S ((w2_t ^ wd_t ^ w7_t ^ w5_t), 1u); SHA1_STEP_S (SHA1_F1, e, a, b, c, d, w5_t);
  w6_t = rotl32_S ((w3_t ^ we_t ^ w8_t ^ w6_t), 1u); SHA1_STEP_S (SHA1_F1, d, e, a, b, c, w6_t);
  w7_t = rotl32_S ((w4_t ^ wf_t ^ w9_t ^ w7_t), 1u); SHA1_STEP_S (SHA1_F1, c, d, e, a, b, w7_t);
  w8_t = rotl32_S ((w5_t ^ w0_t ^ wa_t ^ w8_t), 1u); SHA1_STEP_S (SHA1_F1, b, c, d, e, a, w8_t);
  w9_t = rotl32_S ((w6_t ^ w1_t ^ wb_t ^ w9_t), 1u); SHA1_STEP_S (SHA1_F1, a, b, c, d, e, w9_t);
  wa_t = rotl32_S ((w7_t ^ w2_t ^ wc_t ^ wa_t), 1u); SHA1_STEP_S (SHA1_F1, e, a, b, c, d, wa_t);
  wb_t = rotl32_S ((w8_t ^ w3_t ^ wd_t ^ wb_t), 1u); SHA1_STEP_S (SHA1_F1, d, e, a, b, c, wb_t);
  wc_t = rotl32_S ((w9_t ^ w4_t ^ we_t ^ wc_t), 1u); SHA1_STEP_S (SHA1_F1, c, d, e, a, b, wc_t);
  wd_t = rotl32_S ((wa_t ^ w5_t ^ wf_t ^ wd_t), 1u); SHA1_STEP_S (SHA1_F1, b, c, d, e, a, wd_t);
  we_t = rotl32_S ((wb_t ^ w6_t ^ w0_t ^ we_t), 1u); SHA1_STEP_S (SHA1_F1, a, b, c, d, e, we_t);
  wf_t = rotl32_S ((wc_t ^ w7_t ^ w1_t ^ wf_t), 1u); SHA1_STEP_S (SHA1_F1, e, a, b, c, d, wf_t);
  w0_t = rotl32_S ((wd_t ^ w8_t ^ w2_t ^ w0_t), 1u); SHA1_STEP_S (SHA1_F1, d, e, a, b, c, w0_t);
  w1_t = rotl32_S ((we_t ^ w9_t ^ w3_t ^ w1_t), 1u); SHA1_STEP_S (SHA1_F1, c, d, e, a, b, w1_t);
  w2_t = rotl32_S ((wf_t ^ wa_t ^ w4_t ^ w2_t), 1u); SHA1_STEP_S (SHA1_F1, b, c, d, e, a, w2_t);
  w3_t = rotl32_S ((w0_t ^ wb_t ^ w5_t ^ w3_t), 1u); SHA1_STEP_S (SHA1_F1, a, b, c, d, e, w3_t);
  w4_t = rotl32_S ((w1_t ^ wc_t ^ w6_t ^ w4_t), 1u); SHA1_STEP_S (SHA1_F1, e, a, b, c, d, w4_t);
  w5_t = rotl32_S ((w2_t ^ wd_t ^ w7_t ^ w5_t), 1u); SHA1_STEP_S (SHA1_F1, d, e, a, b, c, w5_t);
  w6_t = rotl32_S ((w3_t ^ we_t ^ w8_t ^ w6_t), 1u); SHA1_STEP_S (SHA1_F1, c, d, e, a, b, w6_t);
  w7_t = rotl32_S ((w4_t ^ wf_t ^ w9_t ^ w7_t), 1u); SHA1_STEP_S (SHA1_F1, b, c, d, e, a, w7_t);

  #undef K
  #define K SHA1C02

  w8_t = rotl32_S ((w5_t ^ w0_t ^ wa_t ^ w8_t), 1u); SHA1_STEP_S (SHA1_F2o, a, b, c, d, e, w8_t);
  w9_t = rotl32_S ((w6_t ^ w1_t ^ wb_t ^ w9_t), 1u); SHA1_STEP_S (SHA1_F2o, e, a, b, c, d, w9_t);
  wa_t = rotl32_S ((w7_t ^ w2_t ^ wc_t ^ wa_t), 1u); SHA1_STEP_S (SHA1_F2o, d, e, a, b, c, wa_t);
  wb_t = rotl32_S ((w8_t ^ w3_t ^ wd_t ^ wb_t), 1u); SHA1_STEP_S (SHA1_F2o, c, d, e, a, b, wb_t);
  wc_t = rotl32_S ((w9_t ^ w4_t ^ we_t ^ wc_t), 1u); SHA1_STEP_S (SHA1_F2o, b, c, d, e, a, wc_t);
  wd_t = rotl32_S ((wa_t ^ w5_t ^ wf_t ^ wd_t), 1u); SHA1_STEP_S (SHA1_F2o, a, b, c, d, e, wd_t);
  we_t = rotl32_S ((wb_t ^ w6_t ^ w0_t ^ we_t), 1u); SHA1_STEP_S (SHA1_F2o, e, a, b, c, d, we_t);
  wf_t = rotl32_S ((wc_t ^ w7_t ^ w1_t ^ wf_t), 1u); SHA1_STEP_S (SHA1_F2o, d, e, a, b, c, wf_t);
  w0_t = rotl32_S ((wd_t ^ w8_t ^ w2_t ^ w0_t), 1u); SHA1_STEP_S (SHA1_F2o, c, d, e, a, b, w0_t);
  w1_t = rotl32_S ((we_t ^ w9_t ^ w3_t ^ w1_t), 1u); SHA1_STEP_S (SHA1_F2o, b, c, d, e, a, w1_t);
  w2_t = rotl32_S ((wf_t ^ wa_t ^ w4_t ^ w2_t), 1u); SHA1_STEP_S (SHA1_F2o, a, b, c, d, e, w2_t);
  w3_t = rotl32_S ((w0_t ^ wb_t ^ w5_t ^ w3_t), 1u); SHA1_STEP_S (SHA1_F2o, e, a, b, c, d, w3_t);
  w4_t = rotl32_S ((w1_t ^ wc_t ^ w6_t ^ w4_t), 1u); SHA1_STEP_S (SHA1_F2o, d, e, a, b, c, w4_t);
  w5_t = rotl32_S ((w2_t ^ wd_t ^ w7_t ^ w5_t), 1u); SHA1_STEP_S (SHA1_F2o, c, d, e, a, b, w5_t);
  w6_t = rotl32_S ((w3_t ^ we_t ^ w8_t ^ w6_t), 1u); SHA1_STEP_S (SHA1_F2o, b, c, d, e, a, w6_t);
  w7_t = rotl32_S ((w4_t ^ wf_t ^ w9_t ^ w7_t), 1u); SHA1_STEP_S (SHA1_F2o, a, b, c, d, e, w7_t);
  w8_t = rotl32_S ((w5_t ^ w0_t ^ wa_t ^ w8_t), 1u); SHA1_STEP_S (SHA1_F2o, e, a, b, c, d, w8_t);
  w9_t = rotl32_S ((w6_t ^ w1_t ^ wb_t ^ w9_t), 1u); SHA1_STEP_S (SHA1_F2o, d, e, a, b, c, w9_t);
  wa_t = rotl32_S ((w7_t ^ w2_t ^ wc_t ^ wa_t), 1u); SHA1_STEP_S (SHA1_F2o, c, d, e, a, b, wa_t);
  wb_t = rotl32_S ((w8_t ^ w3_t ^ wd_t ^ wb_t), 1u); SHA1_STEP_S (SHA1_F2o, b, c, d, e, a, wb_t);

  #undef K
  #define K SHA1C03

  wc_t = rotl32_S ((w9_t ^ w4_t ^ we_t ^ wc_t), 1u); SHA1_STEP_S (SHA1_F1, a, b, c, d, e, wc_t);
  wd_t = rotl32_S ((wa_t ^ w5_t ^ wf_t ^ wd_t), 1u); SHA1_STEP_S (SHA1_F1, e, a, b, c, d, wd_t);
  we_t = rotl32_S ((wb_t ^ w6_t ^ w0_t ^ we_t), 1u); SHA1_STEP_S (SHA1_F1, d, e, a, b, c, we_t);
  wf_t = rotl32_S ((wc_t ^ w7_t ^ w1_t ^ wf_t), 1u); SHA1_STEP_S (SHA1_F1, c, d, e, a, b, wf_t);
  w0_t = rotl32_S ((wd_t ^ w8_t ^ w2_t ^ w0_t), 1u); SHA1_STEP_S (SHA1_F1, b, c, d, e, a, w0_t);
  w1_t = rotl32_S ((we_t ^ w9_t ^ w3_t ^ w1_t), 1u); SHA1_STEP_S (SHA1_F1, a, b, c, d, e, w1_t);
  w2_t = rotl32_S ((wf_t ^ wa_t ^ w4_t ^ w2_t), 1u); SHA1_STEP_S (SHA1_F1, e, a, b, c, d, w2_t);
  w3_t = rotl32_S ((w0_t ^ wb_t ^ w5_t ^ w3_t), 1u); SHA1_STEP_S (SHA1_F1, d, e, a, b, c, w3_t);
  w4_t = rotl32_S ((w1_t ^ wc_t ^ w6_t ^ w4_t), 1u); SHA1_STEP_S (SHA1_F1, c, d, e, a, b, w4_t);
  w5_t = rotl32_S ((w2_t ^ wd_t ^ w7_t ^ w5_t), 1u); SHA1_STEP_S (SHA1_F1, b, c, d, e, a, w5_t);
  w6_t = rotl32_S ((w3_t ^ we_t ^ w8_t ^ w6_t), 1u); SHA1_STEP_S (SHA1_F1, a, b, c, d, e, w6_t);
  w7_t = rotl32_S ((w4_t ^ wf_t ^ w9_t ^ w7_t), 1u); SHA1_STEP_S (SHA1_F1, e, a, b, c, d, w7_t);
  w8_t = rotl32_S ((w5_t ^ w0_t ^ wa_t ^ w8_t), 1u); SHA1_STEP_S (SHA1_F1, d, e, a, b, c, w8_t);
  w9_t = rotl32_S ((w6_t ^ w1_t ^ wb_t ^ w9_t), 1u); SHA1_STEP_S (SHA1_F1, c, d, e, a, b, w9_t);
  wa_t = rotl32_S ((w7_t ^ w2_t ^ wc_t ^ wa_t), 1u); SHA1_STEP_S (SHA1_F1, b, c, d, e, a, wa_t);
  wb_t = rotl32_S ((w8_t ^ w3_t ^ wd_t ^ wb_t), 1u); SHA1_STEP_S (SHA1_F1, a, b, c, d, e, wb_t);
  wc_t = rotl32_S ((w9_t ^ w4_t ^ we_t ^ wc_t), 1u); SHA1_STEP_S (SHA1_F1, e, a, b, c, d, wc_t);
  wd_t = rotl32_S ((wa_t ^ w5_t ^ wf_t ^ wd_t), 1u); SHA1_STEP_S (SHA1_F1, d, e, a, b, c, wd_t);
  we_t = rotl32_S ((wb_t ^ w6_t ^ w0_t ^ we_t), 1u); SHA1_STEP_S (SHA1_F1, c, d, e, a, b, we_t);
  wf_t = rotl32_S ((wc_t ^ w7_t ^ w1_t ^ wf_t), 1u); SHA1_STEP_S (SHA1_F1, b, c, d, e, a, wf_t);

  digest[0] += a;
  digest[1] += b;
  digest[2] += c;
  digest[3] += d;
  digest[4] += e;
}

// add ipad/opad
void sha1_update_64 (sha1_ctx_t *ctx, u32 w0[4], u32 w1[4], u32 w2[4], u32 w3[4], const int len)
{
  const int pos = ctx->len & 63;

  ctx->len += len;

  if ((pos + len) < 64)
  {
    switch_buffer_by_offset_be_S (w0, w1, w2, w3, pos);

    ctx->w0[0] |= w0[0];
    ctx->w0[1] |= w0[1];
    ctx->w0[2] |= w0[2];
    ctx->w0[3] |= w0[3];
    ctx->w1[0] |= w1[0];
    ctx->w1[1] |= w1[1];
    ctx->w1[2] |= w1[2];
    ctx->w1[3] |= w1[3];
    ctx->w2[0] |= w2[0];
    ctx->w2[1] |= w2[1];
    ctx->w2[2] |= w2[2];
    ctx->w2[3] |= w2[3];
    ctx->w3[0] |= w3[0];
    ctx->w3[1] |= w3[1];
    ctx->w3[2] |= w3[2];
    ctx->w3[3] |= w3[3];
  }
  else
  {
    u32 c0[4] = { 0 };
    u32 c1[4] = { 0 };
    u32 c2[4] = { 0 };
    u32 c3[4] = { 0 };

    switch_buffer_by_offset_carry_be_S (w0, w1, w2, w3, c0, c1, c2, c3, pos);

    ctx->w0[0] |= w0[0];
    ctx->w0[1] |= w0[1];
    ctx->w0[2] |= w0[2];
    ctx->w0[3] |= w0[3];
    ctx->w1[0] |= w1[0];
    ctx->w1[1] |= w1[1];
    ctx->w1[2] |= w1[2];
    ctx->w1[3] |= w1[3];
    ctx->w2[0] |= w2[0];
    ctx->w2[1] |= w2[1];
    ctx->w2[2] |= w2[2];
    ctx->w2[3] |= w2[3];
    ctx->w3[0] |= w3[0];
    ctx->w3[1] |= w3[1];
    ctx->w3[2] |= w3[2];
    ctx->w3[3] |= w3[3];

    sha1_transform (ctx->w0, ctx->w1, ctx->w2, ctx->w3, ctx->h);

    ctx->w0[0] = c0[0];
    ctx->w0[1] = c0[1];
    ctx->w0[2] = c0[2];
    ctx->w0[3] = c0[3];
    ctx->w1[0] = c1[0];
    ctx->w1[1] = c1[1];
    ctx->w1[2] = c1[2];
    ctx->w1[3] = c1[3];
    ctx->w2[0] = c2[0];
    ctx->w2[1] = c2[1];
    ctx->w2[2] = c2[2];
    ctx->w2[3] = c2[3];
    ctx->w3[0] = c3[0];
    ctx->w3[1] = c3[1];
    ctx->w3[2] = c3[2];
    ctx->w3[3] = c3[3];
  }
}

void sha1_final (sha1_ctx_t *ctx)
{
  int pos = ctx->len & 63;

  append_0x80_4x4_S (ctx->w0, ctx->w1, ctx->w2, ctx->w3, pos ^ 3);

  if (pos >= 56)
  {
    sha1_transform (ctx->w0, ctx->w1, ctx->w2, ctx->w3, ctx->h);

    ctx->w0[0] = 0;
    ctx->w0[1] = 0;
    ctx->w0[2] = 0;
    ctx->w0[3] = 0;
    ctx->w1[0] = 0;
    ctx->w1[1] = 0;
    ctx->w1[2] = 0;
    ctx->w1[3] = 0;
    ctx->w2[0] = 0;
    ctx->w2[1] = 0;
    ctx->w2[2] = 0;
    ctx->w2[3] = 0;
    ctx->w3[0] = 0;
    ctx->w3[1] = 0;
    ctx->w3[2] = 0;
    ctx->w3[3] = 0;
  }

  ctx->w3[2] = 0;
  ctx->w3[3] = ctx->len * 8;

  sha1_transform (ctx->w0, ctx->w1, ctx->w2, ctx->w3, ctx->h);
}

// sha1_hmac
typedef struct sha1_hmac_ctx
{
  sha1_ctx_t ipad;
  sha1_ctx_t opad;

} sha1_hmac_ctx_t;

// w0, w1, w2, w3 is key
void sha1_hmac_init (sha1_hmac_ctx_t *ctx, const u32 w0[4], const u32 w1[4], const u32 w2[4], const u32 w3[4])
{
  u32 t0[4];
  u32 t1[4];
  u32 t2[4];
  u32 t3[4];

  // ipad
  // 2.XOR K+ with ipad to produce the 512-bit block Si
  t0[0] = w0[0] ^ 0x36363636;
  t0[1] = w0[1] ^ 0x36363636;
  t0[2] = w0[2] ^ 0x36363636;
  t0[3] = w0[3] ^ 0x36363636;
  t1[0] = w1[0] ^ 0x36363636;
  t1[1] = w1[1] ^ 0x36363636;
  t1[2] = w1[2] ^ 0x36363636;
  t1[3] = w1[3] ^ 0x36363636;
  t2[0] = w2[0] ^ 0x36363636;
  t2[1] = w2[1] ^ 0x36363636;
  t2[2] = w2[2] ^ 0x36363636;
  t2[3] = w2[3] ^ 0x36363636;
  t3[0] = w3[0] ^ 0x36363636;
  t3[1] = w3[1] ^ 0x36363636;
  t3[2] = w3[2] ^ 0x36363636;
  t3[3] = w3[3] ^ 0x36363636;

  sha1_init (&ctx->ipad);

  sha1_update_64 (&ctx->ipad, t0, t1, t2, t3, 64);

  // opad
// 5.XOR K+ with opad to produce the 512-bit block S0
  t0[0] = w0[0] ^ 0x5c5c5c5c;
  t0[1] = w0[1] ^ 0x5c5c5c5c;
  t0[2] = w0[2] ^ 0x5c5c5c5c;
  t0[3] = w0[3] ^ 0x5c5c5c5c;
  t1[0] = w1[0] ^ 0x5c5c5c5c;
  t1[1] = w1[1] ^ 0x5c5c5c5c;
  t1[2] = w1[2] ^ 0x5c5c5c5c;
  t1[3] = w1[3] ^ 0x5c5c5c5c;
  t2[0] = w2[0] ^ 0x5c5c5c5c;
  t2[1] = w2[1] ^ 0x5c5c5c5c;
  t2[2] = w2[2] ^ 0x5c5c5c5c;
  t2[3] = w2[3] ^ 0x5c5c5c5c;
  t3[0] = w3[0] ^ 0x5c5c5c5c;
  t3[1] = w3[1] ^ 0x5c5c5c5c;
  t3[2] = w3[2] ^ 0x5c5c5c5c;
  t3[3] = w3[3] ^ 0x5c5c5c5c;

  sha1_init (&ctx->opad);

  sha1_update_64 (&ctx->opad, t0, t1, t2, t3, 64);
}

// w0, w1, w2, w3 is message block
void sha1_hmac_update_64 (sha1_hmac_ctx_t *ctx, u32 w0[4], u32 w1[4], u32 w2[4], u32 w3[4], const int len)
{
  sha1_update_64 (&ctx->ipad, w0, w1, w2, w3, len);
}

void sha1_hmac_final (sha1_hmac_ctx_t *ctx)
{
  sha1_final (&ctx->ipad);

  u32 t0[4];
  u32 t1[4];
  u32 t2[4];
  u32 t3[4];

  t0[0] = ctx->ipad.h[0];
  t0[1] = ctx->ipad.h[1];
  t0[2] = ctx->ipad.h[2];
  t0[3] = ctx->ipad.h[3];
  t1[0] = ctx->ipad.h[4];
  t1[1] = 0;
  t1[2] = 0;
  t1[3] = 0;
  t2[0] = 0;
  t2[1] = 0;
  t2[2] = 0;
  t2[3] = 0;
  t3[0] = 0;
  t3[1] = 0;
  t3[2] = 0;
  t3[3] = 0;

  sha1_update_64 (&ctx->opad, t0, t1, t2, t3, 20);

  sha1_final (&ctx->opad);
}
#endif

int main()
{
  int i = 0;
  uint8_t key[20];
  unsigned char digest[20];

	for (i = 0; i < 20; i++)
		key[i] = i;
	int key_len = sizeof(key);
  char *message = "Sample message for keylen<blocklen";
	int message_len = strlen(message);

for (int i = 0; i < 10000000; i++)
  __hmac_sha1(key, key_len, message, message_len, digest);
  
	hmac_sha1();
	return 0;
}
