#ifndef HMAC_H
#define HMAC_H

#include "sha1.h"
GLOBAL void __hmac_sha1(unsigned char *key, int len, const unsigned char *message, int message_len, unsigned char *digest);

#endif
