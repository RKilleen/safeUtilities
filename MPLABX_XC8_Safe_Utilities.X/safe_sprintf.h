/*
 * Functions to provide a safe compact implementation of stdio
 */
 
#ifndef SAFE_STDIO_H
#define SAFE_STDIO_H

#include "safe_types.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* Functions used to avoid including sprintf */
extern bool safe_sprintf1 (char_t str1[], const char_t format1[], const int16_t d11);
extern bool safe_sprintf2 (char_t str2[], const char_t format2[], const int16_t d12, const int16_t d22);
extern bool safe_sprintf3 (char_t str3[], const char_t format3[], const int16_t d13, const int16_t d23, const int16_t d33);
extern bool safe_sprintf4 (char_t str4[], const char_t format4[], const int16_t d14, const int16_t d24, const int16_t d34, const int16_t d44);

#ifdef __cplusplus
}
#endif

#endif /* SAFE_STDIO_H */
