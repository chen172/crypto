#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
// use CBC mode improve LRC
#define HASH_CODE_LEN 16
// plaintext lens
#define LEN_LEN_TEXT 5
// a longtitudinal redundancy check(LRC) is an error-detection method for
// determining the correctness of transmitted and stored data.

// LRC verifies the accuracy of stored and transmitted data using parity bits.
// It is a redundancy check applied to a parallel group of bit streams. The data
// to be transmitted is divided into transmission blocks into which additional
// check data is inserted.
int main()
{
        char hash_code[HASH_CODE_LEN];

        char *text = "this is the text for test and for test and for test";
        int len_text = strlen(text);
        // get the padding plaintext length
        char *padding_len_text = NULL;
        padding_len_text = (char*)malloc(sizeof(char)*LEN_LEN_TEXT);
        sprintf(padding_len_text, "%05d", len_text);
        //printf("%s\n", padding_len_text);
        int len_zeros = HASH_CODE_LEN-((len_text + LEN_LEN_TEXT) % HASH_CODE_LEN);
        //printf("%d\n", len_zeros);
        int len_message = len_text + LEN_LEN_TEXT + len_zeros;
        //printf("%d\n", len_message);
        int block_num = (len_message) / HASH_CODE_LEN;

        char *padding_text = NULL;

        padding_text = (char*)malloc(sizeof(char)*len_message);
        // add the plaintext
        bcopy(text, padding_text, len_text);
        // add padding zeros
        memset(padding_text+len_text, '0', len_zeros);
        // add padding plaintext length
        bcopy(padding_len_text, padding_text+len_text+len_zeros, LEN_LEN_TEXT);
        // debug code
#if 0
        for (int k = 0; k < len_message; k++)
                printf("%c", padding_text[k]);
        printf("\n");
#endif
        // block operation
        int i = 0, j = 0, k = 0;
        for (i = 0; i < HASH_CODE_LEN; i++)
                hash_code[i] = 0x00;
        for (j = 0; j < block_num; j++) {
                // Rotate the current hash value to the left by one bit
                for (k = 0; k < (HASH_CODE_LEN-1); k++) {
                        hash_code[k] = (hash_code[k] << 1);
                        hash_code[k] = hash_code[k] | ((hash_code[k+1] >> 7) & 0x01);
                }
                hash_code[HASH_CODE_LEN-1] = hash_code[HASH_CODE_LEN-1] << 1;
                // XOR the block into the hash value
                for (k = 0; k < HASH_CODE_LEN; k++)
                        hash_code[k] = hash_code[k] ^ (padding_text[k+HASH_CODE_LEN*j]);
                        //hash_code[i] = (padding_text[i+j]) ^ (padding_text[i+HASH_CODE_LEN+j-1]);
        }

        for (i = 0; i < HASH_CODE_LEN; i++)
                printf("%02x", hash_code[i]);
        printf("\n");
        free(padding_len_text);
        free(padding_text);
        return 0;
}
