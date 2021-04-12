
# 1 "safe_compress.c"

# 13 "C:\Program Files\Microchip\xc8\v2.32\pic\include\c90\stdint.h"
typedef signed char int8_t;

# 20
typedef signed int int16_t;

# 28
typedef __int24 int24_t;

# 36
typedef signed long int int32_t;

# 52
typedef unsigned char uint8_t;

# 58
typedef unsigned int uint16_t;

# 65
typedef __uint24 uint24_t;

# 72
typedef unsigned long int uint32_t;

# 88
typedef signed char int_least8_t;

# 96
typedef signed int int_least16_t;

# 109
typedef __int24 int_least24_t;

# 118
typedef signed long int int_least32_t;

# 136
typedef unsigned char uint_least8_t;

# 143
typedef unsigned int uint_least16_t;

# 154
typedef __uint24 uint_least24_t;

# 162
typedef unsigned long int uint_least32_t;

# 181
typedef signed char int_fast8_t;

# 188
typedef signed int int_fast16_t;

# 200
typedef __int24 int_fast24_t;

# 208
typedef signed long int int_fast32_t;

# 224
typedef unsigned char uint_fast8_t;

# 230
typedef unsigned int uint_fast16_t;

# 240
typedef __uint24 uint_fast24_t;

# 247
typedef unsigned long int uint_fast32_t;

# 268
typedef int32_t intmax_t;

# 282
typedef uint32_t uintmax_t;

# 289
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;

# 15 "C:\Program Files\Microchip\xc8\v2.32\pic\include\c90\stdbool.h"
typedef unsigned char bool;

# 7 "safe_types.h"
typedef char char_t;

# 10 "safe_compress.h"
extern bool safe_compress(uint8_t anArray1[], const char_t aString1[]);
extern bool safe_uncompress(char_t aString[], const uint8_t anArray[], const int16_t arraySize);

# 6 "safe_compress.c"
bool safe_compress(uint8_t anArray1[], const char_t aString1[]) {
bool compress_status;

if ( (anArray1 == (uint8_t*)0) || (aString1 == (char_t*)0) ) {
compress_status=0;
} else {
compress_status = 1;

}
return compress_status;
}

# 21
bool safe_uncompress(char_t aString[], const uint8_t anArray[], const int16_t arraySize) {
bool uncompress_status;

if ( (anArray == (uint8_t*)0) || (aString == (char_t*)0) ) {
uncompress_status=0;
} else {
uncompress_status=1;

}
return uncompress_status;
}

