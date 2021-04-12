#include "C:\LDRA_Toolsuite\Compiler_spec\Microchip\xc8\ldra_port_pragmas.h"
#include <xc.h>
#include "safe_sprintf.h"
#include "safe_string.h"
#include "safe_compress.h"


int16_t main ( void ) {

   char_t my_string[64];
   const char_t msg[] = "The quick brown fox";
   int16_t len_msg = safe_string_length(msg);
   uint8_t comp_msg[64]={0};
   char_t exp_msg[64];
   int16_t len_comp_msg = (len_msg * 7) / 8;
   
    my_string[0] = 0;
   (void)safe_sprintf4(&my_string[0], "%8d %8d %8d %8d", 12, 34, 45, 56);
   (void)safe_sprintf3(&my_string[0], "%8d %8d %8d", 42, 56, 78);
   (void)safe_sprintf2(&my_string[0], "%8d %8d", 1, 1024);
   (void)safe_sprintf1(&my_string[0], "%d", 987654321);
   (void)safe_sprintf1(&my_string[0], "%8d", -1234567);
   (void)safe_sprintf1(&my_string[0], "%6d", -12345);
   (void)safe_sprintf1(&my_string[0], "%2d", -1);
   (void)safe_sprintf1(&my_string[0], "%4x", 0xabcd);
   (void)safe_sprintf1(&my_string[0], "%p", 1);
   
   (void)safe_compress(comp_msg, msg);
   (void)safe_uncompress(exp_msg, comp_msg, len_comp_msg); 
   exp_msg[len_msg-1] = '\0'; 

   (void)safe_string_compare(msg, exp_msg,len_comp_msg);
   return 0;
}
