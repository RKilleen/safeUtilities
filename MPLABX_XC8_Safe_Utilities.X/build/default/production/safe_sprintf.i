
# 1 "safe_sprintf.c"

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

# 15 "safe_sprintf.h"
extern bool safe_sprintf1 (char_t str1[], const char_t format1[], const int16_t d11);
extern bool safe_sprintf2 (char_t str2[], const char_t format2[], const int16_t d12, const int16_t d22);
extern bool safe_sprintf3 (char_t str3[], const char_t format3[], const int16_t d13, const int16_t d23, const int16_t d33);
extern bool safe_sprintf4 (char_t str4[], const char_t format4[], const int16_t d14, const int16_t d24, const int16_t d34, const int16_t d44);

# 13 "safe_sprintf.c"
static bool safe_int_to_dec (char_t string1[], const int16_t offset, const int16_t aValue);
static bool safe_sprintf (char_t string[], const char_t format[], const int16_t aCount, const int16_t d1, const int16_t d2, const int16_t d3, const int16_t d4);

# 21
static bool safe_int_to_dec (char_t string1[], const int16_t offset, const int16_t aValue) {
bool status1;

if ( string1 == (char_t*)(0)) {
status1 = 0;
} else {
int16_t value=aValue;
int16_t index=offset;

bool neg = (value < 0);
if (neg) {
value = -value;
}
status1 = 1;


do {

int16_t remainder = (value % 10);
remainder += (int16_t)'0';
--index;
string1[index] = (char_t)remainder;
value /= 10;
} while (value>0);

if (neg) {
--index;
string1[index] = '-';
}
}
return status1;
}

# 58
static bool safe_sprintf (char_t string[], const char_t format[], const int16_t aCount, const int16_t d1, const int16_t d2, const int16_t d3, const int16_t d4) {
bool status2;
int16_t ifmt=0;
int16_t istr=0;

if ((format == (char_t*)(0)) || (string == (char_t*)(0))) {
status2 = 0;
} else {
int16_t digits;
int16_t digit[4];
int16_t max = aCount;
int16_t count = aCount;
digit[0] = d1;
digit[1] = d2;
digit[2] = d3;
digit[3] = d4;
status2 = 1;
do {


if ((format[ifmt] == '%') && (count>0)) {
int16_t width = 0;
ifmt++;

if ( ((int8_t)(format[ifmt]) >= (int8_t)'1') &&
((int8_t)(format[ifmt]) <= (int8_t)'9') ) {
width = (int16_t)format[ifmt] - (int16_t)'0';
ifmt++;

if ( ((int8_t)(format[ifmt]) >= (int8_t)'0') &&
((int8_t)(format[ifmt]) <= (int8_t)'9') ) {
width *= 10;
width += (int16_t)format[ifmt] - (int16_t)'0';
ifmt++;
}
} else {
width = 1;
digits = digit[max-count];

# 101
while (digits > 9) {
digits /= 10;
width++;
}
}

while (width!=0) {
string[istr] = ' ';
istr++;
--width;
}

if (format[ifmt] == 'd') {
ifmt++;
status2 = safe_int_to_dec((char_t*)&string[0], istr, digit[max-count]);
--count;
} else {

string[0] = 'E';
string[1] = 'r';
string[2] = 'r';
string[3] = 'o';
string[4] = 'r';
istr=5;
status2= 0;
}
} else {


string[istr] = format[ifmt];
istr++;
ifmt++;
}
} while (status2 && (format[ifmt] != '\0'));
string[istr] = '\0';
}
return status2;
}

# 143
bool safe_sprintf1 (char_t str1[], const char_t format1[], const int16_t d11) {
return (safe_sprintf(str1, format1, 1, d11, d11, d11, d11));
}

# 150
bool safe_sprintf2 (char_t str2[], const char_t format2[], const int16_t d12, const int16_t d22) {
return (safe_sprintf(str2, format2, 2, d12, d22, d22, d22));
}

# 157
bool safe_sprintf3 (char_t str3[], const char_t format3[], const int16_t d13, const int16_t d23, const int16_t d33) {
return (safe_sprintf(str3, format3, 3, d13, d23, d33, d33));
}

# 164
bool safe_sprintf4 (char_t str4[], const char_t format4[], const int16_t d14, const int16_t d24, const int16_t d34, const int16_t d44) {
return ( safe_sprintf(str4, format4, 4, d14, d24, d34, d44) );
}
