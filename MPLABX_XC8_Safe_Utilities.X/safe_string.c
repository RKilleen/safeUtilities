#include "safe_string.h"

/*
 * returns the length of the string
 */
int16_t safe_string_length ( const char_t aString[] ) {
   int16_t n=0;
   if ( aString != (char_t*)0 ) {
     while (aString[n] != '\0') {
        n++;
     }
   }
   return n;
}


/*
 * Returns true if strings are equal
 * Compares strings until either the terminator is found or a max number of characters
 */
bool safe_string_compare ( const char_t aString1[], const char_t aString2[], const int16_t max_chars ) {
  bool ret=true;

  if ( (aString1 == (char_t*)0) || (aString2 == (char_t*)0) ) {
    ret=false;
  } else {
    bool loop=true;
    int16_t i=0;
    /* LDRA_EXCLUDE 28 D : <justification start> Loop is not infinite. <justification end> */
    while ( loop ) {
      if ( i >= max_chars ) {
        loop=false;
      } else {
        if (aString1[i] != aString2[i] ) {
          loop=false;
          ret=false;
       } else {
          if ( aString1[i] == '\0' ) {
             loop=false;
          }
       }
     }
     i++;
    }
  }
  return ret;
}

