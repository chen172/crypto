/*********************************************************************
* Filename:   sha1.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding SHA1 implementation.
*********************************************************************/

#ifndef SHA1_H
#define SHA1_H

#if __CUDACC__
#define DEVICE __device__
#define GLOBAL __global__
#else
#define DEVICE
#define GLOBAL
#endif


/*************************** HEADER FILES ***************************/
#include <stddef.h>

/****************************** MACROS ******************************/
#define SHA1_BLOCK_SIZE 20              // SHA1 outputs a 20 byte digest

/**************************** DATA TYPES ****************************/
typedef unsigned char BYTE;             // 8-bit byte
typedef unsigned int  WORD;             // 32-bit word, change to "long" for 16-bit machines

typedef struct {
	BYTE data[64];// 数据
	WORD datalen; //数据的长度
	unsigned long long bitlen; // bit的个数
	WORD state[5]; // 状态
	WORD k[4];
} SHA1_CTX;

/*********************** FUNCTION DECLARATIONS **********************/
DEVICE void sha1_init(SHA1_CTX *ctx);
DEVICE void sha1_update(SHA1_CTX *ctx, const BYTE data[], size_t len);
DEVICE void sha1_final(SHA1_CTX *ctx, BYTE hash[]);

#endif   // SHA1_H
