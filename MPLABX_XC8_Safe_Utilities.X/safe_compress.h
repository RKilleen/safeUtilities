#ifndef SAFE_COMPRESS_H
#define SAFE_COMPRESS_H

#include "safe_types.h"

#ifdef __cplusplus
extern "C" {
#endif

extern bool safe_compress(uint8_t anArray1[], const char_t aString1[]);
extern bool safe_uncompress(char_t aString[], const uint8_t anArray[], const int16_t arraySize);

#ifdef __cplusplus
}
#endif

#endif /* SAFE_COMPRESS_H */
