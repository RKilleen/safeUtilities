#ifndef SAFE_STRING_H_
#define SAFE_STRING_H_

#include "safe_types.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int16_t safe_string_length ( const char_t aString[] );
extern bool safe_string_compare ( const char_t aString1[], const char_t aString2[], const int16_t max_chars );

#ifdef __cplusplus
}
#endif

#endif /* SAFE_STRING_H_ */
