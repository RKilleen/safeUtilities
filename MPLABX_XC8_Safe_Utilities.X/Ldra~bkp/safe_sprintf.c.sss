/*
 *    Safe Utilities project
 * ============================
 * File Path      : safe_sprintf.c
 * Author         : M.W.Richardson
 * Date           : 01/01/18
 * Copyright      : (c) 2018 Liverpool Data Research Associates
 */

#include "safe_sprintf.h"

/* Forward declarations */
static bool safe_int_to_dec (char_t string1[], const int16_t offset, const int16_t aValue);
static bool safe_sprintf (char_t string[], const char_t format[], const int16_t aCount, const int16_t d1, const int16_t d2, const int16_t d3, const int16_t d4);


/*
 * Routine to convert an integer to a decimal string
 * offset is the initial position in the string
 */
static bool safe_int_to_dec (char_t string1[], const int16_t offset, const int16_t aValue) {
  bool status1;

  if ( string1 == (char_t*)(0)) {
     status1 = false;
  } else {
     int16_t value=aValue;
     int16_t index=offset;
    /* handle negative numbers */
     bool neg = (value < 0);
     if (neg) {
       value = -value;
     }
     status1 = true;
 
     /* add a decimal digit to the output string */
     do {
       /* LDRA_EXCLUDE 584 S : <justification start> Remainder can not be negative. <justification end> */
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


/*
 * Routine to print a formatted string
 */
static bool safe_sprintf (char_t string[], const char_t format[], const int16_t aCount, const int16_t d1, const int16_t d2, const int16_t d3, const int16_t d4) {
  bool status2;
  int16_t ifmt=0;
  int16_t istr=0;

  if ((format == (char_t*)(0)) || (string == (char_t*)(0))) {
    status2 = false;
  } else {
    int16_t digits;
    int16_t digit[4];
    int16_t max = aCount;
    int16_t count = aCount;
    digit[0] = d1;
    digit[1] = d2;
    digit[2] = d3;
    digit[3] = d4;
    status2 = true;
    do {
      /* expected format (in regex notation) %[1-9][0-9]?[xdh] */
      /* else print char */
      if ((format[ifmt] == '%') && (count>0)) {
        int16_t width = 0;
        ifmt++;
        /* The next char must be in 1..9 */
        if ( ((int8_t)(format[ifmt]) >= (int8_t)'1') &&
             ((int8_t)(format[ifmt]) <= (int8_t)'9') ) {
          width = (int16_t)format[ifmt] - (int16_t)'0';
          ifmt++;
          /* The width might have two chars for a total range of 1-99 */
          if ( ((int8_t)(format[ifmt]) >= (int8_t)'0') &&
               ((int8_t)(format[ifmt]) <= (int8_t)'9') ) {
            width *= 10;
            width += (int16_t)format[ifmt] - (int16_t)'0';
            ifmt++;
          }
        } else {
          width = 1;
          digits = digit[max-count];
          /* 
           * if value to be printed is two or more digits and the format
           * pointer does not specify the number of digits then this code
           * will calculate the correct number of digits
           */
          while (digits > 9) {
            digits /= 10;
            width++;
          }
        }
        /* Advance the pointer beyond the number field */
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
          /* missing the number type */
          string[0] = 'E';
          string[1] = 'r';
          string[2] = 'r';
          string[3] = 'o';
          string[4] = 'r';
          istr=5;
          status2= false;
        }
      } else {
        /* if not '%' the token for a number format */
        /* output the current character */
        string[istr] = format[ifmt];
        istr++;
        ifmt++;
      }
    } while (status2 && (format[ifmt] != '\0'));
    string[istr] = '\0';
  }
  return status2;
}

/*
 * Routine to convert one argument to a formatted string 
 */
bool safe_sprintf1 (char_t str1[], const char_t format1[], const int16_t d11) {
  return (safe_sprintf(str1, format1, 1, d11, d11, d11, d11));
}

/*
 * Routine to convert two arguments to a formatted string 
 */
bool safe_sprintf2 (char_t str2[], const char_t format2[], const int16_t d12, const int16_t d22) {
  return (safe_sprintf(str2, format2, 2, d12, d22, d22, d22));
}

/*
 * Routine to convert three arguments to a formatted string 
 */
bool safe_sprintf3 (char_t str3[], const char_t format3[], const int16_t d13, const int16_t d23, const int16_t d33) {
  return (safe_sprintf(str3, format3, 3, d13, d23, d33, d33));
}

/*
 * Routine to convert four arguments to a formatted string 
 */
bool safe_sprintf4 (char_t str4[], const char_t format4[], const int16_t d14, const int16_t d24, const int16_t d34, const int16_t d44) {
  return ( safe_sprintf(str4, format4, 4, d14, d24, d34, d44) );
}
