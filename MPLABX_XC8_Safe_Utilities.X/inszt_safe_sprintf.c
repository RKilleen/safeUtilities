/*
C TESTBED VERSION  : 9.8.3
FILE UNDER TEST  : "C:\LDRA_Workarea\Examples\Tlps\Microchip\MPLABX_XC8_Workspace\MPLABX_XC8_Safe_Utilities.X\safe_spri
DATE OF ANALYSIS : Thu Apr 08 16:39:50 2021
*/
/*
 * Safe Utilities project
 * ============================
 * File Path : safe_sprintf.c
 * Author : M.W.Richardson
 * Date : 01/01/18
 * Copyright : (c) 2018 Liverpool Data Research Associates
 */
#define QQQdialect MPLABX                                                                          
#undef QQQ146
#undef QQQ148
#undef QQQbndchk
#undef QQQ294
#undef QQQEMBEDDEDICE
 /* Note: for BITMAP execution histories QQQthreaded is not defined */
#undef QQQthreaded 
#undef QQQdo178b
#undef QQQfixbra
#define QQQswitch3
#undef QQQternary
#undef QQQswitch
#undef QQQmacrof
#undef QQQMULTIPROCESSEXH
#undef QQFLUSH
#undef QQNEWBS
#define qqqMaxBranchDepth     20
#define QQQstructbitmap
 static int qqqqbmselwidth =            8 ;
 static int zzfileid =      6;
#define QQQnumfil        5
#undef QQQALGONE
#undef QQQVCLFLG
#undef QQQFORKFL
#undef QQQIADDRF
#undef QQQRTI
#undef QQQPERFA
#undef QQQADRMOD
#undef QQQDCAPFL
#undef QQQTEMPLATEONLY
#define QQQNOATEXIT
#define QQQUPLOADATEND
#define QQQNOSTDIO
#undef QQQASHLINGVITRA
#define QQQBITMAP 
#define qqqbitmapint int
#undef QQQBITMAPMCDC 
#undef QQQTIC2XSERIALIO
#undef QQQTIC2XFLASH
#undef QQQCOMPRESSED_EXH
#undef QQQMAINFL
#define QQQSINGLEFILE
#define QQQFILEID
#define QQQseparate
extern int QQQindicator;
static int QQQfirstmcdc=1;
#define safe_sprintf_6zzopen                                                                                  zzopen
 extern int safe_sprintf_6zzopen                                                                                ;
//#define safe_sprintf_6zqqzqz1                                                                                 zqqzqz1
#define QQQLDRA_PORT 
                                                                                                                                                                                                                                                                    
/***************** BEGIN INSTRUMENTATION OPTIONS CHECKS ******************/                                                                                                                                                                                         
#if defined(QQQTEMPLATEONLY)                                                                                                                                                                                                                                        
#error "Instrumentation option: 'Use I/O Template (for embedded systems)' is not currently supported with this TLP."                                                                                                                                                
#endif                                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                    
#if defined(QQQCOMPRESSED_EXH) && !defined(QQQFIXEDSIZE)                                                                                                                                                                                                            
#error "Instrumentation option: 'Compress Execution History: Hitmap (Dynamic Alloc)' is not currently supported with this TLP."                                                                                                                                     
#endif                                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                    
#if defined(QQQCOMPRESSED_EXH) && defined(QQQFIXEDSIZE)                                                                                                                                                                                                             
#error "Instrumentation option: 'Compress Execution History: Hitmap (Fixed Alloc)' is not currently supported with this TLP."                                                                                                                                       
#endif                                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                    
#if defined(QQQBITMAP) && defined(QQQBITMAPMCDC) && !defined(QQQstructbitmap)                                                                                                                                                                                       
#error "Instrumentation option: 'Compress Execution History: Bitmap (Bitmap MC/DC)' is not currently supported with this TLP."                                                                                                                                      
#endif                                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                    
#ifndef QQQSINGLEFILE                                                                                                                                                                                                                                               
#error "cvals.dat flag 143 must be selected."                                                                                                                                                                                                                       
#endif                                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                    
#ifdef QQQACCBMAPEXH                                                                                                                                                                                                                                                
#error "Instrumentation option: 'Acummulate Bitmap Execution Histories (Host/Host)' is not currently supported with this TLP."                                                                                                                                      
#endif                                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                    
#ifdef QQQthreaded                                                                                                                                                                                                                                                  
#error "Instrumentation option: 'Thread ID in Execution History' is not currently supported with this TLP."                                                                                                                                                         
#endif                                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                    
#ifdef QQQIADDRF                                                                                                                                                                                                                                                    
#error "Instrumentation option: 'Execution History to Memory Address' is not currently supported with this TLP."                                                                                                                                                    
#endif                                                                                                                                                                                                                                                              
/****************** END INSTRUMENTATION OPTIONS CHECKS *******************/                                                                                                                                                                                         
                                                                                                                                                                                                                                                                    
#ifndef QQQLDRA_PORT                                                                                                                                                                                                                                                
#error "Only LDRA_PORT is supported with this TLP."                                                                                                                                                                                                                 
#define FILEPOINT FILE * f,                                                                                                                                                                                                                                         
#else /* QQQLDRA_PORT */                                                                                                                                                                                                                                            
#define FILEPOINT                                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                    
/*************************** BEGIN LDRA_PORT *****************************/                                                                                                                                                                                         
#ifdef QQQ_SHLAYOUT                                                                                                                                                                                                                                                 
static int tbrun_mode=1;                                                                                                                                                                                                                                            
#else                                                                                                                                                                                                                                                               
static int tbrun_mode=0;                                                                                                                                                                                                                                            
#endif /* QQQ_SHLAYOUT */                                                                                                                                                                                                                                           
#include "C:\LDRA_Toolsuite\Compiler_spec\Microchip\xc8\ldra_port.h"                                                                                                                                                                                                
#include "C:\LDRA_Toolsuite\Compiler_spec\Microchip\xc8\ldra_port_common.h"                                                                                                                                                                                         
#ifndef QQQ_SHLAYOUT                                                                                                                                                                                                                                                
#ifdef QQQMAINFL                                                                                                                                                                                                                                                    
#include "C:\LDRA_Toolsuite\Compiler_spec\Microchip\xc8\ldra_port.c"                                                                                                                                                                                                
#include "C:\LDRA_Toolsuite\Compiler_spec\Microchip\xc8\ldra_port_common.c"                                                                                                                                                                                         
#endif /* QQQMAINFL */                                                                                                                                                                                                                                              
#endif /* QQQ_SHLAYOUT */                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                    
#if 0                                                                                                                                                                                                                                                               
#if defined(QQQstructbitmap)                                                                                                                                                                                                                                        
#error "Instrumentation option: 'Shared Memory' can currently only be used with Bitmap(Hitmap MC/DC) instrumentation."                                                                                                                                              
#endif                                                                                                                                                                                                                                                              
#define VAR_BITMAPARR static unsigned int* bitmaparr;                                                                                                                                                                                                               
#define VAR_AQQQMCDCSTORE static int* aqqqmcdcstore;                                                                                                                                                                                                                
#define VAR_AQQQMCDCSTR static int* aqqqmcdcstr;                                                                                                                                                                                                                    
#define VAR_AQQQSTR static int* aqqqstr;                                                                                                                                                                                                                            
#else                                                                                                                                                                                                                                                               
#define VAR_BITMAPARR static unsigned int bitmaparr[(qqqbranches/8)+1];                                                                                                                                                                                             
#define VAR_AQQQMCDCSTORE static int aqqqmcdcstore[QQQMAXMCDCSIZE];                                                                                                                                                                                                 
#define VAR_AQQQMCDCSTR static int aqqqmcdcstr[qqqbranches1];                                                                                                                                                                                                       
#define VAR_AQQQSTR static int aqqqstr[qqqbranches1];                                                                                                                                                                                                               
#endif /* 0 */                                                                                                                                                                                                                                                      
                                                                                                                                                                                                                                                                    
/* Forward Declaration */                                                                                                                                                                                                                                           
static void init_shared_memory(void);                                                                                                                                                                                                                               
/**************************** END LDRA_PORT *****************************/                                                                                                                                                                                          
#endif /* QQQLDRA_PORT */                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                    
#ifndef QQQnumfil                                                                                                                                                                                                                                                   
#define QQQnumfil 40  /* default setting */                                                                                                                                                                                                                         
#endif /* QQQnumfil */                                                                                                                                                                                                                                              
#if defined(QQQstructbitmap) && defined(QQQSINGLEFILE)                                                                                                                                                                                                              
#ifndef LDRA_VOID_FUNC                                                                                                                                                                                                                                              
#define LDRA_VOID_FUNC                                                                                                                                                                                                                                              
  typedef void(*ldra_void_function)();                                                                                                                                                                                                                              
#endif                                                                                                                                                                                                                                                              
#if defined(QQQMAINFL)                                                                                                                                                                                                                                              
  int qqqshell_upload = 0;                                                                                                                                                                                                                                          
  int QQQfcn_ptr_num = 0;                                                                                                                                                                                                                                           
  static int qqqisinitialised = 0;                                                                                                                                                                                                                                  
  ldra_void_function qqqaccumupload[QQQnumfil];                                                                                                                                                                                                                     
  ldra_void_function qqqaccumreset[QQQnumfil];                                                                                                                                                                                                                      
  void qqqtotalupload(void);                                                                                                                                                                                                                                        
  void qqqtotalreset(void);                                                                                                                                                                                                                                         
  void qqpopulate_array_fcn_ptrQQ(int x, ldra_void_function y, ldra_void_function z) {                                                                                                                                                                              
    qqqaccumupload[x]=y;                                                                                                                                                                                                                                            
    qqqaccumreset[x]=z;                                                                                                                                                                                                                                             
    QQQfcn_ptr_num++;                                                                                                                                                                                                                                               
  }                                                                                                                                                                                                                                                                 
#else /* (QQQMAINFL) */                                                                                                                                                                                                                                             
  extern int QQQfcn_ptr_num;                                                                                                                                                                                                                                        
  extern ldra_void_function qqqaccumupload[QQQnumfil];                                                                                                                                                                                                              
  extern void qqpopulate_array_fcn_ptrQQ(int x, ldra_void_function y, ldra_void_function z);                                                                                                                                                                        
  static int qqqstructzzopen = 0;                                                                                                                                                                                                                                   
#endif /* defined(QQQMAINFL) */                                                                                                                                                                                                                                     
#endif /* defined(QQQstructbitmap) && defined(QQQSINGLEFILE) */                                                                                                                                                                                                     
#if !defined(QQQSUPPRESS_UNDEF)                                                                                                                                                                                                                                     
#undef ldra_fprintf                                                                                                                                                                                                                                                 
#undef ldra_sscanf                                                                                                                                                                                                                                                  
#endif /* !defined(QQQSUPPRESS_UNDEF) */                                                                                                                                                                                                                            
#undef QQQHITMAP_STORAGE                                                                                                                                                                                                                                            
#undef qqnull_params                                                                                                                                                                                                                                                
#define qqnull_params void                                                                                                                                                                                                                                          
#define QQQ_PROTOTYPE_DEF                                                                                                                                                                                                                                           
  /* Conventional Instrumentation */                                                                                                                                                                                                                                
#undef QQ_ANSI_PROTOTYPE                                                                                                                                                                                                                                            
#ifdef __STDC__                                                                                                                                                                                                                                                     
#define QQ_ANSI_PROTOTYPE 1                                                                                                                                                                                                                                         
#else /* __STDC__ */                                                                                                                                                                                                                                                
#endif /* __STDC__ */                                                                                                                                                                                                                                               
  static unsigned char qqqzzglobflag = 0;                                                                                                                                                                                                                           
  static struct bitmapstruct_t                                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
#define ELEMENT(N) qqqbitmapint element##N;                                                                                                                                                                                                                         
#define LASTELEMENT                                                                                                                                                                                                                                                 
#include "safe_sprintf_6zbelem.def"                                                                                                                                                                                                                                 
#undef ELEMENT                                                                                                                                                                                                                                                      
#undef LASTELEMENT                                                                                                                                                                                                                                                  
  } bitmapstruct = {                                                                                                                                                                                                                                                
#define ELEMENT(N) 0,                                                                                                                                                                                                                                               
#undef LASTELEMENT                                                                                                                                                                                                                                                  
#include "safe_sprintf_6zbelem.def"                                                                                                                                                                                                                                 
#undef ELEMENT                                                                                                                                                                                                                                                      
  0};                                                                                                                                                                                                                                                               
  static void qqoutput(FILEPOINT char* s,int i);                                                                                                                                                                                                                    
  static void qqoutput2(FILEPOINT char* s, int i, int j);                                                                                                                                                                                                           
  static void qqoutput3(FILEPOINT char* s, int i, int j, int k);                                                                                                                                                                                                    
  static void qqoutput4(FILEPOINT char* s, int i, int j, int k, int l);                                                                                                                                                                                             
  static void qqoutput0(FILEPOINT char* s);                                                                                                                                                                                                                         
  static int safe_sprintf_6zqqzqz(qqnull_params);                                                                                                                                                                                                                   
  static int safe_sprintf_6zqqzqz1(qqnull_params);                                                                                                                                                                                                                  
  static int safe_sprintf_6zqendz (int qqqi);                                                                                                                                                                                                                       
  static int safe_sprintf_6zqzqzq (int qqqi);                                                                                                                                                                                                                       
  static void qqqupload(qqnull_params);                                                                                                                                                                                                                             
  static void qqqbitmapreset(qqnull_params);                                                                                                                                                                                                                        
/* ------------------------------ END OF TESTBED PROTOTYPES -------------------------------- */                                                                                                                                                                     
                                                                                                                                                                                                                                                                    
/* OPEN FILE C:\LDRA_Workarea\Examples\Tlps\Microchip\MPLABX_XC8_Workspace\MPLABX_XC8_Safe_Utilities.X\safe_sprintf.h */
/*
 * Functions to provide a safe compact implementation of stdio
 */
#ifndef SAFE_STDIO_H
#define SAFE_STDIO_H
/* OPEN FILE C:\LDRA_Workarea\Examples\Tlps\Microchip\MPLABX_XC8_Workspace\MPLABX_XC8_Safe_Utilities.X\safe_types.h */
#ifndef SAFE_TYPES_H
#define SAFE_TYPES_H
#include <stdint.h>
#include <stdbool.h>
 
typedef
char
  char_t ;
       /* SAFE_TYPES_H */
 
#endif /*00 C:\LDRA_Workarea\Examples\Tlps\Microchip\MPLABX_XC8_Workspace\MPLABX_XC8_Safe_Utilities.X\safe_types.h*/
/*   CLOSE_FILE Include File */
 
/* Functions used to avoid including sprintf */
 
extern bool
  safe_sprintf1 (
  char_t str1 [] ,
  const char_t format1 [] ,
  const int16_t d11 ) ;
 
extern bool
  safe_sprintf2 (
  char_t str2 [] ,
  const char_t format2 [] ,
  const int16_t d12 ,
  const int16_t d22 ) ;
 
extern bool
  safe_sprintf3 (
  char_t str3 [] ,
  const char_t format3 [] ,
  const int16_t d13 ,
  const int16_t d23 ,
  const int16_t d33 ) ;
 
extern bool
  safe_sprintf4 (
  char_t str4 [] ,
  const char_t format4 [] ,
  const int16_t d14 ,
  const int16_t d24 ,
  const int16_t d34 ,
  const int16_t d44 ) ;
       /* SAFE_STDIO_H */
 
#endif /*00 C:\LDRA_Workarea\Examples\Tlps\Microchip\MPLABX_XC8_Workspace\MPLABX_XC8_Safe_Utilities.X\safe_sprintf.h*/
/*   CLOSE_FILE Include File */
 
/* Forward declarations */
 
static bool
  safe_int_to_dec (
  char_t string1 [] ,
  const int16_t offset ,
  const int16_t aValue ) ;
 
static bool
  safe_sprintf (
  char_t string [] ,
  const char_t format [] ,
  const int16_t aCount ,
  const int16_t d1 ,
  const int16_t d2 ,
  const int16_t d3 ,
  const int16_t d4 ) ;
/*
 * Routine to convert an integer to a decimal string
 * offset is the initial position in the string
 */
 
static bool
  safe_int_to_dec (
  char_t string1 [] ,
  const int16_t offset ,
  const int16_t aValue )
  {
 int izzqqzz=((int)(bitmapstruct.element0 |= (1 <<  0))); /* 37 */
    bool
      status1 ;
    if
      (
      string1 == ( char_t * ) ( 0 )
      )
 {
  ((int)(bitmapstruct.element0 |= (1 <<  1))); /* 1 */
      {
        status1 = false ;
      }
  ((int)(bitmapstruct.element0 |= (1 <<  2))); /* 3 */
 }
    else
  { 
  ((int)(bitmapstruct.element0 |= (1 <<  3))); /* 2 */
      {
        int16_t
          value = aValue ;
        int16_t
          index = offset ;
          /* handle negative numbers */
        bool
          neg =
          ( value < 0 ) ;
        if
          (
          neg
          )
 {
  ((int)(bitmapstruct.element0 |= (1 <<  4))); /* 1 */
          {
            value = - value ;
          }
  } else ((int)(bitmapstruct.element0 |= (1 <<  5))); /* 4 */
        status1 = true ;
        /* add a decimal digit to the output string */
        do
          {
          /* LDRA_EXCLUDE 584 S : <justification start> Remainder can not be negative. <justification end> */
            int16_t
              remainder =
              ( value %
              10 ) ;
            remainder += ( int16_t ) '0' ;
            -- index ;
            string1[ index ] = ( char_t ) remainder ;
            value /=
            10 ;
          }
        while
 (  /* 50 */
          (
          value > 0
  ) && (((int)(bitmapstruct.element0 |= (1 <<  6))),1) /* 24 */
    || !(((int)(bitmapstruct.element0 |= (1 <<  7))),1) /* 24A */
          ) ;
        if
          (
          neg
          )
 {
  ((int)(bitmapstruct.element1 |= (1 <<  0))); /* 1 */
          {
            -- index ;
            string1[ index ] = '-' ;
          }
  } else ((int)(bitmapstruct.element1 |= (1 <<  1))); /* 4 */
      }
 }
  ((int)(bitmapstruct.element1 |= (1 <<  2))); /* 30 */
    safe_sprintf_6zqendz                                                                                 (      11 ) ; /* 30 */  
    return
    status1 ;
  }
/*
 * Routine to print a formatted string
 */
 
static bool
  safe_sprintf (
  char_t string [] ,
  const char_t format [] ,
  const int16_t aCount ,
  const int16_t d1 ,
  const int16_t d2 ,
  const int16_t d3 ,
  const int16_t d4 )
  {
 int izzqqzz=((int)(bitmapstruct.element1 |= (1 <<  3))); /* 37 */
    bool
      status2 ;
    int16_t
      ifmt = 0 ;
    int16_t
      istr = 0 ;
    if
 (  /* 50 */
      (
      
  (     /*  51 */ 
      (
      format == ( char_t * ) ( 0 )
      )
  ? (bitmapstruct.element1 |= (1 <<  5 ), 1)
  : (bitmapstruct.element1 |= (1 <<  4 ), 0) ) /* 54 */
      ||
      ( string == ( char_t * ) ( 0 ) )
      )
  ) /* 1 */
 {
  ((int)(bitmapstruct.element1 |= (1 <<  6))); /* 1 */
      {
        status2 = false ;
      }
  ((int)(bitmapstruct.element1 |= (1 <<  7))); /* 3 */
 }
    else
  { 
  ((int)(bitmapstruct.element2 |= (1 <<  0))); /* 2 */
      {
        int16_t
          digits ;
        int16_t digit [ 4 ] ;
        int16_t
          max = aCount ;
        int16_t
          count = aCount ;
        digit[ 0 ] = d1 ;
        digit[ 1 ] = d2 ;
        digit[ 2 ] = d3 ;
        digit[ 3 ] = d4 ;
        status2 = true ;
        do
          {
      /* expected format (in regex notation) %[1-9][0-9]?[xdh] */
      /* else print char */
            if
 (  /* 50 */
              (
              
  (     /*  52 */ 
              (
              format[ ifmt ] == '%'
              )
  ? (bitmapstruct.element2 |= (1 <<  1 ), 1)
  : (bitmapstruct.element2 |= (1 <<  2 ), 0) ) /* 54 */
              &&
              ( count > 0 )
              )
  ) /* 1 */
 {
  ((int)(bitmapstruct.element2 |= (1 <<  3))); /* 1 */
              {
                int16_t
                  width = 0 ;
                ifmt ++ ;
                /* The next char must be in 1..9 */
                if
 (  /* 50 */
                  (
                  
  (     /*  52 */ 
                  (
                  ( int8_t ) ( format[ ifmt ] ) >= ( int8_t ) '1'
                  )
  ? (bitmapstruct.element2 |= (1 <<  4 ), 1)
  : (bitmapstruct.element2 |= (1 <<  5 ), 0) ) /* 54 */
                  &&
                  (
                  ( int8_t ) ( format[ ifmt ] ) <= ( int8_t ) '9' )
                  )
  ) /* 1 */
 {
  ((int)(bitmapstruct.element2 |= (1 <<  6))); /* 1 */
                  {
                    width = ( int16_t ) format[ ifmt ] - ( int16_t ) '0' ;
                    ifmt ++ ;
                    /* The width might have two chars for a total range of 1-99 */
                    if
 (  /* 50 */
                      (
                      
  (     /*  52 */ 
                      (
                      ( int8_t ) ( format[ ifmt ] ) >= ( int8_t ) '0'
                      )
  ? (bitmapstruct.element2 |= (1 <<  7 ), 1)
  : (bitmapstruct.element3 |= (1 <<  0 ), 0) ) /* 54 */
                      &&
                      (
                      ( int8_t ) ( format[ ifmt ] ) <= ( int8_t ) '9' )
                      )
  ) /* 1 */
 {
  ((int)(bitmapstruct.element3 |= (1 <<  1))); /* 1 */
                      {
                        width *= 10 ;
                        width += ( int16_t ) format[ ifmt ] - ( int16_t ) '0' ;
                        ifmt ++ ;
                      }
  } else ((int)(bitmapstruct.element3 |= (1 <<  2))); /* 4 */
                  }
  ((int)(bitmapstruct.element3 |= (1 <<  3))); /* 3 */
 }
                else
  { 
  ((int)(bitmapstruct.element3 |= (1 <<  4))); /* 2 */
                  {
                    width = 1 ;
                    digits = digit[ max - count ] ;
          /*
           * if value to be printed is two or more digits and the format
           * pointer does not specify the number of digits then this code
           * will calculate the correct number of digits
           */
                    while
                      (
 (  /* 21 */ 
                      digits > 9
  )  /* 7 */
                      )
                      {
 { /* 32 */
  int zzqqzs = ((int)(bitmapstruct.element3 |= (1 <<  5))); /* 32a */
                        digits /=
                        10 ;
                        width ++ ;
  ((int)(bitmapstruct.element3 |= (1 <<  6))); /* 6 */
  } 
                      }
  ((int)(bitmapstruct.element3 |= (1 <<  7))); /* 5 */
                  }
 }
                  /* Advance the pointer beyond the number field */
                while
                  (
 (  /* 21 */ 
                  width != 0
  )  /* 7 */
                  )
                  {
 { /* 32 */
  int zzqqzs = ((int)(bitmapstruct.element4 |= (1 <<  0))); /* 32a */
                    string[ istr ] = ' ' ;
                    istr ++ ;
                    -- width ;
  ((int)(bitmapstruct.element4 |= (1 <<  1))); /* 6 */
  } 
                  }
  ((int)(bitmapstruct.element4 |= (1 <<  2))); /* 5 */
                if
                  (
                  format[ ifmt ] == 'd'
                  )
 {
  ((int)(bitmapstruct.element4 |= (1 <<  3))); /* 1 */
                  {
                    ifmt ++ ;
  ((int)(bitmapstruct.element4 |= (1 <<  4))); /* 23 */
                    status2 =
                      safe_int_to_dec (
                      ( char_t * ) & string[ 0 ] , istr , digit[ max - count ] ) ;
                    -- count ;
                  }
  ((int)(bitmapstruct.element4 |= (1 <<  5))); /* 3 */
 }
                else
  { 
  ((int)(bitmapstruct.element4 |= (1 <<  6))); /* 2 */
                  {
                  /* missing the number type */
                    string[ 0 ] = 'E' ;
                    string[ 1 ] = 'r' ;
                    string[ 2 ] = 'r' ;
                    string[ 3 ] = 'o' ;
                    string[ 4 ] = 'r' ;
                    istr = 5 ;
                    status2 = false ;
                  }
 }
              }
  ((int)(bitmapstruct.element4 |= (1 <<  7))); /* 3 */
 }
            else
  { 
  ((int)(bitmapstruct.element5 |= (1 <<  0))); /* 2 */
              {
        /* if not '%' the token for a number format */
        /* output the current character */
                string[ istr ] = format[ ifmt ] ;
                istr ++ ;
                ifmt ++ ;
              }
 }
          }
        while
 (  /* 50 */
          (
          
  (     /*  52 */ 
          status2
  ? (bitmapstruct.element5 |= (1 <<  1 ), 1)
  : (bitmapstruct.element5 |= (1 <<  2 ), 0) ) /* 54 */
          &&
          ( format[ ifmt ] != '\0' )
  ) && (((int)(bitmapstruct.element5 |= (1 <<  3))),1) /* 24 */
    || !(((int)(bitmapstruct.element5 |= (1 <<  4))),1) /* 24A */
          ) ;
        string[ istr ] = '\0' ;
      }
 }
  ((int)(bitmapstruct.element5 |= (1 <<  5))); /* 30 */
    safe_sprintf_6zqendz                                                                                 (      46 ) ; /* 30 */  
    return
    status2 ;
  }
/*
 * Routine to convert one argument to a formatted string
 */
 
bool
  safe_sprintf1 (
  char_t str1 [] ,
  const char_t format1 [] ,
  const int16_t d11 )
  {
 /* 36 */bool safe_sprintf_6izzzqq;
 int izzqqzz=((int)(bitmapstruct.element5 |= (1 <<  6))); /* 37 */
  ((int)(bitmapstruct.element5 |= (1 <<  7))); /* 23 */
   safe_sprintf_6izzzqq =
    (
        safe_sprintf (
        str1 , format1 , 1 , d11 , d11 , d11 , d11 ) ) ;
 
  ((int)(bitmapstruct.element6 |= (1 <<  0))); /* 30 */
    safe_sprintf_6zqendz                                                                                 (      49 ) ; /* 30 */  
    ;
return ( safe_sprintf_6izzzqq );
  }
/*
 * Routine to convert two arguments to a formatted string
 */
 
bool
  safe_sprintf2 (
  char_t str2 [] ,
  const char_t format2 [] ,
  const int16_t d12 ,
  const int16_t d22 )
  {
 /* 36 */bool safe_sprintf_6izzzqq;
 int izzqqzz=((int)(bitmapstruct.element6 |= (1 <<  1))); /* 37 */
  ((int)(bitmapstruct.element6 |= (1 <<  2))); /* 23 */
   safe_sprintf_6izzzqq =
    (
        safe_sprintf (
        str2 , format2 , 2 , d12 , d22 , d22 , d22 ) ) ;
 
  ((int)(bitmapstruct.element6 |= (1 <<  3))); /* 30 */
    safe_sprintf_6zqendz                                                                                 (      52 ) ; /* 30 */  
    ;
return ( safe_sprintf_6izzzqq );
  }
/*
 * Routine to convert three arguments to a formatted string
 */
 
bool
  safe_sprintf3 (
  char_t str3 [] ,
  const char_t format3 [] ,
  const int16_t d13 ,
  const int16_t d23 ,
  const int16_t d33 )
  {
 /* 36 */bool safe_sprintf_6izzzqq;
 int izzqqzz=((int)(bitmapstruct.element6 |= (1 <<  4))); /* 37 */
  ((int)(bitmapstruct.element6 |= (1 <<  5))); /* 23 */
   safe_sprintf_6izzzqq =
    (
        safe_sprintf (
        str3 , format3 , 3 , d13 , d23 , d33 , d33 ) ) ;
 
  ((int)(bitmapstruct.element6 |= (1 <<  6))); /* 30 */
    safe_sprintf_6zqendz                                                                                 (      55 ) ; /* 30 */  
    ;
return ( safe_sprintf_6izzzqq );
  }
/*
 * Routine to convert four arguments to a formatted string
 */
 
bool
  safe_sprintf4 (
  char_t str4 [] ,
  const char_t format4 [] ,
  const int16_t d14 ,
  const int16_t d24 ,
  const int16_t d34 ,
  const int16_t d44 )
  {
 /* 36 */bool safe_sprintf_6izzzqq;
 int izzqqzz=((int)(bitmapstruct.element6 |= (1 <<  7))); /* 37 */
  ((int)(bitmapstruct.element7 |= (1 <<  0))); /* 23 */
   safe_sprintf_6izzzqq =
    (
        safe_sprintf (
        str4 , format4 , 4 , d14 , d24 , d34 , d44 ) ) ;
 
  ((int)(bitmapstruct.element7 |= (1 <<  1))); /* 30 */
    safe_sprintf_6zqendz                                                                                 (      58 ) ; /* 30 */  
    ;
return ( safe_sprintf_6izzzqq );
  }
#define qqqbranches     58
#define QQQMAXMCDCSIZE      2
/********************** LDRA_PORT INSTRUMENTATION **********************/                                                                                                                                                                                           
                                                                                                                                                                                                                                                                    
/******************* END OF LDRA_PORT INSTRUMENTATION ******************/                                                                                                                                                                                           
#define ldra_sscanf                                                                                                                                                                                                                                                 
  /* put in undefs to protect our parameter names from macros */                                                                                                                                                                                                    
#undef f                                                                                                                                                                                                                                                            
#undef i                                                                                                                                                                                                                                                            
#undef j                                                                                                                                                                                                                                                            
#undef k                                                                                                                                                                                                                                                            
#undef s                                                                                                                                                                                                                                                            
#undef l                                                                                                                                                                                                                                                            
#undef ii                                                                                                                                                                                                                                                           
#undef some                                                                                                                                                                                                                                                         
#undef none                                                                                                                                                                                                                                                         
#undef from                                                                                                                                                                                                                                                         
#undef a                                                                                                                                                                                                                                                            
#undef b                                                                                                                                                                                                                                                            
#undef iz                                                                                                                                                                                                                                                           
#undef jz                                                                                                                                                                                                                                                           
#undef qqnull_params                                                                                                                                                                                                                                                
#define qqnull_params void                                                                                                                                                                                                                                          
  /* Conventional Instrumentation */                                                                                                                                                                                                                                
#define qqzzidfield 1                                                                                                                                                                                                                                               
  /* single file or fileid */                                                                                                                                                                                                                                       
  /* these have an extra field for the fileid */                                                                                                                                                                                                                    
  static char qqqqone[] = "%6d\n";           /* single point */                                                                                                                                                                                                     
  /* uncompressed data structures */                                                                                                                                                                                                                                
  /* uncompressed  bitmap */                                                                                                                                                                                                                                        
#define QQQFIXEDSIZE                                                                                                                                                                                                                                                
  static int qqqlast = 0;                                                                                                                                                                                                                                           
  extern int qqupload_registered;                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                    
  /* ----------- zscanf ---------------------------------------------------* 201 *                                                                                                                                                                                  
   *        Returns an integer extracted from a string                                                                                                                                                                                                              
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int safe_sprintf_6zscanf(char* qqscan_str)                                                                                                                                                                                                                 
  {                                                                                                                                                                                                                                                                 
    int qqvalue;                                                                                                                                                                                                                                                    
    int qqisign;                                                                                                                                                                                                                                                    
    char* qqcptr;                                                                                                                                                                                                                                                   
    qqvalue = 0;                                                                                                                                                                                                                                                    
    qqisign = 1;                                                                                                                                                                                                                                                    
    qqcptr = qqscan_str;                                                                                                                                                                                                                                            
    /* Skip spaces */                                                                                                                                                                                                                                               
    while (qqcptr[0] == ' ')                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
      qqcptr++;                                                                                                                                                                                                                                                     
    }                                                                                                                                                                                                                                                               
    /* Check for a leading --- */                                                                                                                                                                                                                                   
    if (qqcptr[0] == '-')                                                                                                                                                                                                                                           
    {                                                                                                                                                                                                                                                               
      qqisign = -1;                                                                                                                                                                                                                                                 
      qqcptr++;                                                                                                                                                                                                                                                     
    }                                                                                                                                                                                                                                                               
    /* Extract digits */                                                                                                                                                                                                                                            
    while ((qqcptr[0] >= '0') && (qqcptr[0] <= '9'))                                                                                                                                                                                                                
    {                                                                                                                                                                                                                                                               
      qqvalue = 10 * qqvalue;                                                                                                                                                                                                                                       
      qqvalue = qqvalue + (qqcptr[0] - '0');                                                                                                                                                                                                                        
      qqcptr++;                                                                                                                                                                                                                                                     
    }                                                                                                                                                                                                                                                               
    qqvalue = qqisign * qqvalue;                                                                                                                                                                                                                                    
    return qqvalue;                                                                                                                                                                                                                                                 
  } /* end of zscanf */                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 214 *                                                                                                                                                                                  
   *            qqoutput                                                                                                                                                                                                                                            
   *    This is the principle output routine.                                                                                                                                                                                                                       
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static void qqoutput(FILEPOINT char* s, int i)                                                                                                                                                                                                                    
  {                                                                                                                                                                                                                                                                 
    ldra_sprintf2 (&ldra_buffer[0], s, i, zzfileid);                                                                                                                                                                                                                
    ldra_port_write (&ldra_buffer[0]);                                                                                                                                                                                                                              
  } /* end of qqoutput */                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 215 *                                                                                                                                                                                  
   *            qqoutput0                                                                                                                                                                                                                                           
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static void qqoutput0(FILEPOINT char* s)                                                                                                                                                                                                                          
  {                                                                                                                                                                                                                                                                 
    ldra_port_write(s);                                                                                                                                                                                                                                             
  } /* end of qqoutput0 */                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 216 *                                                                                                                                                                                  
   *            qqoutput2                                                                                                                                                                                                                                           
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static void qqoutput2(FILEPOINT char* s, int i, int j)                                                                                                                                                                                                            
  {                                                                                                                                                                                                                                                                 
    ldra_sprintf2 (&ldra_buffer[0], s, i, j);                                                                                                                                                                                                                       
    ldra_port_write (&ldra_buffer[0]);                                                                                                                                                                                                                              
  } /* end of qqoutput2 */                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 217 *                                                                                                                                                                                  
   *            qqoutput3                                                                                                                                                                                                                                           
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static void qqoutput3(FILEPOINT char* s, int i, int j, int k)                                                                                                                                                                                                     
  {                                                                                                                                                                                                                                                                 
    ldra_sprintf3 (&ldra_buffer[0], s, i, j, k);                                                                                                                                                                                                                    
    ldra_port_write (&ldra_buffer[0]);                                                                                                                                                                                                                              
  } /* end of qqoutput3 */                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 218 *                                                                                                                                                                                  
   *            qqoutput4                                                                                                                                                                                                                                           
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static void qqoutput4(FILEPOINT char* s, int i, int j, int k, int l)                                                                                                                                                                                              
  {                                                                                                                                                                                                                                                                 
    ldra_sprintf4 (&ldra_buffer[0], s, i, j, k, l);                                                                                                                                                                                                                 
    ldra_port_write (&ldra_buffer[0]);                                                                                                                                                                                                                              
  } /* end of qqoutput4 */                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 222 *                                                                                                                                                                                  
   *            qqqqinitialise                                                                                                                                                                                                                                      
   * This procedure initialises the structures for                                                                                                                                                                                                                  
   * compressed execution histories.                                                                                                                                                                                                                                
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static void qqqqinitialise(int ii)                                                                                                                                                                                                                                
  {                                                                                                                                                                                                                                                                 
    /* bitmap separate */                                                                                                                                                                                                                                           
    qqqlast = 1; /* stops qqfun() calling initialise again */                                                                                                                                                                                                       
    /* struct singlefile notmainfl */                                                                                                                                                                                                                               
  } /* end of qqqqinitialise */                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 225 *                                                                                                                                                                                  
   *            qqqbitmapreset                                                                                                                                                                                                                                      
   * This procedure resets the structures for compressed execution histories.                                                                                                                                                                                       
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static void qqqbitmapreset()                                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
    struct bitmapstruct_t localbitmap = {0};                                                                                                                                                                                                                        
    bitmapstruct = localbitmap;                                                                                                                                                                                                                                     
  } /* end of qqqbitmapreset */                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                    
#undef QQQTEMP1                                                                                                                                                                                                                                                     
#define QQQTEMP1                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 312 *                                                                                                                                                                                  
   * This routine opens the execution history file. It is instrumented at the                                                                                                                                                                                       
   * start of the main program if one exists in the file. In general this is                                                                                                                                                                                        
   * superceded by safe_sprintf_6zqqzqz1 below.                                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int safe_sprintf_6zqqzqz(qqnull_params)                                                                                                                                                                                                                    
  {                                                                                                                                                                                                                                                                 
    if ( safe_sprintf_6zzopen != 1 )                                                                                                                                                                                                                                
    {                                                                                                                                                                                                                                                               
      safe_sprintf_6zzopen = 1;                                                                                                                                                                                                                                     
    }                                                                                                                                                                                                                                                               
    return 1;                                                                                                                                                                                                                                                       
  } /* end of zqqzqz */                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 317 *                                                                                                                                                                                  
   * This routine also opens the execution history file.  It is called                                                                                                                                                                                              
   * automatically if a probe fires and the execution history is not already                                                                                                                                                                                        
   * opened (safe_sprintf_6zzopen = 0 ).                                                                                                                                                                                                                            
   * Because this always works (it was intended for files with no main program)                                                                                                                                                                                     
   * it is now the de facto common way to open the execution history.                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int safe_sprintf_6zqqzqz1(qqnull_params)                                                                                                                                                                                                                   
  {                                                                                                                                                                                                                                                                 
    if ( safe_sprintf_6zzopen != 1 )                                                                                                                                                                                                                                
    {                                                                                                                                                                                                                                                               
      ldra_port_open();  /* 7 */                                                                                                                                                                                                                                    
      qqqqinitialise(0);                                                                                                                                                                                                                                            
      safe_sprintf_6zzopen = 1;                                                                                                                                                                                                                                     
    }                                                                                                                                                                                                                                                               
    return 1;                                                                                                                                                                                                                                                       
  } /* end of zqqzqz1 */                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                    
  /* ----------- zqendz ---------------------------------------------------* 330 *                                                                                                                                                                                  
   * This routine is called on exiting a routine in a module.                                                                                                                                                                                                       
   * It closes the execution history.                                                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int safe_sprintf_6zqendz(int qqqi)                                                                                                                                                                                                                         
  {                                                                                                                                                                                                                                                                 
    /* For struct bitmap in one file, ensure upload and reset functions are registered */                                                                                                                                                                           
    if (!qqqstructzzopen)                                                                                                                                                                                                                                           
    {                                                                                                                                                                                                                                                               
      qqpopulate_array_fcn_ptrQQ (QQQfcn_ptr_num, qqqupload, qqqbitmapreset);                                                                                                                                                                                       
      qqqstructzzopen = 1;                                                                                                                                                                                                                                          
    }                                                                                                                                                                                                                                                               
                                                                                                                                                                                                                                                                    
    if ( safe_sprintf_6zzopen != 1 )                                                                                                                                                                                                                                
    {                                                                                                                                                                                                                                                               
      safe_sprintf_6zqqzqz1();                                                                                                                                                                                                                                      
    }                                                                                                                                                                                                                                                               
    /* ----------------------------------------------------------------------* 331 *                                                                                                                                                                                
     * this is the one which puts an integer into                                                                                                                                                                                                                   
     * the execution history file and returns unity.                                                                                                                                                                                                                
     * The format of each field consists of six columns,                                                                                                                                                                                                            
     * the number is right justified in this field.                                                                                                                                                                                                                 
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
    if ( safe_sprintf_6zzopen )                                                                                                                                                                                                                                     
    {                                                                                                                                                                                                                                                               
      /* uncompressed */                                                                                                                                                                                                                                            
      /* uncompressed unbuffered */                                                                                                                                                                                                                                 
      /* uncompressed unbuffered bitmap  */                                                                                                                                                                                                                         
      if ( qqqi > 0 )                                                                                                                                                                                                                                               
      {                                                                                                                                                                                                                                                             
      } else {                                                                                                                                                                                                                                                      
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    qqqlast = 0;                                                                                                                                                                                                                                                    
    return 1;                                                                                                                                                                                                                                                       
  } /* end of zqendz */                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 335 *                                                                                                                                                                                  
   *            Output structure - qqbmsoutput                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int qqqbranches_printed = 0;                                                                                                                                                                                                                               
  static void qqbmsoutput(FILEPOINT char* s, unsigned int i)                                                                                                                                                                                                        
  {                                                                                                                                                                                                                                                                 
    int b, last = 0;                                                                                                                                                                                                                                                
    for (b=0; b<qqqqbmselwidth/8; b++)                                                                                                                                                                                                                              
    {                                                                                                                                                                                                                                                               
      ldra_sprintf1 (&ldra_buffer[0], s, (i >> last) & ~(~0 << 8));                                                                                                                                                                                                 
      ldra_port_write (&ldra_buffer[0]);                                                                                                                                                                                                                            
      ldra_sprintf1 (&ldra_buffer[0], "%8d\n", zzfileid);                                                                                                                                                                                                           
      ldra_port_write (&ldra_buffer[0]);                                                                                                                                                                                                                            
      last += 8;                                                                                                                                                                                                                                                    
      qqqbranches_printed += 8;                                                                                                                                                                                                                                     
      if (qqqbranches_printed >= qqqbranches)                                                                                                                                                                                                                       
      {                                                                                                                                                                                                                                                             
        /* do not print any more, can be left over when using more than 8 bits to store bitmap */                                                                                                                                                                   
        break;                                                                                                                                                                                                                                                      
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
  } /* end of qqbmsoutput */                                                                                                                                                                                                                                        
                                                                                                                                                                                                                                                                    
 /* ----------------------------------------------------------------------* 336 *                                                                                                                                                                                   
  *            qqqupload                                                                                                                                                                                                                                            
  * This routine loops through the stored bitmap and outputs it.                                                                                                                                                                                                    
  * It then uploads the stored mcdc.                                                                                                                                                                                                                                
  * -----------------------------------------------------------------------------                                                                                                                                                                                   
  */                                                                                                                                                                                                                                                                
  static void qqqupload(qqnull_params)                                                                                                                                                                                                                              
  {                                                                                                                                                                                                                                                                 
    int i;                                                                                                                                                                                                                                                          
    /* uncompressed  bitmap (!singlefile or mainfl) separate */                                                                                                                                                                                                     
    {                                                                                                                                                                                                                                                               
      safe_sprintf_6zqqzqz1();                                                                                                                                                                                                                                      
#define ELEMENT(N) qqbmsoutput("%8d", bitmapstruct.element##N);                                                                                                                                                                                                     
#define LASTELEMENT                                                                                                                                                                                                                                                 
#include "safe_sprintf_6zbelem.def"                                                                                                                                                                                                                                 
      qqqbranches_printed = 0;                                                                                                                                                                                                                                      
#undef LASTELEMENT                                                                                                                                                                                                                                                  
#undef ELEMENT                                                                                                                                                                                                                                                      
    }                                                                                                                                                                                                                                                               
    /* bitmap separate */                                                                                                                                                                                                                                           
    qqqlast = 1; /* stops qqfun() calling initialise again */                                                                                                                                                                                                       
  } /* end of qqqupload */                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 344 *                                                                                                                                                                                  
   * This routine should be called before the program terminates.                                                                                                                                                                                                   
   * It closes the execution history                                                                                                                                                                                                                                
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int safe_sprintf_6zqzqzq(int qqqi)                                                                                                                                                                                                                         
  {                                                                                                                                                                                                                                                                 
    if ( safe_sprintf_6zzopen != 1 )                                                                                                                                                                                                                                
    {                                                                                                                                                                                                                                                               
      safe_sprintf_6zqqzqz1();                                                                                                                                                                                                                                      
    }                                                                                                                                                                                                                                                               
    /* not compressed */                                                                                                                                                                                                                                            
    /* do nothing for bitmap*/                                                                                                                                                                                                                                      
    /* upload the history */                                                                                                                                                                                                                                        
    /* bitmap */                                                                                                                                                                                                                                                    
    /* uncompressed  bitmap */                                                                                                                                                                                                                                      
    safe_sprintf_6zqendz(qqqi);                                                                                                                                                                                                                                     
    /* qqqupload closes the execution history file */                                                                                                                                                                                                               
    return 1;                                                                                                                                                                                                                                                       
  } /* end of zqzqzq */                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                    
/*                                                                                                                                                                                                                                                                  
 * This include is in a separate file, otherwise                                                                                                                                                                                                                    
 * the instrumenter strips the #if #endif statements                                                                                                                                                                                                                
 */                                                                                                                                                                                                                                                                 
#include "C:\LDRA_Toolsuite\Compiler_spec\Microchip\xc8\ldra_port_shared_memory.c"                                                                                                                                                                                  
/* END OF TESTBED INSTRUMENTATION */                                                                                                                                                                                                                                
 
