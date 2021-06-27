/* 
 * Symisc xPP: An embeddable general purpose macro processor.
 * Copyright (C) 2011 - 2015 ,Symisc Systems http://symisc.net/
 * Version 2.6.1432
 * For information on licensing,redistribution of this file,and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://www.symisc.net
 */
/*
* Copyright (C) 2011 - 2015 Symisc Systems, S.U.A.R.L [M.I.A.G Mrad Chems Eddine <chm@symisc.net>].
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY SYMISC SYSTEMS ``AS IS'' AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
* NON-INFRINGEMENT, ARE DISCLAIMED. IN NO EVENT SHALL SYMISC SYSTEMS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* $SymiscID: xpp.c v2.6 UNIX|WIN32/64 2011-12-11 22:22 stable <chm@symisc.net> $ */

/* This file is an amalgamation of many separate C source files from xPP version 2.6.
 * By combining all the individual C code files into this single large file, the entire code
 * can be compiled as a single translation unit.This allows many compilers to do optimization's
 * that would not be possible if the files were compiled separately.Performance improvements
 * are commonly seen when xPP is compiled as a single translation unit.
 *
 * This file is all you need to compile xPP.To use xPP in other programs, you need
 * this file and the "xpp.h" header file that defines the programming interface to the 
 * xPP engine.(If you do not have the "xpp.h" header file at hand, you will find
 * a copy embedded within the text of this file.Search for "Header file: <xpp.h>" to find
 * the start of the embedded xpp.h header file.) Additional code files may be needed if
 * you want a wrapper to interface xPP with your choice of programming language.
 * To get the official documentation,please visit http://xpp.symisc.net/
 */
#define XPP_VERSION_NUMBER      (2<<24|6<<16|9)          /* Library binary version [Major.Minor.Revision] */
#define XPP_VERSION_MAJOR(VER)  (VER>>24)                /* Library major version */
#define XPP_VERSION_MINOR(VER)  (((VER>>8)&0xFFFF)>>8)   /* Library minor version */
#define XPP_REVISION(VER)       (VER&0xFF)               /* Library revision number */
/*
 * Header file for the xPP macro processor: <xpp.h>
 */
/* This file was automatically generated.  Do not edit (except for compile time directive)! */ 
#ifndef _XPP_H_
#define _XPP_H_
/* 
 * Symisc xPP: An embeddable general purpose macro processor.
 * Copyright (C) 2011 - 2015, Symisc Systems http://symisc.net/
 * Version 2.6.1432
 * For information on licensing,redistribution of this file,and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://www.symisc.net
 */
/*
* Copyright (C) 2011 - 2015 Symisc Systems, S.U.A.R.L [M.I.A.G Mrad Chems Eddine <chm@symisc.net>].
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY SYMISC SYSTEMS ``AS IS'' AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
* NON-INFRINGEMENT, ARE DISCLAIMED. IN NO EVENT SHALL SYMISC SYSTEMS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/* $SymiscID: xpp.h v2.6 UNIX|WIN32/64 2011-12-01 21:34 stable <chm@symisc.net> $ */
#include <stdarg.h> /* needed for the definition of va_list */ 
/* 
* This header file defines the interface that the Symisc embedded macro processor [xPP]
* presents to host application. 
* If a C-functions,constants,structure,datatype or any other definitions does not appear
* in this  public file,then it is not a published API of the xPP Library,is subject to change 
* without notice,and should not be referenced by programs that use the library. 
*/ 
/* Make sure we can call this stuff from C++ */
#ifdef __cplusplus
extern "C" { 
#endif
/*
 * Compile time engine version,signature,identification in the symisc source tree
 * and copyright notice.
 * Each macro have an equivalent C interface associated with it that provide the same
 * information but are associated with the library instead of the header file.
 * Refer to [xpp_lib_version()],[xpp_lib_signature()],[xpp_lib_ident()] and
 * [xpp_lib_copyright()] for more information.
 */
/*
 * The XPP_VERSION C preprocessor macro in the xpp.h header evaluates to a string
 * literal that is the xPP version in the format "X.Y.Z" where X is the major version
 * number and Y is the minor version number and Z is the release number.
 */
#define XPP_VERSION "2.6.9"
/*
 * xPP macro processor engine signature.
 */
#define XPP_SIG "xPP/2.6"
/*
 * xPP identification in the Symisc source tree:
 * Each particular check-in of a particular software released by symisc systems
 * have an unique identifier associated with it,this macro hold the one associated
 * with xPP.
 */
#define XPP_IDENT "xPP:343c9623efcc3b87cd60dcb1a19492e8b01f1a03"
/*
 * Copyright notice.
 * Please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://www.symisc.net
 * for information on licensing,redistribution of this file,and for a DISCLAIMER OF ALL WARRANTIES.
 */
#define XPP_COPYRIGHT "Copyright (C) Symisc Systems 2011-2012, http://xpp.symisc.net/"
/*
 * Compile time directives.
 */
 /*
  * XPP_ENABLE_THREADS
  *
  * xPP has full support of multi-threading but this feature is disabled by default.
  * In other words, mutexing is disabled and the library is in a mode where it can
  * only be used by a single thread so it's unsafe to use xPP in a multi-threaded program.
  * To compile xPP with threading support simply define the XPP_ENABLE_THREADS directive.
  * In other words,this option enables all mutexes including the recursive mutexes on xPP 
  * objects.
  * In this mode the xPP engine will itself serialize access to xPP objects so that the 
  * application is free to share the same preprocessor between different threads at the 
  * same time.
  * The threading mode can be determined at run-time via the [xpp_lib_is_threadsafe()]
  * interface which return 1 (TRUE) if xPP can work with multiple threads in the same
  * process.Otherwise zero (FALSE) is returned.
  * For more information,refer to the official documentation section "Threading mode".
  */
  /*
   * XPP_OMIT_BUILTIN
   *
   * By default xPP is bundled with more than 70 built-in macros, these macros are extremely
   * useful and can save the host application a lot of time instead of implementing macros
   * from scratch.
   * For a complete listing of the built-in macros and their purposes, please refer to the 
   * official documentation section "Built-in macros".
   * If xPP is compiled with the XPP_OMIT_BUILTIN compile time directive defined then the
   * predefined macros are omitted from the entire build except the configuration macros 
   * like undef,ERROR and so on.
   */
/* Forward declaration to public objects */
typedef struct xpp_context xpp_context;
typedef struct xpp xpp;

/* Symisc public definitions */
#if !defined(SYMISC_STANDARD_DEFS)
#define SYMISC_STANDARD_DEFS

#if defined (_WIN32) || defined (WIN32) || defined(__MINGW32__) || defined (_MSC_VER) || defined (_WINCE)
/* Windows Systems */
#if !defined(__WINNT__)
#define __WINNT__
#endif 
#else
/*
 * By default we will assume that we are compiling on a UNIX systems.
 * Otherwise the OS_OTHER directive must be defined.
 */
#if !defined(OS_OTHER)
#if !defined(__UNIXES__)
#define __UNIXES__
#endif /* __UNIXES__ */
#else
#if !defined(SX_ENABLE_FLOATINGPOINT)
/* Omit floating point arithmetic for non UNIX and non Windows systems */ 
#define SX_OMIT_FLOATINGPOINT
#endif /* !SX_ENABLE_FLOATINGPOINT */
#endif /* OS_OTHER */
#endif /* __WINNT__/__UNIXES__ */
#if defined (__WINNT__)
#if defined(_MSC_VER) || defined(__BORLANDC__)
typedef signed __int64	   sxi64; /* 64 bits(8 bytes) signed int64 */
typedef unsigned __int64   sxu64; /* 64 bits(8 bytes) unsigned int64 */
#else
typedef signed long long int    sxi64; /* 64 bits(8 bytes) signed int64 */
typedef unsigned long long int sxu64; /* 64 bits(8 bytes) unsigned int64 */
#endif /* _MSC_VER */
#else
typedef signed long long int sxi64; /* 64 bits(8 bytes) signed int64 */
typedef unsigned long long int sxu64; /* 64 bits(8 bytes) unsigned int64 */
#endif /* __WINNT__ */
/* Signature of the consumer routine */
typedef int (*ProcConsumer)(const void *,unsigned int,void *);
/* Forward reference to public objects */
typedef struct SyMutexMethods SyMutexMethods;
typedef struct SyMemMethods SyMemMethods;
typedef struct SyString SyString;
typedef struct syiovec syiovec;
typedef struct SyMutex SyMutex;
typedef struct sytime sytime;
typedef struct Sytm Sytm;
/* Scatter and gather array. */
struct syiovec
{
#if defined (__WINNT__)
	/* Same fields type and offset as WSABUF structure defined one winsock2 header */
	unsigned long nLen;
	char *pBase;
#else
	void *pBase;
	unsigned long nLen;
#endif
};
struct SyString
{
	const char *zString;  /* Raw string (may not be null terminated) */
	unsigned int nByte;   /* Raw string length */
};
/* Time structure. */
struct Sytm
{
  int tm_sec;     /* seconds (0 - 60) */
  int tm_min;     /* minutes (0 - 59) */
  int tm_hour;    /* hours (0 - 23) */
  int tm_mday;    /* day of month (1 - 31) */
  int tm_mon;     /* month of year (0 - 11) */
  int tm_year;    /* year + 1900 */
  int tm_wday;    /* day of week (Sunday = 0) */
  int tm_yday;    /* day of year (0 - 365) */
  int tm_isdst;   /* is summer time in effect? */
  char *tm_zone;  /* abbreviation of timezone name */
  long tm_gmtoff; /* offset from UTC in seconds */
};
/* Convert a tm structure (struct tm *) found in <time.h> to a Sytm structure */
#define STRUCT_TM_TO_SYTM(pTM,pSYTM) \
	(pSYTM)->tm_hour = (pTM)->tm_hour;\
	(pSYTM)->tm_min	 = (pTM)->tm_min;\
	(pSYTM)->tm_sec	 = (pTM)->tm_sec;\
	(pSYTM)->tm_mon	 = (pTM)->tm_mon;\
	(pSYTM)->tm_mday = (pTM)->tm_mday;\
	(pSYTM)->tm_year = (pTM)->tm_year + 1900;\
	(pSYTM)->tm_wday = (pTM)->tm_wday;\
	(pSYTM)->tm_zone = 0;

/* Convert a SYSTEMTIME structure (LPSYSTEMTIME: Windows Systems only ) to a Sytm structure */
#define SYSTEMTIME_TO_SYTM(pSYSTIME,pSYTM) \
	 (pSYTM)->tm_hour = (pSYSTIME)->wHour;\
	 (pSYTM)->tm_min  = (pSYSTIME)->wMinute;\
	 (pSYTM)->tm_sec  = (pSYSTIME)->wSecond;\
	 (pSYTM)->tm_mon  = (pSYSTIME)->wMonth - 1;\
	 (pSYTM)->tm_mday = (pSYSTIME)->wDay;\
	 (pSYTM)->tm_year = (pSYSTIME)->wYear;\
	 (pSYTM)->tm_wday = (pSYSTIME)->wDayOfWeek;\
	 (pSYTM)->tm_zone = 0;

/* High resolution timer.*/
struct sytime
{
	long tm_sec;	/* seconds */
	long tm_msec;	/* milliseconds */
};
/* Dynamic memory allocation methods. */
struct SyMemMethods 
{
	void * (*xAlloc)(unsigned int);          /* [Required:] Allocate a memory chunk */
	void * (*xRealloc)(void *,unsigned int); /* [Required:] Re-allocate a memory chunk */
	void   (*xFree)(void *);                 /* [Required:] Release a memory chunk */
	unsigned int  (*xChunkSize)(void *);     /* [Optional:] Return chunk size */
	int    (*xInit)(void *);                 /* [Optional:] Initialization callback */
	void   (*xRelease)(void *);              /* [Optional:] Release callback */
	void  *pUserData;                        /* [Optional:] First argument to xInit() and xRelease() */
};
/* Out of memory callback signature. */
typedef int (*ProcMemError)(void *);
/* Mutex methods. */
struct SyMutexMethods 
{
	int (*xGlobalInit)(void);		/* [Optional:] Global mutex initialization */
	void  (*xGlobalRelease)(void);	/* [Optional:] Global Release callback () */
	SyMutex * (*xNew)(int);	        /* [Required:] Request a new mutex */
	void  (*xRelease)(SyMutex *);	/* [Optional:] Release a mutex  */
	void  (*xEnter)(SyMutex *);	    /* [Required:] Enter mutex */
	int (*xTryEnter)(SyMutex *);    /* [Optional:] Try to enter a mutex */
	void  (*xLeave)(SyMutex *);	    /* [Required:] Leave a locked mutex */
};
#if defined (_MSC_VER) || defined (__MINGW32__) ||  defined (__GNUC__) && defined (__declspec)
#define SX_APIIMPORT	__declspec(dllimport)
#define SX_APIEXPORT	__declspec(dllexport)
#else
#define	SX_APIIMPORT
#define	SX_APIEXPORT
#endif
/* Standard return values from Symisc public interfaces */
#define SXRET_OK       0      /* Not an error */	
#define SXERR_MEM      (-1)   /* Out of memory */
#define SXERR_IO       (-2)   /* IO error */
#define SXERR_EMPTY    (-3)   /* Empty field */
#define SXERR_LOCKED   (-4)   /* Locked operation */
#define SXERR_ORANGE   (-5)   /* Out of range value */
#define SXERR_NOTFOUND (-6)   /* Item not found */
#define SXERR_LIMIT    (-7)   /* Limit reached */
#define SXERR_MORE     (-8)   /* Need more input */
#define SXERR_INVALID  (-9)   /* Invalid parameter */
#define SXERR_ABORT    (-10)  /* User callback request an operation abort */
#define SXERR_EXISTS   (-11)  /* Item exists */
#define SXERR_SYNTAX   (-12)  /* Syntax error */
#define SXERR_UNKNOWN  (-13)  /* Unknown error */
#define SXERR_BUSY     (-14)  /* Busy operation */
#define SXERR_OVERFLOW (-15)  /* Stack or buffer overflow */
#define SXERR_WILLBLOCK (-16) /* Operation will block */
#define SXERR_NOTIMPLEMENTED  (-17) /* Operation not implemented */
#define SXERR_EOF      (-18) /* End of input */
#define SXERR_PERM     (-19) /* Permission error */
#define SXERR_NOOP     (-20) /* No-op */	
#define SXERR_FORMAT   (-21) /* Invalid format */
#define SXERR_NEXT     (-22) /* Not an error */
#define SXERR_OS       (-23) /* System call return an error */
#define SXERR_CORRUPT  (-24) /* Corrupted pointer */
#define SXERR_CONTINUE (-25) /* Not an error: Operation in progress */
#define SXERR_NOMATCH  (-26) /* No match */
#define SXERR_RESET    (-27) /* Operation reset */
#define SXERR_DONE     (-28) /* Not an error */
#define SXERR_SHORT    (-29) /* Buffer too short */
#define SXERR_PATH     (-30) /* Path error */
#define SXERR_TIMEOUT  (-31) /* Timeout */
#define SXERR_BIG      (-32) /* Too big for processing */
#define SXERR_RETRY    (-33) /* Retry your call */
#define SXERR_IGNORE   (-63) /* Ignore */
#endif /* SYMISC_PUBLIC_DEFS */
/* Successful return */
#define XPP_OK SXRET_OK
/*
 * Signature of the C function that implement the macro body.
 *    int MacroCallback(xpp_context *,int,const SyString *)
 * Each registered macro must have a C function associated with it (except when
 * the USER_MACRO_EMPTY flag is set when the macro was registered).
 * This callback will be fired by the macro processor when it encounter a token
 * that correspond to the macro name.
 * This callback is responsible of expanding the macro body using the [xpp_context_*()]
 * interfaces and must return XPP_OK (zero) on success.
 * The first argument is the xPP macro calling context. This context is filled by the
 * underlying macro processor and passed to the callback, the context act as an intermediate
 * between the macro engine and the user callback.
 * The second argument is the total number of collected arguments (if faced with function
 * like macro). Otherwise if faced with an object like macro this parameter is set
 * to zero.
 * The last argument is the collected arguments values (either expanded or not depending 
 * on the macro registration flags) if faced with a function like macro. Otherwise this parameter is set to NULL.
 *
 * Example: Register a function that implement the "TIME" macro:
 *
 * #include <time.h>
 * int Time_Macro_Callback(xpp_context *pCtx,int nArg,const SyString *azArg)
 * {
 *   strut tm *pGm = gmtime(time(NULL)); //Get the current time (GMT) 
 *   //Expand the result
 *   xpp_context_format(pCtx,"%02d:%02d:%02d GMT",pGm->tm_hour,pGm->tm_min,pGm->tm_sec);
 *   //Tell the preprocessor that everything is OK
 *   return XPP_OK;
 * }
 *
 * The next step is to register the C function above and associate it with the TIME
 * keyword. This can be done via calls to [xpp_register_macro()] or [xpp_queue_macro()]
 * interfaces as follows:
 *
 *  xpp_register_macro(pEngine,"TIME",Time_Macro_Callback,0,USER_MACRO_STRICT_INVOKE);
 *
 * Now, when the macro processor see the "TIME" keyword, it calls immediately the associated
 * callback that we have implemented above.
 *
 * Suppose that the user input looks like this:
 *       Current time is: TIME
 * After a call to [xpp_expand()] or [xpp_expand_file()], the expanded input will look
 * like this:
 *      Current time is: 23:56:21 GMT
 *
 * Refer to the official documentation section "Implementing and registering macros"
 * "xPP internal" or "API reference" for more information.
 */
typedef int (*ProcMacroExpansion)(xpp_context *,int,const SyString *);
/*
 * xPP configuration commands. 
 *
 * The following set of constants are the available configuration verbs that can
 * be used by the host-application to configure a working macro processor instance
 * [xpp objects].
 * These constants must be passed as the second argument to the [xpp_config()]
 * interface.
 * Each options require a variable number of arguments.
 * The [xpp_config()] interface will return XPP_OK on success, any other return value
 * indicates failure.
 * Refer to the official documentation for more information on the configuration verbs
 * and their expected parameters.
 */
#define XPP_CONFIG_STRING_DELIMITER       1  /* TWO ARGUMENTS: const char *zLeftDelim,const char *zRightDelim */
#define XPP_CONFIG_COMMENT                2  /* TWO ARGUMENTS: const char *zStart,const char *zEnd */
#define XPP_CONFIG_CONCAT                 3  /* ONE ARGUMENT:  const char *zConcatOperator */
#define XPP_CONFIG_MACRO_KEYWORD          4  /* TWO ARGUMENTS: const char *zMacroDirective,const *zEndDirective */
#define XPP_CONFIG_IMPORT_PATH            5  /* ONE ARGUMENT:  const char *zPath */
#define XPP_CONFIG_STRINGING_OPERATOR     6  /* ONE ARGUMENT:  const char *zStringingOperator */
#define XPP_CONFIG_OUTPUT_CONSUMER        7  /* TWO ARGUMENTS: int (*xConsumer)(const void *,unsigned int,void *),void *pUserData */
#define XPP_CONFIG_OUTPUT_BUFFER          8  /* TWO ARGUMENTS: char zBuffer[],unsigned int INOUT *pBufsize  */
#define XPP_CONFIG_OUTPUT_DYNAMIC_BUFFER  9  /* TWO ARGUMENTS: char **pzBuffer,unsigned int *pOutputLen */
#define XPP_CONFIG_ARG_DELIMITER          10 /* TWO ARGUMENTS: const char *zLeftDelimiter,const char *zRightDelimiter */
#define XPP_CONFIG_ARG_SEPARATOR          11 /* ONE ARGUMENT: const char *zSeparator */
#define XPP_CONFIG_NESTING_LIMIT          12 /* ONE ARGUMENT: int NestingLimit */
#define XPP_CONFIG_MACRO_PREFIX           13 /* ONE ARGUMENT: const char *zPrefix */
#define XPP_CONFIG_EXPAND_QUOTED          14 /* NO ARGUMENTS */
#define XPP_CONFIG_TRACE_CALLBACK         15 /* TWO ARGUMENTS: int (*xTrace)(void *,const char *,const char *,int,int,const SyString *),void *pUserData */
#define XPP_CONFIG_DISABLE_BUILTIN        16 /* NO ARGUMENTS */
#define XPP_CONFIG_ERR_CALLBACK           17 /* TWO ARGUMENTS: void (*xErr)(void *,const char *,int,int,const char *),void *pUserData */
/*
 * Input processing options flags.
 * The follwoing set of options flags are the allowed constants that can be set by the host
 * application when expanding input.
 * These flags have meaning only when called with the [xpp_expand()] or [xpp_expand_file()]
 * interfaces respectively as the fourth and the third parameters.
 * Refer to the official documentation for more information on flags purposes.
 */
#define XPP_IGNORE_WS           0x01  /* Ignore white spaces completely */
#define XPP_REDUCE_WS           0x02  /* Reduce successive white spaces to a single space and successive
                                       * blank lines to a single line.
                                       */
#define XPP_TRIM_ARGS           0x08  /* Remove leading and trailing white spaces when processing macro arguments */
#define XPP_UNESCAPE_STRING     0x010 /* Resolve escape sequences '\n','\x','\r'...in constant string literals */
/*
 * Macro registration options flags.
 * The following set of options flags are the allowed constants that can be set
 * by the host application when registering macros (C functions flags).
 * These flags have meaning only when called with the [xpp_register_macro()]
 * or [xpp_queue_macro()] interfaces as the last argument to one of those.
 * Refer to the official documentation for more information on flags purposes.
 */
#define USER_MACRO_COLLECT_ARGS         0x001 /* Function-like macro: Collect arguments for this macro */
#define USER_MACRO_STRICT_INVOKE        0x002 /* Strict invoke (Recommended for all macros) */
#define USER_MACRO_IGNORE_EXPANDING     0x004 /* Do not process macro body */
#define USER_MACRO_FLAT_ARGS            0x008 /* Function-like macro: Collect arguments until the end of the line */
#define USER_MACRO_EMPTY                0x010 /* Macro with no body (No callback associated with it) [i.e: environment macro] */
#define USER_MACRO_IGNORE_ARG_EXPANDING 0x020 /* Do not expand macro arguments */
#define USER_MACRO_TRIM_ONLY            0x040 /* Trim macro body only (white spaces, blank lines...) without expanding tokens */
/*
 * Global library configuration commands.
 * The following set of constants are the available configuration verbs that can
 * be used by the host-application to configure the whole library.
 * These constants must be passed as the first argument to the [xpp_lib_config()] 
 * interface.
 * Each options require a variable number of arguments.
 * The [xpp_lib_config()] interface will return XPP_OK on success,any other
 * return value indicates failure.
 * Notes:
 * The default configuration is recommended for most applications and so the call to
 * [xpp_lib_config()] is usually not necessary. It is provided to support rare 
 * applications with unusual needs. 
 * The [xpp_lib_config()] interface is not threadsafe. The application must insure that
 * no other [xpp_*()] interfaces are invoked by other threads while [xpp_lib_config()]
 * is running. Furthermore, [xpp_lib_config()] may only be invoked prior to library
 * initialization using [xpp_lib_init()] or [xpp_init()] or after shutdown
 * by [xpp_lib_shutdown()]. If [xpp_lib_config()] is called after [xpp_lib_init()]
 * or [xpp_init()] and before [xpp_lib_shutdown()] then it will return SXERR_LOCKED.
 * Refer to the official documentation for more information on the configuration verbs
 * and their expected parameters.
 */
#define XPP_LIB_CONFIG_USER_MALLOC            1 /* ONE ARGUMENT: const SyMemMethods *pMemMethods */ 
#define XPP_LIB_CONFIG_MEM_ERR_CALLBACK       2 /* TWO ARGUMENTS: int (*xMemError)(void *),void *pUserData */
#define XPP_LIB_CONFIG_USER_MUTEX             3 /* ONE ARGUMENT: const SyMutexMethods *pMutexMethods */ 
#define XPP_LIB_CONFIG_THREAD_LEVEL_SINGLE    4 /* NO ARGUMENTS */ 
#define XPP_LIB_CONFIG_THREAD_LEVEL_MULTI     5 /* NO ARGUMENTS */ 
/*
 * Query commands.
 * The following set of constants are the available query verbs that can be used 
 * by the host-application to query a working macro processor instance and extract
 * fields of interest.
 * These constants must be passed as the second argument to the [xpp_query()] 
 * interface.
 * Each options require a single argument which is a pointer to an unsigned
 * integer.
 * The [xpp_query()] interface will return XPP_OK on success, any other return value
 * indicates failure.
 * Refer to the official documentation for more information on the query verbs.
 */
#define XPP_TOTAL_TOKENS          1 /* ONE ARGUMENT (Pointer): unsigned int *pToken */
#define XPP_TOTAL_IGNORED         2 /* ONE ARGUMENT (Pointer): unsigned int *pToken */
#define XPP_TOTAL_LINES           3 /* ONE ARGUMENT (Pointer): unsigned int *pLines */
#define XPP_TOTAL_COMMENTS        4 /* ONE ARGUMENT (Pointer): unsigned int *pComment */
#define XPP_TOTAL_ERR             5 /* ONE ARGUMENT (Pointer): unsigned int *pErr */
#define XPP_TOTAL_USER_MACRO      6 /* ONE ARGUMENT (Pointer): unsigned int *pMacro */ 
#define XPP_TOTAL_BUILTIN_MACRO   7 /* ONE ARGUMENT (Pointer): unsigned int *pMacro */
#define XPP_TOTAL_ACTIVE_MACRO    8 /* ONE ARGUMENT (Pointer): unsigned int *pMacro */
#define XPP_TOTAL_IF_CONDITION    9 /* ONE ARGUMENT (Pointer): unsigned int *pConditionalMacro */
/*
 * Possible error codes.
 * The following set of constants are the possible errors that can occurs while expanding
 * user input.
 * To catch these errors with a human readable error message simply install an error
 * callback using the [xpp_config()] interface with a configuration verb set to
 * XPP_CONFIG_ERR_CALLBACK.
 * The error callback must have the following signature:
 *   void ErrorCallback(void *,const char *,int,int,const char *)
 * where the first argument is a pointer to the second argument to the XPP_CONFIG_ERR_CALLBACK 
 * option takes which is forwarded verbatim by the macro processor to this function.
 * The second argument is the full path of the processed file. If the processed input is 
 * a chunk of memory then this field is set to "::Memory::".
 * The third argument is one of the possible error code constants listed below.
 * The fourth argument is the line number on which the error occurs.
 * The last argument is a human readable (English) error message generated by the macro
 * processor.
 *
 * Example: Redirect all generated errors to STDOUT:
 *
 * void MyErrorCallback(void *pUserData,const char *zFilename,int nErrType,int nLine,const char *zErr)
 * {
 *    printf("%s ==> %d: %s",zFilename,nErrType,zErr);
 * }
 * 
 * xpp_config(pEngine,XPP_CONFIG_ERR_CALLBACK,MyErrorCallback,0);
 *
 * Refer to the official documentation for more information.
 */
#define XPP_ERR_UNMATCHED_ENDIF   1  /* Unmatched 'endif' directive */
#define XPP_ERR_UNMATCHED_ELSE    2  /* Unmatched 'else' directive */
#define XPP_ERR_UNMATCHED_ELIF    3  /* Unmatched 'elif' directive */
#define XPP_ERR_NESTING_LIMIT     4  /* Nesting limit reached */
#define XPP_ERR_FILE_IO           5  /* Error while opening file [i.e: Not found] using the [include], [import] or [verbatim] directive */
#define XPP_ERR_ABORT             6  /* Macro callback request an operation abort */
#define XPP_ERR_EMPTY_MACRO       7  /* Macro with no name associated with it */
#define XPP_ERR_EMPTY_ARG         8  /* Empty argument */
#define XPP_ERR_MISSING_ARG_DELIM 9  /* Missing argument delimiter */
#define XPP_ERR_UNDEFINED_MACRO   10 /* Given argument is not a registered macro */ 
#define XPP_ERR_OUT_OF_MEMORY     11 /* Out of memory */         
#define XPP_ERR_INVALID_EXPR      12 /* Syntax error while parsing expression */
#define XPP_WARNING               13 /* Warning */
/* 
 * Refer to the official documentation for interface purposes and expected parameters. 
 */ 
/* [1]:  Macro processor management interfaces */
SX_APIEXPORT int xpp_init(xpp **ppEngine);
SX_APIEXPORT int xpp_release(xpp *pEngine);
SX_APIEXPORT int xpp_reset(xpp *pEngine);

SX_APIEXPORT int xpp_query(xpp *pEngine,int nOp,...);
SX_APIEXPORT int xpp_config(xpp *pEngine,int nConfigOp,...);

SX_APIEXPORT int xpp_expand(xpp *pEngine,const char *zInput,unsigned int nLen,int iFlags);
SX_APIEXPORT int xpp_expand_file(xpp *pEngine,const char *zFilePath,int iFlags);

SX_APIEXPORT int xpp_is_registered_macro(xpp *pEngine,const char *zMacro);
SX_APIEXPORT int xpp_rename_macro(xpp *pEngine,const char *zOldName,const char *zNewName);
SX_APIEXPORT int xpp_delete_macro(xpp *pEngine,const char *zMacroName);
SX_APIEXPORT int xpp_register_macro(xpp *pEngine,const char *zMacroName,ProcMacroExpansion xMacro,void *pUserData,int iFlags);
SX_APIEXPORT int xpp_queue_macro(xpp *pEngine,const char *zMacroName,ProcMacroExpansion xMacro,void *pUserData,int iFlags);
SX_APIEXPORT int xpp_pop_macro(xpp *pEngine,const char *zMacroName);

/* [2]: Macro calling context interfaces */
SX_APIEXPORT sxi64 xpp_context_arg_to_int64(xpp_context *pCtx,const SyString *pArg);
#ifndef SX_OMIT_FLOATINGPOINT
SX_APIEXPORT double xpp_context_arg_to_real(xpp_context *pCtx,const SyString *pArg);
#endif
SX_APIEXPORT int xpp_context_arg_to_int(xpp_context *pCtx,const SyString *pArg);
SX_APIEXPORT int xpp_context_arg_trim_ws(xpp_context *pCtx,const SyString *pArg);
SX_APIEXPORT const char * xpp_context_arg_value(xpp_context *pCtx,const SyString *pArg);
SX_APIEXPORT void *xpp_context_userdata(xpp_context *pCtx);
SX_APIEXPORT void *xpp_context_peek_auxdata(xpp_context *pCtx);
SX_APIEXPORT void *xpp_context_pop_auxdata(xpp_context *pCtx);
SX_APIEXPORT int xpp_context_push_auxdata(xpp_context *pCtx,void *pAuxData);
SX_APIEXPORT int xpp_context_line(xpp_context *pCtx,unsigned int *pLine);
SX_APIEXPORT int xpp_context_macro_name(xpp_context *pCtx,SyString *pOut);
SX_APIEXPORT int xpp_context_format(xpp_context *pCtx,const char *zFormat,...);
SX_APIEXPORT int xpp_context_append(xpp_context *pCtx,const char *zData,unsigned int nLen);

/* [3]: Manual library management interfaces */
SX_APIEXPORT int xpp_lib_shutdown(void);
SX_APIEXPORT int xpp_lib_init(void);
SX_APIEXPORT int xpp_lib_config(int nConfigOp,...);
SX_APIEXPORT int xpp_lib_is_threadsafe(void);
SX_APIEXPORT const char * xpp_lib_version(void);
SX_APIEXPORT const char * xpp_lib_signature(void);
SX_APIEXPORT const char * xpp_lib_ident(void);
SX_APIEXPORT const char * xpp_lib_copyright(void);

/* [4]: Utility interfaces */
SX_APIEXPORT const char * xpp_errmsg(int rc);
SX_APIEXPORT unsigned int xpp_snprintf(char *zBuf,unsigned int nBuflen,const char *zFormat,...);
SX_APIEXPORT int xpp_random_num(void);
SX_APIEXPORT int xpp_random_string(char *zBuf,int nBuflen);
SX_APIEXPORT int xpp_eval_expr(xpp *pEngine,const char *zExpression,int *pResult);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _XPP_H_ */

/* End-of header file: <xpp.h> */

/* Symisc Standard types */
#if !defined(SYMISC_STD_TYPES)
#define SYMISC_STD_TYPES
#ifdef __WINNT__
/* Disable nuisance warnings on Borland compilers */
#if defined(__BORLANDC__)
#pragma warn -rch /* unreachable code */
#pragma warn -ccc /* Condition is always true or false */
#pragma warn -aus /* Assigned value is never used */
#pragma warn -csu /* Comparing signed and unsigned */
#pragma warn -spa /* Suspicious pointer arithmetic */
#endif/* Disable nuisance warnings on Borland compilers */
#endif
typedef signed char   sxi8; /* signed char */
typedef unsigned char sxu8; /* unsigned char */
typedef signed short int   sxi16; /* 16 bits(2 bytes) signed integer */
typedef unsigned short int sxu16; /* 16 bits(2 bytes) unsigned integer */
typedef int               sxi32; /* 32 bits(4 bytes) integer */
typedef unsigned int      sxu32; /* 32 bits(4 bytes) unsigned integer */
typedef signed long int   sxssize;
typedef unsigned long int sxsize;
typedef long              sxptr;
typedef unsigned long     sxuptr;
typedef long              sxlong;
typedef unsigned long     sxulong;
typedef sxi32             sxofft;
typedef sxi64             sxofft64;
#if !defined(SX_OMIT_FLOATINGPOINT)
typedef long double	     sxlongreal;
typedef double           sxreal;
#endif /* SX_OMIT_FLOATINGPOINT */
#define SXI8_HIGH       0x7F
#define SXU8_HIGH       0xFF
#define SXI16_HIGH      0x7FFF
#define SXU16_HIGH      0xFFFF
#define SXI32_HIGH      0x7FFFFFFF
#define SXU32_HIGH      0xFFFFFFFF
#define SXI64_HIGH      0x7FFFFFFFFFFFFFFF
#define SXU64_HIGH      0xFFFFFFFFFFFFFFFF 
#if !defined(TRUE)
#define TRUE 1
#endif
#if !defined(FALSE)
#define FALSE 0
#endif
/*
 * The following macros are used to cast pointers to integers and
 * integers to pointers.
 */
#if defined(__PTRDIFF_TYPE__)  
# define SX_INT_TO_PTR(X)  ((void*)(__PTRDIFF_TYPE__)(X))
# define SX_PTR_TO_INT(X)  ((int)(__PTRDIFF_TYPE__)(X))
#elif !defined(__GNUC__)    
# define SX_INT_TO_PTR(X)  ((void*)&((char*)0)[X])
# define SX_PTR_TO_INT(X)  ((int)(((char*)X)-(char*)0))
#else                       
# define SX_INT_TO_PTR(X)  ((void*)(X))
# define SX_PTR_TO_INT(X)  ((int)(X))
#endif
#define SXMIN(a,b)  ((a < b) ? (a) : (b))
#define SXMAX(a,b)  ((a < b) ? (b) : (a))
#endif /* SYMISC_STD_TYPES */
/* Symisc Run-time API private definitions */
#if !defined(SYMISC_PRIVATE_DEFS)
#define SYMISC_PRIVATE_DEFS

typedef sxi32 (*ProcRawStrCmp)(const SyString *,const SyString *);
#define SyStringData(RAW)	((RAW)->zString)
#define SyStringLength(RAW)	((RAW)->nByte)
#define SyStringInitFromBuf(RAW,ZBUF,NLEN){\
	(RAW)->zString 	= (const char *)ZBUF;\
	(RAW)->nByte	= (sxu32)(NLEN);\
}
#define SyStringUpdatePtr(RAW,NBYTES){\
	if( NBYTES > (RAW)->nByte ){\
		(RAW)->nByte = 0;\
	}else{\
		(RAW)->zString += NBYTES;\
		(RAW)->nByte -= NBYTES;\
	}\
}
#define SyStringDupPtr(RAW1,RAW2)\
	(RAW1)->zString = (RAW2)->zString;\
	(RAW1)->nByte = (RAW2)->nByte;

#define SyStringTrimLeadingChar(RAW,CHAR)\
	while((RAW)->nByte > 0 && (RAW)->zString[0] == CHAR ){\
			(RAW)->zString++;\
			(RAW)->nByte--;\
	}
#define SyStringTrimTrailingChar(RAW,CHAR)\
	while((RAW)->nByte > 0 && (RAW)->zString[(RAW)->nByte - 1] == CHAR){\
		(RAW)->nByte--;\
	}
#define SyStringCmp(RAW1,RAW2,xCMP)\
	(((RAW1)->nByte == (RAW2)->nByte) ? xCMP((RAW1)->zString,(RAW2)->zString,(RAW2)->nByte) : (sxi32)((RAW1)->nByte - (RAW2)->nByte))

#define SyStringCmp2(RAW1,RAW2,xCMP)\
	(((RAW1)->nByte >= (RAW2)->nByte) ? xCMP((RAW1)->zString,(RAW2)->zString,(RAW2)->nByte) : (sxi32)((RAW2)->nByte - (RAW1)->nByte))

#define SyStringCharCmp(RAW,CHAR) \
	(((RAW)->nByte == sizeof(char)) ? ((RAW)->zString[0] == CHAR ? 0 : CHAR - (RAW)->zString[0]) : ((RAW)->zString[0] == CHAR ? 0 : (RAW)->nByte - sizeof(char)))

#define SX_ADDR(PTR)    ((sxptr)PTR)
#define SX_ARRAYSIZE(X) (sizeof(X)/sizeof(X[0]))
#define SXUNUSED(P)	(P = 0)
#define	SX_EMPTY(PTR)   (PTR == 0)
#define SX_EMPTY_STR(STR) (STR == 0 || STR[0] == 0 )
typedef struct SyMemBackend SyMemBackend;
typedef struct SyBlob SyBlob;
typedef struct SySet SySet;
/* Standard function signatures */
typedef sxi32 (*ProcCmp)(const void *,const void *,sxsize);
typedef sxi32 (*ProcPatternMatch)(const char *,sxsize,const char *,sxsize,sxu32 *);
typedef sxi32 (*ProcSearch)(const void *,sxsize,const void *,sxsize,ProcCmp,sxu32 *);
typedef sxu32 (*ProcHash)(const void *,sxsize);
typedef sxi32 (*ProcHashSum)(const void *,sxsize,unsigned char *,sxu32);
typedef sxi32 (*ProcSort)(void *,sxsize,sxsize,ProcCmp);
#define MACRO_LIST_PUSH(Head,Item)\
	Item->pNext = Head;\
	Head = Item; 
#define MACRO_LD_PUSH(Head,Item)\
	if( Head == 0 ){\
		Head = Item;\
	}else{\
		Item->pNext = Head;\
		Head->pPrev = Item;\
		Head = Item;\
	}
#define MACRO_LD_REMOVE(Head,Item)\
	if( Head == Item ){\
		Head = Head->pNext;\
	}\
	if( Item->pPrev ){ Item->pPrev->pNext = Item->pNext;}\
	if( Item->pNext ){ Item->pNext->pPrev = Item->pPrev;}
/*
 * A generic dynamic set.
 */
struct SySet
{
	SyMemBackend *pAllocator; /* Memory backend */
	void *pBase;              /* Base pointer */	
	sxu32 nUsed;              /* Total number of used slots  */
	sxu32 nSize;              /* Total number of available slots */
	sxu32 eSize;              /* Size of a single slot */
	sxu32 nCursor;	          /* Loop cursor */	
};
#define SySetBasePtr(S)           ((S)->pBase)
#define SySetBasePtrJump(S,OFFT)  (&((char *)(S)->pBase)[OFFT*(S)->eSize])
#define SySetUsed(S)              ((S)->nUsed)
#define SySetSize(S)              ((S)->nSize)
#define SySetElemSize(S)          ((S)->eSize) 
#define SySetGetAllocator(S)      ((S)->pAllocator)
/*
 * A variable length containers for generic data.
 */
struct SyBlob
{
	SyMemBackend *pAllocator; /* Memory backend */
	void    *pBlob;	          /* Base pointer */
	sxsize  nByte;	          /* Total number of used bytes */
	sxsize  mByte;	          /* Total number of available bytes */
	sxu32   nFlags;	          /* Blob internal flags,see below */
};
#define SXBLOB_LOCKED	0x01	/* Blob is locked; cannot grow */
#define SXBLOB_STATIC	0x02	/* Not allocated from heap   */

#define SyBlobFreeSpace(BLOB)	 ((BLOB)->mByte - (BLOB)->nByte)
#define SyBlobLength(BLOB)	     ((BLOB)->nByte)
#define SyBlobData(BLOB)	     ((BLOB)->pBlob)
#define SyBlobCurData(BLOB)	     ((void*)(&((char*)(BLOB)->pBlob)[(BLOB)->nByte]))
#define SyBlobDataAt(BLOB,OFFT)	 ((void *)(&((char *)(BLOB)->pBlob)[OFFT]))
#define SyBlobGetAllocator(BLOB) ((BLOB)->pAllocator)

#define SXMEM_POOL_INCR			3
#define SXMEM_POOL_NBUCKETS		12
#define SXMEM_BACKEND_MAGIC	0xBAC3E67D
#define SXMEM_BACKEND_CORRUPT(BACKEND)	(BACKEND == 0 || BACKEND->nMagic != SXMEM_BACKEND_MAGIC)

#define SXMEM_BACKEND_RETRY	3
/* A memory backend subsystem is defined by an instance of the following structures */
typedef union SyMemHeader SyMemHeader;
typedef struct SyMemBlock SyMemBlock;
struct SyMemBlock
{
	SyMemBlock *pNext,*pPrev; /* Chain of allocated memory blocks */
	sxu32 nGuard;             /* magic number associated with each valid block,so we
							   * can detect misuse.
							   */
};
/*
 * Header associated with each valid memory pool block.
 */
union SyMemHeader
{
	SyMemHeader *pNext; /* Next chunk of size 1 << (nBucket + SXMEM_POOL_INCR) in the list */
	sxu32 nBucket;      /* Bucket index in aPool[] */
};
struct SyMemBackend
{
	const SyMutexMethods *pMutexMethods; /* Mutex methods */
	const SyMemMethods *pMethods;  /* Memory allocation methods */
	SyMemBlock *pBlocks;           /* List of valid memory blocks */
	sxu32 nBlock;                  /* Total number of memory blocks allocated so far */
	ProcMemError xMemError;        /* Out-of memory callback */
	void *pUserData;               /* First arg to xMemError() */
	SyMutex *pMutex;               /* Per instance mutex */
	sxu32 nMagic;                  /* Sanity check against misuse */
	SyMemHeader *apPool[SXMEM_POOL_NBUCKETS+SXMEM_POOL_INCR]; /* Pool of memory chunks */
};
/* Mutex types */
#define SXMUTEX_TYPE_FAST	1
#define SXMUTEX_TYPE_RECURSIVE	2
#define SXMUTEX_TYPE_STATIC_1	3
#define SXMUTEX_TYPE_STATIC_2	4
#define SXMUTEX_TYPE_STATIC_3	5
#define SXMUTEX_TYPE_STATIC_4	6
#define SXMUTEX_TYPE_STATIC_5	7
#define SXMUTEX_TYPE_STATIC_6	8

#define SyMutexGlobalInit(METHOD){\
	if( (METHOD)->xGlobalInit ){\
	(METHOD)->xGlobalInit();\
	}\
}
#define SyMutexGlobalRelease(METHOD){\
	if( (METHOD)->xGlobalRelease ){\
	(METHOD)->xGlobalRelease();\
	}\
}
#define SyMutexNew(METHOD,TYPE)			(METHOD)->xNew(TYPE)
#define SyMutexRelease(METHOD,MUTEX){\
	if( MUTEX && (METHOD)->xRelease ){\
		(METHOD)->xRelease(MUTEX);\
	}\
}
#define SyMutexEnter(METHOD,MUTEX){\
	if( MUTEX ){\
	(METHOD)->xEnter(MUTEX);\
	}\
}
#define SyMutexTryEnter(METHOD,MUTEX){\
	if( MUTEX && (METHOD)->xTryEnter ){\
	(METHOD)->xTryEnter(MUTEX);\
	}\
}
#define SyMutexLeave(METHOD,MUTEX){\
	if( MUTEX ){\
	(METHOD)->xLeave(MUTEX);\
	}\
}
/* Comparison,byte swap,byte copy macros */
#define SX_MACRO_FAST_CMP(X1,X2,SIZE,RC){\
	register unsigned char *r1 = (unsigned char *)X1;\
	register unsigned char *r2 = (unsigned char *)X2;\
	register sxsize LEN = SIZE;\
	for(;;){\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	}\
	RC = !LEN ? 0 : r1[0] - r2[0];\
}
#define	SX_MACRO_FAST_MEMCPY(SRC,DST,SIZ){\
	register unsigned char *xSrc = (unsigned char *)SRC;\
	register unsigned char *xDst = (unsigned char *)DST;\
	register sxsize xLen = SIZ;\
	for(;;){\
	    if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
		if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
		if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
		if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
	}\
}
#define SX_MACRO_BYTE_SWAP(X,Y,Z){\
	register unsigned char *s = (unsigned char *)X;\
	register unsigned char *d = (unsigned char *)Y;\
	sxsize	ZLong = Z;  \
	sxi32 c; \
	for(;;){\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	}\
}
#endif /* SYMISC_PRIVATE_DEFS */

/* Symisc Run-time API auxiliary definitions */
#if !defined(SYMISC_PRIVATE_AUX_DEFS)
#define SYMISC_PRIVATE_AUX_DEFS

typedef struct SyHashEntry_Pr SyHashEntry_Pr;
typedef struct SyHashEntry SyHashEntry;
typedef struct SyHash SyHash;
/*
 * Each public hashtable entry is represented by an instance
 * of the following structure.
 */
struct SyHashEntry
{
	const void *pKey; /* Hash key */
	sxu32 nKeyLen;    /* Key length */
	void *pUserData;  /* User private data */
};
#define SyHashEntryGetUserData(ENTRY) ((ENTRY)->pUserData)
#define SyHashEntryGetKey(ENTRY)      ((ENTRY)->pKey)
/* Each hashtable is identified by an instance of the following structure */
struct SyHash
{
	SyMemBackend *pAllocator;         /* Memory backend */
	ProcHash xHash;                   /* Hash function */
	ProcCmp xCmp;                     /* Comparison function */
	SyHashEntry_Pr *pList,*pCurrent;  /* Linked list of hash entries user for linear traversal */
	sxu32 nEntry;                     /* Total number of entries */
	SyHashEntry_Pr **apBucket;        /* Hash buckets */
	sxu32 nBucketSize;                /* Current bucket size */
};
#define SXHASH_BUCKET_SIZE 128 /* Initial bucket size: must be a power of two */
#define SXHASH_FILL_FACTOR 3
/* Hash access macro */
#define SyHashFunc(HASH)		((HASH)->xHash)
#define SyHashCmpFunc(HASH)		((HASH)->xCmp)
#define SyHashTotalEntry(HASH)	((HASH)->nEntry)
#define SyHashGetPool(HASH)		((HASH)->pAllocator)

typedef struct SyRC4Ctx	SyRC4Ctx;
typedef struct SyMD5 SyMD5;
/*
 * An instance of the following structure define a single context
 * for an RC4 Pseudo Random Number Generator.
 *
 * Nothing in this file or anywhere else in the library does any kind of
 * encryption.The RC4 algorithm is being used as a PRNG (pseudo-random
 * number generator) not as an encryption device.
 */
struct SyRC4Ctx
{
    sxu8 i,j;               /* State variables */
    unsigned char s[256];   /* State variables */
	sxu16 nMagic;           /* Sanity check */
 };
typedef sxi32 (*ProcRandomSeed)(void *pSeed,sxsize nSeedLen,void *);
#define SX_MD5_BINSZ	16
#define SX_MD5_HEXSZ	32
/* MD5 context */
struct SyMD5 {
 sxu32 buf[4];
 sxu32 bits[2];
 unsigned char in[64];
};
#endif /* SYMISC_PRIVATE_AUX_DEFS */
/* Rely on the standard ctype */
#include <ctype.h>

#define SyToUpper(c) toupper(c)
#define SyToLower(c) tolower(c)

#define SyisUpper(c) isupper(c)
#define SyisLower(c) islower(c)
#define SyisSpace(c) isspace(c)
#define SyisAlpha(c) isalpha(c)
#define SyisDigit(c) isdigit(c)
#define SyisHex(c)	 isxdigit(c)
#define SyisAlphaNum(c) isalnum(c)
#define SyCharToLower(c)  (SyisUpper(c)? SyToLower(c) : c)

#define SyStringLeftTrim(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0 && SyisSpace((RAW)->zString[0])){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}

#define SyStringRightTrim(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && SyisSpace((RAW)->zString[(RAW)->nByte - 1])){\
		(RAW)->nByte--;\
	}

#define SyStringFullTrim(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0  && SyisSpace((RAW)->zString[0])){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && SyisSpace((RAW)->zString[(RAW)->nByte - 1])){\
		(RAW)->nByte--;\
	}
/* Forward declaration */
typedef struct SyStream SyStream;
typedef struct SyToken  SyToken;
typedef struct SyLex    SyLex;
/*
 * Tokenizer callback signature.
 */
typedef sxi32 (*ProcTokenizer)(SyStream *,SyToken *,void *,void *);
/*
 * Each token in the input is represented by an instance
 * of the following structure.
 */
struct SyToken
{
	SyString sData;  /* Token text and length */
	sxu32 nType;     /* Token type */
	sxu32 nLine;     /* Token line number */
	void *pUserData; /* User private data associated with this token */
};
/*
 * During tokenization, information about the state of the input
 * stream is held in an instance of the following structure.
 */
struct SyStream
{
	const unsigned char *zInput; /* Complete text of the input */
	const unsigned char *zText; /* Current input we are processing */	
	const unsigned char *zEnd; /* End of input marker */
	sxu32  nLine; /* Total number of processed lines */
	sxu32  nIgn; /* Total number of ignored tokens */
	SySet *pSet; /* Token containers */
};
/*
 * Each lexer is represented by an instance of the following structure.
 */
struct SyLex
{
	SyStream sStream;         /* Input stream */
	ProcTokenizer xTokenizer; /* Tokenizer callback */
	void * pUserData;         /* Third argument to xTokenizer() */
	SySet *pTokenSet;         /* Token set */
};
#define SyLexTotalToken(LEX)  SySetUsed(&(LEX)->aTokenSet)
#define SyLexTotalLines(LEX)    ((LEX)->sStream.nLine)
#define SyLexTotalIgnored(LEX)  ((LEX)->sStream.nIgn)
/*
 * forward references to private structures.
 */
typedef struct SyCondDirective SyCondDirective;
typedef struct SyMacroDefs SyMacroDefs;
typedef struct SyMacroArg  SyMacroArg;
typedef struct SyMacro     SyMacro;
/*
 * Each inline macro (user defined) definition is parsed out and stored in an
 * instance of the following structure.
 * Macro definitions come in two forms:
 * Object like macros and functions like macros.
 * An object-like macro is a macro that does not takes arguments.
 * Example of object-like macros:
 * define PI 3.14
 * define WHO No Body
 * A function-like macro is a macro that takes arguments.
 * Example of function-like macros:
 * macro max(a,b) 
 *  if a < b 
 *     b
 *  else
 *    a
 *  endif
 * endef
 * or
 * macro max()  
 *  if $1 < $2 //M4 style
 *    $2
 *  else
 *    $1
 *  endif
 * endef
 * Note:
 *  You can mix M4 and C preprocessor argument processing style
 * Note:
 *  In this implementation function-like macros arguments can have 
 *  default values associated with them.
 * Example:
 *  macro min(a=10,b=50)
 *    if a < b
 *      a
 *    else
 *     b
 *    endif
 *  endef
 * Now:
 *  min(500,200) will expand to 200
 *  min(500) will expand to 50
 *  min() will expand to 10
 */
struct SyMacroDefs
{
   xpp *pEngine;        /* Preprocessor that own this instance */
   SyString sName;      /* Name of the parsed macro */
   SySet aBody;         /* Macro body (SyToken instances) */
   SyCondDirective *pCond;  /* If not null then we are within an [if],[elif],[ifdef] or [ifndef] directive */
   int iFlags;          /* One or more options flags */
   SySet aArgs;         /* Macro arguments (SyMacroArg instances).Apply only to function like macros */
   sxu32 nLine;         /* Line at which this macro is defined */
};
struct SyMacroArg
{
	SyString sName;      /* Argument name */
	SyString sDefValue;  /* Argument default value if available */
	sxu32 nIndex;        /* Index of this entry in the arg table */
};
/*
 * Each registered (user defined or host-application defined via public API) macro
 * is recorded in an instance of the following structure.
 * The preprocessor hashtable return an instance of this structure when the
 * given key is a registered macro.
 * Some of the registered macro are: DATE,OS,LINE,MD5,BASE64,CRC32...
 * Refer to [xpp_register_macro()],[xpp_queue_macro()],[xpp_pop_macro()]
 * [xpp_rename_macro()] or [xpp_delete_macro()] interfaces for more information
 * on how macro definition are handled internally.
 */
struct SyMacro
{
	ProcMacroExpansion xMacro; /* C function implementing macro body */
	void *pUserData;           /* xMacro() Private data,a pointer to this field is returned 
							    * via a call to the [xpp_context_userdata()] interface.*/
	sxi32 iFlags;              /* One or more options flags */
	SySet aAuxData;            /* Containers for auxiliary data (SyAuxData instances) associated with the macro definition.
							    * Refer to [xpp_context_push_auxdata()] and [xpp_context_peek_auxdata()]
								* for more information.
								*/
};
/*
 * Auxiliary data associated with a given macro definition are stored
 * in an instance of the following structure.
 */
typedef struct SyAuxData SyAuxData;
struct SyAuxData
{
	void *pAuxData; /* Aux data */
};
/* Private macro flags (apply to the 'iFlags' field member of the 'SyMacro' structure) */
#define USER_MACRO_NEST          0x800 /* Nested macro definition */
/*
 * Macro calling context is represented by an instance of the following structure.
 * This context is passed as the first argument to the C function that
 * implement the macro body.
 * The C function must have the following signature:
 *		int (*ProcMacroExpansion)(xpp_context *,int,const SyString *)
 * Where the first argument is a pointer to an instance of this structure and 
 * the last two arguments are the arguments of a function like macro.
 * This structure is filled by the preprocessor when it encounter a registered macro.
 * This structure hold the result of the expansion after the C function of the 
 * target macro have been called.
 * The C function (Actually the callback) expand its body via calls to the
 * [xpp_context_append()] or [xpp_context_format()] interfaces.
 * This process is best illustrated with an example:
 * Register a function that implement the TIME macro:
 * #include <time.h>
 * int Time_Macro_Callback(xpp_context *pCtx,int nArg,const SyString *azArg)
 * {
 *   strut tm *pGm = gmtime(time(NULL)); //Get the current time (GMT) 
 *   //Expand the result
 *   xpp_context_format(pCtx,"%02d:%02d:%02d GMT",pGm->tm_hour,pGm->tm_min,pGm->tm_sec);
 *   //Tell the preprocessor that everything is OK
 *   return XPP_OK;
 * }
 * The next step is to register the C function above and associate it with the TIME
 * keyword.This can be done via calls to [xpp_register_macro()] or [xpp_queue_macro()]
 * interfaces as follows:
 *  xpp_register_macro(pEngine,"TIME",Time_Macro_Callback,0,USER_MACRO_STRICT_INVOKE);
 * where the first argument is an instance of the xPP preprocessor,the second
 * argument is the name of the desired macro,the third argument is the C function that
 * implement the macro body,the fourth argument is an arbitrary pointer (callback private
 * data) which is forwarded verbatim by the preprocessor and can be extracted via
 * a call to the [xpp_context_userdata()] interface and the last argument is zero or
 * more options flags that drive the macro invocation process.
 * After the registration process,each time the 'TIME' keyword is seen the associated
 * callback [Time_Macro_Callback()] is invoked by the preprocessor.
 * For more information on the macro invocation process and the associated interfaces
 * refer to the official documentation section API references.
 */
struct xpp_context
{
	xpp *pEngine;     /* Preprocessor that own this context */
	SyMacro *pMacro;  /* Internal representation of the invoked macro */
	SyBlob sBlob;     /* Working buffer that hold the output of the [xpp_context_format()] interface */ 
	SyString sName;   /* Name of the invoked macro */ 
	sxu32 nLine;      /* Line at which the keyword (macro name) was seen */
	ProcConsumer xConsumer; /* Redirect all the expanded body to this callback */
	sxi32 iFlags;           /* Control flags */  
	sxi32 rc;               /* Consumer return value */
	void *pConsumerData;    /* xConsumer() private data,passed as the last argument */
};
/* xPP context control flags */
#define XPP_CTX_CONS_ABORT 0x01 /* Consumer routine request an operation abort */
/* 
 * Each conditional directive is parsed out and stored in an instance of the following
 * structure.
 * When an if,ifdef,ifndef or elif directive is encountered,the preprocessor associate
 * with that token an instance of the following structure.
 * This structure holds everything we need to know about the condition that will be
 * evaluated shortly.
 * All defined macros in the block surrounded by one of those directives are stored
 * in the aDefs array member of this structure and are registered later using the 
 * [xpp_queue_macro()] interface when the condition evaluates to true.
 * Each conditional block must start with an if,ifdef or ifndef directive and
 * must end with the endif directive.
 * The implementers have chosen to follow the C preprocessor model rather than
 * the M4 model because it avoid the cryptic style the M4 macro processor uses
 * for its conditional macros.
 * A conditional block can take the following form:
 * ifdef 'macro_name'*
 *    Block will be processed when the 'macro_name'(one or more) are defined
 * endif
 * ifndef 'macro_name'*
 *   Block will be processed when the 'macro_name'(one or more) are not defined
 * endif
 * if 'condition'
 *  Block will be processed when the condition evaluates to true
 * [elif 'condition']
 *  Elif block will be processed when the condition evaluates to true and 
 *  the previous if block evaluate to false.
 * endif
 * Example:
 * ifdef MD5 BASE64 CRC32
 *   MD5,BASE64,CRC32 are defined 
 * else
 *   MD5,BASE64,CRC32 built-in macros are not defined
 * endif
 * ifndef __UNIX__
 *   We are running in a non unix environment
 * endif
 * define file /usr/local/www/httpd.conf
 * if defined(FILE_EXISTS) && FILE_EXISTS(file) && defined(FILE_SIZE)
 *     Size of file = FILE_SIZE(file)
 * endif
 * Note that 'FILE_EXISTS' is a built-in macro that return 1(TRUE) if
 * the given file path exists on disk and 0(FALSE) otherwise.
 * Also 'FILE_SIZE' is a built-in macro that return the size (64-bit) integer
 * of the given file.
 * For more information on the built-in macros,refer to the official
 * documentation section 'built-in macros'.
 */
struct SyCondDirective
{
	SySet aToken;              /* Tokenized text of the condition [SyString instance] */ 
	SySet aDefs;               /* Macro defined in the 'if','ifdef','ifndef' and 'elif' block */
	SySet aElseDefs;           /* Macro defined in the 'else' block */
	ProcMacroExpansion xEval;  /* C function that will evaluate the condition.
							    * This callback must return SXERR_IGNORE when the condition evaluate to false.
								* Any other value indicate that the condition evaluate to true and the target
								* block is processed.*/
	SyCondDirective *pNextDown;     /* Next down in the stack of nested conditional directive */
	SyCondDirective *pNext;         /* Linked list of conditional directive */
	sxi32 iFlags;               /* One or more options flags */
	sxu32 nType;                /* Directive type.Either 'ifdef','ifndef','elif' or 'if' directive */
};
/* Conditional directive flags (apply to the 'iFlags' field member of the 'SyCondDirective' structure) */
#define XPP_COND_ELSE_CTX 0x0001 /* Switch to the else block */
/*
 * All preprocessor configuration parameters are collected and recorded
 * in an instance of the following structure.
 */
typedef struct xpp_conf xpp_conf;
struct xpp_conf
{
	SySet aStrings;           /* String delimiters set (left and right delimiters)
							   * To register a pair of string delimiter call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_STRING_DELIMITER.
							   * Example:
							   *   xpp_config(pEngine,XPP_CONFIG_STRING_DELIMITER,"\"","\""); //C strings
							   */
	SySet aComment;           /* Comments delimiters set (left and right delimiters) [i.e: //,\n ==> C++ style]
							   * To register a pair of comment delimiter call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_COMMENT.
							   * Example: inline comments
							   *  xpp_config(pEngine,XPP_CONFIG_COMMENT,"//","\n"); //C++ comments
							   *  xpp_config(pEngine,XPP_CONFIG_COMMENT,"#","\n"); //Perl comments
							   */
	SyString aArgDelim[2];    /* Arguments delimiter [default: "(" , ")"]
							   * To override the default values call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_ARG_DELIMITER.
							   */
	SyString sArgSep;         /* Arguments separator [default: ","]
							   * To override the default values call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_ARG_SEPARATOR.
							   */
	SyString sConcat;         /* Concatenation operator [default: ##]
							   * To override the default values call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_CONCAT.
							   */
	SyString sStringify;      /* Stringing operator
							   * To register a stringing operator call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_STRINGING_OPERATOR.
							   */
	SySet aPaths;             /* Include,verbatim,import root paths 
							   * To register an import path call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_IMPORT_PATH.
							   * Example:
							   *   xpp_config(pEngine,XPP_CONFIG_IMPORT_PATH,"/usr/include");
							   *   xpp_config(pEngine,XPP_CONFIG_IMPORT_PATH,"/usr/local/include");
							   */
	SyString sPrefix;         /* Macro prefix [i.e: "#" to emulate the C preprocessor] default: NULL
							   * To register a macro prefix call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_MACRO_PREFIX.
							   */
	SySet aIdent;             /* Macro keyword set [default: define,macro]
							   * To register a macro keyword call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_MACRO_KEYWORD.
							   * Example:
							   *   xpp_config(pEngine,XPP_CONFIG_MACRO_KEYWORD,"define","\n"); //Emulate the C preprocessor
							   *   xpp_config(pEngine,XPP_CONFIG_MACRO_KEYWORD,"macro","endef");
							   * Now macro can be defined as follows:
							   *  define PI 3.14
							   *  define MIN() \
							   *       ($1 < $2 ? $1 : $2)
							   *  macro MAX(A,B)
							   *        A < B ? B : A
							   *  endef
							   */ 
	sxi32 nNest;              /* Nesting limit (default: 128)
							   * To override the default limit call the [xpp_config()] interface
							   * with a configuration verb set to XPP_CONFIG_NESTING_LIMT
							   */
	void **ppBufer;           /* If not null,let this pointer point to the output buffer */ 
	sxu32 *pOutlen;           /* Length of the expanded input */
	/* Parser state variables */
	SyCondDirective *pCond;  /* Stack(LIFO) of conditional macro (if,ifdef,ifndef,elif) collected so far */
	sxu8 bLF;                /* TRUE if the last recognized token is the new line '\n' */
	sxu8 bQuoted;            /* TRUE to expand some of the built-in macros in quotes */
	sxu8 bLastwasPrefix;     /* TRUE if the last non alphanumeric (garbage) token was a macro prefix
							  * [i.e '#' if you try to emulate the C preprocessor].
							  * This option is always TRUE if there is no installed macro prefix
							  * (Default configuration).*/
	char zErr[256];          /* Save error messages in this buffer */
	SySet aFiles;            /* Stack of processed file names */
};
/* Signature of the error callback */
typedef void (*ProcMacroErr)(void *,const char *,int,int,const char *);
/* Signature of the trace callback */
typedef int (*ProcMacroTrace)(void *,const char *,const char *,int,int,const SyString *);
/*
 * xPP macro processor is represented by an instance of the following structure.
 * The most important fields in this structure are the 'hMacro' field which
 * is the hashtable were are all the user defined and built-in macros are
 * registered.This hashtable is queried by the macro processor each time
 * an alphanumeric or UTF-8 stream is extracted, when the given key
 * resolve to a registered macro then an instance of the 'SyMacro' structure
 * is returned and the processor invoke the callback associated with it.
 * The second field of interest if the xConsumer() field,which is a pointer
 * to a defined function.Each time a token is extracted or expanded,this
 * callback is invoked by the macro processor in order to consume the
 * processed tokens.This function can be set by the host application using
 * the [xpp_config()] interface with a configuration verb set to XPP_CONFIG_OUTPUT_CONSUMER.
 * In some situation when a macro expand to another macro,then this field
 * is set to point to an internal function that will handle the recursion scenario.
 *
 * Example: Redirect all expanded input to STDOUT
 * int ConsumeExpandedInput(const void *pOut,unsigned int nLen,void *pUserData)
 * {
 *    const char *zOut = (const char *)pOut;
 *    //Consume the expanded chunk
 *    printf("%.*s",nLen,zOut);
 *    return XPP_OK;
 * }
 * Register the function above
 *  xpp_config(pEngine,XPP_CONFIG_OUTPUT_CONSUMER,ConsumeExpandedInput,NULL);
 * After this statement each time a token is processed,the above routine
 * is invoked in order to consume the expanded token.
 * The last field of interest is the 'sAllocator' field which is the low
 * level memory allocator from which all dynamic memory is allocated.
 */
struct xpp
{
	SyMemBackend sAllocator;   /* Low level memory allocator */
	xpp_conf sConfig;          /* Preprocessor configuration parameters */
	SyBlob sConsumer;          /* Working buffer (intermediate input consumer) */
	SyHash hMacro;             /* Container (hashtable) for registered macros  */
	sxi32 iFlags;              /* One or more options flags */
	SySet aToken;              /* All collected tokens waiting for processing (SyToken * instances) */
	ProcConsumer xConsumer;    /* Consumer of the expanded input */
	void *pConsumerData;       /* Consumer private data (last argument to xConsumer()) */
#if defined(XPP_ENABLE_THREADS)
	const SyMutexMethods *pMethods;  /* Mutex methods */
	SyMutex *pMutex;                 /* Per-preprocessor mutex */
#endif
	ProcMacroTrace xTrace;     /* If not null,invoke the trace callback each time a macro in expanded.
							    * This callback can be registered using the [xpp_config()] interface with a 
								* configuration verb set to XPP_CONFIG_TRACE_CALLBACK 
								*/
	void *pTraceData;          /* First argument to xTrace() */
	ProcMacroErr xErr;         /* If not null,invoke this error callback when an error is detected
							    * [i.e: unmatched endif..].
								* This callback can be registered using the [xpp_config()] interface with a 
								* configuration verb set to XPP_CONFIG_ERR_CALLBACK.
								*/
	void *pErrData;             /* First argument to xErr() */
	sxu32 nUserMacro;           /* Total number of user defined macro collected so far (used for statistics purposes) */
	SyCondDirective *pCond;     /* List of collected conditional macros */
	sxu32 nCond;                /* Total number of collected conditional macros */
	SySet *pImportDB;           /* Import Database */
	sxi32 nNest;                /* Current nesting level */
	sxu32 nLines;               /* Total number of processed lines (used for statistics purposes) */
	sxu32 nIgn;                 /* Total number of ignored tokens (used for statistics purposes) */
	sxu32 nComment;             /* Total number of collected comments (used for statistics purposes) */
	sxu32 nErr;                 /* Total number of error seen */
	xpp *pNext,*pPrev;          /* Next and previous active macro processor */
	sxu32 nMagic;               /* Sanity check against misuse */
};
#define XPP_ENGINE_MAGIC_INIT 0xF78A65BC
#define XPP_ENGINE_CORRUPT(ENGINE) (ENGINE == 0 || (ENGINE)->nMagic != XPP_ENGINE_MAGIC_INIT)
/* Argument separator boundary.
 * WARNING: THIS FIELD MUST BE UNIQUE.
 */
#ifndef XPP_ARG_BOUNDARY
#define XPP_ARG_BOUNDARY "--xPP-A1G-BO7NdA8Y-261432--"
#endif
/* 
 * Major token types.
 * Note that all tokens values are a power of two,this is a very important details
 * and must not change!!
 */
#define XPP_TK_SPACE       0x000001 /* White spaces */
#define XPP_TK_LF          0x000002 /* LF: Line Feed ['\n'] or CRLF ['\r\n'] on windows systems */
#define XPP_TK_COMMENT     0x000004 /* Comments */
#define XPP_TK_DIRECTIVE   0x000008 /* Raw macro directive (not yet processed) */
#define XPP_TK_GARBAGE     0x000010 /* Garbage token (non-alphanumeric stream) */
#define XPP_TK_RAW         0x000020 /* Raw text not yet processed (alphanumeric or UTF-8 stream) */
#define XPP_TK_IF          0x000040 /* Conditional macro directive [if] */
#define XPP_TK_IFDEF       0x000080 /* Conditional macro directive [ifdef] */
#define XPP_TK_IFNDEF      0x000100 /* Conditional macro directive [ifndef] */
#define XPP_TK_ELSE        0x000200 /* Conditional macro directive [else] */
#define XPP_TK_ELIF        0x000400 /* Conditional macro directive [elif] */
#define XPP_TK_ENDIF       0x000800 /* Conditional macro directive [endif] */
/* Level three (macro expanding) tokens */
#define XPP_TK_FORMAL_ARG   0x001000 /* Formal argument waiting for expanding */
#define XPP_TK_M4_HASH      0x002000 /* M4 arg style: $#: Expands to the number of given arguments */
#define XPP_TK_M4_NAME      0x004000 /* M4 arg style: $0: Expands to the macro name */
#define XPP_TK_M4_ARG_LIST  0x008000 /* M4 arg style: $*: Expands to the list of arguments */
#define XPP_TK_M4_ARG_LIST2 0x010000 /* M4 arg style: $@: Expands to the list of arguments (quoted) */
/* Token introduced in the version 2 of xPP */
#define XPP_TK_ARG_START    0x020000 /* Left  argument delimiter [default: '('] */
#define XPP_TK_ARG_END      0x040000 /* Right argument delimiter [default: ')'] */
#define XPP_TK_ARG_SEP      0x080000 /* Argument separator [default: ','] */
/* Level two (macro processing) tokens */
#define XPP_TK_STRINGING    0x100000  /* Stringing operator */
#define XPP_TK_VAARG        0x200000  /* __VAARGS__ operator */
#define XPP_TK_STRING       0x400000  /* Constant literal string */
/* Combined token class */
#define XPP_TK_COND (XPP_TK_IF|XPP_TK_IFDEF|XPP_TK_IFNDEF|XPP_TK_ELSE|XPP_TK_ELIF|XPP_TK_ENDIF)

/* IMPLEMENTATION: xpp@embedded@symisc 310-19-46 */

/*
 * All global variables are collected in the structure named "sMPGlobal".
 * That way it is clear in the code when we are using static variable because
 * its name start with sMPGlobal.
 */
static struct Global_Data
{
	SyMemBackend sAllocator;                /* Global low level memory allocator */
#if defined(XPP_ENABLE_THREADS)
	const SyMutexMethods *pMutexMethods;   /* Mutex methods */
	SyMutex *pMutex;                       /* Global mutex */
	sxu32 nThreadingLevel;                 /* Threading level: 0 == Single threaded/1 == Multi-Threaded 
										    * The threading level can be set using the [xpp_lib_config()]
											* interface with a configuration verb set to
											* XPP_LIB_CONFIG_THREAD_LEVEL_SINGLE or 
											* XPP_LIB_CONFIG_THREAD_LEVEL_MULTI
											*/
#endif
	sxi32 nEngine;                          /* Total number of active macro processor instances */
	xpp *pEngines;                          /* List of active macro processors */
	sxu32 nMagic;                           /* Sanity check against library misuse */
}sMPGlobal = {
	{0,0,0,0,0,0,0,0,{0}},
#if defined(XPP_ENABLE_THREADS)
	0,
	0,
	0,
#endif
	0,
	0,
	0
};
#define XPP_LIB_MAGIC  0x26DE78CA
#define XPP_LIB_MISUSE (sMPGlobal.nMagic != XPP_LIB_MAGIC)
/*
 * Supported threading level.
 * These options have meaning only when the library is compiled with multi-threading
 * support.That is,the XPP_ENABLE_THREADS compile time directive must be defined
 * when xPP is built.
 * XPP_THREAD_LEVEL_SINGLE:
 * In this mode,mutexing is disabled and the library can only be used by a single thread.
 * XPP_THREAD_LEVEL_MULTI
 * In this mode, all mutexes including the recursive mutexes on [xpp] objects
 * are enabled so that the application is free to share the same preprocessor
 * between different threads at the same time.
 */
#define XPP_THREAD_LEVEL_SINGLE 1 
#define XPP_THREAD_LEVEL_MULTI  2
/*
 * Symisc Run-Time API: A modern thread safe replacement of the standard libc
 * Copyright (C) Symisc Systems 2007-2011, http://www.symisc.net/
 *
 * The Symisc Run-Time API is an independent project developed by symisc systems
 * internally as a secure replacement of the standard libc.
 * The library is re-entrant,thread-safe and platform independent.
 *
 * Functions prototypes:
 */
/* SyRunTimeApi: sxstr.c */
static sxsize SyStrlen(const char *zSrc);
static sxi32 SyStringGetNextToken(SyString *pCursor,SyString *pCurrent);
/* SyRunTimeAPI: sxmem.c */
static void SyZero(void *pSrc,sxsize nSize);
static sxsize SyMemcpy(const void *pSrc,void *pDest,sxsize nLen);
static sxi32 SyMemcmp(const void *pB1,const void *pB2,sxsize nSize);
static void * SyMemBackendAlloc(SyMemBackend *pBackend,sxu32 nByte);
static void * SyMemBackendRealloc(SyMemBackend *pBackend,void * pOld,sxu32 nByte);
static sxi32 SyMemBackendFree(SyMemBackend *pBackend,void * pChunk);
static void * SyMemBackendPoolAlloc(SyMemBackend *pBackend,sxu32 nByte);
static sxi32 SyMemBackendPoolFree(SyMemBackend *pBackend,void * pChunk);
#if defined(UNTRUST) || defined(XPP_ENABLE_THREADS)
static sxu8 SyMemBackendPoolValidChunk(SyMemBackend *pBackend,void * pChunk);
#endif
static sxi32 SyMemBackendInitFromParent(SyMemBackend *pBackend,SyMemBackend *pParent);
static sxi32 SyMemBackendRelease(SyMemBackend *pBackend);
static void * SyMemBackendDup(SyMemBackend *pBackend,const void *pSrc,sxu32 nSize);
static char * SyMemBackendStrDup(SyMemBackend *pBackend,const char *zSrc,sxu32 nSize);
static sxi32 SyBlobSearch(const void *pBlob,sxu32 nLen,const void *pPattern,sxu32 pLen,sxu32 *pOfft);
static sxi32 SyBlobInit(SyBlob *pBlob,SyMemBackend *pAllocator);
static sxi32 SyBlobAppend(SyBlob *pBlob,const void *pData,sxsize nSize);
static sxi32 SyBlobReset(SyBlob *pBlob);
static sxi32 SyBlobRelease(SyBlob *pBlob);
/* SyRunTimeApi: sxds.c */
static sxi32 SySetInit(SySet *pSet,SyMemBackend *pAllocator,sxu32 ElemSize);
static sxi32 SySetPut(SySet *pSet,const void *pItem);
static sxi32 SySetRemove(SySet *pSet,sxu32 nPos,void *pInfo);
static sxi32 SySetAlloc(SySet *pSet,sxi32 nItem);
static sxi32 SySetAccess(SySet *pSet,sxu32 nPos,void **ppInfo);
static sxi32 SySetReset(SySet *pSet);
static sxi32 SySetResetCursor(SySet *pSet);
static sxi32 SySetGetNextEntry(SySet *pSet,void **ppEntry);
static sxi32 SySetRelease(SySet *pSet);
static void * SySetPeek(SySet *pSet);
static void * SySetPop(SySet *pSet);
static SyHashEntry * SyHashGet(SyHash *pHash,const void *pKey,sxu32 nKeyLen);
static sxi32 SyHashInsert(SyHash *pHash,const void *pKey,sxu32 nKeyLen,void *pUserData);
static sxi32 SyHashTailInsert(SyHash *pHash,const void *pKey,sxu32 nKeyLen,void *pUserData);
/* SyRunTimeApi: sxlib.c */
static sxi32 SyLexInit(SyLex *pLex,SySet *pSet,ProcTokenizer xTokenizer,void *pUserData);
static sxi32 SyLexTokenizeInput(SyLex *pLex,const char *zInput,sxsize nLen,void *pCtxData,ProcSort xSort,ProcCmp xCmp);
static sxi32 SyLexRelease(SyLex *pLex);
static sxi32 SyRandomnessInit(SyRC4Ctx *pCtx,ProcRandomSeed xSeed,void * pUserData);
static sxi32 SyRandomness(SyRC4Ctx *pCtx,void *pBuf,sxsize nLen);
/* SyRunTimeApi: sxutils.c */
static sxi32 SyStrToInt32(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest);
static sxi32 SyStrToInt64(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest);
/* SyRunTimeApi: sxfmt.c */
static sxsize SyBlobFormat(SyBlob *pBlob,const char *zFormat,...);
/*
 * Initialize a macro calling context.
 * Each time a macro is extracted from the input.That is,the preprocessor hashtable
 * return a valid 'SyMacro' instance, we have to initialize the xpp context prior
 * to invoking the callback associated with the target macro.
 * This context serve as an intermediate between the macro processor and the callback 
 * responsible of expanding the macro body.
 * For more information on the xpp_context object refer to the official documentation 
 * section "Implementing and registering macros"
 * This function never fail and always return SXRET_OK.
 */
static sxi32 PreprocessorInitContext(xpp_context *pCtx,xpp *pEngine,SyHashEntry *pName,
	sxu32 nLine,SyMacro *pMacro,ProcConsumer xConsumer,void *pConsumerData)
{
	/* Point to the engine that own this context */
	pCtx->pEngine = &(*pEngine);
	/* Point to the macro that trigger the context creation */
	pCtx->pMacro = &(*pMacro);
	/* Name of the called macro */
	SyStringInitFromBuf(&pCtx->sName,pName->pKey,pName->nKeyLen);
	/* Point to the expanded input consumer routine */
	pCtx->xConsumer = xConsumer;
	pCtx->pConsumerData = pConsumerData;
	pCtx->iFlags = 0;
	SyBlobInit(&pCtx->sBlob,&pEngine->sAllocator);
	pCtx->nLine = nLine;
	pCtx->rc = SXRET_OK;
	return SXRET_OK;
}
/* Forward declaration */
static sxi32 MacroBuiltin_EvalIf(xpp_context *pCtx,int nArg,const SyString *azArg);
static sxi32 MacroBuiltin_EvalIfdef(xpp_context *pCtx,int nArg,const SyString *azArg);
static sxi32 MacroBuiltin_EvalIfndef(xpp_context *pCtx,int nArg,const SyString *azArg);
/*
 * Tokenize a conditional macro.
 * Each time a conditional macro directive is seen [i.e: if,ifdef,ifndef...] this function
 * is called in order to tokenize the condition and extract fields of interest.
 * This function return a valid pointer to a 'SyCondDirective' structure on success.
 * Otherwise NULL is retuned [i.e: Out of memory].
 */
static SyCondDirective * PreprocessorTokenizeCondition(xpp *pEngine,sxu32 nTokType,const char *zInput,sxu32 nLen)
{
	SyString sTokenizer,sToken;
	SyCondDirective *pCond;

	/* Create and initialize a conditional node */
	pCond = (SyCondDirective *)SyMemBackendPoolAlloc(&pEngine->sAllocator,sizeof(SyCondDirective));
	if( pCond == 0 ){
		return 0;
	}
	/* Zero the structure */
	SyZero(pCond,sizeof(SyCondDirective));
	/* Initialize structure fields */
	SySetInit(&pCond->aToken,&pEngine->sAllocator,sizeof(SyString));         /* Tokens set */
	SySetInit(&pCond->aDefs,&pEngine->sAllocator,sizeof(SyMacroDefs *));     /* Macro defined in the [if],[ifdef],[ifndef],[elif] block */
	SySetInit(&pCond->aElseDefs,&pEngine->sAllocator,sizeof(SyMacroDefs *)); /* Macro defined in the [else] block */
	/* Init the tokenizer */
	SyStringInitFromBuf(&sTokenizer,zInput,nLen);
	/* 
	 * Tokenize the condition: 
	 * Return the next non space token
	 */
	if( nTokType & (XPP_TK_IFDEF|XPP_TK_IFNDEF) ){
		while( SyStringGetNextToken(&sTokenizer,&sToken) == SXRET_OK ){
			if( sToken.nByte == sizeof("\\") - 1 && sToken.zString[0] == '\\' ){
				/* Ignore backslash */
				continue;
			}
			/* Insert the token in the set */
			if( SXRET_OK != SySetPut(&pCond->aToken,(const void *)&sToken) ){
				break;
			}
		}
	}else{
		/* Remove leading and trailing white spaces */
		SyStringFullTrim(&sTokenizer);
		SySetPut(&pCond->aToken,(const void *)&sTokenizer);
	}
	/* Point to the appropriate C function responsible of condition evaluation */ 
	switch(nTokType){
	case XPP_TK_IFDEF:
		pCond->xEval = MacroBuiltin_EvalIfdef;
		break;
	case XPP_TK_IFNDEF:
		pCond->xEval = MacroBuiltin_EvalIfndef;
		break;
	case XPP_TK_IF:
		/* FALL THRU */
	default:
		pCond->xEval = MacroBuiltin_EvalIf;
		break;
	}
	pCond->nType = nTokType;
	/* Link to the others conditions */
	pCond->pNext = pEngine->pCond;
	pEngine->pCond = pCond;
	pEngine->nCond++;
	/* Return a parse of the raw condition */
	return pCond;
}
/*
 * Check if the current token begin with a conditional macro directive.
 * On success this function try to delimit the condition and then call [PreprocessorTokenizeCondition()]
 * to parse the condition.If ppCond is not null then this field is set to point to the parse of the 
 * condition.Otherwise SXERR_NOTFOUND is returned when the token does not correspond to a conditional
 * macro directive.
 */
static sxi32 PreprocessorCheckConditional(xpp *pEngine,SyToken *pToken,SyStream *pStream,SyCondDirective **ppCond)
{
	static const SyString aCond[] = {
		{"if"     ,  sizeof("if") - 1   },
		{"ifdef"  ,  sizeof("ifdef")-1  },
		{"ifndef" ,  sizeof("ifndef")-1 },
		{"ifnotdef", sizeof("ifnotdef")-1 },
		{"elif"   ,  sizeof("elif")-1   },
		{"else"   ,  sizeof("else")-1   },
		{"endif"  ,  sizeof("endif")-1  }
	};
	static const sxu32 aTok[] = {
		XPP_TK_IF,
		XPP_TK_IFDEF,
		XPP_TK_IFNDEF,
		XPP_TK_IFNDEF,
		XPP_TK_ELIF,
		XPP_TK_ELSE,
		XPP_TK_ENDIF
	};
	SyString *pIf = &pToken->sData;
	const unsigned char *zBs;
	SyCondDirective *pCond;
	sxu32 n;
	/* Loop throw the conditional macro directive table */
	for( n = 0 ; n < SX_ARRAYSIZE(aCond) ; ++n ){
		if( SyStringCmp(pIf,&aCond[n],SyMemcmp) == 0 ){
			break;
		}
	}
	if( n >= SX_ARRAYSIZE(aCond) ){
		/* Not a conditional macro */
		return SXERR_NOTFOUND;
	}
	/* Jump the directive prefix */
	SyStringUpdatePtr(pIf,aCond[n].nByte);
	/* Record token type */
	pToken->nType = aTok[n];
	/* Isolate condition */
	if( pToken->nType & (XPP_TK_ENDIF|XPP_TK_ELSE) ){
		/* Nothing to isolate,simply synchronize with the next line */
		while( pStream->zText < pStream->zEnd &&  pStream->zText[0] != '\n'  ){
			/* Advance the stream cursor */
			pStream->zText++;
		}
		if( ppCond ){
			*ppCond = 0;
		}
		/* Ignore trailing white spaces */
		if( pStream->pSet ){
			SyToken *pTmp;
			while( (pTmp = (SyToken *)SySetPeek(pStream->pSet)) != 0 ){
				if( (pTmp->nType & (XPP_TK_LF|XPP_TK_SPACE)) == 0 ){
					break;
				}
				pStream->pSet->nUsed--;
			}
		}
		return SXRET_OK;
	}
	while( pStream->zText < pStream->zEnd ){
		if( pStream->zText[0] == '\n' ) {
			if( pToken->nType & (XPP_TK_IFDEF|XPP_TK_IFNDEF) ){
				break;
			}
			zBs = pStream->zText - 1;
			while( (const char *)zBs > pIf->zString && zBs[0] < 0xc0 && SyisSpace(zBs[0]) ){
				zBs--;
			}
			if( zBs[0] != '\\' ){
				break;
			}
			pStream->nLine++;
		}
		/* Advance the cursor */
		pStream->zText++;
	}
	pIf->nByte = (sxu32)((const char *)pStream->zText - pIf->zString);
	/* Tokenize the condition */
	pCond = PreprocessorTokenizeCondition(&(*pEngine),pToken->nType,pIf->zString,pIf->nByte);
	/* Save the parse for later evaluation */
	pToken->pUserData = pCond;
	if( ppCond ){
		*ppCond = pCond;
	}
	/* Synchronize the stream cursor */ 
	while( pStream->zText < pStream->zEnd && (pStream->zText[0] == '\n'||pStream->zText[0] == '\r') ){
		if( pStream->zText[0] == '\n' ){
			pStream->nLine++;
		}
		pStream->zText++;
	}
	return SXRET_OK;
}
/* Forward declaration */
static sxi32 PreprocessorTokenizeMacroBody(SyStream *pStream,SyToken *pToken,void *pUserData,void *pCtxData);
/*
 * Return the full path of the current processed file.
 * Included files are processed in LIFO order,this function return the top most entry
 * in the stack.
 * If the processed entry is a chunk of a memory not a file on disk,then this function
 * return the constant '::Memory::'.
 * This function never fail and always return a valid pointer.
 */
static const char * PreprocessorGetProcessedFilePath(xpp *pEngine)
{
	SyString *pEntry;
	xpp_conf *pConf;

	pConf = &pEngine->sConfig;
	pEntry = (SyString *)SySetPeek(&pConf->aFiles);
	return pEntry ? pEntry->zString : "::Memory::" /* An in memory buffer */ ;
}
/* Forward declaration */
static sxsize SyBufferFormatAp(char *zBuf,sxsize nLen,const char *zFormat,va_list ap);
/* 
 * Consume an error message generated by the upper layers.
 * Each time an error is detected say an unmatched 'if' or 'endif' token or the included
 * file cannot be opened,then the upper layer generate an error message plus some diagnostics
 * info like the line number on which the error occur and the error type.
 * This procedure redirect the generated error to the error consumer callback installed
 * by the host application.
 * If no error consumer callback is installed then this procedure is a no-op.
 * Note: To install an error consumer callback,simply call the [xpp_config()] interface
 * with a configuration verb set to XPP_CONFIG_ERR_CALLBACK.
 * Example: Redirect all generated errors to STDOUT
 * void MyErrorCallback(void *pUserData,const char *zFilename,int nErrType,int nLine,const char *zErr)
 * {
 *    printf("%s ==> %d: %s",zFilename,nErrType,zErr);
 * }
 * Register the procesure above
 * xpp_config(pEngine,XPP_CONFIG_ERR_CALLBACK,MyErrorCallback,0);
 */
static void PreprocessorConsumeError(xpp *pEngine,sxi32 iErrCode,sxu32 nLine,const char *zErr,...)
{
	xpp_conf *pConf;
	va_list ap;

	if( pEngine->xErr == 0 ){
		/* There is no installed error consumer callback,return immediatly */
		return;
	}
	/* Assemble the generated message */
	pConf = &pEngine->sConfig;
	va_start(ap,zErr);
	SyBufferFormatAp(pConf->zErr,sizeof(pConf->zErr),zErr,ap);
	va_end(ap);
	/* Invoke the error consumer callback */
	pEngine->xErr(pEngine->pErrData,PreprocessorGetProcessedFilePath(pEngine),iErrCode,(sxi32)nLine,pConf->zErr);
}
/* 
 * Parse a raw macro definition.
 * Each time the tokenizer recognize a macro keyword [i.e: 'define','macro' or any other keyword
 * defined by the host-application] and after isolation of the whole definition,this procedure
 * get called by the macro processor in order to parse the raw definition.
 * Some of the work done here is extracting macro name,isolating arguments and replacing
 * them with their real index in the arg table (if faced with a function like macro)
 * and finally tokenizing the macro body.
 * This function return a parse of the raw definition on success.Otherwise NULL is returned
 * on failure.
 */ 
static SyMacroDefs * PreprocessorParseRawDefinition(xpp *pEngine,SyString *pToken,SyString *pSuffix,sxu32 nLine)
{
	const unsigned char *zStart,*zEnd,*zArg,*zIn;
	SyString *pName,*pArgDelim;
	SyMacroDefs *pMacro;
	sxu32 nMinArgLen;
	SyMacroArg sArg;
	xpp_conf *pConf;
	SyToken *pTok;
	char *zName;
	SyLex sLex;
	sxi32 rc;
	sxu32 n;

	/* Allocate a new macro instance */
	pMacro = (SyMacroDefs *)SyMemBackendPoolAlloc(&pEngine->sAllocator,sizeof(SyMacroDefs));
	if(pMacro == 0 ){
		return 0;
	}
	/* Zero the structure */
	SyZero(pMacro,sizeof(SyMacroDefs));
	/* Initialize components */
	pMacro->pEngine = pEngine;
	SySetInit(&pMacro->aBody,&pEngine->sAllocator,sizeof(SyToken));
	SySetInit(&pMacro->aArgs,&pEngine->sAllocator,sizeof(SyMacroArg));
	/* Set initial flag */
	pMacro->iFlags = USER_MACRO_STRICT_INVOKE;
	pMacro->nLine  = nLine;
	/* Isolate macro name */
	pName = &pMacro->sName;
	zStart = (const unsigned char *)pToken->zString;
	zEnd = (const unsigned char *)&pToken->zString[pToken->nByte];
	for(;;){
		zIn = zStart;
		/* Skip UTF-8 and alphanumeric stream */
		if( zIn < zEnd && zIn[0] >= 0xc0 ){
			zIn++;
			/* UTF-8 stream */
			while( zIn < zEnd && ((zIn[0] & 0xc0) == 0x80) ){
				zIn++;
			}
		}
		while( zIn < zEnd && zIn[0] < 0xc0 && (SyisAlphaNum(zIn[0]) || zIn[0] == '_') ){
			zIn++;
		}
		if( zIn == zStart ){
			/* White spaces or garbage sequences */
			break;
		}
		/* Synchronize pointers */
		zStart = zIn;
	}
	/* Duplicate macro name */
	pName->nByte = (sxu32)((const char *)zStart-pToken->zString);
	if( pName->nByte <= 0 ){
		/* Empty macro definition */
		pEngine->nErr++;
		PreprocessorConsumeError(&(*pEngine),XPP_ERR_EMPTY_MACRO,nLine,"No name is associated with the macro defined on line %u\n",nLine);
		SyMemBackendPoolFree(&pEngine->sAllocator,pMacro);
		return 0;
	}
	pConf = &pEngine->sConfig;
	pArgDelim = &pConf->aArgDelim[0];
	if( SyMemcmp(zStart,pArgDelim->zString,pArgDelim->nByte) == 0 ){
		/* Function-Like macro detected,record that */
		pMacro->iFlags |= USER_MACRO_COLLECT_ARGS;
	}
	zName = SyMemBackendStrDup(&pEngine->sAllocator,pToken->zString,pName->nByte);
	if( zName == 0 ){
		SyMemBackendPoolFree(&pEngine->sAllocator,pMacro);
		return 0;
	}
	/* Save the duplicated name */
	pName->zString = zName;
	if( zStart >= zEnd ){
		/* Empty macro body */
		pMacro->iFlags |= USER_MACRO_EMPTY;
		return pMacro;
	}
	nMinArgLen = SXU32_HIGH;
	if( pMacro->iFlags & USER_MACRO_COLLECT_ARGS ){
		SyString *pArgStart,*pArgSep;
		sxi32 iNest = 1;
		/* Isolate macro arguments */
		pArgStart = &pConf->aArgDelim[0];
		pArgDelim = &pConf->aArgDelim[1];  /* Right argument delimiter [i.e: ')'] */
		pArgSep   = &pConf->sArgSep;       /* Argument separator [i.e: ','] */
		zStart++;
		for(;;){
			zArg = zStart;
			while(zStart < zEnd && SyMemcmp(zStart,pArgSep->zString,pArgSep->nByte) != 0 ){
				if( SyMemcmp(zStart,pArgStart->zString,pArgStart->nByte) == 0 ){
					/* Increment nesting level */
					iNest++;
					zStart += pArgStart->nByte;
				}else if( SyMemcmp(zStart,pArgDelim->zString,pArgDelim->nByte) == 0 ){
					/* Decrement nesting level */
					iNest--;
					if( iNest <= 0 ){
						break;
					}
					zStart += pArgDelim->nByte;
				}else{
					zStart++;
				}
			}
			/* At this point,we have isolated an argument,save it in the arg set */
			SyStringInitFromBuf(&sArg.sName,zArg,zStart-zArg);
			SyStringInitFromBuf(&sArg.sDefValue,0,0);
			sArg.nIndex = 0;
			/* Ignore leading and trailing white spaces */
			SyStringFullTrim(&sArg.sName);
			if( SyStringLength(&sArg.sName) > 0 ){
				/* Isolate argument default value if any */
				while( zArg < zStart && zArg[0] != '=' ){
					zArg++;
				}
				if( zArg < zStart ){
					/* Got default value */
					pName = &sArg.sName;
					/* fix name length */
					pName->nByte = (sxu32)((const char *)zArg-pName->zString);
					SyStringRightTrim(pName);
					zArg++;
					pName = &sArg.sDefValue;
					SyStringInitFromBuf(pName,zArg,zStart-zArg);
					/* Ignore leading and trailing white spaces */
					SyStringFullTrim(pName);
				}
				if( SyStringLength(&sArg.sName) < nMinArgLen ){
					nMinArgLen = SyStringLength(&sArg.sName);
				}
				sArg.nIndex = SySetUsed(&pMacro->aArgs);
				/* Put in the set */
				rc = SySetPut(&pMacro->aArgs,(const void *)&sArg);
				if( rc != SXRET_OK ){ 
					break;
				}
			}else if( iNest > 0 ){
				/* Empty argument */
				PreprocessorConsumeError(&(*pEngine),XPP_ERR_EMPTY_ARG,nLine,"macro '%z' defined on line %u have an empty argument\n",&pMacro->sName,nLine);
			}
			if( zStart >= zEnd || iNest <= 0 ){
				zStart += pArgDelim->nByte;
				break;
			}else{
				zStart += pArgSep->nByte; /* Advance the cursor  */
			}
		}
	}
	/* Jump leading white spaces */
	while(zStart < zEnd && zStart[0] < 0xc0  && ( SyisSpace(zStart[0])  || zStart[0] == '\\' ) ){
		zStart++;
		if( zStart[-1] == '\n' ){
			break;
		}
	}
	if( zStart >= zEnd || (zStart[0] == 0  && &zStart[1] >= zEnd) ){
		/* Empty macro body */
		pMacro->iFlags |= USER_MACRO_EMPTY;
		return pMacro;
	}
	/* Tokenize macro body */
	SyLexInit(&sLex,&pMacro->aBody,PreprocessorTokenizeMacroBody,&(*pEngine));
	SyLexTokenizeInput(&sLex,(const char *)zStart,(sxsize)(zEnd-zStart),(void *)pSuffix,0,0);
	SyLexRelease(&sLex);
	/* Ignore trailing white spaces (new line included) */
	for(;;){
		pTok = (SyToken *)SySetPeek(&pMacro->aBody);
		if( pTok == 0 || (pTok->nType & (XPP_TK_SPACE|XPP_TK_LF)) == 0 ){
			break;
		}
		pMacro->aBody.nUsed--; 
	}
	if( SySetUsed(&pMacro->aBody) <= 0 ){
		/* Empty macro body */
		pMacro->iFlags |= USER_MACRO_EMPTY;
		return pMacro;
	}
	if( pMacro->iFlags & USER_MACRO_COLLECT_ARGS ){
		SyString *pArgName;
		SyMacroArg *aArgs;
		SyToken *aToken;
		sxi32 nIdx;
		sxu32 i;
		/* Replace formal arguments with their real index in the arg table so we can expand
		 * them later in constant time O(1) rather than doing a linear lookup.
		 */
		aArgs = (SyMacroArg *)SySetBasePtr(&pMacro->aArgs); /* Argument table */
		aToken = (SyToken *)SySetBasePtr(&pMacro->aBody);   /* Macro tokens */
		for ( n = 0 ; n < SySetUsed(&pMacro->aBody) ; ++n ){
			pName = &aToken[n].sData;
			if( aToken[n].nType != XPP_TK_RAW ){
				if( aToken[n].nType & XPP_TK_GARBAGE ){
					if( pName->nByte > sizeof(char) && pName->zString[0] == '$' ){
						/* M4 argument substitution style */
						if( pName->nByte == sizeof("$x") - 1 ){
							if( pName->zString[1] == '#' ){
								/* $#: Expands to the number of given arguments */
								aToken[n].nType = XPP_TK_M4_HASH;
							}else if( pName->zString[1] == '*' ){
								/* $*: Expands to the list of arguments */
								aToken[n].nType = XPP_TK_M4_ARG_LIST;
							}else if( pName->zString[1] == '@' ){
								/* $@: Expands to the list of arguments (quoted) */
								aToken[n].nType = XPP_TK_M4_ARG_LIST2;
							}else if( pName->zString[1] == '0' ){
								/* $0: Expands to the macro name */
								aToken[n].nType = XPP_TK_M4_NAME;
							}else{
								/* Convert to an index in the arg table */
								nIdx = pName->zString[1] - '0';
								/* Record as formal argument */
								aToken[n].nType = XPP_TK_FORMAL_ARG;
								nIdx--;
								aToken[n].pUserData = (void *)nIdx;
							}
						}else if(SyisDigit(pName->zString[1])) {
							/* Convert number to an index in the arg table */
							SyStrToInt32(&pName->zString[1],pName->nByte - 1,(void *)&nIdx,0);
							if( nIdx == 0 ){
								/* $0000: Expands to the macro name */
								aToken[n].nType = XPP_TK_M4_NAME;
							}else{
								/* Record as formal argument */
								aToken[n].nType = XPP_TK_FORMAL_ARG;
								nIdx--;
								aToken[n].pUserData = (void *)nIdx;
							}
						}
					}
				}
				/* Ignore grabages */
				continue;
			}
			if( pName->nByte < nMinArgLen ){
				/* Can't be a formal argument */
				continue;
			}
			/* Try to find a formal argument */
			for ( i = 0 ; i < SySetUsed(&pMacro->aArgs) ; ++i ){
				pArgName = &aArgs[i].sName;
				if( pArgName->nByte != pName->nByte || SyMemcmp(pArgName->zString,pName->zString,pArgName->nByte) != 0 ){
					/* Can't be a formal argument */
					continue;
				}
				/* Got one,mark it */
				aToken[n].nType = XPP_TK_FORMAL_ARG;
				/* Save the formal argument index  */
				aToken[n].pUserData = (void *)i;
				break;
			}
		}
	}
	/* Return the parse of the raw macro */
	return pMacro;
}
/* Forward declaration */
static sxi32 PreprocessorRegisterMacro(xpp *pEngine,const SyString *pName,ProcMacroExpansion x,void *pUserData,sxi32 iFlags);
static sxi32 PreprocessorRegisterMacro2(xpp *pEngine,const SyString *pName,ProcMacroExpansion xMacro,void *pUserData,sxi32 iFlags);
static sxi32 MacroBuiltin_Expand(xpp_context *pCtx,int nArg,const SyString *azArg);
/*
 * Check if the given token is a macro prefix.
 * When the given token start with a macro keyword [i.e: 'define','macro' or any other keyword
 * defined by the host-application] then this function try to isolate the whole definition
 * and then call [PreprocessorParseRawDefinition()] in order to parse the raw definition.
 * This function return SXRET_OK if the token is a macro keyword.Otherwise SXERR_NOTFOUND
 * is returned.
 */
static sxi32 PreprocessorCheckMacroDefinition(xpp *pEngine,SyString *pRaw,SyStream *pStream,
	SySet *aIdent,SyCondDirective *pCond,sxi32 iCtxFlags)
{
	SyString *aPrefix,*pPrefix,*pEnd;
	SyMacroDefs *pDef;
	sxu8 bStripSuffix;
	sxu8 bPtrUpdate;
	sxu32 nLine;
	sxi32 rc;
	sxu32 n;

	pPrefix = pEnd = 0; /* Prevent compiler warning */
	aPrefix = (SyString *)SySetBasePtr(aIdent);
	for( n = 0 ; n < SySetUsed(aIdent) ; n += 2 ){
		pPrefix = &aPrefix[n];
		if( SyStringCmp(pRaw,pPrefix,SyMemcmp) == 0 ){
			/* Token is a macro keyword,try to isolate the whole definition */
			pEnd = &aPrefix[n + 1];
			break;
		}
	}
	if( n >= SySetUsed(aIdent) ){
		/* Token is not a macro keyword */
		return SXERR_NOTFOUND;
	}
	nLine = pStream->nLine;
	bStripSuffix = FALSE;
	/* Isolate the raw macro definition */
	if( (pEnd->nByte == sizeof(char) && pEnd->zString[0] == '\n') ||
		(pEnd->nByte == sizeof("\r\n") - 1 && pEnd->zString[0] == '\r' && pEnd->zString[1] == '\n') ){
			SyString sStr,*pComStart,*pComEnd;
			const unsigned char *zBs;
			xpp_conf *pConf;
			sxu8 bExitLoop;
			
			pConf = &pEngine->sConfig;
			while( pStream->zText < pStream->zEnd ){
				if( pStream->zText[0] == '\n' ){
					zBs = pStream->zText - 1;
					pStream->nLine++;
					while( (const char *)zBs > pRaw->zString && zBs[0] < 0xc0 && SyisSpace(zBs[0]) ){
						if( zBs[0] == '\n' ){
							break;
						}
						zBs--;
					}
					if( zBs[0] != '\\' ){
						break;
					}
				}
				/* Handle the special case of multiline comments */
				SySetResetCursor(&pConf->aComment);
				bExitLoop = FALSE ;
				while( SySetGetNextEntry(&pConf->aComment,(void **)&pComStart) == SXRET_OK ){
					SySetGetNextEntry(&pConf->aComment,(void **)&pComEnd);
					if( (pComEnd->nByte == sizeof(char) && pComEnd->zString[0] == '\n') ||
						(pComEnd->nByte == sizeof("\r\n") - 1 && pComEnd->zString[0] == '\r' && pComEnd->zString[0] == '\n') ){
							continue;
					}
					/* Check for the presence of a comment prefix */
					SyStringInitFromBuf(&sStr,pStream->zText,pStream->zEnd-pStream->zText);
					if( SyStringCmp2(&sStr,pComStart,SyMemcmp) != 0 ){
						continue;
					}
					pStream->zText += pComStart->nByte;
					/* Delimit the comment */
					while( (sxu32)(pStream->zEnd - pStream->zText) >= pComEnd->nByte && 
						SyMemcmp(pStream->zText,pComEnd->zString,pComEnd->nByte) != 0 ){
							if( pStream->zText[0] == '\n' ){
								pStream->nLine++;
								/* Delimit the comment and exit the loop immediately */
								bExitLoop = TRUE;
							}
							/* Advance the stream cursor */
							pStream->zText++;
					}
					pStream->zText += pComEnd->nByte;
					if( bExitLoop ){
						pRaw->nByte = (sxu32)((const char *)pStream->zText - pRaw->zString);
						goto Delimit;
					}
					/* Synchronize pointers */
					pStream->zText--;
					break;
				}
				pStream->zText++;
			}
	}else{
		sxi32 iNest;

		bStripSuffix = TRUE;
		iNest = 1;
		while( pStream->zText < pStream->zEnd ){
			if( pStream->zText[0] == '\n' ){
				pStream->nLine++;
			}
			if( (sxu32)(pStream->zEnd - pStream->zText) >= pPrefix->nByte && 
				SyMemcmp(pStream->zText,pPrefix->zString,pPrefix->nByte) == 0 ){
					/* Increment nesting level */
					iNest++;
					pStream->zText += pPrefix->nByte;
			}else if( (sxu32)(pStream->zEnd - pStream->zText) >= pEnd->nByte && 
				SyMemcmp(pStream->zText,pEnd->zString,pEnd->nByte) == 0 ){
					iNest--;
					if( iNest <= 0 ){
						const unsigned char *zPtr = pStream->zText;
						/* Count trailing lines */
						while( zPtr < &pStream->zText[pEnd->nByte] ){
							if( zPtr[0] == '\n' ){
								pStream->nLine++;
							}
							zPtr++;
						}
						break;
					}
					pStream->zText += pEnd->nByte;
			}else{
				/* Advance the stream cursor */
				pStream->zText++;
			}
		}
	}
	bPtrUpdate = FALSE;
	if( &pStream->zText[pEnd->nByte] < pStream->zEnd ){
		pStream->zText += pEnd->nByte;
		bPtrUpdate = TRUE;
	}
	pRaw->nByte = (sxu32)((const char *)pStream->zText - pRaw->zString);
	if( bPtrUpdate && pStream->zText < pStream->zEnd ){
		pRaw->nByte -= pEnd->nByte;
	}
Delimit:
	/* Ignore keyword prefix and suffix */
	SyStringUpdatePtr(pRaw,pPrefix->nByte);
	/* Ignore leading spaces (new line included) and backslashes */
	while( pRaw->zString < (const char *)pStream->zText && 
		(( (unsigned char)pRaw->zString[0] < 0xc0 && SyisSpace(pRaw->zString[0])) || pRaw->zString[0] == '\\') ){
			pRaw->zString++;
			if( pRaw->nByte > 0 ){
				pRaw->nByte--;
			}
	}
	SyStringRightTrim(pRaw);
	if( iCtxFlags & USER_MACRO_NEST ){
		char *zInput;
		/* Duplicate the raw macro definition since the memory buffer may be released by
		 * the macro processor when the nesting level is greater than one.*/
		zInput = (char *)SyMemBackendDup(&pEngine->sAllocator,pRaw->zString,pRaw->nByte);
		if( zInput == 0 ){
			goto End;
		}
		pRaw->zString = zInput;
	}
	/* Parse the raw macro */
	pDef = PreprocessorParseRawDefinition(&(*pEngine),pRaw,bStripSuffix ? pEnd : 0,nLine);
	if( pDef ){
		pDef->pCond = pCond;
		if( pCond ){
			/* Insert the macro in its [if] or [else] context */
			if( pCond->iFlags & XPP_COND_ELSE_CTX ){
				/* [else] context */
				SySetPut(&pCond->aElseDefs,(const void *)&pDef);
			}else{
				/* [if],[ifndef],[ifdef],[elif] context */
				SySetPut(&pCond->aDefs,(const void *)&pDef);
			}
			/* Deffer registration later when the condition evaluate to TRUE */
		}else{
			/* Register the macro */
			rc = PreprocessorRegisterMacro2(&(*pEngine),&pDef->sName,MacroBuiltin_Expand,pDef,pDef->iFlags);
		}
		pEngine->nUserMacro++; /* User defined macro counters */
	}
End:
	while( pStream->zText < pStream->zEnd && (pStream->zText[0] == '\n'||pStream->zText[0] == '\r')  ){
		if( pStream->zText[0] == '\n' ){
			pStream->nLine++;
		}
		pStream->zText++;
	}
	return SXRET_OK;
}
/*
 * Tokenize the entire input.
 * Get a single low-level token from the input file.Update the file pointer so that
 * it points to the first character beyond the extracted token.
 * Profiling shows that this routine consumes about half the CPU time on a typical 
 * run of [xpp_expand()].
 * This function return SXRET_OK on success,SXERR_CONTINUE if the token must be
 * ignored.Any other value indicates failure.
 */
static sxi32 PreprocessorTokenizeInput(SyStream *pStream,SyToken *pToken,void *pUserData,void *pCtxData)
{
	xpp *pEngine = (xpp *)pUserData;
	xpp_conf *pConf = &pEngine->sConfig;
	SyString *pStr = &pToken->sData;
	sxu32 iFlags = pEngine->iFlags;
	const char *zPtr,*zPtrEnd;
	const unsigned char *zIn;
	SyString *pPrefix,*pEnd;
	sxu32 nPos;
	sxi32 rc;

	/* Record token starting position and line */
	SyStringInitFromBuf(pStr,pStream->zText,pStream->zEnd-pStream->zText);
	pToken->nLine = pStream->nLine;
	pToken->pUserData = 0;
	if( SyStringLength(&pConf->sPrefix) <= 0 ){
		pConf->bLastwasPrefix = TRUE; 
	}
	/* Extract a single token from the input */
	for(;;){
		zIn = pStream->zText;
		/* Skip alphanumeric stream */
		while( zIn < pStream->zEnd && zIn[0] < 0xc0 && (SyisAlphaNum(zIn[0]) || zIn[0] == '_') ){
				zIn++;
		}
		if( zIn < pStream->zEnd && zIn[0] >= 0xc0 ){
			zIn++;
			/* UTF-8 stream */
			while( zIn < pStream->zEnd && ((zIn[0] & 0xc0) == 0x80) ){
				zIn++;
			}
		}
		if( zIn == pStream->zText ){
			/* Not an UTF-8 or alphanumeric stream */
			break;
		}
		/* Synchronize pointers */
		pStream->zText = zIn;
	}
	if( (const char *)pStream->zText > pStr->zString ){
		SyCondDirective *pCond;
		sxi32 iCtxFlag = 0;
		/* Record token type and length */
		pToken->nType = XPP_TK_RAW;
		pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
		if( pCtxData ){
			iCtxFlag = SX_PTR_TO_INT(pCtxData);
		}
		if( pConf->bLF && pConf->bLastwasPrefix && (iCtxFlag & USER_MACRO_IGNORE_EXPANDING) == 0){
			SyToken *pTmp;
			sxu32 nLine;
			nLine = pStream->nLine;
			pConf->bLastwasPrefix = FALSE;
			/* Check if the token is a macro keyword */
			rc = PreprocessorCheckMacroDefinition(pEngine,pStr,&(*pStream),&pConf->aIdent,pConf->pCond,iCtxFlag);
			if( rc == SXRET_OK ){
				/* Ignore leading white spaces */
				if( pStream->pSet ){
					while( (pTmp = (SyToken *)SySetPeek(pStream->pSet)) != 0 ){
						if( (pTmp->nType & XPP_TK_SPACE) == 0 ){
							break;
						}
						pStream->pSet->nUsed--;
					}
				}
				/* Tell the upper layer to ignore this token */
				return SXERR_CONTINUE;
			}
			/* Check for conditional macro directive*/
			rc = PreprocessorCheckConditional(pEngine,&(*pToken),&(*pStream),&pCond);
			if( rc == SXRET_OK ){
				if( pToken->nType & XPP_TK_ENDIF ){
					if( pConf->pCond == 0 ){
						/* Unmatched [endif] directive */
						pEngine->nErr++;
						PreprocessorConsumeError(pEngine,XPP_ERR_UNMATCHED_ENDIF,nLine,
							"Illegal 'endif' directive without matching 'if/ifdef/ifndef/else' tokens on line %u\n",nLine);
					}else{
						/* Pop from the stack */
						while(pConf->pCond && (pConf->pCond->nType & XPP_TK_ELIF) != 0 ){
							/* Pop as many [elif] condition as we have */
							pConf->pCond = pConf->pCond->pNextDown;
						}
						if( pConf->pCond ){
							pConf->pCond = pConf->pCond->pNextDown;
						}
					}
				}else if( pToken->nType & (XPP_TK_IF|XPP_TK_IFDEF|XPP_TK_IFNDEF|XPP_TK_ELIF) ){
					if( pCond ){
						if( (pToken->nType & XPP_TK_ELIF) && pConf->pCond == 0 ){
							PreprocessorConsumeError(pEngine,XPP_ERR_UNMATCHED_ELIF,nLine,
								"Illegal 'elif' directive without matching 'if/ifdef/ifndef/' tokens on line %u\n",nLine);
							pEngine->nErr++;
							/* Well,this is not a fatal error,we will treat it as an 'if' directive */ 
						}else{
							/* Push condition in the stack */
							pCond->pNextDown = pConf->pCond;
							pConf->pCond = pCond;
						}
					}
				}else if( pToken->nType & XPP_TK_ELSE ){
					if( pConf->pCond == 0 ){
						/* Unmatched [else] directive */
						pEngine->nErr++;
						PreprocessorConsumeError(pEngine,XPP_ERR_UNMATCHED_ELSE,nLine,
							"Illegal 'else' directive without matching 'if/ifdef/ifndef' on line %u\n",nLine);
					}else{
						/* Switch to the else context */
						pConf->pCond->iFlags |= XPP_COND_ELSE_CTX;
						pToken->pUserData = pConf->pCond;
					}
				}
				/* Ignore leading white spaces */
				if( pStream->pSet ){					
					while( (pTmp = (SyToken *)SySetPeek(pStream->pSet)) != 0 ){
						if( (pTmp->nType & XPP_TK_SPACE) == 0 ){
							break;
						}
						pStream->pSet->nUsed--;
					}
				}
				return SXRET_OK;
			}
		}
	}else{
		/* Non-alphanumeric (Garbage) stream */
		if( pStream->zText[0] == '\n' ){
			pStream->nLine++;
			pStream->zText++;
#ifdef __WINNT__
			pStr->zString = "\r\n";
			pStr->nByte = sizeof("\r\n") - 1;
#else
			while( pStream->zText < pStream->zEnd && pStream->zText[0] == '\n' ){
				pStream->zText++;
				pStream->nLine++;
			}
			if( iFlags & XPP_REDUCE_WS ){
				/* All successive blank-lines are reduced to a single line */
				pStr->zString = "\n";
				pStr->nByte = sizeof(char);
			}else{
				pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
			}
#endif
			pConf->bLF = TRUE;
			pToken->nType = XPP_TK_LF;
			return SXRET_OK;
		}else if( SyisSpace(pStream->zText[0]) ) {
			pStream->zText++;
			while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisSpace(pStream->zText[0])){
				if( pStream->zText[0] == '\n' ){
					break;
				}
				pStream->zText++;
			}
			/* Keep white spaces */
			pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
#ifdef __WINNT__
			if( pStream->zText[0] == '\n' && pStream->zText[-1] == '\r' ){
				pStr->nByte--;
			}
#endif
			if( 
#ifdef __WINNT__
				pStr->nByte <= 0 || 
#endif
				(iFlags & XPP_IGNORE_WS) != 0 ){
					/* Ignore white spaces completely */
					return SXERR_CONTINUE;
			}else if( iFlags & XPP_REDUCE_WS ){
				/* All successive white spaces are reduced to a single space */
				pStr->zString = " ";
				pStr->nByte = sizeof(char);
			}			
			pToken->nType = XPP_TK_SPACE;
			return SXRET_OK;
		}
		while( pStream->zText < pStream->zEnd  && pStream->zText[0] < 0xc0 && !SyisAlphaNum(pStream->zText[0])
			&& pStream->zText[0] != '_' && !SyisSpace(pStream->zText[0]) ){
				/* Advance the stream cursor */
				pStream->zText++;
		}
		/* Record token length */
		pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
		/* Select the appropriate type for this token */
		if(SyStringLength(&pConf->sConcat) > 0 && SyStringCmp(pStr,&pConf->sConcat,SyMemcmp) == 0 ){
			/* Concatenation operator,simply ignore */
			return SXERR_CONTINUE;
		}
		if( SyStringLength(&pConf->sPrefix) > 0 ){
			if( pConf->bLF && SyStringCmp(&pConf->sPrefix,pStr,SyMemcmp) == 0 ){
				/* Non-alphanumeric prefix [i.e: #] detected */
				pConf->bLastwasPrefix = TRUE;
				return SXERR_CONTINUE; /* Discard this prefix anyway */
			}else{
				pConf->bLastwasPrefix = FALSE;
			}
		}
		SySetResetCursor(&pConf->aStrings);
		while( SySetGetNextEntry(&pConf->aStrings,(void **)&pPrefix) == SXRET_OK ){
			SySetGetNextEntry(&pConf->aStrings,(void **)&pEnd);
			/* Check for the presence of a string delimiter */
			if( SyStringCmp2(pStr,pPrefix,SyMemcmp) != 0 ){
				rc = SyBlobSearch(pStr->zString,pStr->nByte,pPrefix->zString,pPrefix->nByte,&nPos);
				if( rc != SXRET_OK ){
					continue;
				}
				pStr->nByte = nPos;
				/* Push back literal and synchronize the stream cursor */
				while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
					pStream->zText--;
				}
				continue;
			}
			zPtr = pStr->zString;
			zPtrEnd = &pStr->zString[pStr->nByte];
			/* Delimit the string */
			zPtr += pPrefix->nByte;
			while( zPtr < zPtrEnd ){
				if( zPtr[0] == '\n' ){
					/* Issue a warning */
					PreprocessorConsumeError(pEngine,XPP_WARNING,pStream->nLine,
						"Warning: New line in constant string literal on line %u\n",pStream->nLine);
					pStream->nLine++;
				}
				if( (sxu32)(zPtrEnd - zPtr) >= pEnd->nByte && SyMemcmp(zPtr,pEnd->zString,pEnd->nByte) == 0 ){
					if( zPtr[-1] != '\\' || zPtr[-2] == '\\' ){
						break;
					}
					zPtr += pEnd->nByte - 1;
				}
				/* Advance the stream cursor */
				zPtr++;
			}
			if( zPtr >= zPtrEnd ){
				zPtr = (const char *)pStream->zText;
				zPtrEnd = (const char *)pStream->zEnd;
				while( zPtr < zPtrEnd && (sxu32)(zPtrEnd - zPtr) >= pEnd->nByte ){
					if( zPtr[0] == '\n' ){
						PreprocessorConsumeError(pEngine,XPP_WARNING,pStream->nLine,
							"Warning: New line in constant string literal on line %u\n",pStream->nLine);
						pStream->nLine++;
					}
					if( SyMemcmp(zPtr,pEnd->zString,pEnd->nByte) == 0 ){
						if( zPtr[-1] != '\\' || zPtr[-2] == '\\' ){
							break;
						}
						zPtr += pEnd->nByte - 1;
					}
					/* Advance the stream cursor */
					zPtr++;
				}
			}
			if( (sxu32)(zPtrEnd - zPtr) >= pEnd->nByte ){
				zPtr += pEnd->nByte;
			}
			/* Synchronize pointers */
			pStream->zText = (const unsigned char *)zPtr;
			/* Record token type and length */
			pToken->nType = XPP_TK_STRING;
			pStr->nByte = (sxu32)(zPtr-pStr->zString);
			return SXRET_OK;
		}
		SySetResetCursor(&pConf->aComment);
		while( SySetGetNextEntry(&pConf->aComment,(void **)&pPrefix) == SXRET_OK ){
			SySetGetNextEntry(&pConf->aComment,(void **)&pEnd);
			/* Check for the presence of a comment prefix */
			if( SyStringCmp2(pStr,pPrefix,SyMemcmp) != 0 ){
				rc = SyBlobSearch(pStr->zString,pStr->nByte,pPrefix->zString,pPrefix->nByte,&nPos);
				if( rc != SXRET_OK ){
					continue;
				}
				pStr->nByte = nPos;
				/* Push back literal and synchronize the stream cursor */
				while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
					pStream->zText--;
				}
				continue;
			}
			zPtr = pStr->zString;
			zPtrEnd = &pStr->zString[pStr->nByte];
			zPtr += pPrefix->nByte;
			/* Delimit the comment */
			if( (pEnd->nByte == sizeof(char) && pEnd->zString[0] == '\n') ||
				(pEnd->nByte == sizeof("\r\n") - 1 && pEnd->zString[0] == '\r' && pEnd->zString[1] == '\n' )){
					/* Inline comments:Consume until a LF is found */
					while( zPtr < (const char *)pStream->zEnd && zPtr[0] != '\n' ){
						zPtr++;
					}
			}else{
				while( zPtr < zPtrEnd ){
					if( (sxu32)(zPtrEnd - zPtr) >= pEnd->nByte && SyMemcmp(zPtr,pEnd->zString,pEnd->nByte) == 0 ){
						break;
					}
					if( zPtr[0] == '\n' ){
						pStream->nLine++;
					}
					/* Advance the stream cursor */
					zPtr++;
				}
				if( zPtr >= zPtrEnd ){
					zPtr = (const char *)pStream->zText;
					zPtrEnd = (const char *)pStream->zEnd;
					while( zPtr < zPtrEnd && (sxu32)(zPtrEnd - zPtr) >= pEnd->nByte ){
						if( zPtr[0] == '\n' ){
							pStream->nLine++;
						}
						if( SyMemcmp(zPtr,pEnd->zString,pEnd->nByte) == 0 ){
							break;
						}
						/* Advance the stream cursor */
						zPtr++;
					}
				}
				if( (sxu32)(zPtrEnd - zPtr) >= pEnd->nByte ){
					zPtrEnd = &zPtr[pEnd->nByte];
					zPtr++;
					while( zPtr < zPtrEnd ){
						if( zPtr[0] == '\n' ){
							pStream->nLine++;
						}
						zPtr++;
					}
				}
			}
			/* Synchronize pointers */
			pStream->zText = (const unsigned char *)zPtr;
			/* Record token type and length */
			pToken->nType = XPP_TK_COMMENT;
			pStr->nByte = (sxu32)(zPtr-pStr->zString);
			pEngine->nComment++;
			/* Ignore comment */
			return SXERR_CONTINUE;
		}
		/* Isolate argument delimiter and separator */
		pPrefix = &pConf->aArgDelim[0];
		pEnd = &pConf->aArgDelim[1];
		if( SyStringCmp2(pStr,pPrefix,SyMemcmp) == 0 ){
			/* Record token type and length */
			pStr->nByte = pPrefix->nByte;
			pToken->nType = XPP_TK_ARG_START;
			/* Push back literals and synchronize the stream cursor */
			while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
				pStream->zText--;
			}
			return SXRET_OK;
		}else if( SXRET_OK == SyBlobSearch(pStr->zString,pStr->nByte,pPrefix->zString,pPrefix->nByte,&nPos) ){
			pStr->nByte = nPos;
			/* Push back literals and synchronize the stream cursor */
			while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
				pStream->zText--;
			}
		}
		if( SyStringCmp2(pStr,pEnd,SyMemcmp) == 0 ){
			/* Record token type and length */
			pStr->nByte = pEnd->nByte;
			pToken->nType = XPP_TK_ARG_END;
			/* Push back literals and synchronize the stream cursor */
			while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
				pStream->zText--;
			}
			return SXRET_OK;
		}else if( SXRET_OK == SyBlobSearch(pStr->zString,pStr->nByte,pEnd->zString,pEnd->nByte,&nPos) ){
			pStr->nByte = nPos;
			/* Push back literals and synchronize the stream cursor */
			while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
				pStream->zText--;
			}
		}
		pPrefix = &pConf->sArgSep;
		if( SyStringCmp2(pStr,pPrefix,SyMemcmp) == 0 ){
			/* Record token type and length */
			pStr->nByte = pPrefix->nByte;
			pToken->nType = XPP_TK_ARG_SEP;
			/* Push back literal and synchronize the stream cursor */
			while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
				pStream->zText--;
			}
			return SXRET_OK;
		}else if( SXRET_OK == SyBlobSearch(pStr->zString,pStr->nByte,pPrefix->zString,pPrefix->nByte,&nPos) ){
			pStr->nByte = nPos;
			/* Push back literals and synchronize the stream cursor */
			while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
				pStream->zText--;
			}
		}
		/* Garbage token */
		pToken->nType = XPP_TK_GARBAGE;
	}
	pConf->bLF = FALSE;
	return SXRET_OK;
}
/*
 * Tokenize a macro body.
 * This function does the same job as [PreprocessorTokenizeInput()] except 
 * that is called to tokenize a macro body instead of the entire input.
 */
static sxi32 PreprocessorTokenizeMacroBody(SyStream *pStream,SyToken *pToken,void *pUserData,void *pCtxData)
{
	const unsigned char *zIn;
	SyString *pSuffix;
	xpp_conf *pConf;
	SyString *pStr;
	xpp *pEngine;
	sxu32 nPos;

	pEngine = (xpp *)pUserData;
	pConf = &pEngine->sConfig;
	pStr = &pToken->sData;
	/* Record token starting position  */
	SyStringInitFromBuf(pStr,pStream->zText,pStream->zEnd-pStream->zText);
	pSuffix = (SyString *)pCtxData;
	pToken->pUserData = 0;
	pToken->nLine = 0;
	/* Extract a single token from the input */
	for(;;){
		zIn = pStream->zText;
		/* Skip UTF-8 and alphanumeric stream */
		while( zIn < pStream->zEnd && zIn[0] < 0xc0 && (SyisAlphaNum(zIn[0]) || zIn[0] == '_') ){
				zIn++;
		}
		if( zIn < pStream->zEnd && zIn[0] >= 0xc0 ){
			zIn++;
			/* UTF-8 stream */
			while( zIn < pStream->zEnd && ((zIn[0] & 0xc0) == 0x80) ){
				zIn++;
			}
		}
		if( zIn == pStream->zText ){
			/* Not an UTF-8 or alphanumeric stream */
			break;
		}
		/* Synchronize pointers */
		pStream->zText = zIn;
	}
	if( (const char *)pStream->zText > pStr->zString ){
		if( pStr->nByte == sizeof("__VA_ARGS__")-1 && SyMemcmp(pStr->zString,"__VA_ARGS__",sizeof("__VA_ARGS__")-1) == 0 ){
				/* Emulate the C preprocessor __VA_ARGS__ operator */
				pToken->nType = XPP_TK_VAARG;
		}else{
			/* Record token type and length */
			pToken->nType = XPP_TK_RAW;
			pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
			if( pSuffix && SyStringCmp(pStr,pSuffix,SyMemcmp) == 0 ){
				if( pStream->pSet ){					
					SyToken *pTmp;
					while( (pTmp = (SyToken *)SySetPeek(pStream->pSet)) != 0 ){
						if( (pTmp->nType & (XPP_TK_LF|XPP_TK_SPACE)) == 0 ){
							break;
						}
						pStream->pSet->nUsed--;
					}
				}
				/* Ignore macro suffix [i.e: 'endef' ] */
				return SXERR_CONTINUE;
			}
		}
		return SXRET_OK;
	}else{
		/* Non-alphanumeric (Garbage) stream */
		if( SyisSpace(pStream->zText[0]) ){
			pStream->zText++;
			while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisSpace(pStream->zText[0])){
				pStream->zText++;
			}
			if( pStream->pSet && SySetUsed(pStream->pSet) <= 0 ){
				/* Ignore leading white spaces */
				return SXERR_CONTINUE;
			}
			/* Record token type and length */
			pToken->nType = XPP_TK_SPACE;
			pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
			return SXRET_OK;
		}
		if( pStream->zText[0] == '$' && 
			((pStream->zText[1] < 0xc0 && SyisDigit(pStream->zText[1])) || pStream->zText[1] == '#' || pStream->zText[1] == '*' || pStream->zText[1] == '@')){
				pStream->zText += 2;
				/* Candidate for M4 argument substitution */
				while( pStream->zText < pStream->zEnd  && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
					/* Advance the stream cursor */
					pStream->zText++;
				}
				/* Record token type and length */
				pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
				pToken->nType = XPP_TK_GARBAGE;
				return SXRET_OK;
		}
		while( pStream->zText < pStream->zEnd  && pStream->zText[0] < 0xc0 && !SyisAlpha(pStream->zText[0]) &&
			pStream->zText[0] != '_' && !SyisSpace(pStream->zText[0]) ){
				/* Advance the stream cursor */
				pStream->zText++;
				if(/* pStream->zText < pStream->zEnd && */ pStream->zText[0] == '$' ){
					break;
				}
		}
		while( (const char *)pStream->zText > &pStr->zString[1] && pStream->zText[-1] == '\\' ){
			pStream->zText--;
		}
		/* Record token length */
		pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
		if( pStr->nByte == sizeof(char) && pStr->zString[0] == 0 ){
			/* Ignore this token */
			return SXERR_CONTINUE;
		}
		if(SyStringLength(&pConf->sStringify) > 0 && 
			SyStringCmp(pStr,&pConf->sStringify,SyMemcmp) == 0 ){
				/* Stringify operator */
				pToken->nType = XPP_TK_STRINGING;
				return SXRET_OK;
		}
		if( pStr->nByte == sizeof(char) && pStr->zString[0] == '\\' ){
			const unsigned char *zStream = pStream->zText;
			if( pStream->zText >= pStream->zEnd ){
				/* Ignore the last backslash */
				return SXERR_CONTINUE;
			}
			while( zStream < pStream->zEnd && zStream[0] < 0xc0 && SyisSpace(zStream[0]) ){
				if( zStream[0] == '\n' ){
#ifdef __WINNT__
					if( zStream > pStream->zInput && zStream[-1] == '\r' ){
						zStream--;
					}
#endif
					/* We can safely ignore this backslash */
					pStream->zText = zStream; /* Synchronize pointers */
					return SXERR_CONTINUE;
				}
				zStream++;
			}
		}
		if( pSuffix && !SyisAlphaNum(pSuffix->zString[0])){
			if( SyStringCmp2(pStr,pSuffix,SyMemcmp) == 0 ){
				if( pStream->pSet ){
					SyToken *pTmp;
					while( (pTmp = (SyToken *)SySetPeek(pStream->pSet)) != 0 ){
						if( (pTmp->nType & (XPP_TK_LF|XPP_TK_SPACE)) == 0 ){
							break;
						}
						pStream->pSet->nUsed--;
					}
				}
				/* Push back literal and synchronize the stream cursor */
				while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
					pStream->zText--;
				}
				/* Ignore macro suffix */
				return SXERR_CONTINUE;
			}else if( SXRET_OK == SyBlobSearch(pStr->zString,pStr->nByte,pSuffix->zString,pSuffix->nByte,&nPos) ){
				pStr->nByte = nPos;
				/* Push back literals and synchronize the stream cursor */
				while( (const char *)pStream->zText > &pStr->zString[pStr->nByte] ){
					pStream->zText--;
				}
			}
		}
		/* Garbage token */
		pToken->nType = XPP_TK_GARBAGE;
	}
	return SXRET_OK;
}
/*
 * Internal input consumer callback.
 * Whenever a macro expand to another macro,then the default consumer routine is
 * replaced by this one.
 * The role of this callback is to collect the expanded input in order to be
 * expanded again by the macro processor.
 * On success this function return SXRET_OK,any other value indicates failure
 * (an unlikely scenario) and the expanding operation is aborted immediately.
 */
static sxi32 MacroBlobConsumer(const void *pSrc,unsigned int nLen,void *pUserData)
 {
	 sxi32 rc;
	 rc = SyBlobAppend((SyBlob *)pUserData,pSrc,(sxsize)nLen);
	 return rc;
 }
/*
 * Output token verbatim without any processing.
 * When the USER_MACRO_IGNORE_EXPANDING flag is set for a registered macro which mean
 * do not expand the macro output again (a recursive operation) then this function is 
 * called instead of [PreprocessorExpandInput()].
 * The role of this routine is to consume the input tokens verbatim without any processing.
 * The USER_MACRO_IGNORE_EXPANDING flag can improve performance greatly since it avoid 
 * an other recursive call to [PreprocessorExpandInput()],so it's good habit to set this
 * flag when you register your own macro via [xpp_register_macro()] or [xpp_queue_macro()]
 * interfaces if you are sure that your macros will not expand another macro definition 
 * like the MD5 or the OS built-in macros.
 * This function return SXRET_OK on success,any other value indicates failure and the
 * processing is aborted.
 */
static sxi32 PreprocessorVerbatimOutput(SyToken *aToken,sxu32 nToken,ProcConsumer xConsumer,void *pConsumerData,sxi32 iFlags)
{
	sxu32 n = 0;
	sxi32 rc;

	for(;;){
		if( n >= nToken ){
			break;
		}
		if( (iFlags & XPP_IGNORE_WS) && (aToken[n].nType & (XPP_TK_SPACE|XPP_TK_LF)) ){
			/* Ignore white space completely */
			n++;
			continue;
		}
		rc = xConsumer((const void *)SyStringData(&aToken[n].sData),SyStringLength(&aToken[n].sData),pConsumerData);
		if( rc != SXRET_OK ){
			/* Consumer callback request an operation abort */
			return rc;
		}
		n++;
		if( iFlags & XPP_REDUCE_WS ){
			if( aToken[n-1].nType & XPP_TK_SPACE ){
				/* Collapse white space stream into a single space */
				while( n < nToken && (aToken[n].nType & XPP_TK_SPACE) ){
					++n;
				}
			}else if( aToken[n-1].nType & XPP_TK_LF ){
				/* Collapse blank lines stream into a single line */
				while( n  < nToken && (aToken[n].nType & (XPP_TK_LF|XPP_TK_SPACE)) ){
					++n;
				}
			}
		}
	}
	return SXRET_OK;
}
/*
 * Tokenize the entire input and collect tokens of interest.
 * This function is simply a wrapper around [PreprocessorTokenizeInput()]
 * which call it in order to extract low level tokens from the input.
 * This function return SXRET_OK on success,any other value indicates failure.
 */
static sxi32 PreprocessorProcessInput(xpp *pEngine,SySet *pTokenSet,
	const char *zIn,sxu32 nLen,void *pCtxData,sxu32 nCurLine,
	sxu32 *pLines,sxu32 *pIgnored)
{
	SyLex sLex;
	sxi32 rc;

	pEngine->sConfig.bLF = TRUE;
	/* Initialize the lexer */
	SyLexInit(&sLex,&(*pTokenSet),PreprocessorTokenizeInput,&(*pEngine)); 
	sLex.sStream.nLine = nCurLine;
	/* Tokenize the input  */
	rc = SyLexTokenizeInput(&sLex,zIn,nLen,pCtxData,0,0); 
	if( pLines ){
		/* Write total number of processed lines */
		*pLines = SyLexTotalLines(&sLex);
	}
	if( pIgnored ){
		/* Write total number of ignored tokens */
		*pIgnored = SyLexTotalIgnored(&sLex);
	}
	SyLexRelease(&sLex);
	return rc;
}
/*
 * Collect arguments for a function-like macro.
 * When a function-like macro is detected,the macro processor will invoke this routine in
 * order to collect macro arguments.Prior to invoking the callback associated with the macro
 * definition the macro processor will expand the collected arguments (A recursive operation)
 * unless the USER_MACRO_IGNORE_ARG_EXPANDING flag is set when the processed macro was registered
 * via [xpp_register_macro()] or [xpp_queue_macro()] interfaces,after that the macro processor
 * invoke the associated callback with the total number of collected arguments and arguments 
 * values as arguments to the invoked callback.
 * Function-like macro can support two form of arguments:
 * [[flat arguments]]:
 * Those arguments does not need a left and right delimiters and are collected until the end
 * of line.Some of the macro that support flat arguments are:
 * [include,undef...]
 * Example:
 *  include file.txt page.html stdio.h \n
 *  undef X Y Z \n
 * In this case each macro (include and undef) take three white-space separated arguments that
 * will be passed as parameters to the callback associated with those macros [in this case the
 * callbacks are: MacroBuiltin_Include() for the 'include' macro and MacroBuiltin_Undef() for
 * the 'undef' macro]
 * [[Normal arguments]]:
 * Those arguments are right and left delimited.Most of the macro come in this form.
 * Example:
 *   MD5(a,b,c)
 *   BASE64(x,y,z)
 * For more information,refer to official documentation section "Implementing and registering macros".
 * This function return SXRET_OK on success,SXERR_CONTINUE if there is nothing to collect
 * (no arguments are associated with the macro).Any other value indicates failure.
 */
static sxi32 PreprocessorCollectArguments(SySet *pOut,sxi32 iFlags,SyToken *aToken,sxu32 *pTokCursor,sxu32 nToken)
{
	sxu32 n = *pTokCursor;   /* Save current position */
	SyToken *pToken = 0;     /* Current processed token */
	sxi32 iNest = 1;         /* Nesting level */
	sxu32 nIgn;              /* One or more tokens to ignore while collecting arguments
							  * [i.e: white space,comments] 
							  */

	nIgn = XPP_TK_COMMENT|XPP_TK_SPACE;
	if( (iFlags & USER_MACRO_FLAT_ARGS) == 0 ){
		nIgn |= XPP_TK_LF;
	}
	while( n < nToken && (aToken[n].nType & nIgn) != 0 ){
		/* Ignore this token */
		n++;
	}
	if( n >= nToken || (aToken[n].nType & XPP_TK_ARG_START) == 0 ){
		static const SyToken sTokSep = { {0,0},XPP_TK_ARG_SEP,0,0}; 
		if( (iFlags & USER_MACRO_FLAT_ARGS) == 0 ){
			/* Synchronize token cursor */
			*pTokCursor = n;
			/* No arguments associated with this macro */
			return SXERR_CONTINUE;
		}
		/*
		 * flat arguments:
		 * Collect arguments until the end of the line
		 */
		while( n < nToken  ){
			if( aToken[n].nType & XPP_TK_LF ){
				break;
			}
			if( aToken[n].nType & XPP_TK_SPACE ){
				if( SySetUsed(pOut) > 0 ){
					/* Treat as argument separator */
					SySetPut(pOut,(const void *)&sTokSep);
				}
			}else if ( (aToken[n].nType & XPP_TK_COMMENT) == 0 ){
				/* Save argument */
				SySetPut(pOut,(const void *)&aToken[n]);
			}
			/* Advance cursor */
			n++;
		}
		/* Synchronize token cursor */
		*pTokCursor = n + 1;
		return SXRET_OK;
	}
	/* Left and right delimited arguments */
	n++; /* Jump the left delimiter */
	for(;;){
		if( iNest <= 0 ){
			break;
		}
		 if( n >= nToken ){	break; }
		 pToken = &aToken[n];
		 /* Advance cursor */
		 n++;
		 if( (pToken->nType & (XPP_TK_ARG_END|XPP_TK_COMMENT)) == 0 ){
			 /* Save argument */
			 SySetPut(pOut,(const void *)pToken);
			 if( pToken->nType & XPP_TK_ARG_START ){
				 /* Increment nesting level */
				 iNest++;
			 }
			 continue;
		 }
		 if( pToken->nType & XPP_TK_ARG_END ){
			/* Decrement nesting level */
			 iNest--;
			 if( iNest > 0 ){
				 /* Save argument */
				 SySetPut(pOut,(const void *)pToken);
				 continue;
			 }
		 }
	}
	/* Synchronize token cursor */
	*pTokCursor = n;
	if( iNest > 0 ){
		/* Missing right argument [i.e: ')'] delimiter */
		return SXERR_SYNTAX;
	}
	return SXRET_OK;
}
/*
 * After a successful return from [PreprocessorExpandArguments()] the macro processor
 * call this function in order to assemble the expanded arguments values.
 * Note that a single working buffer is used for holding expanded arguments values.
 * Therefore argument must be separated by a boundary defined at compile-time via the
 * XPP_ARG_BOUNDARY macro.
 * The default value of the boundary for this version is "--xPP-A1G-BO7NdA8Y-261432--".
 * This technique is inspired from the one used by the HTTP protocol[RFC 2616] for 
 * the purpose of multi-part byte range requests.
 * This function return SXRET_OK on success,any other value indicates failure.
 */
static sxi32 PreprocessorAssembleArguments(SyBlob *pWorker,SySet *pOut,sxi32 iFlags)
{
	char *zIn,*zEnd,*zCur;
	SyString sArg;
	sxi32 rc;

	zIn = ( char *)SyBlobData(pWorker);
	zEnd = &zIn[SyBlobLength(pWorker)];

	for(;;){
		if( zIn >= zEnd ){
			/* End of input reached */
			break;
		}
		zCur = zIn;
		while( ((sxsize)(zEnd - zIn) > sizeof(XPP_ARG_BOUNDARY) - 1)  && SyMemcmp(zIn,XPP_ARG_BOUNDARY,sizeof(XPP_ARG_BOUNDARY)-1) != 0 ){
			zIn++;
		}
		if( zIn > zCur ){
			/* Save argument in the arg set */
			SyStringInitFromBuf(&sArg,zCur,zIn - zCur);
			if( iFlags & XPP_TRIM_ARGS ){
				/* Remove leading and trailing white spaces */
				SyStringFullTrim(&sArg);
			}
			if( sArg.nByte > 0 ){
				rc = SySetPut(pOut,(const void *)&sArg);
				if( rc != SXRET_OK ){
					return rc;
				}
				/* Replace the boundary with a null terminator */
				zCur = (char *)sArg.zString;
				zCur[sArg.nByte] = 0;
			}
		}
		/* Advance cursor */
		zIn += sizeof(XPP_ARG_BOUNDARY)-1;
	}
	return SXRET_OK;
}
/* Forward declaration */
static sxi32 PreprocessorExpandInput(xpp *pEngine,SyToken *aToken,sxu32 nToken,ProcConsumer xConsumer,void *pConsumerData,sxi32 iFlags);
static sxi32 PreprocessorExpandArguments(xpp *pEngine,SySet *pIn,ProcConsumer xConsumer,void *pConsumerData,sxi32 iFlags,sxi32 iMacroFlags);
static sxi32 MacroBuiltin_Error(xpp_context *pCtx,int nArg,const SyString *azArg);
#ifndef XPP_OMIT_BUILTIN
static int MacroBuiltin_Include(xpp_context *pCtx,int nArg,const SyString *azArg);
static int MacroBuiltin_Import(xpp_context *pCtx,int nArg,const SyString *azArg);
static sxi32 SySetTruncate(SySet *pSet,sxu32 nNewSize);
#endif
/*
 * Each time the macro processor extract a raw token [ Alphanumeric and/or UTF-8 stream]
 * this function is called in order to process the target token.
 * The algorithm is as follows:
 * If the target token is not a registered macro.That is,the macro hashtable return the NULL
 * pointer,then this routine output the token value verbatim without any processing and 
 * it return immediately.
 * Otherwise,if the token resolve to a registered macro definition then the following
 * steps are taken:
 * The nesting limit is checked first and if this limit is reached the processing is
 * aborted,the macro is not expanded and the function return SXERR_LIMIT.
 * If the target macro is a function-like macro then arguments are collected first
 * and expanded if the USER_MACRO_IGNORE_ARG_EXPANDING flag is not set.
 * Prior to invoking the macro callback,this routine check for an installed trace callback
 * and if so,the trace callback is invoked.
 * After that,the macro context is initialized and the callback associated with the macro 
 * is invoked.
 * If the callback return a value different from XPP_OK then the processing is aborted
 * and this function return SXERR_ABORT.
 * Otherwise if the USER_MACRO_IGNORE_EXPANDING flag is not set which mean do not expand
 * the macro body and output it verbatim,then this function is called again(recurse) 
 * in order to process the expanded macro body.
 * For more information on the macro processing algorithm refer to the official 
 * documentation section "xPP internals".
 */
static sxi32 PreprocessorExpandToken(xpp *pEngine,SyToken *aToken,sxu32 *pTokCursor,sxu32 nToken,
	ProcConsumer xConsumer,void *pConsumerData)
{
	SySet aTokenSet,aArgTok,aArgSet; /* Containers for token and collected arguments */
	SyString *pTokenData;            /* Token raw data */
	SyHashEntry *pEntry;	         /* Hashtable entry */
	xpp_context sCtx;                /* Macro context:First arg to the callback associated with the macro */
	SyMacro *pMacro;                 /* Macro definition (Hashtable user data) */
	SyString *aArg;                  /* Expanded macro arguments */
	SyBlob sArgBuf;                  /* Containers for the expanded arguments */
	SyBlob sWorker;                  /* Containers for the expanded macro body */ 
	sxu32 nLine;                     /* Token line number */ 
	sxu32 nPath;
	int nArg;                        /* Total number of collected arguments */
	sxi32 rc;

	/* Extract fields of interest */
	pTokenData = &aToken[(*pTokCursor)].sData;
	nLine = aToken[(*pTokCursor)].nLine;
	rc = SXRET_OK;
	/* Advance cursor */
	(*pTokCursor)++;
	/* Check for a macro definition */
	pEntry = SyHashGet(&pEngine->hMacro,pTokenData->zString,pTokenData->nByte);
	if( pEntry == 0 ){
		/* There is no definition associated with this token.That is,output token as it is */
		rc = xConsumer(pTokenData->zString,pTokenData->nByte,pConsumerData);
		return rc;
	}
	/* Make sure we do not nest too much */
	if( pEngine->nNest > pEngine->sConfig.nNest ){
		/* Nesting limit reached */
		pEngine->nErr++;
		PreprocessorConsumeError(&(*pEngine),XPP_ERR_NESTING_LIMIT,nLine,
			"'%z': Nesting limit reached while expanding macro definition\n",
			pTokenData);
		return SXERR_LIMIT;
	}
	/* At this point,we have a macro definition,try to expand it */
	pMacro = (SyMacro *)SyHashEntryGetUserData(pEntry);
	/* Increment nesting level */
	pEngine->nNest++;
	/* Initialize components */
	SySetInit(&aTokenSet,&pEngine->sAllocator,sizeof(SyToken));
	SySetInit(&aArgSet,&pEngine->sAllocator,sizeof(SyString));
	SySetInit(&aArgTok,&pEngine->sAllocator,sizeof(SyToken));
	SyBlobInit(&sArgBuf,&pEngine->sAllocator);
	SyBlobInit(&sWorker,&pEngine->sAllocator);
	aArg = 0;
	nArg = 0;
	if( (pMacro->iFlags & (USER_MACRO_COLLECT_ARGS|USER_MACRO_FLAT_ARGS)) == 0 ){
		if( pMacro->iFlags & USER_MACRO_STRICT_INVOKE ){
			sxu32 n = (*pTokCursor);
			while( n < nToken ){
				if( aToken[n].nType & (XPP_TK_COMMENT|XPP_TK_SPACE|XPP_TK_LF) ){
					/* Ignore comment,spaces and so on */
					n++; continue;
				}
				break;
			}
			/* Check for the presence of the left argument delimiter */
			if( n < nToken && (aToken[n].nType & XPP_TK_ARG_START) != 0 ){
				/* Output token verbatim,without expanding the macro as requested by the strict invoke flag
				 * since the left argument delimiter is found and so we follow the C pre-processor logic.
				 */
				rc = xConsumer(pTokenData->zString,pTokenData->nByte,pConsumerData);
				goto Release;
			}
		}
	}else{
		sxu32 n = (*pTokCursor);
		/* Collect arguments */
		rc = PreprocessorCollectArguments(&aArgTok,pMacro->iFlags,aToken,pTokCursor,nToken);
		if( rc == SXERR_SYNTAX){
			/* Missing right argument delimiter */
			pEngine->nErr++;
			PreprocessorConsumeError(&(*pEngine),XPP_ERR_MISSING_ARG_DELIM,nLine,
				"'%z' on line %u: Missing right argument delimiter\n",
				pTokenData,nLine);
			/* Not so fatal: FALL THRU */
			rc = SXRET_OK;
		}
		if( rc != SXRET_OK ){
			/* Reset our token cursor */
			*pTokCursor = n;
			if( pMacro->iFlags & USER_MACRO_STRICT_INVOKE ){
				/* Strict invoke require that arguments be present,this is not the case */
				rc = xConsumer(pTokenData->zString,pTokenData->nByte,pConsumerData); /* Output token verbatim */
				goto Release;
			}
		}else{
			/* Process arguments first before passing them to the invoked macro */
			PreprocessorExpandArguments(&(*pEngine),&aArgTok,MacroBlobConsumer,&sArgBuf,pEngine->iFlags,pMacro->iFlags);
			if( SyBlobLength(&sArgBuf) > 0 ){
				/* Assemble arguments */
				PreprocessorAssembleArguments(&sArgBuf,&aArgSet,pEngine->iFlags);
				/* Extract resolved arguments */
				aArg = (SyString *)SySetBasePtr(&aArgSet);
				nArg = (int)SySetUsed(&aArgSet);
			}
		}
	}
	/* Invoke the trace callback if available */
	nPath = SySetUsed(&pEngine->sConfig.aFiles);
	if( pEngine->xTrace && SXERR_ABORT == pEngine->xTrace(pEngine->pTraceData,(const char *)pEntry->pKey,
		PreprocessorGetProcessedFilePath(pEngine),(int)nLine,nArg,aArg) ){
		/* Trace callback request an operation abort.That is,macro invocation is canceled
		 * and the macro name is outputted verbatim.
		 */
		rc = xConsumer(pTokenData->zString,pTokenData->nByte,pConsumerData);
		goto Release;
	}
	if( pMacro->iFlags & USER_MACRO_EMPTY ){
		/* No callback is associated with this macro */
		goto Release; /* Ignore expanding */
	}
	/* Initialize the macro context */
	if( (pMacro->iFlags & USER_MACRO_IGNORE_EXPANDING) && pEngine->nNest < 2 ){
		/* Pass the given consumer directly to the context,since the expanded macro
		 * will not be processed anyway,this will improve performance greatly.
		 */
		PreprocessorInitContext(&sCtx,&(*pEngine),pEntry,nLine,pMacro,xConsumer,pConsumerData);
	}else{
		PreprocessorInitContext(&sCtx,&(*pEngine),pEntry,nLine,pMacro,MacroBlobConsumer,&sWorker);
	}
	/* Invoke the callback associated with this macro.
	 * This callback is responsible of expanding macro body.
	 */
	rc = pMacro->xMacro(&sCtx,nArg,aArg);
	if( sCtx.iFlags & XPP_CTX_CONS_ABORT ){
		/* Consumer routine request an operation abort */
		return sCtx.rc;
	}else if( rc == SXRET_OK && SyBlobLength(&sWorker) > 0 ){
		if( pMacro->iFlags & USER_MACRO_IGNORE_EXPANDING ){
			/* Output expanded data without any processing as requested by the USER_MACRO_IGNORE_EXPANDING flags.
			 */
			xConsumer(SyBlobData(&sWorker),SyBlobLength(&sWorker),pConsumerData);
		}else{
#ifndef XPP_OMIT_BUILTIN
			if( pMacro->xMacro == MacroBuiltin_Include || pMacro->xMacro == MacroBuiltin_Import ){
				/* Reset line cursor when processing included files */
				nLine = 1;
			}
#endif
			rc = PreprocessorProcessInput(&(*pEngine),&aTokenSet,(const char *)SyBlobData(&sWorker),SyBlobLength(&sWorker),
				(void *)(pMacro->iFlags|USER_MACRO_NEST),nLine,0,0);
			if( SySetUsed(&aTokenSet) > 0 && rc == SXRET_OK ){
				if( pMacro->iFlags & USER_MACRO_TRIM_ONLY ){
					rc = PreprocessorVerbatimOutput((SyToken *)SySetBasePtr(&aTokenSet),SySetUsed(&aTokenSet),xConsumer,pConsumerData,pEngine->iFlags);
				}else{
					/* Now,recurse and process the expanded input */
					rc = PreprocessorExpandInput(&(*pEngine),(SyToken *)SySetBasePtr(&aTokenSet),SySetUsed(&aTokenSet),
						xConsumer,pConsumerData,pEngine->iFlags);
				}
			}
		}
	}else if( rc == SXERR_ABORT && pMacro->xMacro != MacroBuiltin_Error ){
		/* Macro expansion callback request an operation abort */
		pEngine->nErr++;
		PreprocessorConsumeError(&(*pEngine),XPP_ERR_ABORT,nLine,
			"'%z' on line %u: Macro expansion callback request an operation abort\n",
			pTokenData,nLine);
	}
#ifndef XPP_OMIT_BUILTIN
	if( pMacro->xMacro == MacroBuiltin_Include || pMacro->xMacro == MacroBuiltin_Import ){
		xpp_conf *pConf = &pEngine->sConfig;
		SyString *aEntries;
		char *zPath;
		sxu32 n;
		aEntries = (SyString *)SySetBasePtr(&pConf->aFiles);
		for( n =  nPath ; n < SySetUsed(&pConf->aFiles) ; ++n ){
			zPath = (char *)aEntries[n].zString;
			SyMemBackendFree(&pEngine->sAllocator,(void *)zPath);
		}
		SySetTruncate(&pConf->aFiles,nPath);
	}
#endif
Release:
	/* Decrement nesting level */
	pEngine->nNest--;
	/* Release all resource consumed by the expanding operation */
	SySetRelease(&aTokenSet);
	SyBlobRelease(&sArgBuf);
	SySetRelease(&aArgSet);
	SySetRelease(&aArgTok);
	SyBlobRelease(&sWorker);
	return rc;
}
/*
 * When a conditional macro directive evaluates to FALSE,then this function
 * is called in order to synchronize the stream cursor with the block beyond
 * the FALSE [if/elif/else] block.
 */
static void PreprocessorJumpIfToken(SyToken *aToken,sxu32 nType,sxu32 *pCursor,sxu32 nToken)
{
    sxi32 iNest = 1;
	sxu32 n;
	
	n = *pCursor;
	/* Jump the false block */
	for(;;){
		if( n >= nToken ){
			break;
		}
		if( aToken[n].nType & (XPP_TK_IF|XPP_TK_IFDEF|XPP_TK_IFNDEF) ){
			/* Increment nesting level */
			iNest++;
		}else if( aToken[n].nType & XPP_TK_ENDIF ){
			/* Decrement nesting level */
			iNest--;
			if( nType & XPP_TK_ENDIF ){
				if( iNest <= 0 ){
					break;
				}else{
					n++; continue;
				}
			}
		}
		if( (aToken[n].nType & nType) != 0 && iNest <= 1 ){
			break;
		}
		++n;
	}
	*pCursor = n;
}
/*
 * Collect tokens defined in a [if],[ifdef],[ifndef],[else] or [elif]
 * block.
 * When a conditional macro directive evaluates to TRUE,then this function is called
 * in order to collect tokens defined in this block that will be processed shortly.
 * This function return the total number of collected tokens.
 */
static sxu32 PreprocessorCollectIfToken(SyToken *aToken,sxu32 nType,sxu32 nToken)
{
	sxi32 iNest = 1;
	sxu32 n = 0;
	
	/* Collect tokens */
	for(;;){
		if( n >= nToken ){
			break;
		}
		if( aToken[n].nType & (XPP_TK_IF|XPP_TK_IFDEF|XPP_TK_IFNDEF) ){
			/* Increment nesting level */
			iNest++;
		}else if( aToken[n].nType & XPP_TK_ENDIF ){
			/* Decrement nesting level */
			iNest--;
			if( nType & XPP_TK_ENDIF ){
				if( iNest <= 0 ){
					break;
				}else{
					n++; continue;
				}
			}
		}
		if( (aToken[n].nType & nType) != 0 && iNest <= 1 ){
			break;
		}
		++n;
	}
	return n;
}
/* Forward declaration */
static sxi32 SyHexToint(sxi32 hc);
/*
 * Process a constant string literal by resolving all escape sequences.
 * When the processed token is a string literal and the [xpp_expand()] interface is
 * called with the XPP_UNESCAPE_STRING flag set then this function is called in order
 * to process the escape sequences (\n,\r,\\...).
 * The recognized escape sequence are the same processed by the UNIX 'awk' program
 * which are:
 * '\\': A literal backslash
 * 'a': The "alert" character (BEL)[ctrl+g] ASCII code 7 
 * 'b': Backspace (BS)[ctrl+h] ASCII code 8 
 * 'f': Form-feed (FF)[ctrl+l] ASCII code 12
 * 'n': Line feed(new line) (LF)[ctrl+j] ASCII code 10
 * 'r': Carriage return (CR)[ctrl+m] ASCII code 13
 * 't': Horizontal tab (HT)[ctrl+i] ASCII code 9 
 * 'v': Vertical tab(VT)[ctrl+k] ASCII code 11 
 * '\'': Single quote 
 * '"': Double quote
 * 'x': Hexadecimal digit stream
 * 'o': One to three octal digit stream
 * This function return SXRET_OK on success,any other value indicates failure.
 */
static sxi32 PreprocessorHandleString(SyString *pStr,ProcConsumer xConsumer,void *pConsumerData)
{
	const char *zEnd;
	const char *zCur;
	const char *zIn;
	sxi32 rc;
	sxu32 n;
	/* Delimit the string first */
	zIn = pStr->zString;
	zEnd = &pStr->zString[pStr->nByte];
	n = 1;
	/* Resolve escape sequences */
	for(;;){
		zCur = zIn;
		while( zIn < zEnd && zIn[0] != '\\' ){
			zIn++;
		}
		if( zIn > zCur ){
			/* Consume raw input */
			rc = xConsumer((const void *)zCur,(sxu32)(zIn-zCur),pConsumerData);
			if( rc != SXRET_OK ){
				/* Consumer callback request an operation abort */
				return rc;
			}
		}
		zIn++; /* Jump the backslash */
		if( zIn >= zEnd ){
			/* No more input to process */
			break;
		}
		n = sizeof(char); /* Size of conversion */
		rc = SXRET_OK; /* Prevent compiler warning */
		/* Process escape sequence */
		switch(zIn[0]){
		case '\\':
			/* A literal backslash */
			rc = xConsumer((const void *)"\\",sizeof(char),pConsumerData);
			break;
		case 'a':
			/* The "alert" character (BEL)[ctrl+g] ASCII code 7 */
			rc = xConsumer((const void *)"\a",sizeof(char),pConsumerData);
			break;
		case 'b':
			/* Backspace (BS)[ctrl+h] ASCII code 8 */
			rc = xConsumer((const void *)"\b",sizeof(char),pConsumerData);
			break;
		case 'f':
			/* Form-feed (FF)[ctrl+l] ASCII code 12 */
			rc = xConsumer((const void *)"\f",sizeof(char),pConsumerData);
			break;
		case 'n':
			/* Line feed(new line) (LF)[ctrl+j] ASCII code 10 */
			rc = xConsumer((const void *)"\n",sizeof(char),pConsumerData);
			break;
		case 'r':
			/* Carriage return (CR)[ctrl+m] ASCII code 13 */
			rc = xConsumer((const void *)"\r",sizeof(char),pConsumerData);
			break;
		case 't':
			/* Horizontal tab (HT)[ctrl+i] ASCII code 9 */
			rc = xConsumer((const void *)"\t",sizeof(char),pConsumerData);
			break;
		case 'v':
			/* Vertical tab(VT)[ctrl+k] ASCII code 11 */
			rc = xConsumer((const void *)"\v",sizeof(char),pConsumerData);
			break;
		case '\'':
			/* Single quote */
			rc = xConsumer((const void *)"'",sizeof(char),pConsumerData);
			break;
		case '"':
			/* Double quote */
			rc = xConsumer((const void *)"\"",sizeof(char),pConsumerData);
			break;
		case 'x':
			if( SyisHex(zIn[1]) ){
				sxu8 bExitLoop = FALSE;
				char zOut[2];
				int c;
				zCur = &zIn[1];
				/* Hex digit stream */
				while( zCur < zEnd && (unsigned char)zCur[0] < 0xc0 && SyisHex(zCur[0]) ){
					c = SyHexToint(zCur[0]);
					if( &zCur[1] >= zEnd ){
						break;
					}
					if( SyisHex(zCur[1]) ){
						c = c * 16 + SyHexToint(zCur[1]);
					}else{
						bExitLoop = TRUE;
					}
					zOut[0] = (char)c;
					rc = xConsumer((const void *)zOut,sizeof(char),pConsumerData);
					if( rc != SXRET_OK ){
						return rc;
					}
					if( bExitLoop ){
						zCur++;
						break;
					}else{
						zCur += sizeof(char) * 2;
					}
				}
				n = (sxu32)(zCur-zIn); 
			}else{
				/* Output literal character */
				rc = xConsumer((const void *)"x",sizeof(char),pConsumerData);
			}
			break;
		case 'o':{
			/* One to three octal digit stream */
			char zOut[2];
			int c = 0;
			for( zCur = &zIn[1] ; zCur < &zIn[4*sizeof(char)] ; zCur++ ){
				if( (unsigned char)zCur[0] >= 0xc0 || !SyisDigit(zCur[0]) || (zCur[0] - '0') > 7 ){
					break;
				}
				c = c * 8 + (zCur[0] - '0');
			}
			if ( c > 0 ){
				zOut[0] = (char)c;
				rc = xConsumer((const void *)zOut,sizeof(char),pConsumerData);
			}else if ( zCur == &zIn[1] ){
				/* Output literal character */
				rc = xConsumer((const void *)"o",sizeof(char),pConsumerData);
			}
			n = (sxu32)(zCur-zIn);
			break;
				 }
		default:
			/* Strip the backslash out and keep the character */
			rc = xConsumer((const void *)zIn,sizeof(char),pConsumerData);
			break;
		}
		if( rc != SXRET_OK ){
			/* Consumer callback request an operation abort */
			return rc;
		}
		/* Synchronize pointers */
		zIn += n;
	}
	return SXRET_OK;
}
/*
 * Expand all input tokens.
 * After the tokenizer assemble raw input into a set of tokens,the macro processor 
 * call this routine in order to process the collected tokens.
 * Only XPP_TK_RAW (Aplhanumeric and/or UTF-8 stream) token are processed.
 * That is,a call to [PreprocessorExpandToken()] is made to check for a registered macro
 * definition and the expanding operation is performed only in this place.
 * All the other tokens (garbage and non-alphanumeric stream) are outputted verbatim 
 * without any processing except if the following flag are set which affect how some
 * tokens (space,string) are processed:
 *   XPP_IGNORE_WS:
 * White space here,is completely ignored and so the expanded input appears to have
 * no white spaces.
 *  XPP_REDUCE_WS:
 * If this flag is set then all successive white spaces are reduced to a single space
 * and successive blank lines are reduced to a single line.
 *  XPP_UNESCAPE_STRING:
 * If this flag is set then all constant string literal are processed by resolving all
 * escape sequences,this is done via call to [PreprocessorHandleString()].
 *
 * This function return SXRET_OK on success,any other value indicates failure.
 * For more information on the macro processing algorithm refer to the official 
 * documentation section "xPP internals".
 */
static sxi32 PreprocessorExpandInput(xpp *pEngine,SyToken *aToken,sxu32 nToken,
	ProcConsumer xConsumer,void *pConsumerData,sxi32 iFlags)
{
	SyCondDirective *pCond;
	SyToken *pToken;	
	sxi32 rc;
	sxu32 n;

	/* Assign default value if not properly set */ 
	if( xConsumer == 0 ){
		xConsumer = pEngine->xConsumer;
		pConsumerData = pEngine->pConsumerData;
	}
	if( iFlags < 0 ){
		iFlags = pEngine->iFlags;
	}
	n = 0;
	/* Expand the input */
	for(;;){
		if( n >= nToken ){ 
			/* End of input */
			break;
		}
		pToken = &aToken[n];
		if( (pToken->nType & (XPP_TK_RAW|XPP_TK_COND)) == 0 ){
			if( (iFlags & XPP_IGNORE_WS) && (aToken[n].nType & (XPP_TK_SPACE|XPP_TK_LF)) ){
				/* Ignore white space completely */
				n++;
				continue;
			}
			if( pToken->nType == XPP_TK_STRING && (iFlags & XPP_UNESCAPE_STRING) ){
				/* Resolve all escape sequences */
				rc = PreprocessorHandleString(&pToken->sData,xConsumer,pConsumerData);
				if( rc != SXRET_OK ){
					/* Consumer routine request an operation abort */
					return rc;
				}
			}else{
				/* Consume token verbatim */
				rc = xConsumer((const void *)SyStringData(&pToken->sData),SyStringLength(&pToken->sData),pConsumerData);
				if( rc != SXRET_OK ){
					/* Consumer routine request an operation abort */
					return rc;
				}
			}
			/* Increment loop cursor */
			++n;
			if( iFlags & XPP_REDUCE_WS ){
				if( aToken[n-1].nType & XPP_TK_SPACE ){
					/* Collapse white space stream into a single space */
					while( n < nToken && (aToken[n].nType & XPP_TK_SPACE) ){
						++n;
					}
				}else if( aToken[n-1].nType & XPP_TK_LF ){
					/* Collapse blank lines stream into a single line */
					while( n  < nToken && (aToken[n].nType & (XPP_TK_LF|XPP_TK_SPACE)) ){
						++n;					
					}
				}
			}
			continue;
		}
		if( pToken->nType & (XPP_TK_ELIF|XPP_TK_ELSE|XPP_TK_ENDIF) ){
			n++;
			continue;
		}
		if( pToken->nType & (XPP_TK_IF|XPP_TK_IFDEF|XPP_TK_IFNDEF) ){
			/* Expand only if the condition evaluate to TRUE */
			for(;;){
				pCond = (SyCondDirective *)pToken->pUserData;
				if( pCond == 0 ){
					break;
				}
				n++;
				if( pToken->nType & XPP_TK_ELSE ){
					rc = SXRET_OK; 
				}else{
					/* Invoke the eval callback */
					rc = pCond->xEval((xpp_context *)pEngine,(int)SySetUsed(&pCond->aToken),(const SyString *)SySetBasePtr(&pCond->aToken));
					if( rc != SXRET_OK && rc != SXERR_IGNORE ){
						/* Syntax error */
						pEngine->nErr++;
						PreprocessorConsumeError(pEngine,XPP_ERR_INVALID_EXPR,pToken->nLine,
							"%s while parsing conditional macro on line %u\n",
							rc == SXERR_SYNTAX ? "Syntax error" : "Error",
							pToken->nLine
							);
						rc = SXERR_IGNORE; /* Ignore this [if/elif] block */
					}
				}
				if( rc != SXERR_IGNORE ){
					SyMacroDefs **aMacro;
					sxu32 nIfToken;
					sxu32 nCollect;
					SySet *aDefs;
					/* 
					 * The condition evaluates to true.Register all macros defined on this block.
					 */
					aDefs = (pToken->nType & XPP_TK_ELSE) ? &pCond->aElseDefs : &pCond->aDefs;
					aMacro = (SyMacroDefs **)SySetBasePtr(aDefs);
					for( nCollect = 0 ; nCollect < SySetUsed(aDefs) ; ++nCollect ){
						PreprocessorRegisterMacro2(&(*pEngine),&aMacro[nCollect]->sName,MacroBuiltin_Expand,
							(void *)aMacro[nCollect],aMacro[nCollect]->iFlags);
					}
					SySetReset(aDefs);
					nCollect = XPP_TK_ENDIF;
					if( (pToken->nType & XPP_TK_ELSE) == 0 ){
						nCollect |= XPP_TK_ELIF|XPP_TK_ELSE;
					}
					while( n < nToken && (aToken[n].nType & (XPP_TK_SPACE|XPP_TK_LF)) ){
						/* Ignore leading white spaces and blank lines */
						++n;
					}
					if( n >= nToken ){
						break;
					}					
					/* Collect and process tokens that belongs to this block */
					nIfToken = PreprocessorCollectIfToken(&aToken[n],nCollect,nToken-n);
					if( nIfToken > 0 ){
						/* Recurse and process this block */
						rc = PreprocessorExpandInput(&(*pEngine),&aToken[n],nIfToken,xConsumer,pConsumerData,iFlags);
						if( rc != SXRET_OK ){
							return rc;
						}
						n += nIfToken;
						if( n >= nToken ){
							pEngine->nErr++;
							PreprocessorConsumeError(pEngine,XPP_ERR_UNMATCHED_ENDIF,pEngine->nLines,
								"missing 'endif' token on line %u\n",pEngine->nLines);
						}
					}
					if( n < nToken && (aToken[n].nType & XPP_TK_ENDIF) == 0 ){
						/* Synchronize with the next [endif] token */
						PreprocessorJumpIfToken(aToken,XPP_TK_ENDIF,&n,nToken);
						if( n >= nToken ){
							pEngine->nErr++;
							PreprocessorConsumeError(pEngine,XPP_ERR_UNMATCHED_ENDIF,pEngine->nLines,
								"missing 'endif' token on line %u\n",pEngine->nLines);
						}
					}
					break;
				}
				/* Synchronize with the next [else],[elif],[endif] token */
				PreprocessorJumpIfToken(aToken,XPP_TK_ELSE|XPP_TK_ELIF|XPP_TK_ENDIF,&n,nToken);
				if( n >= nToken || (aToken[n].nType & XPP_TK_ENDIF) != 0 ){
					if( n >= nToken ){
						pEngine->nErr++;
						PreprocessorConsumeError(pEngine,XPP_ERR_UNMATCHED_ENDIF,pEngine->nLines,
							"missing 'endif/else/elif' tokens on line %u\n",pEngine->nLines);
					}
					break;
				}
				pToken = &aToken[n];
			}
			/* Jump the [if],[else],[elif],[ifdef],[ifndef],[endif] token */
			n++;
		}else{
			/* Expand single token */
			rc = PreprocessorExpandToken(&(*pEngine),aToken,&n,nToken,xConsumer,pConsumerData);
			if( rc != SXRET_OK ){
				return rc;
			}
		}
		
	}
	return SXRET_OK;
}
/*
 * Expand macro arguments before passing them to the target macro callback.
 * 
 * After a successful return from [PreprocessorCollectArguments()] and when the
 * USER_MACRO_IGNORE_ARG_EXPANDING flag is not set,the macro processor call this
 * routine in order to expand the collected arguments one after one prior to
 * passing them to the target macro callback.This function does all the dirty
 * work.
 * This function return SXRET_OK on success,any other value indicates failure.
 * Note that a single working buffer is used for holding expanded arguments values.
 * Therefore argument must be separated by a boundary defined at compile-time via
 * the XPP_ARG_BOUNDARY macro.
 * The default value of the boundary for this version is "--xPP-A1G-BO7NdA8Y-261432--".
 * This technique is inspired from the one found in the HTTP protocol (RFC 2616)
 * for handling multi-part byte range requests.
 */
static sxi32 PreprocessorExpandArguments(xpp *pEngine,SySet *pIn,ProcConsumer xConsumer,
	void *pConsumerData,sxi32 iFlags,sxi32 iMacroFlags)
{
	sxu32 n,nOfft,nMax;
	SyToken *aToken;
	sxi32 iNest;
	sxi32 rc;

	aToken = (SyToken *)SySetBasePtr(pIn);
	nMax = SySetUsed(pIn);
	n = 0;
	iNest = 0;
	if( iFlags < 0 ){
		iFlags = pEngine->iFlags;
	}
	/* Expand arguments one after one */
	for( ;; ){
		if( n >= nMax ){
			break;
		}
		nOfft = n;
		while( n < nMax ){
			if( (aToken[n].nType & XPP_TK_ARG_SEP) != 0 && iNest <= 0 ){
				break;
			}else if( aToken[n].nType & XPP_TK_ARG_START ){
				/* Increment nesting level */
				iNest++;
			}else if( aToken[n].nType & XPP_TK_ARG_END ){
				/* Decrement nesting level */
				iNest--;
			}
			++n;
		}
		if( n > nOfft ){
			if( (iMacroFlags & USER_MACRO_IGNORE_ARG_EXPANDING) ){
				/* Consume arguments without any processing */
				rc = PreprocessorVerbatimOutput(&aToken[nOfft],n - nOfft,xConsumer,pConsumerData,iFlags);
			}else{
				rc = PreprocessorExpandInput(&(*pEngine),&aToken[nOfft],n - nOfft,xConsumer,pConsumerData,iFlags);
			}
			if( rc != SXRET_OK ){
				return rc;
			}
			/* Delimit arguments by appending the boundary */
			rc = xConsumer((const void *)XPP_ARG_BOUNDARY,sizeof(XPP_ARG_BOUNDARY)-1,pConsumerData);
			if( rc != SXRET_OK ){
				return rc;
			}
		}
		++n;
	}
	return SXRET_OK;
}
/*
 * Register a macro definition.
 * The [xpp_register_macro()] interface is simply a wrapper around the following
 * function.
 * The major difference between this function and [PreprocessorRegisterMacro2()]
 * is that if a macro with the same given name is already registered,then this function
 * override the old definition (callback,flags and user data) with the new one.
 * This function return SXRET_OK on success,any other value indicates failure.
 * Refer to [xpp_register_macro()] for more information.
 */
static sxi32 PreprocessorRegisterMacro(
	xpp *pEngine,                     /* Preprocessor engine */
	const SyString *pName,            /* Macro name */
	ProcMacroExpansion xMacro,        /* C function implementing macro body */
	void *pUserData,                  /* xMacro() private data */
	sxi32 iFlags                      /* One or more USER_MACRO_* options flags */
	){
		SyHashEntry *pEntry;
		SyMacro *pMacro;
		sxi32 rc;

		if( iFlags < 0 ){
			/* Set default flags */
			iFlags |= USER_MACRO_STRICT_INVOKE;
		}
		if( xMacro == 0 ){
			/* Mark as an empty macro */
			iFlags |= USER_MACRO_EMPTY;
		}
		/* Check if the macro is already installed */
		pEntry = SyHashGet(&pEngine->hMacro,pName->zString,pName->nByte);
		if( pEntry ){
			/* Override the old fields with the new one */
			pMacro = (SyMacro *)SyHashEntryGetUserData(pEntry);
			pMacro->xMacro = xMacro;
			pMacro->pUserData = pUserData;
			pMacro->iFlags = iFlags;
			SySetReset(&pMacro->aAuxData);
			return SXRET_OK;
		}
		pMacro = (SyMacro *)SyMemBackendPoolAlloc(&pEngine->sAllocator,sizeof(SyMacro));
		if( pMacro == 0 ){
			return SXERR_MEM;
		}
		/* Zero the structure */
		SyZero(pMacro,sizeof(SyMacro));
		SySetInit(&pMacro->aAuxData,&pEngine->sAllocator,sizeof(SyAuxData));
		/* Fill structure fields and install it in the hashtable */
		pMacro->xMacro = xMacro;
		pMacro->pUserData = pUserData;
		pMacro->iFlags = iFlags;
		rc = SyHashInsert(&pEngine->hMacro,pName->zString,pName->nByte,pMacro);
		if( rc != SXRET_OK ){
			SyMemBackendPoolFree(&pEngine->sAllocator,pMacro);
			return rc;
		}
		return SXRET_OK;
}
/*
 * Push a macro definition.
 * The [xpp_queue_macro()] interface is simply a wrapper around the following
 * function.
 * The major difference between this function and [PreprocessorRegisterMacro()]
 * is that there is no check for an already installed macro with the given name
 * and macro with the same name are queued as it would be in a FIFO stack.
 * This function return SXRET_OK on success.Any other value indicates failure.
 * Refer to [xpp_queue_macro()] for more information.
 */
static sxi32 PreprocessorRegisterMacro2(
	xpp *pEngine,                     /* Preprocessor engine */
	const SyString *pName,            /* Macro name */
	ProcMacroExpansion xMacro,        /* C function implementing macro body */
	void *pUserData,                  /* xMacro() private data */
	sxi32 iFlags                      /* One or more USER_MACRO_* options flags */
	){
		SyMacro *pMacro;
		sxi32 rc;

		if( iFlags < 0 ){
			/* Set default flags */
			iFlags |= USER_MACRO_STRICT_INVOKE;
		}
		if( xMacro == 0 ){
			/* Mark as an empty macro */
			iFlags |= USER_MACRO_EMPTY;
		}
		pMacro = (SyMacro *)SyMemBackendPoolAlloc(&pEngine->sAllocator,sizeof(SyMacro));
		if( pMacro == 0 ){
			return SXERR_MEM;
		}
		/* Zero the structure */
		SyZero(pMacro,sizeof(SyMacro));
		SySetInit(&pMacro->aAuxData,&pEngine->sAllocator,sizeof(SyAuxData));
		/* Fill structure fields and install it in the hashtable */
		pMacro->xMacro = xMacro;
		pMacro->pUserData = pUserData;
		pMacro->iFlags = iFlags;
		/* Perform a tail insert [i.e: FIFO stack]*/
		rc = SyHashTailInsert(&pEngine->hMacro,pName->zString,pName->nByte,pMacro);
		if( rc != SXRET_OK ){
			SyMemBackendPoolFree(&pEngine->sAllocator,pMacro);
			return rc;
		}
		return SXRET_OK;
}
/*
 * Check if the given name is a registered macro definition.
 * This function does a simple lookup on the preprocessor hashtable and if the
 * given name resolve to a macro definition then this function return SXRET_OK
 * and write a pointer to the structure definition if ppMacro (last argument) is
 * not NULL.Otherwise SXERR_NOTFOUND is returned.
 */
static sxi32 PreprocessorGetMacro(xpp *pEngine,const SyString *pName,SyMacro **ppMacro)
{
	SyHashEntry *pEntry;
	/* Query the preprocessor hashtable */
	pEntry = SyHashGet(&pEngine->hMacro,(const void *)pName->zString,pName->nByte);
	if( pEntry == 0 ){
		/* No such macro definition */
		return SXERR_NOTFOUND;
	}
	if( ppMacro ){
		/* Write a pointer to the macro definition */
		*ppMacro = (SyMacro *)SyHashEntryGetUserData(pEntry);
	}
	return SXRET_OK;
}
/* Forward declaration */
static sxi32 SyHashDeleteEntry(SyHash *pHash,const void *pKey,sxu32 nKeyLen,void **ppUserData);
/*
 * Delete a registered macro definition.
 * This function delete the macro named in pName from the preprocessor hashtable.
 * If two or more macros with the same name [push macros using the xpp_queue_macro() 
 * interface] exists then the top most definition is deleted,all others definition 
 * remain in the database.
 * This function return SXRET_OK on success.SXERR_NOTFOUND is returned when no such
 * definition.
 */
static sxi32 PreprocessorDeleteMacro(xpp *pEngine,const SyString *pName)
{
	SyMacro *pMacro;
	sxi32 rc;
	rc = SyHashDeleteEntry(&pEngine->hMacro,(const void *)pName->zString,pName->nByte,(void **)&pMacro);
	if( rc != SXRET_OK ){
		return SXERR_NOTFOUND;
	}
	if( pMacro->xMacro == MacroBuiltin_Expand ){
		pEngine->nUserMacro--;
	}
	SySetRelease(&pMacro->aAuxData);
	SyMemBackendPoolFree(&pEngine->sAllocator,pMacro);
	return SXRET_OK;
}
/*
 * Rename a macro definition
 * This function return SXRET_OK if the given name is a registered macro definition
 * and was successfully renamed.Otherwise SXERR_NOTFOUND is returned.
 */
static sxi32 PreprocessorRenameMacro(xpp *pEngine,SyString *pName,const char *zNew)
{
	SyMacro *pMacro;
	sxi32 rc;
	/* Delete the old name first */
	rc = SyHashDeleteEntry(&pEngine->hMacro,(const void *)pName->zString,pName->nByte,(void **)&pMacro);
	if( rc != SXRET_OK ){
		/* Given name is not a registered macro definition */
		return SXERR_NOTFOUND;
	}
	SyStringInitFromBuf(pName,zNew,SyStrlen(zNew));
	/* Reflect the change */
	rc = SyHashInsert(&pEngine->hMacro,(const void *)pName->zString,pName->nByte,pMacro);
	return rc;
}
/* Forward declaration */
static sxi32 SyMemBackendInit(SyMemBackend *pBackend,ProcMemError xMemErr,void * pUserData);
static sxi32 SyMemBackendInitFromOthers(SyMemBackend *pBackend,const SyMemMethods *pMethods,ProcMemError xMemErr,void * pUserData);
/*
  * Global library configuration.
  * Refer to [xpp_lib_onfig()].
  */
static sxi32 xPPCoreConfigure(sxi32 nOp,va_list ap)
{
	sxi32 rc = SXRET_OK;
	switch(nOp){
		case XPP_LIB_CONFIG_USER_MALLOC: {
			/* Use an alternative low-level memory allocation routines */
			const SyMemMethods *pMethods = va_arg(ap,const SyMemMethods *);
			/* Save the memory failure callback (if available) */
			ProcMemError xMemErr = sMPGlobal.sAllocator.xMemError;
			void *pMemErr = sMPGlobal.sAllocator.pUserData;
			if( pMethods == 0 ){
				/* Use the built-in memory allocation subsystem */
				rc = SyMemBackendInit(&sMPGlobal.sAllocator,xMemErr,pMemErr);
			}else{
				rc = SyMemBackendInitFromOthers(&sMPGlobal.sAllocator,pMethods,xMemErr,pMemErr);
			}
			break;
										  }
		case XPP_LIB_CONFIG_MEM_ERR_CALLBACK: {
			/* Memory failure callback */
			ProcMemError xMemErr = va_arg(ap,ProcMemError);
			void *pUserData = va_arg(ap,void *);
			sMPGlobal.sAllocator.xMemError = xMemErr;
			sMPGlobal.sAllocator.pUserData = pUserData;
			break;
												 }	  
		case XPP_LIB_CONFIG_USER_MUTEX: {
#if defined(XPP_ENABLE_THREADS)
			/* Use an alternative low-level mutex subsystem */
			const SyMutexMethods *pMethods = va_arg(ap,const SyMutexMethods *);
#if defined (UNTRUST)
			if( pMethods == 0 ){
				rc = SXERR_EMPTY;
			}
#endif
			/* Sanity check */
			if( pMethods->xEnter == 0 || pMethods->xLeave == 0 || pMethods->xNew == 0){
				/* At least three criticial callbacks xEnter(),xLeave() and xNew() must be supplied */
				rc = SXERR_INVALID;
				break;
			}
			if( sMPGlobal.pMutexMethods ){
				/* Override the previous mutex subsystem */
				SyMutexRelease(sMPGlobal.pMutexMethods,sMPGlobal.pMutex);
				if( sMPGlobal.pMutexMethods->xGlobalRelease ){
					sMPGlobal.pMutexMethods->xGlobalRelease();
				}
				sMPGlobal.pMutex = 0;
			}
			/* Initialize and install the new mutex subsystem */
			if( pMethods->xGlobalInit ){
				rc = pMethods->xGlobalInit();
				if ( rc != SXRET_OK ){
					break;
				}
			}
			/* Create the global mutex */
			sMPGlobal.pMutex = pMethods->xNew(SXMUTEX_TYPE_FAST);
			if( sMPGlobal.pMutex == 0 ){
				/*
				 * If the supplied mutex subsystem is so sick that we are unable to
				 * create a single mutex,there is no much we can do here.
				 */
				if( pMethods->xGlobalRelease ){
					pMethods->xGlobalRelease();
				}
				rc = SXERR_CORRUPT;
				break;
			}
			sMPGlobal.pMutexMethods = pMethods;			
			if( sMPGlobal.nThreadingLevel == 0 ){
				/* Set a default threading level */
				sMPGlobal.nThreadingLevel = XPP_THREAD_LEVEL_MULTI; 
			}
#endif
			break;
										   }
		case XPP_LIB_CONFIG_THREAD_LEVEL_SINGLE:
#if defined(XPP_ENABLE_THREADS)
			/* Single thread mode(Only one thread is allowed to play with the library) */
			sMPGlobal.nThreadingLevel = XPP_THREAD_LEVEL_SINGLE;
#endif
			break;
		case XPP_LIB_CONFIG_THREAD_LEVEL_MULTI:
#if defined(XPP_ENABLE_THREADS)
			/* Multi-threading mode (library is thread safe and xPP instances may be shared
			 * between multiple threads).
			 */
			sMPGlobal.nThreadingLevel = XPP_THREAD_LEVEL_MULTI;
#endif
			break;
		default:
			/* Unknown configuration option */
			rc = SXERR_UNKNOWN;
			break;
	}
	return rc;
}
/*
 * [CAPIREF: xpp_lib_config()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_lib_config(int nConfigOp,...)
{
	va_list ap;
	sxi32 rc;

	if( sMPGlobal.nMagic == XPP_LIB_MAGIC ){
		/* Library is already initialized,this operation is forbidden */
		return SXERR_LOCKED;
	}
	va_start(ap,nConfigOp);
	rc = xPPCoreConfigure(nConfigOp,ap);
	va_end(ap);
	return rc;
}
/* Forward declaration */
#if defined(XPP_ENABLE_THREADS)
static sxi32 SyMemBackendMakeThreadSafe(SyMemBackend *pBackend,const SyMutexMethods *pMethods);
static sxi32 SyMemBackendDisbaleMutexing(SyMemBackend *pBackend);
static const SyMutexMethods * SyMutexExportMethods(void);
#endif
/*
 * Global library initialization
 * Refer to [xpp_lib_init()]
 * This routine must be called to initialize the memory allocation 
 * subsystem,the mutex subsystem prior to doing any serious work 
 * with the library.The first thread to call this routine does the
 * initialization process and set the magic number so no body later
 * can re-initialize the library.If subsequent threads call this 
 * routine before the first thread have finished the initialization
 * process, then the subsequent threads must block until the initialization
 * process is done.
 */
static sxi32 xPPCoreInitialize(void)
{
#if defined(XPP_ENABLE_THREADS)
	const SyMutexMethods *pMutexMethods = 0;
	SyMutex *pMaster = 0;
#endif
	sxi32 rc;
	/*
	 * If the library is already initialized,then a call to this routine
	 * is a no-op.
	 */
	if( sMPGlobal.nMagic == XPP_LIB_MAGIC ){
		return SXRET_OK; /* Already initialized */
	}
#if defined(XPP_ENABLE_THREADS)
	if( sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_SINGLE ){
		pMutexMethods = sMPGlobal.pMutexMethods;
		if( pMutexMethods == 0 ){
			/* Use the built-in mutex subsystem */
			pMutexMethods = SyMutexExportMethods();
			if( pMutexMethods == 0 ){
				return SXERR_CORRUPT; /* Can't happen */
			}
			/* Install the mutex subsystem */
			rc = xpp_lib_config(XPP_LIB_CONFIG_USER_MUTEX,pMutexMethods);
			if( rc != SXRET_OK ){
				return rc;
			}
		}
		/* Obtain a static mutex so we can initialize the library without calling malloc() */
		pMaster = SyMutexNew(pMutexMethods,SXMUTEX_TYPE_STATIC_1);
		if( pMaster == 0 ){
			return SXERR_CORRUPT; /* Can't happen */
		}
	}
	/* Lock the master mutex */
	rc = SXRET_OK;
	SyMutexEnter(pMutexMethods,pMaster); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
	if( sMPGlobal.nMagic != XPP_LIB_MAGIC ){
#endif
		if( sMPGlobal.sAllocator.pMethods == 0 ){
			/* Install a memory subsystem */
			rc = xpp_lib_config(XPP_LIB_CONFIG_USER_MALLOC,0); /* zero mean use the built-in memory backend */
			if( rc != SXRET_OK ){
				/* If we are unable to initialize the memory backend,there is no much we can do here.*/
				goto End;
			}
		}
#if defined(XPP_ENABLE_THREADS)
		if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE ){
			/* Protect the memory allocation subsystem */
			rc = SyMemBackendMakeThreadSafe(&sMPGlobal.sAllocator,sMPGlobal.pMutexMethods);
			if( rc != SXRET_OK ){
				goto End;
			}
		}
#endif
		/* Our library is initialized,set the magic number */
		sMPGlobal.nMagic = XPP_LIB_MAGIC;
		rc = SXRET_OK;
#if defined(XPP_ENABLE_THREADS)
	} /* sMPGlobal.nMagic != XPP_LIB_MAGIC */
#endif
End:
#if defined(XPP_ENABLE_THREADS)
	/* Unlock the master mutex */
	SyMutexLeave(pMutexMethods,pMaster); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	return rc;
}
/*
 * [CAPIREF: xpp_lib_init()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_lib_init(void)
{
	sxi32 rc;
	rc = xPPCoreInitialize();
	return rc;
}
/* Forward declaration */
static sxi32 PreprocessorRelease(xpp *pEngine);
/*
 * Release all the resources consumed by the library.
 * Refer to [xpp_lib_shutdown()].
 * Note: This call is not thread safe.
 */
static void xPPCoreShutdown(void)
{
	xpp *pEngine,*pNext;
	/* Release all active macro processors */
	pEngine = sMPGlobal.pEngines;
	for(;;){
		if( sMPGlobal.nEngine <= 0 ){
			break;
		}
		pNext = pEngine->pNext;
		PreprocessorRelease(pEngine); 
		pEngine = pNext;
		sMPGlobal.nEngine--;
	}
#if defined(XPP_ENABLE_THREADS)
	/* Release the mutex subsystem */
	if( sMPGlobal.pMutexMethods ){
		if( sMPGlobal.pMutex ){
			SyMutexRelease(sMPGlobal.pMutexMethods,sMPGlobal.pMutex);
			sMPGlobal.pMutex = 0;
		}
		if( sMPGlobal.pMutexMethods->xGlobalRelease ){
			sMPGlobal.pMutexMethods->xGlobalRelease();
		}
		sMPGlobal.pMutexMethods = 0;
	}
	sMPGlobal.nThreadingLevel = 0;
#endif
	if( sMPGlobal.sAllocator.pMethods ){
		/* Release the memory backend */
		SyMemBackendRelease(&sMPGlobal.sAllocator);
	}
	sMPGlobal.nMagic = 0x1928;	
}
/*
 * [CAPIREF: xpp_lib_shutdown()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_lib_shutdown(void)
{
	if( sMPGlobal.nMagic != XPP_LIB_MAGIC ){
		/* Already released */
		return SXRET_OK;
	}
	xPPCoreShutdown();
	return SXRET_OK;
}
/*
 * [CAPIREF: xpp_lib_is_threadsafe()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_lib_is_threadsafe(void)
{
#if !defined(XPP_ENABLE_THREADS)
	return FALSE;
#else
	if( sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE ){
		return FALSE; /* Single threading mode */
	}
	return TRUE;
#endif
}
/*
 * [CAPIREF: xpp_lib_version()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * xpp_lib_version(void)
{
	return XPP_VERSION;
}
/*
 * [CAPIREF: xpp_lib_signature()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * xpp_lib_signature(void)
{
	return XPP_SIG;
}
/*
 * [CAPIREF: xpp_lib_ident()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * xpp_lib_ident(void)
{
	return XPP_IDENT;
}
/*
 * [CAPIREF: xpp_lib_copyright()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * xpp_lib_copyright(void)
{
	return XPP_COPYRIGHT;
}
/*
 * [CAPIREF: xpp_context_append()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_context_append(xpp_context *pCtx,const char *zData,unsigned int nLen)
{
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) ){
		return SXERR_CORRUPT;
	}
#endif
	if( nLen <= 0 ){
		/* Compute the length of the appended data */
		nLen = SyStrlen(zData);
	}
#if defined(UNTRUST)
	if( nLen <= 0 ){
		return SXERR_EMPTY;
	}
#endif
	/* Append the expanded chunk as a result of macro invocation */
	pCtx->rc = pCtx->xConsumer((const void *)zData,nLen,pCtx->pConsumerData);
	if( pCtx->rc != SXRET_OK ){
		/* Consumer routine request an operation abort */
		pCtx->iFlags |= XPP_CTX_CONS_ABORT;
	}
	return pCtx->rc;
}
/* Forward declaration */
static sxsize SyBlobFormatAp(SyBlob *pBlob,const char *zFormat,va_list ap);
/*
 * [CAPIREF: xpp_context_format()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_context_format(xpp_context *pCtx,const char *zFormat,...)
{
	sxi32 rc = SXRET_OK;
	va_list ap;
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) ){
		return SXERR_CORRUPT;
	}
#endif
	/* Reset the working buffer */
	SyBlobReset(&pCtx->sBlob);
	/* Format the given input */
	va_start(ap,zFormat);
	SyBlobFormatAp(&pCtx->sBlob,zFormat,ap);
	va_end(ap);
	/* Consume the formatted message */
	if( SyStringLength(&pCtx->sBlob) > 0 ){
		pCtx->rc = pCtx->xConsumer(SyBlobData(&pCtx->sBlob),SyBlobLength(&pCtx->sBlob),pCtx->pConsumerData);
		if( pCtx->rc != SXRET_OK ){
			/* Consumer routine request an operation abort */
			pCtx->iFlags |= XPP_CTX_CONS_ABORT;
		}
		rc = pCtx->rc;
	}
	return rc;
}
/*
 * [CAPIREF: xpp_context_line()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_context_line(xpp_context *pCtx,unsigned int *pLine)
{
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pLine == 0){
		return SXERR_CORRUPT;
	}
#endif
	*pLine =  pCtx->nLine;
	return SXRET_OK;
}
/*
 * [CAPIREF: xpp_context_macro_name()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_context_macro_name(xpp_context *pCtx,SyString *pOut)
{
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) ){
		return SXERR_CORRUPT;
	}
#endif
	SyStringDupPtr(pOut,&pCtx->sName);
	return SXRET_OK;
}
/*
 * [CAPIREF: xpp_context_userdata()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
void * xpp_context_userdata(xpp_context *pCtx)
{
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pCtx->pMacro == 0){
		return 0;
	}
#endif
	return pCtx->pMacro->pUserData;
}
/*
 * [CAPIREF: xpp_context_peek_auxdata()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
void * xpp_context_peek_auxdata(xpp_context *pCtx)
{
	SyAuxData *pAux;
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pCtx->pMacro == 0 ){
		return 0;
	}
#endif
	pAux = (SyAuxData *)SySetPeek(&pCtx->pMacro->aAuxData);
	return pAux ? pAux->pAuxData : 0;
}
/*
 * [CAPIREF: xpp_context_pop_auxdata()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
void * xpp_context_pop_auxdata(xpp_context *pCtx)
{
	SyAuxData *pAux;
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pCtx->pMacro == 0 ){
		return 0;
	}
#endif
	pAux = (SyAuxData *)SySetPop(&pCtx->pMacro->aAuxData);
	return pAux ? pAux->pAuxData : 0;
}
/*
 * [CAPIREF: xpp_context_push_auxdata()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_context_push_auxdata(xpp_context *pCtx,void *pAuxData)
{
	SyAuxData sAux;
	sxi32 rc;
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pCtx->pMacro == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	sAux.pAuxData = pAuxData;
	rc = SySetPut(&pCtx->pMacro->aAuxData,(const void *)&sAux);
	return rc;
}
/*
 * [CAPIREF: xpp_context_arg_to_int()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_context_arg_to_int(xpp_context *pCtx,const SyString *pArg)
{
	sxi32 nNum = 0;
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pArg == 0){
		return 0;
	}
#else
	SXUNUSED(pCtx); /* Prevent compiler warning */
#endif
	/* Cast the given macro argument to integer */
	SyStrToInt32(pArg->zString,pArg->nByte,(void *)&nNum,0);
	return nNum;
}
#ifndef SX_OMIT_FLOATINGPOINT
/* Forward declaration */
static sxi32 SyStrToReal(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest);
/*
 * [CAPIREF: xpp_context_arg_to_real()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
double xpp_context_arg_to_real(xpp_context *pCtx,const SyString *pArg)
{
	double nNum = 0.0;
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pArg == 0){
		return 0.0;
	}
#else
	SXUNUSED(pCtx); /* Prevent compiler warning */
#endif
	/* Cast the given macro argument to double */
	SyStrToReal(pArg->zString,pArg->nByte,(void *)&nNum,0);
	return nNum;
}
#endif
/*
 * [CAPIREF: xpp_context_arg_to_int64()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
sxi64 xpp_context_arg_to_int64(xpp_context *pCtx,const SyString *pArg)
{
	sxi64 nNum = 0;
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pArg == 0){
		return 0;
	}
#else
	SXUNUSED(pCtx); /* Prevent compiler warning */
#endif
	/* Cast the given argument to 64-bit integer */
	SyStrToInt64(pArg->zString,pArg->nByte,(void *)&nNum,0);
	return nNum;
}
/*
 * [CAPIREF: xpp_context_arg_trim_ws()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_context_arg_trim_ws(xpp_context *pCtx,const SyString *pArg)
{
	SyString *pVal = (SyString *)pArg;
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pArg == 0){
		return SXERR_CORRUPT;
	}
#else
	SXUNUSED(pCtx); /* Prevent compiler warning */
#endif
	/* Remove leading and trailing white spaces from the given argument */
	SyStringFullTrim(pVal);
	if( pVal->nByte > 0 && pVal->zString[pVal->nByte] != 0 ){
		char *zVal = (char *)pVal->zString;
		zVal[pVal->nByte] = 0;
	}
	return SXRET_OK;
}
/*
 * [CAPIREF: xpp_context_arg_value()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * xpp_context_arg_value(xpp_context *pCtx,const SyString *pArg)
{
#if defined(UNTRUST)
	if( pCtx == 0 || XPP_ENGINE_CORRUPT(pCtx->pEngine) || pArg == 0){
		return 0;
	}
#else
	SXUNUSED(pCtx); /* Prevent compiler warning */
#endif
	return pArg->nByte > 0 ? pArg->zString : 0;
}
/*
 * xPP built-in macros [9845-5214-74455WCCD].
 * What we follows here is a massive collection of useful built-in macro definitions.
 * For the complete listing of these built-in macros,please refer to the official 
 * documentation section "Built-in macros".
 * These built-in macros are a good starting point to study the [xpp_context_*()]
 * interfaces that the xPP macro processor present to host application and how
 * these interfaces make macro implementation powerful and easier.
 * Note: To avoid conflict with host-application defined macros,all built-in
 * macros are upper-case registered [i.e: DATE,LINE,MD5,CRC32] except the
 * 'include','sinclude','verbatim','sverbatim','import','simport',defined and undef macros.
 * You can use the [xpp_rename_macro()],[xpp_delete_macro()]...public interfaces
 * to rename,delete those built-in macros as any other user defined macros.
 * To omit built-in macros from the entire build,simply compile your library 
 * with the XPP_OMIT_BUILIN directive defined.
 */
/* Forward declaration */
 static sxi32 PreprocessorEvalExpr(xpp *pEngine,const SyString *pExprText,sxi32 *pResult);
/*
 * XPP:
 *   Expands xPP engine signature.
 * Expects:
 *    No arguments.
 * Expands:
 *    Constant string literal.
 */
static int MacroBuiltin_XPP(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Expand */
	xpp_context_append(&(*pCtx),XPP_SIG,sizeof(XPP_SIG)-1);
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * XPP_COPYRIGHT: 
 *    Expand xPP copyright notice.
 * Expects:
 *    No arguments.
 * Expands:
 *    Constant string literal.
 */
static int MacroBuiltin_XPPCopyright(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Expand */
	xpp_context_append(&(*pCtx),XPP_COPYRIGHT,sizeof(XPP_COPYRIGHT)-1);
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * XPP_VERSION:
 *   Expands xPP version number.
 * Expects:
 *    No arguments.
 * Expands:
 *    Constant string literal.
 */
static int MacroBuiltin_XPPVersion(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Expand */
	xpp_context_append(&(*pCtx),XPP_VERSION,sizeof(XPP_VERSION)-1);
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * Register the full path of the processed file.
 * This procedure is merely used by the Trace callback and have no particular interest.
 */
static void PushFilePath(SyMemBackend *pAllocator,SySet *pOut,const char *zPath,sxu32 nLen)
{
	SyString sEntry;

	if( nLen <= 0 ){
		nLen = SyStrlen(zPath);
	}
	if( pAllocator ){
		char *zDup;
		/* Duplicate file path */
		zDup = (char *)SyMemBackendStrDup(&(*pAllocator),zPath,nLen);
		if( zDup == 0 ){
			return;
		}
		SyStringInitFromBuf(&sEntry,zDup,nLen);
#ifdef __WINNT__
		/* Normalize path on windows */
		while( zDup[0] != 0 ){
			if( zDup[0] == '/' ){
				zDup[0] = '\\';
			}
			zDup++;
		}
#endif
	}else{
		SyStringInitFromBuf(&sEntry,zPath,nLen);
	}
	/* Register entry */
	SySetPut(&(*pOut),(const void *)&sEntry);
}
#ifndef XPP_OMIT_BUILTIN
/* Forward declaration */
static sxi32 SyOSUtilFormatTimeToLocal(sytime *pIn,Sytm *pOut);
static sxi32 SyOSUtilGetSystemTime(sytime *pTime);
static const char * SyTimeGetDay(sxi32 iDay);
static const char * SyTimeGetMonth(sxi32 iMonth);
/*
 * TIME:
 *  Expands the current time.
 * Expects:
 *    No arguments.
 * Expands:
 *    Constant digit stream separated by ':' in the form: H:M:S.
 * Example:
 *   Current time is: TIME
 * will expand:
 *   Current time is: 21:41:32
 */
static int MacroBuiltin_Time(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	sytime sTime;
	Sytm sFmt;
	
	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Get the current time */
	SyOSUtilGetSystemTime(&sTime);
	/* Format the binary time to a presentable format */
	SyOSUtilFormatTimeToLocal(&sTime,&sFmt);
	/* Expand */
	xpp_context_format(&(*pCtx),"%02d:%02d:%02d",sFmt.tm_hour,sFmt.tm_min,sFmt.tm_sec);
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * DATE:
 *  Expands the current date.
 * Expects:
 *    No arguments.
 * Expands:
 *    Constant string literal in the C asctime() format.
 * Example:
 *    Current date is: DATE
 * Will expand:
 *   Current date is: Dec 27 2011.
 */
static int MacroBuiltin_Date(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	sytime sTime;
	Sytm sFmt;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Get the current time */
	SyOSUtilGetSystemTime(&sTime);
	/* Format the binary time to a presentable format */
	SyOSUtilFormatTimeToLocal(&sTime,&sFmt);
	/* Expand the time macro */
	xpp_context_format(&(*pCtx),"%.3s %02d %04d",SyTimeGetMonth(sFmt.tm_mon),sFmt.tm_mday,sFmt.tm_year);
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* All done,macro is expanded */
	return SXRET_OK;
}
/*
 * TIMESTAMP:
 *   Expands the current date and time.
 * Expects:
 *   No arguments.
 * Expands:
 *   Constant string literal in the form: wday mon mday H:M:S year.
 * Example:
 *  Timestamps: TIMESTAMP
 * Will expand:
 *  Timestamps: Tue Nov 22 14:09:10 2011
 */
static int MacroBuiltin_TimeStamp(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	sytime sTime;
	Sytm sFmt;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Get the current time */
	SyOSUtilGetSystemTime(&sTime);
	/* Format the binary time to a presentable format */
	SyOSUtilFormatTimeToLocal(&sTime,&sFmt);
	/* Expand */
	xpp_context_format(&(*pCtx),"%.3s %.3s %02d %02d:%02d:%02d %04d",
		SyTimeGetDay(sFmt.tm_wday),SyTimeGetMonth(sFmt.tm_mon),sFmt.tm_mday,
		sFmt.tm_hour,sFmt.tm_min,sFmt.tm_sec,
		sFmt.tm_year);
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * ISO_DATE:
 *  Expands the current date.
 * Expects:
 *   No arguments.
 * Expands:
 *   Constant digit stream separated by '-' in the ISO-8601 date format: YYYY-MM-DD.
 * Example:
 *  Current date: ISO_DATE
 * Will expand:
 *  Current date: 2011-11-22
 */
static int MacroBuiltin_ISODate(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	sytime sTime;
	Sytm sFmt;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Get the current time */
	SyOSUtilGetSystemTime(&sTime);
	/* Format the binary time to a presentable format */
	SyOSUtilFormatTimeToLocal(&sTime,&sFmt);
	/* Expand */
	xpp_context_format(&(*pCtx),"%04d-%02d-%02d",sFmt.tm_year,sFmt.tm_mon+1,sFmt.tm_mday);
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * Extract a filename from the given path.
 * This function get called only from the function that implement the FILE and FILENAME
 * macro and have no particular interest.
 */
static const char * SyExtractFilename(const char *zFilepath)
{
	const char *zRelative;
	sxu32 n;
	int c,d;
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zFilepath) ){
		return 0;
	}
#endif
	n = SyStrlen(zFilepath);
	zRelative = &zFilepath[n - 1];
	c = d = '/';
#ifdef __WINNT__
	d = '\\';
#endif
	while( zRelative > zFilepath && (zRelative[0] == c || zRelative[0] == d) ){
		zRelative--;
	}
	while(zRelative > zFilepath && zRelative[0] != c && zRelative[0] != d ){
		zRelative--;
	}
	if( zRelative > zFilepath ){
		zRelative++;
	}
	return zRelative;
}
/*
 * FILENAME:
 * FILE
 * Expands to the name of the processed file.
 * Expects:
 *   No arguments.
 * Expands:
 *   Constant string literal.
 * Example:
 *   Processed file: FILENAME
 *   Processed file: FILE
 * Will expand:
 *   Processed file: input.txt
 *   Processed file: /full/path/to/input.txt
 * Note:
 * If the processed entity is a memory chunk (not a file on disk),then this macro
 * expand to the constant string ::Memory::
 */
static int MacroBuiltin_Filename(xpp_context *pCtx,int nArg,const SyString *azArg)
{
        SyString sName = {0,0}; /* prevent cc -O6 warning */
	const char *zName;
	xpp *pEngine;
	
	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	zName = PreprocessorGetProcessedFilePath(pEngine);
	/* Extract the macro name so will know what to expand:
	 * Either the full path or the file name only.
	 */
	xpp_context_macro_name(&(*pCtx),&sName);
	if( SyBlobSearch(sName.zString,sName.nByte,"NAME",sizeof("NAME")-1,0) == SXRET_OK ){
		/* Expand the filename only */
		zName = SyExtractFilename(zName);
	}	
	/* Expand */
	xpp_context_append(&(*pCtx),zName,SyStrlen(zName));
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * LINE:
 *  Expands to the current line number in the processed input.
 * Expects:
 *   No arguments.
 * Expands:
 *   constant digit stream.
 */
static int MacroBuiltin_Line(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxu32 nLine = 0;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Extract the current line */
	xpp_context_line(&(*pCtx),&nLine);
	xpp_context_format(&(*pCtx),"%u",nLine);
	return SXRET_OK;
}
/*
 * LINEX:
 *  Expands to the current line number in the processed input.
 * Expects:
 *   No arguments.
 * Expands:
 *   constant hexadecimal (base-16) digit stream.
 * Example:
 *  Current line: LINEX
 * Will expand:
 *  Current line: E6E
 */
static int MacroBuiltin_LineX(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxu32 nLine = 0;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Extract the current line */
	xpp_context_line(&(*pCtx),&nLine);	
	xpp_context_format(&(*pCtx),"%x",nLine);
	return SXRET_OK;
}
/* Forward declaration */
static sxi32 SyBinToHexString(const void *pIn,sxsize nLen,char *zBuf,sxsize *pOutLen);
static sxi32 SyMD5ComputeSum(const void *pIn,sxsize nLen,unsigned char *zDigest,sxu32 oLen);
/*
 * MD5:
 *  Expands to the MD5 hash of the given arguments.
 * Expects:
 *  Variable number of arguments (left and right delimited)
 * Expands:
 *  32 bytes MD5 hash and a single white space (if faced with more than one argument)
 *  for each argument.
 * Example:
 *       MD5(a,b,c)
 *       MD5(hello,world)
 *       MD5(A)
 * Will expand:
 *       0cc175b9c0f1b6a831c399e269772661 92eb5ffee6ae2fec3ad71c777531578f 4a8a08f09d37b73795649038408b5f33
 *       5d41402abc4b2a76b9719d911017c592 7d793037a0760186574b0282f2f435e7
 *       7fc56270e7a70fa81a5935b72eacbe29
 * MD5 sum of a given file.
 *   define file /path/to/something
 *   MD5(verbatim file)
 *   Will expand the MD5 sum of the whole file.
 *   Refer to the 'verbatim' macro for more information.
 */
static int MacroBuiltin_MD5(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	unsigned char zDigest[16]; /* MD5 digest */
	char zHex[32];             /* MD5 hash */
	xpp *pEngine;
	sxsize n;
	int i;

	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		SyMD5ComputeSum((const void *)azArg[i].zString,azArg[i].nByte,zDigest,sizeof(zDigest));
		/* Hexify the digest */
		n = sizeof(zHex);
		SyBinToHexString((const void *)zDigest,sizeof(zDigest),zHex,&n);
		/* Expand */
		xpp_context_append(&(*pCtx),zHex,n);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * BASE64:
 *   Expands to the Base64 value of the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expand:
 *  Base64 and a single white space(if faced with more than one argument)
 *  for each argument
 * Example:
 *       BASE64(a)
 *       BASE64(hello,world)
 *       BASE64(1,2)
 * Will expand:
 *       YQ==
 *       aGVsbG8= d29ybGQ=
 *       MQ== Mg==
 * Base64 encoding of a given file.
 *   define file /path/to/something
 *   BASE64(verbatim file)
 *   Will expand the BASE64 encoding of the whole file.
 *   Refer to the 'verbatim' macro for more information.
 */
static int MacroBuiltin_Base64(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	int i;

	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Perform the base64 encoding */
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		xpp_context_format(&(*pCtx),"%.*b",azArg[i].nByte,azArg[i].zString);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * BASE64_DECODE:
 *  Expands to the base64 decoding of the given arguments.
 *  In other words perform the reverse operation of the BASE64
 *  macro.
 * Expects:
 *  Variable number of arguments (left and right delimited).
 * Expands
 *  Decoded values of the base64 encoded argument and a single white space
 *  (if faced with more than one argument)
 * Example:
 *  BASE64_DECODE(dXNlcg==)
 *  BASE64_DECODE(bm8gYm9keQ==)
 *  BASE64_DECODE(IA==) //Base64 encoding of a single space
 *  BASE64_DECODE(BASE64(hello)) 
 * Will expand:
 *  user
 *  no body
 *   
 *  hello
 */
static int MacroBuiltin_Base64Decode(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	int i;
	/* Perform the decoding operation */
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		xpp_context_format(&(*pCtx),"%-.*b",azArg[i].nByte,azArg[i].zString);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/* Forward declaration */
static sxu32 SyCrc32(const void *pSrc,sxsize nLen);
/*
 * CRC32:
 *  Expand to the CRC32 of the given arguments.
  Expects:
 *  Variable number of arguments (left and right delimited).
 * Expands
 *  CRC32 (digit stream) and a single white space (if faced with more than one argument)
 * Example:
 *  CRC32(hello)
 *  CRC32(a,b)
 * Will expand:
 *   3387906425
 *   390611388 2386628614
 * CRC32 of a given file.
 *   define file /path/to/something
 *   CRC32(verbatim file)
 *   Will expand the CRC32 of the whole file.
 *   Refer to the 'verbatim' macro for more information.
 */
static int MacroBuiltin_Crc32(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxu32 nCrc;
	int i;

	/* Calculate CRC32 */
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		nCrc = SyCrc32((const void *)azArg[i].zString,azArg[i].nByte);
		/* Expand the CRC32 value */
		xpp_context_format(&(*pCtx),"%u",nCrc);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/*
 * HTML_ESCAPE:
 *   Expand a safe HTML representation of the given input.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant string literal (a safe HTML string) and a single white space
 *   (if faced with more than one argument)
 * Example:
 *   HTML_ESCAPE(<hello>,<world>)
 *   HTML_ESCAPE({user}) 
 * Will expand:
 *   &lt;hello&gt; &lt;world&gt;
 *   &#123;user&#125;  
 */
static int MacroBuiltin_HTMLEscape(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	int i;

	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Encode arguments */
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		xpp_context_format(&(*pCtx),"%.*h",azArg[i].nByte,azArg[i].zString);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * HTML_UNESCAPE:
 *   Decode an encoded HTML string.In other words perform the reverse operation of
 *   the HTML_ESCAPE macro.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant string literal(a decoded HTML string) and a single white space
 *   (if faced with more than one argument)
 * Example:
 *  HTML_UNESCAPE(&lt;hello&gt; &lt;world&gt;)
 *  HTML_UNESCAPE(&#123;user&#125;)
 *  HTML_UNESCAPE(HTML_ESCAPE($whois$))
 * Will output:
 *  <hello> <world> 
 *  {user}
 *  $whois$ 
 */
static int MacroBuiltin_HTMLUnEscape(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	int i;	
	/* Decode arguments */
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		xpp_context_format(&(*pCtx),"%-.*h",azArg[i].nByte,azArg[i].zString);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/* Forward declaration */
static sxu32 SyBinHash(const void *pSrc,sxsize nLen);
/*
 * HASH:
 *   Expands to the 32-bit hash (djb) of the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant digit stream and a single white space (if faced with more than one argument)
 * Example:
 *   HASH(hello,world)
 *   HASH(user)
 *   HASH( ) //a single space
 * Will expand:
 *   261238937 279393645
 *   2090806916
 *   177605 
 */
static int MacroBuiltin_Hash(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxu32 nHash;
	int i;
	
	/* Hash arguments */
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		nHash = SyBinHash((const void *)azArg[i].zString,azArg[i].nByte);
		/* Expand the hash value */
		xpp_context_format(&(*pCtx),"%u",nHash);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/*
 * HASHX:
 *   Expands to the 32-bit hash (djb) of the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant hexadecimal(base 16) digit stream and a single white space
 *   (if faced with more than one argument)
 * Example:
 *   HASHX(hello,world)
 *   HASHX(user)
 *   HASHX( ) //a single space
 * Will expand:
 *   f923099 10a7356d
 *   7c9f2e84
 *   2b5c5 
 */
static int MacroBuiltin_HashX(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxu32 nHash;
	int i;

	/* Hash arguments */
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		nHash = SyBinHash((const void *)azArg[i].zString,azArg[i].nByte);
		/* Expand the hash value */
		xpp_context_format(&(*pCtx),"%x",nHash);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/*
 * LEN:
 *   Expands to the total length of the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant digit stream.
 * Example:
 *   LEN(a,b,c)
 *   LEN(abc)
 *   LEN(hello,world)
 *   LEN() //nothing 
 *   LEN( ) //a single space
 *   LEN((a,b))
 * Will expand:
 *   3
 *   3
 *   10
 *   0 
 *   1 
 *   5 
 * Size of a given file.
 *   define file /path/to/something
 *   LEN(verbatim file)
 *   Will expand the size of the whole file.
 *   Refer to the 'verbatim' macro for more information.
 */
static int MacroBuiltin_len(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxu32 nLength = 0;	
	for(;;){
		if( nArg <= 0 ){
			break;
		}
		nLength += azArg[nArg - 1].nByte;
		nArg--;
	}
	/* Output arguments length */
	xpp_context_format(&(*pCtx),"%u",nLength);
	return SXRET_OK;
}
/*
 * LENX:
 *   Expands to the total length of the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant hexadecimal(base 16) digit stream.
 * Example:
 *   LENX(abc)
 *   LENX(hello,world)
 * Will expand:
 *   3
 *   a
 * Length of a given file.
 *   define file /path/to/something
 *   LENX(verbatim file)
 *   Will expand the size of the whole file.
 *   Refer to the 'verbatim' macro for more information.
 */
static int MacroBuiltin_lenX(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxu32 nLength = 0;
	for(;;){
		if( nArg <= 0 ){
			break;
		}
		nLength += azArg[nArg - 1].nByte;
		nArg--;
	}
	/* Output arguments length */
	xpp_context_format(&(*pCtx),"%x",nLength);
	return SXRET_OK;
}
/*
 * INCR:
 *  Increment an integer argument by one.
 * Expects:
 *  A single integer argument (left and right delimited).
 * Expands
 *  Constant digit stream (integer value plus one).
 * Example:
 *   INCR(10)
 *   INCR(100)
 *   INCR(INCR(20))
 * Will expand:
 *   11
 *   101
 *   22
 * This macro is deprecated and is replaced by the more generic and powerful EVAL macro.
 */
static int MacroBuiltin_Incr(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 iNum;
	if( nArg > 0 ){
		/* Convert arg to an integer */
		iNum = xpp_context_arg_to_int(pCtx,&azArg[0]);
		/* Increment value by one */
		iNum++;
		/* Expand new value */
		xpp_context_format(pCtx,"%d",iNum);
	}
	return SXRET_OK;
}
/*
 * DECR:
 *  Decrement an integer argument by one.
 * Expects:
 *  A single integer argument (left and right delimited).
 * Expands
 *  Constant digit stream (integer value minus one).
 * Example:
 *   DECR(10)
 *   DECR(100)
 *   DECR(DECR(20))
 * Will expand:
 *   9
 *   99
 *   18
 * This macro is deprecated and is replaced by the more generic and powerful EVAL macro.
 */
static int MacroBuiltin_Decr(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 iNum;
	if( nArg > 0 ){
		/* Convert arg to an integer */
		iNum = xpp_context_arg_to_int(pCtx,&azArg[0]);
		/* Decrement integer */
		iNum--;
		/* Expand new value */
		xpp_context_format(pCtx,"%d",iNum);
	}
	return SXRET_OK;
}
/*
 * SUBSTR:
 *   Expand to a substrings of strings.
 *   SUBSTR(s, i, n) returns the substring of s that starts at the ith position
 *   (origin zero), and is n characters long.If n is omitted, the rest of the
 *   string is returned.
 * Expects:
 *   One,two or three arguments (left and right delimited).
 * Expands:
 *  constant string literal.
 * Note:
 *   Inconsistent or out of range values are simply discarded.
 * Example:
 *   SUBSTR(hello world,6)
 *   SUBSTR(hello world,6,2)
 *   SUBSTR(hello world,0,5)
 *   SUBSTR(hello world,0) or SUBSTR(hello world)
 * Will expand:
 *   world
 *   wo
 *   hello
 *   hello world
 */
static int MacroBuiltin_Substr(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 nOfft = 0;
	xpp *pEngine;
	sxi32 nLen;
	sxi32 rc;
	
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	nLen = (sxi32)azArg[0].nByte;
	if( nArg > 1 ){
		/* Try to get substring offset */
		rc = SyStrToInt32(azArg[1].zString,azArg[1].nByte,(void *)&nOfft,0);
		if( rc != SXRET_OK || nOfft < 0 || nOfft > nLen ){
			/* Inconsistent value,we will assume its zero */
			nOfft = 0;
		}
	}
	/* Try to get substring length */
	if( nArg > 2 ){
		rc = SyStrToInt32(azArg[2].zString,azArg[2].nByte,(void *)&nLen,0);
		if( rc != SXRET_OK || nLen < 0 || nLen > (sxi32)azArg[0].nByte  ){
			/* Inconsistent value,we will assume its the string length */
			nLen = (sxi32)azArg[0].nByte;
		}
	}
	if( nLen > nOfft ){
		nLen -= nOfft;
	}
	if( nLen > 0 ){
		/* Output the substring */
		xpp_context_append(&(*pCtx),&azArg[0].zString[nOfft],nLen);
	}
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * INDEX
 * OFFSET:
 *  Perform a pattern search on the given string and expand
 *  pattern position (origin zero) in text.
 * Expects:
 *  Two arguments (left and right delimited).
 * Expand:
 *  Constant digit stream.
 * Example
 *  INDEX(hello world,world)
 *  INDEX(hello world,hell)
 *  INDEX(hello world,wo)
 *  INDEX(hello world,user)
 * Will expand:
 *  6
 *  0
 *  9
 *  -1 
 * Note:
 *  ** Brute force is the pattern search method used here.
 *  ** If the pattern is not found,then this macro expand to '-1'
 * To search a file,simply do something like this:
 *    define pattern Something
 *    define file /path/to/something
 *    pattern position in file = INDEX(verbatim file,pattern)
 * Refer to the 'verbatim' macro for more information.
 */
static int MacroBuiltin_Index(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 rc = SXERR_NOTFOUND;
	sxu32 nOfft = 0; /* Offset were the pattern occurs in the text */
	if( nArg >= 2 ){
		if( azArg[0].nByte > 0 && azArg[1].nByte > 0 ){
			/* Do a brute force search */
			rc = SyBlobSearch((const void *)azArg[0].zString,azArg[0].nByte,
				(const void *)azArg[1].zString,azArg[1].nByte,&nOfft);
		}
	}
	if( rc == SXRET_OK ){
		/* Output pattern position in text */
		xpp_context_format(&(*pCtx),"%u",nOfft);
	}else{
		/* Output negative number */
		xpp_context_append(&(*pCtx),"-1",sizeof("-1")-1);
	}
	return SXRET_OK;
}
/*
 *  MATCH
 *  Perform a pattern (second argument) search on the given string (first argument) and expand
 *  1 (TRUE) if the pattern is found.0 (false) otherwise.
 * Expects:
 *  Two arguments (left and right delimited).
 * Expand:
 *  Single digit (0 or 1).
 * Example
 *  MATCH(hello world,world)
 *  MACTH(hello world,user)
 * Will expand:
 *  1
 *  0
 * Note:
 *  ** Brute force is the pattern search method used here.
 * To search a file,simply do something like this:
 *   define pattern Something
 *   define file /path/to/something
 *   is pattern found in file?
 *   if MATCH(verbatim file,pattern)
 *     Yes
 *   else
*      No
*    endif
 * Refer to the 'verbatim' macro for more information.
 */
static int MacroBuiltin_Match(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 rc = SXERR_NOTFOUND;
	if( nArg >= 2 ){
		if( azArg[0].nByte > 0 && azArg[1].nByte > 0 ){
			/* Do a brute force search */
			rc = SyBlobSearch((const void *)azArg[0].zString,azArg[0].nByte,
				(const void *)azArg[1].zString,azArg[1].nByte,0);
		}
	}
	if( rc == SXRET_OK ){
		/* Pattern is found: output TRUE */
		xpp_context_append(&(*pCtx),"1",sizeof(char));
	}else{
		/* Output FALSE */
		xpp_context_append(&(*pCtx),"0",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * TOUPPER:
 *   Expands upper-case version of the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant string literal and a single white space
 *   (if faced with more than one argument).
 * Example:
 *    TOUPPER(hello,world)
 * Will expand:
 *    HELLO WORLD
 * Note:
 *   non-ASCII stream are expanded verbatim.
 */
static int MacroBuiltin_ToUpper(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	const unsigned char *zIn,*zCur,*zEnd;
	int i,c;
	
	for( i = 0 ; i < nArg ; ++i ){
		zIn = (const unsigned char *)azArg[i].zString;
		zEnd = &zIn[azArg[i].nByte];
		for(;;){
			if( zIn >= zEnd ){
				break;
			}
			if( zIn[0] >= 0xc0 ){
				/* UTF-8 stream are expanded verbatim */
				zCur = zIn;
				zIn++;
				while( zIn < zEnd && ((zIn[0] & 0xc0) == 0x80) ){
					zIn++;
				}
				xpp_context_append(&(*pCtx),(const char *)zCur,(sxu32)(zIn-zCur));
			}
			while( zIn < zEnd && zIn[0] < 0xc0 ){
				c = zIn[0];
				if( SyisLower(c) ){
					c = SyToUpper(zIn[0]);
				}
				xpp_context_append(&(*pCtx),(const char *)&c,sizeof(char));
				zIn++;
			}
		}
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/*
 * TOLOWER:
 *   Expands lower-case version of the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant string literal and a single white space
 *   (if faced with more than one argument).
 * Example:
 *    TOLOWER(HELLO,WORLD)
 *    or
 *    TOLOWER(TOUPPER(hello,world))
 * Will expand:
 *    hello world
 * Note:
 *   non-ASCII stream are expanded verbatim.
 */
static int MacroBuiltin_ToLower(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	const unsigned char *zIn,*zCur,*zEnd;
	int i,c;
	for( i = 0 ; i < nArg ; ++i ){
		zIn = (const unsigned char *)azArg[i].zString;
		zEnd = &zIn[azArg[i].nByte];
		for(;;){
			if( zIn >= zEnd ){
				break;
			}
			if( zIn[0] >= 0xc0 ){
				/* UTF-8 stream are expanded verbatim */
				zCur = zIn;
				zIn++;
				while( zIn < zEnd && ((zIn[0] & 0xc0) == 0x80) ){
					zIn++;
				}
				xpp_context_append(&(*pCtx),(const char *)zCur,(sxu32)(zIn-zCur));
			}
			while( zIn < zEnd && zIn[0] < 0xc0 ){
				c = zIn[0];
				if( SyisUpper(c) ){
					c = SyToLower(zIn[0]);
				}
				xpp_context_append(&(*pCtx),(const char *)&c,sizeof(char));
				zIn++;
			}
		}
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/* SyRunTimeApi: sxutils.c */
static sxi32 SyAsciiToHex(sxi32 c)
{
	if( c >= 'a' && c <= 'f' ){
		c += 10 - 'a';
		return c;
	}
	if( c >= '0' && c <= '9' ){
		c -= '0';
		return c;
	}
	if( c >= 'A' && c <= 'F') {
		c += 10 - 'A';
		return c;
	}		
	
	return 0; 
}
/* SyRunTimeApi: sxutf.c */
#define SX_WRITE_UTF8(zOut, c) {                       \
  if( c<0x00080 ){                                     \
    *zOut++ = (sxu8)(c&0xFF);                          \
  }else if( c<0x00800 ){                               \
    *zOut++ = 0xC0 + (sxu8)((c>>6)&0x1F);              \
    *zOut++ = 0x80 + (sxu8)(c & 0x3F);                 \
  }else if( c<0x10000 ){                               \
    *zOut++ = 0xE0 + (sxu8)((c>>12)&0x0F);             \
    *zOut++ = 0x80 + (sxu8)((c>>6) & 0x3F);            \
    *zOut++ = 0x80 + (sxu8)(c & 0x3F);                 \
  }else{                                               \
    *zOut++ = 0xF0 + (sxu8)((c>>18) & 0x07);           \
    *zOut++ = 0x80 + (sxu8)((c>>12) & 0x3F);           \
    *zOut++ = 0x80 + (sxu8)((c>>6) & 0x3F);            \
    *zOut++ = 0x80 + (sxu8)(c & 0x3F);                 \
  }                                                    \
}

/*
 * TOUTF8:
 *   Expands to the UTF-8 encoding of the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   UTF-8 stream and a single white space
 *   (if faced with more than one argument).
 * Example:
 *    TOUTF8(UNICODE STREAM)
 * Will expand:
 *    Valid UTF-8 stream
 * TIP:
 *   To encode a plain text file using the UTF-8 encoding
 *   simply do something like this:
 *   define file /path/to/some/text/thing
 *   TOUTF8(verbatim file)
 *   The result of the expansion is now a valid UTF-8 stream.
 *   Refer to the 'verbatim' macro for more information.
 */
static int MacroBuiltin_ToUTF8(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	const unsigned char *zIn,*zEnd;
	char zData[10];
	char *zCur;
	int i,c;

	for ( i = 0 ; i < nArg ; ++i ){
		zIn = (const unsigned char *)azArg[i].zString;
		zEnd = &zIn[azArg[i].nByte];
		while( zIn < zEnd ){
			zCur = zData;
			c = zIn[0];
			SX_WRITE_UTF8(zCur,c);
			if( zCur > zData ){
				/* Expand UTF-8 stream */
				xpp_context_append(&(*pCtx),zData,(sxu32)(zCur-zData));
			}
			zIn++;
		}
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/* Forward declaration */
static sxi32 SyUriDecode(const char *zSrc,sxsize nLen,ProcConsumer xConsumer,void *pUserData,sxu8 bUTF8);
static sxi32 SyUriEncode(const char *zSrc,sxsize nLen,ProcConsumer xConsumer,void *pUserData);
static sxi32 SyBinToHexConsumer(const void *pIn,sxsize nLen,ProcConsumer xConsumer,void *pConsumerData);
/*
 * URIENCODE:
 *   Perform an URI encoding operation on the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant string literal and a single white space
 *   (if faced with more than one argument).
 * Example:
 *    URIENCODE(/path/to/home#user:pass@something)
 *    URIENCODE( ) //a single space
 * Will expand:
 *    %2Fpath%2Fto%2Fhome%23user%3Apass%40something
 *    + 
 */
static int MacroBuiltin_UriEncode(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	int i,rc;
		
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	for( i =  0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		rc = SyUriEncode(azArg[i].zString,azArg[i].nByte,pCtx->xConsumer,pCtx->pConsumerData);
		if( rc != SXRET_OK ){
			break;
		}
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * URIDECODE:
 *  Perform an URI decoding operation on the given arguments.
 *  In other word do the reverse of the URIENCODE operation.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant string literal and a single white space
 *   (if faced with more than one argument).
 * Example:
 *    URIDECODE(%2Fpath%2Fto%2Fhome%23user%3Apass%40something)
 *    URIDECODE(+)
 * Will expand:
 *   /path/to/home#user:pass@something
 *     //a single space
 */
static int MacroBuiltin_UriDecode(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	int i,rc;
	for( i =  0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		rc = SyUriDecode(azArg[i].zString,azArg[i].nByte,pCtx->xConsumer,pCtx->pConsumerData,TRUE);
		if( rc != SXRET_OK ){
			break;
		}
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/*
 * TOHEX:
 *   Expand to the hexadecimal encoding of the given arguments.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant hexadecimal(base 16) digit stream and a single white space
 *   (if faced with more than one argument).
 * Example:
 *   TOHEX(hello,world)
 *   TOHEX([{}])
 *   TOHEX(14)
 *   TOHEX( ) // a single space
 * Will expand:
 *   68656c6c6f 776f726c64
 *   5b7b7d5d
 *   3134
 *   20 
 */
static int MacroBuiltin_ToHex(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	int i;
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		SyBinToHexConsumer((const void *)azArg[i].zString,azArg[i].nByte,
			pCtx->xConsumer,pCtx->pConsumerData);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/*
 * NUMTOHEX:
 *   Expand to the hexadecimal representation of the given numbers.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant hexadecimal(base 16) digit stream and a single white space
 *   (if faced with more than one argument).
 * Example:
 *   NUMTOHEX(654,856231)
 *   NUMTOHEX(7911)
 *   NUMTOHEX(14)
 *   NUMTOHEX( ) // a single space
 * Will expand:
 *   28e d10a7
 *   1ee7
 *   e
 *   0
 */
static int MacroBuiltin_NumToHex(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 iNum;
	int i;
	for( i = 0 ; i < nArg ; ++i ){
		/* Get an integer representation of the given argument */
		iNum = xpp_context_arg_to_int(&(*pCtx),&azArg[i]);
		/* Expand hexadecimal representation */
		xpp_context_format(&(*pCtx),"%x",iNum);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
/*
 * TOOCTAL:
 *   Expand to the octal representation of the given numbers.
 * Expects:
 *   Variable number of arguments (left and right delimited).
 * Expands:
 *   Constant octal(base 8) digit stream and a single white space
 *   (if faced with more than one argument).
 * Example:
 *   TOOCTAL(999)
 *   TOOCTAL(7911)
 *   TOOCTAL(14)
 *   TOOCTAL( ) // a single space
 * Will expand:
 *   1747
 *   17347
 *   16
 *   0
 */
static int MacroBuiltin_ToOctal(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 iNum;
	int i;		
	for( i = 0 ; i < nArg ; ++i ){
		/* Get an integer representation of the given argument */
		iNum = xpp_context_arg_to_int(&(*pCtx),&azArg[i]);
		/* Expand octal representation */
		xpp_context_format(&(*pCtx),"%o",iNum);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
}
#endif
/*
 * RC4 context used to generate random numbers and strings.
 * Note that this context is protected by the global mutex when running 
 * on multi-threaded environments.
 */
static SyRC4Ctx sRC4;
#ifndef XPP_OMIT_BUILTIN
/*
 * RANDOM:
 *  Generate and expand a random number.
 * Expects:
 *  No arguments.
 * Expands:
 *  Constant digit stream (base 10).
 * Example:
 *      RANDOM *  RANDOM + RANDOM / RANDOM
 * Will expand:
 *      350456268 *  2840094544 + 1077437465 / 843906713
 * Note:
 *  The algorithm used for generating random numbers here is the RC4 
 *  algorithm which works well for this situation.
 */
static int MacroBuiltin_Random(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxu32 nRandom; 

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);	
	/* One time RC4 context initialization */
#if defined(XPP_ENABLE_THREADS)
	 /* Enter the global mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	 SyRandomnessInit(&sRC4,0,0);
	/* Generate the random number */
	SyRandomness(&sRC4,(void *)&nRandom,sizeof(sxu32));
#if defined(XPP_ENABLE_THREADS)
	 /* Leave the global mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	/* Expand */
	xpp_context_format(&(*pCtx),"%u",nRandom);
	return SXRET_OK;
}
/*
 * RANDOMX:
 *  Generate and expand a random number.
 * Expects:
 *  No arguments.
 * Expands:
 *  Constant hexadecimal digit stream (base 16).
 * Example:
 *      RANDOMX *  RANDOMX + RANDOMX / RANDOMX
 * Will expand:
 *      976b7b3f *  ec13f6c1 + 2c06e6cf / ebe58755
 * Note:
 *  The algorithm used for generating random numbers here is the RC4 
 *  algorithm which works well for this situation.
 * Note:
 * A call to this macro is equivalent to:
 *        NUMTOHEX(RANDOM)
 * and the example above could be replaced by:
 *      NUMTOHEX(RANDOM) *  NUMTOHEX(RANDOM) + NUMTOHEX(RANDOM) / NUMTOHEX(RANDOM)
 * Refer to the 'NUMTOHEX' and 'RANDOM' macro for more information.
 */
static int MacroBuiltin_RandomX(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxu32 nRandom;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* One time RC4 context initialization */
#if defined(XPP_ENABLE_THREADS)
	 /* Enter the global mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	 SyRandomnessInit(&sRC4,0,0);
	/* Generate the random number */
	SyRandomness(&sRC4,(void *)&nRandom,sizeof(sxu32));
#if defined(XPP_ENABLE_THREADS)
	 /* Leave the global mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	/* Expand */
	xpp_context_format(&(*pCtx),"%x",nRandom);
	return SXRET_OK;
}
/*
 * RANDOM_STR:
 *   Generate and expand a random string.
 * Expects: 
 *   Zero or one argument specifying the desired string length.
 * Expands:
 *   Constant literal string (English alphabet based).
 * Example:
 *      RANDOM_STR(3)
 *      RANDOM_STR(7)
 *      RANDOM_STR()
 * Will expand:
 *     gtp
 *     bhutvsp
 *     udjzfkpicmfllhnn
 * Note: 
 *  If no arguments are given then this macro will output a random string
 *  of length 16.
 * Note:
 *  The maximum allowed string length is 512.
 * Note: 
 *  The algorithm used for generating random numbers here is the RC4 
 *  algorithm which works well for this situation.
 */
#define SXRANDOM_STR_MACRO_LENGTH 16
static int MacroBuiltin_RandomStr(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	static const char zBase[] = {"abcdefghijklmnopqrstuvwxyz"};
	sxu32 nLength = SXRANDOM_STR_MACRO_LENGTH;
	char zRandom[512];
	xpp *pEngine;
	sxu32 i;
	
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	if( nArg > 0 ){
		/* Try to get the desired string length */
		nLength = (sxu32)xpp_context_arg_to_int(&(*pCtx),&azArg[0]);
		if( nLength <= 0 || nLength >= sizeof(zRandom) ){
			nLength = SXRANDOM_STR_MACRO_LENGTH;
		}
	}
	/* One time RC4 context initialization */
#if defined(XPP_ENABLE_THREADS)
	 /* Enter the global mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	 SyRandomnessInit(&sRC4,0,0);
	 /* Generate a random binary string first */
	 SyRandomness(&sRC4,zRandom,nLength);
#if defined(XPP_ENABLE_THREADS)
	 /* Leave the global mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	 /* Turn the binary string into english based alphabet */
	for( i = 0 ; i < nLength ; ++i ){
		zRandom[i] = zBase[zRandom[i] % (sizeof(zBase)-1)];
	}
	/* Expand */
	xpp_context_append(&(*pCtx),zRandom,nLength);
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/* Forward declaration */
static sxi32 ExpandOsName(xpp_context *pCtx);
static sxi32 ExpandSysCmd(xpp_context *pCtx,const SyString *pCmd);
/*
 * OS:
 *  Expand to the name of the host Operating System.
 * Expects:
 *  No arguments.
 * Expands:
 *  Constant string literal.
 * Example:
 *   Host O##S: OS 
 *   Note that the '##' is the default concatenation operator which assemble
 *   two distinct tokens and prevent expanding a single token like 'OS'.
 * The example above will expand:
 *   Host OS: Microsoft Windows 7
 * or
 *   Host OS: FreeBSD 9.0
 */
static int MacroBuiltin_OS(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	sxi32 rc;
	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	/* Expand  */
	rc = ExpandOsName(&(*pCtx));
	if( pEngine->sConfig.bQuoted ){
		/* Delimit the expanded result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return rc;
}
/*
 * SYSCMD:
 *  Execute a system command.
 * Expects:
 *  Single argument (command to execute)
 * Expands:
 *  Single digit:
 *      1 (TRUE) if the command was successfully executed.0 (FALSE) otherwise.
 * Example:
 *    SYSCMD(date)
 * Will expand:
 *   1 
 * or
 *  0
 */
static int MacroBuiltin_SysCmd(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 rc = SXRET_OK;
	if( nArg > 0 ){
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[0]);
		/* Expand  */
		rc = ExpandSysCmd(&(*pCtx),&azArg[0]);
	}
	return rc;
}
#endif /* XPP_OMIT_BUILTIN */
/* File access and memory mapping objects */
typedef struct SyFileMethods SyFileMethods;
typedef struct SyFile SyFile;
typedef struct SyStat SyStat;

struct SyFileMethods
{
	sxi32 (*xOpen)(const void *,sxi32,void **);
	sxi32 (*xClose)(void *);
	sxi32 (*xRead)(void *,sxsize,sxsize *,void *);
	sxi32 (*xWrite)(const void *,sxsize,sxsize *,void *);
	sxi32 (*xWriteVec)(const syiovec *,int,sxsize *,void *);
	sxi32 (*xAtomicWrite)(const void *,sxsize,sxsize *,sxofft,void *);
	sxi32 (*xAtomicRead)(void *,sxsize,sxsize *,sxofft,void *);
	sxi32 (*xSync)(void *);
	sxi32 (*xLock)(void *,void *);
    sxi32 (*xUnLock)(void *,void *);
	sxi32 (*xStat)(SyStat *,void *);
	sxi32 (*xSeek)(sxu16,sxofft,sxofft *,void *);
	sxi32 (*xSeek64)(sxu16,sxofft64,sxofft64 *,void *);
	sxi32 (*xTruncate)(sxofft,void *);
	sxi32 (*xTruncate64)(sxofft64,void *);
	sxi32 (*xConfigure)(sxu32,void *,void *);
};
struct SyFile
{
	void * pHandle;                /* File handle [i.e: int on UNIX,HANDLE on windows]*/
	const SyFileMethods *pMethods; /* Virtual access methods */
};

#define SyFileGetHandle(PFILE) (PFILE)->pHandle
#define SyFileGetMethods(PFILE) (PFILE)->pMethods

#define SXFILE_OPEN_RDONLY		0x01
#define SXFILE_OPEN_WRONLY		0x02
#define SXFILE_OPEN_RDWR		0x04
#define SXFILE_OPEN_CREAT		0x08
#define SXFILE_OPEN_NONBLOCK	0x10
#define SXFILE_OPEN_TRUNC		0x20
#define SXFILE_OPEN_APPEND		0x40
#define SXFILE_OPEN_SHLOCK		0x80
#define SXFILE_OPEN_BINARY		0x100
#define SXFILE_OPEN_LARGEFILE	0x200
#define SXFILE_OPEN_TEMP		0x400
#define SXFILE_OPEN_NEW			0x800

#define SXFILE_SEEK_SET		1	
#define SXFILE_SEEK_CUR		2
#define SXFILE_SEEK_END		3

struct SyStat
{
	sxi64 nSize;     /* File size on disk */
	sytime tmCreat;  /* File creation time */
	sytime tmModif;  /* Last-Modification time */
	sxi16 nType;     /* File type [i.e: regular,pipe] */
	/* ID of this file on disk */
	sxu32	nDev;	/* device this file belong */
	sxu32	unID;	/* ID [i.e: inode number under UNIX] */
};
 /* Memory map permission flags */
#define SXMMAP_READ		0x01
#define SXMMAP_WRITE	0x02
#define SXMMAP_EXEC		0x04
/* Unused options for now */
#define SXMMAP_SHARED	1
#define SXMMAP_PRIVATE	2
#define SyMemMapGetAddr(MAPOBJ)		((MAPOBJ)->pAddr)
#define SyMemMapGetHandle(MAPOBJ)	((MAPOBJ)->pHandle)
typedef struct SyMapHandle	SyMapHandle;
struct SyMapHandle
{
	void *pAddr;	 /* Base address of the mapped object */
	void *pHandle;	 /* Map handle.Otherwise null */
	void *pUserdata; /* User private data associated with the memory mapped object */
};
/* Forward declaration */
static sxi32 SyFileInit(SyFile *pFile);
static sxi32 SyFileOpen(SyFile *pFile,const void *pFilename,sxi32 nFLags);
static sxi32 SyFileRead(SyFile *pFile,void *pBuffer,sxsize nBufsize,sxsize *pReaden);
static sxi32 SyFileClose(SyFile *pFile);
static sxi32 SyFileStat(SyFile *pFile,SyStat *pStat);

#ifndef XPP_OMIT_BUILTIN
#ifndef XPP_INCLUDE_BUF_SIZE
/* Include buffer size */
#define XPP_INCLUDE_BUF_SIZE 8192
#endif
/*
 * include,sinclude:
 *  Open,read and process one or more files.
 * verbatim,sverbatim:
 *   Open,read and copy files contents without any processing (blind copy).
 * Overview:
 *   You can include one or more files in the input at any time using the built-in
 *   macros 'include' and 'verbatim' as follows:
 *    include filename1 filename2 filename3 ...'\n'
 *    verbatim filename1 filename2 filename3...'\n'
 *    include(file1,file2)
 *    verbatim(file1,file2)
 *   inserts the contents of filenames in place of the include/verbatim command.
 *   The contents of the file is often a set of definitions.
 *   It is a fatal error if the file named in include/verbatim cannot be accessed.
 *   That is,this function return SXERR_IO and the processing is aborted immediately.
 *   To get some control over this situation, the alternate form can be used:
 *   sinclude/sverbatim (s is the prefix of silent) says nothing and continues 
 *   processing if the file cannot be accessed.
 *   The major difference between the 'include' and the 'verbatim' macro is that the former
 *   will process and expand the file if faced with some registered macro but the latter
 *   (verbatim) will copy the file contents blindly without any processing even if the target
 *   file contains some registered macros.
 * Expects:
 *   Variable number of full or relative file paths (flat or delimited arguments)
 * Expands:
 *   Target files contents.
 * Example:
 *    include file1.txt file2.html file3.php  
 *    include(/usr/local/share/doc/index.html) //full path
 * Will expand processed files contents.
 *    verbatim file.txt
 * Will expand file contents without any processing.
 * The verbatim macro is very useful if you need to gather some information about
 * the target file like it's MD5 sum,CRC32,Size...and thus:
 *   MD5(verbatim(file.pdf))
 * will expand the MD5 sum of the whole file
 *  CRC32(verbatim file.pdf)
 * will expand the CRC32 of the whole file.
 * Note:
 *  To register some include paths (directories used by the include/verbatim macros to
 *  build full paths if faced with relative file paths like file.txt....)
 *  call the [xpp_config()] interface with a configuration verb set to 
 *  XPP_CONFIG_IMPORT_PATH as follows:
 *   xpp_config(pEngine,XPP_CONFIG_IMPORT_PATH,"/usr/local/include");
 *   xpp_config(pEngine,XPP_CONFIG_IMPORT_PATH,"/usr/include");
 *   xpp_config(pEngine,XPP_CONFIG_IMPORT_PATH,"C:\path\to\include\folders");
 */
static int MacroBuiltin_Include(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	char zBuf[XPP_INCLUDE_BUF_SIZE];
	SyString sMacro = {0,0};  /* Invoked macro name [i.e: include,sinclude,verbatim or sverbatim] */
	SyString *pPath; /* include path */
	SyBlob sWorker;  /* Path builder */
	SyString sName;  /* File name */  
	sxu32 nReaden;   /* Total number of bytes readen so far */
	sxu8 bSilent;    /* TRUE if silent include [i.e: don't complain when the file is not found] */
	xpp *pEngine;    /* Macro processor */
	SyFile sFile;    /* File handle */ 
	sxi32 rc;
	int i,c;

	
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	/* Init the working buffer */
	SyBlobInit(&sWorker,&pEngine->sAllocator);
	/* Extract the name of the called macro */
	xpp_context_macro_name(&(*pCtx),&sMacro);
	/* Check if we deal with a normal include or silent include macro directive */
	bSilent = FALSE;
	if( sMacro.zString[0] == 's' ){
		/* Silent include macro does not complain when the target file is not found */
		bSilent = TRUE;
	}
	/* Select the appropriate path separator */ 
#ifdef __WINNT__
	c = '\\';
#else
	c = '/';
#endif
	SyFileInit(&sFile);
	
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		if( azArg[i].nByte == sizeof(char) && !SyisAlphaNum(azArg[i].zString[0]) ){
			/* Ignore trailing non-alphanumeric characters [i.e: ',",<..] */
			continue;
		}
		rc = SXERR_NOTFOUND;
		/* Clean up filename */
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[i]);
		SyStringDupPtr(&sName,&azArg[i]);
		if( sName.zString[0] == '"' || sName.zString[0] == '<' || sName.zString[0] == '\''|| sName.zString[0] == '(' ){
			SyStringUpdatePtr(&sName,sizeof(char));
			if( sName.nByte > 0 && 
				( sName.zString[sName.nByte - 1] == '"' || sName.zString[sName.nByte - 1] == '>' ||
				  sName.zString[sName.nByte - 1] == '\'' || sName.zString[sName.nByte - 1] == ')' ) ){
					sName.nByte--;
			}
			/* Ignore leading and trailing white spaces */
			SyStringFullTrim(&sName);
		}
		if( sName.nByte <= 0 ){
			continue;
		}
		if(
		sName.zString[0] == '/' ||
#ifdef __WINNT__
		(sName.nByte > 2 && sName.zString[1] == ':' && (sName.zString[2] == '\\' || sName.zString[2] == '/') ) ||
#endif
		 (sName.nByte > 1 && sName.zString[0] == '.' && sName.zString[1] == '/') ||
		 (sName.nByte > 2 && sName.zString[0] == '.' && sName.zString[1] == '.' && sName.zString[2] == '/')
		 ){
			 /* FULL PATH */
			char *zFullPath = (char *)sName.zString;
			if( sName.zString[sName.nByte] != 0 ){
				zFullPath[sName.nByte] = 0;
			}
			rc = SyFileOpen(&sFile,zFullPath,SXFILE_OPEN_RDONLY);
			if( rc == SXRET_OK ){
				/* Append file contents */
				while( SXRET_OK == SyFileRead(&sFile,zBuf,sizeof(zBuf),(sxsize *)&nReaden) ){
					if( nReaden > 0 ){
						xpp_context_append(&(*pCtx),zBuf,nReaden);
					}else{
						break;
					}
				}
				SyFileClose(&sFile);
				PushFilePath(&pEngine->sAllocator,&pEngine->sConfig.aFiles,zFullPath,0);
			}
			if( rc == SXRET_OK || bSilent == TRUE ){
				continue;
			}
			/* Error while importing external file */
			rc = SXERR_IO;
			pEngine->nErr++;
			PreprocessorConsumeError(&(*pEngine),XPP_ERR_FILE_IO,pCtx->nLine,
				"'%z' on line %u: IO error while importing external file: '%s'\n",
				&pCtx->sName,pCtx->nLine,zFullPath);
			return rc;
		}
		/* RELATIVE PATH */
		SySetResetCursor(&pEngine->sConfig.aPaths);
		while( SySetGetNextEntry(&pEngine->sConfig.aPaths,(void **)&pPath) == SXRET_OK ){
			
			SyBlobReset(&sWorker);
			/* Build full path */
			SyBlobFormat(&sWorker,"%z%c%z",pPath,c,&sName);
			/* Append null terminator */
			SyBlobAppend(&sWorker,"\0",sizeof(char));
			rc = SyFileOpen(&sFile,SyBlobData(&sWorker),SXFILE_OPEN_RDONLY);
			if( rc != SXRET_OK ){
				/* Check the next path */
				continue;
			}
			/* Append file contents */
			while( SXRET_OK == SyFileRead(&sFile,zBuf,sizeof(zBuf),(sxsize *)&nReaden) ){
				if( nReaden > 0 ){
					xpp_context_append(&(*pCtx),zBuf,nReaden);
				}else{
					break;
				}
			}
			PushFilePath(&pEngine->sAllocator,&pEngine->sConfig.aFiles,
				(const char *)SyBlobData(&sWorker),SyBlobLength(&sWorker) - 1);
			SyFileClose(&sFile);
			/* All done,file contents is included */
			rc = SXRET_OK;
			break;
		}
		if( rc != SXRET_OK ){
			if( bSilent == FALSE ){
				/* Complain if the target file cannot be opened */
				pEngine->nErr++;
				PreprocessorConsumeError(&(*pEngine),XPP_ERR_FILE_IO,pCtx->nLine,
				"'%z' on line %u: IO error while importing external file: '%z'\n",
				&pCtx->sName,pCtx->nLine,&sName);
				rc = SXERR_IO;
				return rc;
			}
		}
	}
	/* Release the working buffer */
	SyBlobRelease(&sWorker);
	return SXRET_OK;
}
/*
 * Check if a file is already imported.
 * Return SXRET_OK if the target file is imported.Otherwise return SXERR_NOTFOUND.
 * This routine is used by the 'import' directive to query it's internal database.
 */
static sxi32 FileImportCheck(SySet *pSet,const char *zFullPath,sxu32 nLen)
{
	SyString *aEntries;
	SyString sFile;
	sxu32 i;
	if( nLen <= 0 ){
		nLen = SyStrlen(zFullPath);
	}
	SyStringInitFromBuf(&sFile,zFullPath,nLen);
	aEntries = (SyString *)SySetBasePtr(pSet);
	for( i = 0  ; i < SySetUsed(pSet) ; ++i ){
		if( SyStringCmp(&aEntries[i],&sFile,SyMemcmp) == 0 ){
			/* File already imported */
			return SXRET_OK;
		}
	}
	/* File does not exists in the database */
	return SXERR_NOTFOUND;
}
/*
 * Install a processed file full path in the import database.
 * Return SXRET_OK on success.Any other value indicates failure.
 * This routine is used by the 'import' directive to update it's internal database.
 */
static sxi32 FileImportInstall(SyMemBackend *pAllocator,SySet *pSet,const char *zFullPath,sxu32 nLen)
{
	SyString sFile;
	char *zFile;
	sxi32 rc;
	
	if( nLen <= 0 ){
		nLen = SyStrlen(zFullPath);
	}
	/* Duplicate path */
	zFile = (char *)SyMemBackendStrDup(&(*pAllocator),zFullPath,nLen);
	if( zFile == 0 ){
		return SXERR_MEM;
	}
	SyStringInitFromBuf(&sFile,zFile,nLen);
	/* Install in the database */
	rc = SySetPut(&(*pSet),(const void *)&sFile);
	return rc;
}
/*
 * import,simport:
 *  This directive does the same job as include which mean that it open the target file
 *  and expand the processed content except that the target file is processed once.
 * Overview:
 *   Refer to the 'include' directive
 * Expects:
 *   Variable number of full or relative file paths (flat or delimited arguments).
 * Expands:
 *   Processed files contents.
 * Example:
 *   import file1.txt
 *   import(file1.txt)
 *   import file1.txt
 * The last two calls are no-ops since the file is already imported by the first call.
 */
static int MacroBuiltin_Import(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	char zBuf[XPP_INCLUDE_BUF_SIZE];
	SyString sMacro = {0,0};  /* Invoked macro name [i.e: include,sinclude,verbatim or sverbatim] */	
	SySet *pDataBase; /* Import database */
	SyString *pPath;  /* include path */
	SyBlob sWorker;   /* Path builder */
	SyString sName;   /* File name */  
	sxu32 nReaden;    /* Total number of bytes readen so far */
	sxu8 bSilent;     /* TRUE if silent include [i.e: don't complain when the file is not found] */
	xpp *pEngine;     /* Macro processor */
	SyFile sFile;     /* File handle */ 
	sxi32 rc;
	int i,c;

	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	/* Init the working buffer */
	SyBlobInit(&sWorker,&pEngine->sAllocator);
	/* Extract the name of the called macro */
	xpp_context_macro_name(&(*pCtx),&sMacro);
	/* Check if we deal with a normal include or silent include macro directive */
	bSilent = FALSE;
	if( sMacro.zString[0] == 's' ){
		/* Silent include does not complain when the target file is not found */
		bSilent = TRUE;
	}
	/* Access to the import database */
	pDataBase = (SySet *)xpp_context_peek_auxdata(&(*pCtx));
	if( pDataBase == 0 ){
		/* Create and install the import database */
		pDataBase = (SySet *)SyMemBackendAlloc(&pEngine->sAllocator,sizeof(SySet));
		if( pDataBase == 0 ){
			PreprocessorConsumeError(&(*pEngine),XPP_ERR_OUT_OF_MEMORY,pCtx->nLine,
				"'%z' on line %u: Memory failure while creating the import database\n",
				&pCtx->sName,pCtx->nLine);
			return SXRET_OK;
		}
		SySetInit(pDataBase,&pEngine->sAllocator,sizeof(SyString));
		/* Save the import database as auxiliary data */
		xpp_context_push_auxdata(&(*pCtx),pDataBase);
		pEngine->pImportDB = pDataBase;
	}
	/* Select the appropriate path separator */ 
#ifdef __WINNT__
	c = '\\';
#else
	c = '/';
#endif
	SyFileInit(&sFile);
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		if( azArg[i].nByte == sizeof(char) && !SyisAlphaNum(azArg[i].zString[0]) ){
			/* Ignore trailing non-alphanumeric characters [i.e: ',",<..] */
			continue;
		}
		rc = SXERR_NOTFOUND;
		/* Clean up filename  */
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[i]);
		SyStringDupPtr(&sName,&azArg[i]);
		/* Remove garbage */
		if( sName.zString[0] == '"' || sName.zString[0] == '<' || sName.zString[0] == '\''|| sName.zString[0] == '(' ){
			SyStringUpdatePtr(&sName,sizeof(char));
			if( sName.nByte > 0 && 
				( sName.zString[sName.nByte - 1] == '"' || sName.zString[sName.nByte - 1] == '>' ||
				  sName.zString[sName.nByte - 1] == '\'' || sName.zString[sName.nByte - 1] == ')' ) ){
					sName.nByte--;
			}
			SyStringFullTrim(&sName);
		}
		if( sName.nByte <= 0 ){
			continue;
		}
		if(
		sName.zString[0] == '/' ||
#ifdef __WINNT__
		(sName.nByte > 2 && sName.zString[1] == ':' && (sName.zString[2] == '\\' || sName.zString[2] == '/') ) ||
#endif
		 (sName.nByte > 1 && sName.zString[0] == '.' && sName.zString[1] == '/') ||
		 (sName.nByte > 2 && sName.zString[0] == '.' && sName.zString[1] == '.' && sName.zString[2] == '/')
		 ){
			 /* FULL PATH */
			char *zFullPath = (char *)sName.zString;
			if( sName.zString[sName.nByte] != 0 ){
				zFullPath[sName.nByte] = 0;
			}
			/* Check if the file is already imported */
			rc = FileImportCheck(pDataBase,zFullPath,0);
			if( rc == SXRET_OK ){
				/* File already imported */
				continue;
			}
			rc = SyFileOpen(&sFile,zFullPath,SXFILE_OPEN_RDONLY);
			if( rc == SXRET_OK ){
				/* Append file contents */
				while( SXRET_OK == SyFileRead(&sFile,zBuf,sizeof(zBuf),(sxsize *)&nReaden) ){
					if( nReaden > 0 ){
						xpp_context_append(&(*pCtx),zBuf,nReaden);
					}else{
						break;
					}
				}
				SyFileClose(&sFile);
				PushFilePath(&pEngine->sAllocator,&pEngine->sConfig.aFiles,zFullPath,0);
				/* Mark the file as imported */
				FileImportInstall(&pEngine->sAllocator,pDataBase,zFullPath,0);
				rc = SXRET_OK;
			}
			if( rc == SXRET_OK || bSilent == TRUE ){
				continue;
			}
			/* Error while importing external file */
			rc = SXERR_IO;
			pEngine->nErr++;
			PreprocessorConsumeError(&(*pEngine),XPP_ERR_FILE_IO,pCtx->nLine,
				"'%z' on line %u: IO error while importing external file: '%s'\n",
				&pCtx->sName,pCtx->nLine,zFullPath);
			return rc;
		}
		/* RELATIVE PATH */
		SySetResetCursor(&pEngine->sConfig.aPaths);
		while( SySetGetNextEntry(&pEngine->sConfig.aPaths,(void **)&pPath) == SXRET_OK ){
			SyBlobReset(&sWorker);
			/* Build full path */
			SyBlobFormat(&sWorker,"%z%c%z",pPath,c,&sName);
			/* Append null terminator */
			SyBlobAppend(&sWorker,"\0",sizeof(char));
			rc = SyFileOpen(&sFile,SyBlobData(&sWorker),SXFILE_OPEN_RDONLY);
			if( rc != SXRET_OK ){
				/* Check the next path */
				continue;
			}
			/* Check if the file is already imported */
			rc = FileImportCheck(pDataBase,(const char *)SyBlobData(&sWorker),SyBlobLength(&sWorker) - 1);
			if( rc == SXRET_OK ){
				/* File already imported */
				break;
			}
			/* Append file contents */
			while( SXRET_OK == SyFileRead(&sFile,zBuf,sizeof(zBuf),(sxsize *)&nReaden) ){
				if( nReaden > 0 ){
					xpp_context_append(&(*pCtx),zBuf,nReaden);
				}else{
					break;
				}
			}
			/* Mark as imported */
			FileImportInstall(&pEngine->sAllocator,pDataBase,(const char *)SyBlobData(&sWorker),SyBlobLength(&sWorker) - 1);
			PushFilePath(&pEngine->sAllocator,&pEngine->sConfig.aFiles,
				(const char *)SyBlobData(&sWorker),SyBlobLength(&sWorker) - 1);
			SyFileClose(&sFile);
			/* All done,file contents is included */
			rc = SXRET_OK;
			break;
		}
		if( rc != SXRET_OK ){
			if( bSilent == FALSE ){
				/* Complain if the target file cannot be opened */
				pEngine->nErr++;
				PreprocessorConsumeError(&(*pEngine),XPP_ERR_FILE_IO,pCtx->nLine,
				"'%z' on line %u: IO error while importing external file: '%z'\n",
				&pCtx->sName,pCtx->nLine,&sName);
				rc = SXERR_IO;
				return rc;
			}
		}
	}
	/* Release the working buffer */
	SyBlobRelease(&sWorker);
	return SXRET_OK;
}
/* Forward declaration */
static sxsize SySizeFormat(char *zBuf,sxsize nBufLen,sxi64 iSize);
/*
 * FORMAT_SIZE: 
 *   Expand a formatted version of the given size.
 * Expects:
 *  Variable numbers of 64-bit integer.
 * Expands:
 *  Constant literal string and a single white space
 *  (if faced with more than one argument).
 * Example:
 *  FORMAT_SIZE(52428800)
 *  FORMAT_SIZE(102400)
 *  FORMAT_SIZE(FILE_SIZE(/etc/rc.conf)) //Test on a FreeBSD box
 *  FORMAT_SIZE(1048567,51200)
 * Will expand:
 *  50.0 MB
 *  100.0 KB
 *  13.6 KB 
 *  0.9 MB 50.0 KB
 */
static int MacroBuiltin_FormatSize(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	char zBuf[128];
	sxi64 iSize; 
	sxu32 nLen;
	int i;

	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		/* Convert to 64-bit integer */
		iSize = 0;
		SyStrToInt64(azArg[i].zString,azArg[i].nByte,(void *)&iSize,0);
		if( iSize > 0 ){
			/* Format the size */
			nLen = (sxu32)SySizeFormat(zBuf,sizeof(zBuf),iSize);
		}else{
			zBuf[0] = '0'; zBuf[1] = 0;
			nLen = sizeof(char);
		}
		/* Expand */
		xpp_context_append(&(*pCtx),zBuf,nLen);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	return SXRET_OK;
}
/*
 * Stat a given file.
 * This function return SXRET_OK and the stat structure is filled with
 * appropriate information on success.Any other values indicates failure.
 * This function is only used by DISK IO macro like 'FILE_EXISTS','FILE_SIZE'
 * and 'FILE_MTIME'
 */
static sxi32 FileStats(const char *zFile,SyStat *pOut)
{
	SyFile sFile;
	sxi32 rc;

	SyFileInit(&sFile);
	rc = SyFileOpen(&sFile,(const void *)zFile,SXFILE_OPEN_RDONLY);
	if( rc != SXRET_OK ){
		return rc; /* IO error */
	}
	/* Stat the file */
	SyFileStat(&sFile,&(*pOut));
	/* Close the handle */
	SyFileClose(&sFile);
	return SXRET_OK;
}
/*
 * FILE_SIZE:
 *  Expands the size of the given file.
 * Expects:
 *  Variable number of arguments (left and right delimited).
 * Expands:
 *  Constant digit stream and a single white space
 *  (if faced with more than one argument).
 * Example:
 *     FILE_SIZE(/usr/local/www/httpd.conf)
 *     FILE_SIZE(C:\Users\dean\Desktop\rfc2617.pdf)
 * Will expand:
 *    51200
 *    121536
 * Note:
 *  The macro will expand '-1' if the target file cannot be opened.
 */
static int MacroBuiltin_FileSize(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	const SyString *pPath;  /* include path */
	SyBlob sWorker;         /* Path builder */
	SyStat sStat;           /* Information about the target file */
	sxi32 rc;
	int i,c;

	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	/* Init the working buffer */
	SyBlobInit(&sWorker,&pEngine->sAllocator);
	/* Select the appropriate path separator */ 
#ifdef __WINNT__
	c = '\\';
#else
	c = '/';
#endif
	sStat.nSize = 0; /* Prevent compiler warning */
	for( i = 0 ; i < nArg ; ++i ){
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[i]);
		pPath = &azArg[i];
		rc = SXERR_NOTFOUND;
		if( pPath->nByte <= 0 ){
			continue;
		}
		if(
		pPath->zString[0] == '/' ||
#ifdef __WINNT__
		(pPath->nByte > 2 && pPath->zString[1] == ':' && (pPath->zString[2] == '\\' || pPath->zString[2] == '/') ) ||
#endif
		 (pPath->nByte > 1 && pPath->zString[0] == '.' && pPath->zString[1] == '/') ||
		 (pPath->nByte > 2 && pPath->zString[0] == '.' && pPath->zString[1] == '.' && pPath->zString[2] == '/')
		 ){
			/* Full path,stat file directly  */
			rc = FileStats(pPath->zString,&sStat);
		}else{
			/* Relative path */
			SySetResetCursor(&pEngine->sConfig.aPaths);
			while( SySetGetNextEntry(&pEngine->sConfig.aPaths,(void **)&pPath) == SXRET_OK ){
				SyBlobReset(&sWorker);
				/* Build full path */
				SyBlobFormat(&sWorker,"%z%c%z",pPath,c,&azArg[i]);
				/* Append null terminator */
				SyBlobAppend(&sWorker,"\0",sizeof(char));
				/* Stat file */
				rc = FileStats((const char *)SyBlobData(&sWorker),&sStat);
				if( rc == SXRET_OK ){
					/* Correct stat */
					break;
				}
			}
		}
		if( rc != SXRET_OK ){
			PreprocessorConsumeError(&(*pEngine),XPP_ERR_FILE_IO,pCtx->nLine,
				"'%z' on line %u: IO error while importing external file: '%z'\n",
				&pCtx->sName,pCtx->nLine,&azArg[i]);
			/* Expand a negative number if there is an IO error */
			xpp_context_append(&(*pCtx),"-1",sizeof("-1")-1);
		}else{
			/* Expand */
			xpp_context_format(&(*pCtx),"%qd",sStat.nSize);
			/* %qd (BSD quad) is equivalent to %lld in the libc printf */
		}
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	SyBlobRelease(&sWorker);
	return SXRET_OK;
}
/*
 * FILE_EXISTS: 
 *  Expands 1 (TRUE) if the given file exists.0 (FALSE) otherwise.
 * Expects:
 *  Variable number of arguments(left and right delimited)
 * Expands:
 *  A single digit and a single white space  (if faced with more than one argument)
 * Example:
 *     FILE_EXISTS(/usr/local/www/httpd.conf) 
 * Will expand:
 *   1 //if file exists
 * or
 *  0 //if IO error.
 */
static int MacroBuiltin_FileExists(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	const SyString *pPath;  /* include path */
	SyBlob sWorker;         /* Path builder */
	SyStat sStat;           /* Information about the target file */
	sxi32 rc;
	int i,c;

	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	/* Init the working buffer */
	SyBlobInit(&sWorker,&pEngine->sAllocator);
	/* Select the appropriate path separator */ 
#ifdef __WINNT__
	c = '\\';
#else
	c = '/';
#endif
	sStat.nSize = 0; /* Prevent compiler warning */
	/* Go and extract contents size */
	for( i = 0 ; i < nArg ; ++i ){
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[i]);
		pPath = &azArg[i];
		rc = SXERR_NOTFOUND;
		if( pPath->nByte <= 0 ){
			continue;
		}
		if(
		pPath->zString[0] == '/' ||
#ifdef __WINNT__
		(pPath->nByte > 2 && pPath->zString[1] == ':' && (pPath->zString[2] == '\\' || pPath->zString[2] == '/') ) ||
#endif
		 (pPath->nByte > 1 && pPath->zString[0] == '.' && pPath->zString[1] == '/') ||
		 (pPath->nByte > 2 && pPath->zString[0] == '.' && pPath->zString[1] == '.' && pPath->zString[2] == '/')
		 ){
			/* Full path,stat file directly */
			rc = FileStats(pPath->zString,&sStat);
		}else{
			/* Relative path  */
			SySetResetCursor(&pEngine->sConfig.aPaths);
			while( SySetGetNextEntry(&pEngine->sConfig.aPaths,(void **)&pPath) == SXRET_OK ){
				/* Reset working buffer */
				SyBlobReset(&sWorker);
				/* Build full path */
				SyBlobFormat(&sWorker,"%z%c%z",pPath,c,&azArg[i]);
				/* Append null terminator */
				SyBlobAppend(&sWorker,"\0",sizeof(char));
				/* Stat file */
				rc = FileStats((const char *)SyBlobData(&sWorker),&sStat);
				if( rc == SXRET_OK ){
					/* Correct stat */
					break;
				}
			}
		}
		/* Expand */
		xpp_context_append(&(*pCtx),rc == SXRET_OK ? "1":"0",sizeof(char));
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	/* Release working buffer */
	SyBlobRelease(&sWorker);
	return SXRET_OK;
}
/*
 * FILE_MTIME:
 *  Expands file modification time
 * Expects:
 *  Variable number of arguments(left an right delimited)
 * Expands:
 *  ISO-8601 Date and a timestamps and a single white space
 *  (if faced with more than one argument).
 * Example:
 *     FILE_MTIME(/usr/local/www/httpd.conf) 
 * will expand
 *  2011-04-15 10:07:23
 * or
 *  -1 //if the file does not exists.
 */
static int MacroBuiltin_FileMtime(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	const SyString *pPath;  /* include path */
	SyBlob sWorker;         /* Path builder */
	SyStat sStat;           /* Information about the target file */
	xpp *pEngine;
	Sytm sTm;               
	sxi32 rc;
	int i,c;

	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	/* Init the working buffer */
	SyBlobInit(&sWorker,&pEngine->sAllocator);
	/* Select the appropriate path separator */ 
#ifdef __WINNT__
	c = '\\';
#else
	c = '/';
#endif
	sStat.nSize = 0; /* Prevent compiler warning */
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	for( i = 0 ; i < nArg ; ++i ){
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[i]);
		pPath = &azArg[i];
		rc = SXERR_NOTFOUND;
		if( pPath->nByte <= 0 ){
			continue;
		}
		if(
		pPath->zString[0] == '/' ||
#ifdef __WINNT__
		(pPath->nByte > 2 && pPath->zString[1] == ':' && (pPath->zString[2] == '\\' || pPath->zString[2] == '/') ) ||
#endif
		 (pPath->nByte > 1 && pPath->zString[0] == '.' && pPath->zString[1] == '/') ||
		 (pPath->nByte > 2 && pPath->zString[0] == '.' && pPath->zString[1] == '.' && pPath->zString[2] == '/')
		 ){
			/* Full path,stat file directly */
			rc = FileStats(pPath->zString,&sStat);
		}else{
			/* Relative path */
			SySetResetCursor(&pEngine->sConfig.aPaths);
			while( SySetGetNextEntry(&pEngine->sConfig.aPaths,(void **)&pPath) == SXRET_OK ){
				SyBlobReset(&sWorker);
				/* Build full path */
				SyBlobFormat(&sWorker,"%z%c%z",pPath,c,&azArg[i]);
				/* Append null terminator */
				SyBlobAppend(&sWorker,"\0",sizeof(char));
				/* Stat file */
				rc = FileStats((const char *)SyBlobData(&sWorker),&sStat);
				if( rc == SXRET_OK ){
					/* Correct stat */
					break;
				}
			}
		}
		if( rc != SXRET_OK ){
			PreprocessorConsumeError(&(*pEngine),XPP_ERR_FILE_IO,pCtx->nLine,
				"'%z' on line %u: IO error while importing external file: '%z'\n",
				&pCtx->sName,pCtx->nLine,&azArg[i]);
			/* Expand a negative number if there is an IO error */
			xpp_context_append(&(*pCtx),"-1",sizeof("-1")-1);
		}else{
			/* Time format */
			SyOSUtilFormatTimeToLocal(&sStat.tmModif,&sTm);
			/* Expand */
			xpp_context_format(&(*pCtx),"%04d-%02d-%02d %02d:%02d:%02d",
				sTm.tm_year,sTm.tm_mon+1,sTm.tm_mday,
				sTm.tm_hour,sTm.tm_min,sTm.tm_sec
				);
		}
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	if( pEngine->sConfig.bQuoted ){
		/* Expand the result in quotes */
		xpp_context_append(&(*pCtx),"\"",sizeof(char));
	}
	SyBlobRelease(&sWorker);
	return SXRET_OK;
}
 /*
  * EVAL:
  *  Evaluate an expression and expand the evaluation result.
  * Expects:
  *  Variable number of arguments(expressions).(left and right delimited).
  * Expands:
  *  Constant digit stream.
  * Note:
  *  Refer to the official documentation section "Expression and conditional macros"
  *  for more information on the handled operators,their precedence and
  *  associativity.
  * Example:
  *     define X 10
  * Logical expression:
  *     EVAL( (defined(MD5) && defined(BASE64)) || defined(CRC32)) && defined(X) && X == 10)
  *     Will expand:
  *     1 if the expression evaluates to TRUE.0 (FALSE) otherwise.
  * Arithmetic expression:
  *    EVAL ((X + 10 *30 / 200 % -RANDOM) - RANDOM) 
  */
static sxi32 MacroBuiltin_Eval(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 iResult;
	xpp *pEngine;
	int i;
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	/* Process expressions one after one */
	for( i = 0 ; i < nArg ; ++i ){
		iResult = 0;
		PreprocessorEvalExpr(pEngine,&azArg[i],&iResult);
		xpp_context_format(&(*pCtx),"%d",iResult);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	return SXRET_OK;
 }
#endif /* XPP_OMIT_BUILTIN */
/* xPP Configuration macros: 0036-11-26*/

/*
 * XPP_IMPORT_PATH: 
 * XPP_INCLUDE_PATH:
 *  Add a path to the import database.
 * Expects: 
 *  Variable number of arguments(paths) (flat or delimited).
 * Expands:
 *  Nothing.
 * Example:
 *  XPP_IMPORT_PATH(/usr/include,/usr/local/include)
 *  XPP_IMPORT_PATH C:\include\path '\n'
 */
static int MacroBuiltin_XPPImportPath(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	char *zPath;
	int i,rc;
	
	pEngine = (xpp *)xpp_context_userdata(pCtx);
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		if( azArg[i].nByte == sizeof(char) && !SyisAlphaNum(azArg[i].zString[0]) ){
			continue;
		}
		/* Duplicate path */
		zPath = SyMemBackendStrDup(&pEngine->sAllocator,azArg[i].zString,azArg[i].nByte);
		if( zPath == 0 ){ continue; }
		/* Register path */
		rc = xpp_config(pEngine,XPP_CONFIG_IMPORT_PATH,zPath);
		if( rc != SXRET_OK ){ continue; }
	}
	return SXRET_OK;
}
/*
 * XPP_RENAME_MACRO:
 *  Rename a registered macro.
 * Expects:
 *  Two arguments (flat or delimited): The first argument is the old macro 
 *  name,the second is the desired new name.
 * Expands:
 *  Nothing.
 * Example:
 *   XPP_RENAME_MACRO(DATE,__DATE__)
 *   XPP_RENAME_MACRO TIME __TIME__
 */
static int MacroBuiltin_XPPRenameMacro(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	if( nArg == 2 ){
		const char *zOld,*zNew;
		sxi32 rc;

		zOld = zNew = 0;
		pEngine = (xpp *)xpp_context_userdata(pCtx);
		/* Extract the old macro name */
		xpp_context_arg_trim_ws(pCtx,&azArg[0]);
		zOld = azArg[0].zString;
		/* Extract the new macro name */
		xpp_context_arg_trim_ws(pCtx,&azArg[1]);
		zNew = azArg[1].zString;
		if( SX_EMPTY_STR(zOld) || SX_EMPTY_STR(zNew) ){
			rc = SXERR_EMPTY;
		}else{
			char *zDup;
			/* Duplicate name */
			zDup = SyMemBackendStrDup(&pEngine->sAllocator,zNew,SyStrlen(zNew));
			if( zDup == 0 ){
				pEngine->nErr++;
				/* Generate an error message */
				PreprocessorConsumeError(pEngine,XPP_ERR_OUT_OF_MEMORY,pCtx->nLine,
					"'%z' on line %u: Macro processor is running out of memory\n",
					&pCtx->sName,pCtx->nLine);
				return SXRET_OK;
			}
			rc = xpp_rename_macro(pEngine,zOld,zDup);
		}
		if( SXRET_OK != rc ){
			/* Macro does not exists */
			pEngine->nErr++;
			/* Generate an error message */
			PreprocessorConsumeError(pEngine,XPP_ERR_UNDEFINED_MACRO,pCtx->nLine,
				"'%z' on line %u: Given argument '%z' is not a registered macro\n",
				&pCtx->sName,pCtx->nLine,&azArg[0]); 
		}
	}
	return SXRET_OK;
}
/*
 * XPP_NO_EXPAND.
 *   Do not process macro body.
 * Expects:
 *  Variable number of arguments (registered macros names) (flat or delimited).
 * Expands:
 *  Nothing
 * Example:
 *  define file /path/to/file
 *  Without call to XPP_NO_EXPAND,a call to 'file' will enter in an infinite
 *  recursive loop,this is due to the fact that 'file' will call it self recursively
 *  until the nesting limit is reached and the processing will abort.
 *  To avoid this situation call:
 *   XPP_NO_EXPAND(file)
 *  or
 *   XPP_NO_EXPAND file '\n'
 *  Now the 'file' macro will expand it self once without recursion.
 */
static int MacroBuiltin_XPPNoExpand(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	SyMacro *pMacro;
	xpp *pEngine;
	sxi32 rc;
	int i;

	pEngine = (xpp *)xpp_context_userdata(pCtx);
	for( i = 0 ; i < nArg ; ++i ){
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[i]);
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		/* Check if the given argument is a registered macro */
		rc = PreprocessorGetMacro(pEngine,&azArg[i],&pMacro);
		if( rc != SXRET_OK ){
			/* Raise an error */
			pEngine->nErr++;
			PreprocessorConsumeError(pEngine,XPP_ERR_UNDEFINED_MACRO,pCtx->nLine,
				"'%z' on line %u: Given argument '%z' is not a registered macro\n",
				&pCtx->sName,pCtx->nLine,&azArg[i]); 
			continue;
		}
		/* Set the ignore expanding flag */
		pMacro->iFlags |= USER_MACRO_IGNORE_EXPANDING;
	}
	return SXRET_OK;
}
/*
 * XPP_BLIND_COPY:
 *  Expand arguments without any processing (blind copy) (flat or delimited).
 * Expects:
 *   Variable number of arguments.
 * Expands:
 *  Given arguments.
 * Example:
 *  define X 14
 *  Without XPP_BLIND_COPY:
 *   X=X
 *  Will expand:
 *   14=14
 * Now:
 *   XPP_BLIND_COPY(X)=X
 * Will expand:
 *   X=14
 */
static int MacroBuiltin_XPPBlindCopy(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	int i;
	/* Expand */
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		xpp_context_append(&(*pCtx),azArg[i].zString,azArg[i].nByte);
	}
	return SXRET_OK;
}
/*
 * XPP_IGNORE_SPACE:
 *  Expand arguments without any white spaces (flat or delimited).
 * Expects:
 *   Variable number of arguments.
 * Expands:
 *  Given arguments without whites spaces.
 * Example:
 *  XPP_IGNORE_SPACE( H	e l l		o )
 * Will expand:
 *  Hello
 */
static int MacroBuiltin_XPPIgnoreSpace(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	const unsigned char *zIn,*zCur,*zEnd;
	int i;
	/* Expand without any white spaces */
	for( i = 0 ; i < nArg ; ++i ){
		if( azArg[i].nByte <= 0 ){
			continue;
		}
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[i]);
		zIn  = (const unsigned char *)azArg[i].zString;
		zEnd = &zIn[azArg[i].nByte];
		for(;;){
			if( zIn >= zEnd ){
				break;
			}
			zCur = zIn;
			while( zIn < zEnd ){
				if( zIn[0] >= 0xc0 ){
					/* UTF-8 stream */
					zIn++;
					while( zIn < zEnd && ((zIn[0] & 0xc0) == 0x80) ){
						zIn++;
					}
					continue;
				}else if( SyisSpace(zIn[0]) ){
					break;
				}
				zIn++;
			}
			if( zIn > zCur ){
				xpp_context_append(&(*pCtx),(const char *)zCur,(sxu32)(zIn-zCur));
			}
			while( zIn < zEnd ){
				if( zIn[0] >= 0xc0 || !SyisSpace(zIn[0]) ){
					break;
				}
				zIn++;
			}
		}
	}
	return SXRET_OK;
}
/*
 * XPP_ALIAS_MACRO
 *  Create an alias to a registered macro.
 * Expects:
 *  Two arguments(flat or delimited).The first argument is the registered
 *  macro name and the second is the desired alias name.
 * Expands:
 *  Nothing.
 * Example:
 *   XPP_ALIAS_MACRO(DATE,TODAY)
 *   XPP_ALIAS_MACRO TIME NOW '\n'
 * Now a Call to 'TODAY' is the same as calling 'DATE' and a call to 'NOW'
 * is the same as calling 'TIME'.
 */
static int MacroBuiltin_XPPAliasMacro(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	if( nArg == 2 ){
		const char *zAlias,*zMacro;
		SyHashEntry *pEntry;

		zAlias = zMacro = 0;
		pEngine = (xpp *)xpp_context_userdata(pCtx);
		/* Extract the real macro name */
		xpp_context_arg_trim_ws(pCtx,&azArg[0]);
		zMacro = azArg[0].zString;
		/* Extract the alias name */
		xpp_context_arg_trim_ws(pCtx,&azArg[1]);
		zAlias = azArg[1].zString;
		if( SX_EMPTY_STR(zAlias) || SX_EMPTY_STR(zMacro) ){
			pEntry = 0;
		}else{
			pEntry = SyHashGet(&pEngine->hMacro,zMacro,SyStrlen(zMacro));
		}
		if( pEntry == 0 ){
			/* Macro does not exists */
			pEngine->nErr++;
			/* Generate an error message */
			PreprocessorConsumeError(pEngine,XPP_ERR_UNDEFINED_MACRO,pCtx->nLine,
				"'%z' on line %u: Given argument '%z' is not a registered macro\n",
				&pCtx->sName,pCtx->nLine,&azArg[0]); 
		}else{
			SyMacro *pMacro = (SyMacro *)SyHashEntryGetUserData(pEntry);
			char *zDup;
			/* Duplicate alias name */
			zDup = SyMemBackendStrDup(&pEngine->sAllocator,zAlias,SyStrlen(zAlias));
			if( zDup == 0 ){
				pEngine->nErr++;
				/* Generate an error message */
				PreprocessorConsumeError(pEngine,XPP_ERR_OUT_OF_MEMORY,pCtx->nLine,
					"'%z' on line %u: Macro processor is running out of memory\n",
					&pCtx->sName,pCtx->nLine);
				return SXRET_OK;
			}
			/* Let the alias point to the desired macro definition */
			xpp_register_macro(pEngine,zDup,pMacro->xMacro,pMacro->pUserData,pMacro->iFlags);
		}
	}
	return SXRET_OK;
}
/*
 * XPP_TOTAL_LINES:
 *  Expand total number of processed lines.
 * Expects:
 *  No Arguments.
 * Expands:
 *  Constant digit stream.
 */
static int MacroBuiltin_XPPTotalLines(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	xpp_context_format(pCtx,"%u",pEngine->nLines);
	return SXRET_OK;
}
/*
 * XPP_TOTAL_COMMENTS:
 *  Expand total number of collected comments so far.
 * Expects:
 *  No Arguments.
 * Expands:
 *  Constant digit stream.
 */
static int MacroBuiltin_XPPTotalComments(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	xpp_context_format(pCtx,"%u",pEngine->nComment);
	return SXRET_OK;
}
/*
 * XPP_TOTAL_IGNORED:
 *  Expand total number of ignored tokens.
 * Expects:
 *  No Arguments.
 * Expands:
 *  Constant digit stream.
 */
static int MacroBuiltin_XPPTotalIgnored(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	xpp_context_format(pCtx,"%u",pEngine->nIgn);
	return SXRET_OK;
}
/*
 * XPP_TOTAL_TOKENS:
 *  Expand total number of collected tokens.
 * Expects:
 *   No Arguments.
 * Expands:
 *   Constant digit stream.
 */
static int MacroBuiltin_XPPTotalTokens(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	xpp_context_format(pCtx,"%u",SySetUsed(&pEngine->aToken));
	return SXRET_OK;
}
/*
 * XPP_TOTAL_ACTIVE_MACRO:
 *   Expand total number of active macros.
 * Expects:
 *   No Arguments.
 * Expands:
 *   Constant digit stream.
 */
static int MacroBuiltin_XPPTotalActiveMacro(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	xpp_context_format(pCtx,"%u",SyHashTotalEntry(&pEngine->hMacro));
	return SXRET_OK;
}
/*
 * XPP_TOTAL_USER_MACRO:
 *  Expand total number of user defined macros.
 * Expects:
 *  No Arguments.
 * Expands:
 *  Constant digit stream.
 */
static int MacroBuiltin_XPPTotalUserMacro(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	xpp_context_format(pCtx,"%u",pEngine->nUserMacro);
	return SXRET_OK;
}
/*
 * XPP_TOTAL_IF_CONDITION:
 *   Expand total number of conditional macros.
 * Expects:
 *   No Arguments.
 * Expands:
 *   Constant digit stream.
 */
static int MacroBuiltin_XPPTotalCondMacro(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	xpp_context_format(pCtx,"%u",pEngine->nCond);
	return SXRET_OK;
}
/*
 * XPP_TOTAL_ERRORS:
 *  Expand total number of errors seen while processing the input.
 * Expects:
 *  No Arguments.
 * Expands:
 *  Constant digit stream.
 */
static int MacroBuiltin_XPPTotalErrMacro(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;

	SXUNUSED(nArg); /* Prevent compiler warning */
	SXUNUSED(azArg);
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	xpp_context_format(pCtx,"%u",pEngine->nErr);
	return SXRET_OK;
}
/*
 * undef:
 *    Remove/Pop one or more registered macros.
 * Expects:
 *   Variable number or arguments (flat or delimited) of registered
 *   macros.
 * Expands:
 *      Nothing.
 * Example:
 *       undef MD5 BASE64 CRC32 '\n'
 *       undef(TOLOWER,TOUPPER)
 *       undef(X) 
 *       undef Y '\n'
 * Note:
 *  A call to undef with a registered macro that is defined below the undef
 *  directive is a no-op operation and so:
 *  undef PI
 *  define PI 3.14
 *  The 'undef' call here is a NO-OP since PI is defined later in the input (after the undef
 *  directive).The correct behavior is as follows:
 *  define PI 3.14
 *  undef PI
 */
static int MacroBuiltin_Undef(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	SyMacroDefs *pUserDef;
	SyHashEntry *pEntry;
	SyMacro *pMacro;
	xpp *pEngine;
	int i;
	/* Access to our private data */
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	for( i = 0 ; i < nArg ; ++i ){
		/* Remove leading and trailing white spaces */
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[i]);
		/* Check if the current argument is a registered macro */
		pEntry = SyHashGet(&pEngine->hMacro,azArg[i].zString,azArg[i].nByte);
		if( pEntry == 0 ){
			/* Raise an error since the given argument is not a registered macro */
			PreprocessorConsumeError(pEngine,XPP_ERR_UNDEFINED_MACRO,pCtx->nLine,
				"'%z' on line %u: Given argument '%z' is not a defined macro\n",
				&pCtx->sName,pCtx->nLine,&azArg[i]);
			continue;
		}
		pMacro = (SyMacro *)SyHashEntryGetUserData(pEntry);
		/* Check if we are allowed to undef this macro */
		if( pMacro->xMacro == MacroBuiltin_Expand ){
			pUserDef = (SyMacroDefs *)pMacro->pUserData;
			if( pCtx->nLine < pUserDef->nLine ){
				/* Cannot undef this macro since it is defined below the undef directive */
				continue;
			}
		}
		/* Delete from the hashtable */
		PreprocessorDeleteMacro(pEngine,&azArg[i]);
	}
	return SXRET_OK;
}
/*
 * defined:
 *  Expands 1 (TRUE) if the given argument is a registered macro.0 (FALSE) otherwise.
 * Expects:
 *  Variable number of arguments (flat or delimited)
 * Expands:
 *  Single digit and a single white space (if faced with more than one argument).
 * Example:
 *   defined MD5 BASE64 '\n'
 *   defined(CRC32,X)
 * Will expand:
 *   1 1
 *   1 0
 * Note:
 *  the 'defined' macro is very useful especially if used with conditional macro 
 *  directive as follows:
 *        if defined(MD5)
 *         The MD5 macro is defined
 *        else
 *         The MD5 macro is not defined
 *        endif
 */
static int MacroBuiltin_defined(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	int i;
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	for( i = 0 ; i < nArg ; ++i ){
		xpp_context_arg_trim_ws(pCtx,&azArg[i]);
		if( azArg[i].nByte <= 0 ||
			SyHashGet(&pEngine->hMacro,(const void *)azArg[i].zString,azArg[i].nByte) == 0 ){
				/* Macro is not defined,abort and expand FALSE */
				xpp_context_append(&(*pCtx),"0",sizeof(char));
				return SXRET_OK;
		}
	}
	/* Given macros are defined,expand TRUE */
	xpp_context_append(&(*pCtx),"1",sizeof(char));
	return SXRET_OK;
}
/*
 * ERROR:
 *  Expand the desired error message and abort processing immediately.
 * Expects:
 *  Variable number of arguments (flat or delimited).
 * Expands:
 *  Given arguments.
 * Example
 *  if !defined(MD5)
 *    ERROR(Fatal: The MD5 macro must be defined)
 *    //The following token will not be processed.
 *    Hello!!!
 *  endif
 * Will expand: (if the MD5 macro is not defined)
 *   Fatal: The MD5 macro must be defined
 */
static sxi32 MacroBuiltin_Error(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	int i;
	/* Extract the target macro processor */
	pEngine = (xpp *)xpp_context_userdata(&(*pCtx));
	/* Increment error counter */
	pEngine->nErr++;
	for(i = 0 ; i < nArg ; ++i ){
		xpp_context_arg_trim_ws(&(*pCtx),&azArg[i]);
		if(azArg[i].nByte <= 0 ){
			continue;
		}
		/* Expand */
		xpp_context_append(&(*pCtx),azArg[i].zString,azArg[i].nByte);
		if( i + 1 < nArg ){
			/* Append a space between expanded values */
			xpp_context_append(&(*pCtx)," ",sizeof(char));
		}
	}
	if( nArg == 1 ){
		/* Invoke the user defined error callback */
		PreprocessorConsumeError(pEngine,XPP_ERR_ABORT,pCtx->nLine,"%z\n",&azArg[0]);
	}
	return SXERR_ABORT; /* Abort processing and return immediately */
}
/* xPP internal macro definitions: 1127-20-5411 */
/*
 * Evaluate an [if] conditional macro directive.
 * When the parser recognize an if block in the form of:
 *  if CONDITION
 *  
 *  [else/elif]
 *
 *  endif
 * it calls (the parser) this function to evaluate the condition.
 * This function return SXRET_OK if the condition evaluates to TRUE.
 * SXERR_IGNORE otherwise (which tell the upper layer to ignore this block
 * and synchronize it's token cursor with the next elif,else or endif token).
 * Refer to the official documentation section "Expression and conditional macros"
 * for more information on the handled operators,their precedence and associativity.
 */
static sxi32 MacroBuiltin_EvalIf(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	sxi32 iResult = 0;
	xpp *pEngine;
	sxi32 rc;

	if( nArg < 1 ){
		/* Nothing to process */
		return SXERR_IGNORE;
	}
	/* Access to our private data */
	pEngine = (xpp *)pCtx;
	/* Evaluate the expression */
	rc = PreprocessorEvalExpr(pEngine,&azArg[0],&iResult);
	if( rc != SXRET_OK ){
		return rc; /* Syntax error or out-of-memory while parsing expression */
	}
	return iResult ? SXRET_OK /* Expression evaluate to TRUE */ : SXERR_IGNORE /* Expression evaluate to FALSE */;
}
/*
 * Evaluate an [ifdef] conditional macro.
 *  When the parser recognize an ifdef block in the form of:
 *  ifdef ONE OR MORE MACRO NAMES
 *  
 *  [else/elif]
 *
 *  endif
 * it calls (the parser) this function to evaluate the condition.
 * This function return SXRET_OK if the condition evaluates to TRUE.
 * SXERR_IGNORE otherwise (which tell the upper layer to ignore this block
 * and synchronize it's token cursor with the next elif,else or endif token).
 * Refer to the official documentation section "Expression and conditional macros"
 * for more information.
 */
static sxi32 MacroBuiltin_EvalIfdef(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	sxi32 rc;
	int i;
	/* Access to our private data */
	pEngine = (xpp *)pCtx;
	for( i = 0 ; i < nArg ; ++i ){
		/* Make sure the given macros are defined */
		rc = PreprocessorGetMacro(pEngine,&azArg[i],0);
		if( rc != SXRET_OK ){
			/* macro is not defined,tell the upper layer to ignore this block */
			return SXERR_IGNORE;
		}
	}
	return SXRET_OK; /* Process the [ifdef] block */
}
/*
 * Evaluate an [ifndef] conditional macro.
 * When the parser recognize an if block in the form of:
 *  ifndef ONE OR MORE MACRO NAMES
 *  
 *  [else/elif]
 *
 *  endif
 * it calls (the parser) this function to evaluate the condition.
 * This function return SXRET_OK if the condition evaluates to TRUE.
 * SXERR_IGNORE otherwise (which tell the upper layer to ignore this block
 * and synchronize it's token cursor with the next elif,else or endif token).
 * Refer to the official documentation section "Expression and conditional macros"
 * for more information on the handled operators,their precedence and associativity.
 *
 */
static sxi32 MacroBuiltin_EvalIfndef(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	xpp *pEngine;
	sxi32 rc;
	int i;
	
	/* Access to our private data */
	pEngine = (xpp *)pCtx;
	for( i = 0 ; i < nArg ; ++i ){
		/* Make sure the given macro are defined */
		rc = PreprocessorGetMacro(pEngine,&azArg[i],0);
		if( rc == SXRET_OK ){
			/* macro is defined,tell the upper layer to ignore this block */
			return SXERR_IGNORE;
		}
	}
	return SXRET_OK; /* Process the [ifndef] block */
}
/*
 * Expand an user defined macro.
 * This function is associated with every user defined.That is,when
 * a macro definition is extracted from the processed input xPP associates
 * this function with the macro name before registering it in the main 
 * hashtable.
 * Example:
 * define PI 3.14
 * Now,when the parser see the define keyword and after isolating the macro
 * definition,the PI macro is registered using the following statement:
 *   xpp_register(pEngine,"PI",MacroBuiltin_Expand,USER_MACRO_STRICT_INVOKE);
 *  or
 *  xpp_queue_macro(pEngine,"PI",MacroBuiltin_Expand,USER_MACRO_STRICT_INVOKE);
 * For more information on how macro are handled internally,refer to the official 
 * documentation section "xPP internals".
 * This function never fail and always return SXRET_OK.
 */
static sxi32 MacroBuiltin_Expand(xpp_context *pCtx,int nArg,const SyString *azArg)
{
	SyString sLeft,sRight; /* String delimiter */
	SyMacroDefs *pDefs;    /* Parse of the macro definition */
	SyMacroArg *aArg;      /* Macro arguments table if faced with a function-like macro */
	SyToken *aToken;       /* Macro body */
	SyString *pData;       
	SyToken *pToken;
	sxu32 nToken;
	sxi32 nVarg;
	sxi32 idx;
	sxu32 i;

	/* Access to the macro definition */
	pDefs = (SyMacroDefs *)xpp_context_userdata(&(*pCtx));
	/* Extract macro body */
	aToken = (SyToken *)SySetBasePtr(&pDefs->aBody);
	nToken = SySetUsed(&pDefs->aBody);
	/* Extract the formal argument table */
	aArg = (SyMacroArg *)SySetBasePtr(&pDefs->aArgs);
	SyStringInitFromBuf(&sLeft,"\"",sizeof(char));
	SyStringInitFromBuf(&sLeft,"\"",sizeof(char));
	if( SySetUsed(&pDefs->pEngine->sConfig.aStrings) > 0 ){
		SyString *pDelim;
		SySetAccess(&pDefs->pEngine->sConfig.aStrings,0,(void **)&pDelim);
		SyStringDupPtr(&sLeft,pDelim);
		SySetAccess(&pDefs->pEngine->sConfig.aStrings,1,(void **)&pDelim);
		SyStringDupPtr(&sRight,pDelim);
	}
	nVarg = 0;
	/* Expand the macro */
	for( i =  0 ; i < nToken ; ++i ){
		pToken = &aToken[i];
		pData =  &pToken->sData;
		if( (pToken->nType &
			(XPP_TK_FORMAL_ARG|XPP_TK_VAARG|XPP_TK_M4_HASH|XPP_TK_M4_ARG_LIST|XPP_TK_M4_NAME|XPP_TK_M4_ARG_LIST2)) == 0 ){
				if( (pToken->nType & XPP_TK_STRINGING) && i + 1 < nToken  ){
					if( aToken[i+1].nType & (XPP_TK_FORMAL_ARG|XPP_TK_VAARG|XPP_TK_M4_HASH|XPP_TK_M4_ARG_LIST|XPP_TK_M4_NAME|XPP_TK_M4_ARG_LIST2)){
						continue;
					}
				}
				/* Output token verbatim without any processing */
				xpp_context_append(&(*pCtx),pData->zString,pData->nByte);
				continue;
		}
		if( pToken->nType == XPP_TK_FORMAL_ARG ){
			/* Resolve formal argument  */
			idx = (int)pToken->pUserData; /* Argument index */
			/* Note that out of range indexes are silently ignored */
			if( idx >= 0 && idx < nArg ){
				if( azArg[idx].nByte > 0 ){
					/* Expand the argument value */
					if( i > 0 && aToken[i-1].nType == XPP_TK_STRINGING ){
						/* Stringfy:Expand the argument as a string */
						xpp_context_format(&(*pCtx),"%z%z%z",&sLeft,&azArg[idx],&sRight);
					}else{
						xpp_context_append(&(*pCtx),azArg[idx].zString,azArg[idx].nByte);
					}
				}
				nVarg++;
			}else{
				/* Check if a default value is associated with this argument */
				if( idx >= 0 && idx < (int)SySetUsed(&pDefs->aArgs) && SyStringLength(&aArg[idx].sDefValue) > 0 ){
					if( i > 0 && aToken[i-1].nType == XPP_TK_STRINGING ){
						/* Stringify: Expand the argument as a string */
						xpp_context_format(&(*pCtx),"%z%z%z",&sLeft,&aArg[idx].sDefValue,&sRight);
					}else{
						/* Expand the default value associated with this argument */
						xpp_context_append(&(*pCtx),SyStringData(&aArg[idx].sDefValue),SyStringLength(&aArg[idx].sDefValue));
					}
					nVarg++;
				}
			}
		}else if( pToken->nType == XPP_TK_M4_HASH ){
			/* M4 argument style expanding: $#: Expands to the number of given arguments */
			xpp_context_format(&(*pCtx),"%d",nArg);
		}else if( pToken->nType == XPP_TK_M4_NAME ){
			/* M4 argument style expanding: $0: Expands to the macro name */
			xpp_context_append(&(*pCtx),SyStringData(&pDefs->sName),SyStringLength(&pDefs->sName));
		}else if( pToken->nType == XPP_TK_M4_ARG_LIST ){
			/* M4 argument style expanding: $*: Expands to the list of arguments */
			int j;
			for( j = 0 ; j < nArg ; ++j ){
				if( azArg[j].nByte <= 0 ){
					continue;
				}
				xpp_context_append(&(*pCtx),azArg[j].zString,azArg[j].nByte);
				if( j + 1 < nArg ){
					/* Append a space between expanded values */
					xpp_context_append(&(*pCtx)," ",sizeof(char));
				}
			}
		}else if( pToken->nType == XPP_TK_M4_ARG_LIST2 ){
			/* M4 argument style expanding: $@: Expands to the list of arguments(quoted) */
			int j;
			for( j = 0 ; j < nArg ; ++j ){
				if( azArg[j].nByte <= 0 ){
					continue;
				}
				xpp_context_format(&(*pCtx),"\"%z\"",&azArg[j]);
				if( j + 1 < nArg ){
					/* Append a space between expanded values */
					xpp_context_append(&(*pCtx)," ",sizeof(char));
				}
			}
		}else if ( pToken->nType == XPP_TK_VAARG ){
			/* C preprocessor __VA_ARGS__ operator */
			int j;
			for( j = nVarg ; j < nArg ; ++j ){
				if( azArg[j].nByte <= 0 ){
					continue;
				}
				xpp_context_append(&(*pCtx),azArg[j].zString,azArg[j].nByte);
				if( j + 1 < nArg ){
					/* Append a space between expanded values */
					xpp_context_append(&(*pCtx)," ",sizeof(char));
				}
			}
		}
	}
	return SXRET_OK;
}
static const struct SyBuiltinMacro {
	SyString sName;           /* Name of the built-in macro */
	ProcMacroExpansion xCode; /* C function that implement macro body */
	int iFlags;               /* Macro invocation flags */
}aBuiltin[] = {
#ifndef XPP_OMIT_BUILTIN
	{{"TIME",sizeof("TIME")-1                  }, MacroBuiltin_Time,         USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"DATE",sizeof("DATE")-1                  }, MacroBuiltin_Date,         USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"ISO_DATE",sizeof("ISO_DATE")-1          }, MacroBuiltin_ISODate,      USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"TIMESTAMP",sizeof("TIMESTAMP")-1        }, MacroBuiltin_TimeStamp,    USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"FILENAME",sizeof("FILENAME")-1          }, MacroBuiltin_Filename,     USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"FILE",sizeof("FILE")-1                  }, MacroBuiltin_Filename,     USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"LINE",sizeof("LINE")-1                  }, MacroBuiltin_Line,         USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"LINEX",sizeof("LINEX")-1                }, MacroBuiltin_LineX,        USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"MD5",sizeof("MD5")-1                    }, MacroBuiltin_MD5,          USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"BASE64",sizeof("BASE64")-1              }, MacroBuiltin_Base64,       USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"BASE64_DECODE",sizeof("BASE64_DECODE")-1}, MacroBuiltin_Base64Decode, USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"CRC32",sizeof("CRC32")-1                }, MacroBuiltin_Crc32,        USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"HTML_ESCAPE",sizeof("HTML_ESCAPE")-1    }, MacroBuiltin_HTMLEscape,   USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"HTML_UNESCAPE",sizeof("HTML_UNESCAPE")-1}, MacroBuiltin_HTMLUnEscape, USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"HASH",sizeof("HASH")-1                  }, MacroBuiltin_Hash,         USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"HASHX",sizeof("HASHX")-1                }, MacroBuiltin_HashX,        USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"LEN",sizeof("LEN")-1                    }, MacroBuiltin_len,          USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"LENX",sizeof("LENX")-1                  }, MacroBuiltin_lenX,         USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"INCR",sizeof("INCR")-1                  }, MacroBuiltin_Incr,         USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"DECR",sizeof("DECR")-1                  }, MacroBuiltin_Decr,         USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"SUBSTR",sizeof("SUBSTR")-1              }, MacroBuiltin_Substr,       USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"INDEX",sizeof("INDEX")-1                }, MacroBuiltin_Index,        USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"OFFSET",sizeof("OFFSET")-1              }, MacroBuiltin_Index,        USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"MATCH",sizeof("MATCH")-1                }, MacroBuiltin_Match,        USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"TOUPPER",sizeof("TOUPPER")-1            }, MacroBuiltin_ToUpper,      USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"TOLOWER",sizeof("TOLOWER")-1            }, MacroBuiltin_ToLower,      USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"TOUTF8",sizeof("TOUTF8")-1              }, MacroBuiltin_ToUTF8,       USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"URIENCODE",sizeof("URIENCODE")-1        }, MacroBuiltin_UriEncode,    USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"URIDECODE",sizeof("URIDECODE")-1        }, MacroBuiltin_UriDecode,    USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"TOHEX",sizeof("TOHEX")-1                }, MacroBuiltin_ToHex,        USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"NUMTOHEX",sizeof("NUMTOHEX")-1          }, MacroBuiltin_NumToHex,     USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"TOOCTAL",sizeof("TOOCTAL")-1            }, MacroBuiltin_ToOctal,      USER_MACRO_STRICT_INVOKE||USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"RANDOM",sizeof("RANDOM")-1              }, MacroBuiltin_Random,       USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"RANDOMX",sizeof("RANDOMX")-1            }, MacroBuiltin_RandomX,      USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"RANDOM_STR",sizeof("RANDOM_STR")-1      }, MacroBuiltin_RandomStr,    USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"OS",sizeof("OS")-1                      }, MacroBuiltin_OS,           USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"SYSCMD",sizeof("SYSCMD")-1              }, MacroBuiltin_SysCmd,       USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"FORMAT_SIZE",sizeof("FORMAT_SIZE")-1    }, MacroBuiltin_FormatSize,   USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"FILE_SIZE",sizeof("FILE_SIZE")-1        }, MacroBuiltin_FileSize,     USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"FILE_EXISTS",sizeof("FILE_EXISTS")-1    }, MacroBuiltin_FileExists,   USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"FILE_MTIME",sizeof("FILE_MTIME")-1      }, MacroBuiltin_FileMtime,    USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING}, 
	{{"include",sizeof("include")-1            }, MacroBuiltin_Include,      USER_MACRO_FLAT_ARGS},
	{{"sinclude",sizeof("sinclude")-1          }, MacroBuiltin_Include,      USER_MACRO_FLAT_ARGS},
	{{"verbatim",sizeof("verbatim")-1          }, MacroBuiltin_Include,      USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"sverbatim",sizeof("sverbatim")-1        }, MacroBuiltin_Include,      USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"import",sizeof("import")-1              }, MacroBuiltin_Import,       USER_MACRO_FLAT_ARGS},
	{{"simport",sizeof("simport")-1            }, MacroBuiltin_Import,       USER_MACRO_FLAT_ARGS},
	{{"EVAL",sizeof("EVAL")-1                  }, MacroBuiltin_Eval,         USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING},
#endif /* XPP_OMIT_BUILTIN */
	/* Register some environments macro */
#ifdef __WINNT__
	{{"WINDOWS",sizeof("WINDOWS")-1      }, 0,    USER_MACRO_EMPTY},
	{{"WIN32",sizeof("WIN32")-1          }, 0,    USER_MACRO_EMPTY},
	{{"_WIN32",sizeof("_WIN32")-1        }, 0,    USER_MACRO_EMPTY},
#elif defined(__UNIXES__)
	{{"unix",sizeof("unix")-1            }, 0,    USER_MACRO_EMPTY},
	{{"__UNIX__",sizeof("__UNIX__")-1    }, 0,    USER_MACRO_EMPTY},
#endif
	/* Run time preprocessor configuration,statistics and license macros */
	{{"undef",sizeof("undef")-1                }, MacroBuiltin_Undef,        USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_EXPANDING|USER_MACRO_IGNORE_ARG_EXPANDING},
	{{"defined",sizeof("defined")-1            }, MacroBuiltin_defined,      USER_MACRO_STRICT_INVOKE|USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_EXPANDING|USER_MACRO_IGNORE_ARG_EXPANDING},
	{{"ERROR",sizeof("ERROR")-1                }, MacroBuiltin_Error,        USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_EXPANDING|USER_MACRO_IGNORE_ARG_EXPANDING},
	{{"XPP",sizeof("XPP")-1                    }, MacroBuiltin_XPP,          USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_COPYRIGHT",sizeof("XPP_COPYRIGHT")-1}, MacroBuiltin_XPPCopyright, USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_VERSION",sizeof("XPP_VERSION")-1    }, MacroBuiltin_XPPVersion,   USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_IMPORT_PATH",sizeof("XPP_IMPORT_PATH")-1   }, MacroBuiltin_XPPImportPath, USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_INCLUDE_PATH",sizeof("XPP_INCLUDE_PATH")-1 }, MacroBuiltin_XPPImportPath, USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_RENAME_MACRO",sizeof("XPP_RENAME_MACRO")-1 }, MacroBuiltin_XPPRenameMacro,USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_EXPANDING|USER_MACRO_IGNORE_ARG_EXPANDING},
	{{"XPP_ALIAS_MACRO",sizeof("XPP_ALIAS_MACRO")-1   }, MacroBuiltin_XPPAliasMacro, USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_EXPANDING|USER_MACRO_IGNORE_ARG_EXPANDING},
	{{"XPP_NO_EXPAND",sizeof("XPP_NO_EXPAND")-1       }, MacroBuiltin_XPPNoExpand,   USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_ARG_EXPANDING|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_BLIND_COPY",sizeof("XPP_BLIND_COPY")-1     }, MacroBuiltin_XPPBlindCopy,  USER_MACRO_COLLECT_ARGS|USER_MACRO_IGNORE_ARG_EXPANDING|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_IGNORE_SPACE",sizeof("XPP_IGNORE_SPACE")-1 }, MacroBuiltin_XPPIgnoreSpace,USER_MACRO_FLAT_ARGS|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_TOTAL_LINES",sizeof("XPP_TOTAL_LINES")-1      }, MacroBuiltin_XPPTotalLines, USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_TOTAL_COMMENTS",sizeof("XPP_TOTAL_COMMENTS")-1}, MacroBuiltin_XPPTotalComments, USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_TOTAL_IGNORED",sizeof("XPP_TOTAL_IGNORED")-1  }, MacroBuiltin_XPPTotalIgnored,  USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_TOTAL_TOKENS",sizeof("XPP_TOTAL_TOKENS")-1    }, MacroBuiltin_XPPTotalTokens,   USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_TOTAL_ERRORS",sizeof("XPP_TOTAL_ERRORS")-1    }, MacroBuiltin_XPPTotalErrMacro, USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_TOTAL_ACTIVE_MACRO",sizeof("XPP_TOTAL_ACTIVE_MACRO")-1}, MacroBuiltin_XPPTotalActiveMacro, USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_TOTAL_USER_MACRO",sizeof("XPP_TOTAL_USER_MACRO")-1    }, MacroBuiltin_XPPTotalUserMacro,   USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING},
	{{"XPP_TOTAL_IF_CONDITION",sizeof("XPP_TOTAL_IF_CONDITION")-1}, MacroBuiltin_XPPTotalCondMacro,   USER_MACRO_STRICT_INVOKE|USER_MACRO_IGNORE_EXPANDING}
};
/* Forward declaration */
static sxi32 SyBlobInitFromBuf(SyBlob *pBlob,void *pBuffer,sxsize nSize);
/*
 * Default nesting limit.
 */
#if defined(__UNIXES__) || defined(__WINNT__)
#define XPP_NESTING_LIMIT  32
#else
#define XPP_NESTING_LIMIT  16
#endif
/*
 * Configure a working macro processor instance.
 * Refer to [xpp_config()].
 */
static sxi32 PreprocessorConfigure(xpp *pEngine,sxi32 nOp,va_list ap)
{
	xpp_conf *pConf = &pEngine->sConfig;
	const unsigned char *zCur;
	sxi32 rc = SXRET_OK;
	SyString sTmp;
	sxu32 nLen;

	switch(nOp){
	  case XPP_CONFIG_ARG_DELIMITER: {
		  /* Left and right arguments delimiters [default: '(',')'] */
		  const char *zLeft  = va_arg(ap,const char *);
		  const char *zRight = va_arg(ap,const char *);
#if defined(UNTRUST)
		  if( SX_EMPTY_STR(zLeft) ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  zCur = (unsigned char *)zLeft;
		  /* Isolate the left delimiter.
		   * Note: Alphanumeric stream are not allowed
		   */
		  while( zCur[0] != 0 && zCur[0] < 0xc0 && !SyisAlphaNum(zCur[0]) ){
			  zCur++;
		  }
		  if( (const char *)zCur == zLeft ){
			  /* Invalid operator */
			  rc = SXERR_INVALID;
			  break;
		  }
		  nLen = (sxu32)((const char *)zCur - zLeft);
		  if( SX_EMPTY_STR(zRight) ){
			  if( nLen == sizeof("(") - 1 ){
				  if( zLeft[0] == '(' ){
					  zRight = ")";
				  }else if( zLeft[0] == '[' ){
					  zRight = "]";
				  }else if(zLeft[0] == '{' ){
					  zRight = "}";
				  }else{
					  /* Right delimiter must be present */
					  rc = SXERR_INVALID;
					  break;
				  }
			  }else if( nLen == sizeof("[[") - 1 ){
				  if( zLeft[0] == '[' && zLeft[1] == '[' ){
					  zRight = "]]";
				  }else if (zLeft[0] == '<' && zLeft[1] == '<' ){
					  zRight = ">>";
				  }else{
					  /* Right delimiter must be present */
					  rc = SXERR_INVALID;
					  break;
				  }
			  }else{
				  /* Right delimiter must be present */
				  rc = SXERR_INVALID;
				  break;
			  }
		  }
		  /* Register the argument delimiters */
		  SyStringInitFromBuf(&pConf->aArgDelim[0],zLeft,nLen);
		  SyStringInitFromBuf(&pConf->aArgDelim[1],zRight,SyStrlen(zRight));
		  break;
										 }
	  case XPP_CONFIG_ARG_SEPARATOR: {
		  /* Argument separator */
		  const char *zSep = va_arg(ap,const char *);
#if defined(UNTRUST)
		  if( SX_EMPTY_STR(zSep) ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  zCur = (const unsigned char *)zSep;
		  /* Isolate the argument separator.
		   * Note: Alphanumeric stream are not allowed
		   */
		  while( zCur[0] != 0 && zCur[0] < 0xc0 && !SyisAlphaNum(zCur[0]) ){
			  zCur++;
		  }
		  if( (const char *)zCur == zSep ){
			  /* Invalid operator */
			  rc = SXERR_INVALID;
			  break;
		  }
		  nLen = (sxu32)((const char *)zCur-zSep);
		  SyStringInitFromBuf(&pConf->sArgSep,zSep,nLen);
		  break;
										}
	  case XPP_CONFIG_COMMENT: {
		  /* Comment delimiter */
		  const char *zLeft = va_arg(ap,const char *);
		  const char *zRight = va_arg(ap,const char *);
#if defined(UNTRUST)  
		  if( SX_EMPTY_STR(zLeft) ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  zCur = (const unsigned char *)zLeft;
		  /* Isolate the left delimiter.
		   * Note: Alphanumeric stream are not allowed
		   */
		  while( zCur[0] != 0 && zCur[0] < 0xc0 && !SyisAlphaNum(zCur[0]) ){
			  zCur++;
		  }
		  if( (const char *)zCur == zLeft ){
			  /* Invalid operator */
			  rc = SXERR_INVALID;
			  break;
		  }
		  nLen = (sxu32)((const char *)zCur-zLeft);
		  if( SX_EMPTY_STR(zRight) ){
			  /* Assume comments ends at the end of the line */
			  zRight = "\n";
		  }
		  SyStringInitFromBuf(&sTmp,zLeft,nLen);
		  rc = SySetPut(&pConf->aComment,(const void *)&sTmp);
		  if( rc == SXRET_OK ){
			  SyStringInitFromBuf(&sTmp,zRight,SyStrlen(zRight));
			  rc = SySetPut(&pConf->aComment,(const void *)&sTmp);
			  if( rc != SXRET_OK ){
				  SySetRemove(&pConf->aComment,SySetUsed(&pConf->aComment) - 1,0);
			  }
		  }
		  break;
								   }
	  case XPP_CONFIG_CONCAT: {
		  /* Concatenation operator */
		  const char *zOp = va_arg(ap,const char *);
#if defined(UNTRUST)
		  if( SX_EMPTY_STR(zOp) ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  zCur = (const unsigned char *)zOp;
		  /* Isolate the concatenation operator.
		   * Note: Alphanumeric stream are not allowed
		   */
		  while( zCur[0] != 0 && zCur[0] < 0xc0 && !SyisAlphaNum(zCur[0]) ){
			  zCur++;
		  }
		  if( (const char *)zCur == zOp ){
			  /* Invalid operator */
			  rc = SXERR_INVALID;
			  break;
		  }
		  nLen = (sxu32)((const char *)zCur-zOp);
		  /* Register the allowed sequence */
		  SyStringInitFromBuf(&pConf->sConcat,zOp,nLen);
		break;
								  }
	  case XPP_CONFIG_STRING_DELIMITER: {
		  /* String delimiter */
		  const char *zLeft = va_arg(ap,const char *);
		  const char *zRight = va_arg(ap,const char *);
		  
		  if( SX_EMPTY_STR(zLeft) && SX_EMPTY_STR(zRight) ){
			  /* Set default delimiters */
			  zLeft = "\"";
			  zRight = "\"";
		  }
#if defined(UNTRUST)
		  if( SX_EMPTY_STR(zLeft) ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  zCur = (const unsigned char *)zLeft;
		  /* Isolate the operator.
		   * Note: Alphanumeric stream are not allowed
		   */
		  while( zCur[0] != 0 && zCur[0] < 0xc0 && !SyisAlphaNum(zCur[0]) ){
			  zCur++;
		  }
		  if( (const char *)zCur == zLeft ){
			  /* Invalid operator */
			  rc = SXERR_INVALID;
			  break;
		  }
		  nLen = (sxu32)((const char *)zCur - zLeft);
		  if( SX_EMPTY_STR(zRight) ){
			  /* Guess right quote */
			  if( nLen == sizeof("\"") - 1 ){
				  if( zLeft[0] == '"' ){
					  zRight = "\"";
				  }else if( zLeft[0] == '\''){
					  zRight = "'";
				  }else{
					  rc = SXERR_INVALID;
					  break;
				  }
			  }else if( nLen == sizeof("[[") - 1 ){
				  if( zLeft[0] == '[' && zLeft[1] == '[' ){
					  zRight = "]]";
				  }else if (zLeft[0] == '<' && zLeft[1] == '<' ){
					  zRight = ">>";
				  }else{
					  /* Right delimiter must be present */
					  rc = SXERR_INVALID;
					  break;
				  }
			  }
		  }
		  /* Register string delimiters */
		  SyStringInitFromBuf(&sTmp,zLeft,nLen);
		  rc = SySetPut(&pConf->aStrings,(const void *)&sTmp);
		  if( rc == SXRET_OK ){
			  SyStringInitFromBuf(&sTmp,zRight,SyStrlen(zRight));
			  rc = SySetPut(&pConf->aStrings,(const void *)&sTmp);
			  if( rc != SXRET_OK ){
				  SySetRemove(&pConf->aStrings,SySetUsed(&pConf->aStrings) - 1,0);
			  }
		  }
		  break;
								  }
	  case XPP_CONFIG_STRINGING_OPERATOR: {
		  /* Stringing operator */
		  const char *zOp = va_arg(ap,const char *);
#if defined(UNTRUST)
		  if( SX_EMPTY_STR(zOp) ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  zCur = (const unsigned char *)zOp;
		  /* Delimit the operator.
		   * Note: Alphanumeric stream are not allowed
		   */
		  while( zCur[0] != 0 && zCur[0] < 0xc0 && !SyisAlphaNum(zCur[0]) ){
			  zCur++;
		  }
		  if( (const char *)zCur == zOp ){
			  /* Invalid operator */
			  rc = SXERR_INVALID;
			  break;
		  }
		  nLen = (sxu32)((const char *)zCur-zOp);
		  /* Register the operator */
		  SyStringInitFromBuf(&pConf->sStringify,zOp,nLen);
		  break;
									   }
	  case XPP_CONFIG_IMPORT_PATH: {
		  /* Import path */
		  const char *zPath;
		  SyString sPath;
		  zPath = va_arg(ap,const char *);
#if defined(UNTRUST)
		  if( zPath == 0 ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  SyStringInitFromBuf(&sPath,zPath,SyStrlen(zPath));
		  /* Remove trailing slash and backslash stream */
#ifdef __WINNT__
		  SyStringTrimTrailingChar(&sPath,'\\');
#endif
		  SyStringTrimTrailingChar(&sPath,'/');
		  /* Remove leading and trailing white spaces */
		  SyStringFullTrim(&sPath);
		  if( sPath.nByte > 0 ){
			  /* Store the path in the corresponding set */
			  rc = SySetPut(&pConf->aPaths,(const void *)&sPath);
		  }
		  break;
									   }
	  case XPP_CONFIG_MACRO_KEYWORD: {
		  /* Macro keyword [i.e: define,macro...] */
		  const char *zName = va_arg(ap,const char *);
		  const char *zEnd  = va_arg(ap,const char *);
		  const unsigned char *zGuard;
#if defined(UNTRUST)
		  if( SX_EMPTY_STR(zName) ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  zGuard = (const unsigned char *)zName;
		  if( zGuard[0] < 0x0c && !SyisAlphaNum(zGuard[0]) ){
			  /* Invalid keyword: MUST BE ALPHANUMERIC or UTF-8 stream */
			  rc = SXERR_INVALID;
			  break;
		  }
		  if( SX_EMPTY_STR(zEnd) ){
			  /* Assume that a macro end at the end of the line */
			  zEnd = "\n";
		  }else if( zEnd[0] == '$' ){
			  /* Not allowed since it will create confusion when parsing M4 arguments */
			  rc = SXERR_INVALID;
			  break;
		  }
		  /* Save the name */
		  SyStringInitFromBuf(&sTmp,zName,SyStrlen(zName));
		  rc = SySetPut(&pConf->aIdent,(const void *)&sTmp);
		  if( rc == SXRET_OK ){
			  SyStringInitFromBuf(&sTmp,zEnd,SyStrlen(zEnd));
			  rc = SySetPut(&pConf->aIdent,(const void *)&sTmp);
			  if( rc != SXRET_OK ){
				  SySetRemove(&pConf->aIdent,SySetUsed(&pConf->aIdent) - 1,0);
			  }
		  }
		  break;
								}
	  case XPP_CONFIG_MACRO_PREFIX: {
		  /* Macro prefix [i.e: '#','.','!!'] */
		  const char *zPrefix = va_arg(ap,const char *);
#if defined(UNTRUST)
		  if( SX_EMPTY_STR(zPrefix) ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  zCur = (const unsigned char *)zPrefix;
		  /* Delimit the operator.
		   * Note: Alphanumeric stream are not allowed
		   */
		  while( zCur[0] != 0 && zCur[0] < 0xc0 && !SyisAlphaNum(zCur[0]) ){
			  zCur++;
		  }
		  if( (const char *)zCur == zPrefix ){
			  /* Invalid operator */
			  rc = SXERR_INVALID;
			  break;
		  }
		  nLen = (sxu32)((const char *)zCur-zPrefix);
		  /* Register the operator */
		  SyStringInitFromBuf(&pConf->sPrefix,zPrefix,nLen);
		  break;
									}

	  case XPP_CONFIG_NESTING_LIMIT:
		  /* Nesting limit */
		  pConf->nNest = va_arg(ap,sxi32);
		  if( pConf->nNest < 1 ){
			  pConf->nNest = XPP_NESTING_LIMIT;
		  }
		  break;
	  case XPP_CONFIG_OUTPUT_CONSUMER:{
		  /* Host-application output consumer callback */
		  ProcConsumer xConsumer = va_arg(ap,ProcConsumer);
		  void *pConsumerData = va_arg(ap,void *);
		  if( xConsumer == 0 ){
			  rc = SXERR_EMPTY;
			  break;
		  }
		  pEngine->xConsumer = xConsumer;
		  pEngine->pConsumerData = pConsumerData;
		  break;
										  }
	  case XPP_CONFIG_OUTPUT_BUFFER: {
		  /* Host-application output consumer buffer */
		  void *pBuf = va_arg(ap,void *);
		  sxsize n;
		  pConf->pOutlen = va_arg(ap,sxu32 *);
		  if( pConf->pOutlen == 0 ){
			  rc = SXERR_CORRUPT;
			  break;
		  }
		  n = (*pConf->pOutlen) - 1;
		  rc = SyBlobInitFromBuf(&pEngine->sConsumer,pBuf,n);
		  if( rc == SXRET_OK ){
			  pEngine->xConsumer = MacroBlobConsumer;
			  pEngine->pConsumerData = &pEngine->sConsumer;
		  }
		  break;
										 }
	  case XPP_CONFIG_OUTPUT_DYNAMIC_BUFFER:
		  /* Write a pointer to the expanded input */
		  pConf->ppBufer = va_arg(ap,void **);
		  pConf->pOutlen = va_arg(ap,sxu32 *);

		  rc = SyBlobInit(&pEngine->sConsumer,&pEngine->sAllocator);
		  if( rc == SXRET_OK ){
			  pEngine->xConsumer = MacroBlobConsumer;
			  pEngine->pConsumerData = &pEngine->sConsumer;
		  }
		  break;
	  case XPP_CONFIG_EXPAND_QUOTED:
		  /* Expand some of the built-in macro[i.e: MD5,DATE,OS,TIME...] in quotes */
		  pConf->bQuoted = TRUE;
		  break;
	  case XPP_CONFIG_TRACE_CALLBACK:
		  /* Register a trace callback */
		  pEngine->xTrace = va_arg(ap,ProcMacroTrace);
		  pEngine->pTraceData = va_arg(ap,void *);
#if defined(UNTRUST)
		  if( pEngine->xTrace == 0 ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  break;
	  case XPP_CONFIG_DISABLE_BUILTIN: {
		  sxu32 n = 0;
		  /* Disable built-in macros [i.e: DATE,TIME,MD5,CRC32...] except the configuration
		   * macro [i.e XPP_IMPORT_PATH,XPP_TOTAL_ERR,undef,ERROR...] */
		  for(;;){
			  if( n >= SX_ARRAYSIZE(aBuiltin) || aBuiltin[n].xCode == MacroBuiltin_Undef ){
				  break;
			  }
			  PreprocessorDeleteMacro(&(*pEngine),&aBuiltin[n].sName);
			  n++;
		  }
		  break;
									   }
	  case XPP_CONFIG_ERR_CALLBACK:
		  /* Register an error callback */
		  pEngine->xErr = va_arg(ap,ProcMacroErr);
		  pEngine->pErrData = va_arg(ap,void *);
#if defined(UNTRUST)
		  if( pEngine->xErr == 0 ){
			  rc = SXERR_EMPTY;
			  break;
		  }
#endif
		  break;
	  default:
		  /* Unknown config directive */
		  rc = SXERR_UNKNOWN;
		  break;
	}/* Switch() */
	return rc;
}
/*
 * [CAPIREF: xpp_config()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_config(xpp *pEngine,int nConfigOp,...)
{
	va_list ap;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_LIB_MISUSE || pEngine == 0 ){
		return SXERR_CORRUPT;
	}
#endif
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	if( pEngine->nMagic != XPP_ENGINE_MAGIC_INIT ){
		rc = SXERR_LOCKED;
	}else{
		/* Configure the macro processor */
		va_start(ap,nConfigOp);
		rc = PreprocessorConfigure(&(*pEngine),nConfigOp,ap);
		va_end(ap);
	}
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * Query a working macro processor instance and extract fields of interest.
 * Refer to [xpp_query()].
 */
static sxi32 PreprocessorQuery(xpp *pEngine,sxi32 nOp,va_list ap)
{
	sxi32 rc = SXRET_OK;
	sxu32 *pNum;
	switch(nOp){
	case XPP_TOTAL_TOKENS:
		/* Total number of processed tokens */
		pNum = va_arg(ap,sxu32 *);
#if defined(UNTRUST)
		if( pNum == 0 ){
			rc = SXERR_CORRUPT;
			break;
		}
#endif
		*pNum = SySetUsed(&pEngine->aToken);
		break;
	case XPP_TOTAL_ACTIVE_MACRO:
		/* Total number of active macros */
		pNum = va_arg(ap,sxu32 *);
#if defined(UNTRUST)
		if( pNum == 0 ){
			rc = SXERR_CORRUPT;
			break;
		}
#endif
		*pNum = SyHashTotalEntry(&pEngine->hMacro);
		break;
	case XPP_TOTAL_BUILTIN_MACRO:
		/* Total number of built-in macros */
		pNum = va_arg(ap,sxu32 *);
#if defined(UNTRUST)
		if( pNum == 0 ){
			rc = SXERR_CORRUPT;
			break;
		}
#endif
		*pNum = SX_ARRAYSIZE(aBuiltin);
		break;
	case XPP_TOTAL_USER_MACRO:
		/* Total number of user defined macros */
		pNum = va_arg(ap,sxu32 *);
#if defined(UNTRUST)
		if( pNum == 0 ){
			rc = SXERR_CORRUPT;
			break;
		}
#endif
		*pNum = pEngine->nUserMacro;
		break;
	case XPP_TOTAL_IF_CONDITION:
		/* Total number of conditional macro (if,elif,endif...) collected so far */
		pNum = va_arg(ap,sxu32 *);
#if defined(UNTRUST)
		if( pNum == 0 ){
			rc = SXERR_CORRUPT;
			break;
		}
#endif
		*pNum = pEngine->nCond;
		break;
	case XPP_TOTAL_LINES:
		/* Total number of processed lines */
		pNum = va_arg(ap,sxu32 *);
#if defined(UNTRUST)
		if( pNum == 0 ){
			rc = SXERR_CORRUPT;
			break;
		}
#endif
		*pNum = pEngine->nLines;
		break;
		case XPP_TOTAL_IGNORED:
		/* Total number of ignored tokens */
		pNum = va_arg(ap,sxu32 *);
#if defined(UNTRUST)
		if( pNum == 0 ){
			rc = SXERR_CORRUPT;
			break;
		}
#endif
		*pNum = pEngine->nIgn;
		break;
		case XPP_TOTAL_COMMENTS:
		/* Total number of collected comments */
		pNum = va_arg(ap,sxu32 *);
#if defined(UNTRUST)
		if( pNum == 0 ){
			rc = SXERR_CORRUPT;
			break;
		}
#endif
		*pNum = pEngine->nComment;
		break;
		case XPP_TOTAL_ERR:
			/* Total number of errors while processing the input */
			pNum = va_arg(ap,sxu32 *);
#if defined(UNTRUST)
		if( pNum == 0 ){
			rc = SXERR_CORRUPT;
			break;
		}
#endif
		*pNum = pEngine->nErr;
		break;
	default:
		rc = SXERR_UNKNOWN;
		break;
	}
	return rc;
}
/*
 * [CAPIREF: xpp_query()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_query(xpp *pEngine,int nOp,...)
{
	va_list ap;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine)  ){
		return SXERR_CORRUPT;
	}
#endif
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	 /* Extract fields of interest */
	 va_start(ap,nOp);
	 rc = PreprocessorQuery(&(*pEngine),nOp,ap);
	 va_end(ap);
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/* Forward declaration */
static sxi32 SyHashInit(SyHash *pHash,SyMemBackend *pAllocator,ProcHash xHash,ProcCmp xCmp);
/*
 * [CAPIREF: xpp_init()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_init(xpp **ppEngine)
{
	xpp *pEngine;
	sxi32 rc;
	sxu32 n;
#if defined(UNTRUST)
	if( ppEngine == 0 ){
		return SXERR_EMPTY;
	}
#endif
	/* One-time automatic library initialization */
	rc = xPPCoreInitialize();
	if( rc != SXRET_OK ){
		return rc;
	}
	/* Allocate a new macro processor */
	pEngine = (xpp *)SyMemBackendPoolAlloc(&sMPGlobal.sAllocator,sizeof(xpp));
	if( pEngine == 0 ){
		*ppEngine = 0;
		return SXERR_MEM;
	}
	/* Zero the structure */
	SyZero(pEngine,sizeof(xpp));
	/* Initialize structure fields */
	pEngine->nMagic = XPP_ENGINE_MAGIC_INIT;
	rc = SyMemBackendInitFromParent(&pEngine->sAllocator,&sMPGlobal.sAllocator);
	if( rc != SXRET_OK ){
		goto Release;
	}
#if defined(XPP_ENABLE_THREADS)
	SyMemBackendDisbaleMutexing(&pEngine->sAllocator);
#endif
	rc = SyHashInit(&pEngine->hMacro,&pEngine->sAllocator,0,0);
	if( rc != SXRET_OK ){
		goto Release;
	}
	/* Token table */
	rc = SySetInit(&pEngine->aToken,&pEngine->sAllocator,sizeof(SyToken));
	if( rc != SXRET_OK ){
		goto Release;
	}
	/* Pre-allocate some slots to avoid excessive calls to memory re-allocation routine */
	rc = SySetAlloc(&pEngine->aToken,1024);
	if( rc != SXRET_OK ){
		/* If the system is so sick that we are unable to allocate
		 * some slots,there is no much we can here.
		 */
		goto Release;
	}
	SySetInit(&pEngine->sConfig.aComment,&pEngine->sAllocator,sizeof(SyString));  /* Comment container */
	SySetInit(&pEngine->sConfig.aStrings,&pEngine->sAllocator,sizeof(SyString));  /* Constant string literal delimiters set */
	SySetInit(&pEngine->sConfig.aPaths,&pEngine->sAllocator,sizeof(SyString));    /* Import set */
	SySetInit(&pEngine->sConfig.aIdent,&pEngine->sAllocator,sizeof(SyString));    /* Macro keyword container */
	SySetInit(&pEngine->sConfig.aFiles,&pEngine->sAllocator,sizeof(SyString));    /* Processed files stack */
	/* Default configuration */
	xpp_config(&(*pEngine),XPP_CONFIG_ARG_DELIMITER,"(",")"); /* Argument delimiter */
	xpp_config(&(*pEngine),XPP_CONFIG_ARG_SEPARATOR,",");     /* Argument separator */
	xpp_config(&(*pEngine),XPP_CONFIG_CONCAT,"##");           /* Token pasting operator */
	rc = xpp_config(&(*pEngine),XPP_CONFIG_IMPORT_PATH,"./"); /* Import path */
	if( rc != SXRET_OK ){
		/* The XPP_CONFIG_IMPORT_PATH configuration is a critical operation and must therefore
		 * succeed.
		 */
		goto Release;
	}
	/* Register standard macro keyword */
	rc = xpp_config(&(*pEngine),XPP_CONFIG_MACRO_KEYWORD,"define","\n");   /* Emulate the C preprocessor define directive */
	if( rc != SXRET_OK ){ goto Release; }
	rc = xpp_config(&(*pEngine),XPP_CONFIG_MACRO_KEYWORD,"macro","endef"); /* The macro end at a 'endef' token */
	if( rc != SXRET_OK ){ goto Release; }
	xpp_config(&*(pEngine),XPP_CONFIG_NESTING_LIMIT,XPP_NESTING_LIMIT); /* Default nesting limit */
	rc = xpp_config(&(*pEngine),XPP_CONFIG_OUTPUT_DYNAMIC_BUFFER,0,0);  /* Allocate memory on demand */
	if( rc != SXRET_OK ){ goto Release; }
	/* Register built-in macros */
	for( n = 0 ; n < SX_ARRAYSIZE(aBuiltin) ; ++n ){
		PreprocessorRegisterMacro(&(*pEngine),&aBuiltin[n].sName,aBuiltin[n].xCode,pEngine,aBuiltin[n].iFlags);
	}
#if defined(XPP_ENABLE_THREADS)
	if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE ){
		 /* Associate a recursive mutex with this instance */
		 pEngine->pMutex = SyMutexNew(sMPGlobal.pMutexMethods,SXMUTEX_TYPE_RECURSIVE);
		 if( pEngine->pMutex == 0 ){
			 rc = SXERR_OS;
			 goto Release;
		 }
	 }
#endif
	/* Link to the list of active macro processors */
#if defined(XPP_ENABLE_THREADS)
	/* Enter the global mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	MACRO_LD_PUSH(sMPGlobal.pEngines,pEngine);
	sMPGlobal.nEngine++;
#if defined(XPP_ENABLE_THREADS)
	/* Leave the global mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	/* Write a pointer to the new instance */
	*ppEngine = pEngine;
	return SXRET_OK;
Release:
	SyMemBackendRelease(&pEngine->sAllocator);
	SyMemBackendPoolFree(&sMPGlobal.sAllocator,pEngine);
	*ppEngine = 0;
	return rc;
}
/*
 * [CAPIREF: xpp_register_macro()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_register_macro(xpp *pEngine,const char *zMacroName,ProcMacroExpansion xMacro,void *pUserData,int iFlags)
{
	SyString sName;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) || SX_EMPTY_STR(zMacroName) ){
		return SXERR_CORRUPT;
	}
#endif
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	SyStringInitFromBuf(&sName,zMacroName,SyStrlen(zMacroName));
	/* Jump leading and trailing white spaces */
	SyStringFullTrim(&sName);
	/* Register user macro */
	rc = PreprocessorRegisterMacro(&(*pEngine),&sName,xMacro,pUserData,iFlags);
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * [CAPIREF: xpp_queue_macro()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_queue_macro(xpp *pEngine,const char *zMacroName,ProcMacroExpansion xMacro,void *pUserData,int iFlags)
{
	SyString sName;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) || SX_EMPTY_STR(zMacroName) ){
		return SXERR_CORRUPT;
	}
#endif
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	SyStringInitFromBuf(&sName,zMacroName,SyStrlen(zMacroName));
	SyStringFullTrim(&sName);
	/* Queue user macro */
	rc = PreprocessorRegisterMacro2(&(*pEngine),&sName,xMacro,pUserData,iFlags);
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * [CAPIREF: xpp_pop_macro()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_pop_macro(xpp *pEngine,const char *zMacroName)
{
	SyString sName;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) || SX_EMPTY_STR(zMacroName) ){
		return SXERR_CORRUPT;
	}
#endif
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	SyStringInitFromBuf(&sName,zMacroName,SyStrlen(zMacroName));
	rc = PreprocessorDeleteMacro(&(*pEngine),&sName);
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * [CAPIREF: xpp_delete_macro()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_delete_macro(xpp *pEngine,const char *zMacroName)
{
	SyString sName;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) || SX_EMPTY_STR(zMacroName) ){
		return SXERR_CORRUPT;
	}
#endif
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	SyStringInitFromBuf(&sName,zMacroName,SyStrlen(zMacroName));
	rc = PreprocessorDeleteMacro(&(*pEngine),&sName);
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * [CAPIREF: xpp_rename_macro()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_rename_macro(xpp *pEngine,const char *zOldName,const char *zNewName)
{
	SyString sName;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) || SX_EMPTY_STR(zOldName) ){
		return SXERR_CORRUPT;
	}
#endif
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	SyStringInitFromBuf(&sName,zOldName,SyStrlen(zOldName));
	if( SX_EMPTY_STR(zNewName) ){
		/* Delete the macro if the new name is the NULL pointer */
		rc = PreprocessorDeleteMacro(pEngine,&sName);
	}else{
		rc = PreprocessorRenameMacro(pEngine,&sName,zNewName);
	}
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * [CAPIREF: xpp_is_registered_macro()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_is_registered_macro(xpp *pEngine,const char *zMacro)
{
	SyString sName;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) || SX_EMPTY_STR(zMacro) ){
		return 0;
	}
#endif
	SyStringInitFromBuf(&sName,zMacro,SyStrlen(zMacro));
	/* Query the hashtable */
	rc = PreprocessorGetMacro(&(*pEngine),&sName,0);
	return rc == SXRET_OK ? TRUE /* Registered macro */ : FALSE /* Not a registered macro */;
}
/*
 * [CAPIREF: xpp_expand()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_expand(xpp *pEngine,const char *zInput,unsigned int nLen,int iFlags)
{
	xpp_conf *pConf; 
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) || SX_EMPTY_STR(zInput) ){
		return SXERR_CORRUPT;
	}
#endif
	if( nLen <= 0 ){
		/* Compute input length */
		nLen = SyStrlen(zInput);
	}
	if( iFlags < 0 ){
		/* Set default processing flags:
		 * In the default processing mode,white spaces are reduced to a single 
		 * space and successive blank-lines are reduced to a single line.
		 */
		iFlags = XPP_REDUCE_WS;
	}
	if( iFlags & XPP_IGNORE_WS ){
		/* Ignore white space completely */
		iFlags &= ~XPP_REDUCE_WS;
	}
	/* Expand given input */
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	pEngine->iFlags = iFlags;
	/* Tokenize the input first */
	rc = PreprocessorProcessInput(&(*pEngine),&pEngine->aToken,zInput,nLen,0,1,
		&pEngine->nLines,&pEngine->nIgn);
	if( rc == SXRET_OK ){
		/* Process tokens */
		rc = PreprocessorExpandInput(&(*pEngine),(SyToken *)SySetBasePtr(&pEngine->aToken),SySetUsed(&pEngine->aToken),
			pEngine->xConsumer,pEngine->pConsumerData,pEngine->iFlags);
		/* Record processing result */
		pConf = &pEngine->sConfig;
		if( pConf->pOutlen || pConf->ppBufer ){
			SyBlob *pConsumer = &pEngine->sConsumer;
			if( pConsumer->nFlags & (SXBLOB_STATIC|SXBLOB_LOCKED) ){
				pConsumer->mByte++;
			}
			if( pConf->pOutlen ){
				*pConf->pOutlen = SyBlobLength(&pEngine->sConsumer);
			}
			/* Append the null terminator */
			SyBlobAppend(&pEngine->sConsumer,(const void *)"\0",sizeof(char));
			if( pConf->ppBufer ){
				*pConf->ppBufer = SyBlobData(&pEngine->sConsumer);
			}
		}
		pConf->bLF = TRUE;
	}
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/* Forward declaration */
static sxi32 SyOSMemoryUnmap(SyMapHandle *pMap,sxu32 nSize);
static sxi32 SyOSMemoryMap(SyFile *pFile,sxu32 nLen,sxofft nOfft,sxu32 nProt,SyMapHandle *pMap);
/*
 * [CAPIREF: xpp_expand_file()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_expand_file(xpp *pEngine,const char *zFilePath,int iFlags)
{
	char *zContents = 0;
	SyMapHandle sMap; 
	SyFile sFile;
	SyStat sStat;
	sxsize nSize;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) || SX_EMPTY_STR(zFilePath) ){
		return SXERR_CORRUPT;
	}
#endif
	SyFileInit(&sFile);
	/* Try to open the requested file */
	rc = SyFileOpen(&sFile,zFilePath,SXFILE_OPEN_RDONLY);
	if( rc != SXRET_OK ){
		/* IO error [i.e: File does not exist] or permission error */
		return SXERR_IO;
	}
	/* Extract file size */
	rc = SyFileStat(&sFile,&sStat);
	nSize = (sxsize)sStat.nSize;
	sMap.pAddr = sMap.pHandle = sMap.pUserdata = 0; /* Prevent compiler warning */
	if( rc == SXRET_OK ){
		/* Obtain a memory view of the whole file */ 
		rc = SyOSMemoryMap(&sFile,(sxofft)nSize,0,SXMMAP_READ,&sMap);
		if( rc == SXRET_OK ){
			/* Point to the content starting address */
			zContents = (char *)sMap.pAddr;
		}else{
#if defined(XPP_ENABLE_THREADS)
			/* Acquire engine mutex */
			SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
			if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
				SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
					return SXERR_ABORT; /* Another thread have released this instance */
			}
#endif
			/* Try to read the file contents using standard IO */
			zContents = (char *)SyMemBackendAlloc(&pEngine->sAllocator,(sxu32)nSize);
#if defined(XPP_ENABLE_THREADS)
			/* Leave engine mutex */
			SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
			if( zContents == 0 ){
				/* If the system is so sick that we are unable to allocate a chunk
				 * of memory,there is no much we can do here.
				 */
				rc = SXERR_MEM;
				goto Release;
			}
			/* Read the whole file */
			rc = SyFileRead(&sFile,zContents,nSize,&nSize);
			if( rc != SXRET_OK ){
				/* IO error */
				goto Release;
			}
		}
		/* Push the processed file path */
		PushFilePath(0,&pEngine->sConfig.aFiles,zFilePath,0);
		/* Expand the file */
		rc = xpp_expand(&(*pEngine),zContents,(sxu32)nSize,iFlags);
	}
Release:
	SyFileClose(&sFile);
	if( zContents ){
		if( (void *)zContents == sMap.pAddr ){
			/* unmap the memory view */
			SyOSMemoryUnmap(&sMap,nSize);
		}else{
			/* Release the allocated chunk of memory */
#if defined(XPP_ENABLE_THREADS)
			/* Acquire engine mutex */
			SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
			if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
				SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
					return SXERR_ABORT; /* Another thread have released this instance */
			}
#endif
			SyMemBackendFree(&pEngine->sAllocator,zContents);
#if defined(XPP_ENABLE_THREADS)
			/* Leave engine mutex */
			SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
		}
	}
	return rc;
}
/*
 * Release a macro definition
 * Refer to [xpp_release()].
 */
static void PreprocessorReleaseDefinition(SyMemBackend *pAllocator,SyMacroDefs *pDef)
{
	/* Release the Arg table */
	SySetRelease(&pDef->aArgs); 
	/* Release macro body */
	SySetRelease(&pDef->aBody); 
	SyMemBackendFree(&(*pAllocator),(void *)SyStringData(&pDef->sName));
	/* Release the whole instance */
	SyMemBackendPoolFree(&(*pAllocator),pDef);
}
/* Forward declaration */
static sxi32 SyHashRelease(SyHash *pHash);
/*
 * Release a working macro processor instance.
 * Refer to [xpp_release()].
 */
static sxi32 PreprocessorRelease(xpp *pEngine)
{
	SySetRelease(&pEngine->aToken);
	SyHashRelease(&pEngine->hMacro);
	SySetRelease(&pEngine->sConfig.aComment);  
	SySetRelease(&pEngine->sConfig.aIdent);    
	SySetRelease(&pEngine->sConfig.aPaths);    
	SySetRelease(&pEngine->sConfig.aStrings);
	SySetRelease(&pEngine->sConfig.aFiles);
	SyBlobRelease(&pEngine->sConsumer);
	/* Finally release the private memory subsytem */
	SyMemBackendRelease(&pEngine->sAllocator);
	/* Mark as a stale pointer */
	pEngine->nMagic = 0x2121;
	return SXRET_OK;
}
/*
 * [CAPIREF: xpp_release()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_release(xpp *pEngine)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) ){
		return SXERR_CORRUPT;
	}
#endif
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	/* Release internal components */
	rc = PreprocessorRelease(&(*pEngine));
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 /* Release engine mutex */
	 SyMutexRelease(sMPGlobal.pMutexMethods,pEngine->pMutex) /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
#if defined(XPP_ENABLE_THREADS)
	/* Enter the global mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	/* Unlink from the list of active macro processors */
	MACRO_LD_REMOVE(sMPGlobal.pEngines,pEngine);
	sMPGlobal.nEngine--;
#if defined(XPP_ENABLE_THREADS)
	/* Leave the global mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	/* Release the memory chunk allocated to this engine*/
	SyMemBackendPoolFree(&sMPGlobal.sAllocator,pEngine);
	return rc;
}
/* Forward declaration */
static sxi32 SyHashDeleteEntry2(SyHashEntry *pEntry);
static SyHashEntry * SyHashGetNextEntry(SyHash *pHash);
static sxi32 SyHashResetLoopCursor(SyHash *pHash);
/*
 * Reset a working macro processor instance.
 * Refer to [xpp_reset()].
 */
static sxi32 PreprocessorReset(xpp *pEngine)
{
	SyCondDirective *pCond,*pNextCond;
	SyHashEntry *pEntry;
	SyMacroDefs **aDef;
	SyMacro *pMacro;
	sxu32 n;

	SyHashResetLoopCursor(&pEngine->hMacro);
	/* Release all registered macros */
	while( (pEntry = SyHashGetNextEntry(&pEngine->hMacro)) != 0 ){
		pMacro = (SyMacro *)SyHashEntryGetUserData(pEntry);
		if( pMacro->xMacro == MacroBuiltin_Expand ){
			PreprocessorReleaseDefinition(&pEngine->sAllocator,(SyMacroDefs *)pMacro->pUserData);
			SyHashDeleteEntry2(pEntry);
			SySetRelease(&pMacro->aAuxData);
			SyMemBackendPoolFree(&pEngine->sAllocator,pMacro);
		}else{
			SySetReset(&pMacro->aAuxData);
		}
	}
	/* Release conditional definitions */
	pCond = pEngine->pCond;
	for(;;){
		if( pEngine->nCond <= 0 ){
			break;
		}
		pNextCond = pCond->pNext;
		/* Release macro defined in the [if] and [else] context */
		aDef = (SyMacroDefs **)SySetBasePtr(&pCond->aDefs);
		for( n = 0 ; n < SySetUsed(&pCond->aDefs) ; ++n ){
			PreprocessorReleaseDefinition(&pEngine->sAllocator,aDef[n]);
		}
		aDef = (SyMacroDefs **)SySetBasePtr(&pCond->aElseDefs);
		for( n = 0 ; n < SySetUsed(&pCond->aElseDefs) ; ++n ){
			PreprocessorReleaseDefinition(&pEngine->sAllocator,aDef[n]);
		}
		SySetRelease(&pCond->aDefs);
		SySetRelease(&pCond->aElseDefs);
		/* Release token table */
		SySetRelease(&pCond->aToken);
		/* Release the whole instance */
		SyMemBackendPoolFree(&pEngine->sAllocator,pCond);
		pCond = pNextCond;
		pEngine->nCond--;
	}
	if( pEngine->pImportDB ){
		SyString *pEntry;
		/* Release the import database */
		SySetResetCursor(pEngine->pImportDB);
		/* Release duplicated path */
		while( SXRET_OK == SySetGetNextEntry(pEngine->pImportDB,(void **)&pEntry) ){
			char *zDup = (char *)pEntry->zString;
			SyMemBackendFree(&pEngine->sAllocator,zDup);
		}
		SySetRelease(pEngine->pImportDB);
		SyMemBackendFree(&pEngine->sAllocator,pEngine->pImportDB);
		pEngine->pImportDB = 0;
	}
	/* Reset token table */
	SySetReset(&pEngine->aToken);
	/* Reset working buffer */
	SyBlobReset(&pEngine->sConsumer);
	/* Reset parser state variables */
	pEngine->nComment = 0;
	pEngine->nNest = 0;
	pEngine->nIgn = 0;
	pEngine->nUserMacro = 0;
	pEngine->nErr = 0;
	pEngine->nLines = 0;
	pEngine->sConfig.bLF = TRUE;
	SySetReset(&pEngine->sConfig.aFiles);
	return SXRET_OK;
}
/*
 * [CAPIREF: xpp_reset()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_reset(xpp *pEngine)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) ){
		return SXERR_CORRUPT;
	}
#endif
#if defined(XPP_ENABLE_THREADS)
	 /* Acquire engine mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
	 if( sMPGlobal.nThreadingLevel > XPP_THREAD_LEVEL_SINGLE && 
		 SyMemBackendPoolValidChunk(&sMPGlobal.sAllocator,&(*pEngine)) == FALSE ){
			 return SXERR_ABORT; /* Another thread have released this instance */
	 }
#endif
	rc = PreprocessorReset(&(*pEngine));
#if defined(XPP_ENABLE_THREADS)
	 /* Leave engine mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,pEngine->pMutex); /* NO-OP if sMPGlobal.nThreadingLevel != XPP_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * [CAPIREF: xpp_errmsg()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * xpp_errmsg(int rc)
{
	const char *z = "Unknown error";
	switch(rc){
	case SXRET_OK:      z = "Not an error"; break; 
	case SXERR_MEM:     z = "Out of memory"; break;
	case SXERR_LOCKED:  z = "Locked operation"; break;
	case SXERR_ABORT:   z = "Another thread have released this macro processor or the trace/error callback request an operation abort"; break;
	case SXERR_CORRUPT: z = "Corrupted or stale pointer"; break;
	case SXERR_IO:      z = "Input/Output related errors"; break;
	case SXERR_LIMIT:   z = "Nesting limit reached while expanding macro definition"; break;
	case SXERR_INVALID: z = "Invalid parameter"; break;
	case SXERR_SHORT:   z = "Given buffer cannot hold all the expanded input"; break; 
	case SXERR_NOTIMPLEMENTED: z = "Feature not implemented"; break;
	case SXERR_OS:      z = "Mutex or memory subystems failure"; break; 
	default:
		break;
	}
	return z;
}
/*
 * [CAPIREF: xpp_snprintf()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
unsigned int xpp_snprintf(char *zBuf,unsigned int nBuflen,const char *zFormat,...)
{
	va_list ap;
	sxu32 n;
	/* Format the string */
	va_start(ap,zFormat);
	n = (sxu32)SyBufferFormatAp(zBuf,(sxsize)nBuflen,zFormat,ap);
	va_end(ap);
	/* Total number of processed characters */
	return n;
}
/*
 * [CAPIREF: xpp_random_num()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_random_num(void)
{
	sxi32 nNum;
	/* One time RC4 context initialization */
#if defined(XPP_ENABLE_THREADS)
	sxi32 rc;
	/* Initialize the whole library,so we can access the global mutex */
	rc = xPPCoreInitialize();
	if( rc != SXRET_OK ){ return rc; }
	/* Enter the global mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	 SyRandomnessInit(&sRC4,0,0);
	 /* Generate a random number */
	 SyRandomness(&sRC4,(void *)&nNum,sizeof(sxi32));
#if defined(XPP_ENABLE_THREADS)
	 /* Leave the global mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	return nNum;
}
/*
 * [CAPIREF: xpp_random_string()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_random_string(char *zBuf,int nBuflen)
{
	static const char zBase[] = {"abcdefghijklmnopqrstuvwxyz"}; /* English Alphabet */
	sxi32 rc;
	sxi32 i;
	/* One time RC4 context initialization */
#if defined(XPP_ENABLE_THREADS)
	/* Initialize the whole library,so we can access the global mutex */
	rc = xPPCoreInitialize();
	if( rc != SXRET_OK ){ return rc; }
	 /* Enter the global mutex */
	 SyMutexEnter(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	 SyRandomnessInit(&sRC4,0,0);
	 /* Reserve room for the null terminator */
	 if( nBuflen > 0 ){
		 nBuflen--;
	 }
	 /* Generate a random binary string first */
	 rc = SyRandomness(&sRC4,zBuf,(sxsize)nBuflen);
#if defined(XPP_ENABLE_THREADS)
	 /* Leave the global mutex */
	 SyMutexLeave(sMPGlobal.pMutexMethods,sMPGlobal.pMutex); /* NO-OP if sMPGlobal.nThreadingLevel == XPP_THREAD_LEVEL_SINGLE */
#endif
	 if( rc != SXRET_OK ){
		 /* Something goes wrong while generating the binary string [i.e: NULL pointer] */
		 return rc;
	 }
	 /* Turn the binary string into english based alphabet */
	 for( i = 0 ; i < nBuflen ; ++i ){
		 zBuf[i] = zBase[zBuf[i] % (sizeof(zBase)-1)];
	 }
	 zBuf[i] = 0; /* Null terminate the generated string */
	return SXRET_OK;
}
/*
 * [CAPIREF: xpp_eval_expr()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int xpp_eval_expr(xpp *pEngine,const char *zExpression,int *pResult)
{
	SyString sExpr;
	sxi32 iResult;
	sxi32 rc;
#if defined(UNTRUST)
	if( XPP_ENGINE_CORRUPT(pEngine) || SX_EMPTY_STR(zExpression) ){
		return SXERR_CORRUPT;
	}
#endif
	SyStringInitFromBuf(&sExpr,zExpression,SyStrlen(zExpression));
	/* Evaluate the expression */
	rc = PreprocessorEvalExpr(&(*pEngine),&sExpr,&iResult);
	if( pResult ){
		*pResult = iResult;
	}
	return rc;
}
/*
 * Expression parser module.
 * Copyright (C) 2011-2012 Symisc Systems  http://symisc.net/
 * This module is taken from the Symisc compiler framework suite.
 * A framework used by symisc systems for its embeddable byte-code
 * implementation suite of some of the modern scripting languages like 
 * PHP,JavaScript and Ruby.
 * For more information visit: http://symisc.net/
 * This implementation is inspired from the one found in the TH1 source
 * tree developed by D.Richard Hipp.
 * Note that in this implementation floating point arithmetic is not allowed which
 * mean that all real numbers are converted to integer before applying integer arithmetic.
 */
typedef struct SyExprOp SyExprOp;
typedef struct SyExpr   SyExpr;
/*
 * Each supported operator [i.e: +,-,==*,%,>>,>=...] is represented by an instance
 * of the following structure.
 */
struct SyExprOp
{
	SyString sOp;      /* String representation of the operator [i.e: "+","*","=="...] */
	sxi32 iOp;         /* Operator ID [i.e: OP_PLUS,OP_EQ...] */
	sxi32 iPrec;       /* Operator precedence: 1 == Highest */ 
	sxi32 nArgType;    /* Expected argument,either string or integer */
};
/*
 * Each expression node is parsed out and recorded in an instance
 * of the following structure.
 */
struct SyExpr
{
	const SyExprOp *pOp;    /* Current operator or NULL if literal */
	SyExpr *pLeft;          /* Left expression node */
	SyExpr *pRight;         /* Right expression node */
	SyString sValue;        /* Literal value */
	sxu8 isNumber;          /* TRUE if the node is a stream of digit (decimal,octal or hex) */
};
/*
 * Supported arguments types
 */
#define EXPR_ARG_INTEGER  0x01
#define EXPR_ARG_STRING   0x02
/*
 * Supported operator
 */

/* Unary operators */
#define OP_UNARY_MINUS  1  /* Unary minus [i.e: -145,-589] */
#define OP_UNARY_PLUS   2  /* Unary plus  [i.e: +58,+565] */
#define OP_BIT_NOT      3  /* Bitwise not [i.e: ~654 ] */
#define OP_LOGICAL_NOT  4  /* Logical not [i.e: !defined(MD5) ] */
/* Binary operators */
#define OP_MUL          5  /* '*' */
#define OP_DIV          6  /* '/' */
#define OP_MOD          7  /* '%' */
#define OP_ADD          8  /* '+' */
#define OP_SUB          9  /* '-' */
#define OP_LSHIFT       10 /* << */
#define OP_RSHIFT       11 /* >> */
#define OP_LT           12 /* Less than '<' */
#define OP_LE           13 /* Less or equal '<=' */
#define OP_GT           14 /* Greater than '>' */
#define OP_GE           15 /* Greater or equal '>=' */
#define OP_EQ           16 /* Equal '==' */
#define OP_NEQ          17 /* Not equal '!=' */
#define OP_SEQ          18 /* String equal '===' */
#define OP_SNE          19 /* String not equal '!==' */
#define OP_BIT_AND      20 /* Bitwise and '&' */
#define OP_BIT_XOR      21 /* Bitwise xor '^' */
#define OP_BIT_OR       22 /* Bitwise or '|' */
#define OP_LOGICAL_AND  23 /* Logical and '&&' */
#define OP_LOGICAL_OR   24 /* Logical or  '||' */
/* Other symbols */
#define OP_OPEN_PAREN  0x1000 /* Open parenthesis '(' */
#define OP_CLOSE_PAREN 0x2000 /* Closing parenthesis ')' */
/* 
 * Operators table
 * This table is sorted by operators priority(highest to lowest).
 */
static const SyExprOp aOpTable[] = {
	/* Other symbols */
	{ {"(",sizeof(char)}, OP_OPEN_PAREN,  -1,0},
	{ {")",sizeof(char)}, OP_CLOSE_PAREN, -1,0},
	/* Unary operators */
	{ {"-",sizeof(char)},OP_UNARY_MINUS,1 /* Highest priority */,EXPR_ARG_INTEGER },
	{ {"+",sizeof(char)},OP_UNARY_PLUS, 1 /* Highest priority */,EXPR_ARG_INTEGER },
	{ {"~",sizeof(char)},OP_BIT_NOT,    1 /* Highest priority */,EXPR_ARG_INTEGER },
	{ {"!",sizeof(char)},OP_LOGICAL_NOT,1 /* Highest priority */,EXPR_ARG_INTEGER },
	/* Binary operators */
	{ {"*",sizeof(char)}, OP_MUL, 2,EXPR_ARG_INTEGER},
	{ {"/",sizeof(char)}, OP_DIV, 2,EXPR_ARG_INTEGER},
	{ {"%",sizeof(char)}, OP_MOD, 2,EXPR_ARG_INTEGER},
	{ {"+",sizeof(char)}, OP_ADD, 3,EXPR_ARG_INTEGER},
	{ {"-",sizeof(char)}, OP_SUB, 3,EXPR_ARG_INTEGER},
	{ {"<<",sizeof(char)*2}, OP_LSHIFT, 4, EXPR_ARG_INTEGER},
	{ {">>",sizeof(char)*2}, OP_RSHIFT, 4, EXPR_ARG_INTEGER},
	{ {"<",sizeof(char)},    OP_LT,  5, EXPR_ARG_INTEGER},
	{ {"<=",sizeof(char)*2}, OP_LE,  5, EXPR_ARG_INTEGER},
	{ {">",sizeof(char)},    OP_GT,  5, EXPR_ARG_INTEGER},
	{ {">=",sizeof(char)*2}, OP_GE,  5, EXPR_ARG_INTEGER},
	{ {"==",sizeof(char)*2}, OP_EQ,  6, EXPR_ARG_INTEGER},
	{ {"!=",sizeof(char)*2}, OP_NEQ, 6, EXPR_ARG_INTEGER},
	{ {"===",sizeof(char)*3}, OP_SEQ, 7, EXPR_ARG_STRING},
	{ {"!==",sizeof(char)*3}, OP_SNE, 7, EXPR_ARG_STRING},
	{ {"&",sizeof(char)}, OP_BIT_AND, 8,EXPR_ARG_INTEGER},
	{ {"^",sizeof(char)}, OP_BIT_XOR, 9,EXPR_ARG_INTEGER},
	{ {"|",sizeof(char)}, OP_BIT_OR,  10,EXPR_ARG_INTEGER},
	{ {"&&",sizeof(char)*2}, OP_LOGICAL_AND, 11,EXPR_ARG_INTEGER},
	{ {"||",sizeof(char)*2}, OP_LOGICAL_OR,  12,EXPR_ARG_INTEGER}
};
/*
 * Check if the given token is really an operator.
 * Return a pointer describing the operator if TRUE.NULL otherwise.
 */
static const SyExprOp * ExprExtractOperator(SyString *pToken,SyExpr *pLast)
{
	sxu32 n = 0;
	/* Do a linear lookup on the operators table */
	for(;;){
		if( n >= SX_ARRAYSIZE(aOpTable) ){
			break;
		}
		if( SyStringCmp(&aOpTable[n].sOp,pToken,SyMemcmp) == 0 ){
			if( aOpTable[n].iPrec != 1 || pLast == 0 || (pLast->pOp && pLast->pOp->iOp != OP_CLOSE_PAREN) ){
				/* Got an operator */
				return &aOpTable[n];
			}
		}
		n++;
	}
	return 0; /* Not an operator */
}
/* Forward declaration */
static sxi32 SyStrnicmp(const char *zLeft, const char *zRight,sxsize SLen);
/*
 * Extract a single token from the expression stream.
 */
static sxi32 ExprExtractToken(SyStream *pStream,xpp *pEngine,SyExpr *pLast,SyExpr **ppOut)
{
	const SyExprOp *pOp = 0;
	sxu8 isNumber = 0;
	SyString sToken;
	SyString sTmp;
	SyExpr *pExpr;
	sxi32 c;
	/* Jump leading white spaces */
	while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && 
		SyisSpace(pStream->zText[0]) ){
			/* Advance the stream cursor */
			pStream->zText++;
	}
	if( pStream->zText >= pStream->zEnd ){
		/* End of the input reached */
		return SXERR_EOF;
	}
	sToken.zString = (const char *)pStream->zText;
	if( pStream->zText[0] >= 0xc0 || SyisAlpha(pStream->zText[0]) || pStream->zText[0] == '_' ){
		const unsigned char *zIn;
		/* Isolate UTF-8 or alphanumeric stream */
		if( pStream->zText[0] < 0xc0 ){
			pStream->zText++;
		}
		for(;;){
			zIn = pStream->zText;
			/* Skip alphanumeric stream */
			while( zIn < pStream->zEnd && zIn[0] < 0xc0 ){
				if ( !SyisAlphaNum(zIn[0]) && !SyisSpace(zIn[0]) ){
					if( zIn[0] != '_' ){
						SyStringInitFromBuf(&sTmp,zIn,pStream->zEnd-zIn);
						if( SyStringCmp2(&sTmp,&pEngine->sConfig.aArgDelim[0],SyMemcmp) == 0 ){
							sxi32 iNest = 1;
							zIn += SyStringLength(&pEngine->sConfig.aArgDelim[0]);
							while( zIn < pStream->zEnd ){
								SyStringInitFromBuf(&sTmp,zIn,pStream->zEnd-zIn);
								if( SyStringCmp2(&sTmp,&pEngine->sConfig.aArgDelim[0],SyMemcmp) == 0 ){
									iNest++;
									zIn += SyStringLength(&pEngine->sConfig.aArgDelim[0]);
									continue;
								}else if( SyStringCmp2(&sTmp,&pEngine->sConfig.aArgDelim[1],SyMemcmp) == 0 ){
									iNest--;
									zIn += SyStringLength(&pEngine->sConfig.aArgDelim[1]);
									if( iNest <= 0 ){
										break;
									}
									continue;
								}
								zIn++;
							} /* While() */
							if( zIn >= pStream->zEnd && iNest > 0 ){
								return SXERR_SYNTAX;
							}
						}
						break;
					} 
				}
				zIn++;
			}
			if( zIn < pStream->zEnd && zIn[0] >= 0xc0 ){
				zIn++;
				/* UTF-8 stream */
				while( zIn < pStream->zEnd && ((zIn[0] & 0xc0) == 0x80) ){
					zIn++;
				}
			}
			if( zIn == pStream->zText ){
				/* Not an UTF-8 or alphanumeric stream */
				break;
			}
			/* Synchronize pointers */
			pStream->zText = zIn;
		}
	}else{
		xpp_conf *pConf = &pEngine->sConfig;
		SyString *pPrefix,*pSuffix;
		/* Check for the token grouping operator [single quote "'"] */
		if( pStream->zText[0] == '\'' ){
			pStream->zText++;
			sToken.zString = (const char *)pStream->zText;
			while( pStream->zText < pStream->zEnd ){
				if( pStream->zText[0] == '\'' && pStream->zText[-1] != '\\' ){
					break;
				}
				pStream->zText++;
			}
			/* Record token length */
			sToken.nByte = (sxu32)((const char *)pStream->zText-sToken.zString);
			/* Handle TRUE and FALSE tokens */
			if( sToken.nByte == sizeof("true") - 1 && SyStrnicmp(sToken.zString,"true",sizeof("true")-1) == 0 ){
				SyStringInitFromBuf(&sToken,"1",sizeof(char));
				isNumber = 1;
			}else if( sToken.nByte == sizeof("false") - 1 && SyStrnicmp(sToken.zString,"false",sizeof("false")-1) == 0 ){
				SyStringInitFromBuf(&sToken,"0",sizeof(char));
				isNumber = 1;
			}
			if( pStream->zText < pStream->zEnd ){
				/* Advance the stream cursor */
				pStream->zText++;
			}
			goto NewNode;
		}
		/* Check for commments */
		SySetResetCursor(&pConf->aComment);
		while( SySetGetNextEntry(&pConf->aComment,(void **)&pPrefix) == SXRET_OK ){
			SySetGetNextEntry(&pConf->aComment,(void **)&pSuffix);
			if( (sxu32)(pStream->zEnd - pStream->zText) >= pPrefix->nByte &&
				SyMemcmp((const void *)pStream->zText,(const void *)pPrefix->zString,pPrefix->nByte) == 0 ){
					pStream->zText += pPrefix->nByte;
					while( (sxu32)(pStream->zEnd - pStream->zText) >= pSuffix->nByte &&
						SyMemcmp((const void *)pStream->zText,(const void *)pSuffix->zString,pSuffix->nByte) != 0 ){
							/* Advance the stream cursor */
							pStream->zText++;
					}
					if( pStream->zText < pStream->zEnd ){
						pStream->zText += pSuffix->nByte;
					}
					/* Ignore comment */
					return SXERR_IGNORE;
			}
		}
		/* The raw text must be a digit stream or an operator */
		switch( pStream->zText[0] ){
		case '0':
			if( pStream->zText[1] == 'x' || pStream->zText[1] == 'X' ){
				/* Hex digit stream */
				pStream->zText += sizeof(char) * 2;
				while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisHex(pStream->zText[0]) ){
					pStream->zText++; 
				}
			}else{
				/* Octal digit stream */
				while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) /* 8 9 */ ){
					pStream->zText++; 
				}
			}
			isNumber = TRUE;
			break;
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8':
		case '9':
			/* A digit stream */
			while( pStream->zText < pStream->zEnd &&  pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
				pStream->zText++; 
			}
			isNumber = TRUE;
			if( pStream->zText >= pStream->zEnd ){
				break;
			}
			c = pStream->zText[0];
			if( c == '.' ){
				pStream->zText++;
				while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
					pStream->zText++; 
				}
				if( pStream->zText >= pStream->zEnd ){
					break;
				}
				c = pStream->zText[0];
				if( c=='e' || c=='E' ){
					pStream->zText++;
					if( pStream->zText >= pStream->zEnd ){
						break;
					}
					c = pStream->zText[0];
					if( (c =='+' || c=='-') && &pStream->zText[1] < pStream->zEnd  && 
						pStream->zText[1] < 0xc0 && SyisDigit(pStream->zText[1]) ){
							pStream->zText++; 
					}
					while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
						pStream->zText++; 
					}
				}
			}else if( c=='e' || c=='E' ){
				pStream->zText++;
				if( pStream->zText >= pStream->zEnd ){
					break;
				}
				c = pStream->zText[0];
				if( (c =='+' || c=='-') && &pStream->zText[1] < pStream->zEnd  && 
						pStream->zText[1] < 0xc0 && SyisDigit(pStream->zText[1]) ){
							pStream->zText++; 
				}
				while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
					pStream->zText++;
				}
			}
			break;
		default:
			c = pStream->zText[0];
			pStream->zText++;
			if( pStream->zText >= pStream->zEnd ){
				break;
			}else{
				sxi32 d;
				/* Handle the longest operator prefix */
				d = pStream->zText[0];
				switch(c){
				case '<':
					if ( d == '<' || d == '=' ){
						/* Advance the cursor */
						pStream->zText++;
					}
					break;
				case '>':
					if( d == '>' || d == '=' ){
						/* Advance the cursor */
						pStream->zText++;
					}
					break;
				case '=':
					if ( d == '=' ){
						/* Advance the cursor */
						pStream->zText++;
						if( pStream->zText < pStream->zEnd && pStream->zText[0] == '=' ){
							pStream->zText++;
						}
					}
					break;
				case '!':
					if ( d == '=' ){
						/* Advance the cursor */
						pStream->zText++;
						if( pStream->zText < pStream->zEnd && pStream->zText[0] == '=' ){
							pStream->zText++;
						}
					}
					break;
				case '|':
					if( d == '|' ){
						/* Advance the cursor */
						pStream->zText++;
					}
					break;
				case '&':
					if( d == '&' ){
						/* Advance the cursor */
						pStream->zText++;
					}
					break;
				default:
					break;
				}
			}
		 }
	  }
	  /* Record token length */
	  sToken.nByte = (sxu32)((const char *)pStream->zText - sToken.zString);
	  if( sToken.nByte <= sizeof(char) * 3 ){
		  if( sToken.nByte == sizeof(char) && sToken.zString[0] == '\\' ){
			  /* Ignore trailing backslashes used for line escaping */
			  return SXERR_IGNORE;
		  }
		  /* Try to extract an operator */
		  pOp = ExprExtractOperator(&sToken,&(*pLast));
		  if( pOp == 0 && (unsigned char)sToken.zString[0] < 0xc0 && !SyisAlphaNum(sToken.zString[0]) ){
			  /* Unknown operator */
			  return SXERR_SYNTAX;
		  }
	  }else{
		  /* Handle TRUE and FALSE tokens */
		  if( sToken.nByte == sizeof("true") - 1 && SyStrnicmp(sToken.zString,"true",sizeof("true")-1) == 0 ){
			  SyStringInitFromBuf(&sToken,"1",sizeof(char));
			  isNumber = 1;
		  }else if( sToken.nByte == sizeof("false") - 1 && SyStrnicmp(sToken.zString,"false",sizeof("false")-1) == 0 ){
			  SyStringInitFromBuf(&sToken,"0",sizeof(char));
			  isNumber = 1;
		  }
	  }
NewNode:
	  /* Create a new expression node */
	  pExpr = (SyExpr *)SyMemBackendPoolAlloc(&pEngine->sAllocator,sizeof(SyExpr));
	  if( pExpr == 0 ){
		  return SXERR_MEM;
	  }
	  /* Zero the structure */
	  SyZero(pExpr,sizeof(SyExpr));
	  /* Associate the node with the extracted lexeme */
	  pExpr->pOp = pOp;
	  SyStringDupPtr(&pExpr->sValue,&sToken);
	  pExpr->isNumber = isNumber;
	  /* Write a pointer to this node */
	  *ppOut = pExpr;
	  return SXRET_OK;
 }
 /*
  * Release an expression tree.
  */
 static void ExprFreeTree(SyMemBackend *pAllocator,SyExpr *pTree)
 {
	 if( pTree->pLeft ){
		 ExprFreeTree(&(*pAllocator),pTree->pLeft);
	 }
	 if( pTree->pRight ){
		 ExprFreeTree(&(*pAllocator),pTree->pRight);
	 }
	 SyMemBackendPoolFree(&(*pAllocator),pTree);
 }
 #define NODE_ISTERM(NODE) (apToken[NODE] && (!apToken[NODE]->pOp || apToken[NODE]->pLeft))
 /*
  * Create an expression tree from an array of tokens.
  * If successful, the root of the tree is stored in apToken[0].
  */
 static sxi32 ExprMakeTree(SyMemBackend *pAllocator,SyExpr **apToken,sxi32 nToken)
 {
	 sxi32 i,iLeft,iRight;
	 SyExpr *pTok;
	 sxi32 iCur;
	 /* Process expressions enclosed in parenthesis first */
	 for( iCur =  0 ; iCur < nToken ; ++iCur ){
		 sxi32 iNest;
		 if( apToken[iCur] == 0 || apToken[iCur]->pOp == 0 || apToken[iCur]->pOp->iOp != OP_OPEN_PAREN ){
			 continue;
		 }
		 iNest = 1;
		 iLeft = iCur;
		 /* Find the closing parenthesis */
		 iCur++;
		 while( iCur < nToken ){
			 if( apToken[iCur]->pOp ){
				 if( apToken[iCur]->pOp->iOp == OP_CLOSE_PAREN ){
					 /* Decrement nesting level */
					 iNest--;
					 if( iNest <= 0 ){
						 break;
					 }
				 }else if( apToken[iCur]->pOp->iOp == OP_OPEN_PAREN ){
					 /* Increment nesting level */
					 iNest++;
				 }
			 }
			 iCur++;
		 }
		 if( iCur >= nToken ){
			 return SXERR_SYNTAX; /* Syntax error: Missing right parenthesis ')' */
		 }
		 if( iCur - iLeft > 1 ){
			 sxi32 rc;
			 /* Recurse and process this expression */
			 rc = ExprMakeTree(&(*pAllocator),&apToken[iLeft + 1],iCur - iLeft - 1);
			 if( rc != SXRET_OK ){
				 return rc;
			 }
		 }
		 /* Free the left and right nodes */
		 ExprFreeTree(&(*pAllocator),apToken[iLeft]);
		 ExprFreeTree(&(*pAllocator),apToken[iCur]);
		 apToken[iLeft] = 0;
		 apToken[iCur] = 0;
	 }
	 /* Handle right associative unary operators that have the highest precedence */
	 iLeft = 0;
	 for( iCur = nToken -  1 ; iCur >= 0 ; iCur-- ){
		 if( apToken[iCur] ){
			 pTok = apToken[iCur];
			 if( pTok->pOp && pTok->pOp->iPrec == 1 /* Unary operators have precedence 1 */ && iLeft > 0){
				 pTok->pLeft = apToken[iLeft];
				 apToken[iLeft] = 0;
			 }
			 /* Save terminal position */
			 iLeft = iCur;
		 }
	 }
	 /*
	  * Process binary operators: Binary operators priority range from 2 to 12
	  */
	 for( i = 2 ; i < 13 ; i++ ){
		 iLeft = -1;
		 for( iCur = 0 ; iCur < nToken ; ++iCur ){
			 if( apToken[iCur] == 0 ){
				 continue;
			 }
			 pTok = apToken[iCur];
			 if( pTok->pOp && pTok->pLeft == 0 && pTok->pOp->iPrec == i ){
				 /* Get the right node */
				 iRight = iCur + 1;
				 while( iRight < nToken && apToken[iRight] == 0 ){
					 iRight++;
				 }
				 if( iRight >= nToken || iLeft < 0 || !NODE_ISTERM(iRight) || !NODE_ISTERM(iLeft) ){
					 return SXERR_SYNTAX; /* Syntax error */
				 }
				 /* Perform the link */
				 pTok->pLeft = apToken[iLeft];
				 pTok->pRight = apToken[iRight];
				 apToken[iLeft] = apToken[iRight] = 0;
			 }
			 iLeft = iCur;
		 }
	 }
	 /* Point to the root of the expression tree */
	 for( iCur = 1 ; iCur < nToken ; ++iCur ){
		 if( apToken[iCur] ){
			 apToken[0] = apToken[iCur];
			 apToken[iCur] = 0;
		 }
	 }
	 return SXRET_OK;
 }
 /*
  * Evaluate a terminal node.
  * This function never fail and always return SXRET_OK.
  */
 static sxi32 ExprEvalTerminal(xpp *pEngine,ProcConsumer xConsumer,void *pConsumerData,SyExpr *pExpr)
 {
	 SyString *pVal = &pExpr->sValue;
	 if( pExpr->isNumber ){
		 /* Pass value to the consumer routine without any processing */
		 xConsumer((const void *)pVal->zString,pVal->nByte,pConsumerData);
	 }else{
		 /* Process literal text */
		 SySet aToken;
		 SyLex sLex;
		 /* Initialize the token set */
		 SySetInit(&aToken,&pEngine->sAllocator,sizeof(SyToken));
		 /* Initialize the tokenizer */
		 SyLexInit(&sLex,&aToken,PreprocessorTokenizeInput,&(*pEngine));
		 /* Tokenize input */
		 SyLexTokenizeInput(&sLex,pVal->zString,pVal->nByte,0,0,0);
		 /* Release the lexer */
		 SyLexRelease(&sLex);
		 /* Process collected tokens */
		 PreprocessorExpandInput(&(*pEngine),(SyToken *)SySetBasePtr(&aToken),SySetUsed(&aToken),
			 xConsumer,pConsumerData,pEngine->iFlags&~XPP_UNESCAPE_STRING);
		 /* Release token set */
		 SySetRelease(&aToken);
	 }
	 return SXRET_OK;
 }
 /* Forward declaration */
 static sxi32 SyLexStreamInit(SyStream *pStream,SySet *pSet,const char *zInput,sxu32 nLen);
 static sxi32 SyBlobTruncate(SyBlob *pBlob,sxsize nNewLen);
 static sxi32 SyHexStrToInt32(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest);
 static sxi32 SyOctalStrToInt32(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest);
 /*
  * Convert a literal value to an integer.
  */
 static sxi32 ExprValueToInt(SyString *pValue)
 {
	 sxi32 iVal = 0;
	 if( pValue->zString[0] != '0' ){
		 SyStrToInt32(pValue->zString,pValue->nByte,(void *)&iVal,0);
	 }else{
		 if( pValue->nByte == sizeof(char) ){
			 return 0;
		 }else if( pValue->zString[1] == 'x' || pValue->zString[1] == 'X' ){
			 /* Hex digit stream */
			 SyHexStrToInt32(pValue->zString,pValue->nByte,(void *)&iVal,0);
		 }else{
			 /* Octal digit stream */
			 SyOctalStrToInt32(pValue->zString,pValue->nByte,(void *)&iVal,0);
		 }
	 }
	 return iVal;
 }
 /*
  * Evaluate an expression tree.
  * Return SXRET_OK on success.Any other value indicates failure.
  */
 static sxi32 ExprEval(xpp *pEngine,ProcConsumer xConsumer,void *pConsumerData,SyExpr *pExpr)
 {
	 SyString sLeft,sRight;  /* Processed node values */
	 sxu32 nOfft,lOfft;      /* Left and right offsets */
	 SyBlob *pWorker;        /* Working buffer */
	 sxi32 iResult;
	 
	 if( pExpr->pOp == 0 ){
		 /* Process literal text [i.e: defined(X) ] */
		 ExprEvalTerminal(&(*pEngine),xConsumer,pConsumerData,&(*pExpr));
		 return SXRET_OK;
	 }
	 pWorker = (SyBlob *)pConsumerData;
	 iResult = 0; /* Prevent compiler warning */
	 lOfft = SyBlobLength(pWorker);
	 if( pExpr->pLeft ){
		 /* Evaluate the left tree */
		 ExprEval(&(*pEngine),xConsumer,pConsumerData,pExpr->pLeft);
	 }
	 nOfft = SyBlobLength(pWorker);
	 if( pExpr->pRight ){
		 /* Evaluate the right tree */
		 ExprEval(&(*pEngine),xConsumer,pConsumerData,pExpr->pRight);
	 }
	 /* Extract node values */
	 SyStringInitFromBuf(&sLeft,SyBlobDataAt(pWorker,lOfft),nOfft - lOfft);
	 SyStringInitFromBuf(&sRight,SyBlobDataAt(pWorker,nOfft),SyBlobLength(pWorker) - nOfft);
	 if( pExpr->pOp->nArgType == EXPR_ARG_STRING ){
		 /* Trim leading and trailing white spaces */
		 SyStringFullTrim(&sLeft);
		 SyStringFullTrim(&sRight);
		 /* Simply a memcmp() operation */
		 if( sLeft.nByte > 0 && sRight.nByte > 0 ){
			 iResult = SyStringCmp(&sLeft,&sRight,SyMemcmp);
			 iResult = iResult == 0 ? 1 : 0;
		 }
		 if( pExpr->pOp->iOp == OP_SNE ){
			 iResult = !iResult;
		 }
	 }else{
		 sxi32 iLeft = 0;
		 sxi32 iRight = 0;
		 if( sLeft.nByte > 0 ){
			 iLeft = ExprValueToInt(&sLeft);
		 }
		 if( sRight.nByte > 0 ){
			 iRight = ExprValueToInt(&sRight);
		 }
		 /* Preform the requested operation */
		 switch(pExpr->pOp->iOp){
		 case OP_MUL: iResult = iLeft * iRight; break;
		 case OP_DIV: iResult = iLeft / iRight; break;
		 case OP_MOD: iResult = iLeft % iRight; break;
		 case OP_ADD: iResult = iLeft + iRight; break;
		 case OP_SUB: iResult = iLeft - iRight; break;
		 case OP_LSHIFT: iResult = iLeft << iRight; break;
		 case OP_RSHIFT: iResult = iLeft >> iRight; break;
		 case OP_LT: iResult = iLeft < iRight;  break;
		 case OP_LE: iResult = iLeft <= iRight; break;
		 case OP_GT: iResult = iLeft > iRight;  break;
		 case OP_GE: iResult = iLeft >= iRight; break;
		 case OP_EQ: iResult = iLeft == iRight; break;
		 case OP_NEQ: iResult = iLeft != iRight; break;
		 case OP_BIT_AND: iResult = iLeft & iRight; break;
		 case OP_BIT_OR:  iResult = iLeft | iRight; break;
		 case OP_BIT_XOR: iResult = iLeft ^ iRight; break;
		 case OP_LOGICAL_AND: iResult = iLeft && iRight; break;
		 case OP_LOGICAL_OR: iResult = iLeft || iRight; break; 
		 case OP_UNARY_MINUS: iResult = -iLeft; break;
		 case OP_UNARY_PLUS:  iResult = +iLeft; break;
		 case OP_LOGICAL_NOT: iResult = !iLeft; break;
		 case OP_BIT_NOT:     iResult = ~iLeft; break;
		 default:
			 /* CAN'T HAPPEN */
			 break;
		 }
	 }
	  /* Truncate the working buffer */
	 SyBlobTruncate(pWorker,lOfft);
	 /* Set evaluation result */
	 if( iResult == 0 ){
		 xConsumer((const void *)"0",sizeof(char),pConsumerData);
	 }else if (iResult == 1 ){
		 xConsumer((const void *)"1",sizeof(char),pConsumerData);
	 }else{
		 SyBlobFormat(pWorker,"%d",iResult);
	 }
	 return SXRET_OK;
 }
 /*
  * Evaluate an expression.
  * Return SXRET_OK on success.Any other value indicates failure.
  */
 static sxi32 PreprocessorEvalExpr(xpp *pEngine,const SyString *pExprText,sxi32 *pResult)
 {
	 SyExpr *pExpr = 0;  /* Last recognized node */
	 SyString sResult;   /* Evaluation result */
	 SyStream sStream;   /* Input stream */
	 SyExpr **apTree;    /* Expression tree: apTree[0] is the root of the tree */
	 SyBlob sWorker;     /* Hold intermediate result here */
	 SySet aNodes;       /* Store pointers to expression nodes here */
	 sxi32 rc;
	 sxu32 i;

	 if( pExprText->nByte <= 0 ){
		 /* Nothing to process */
		 *pResult = 0;
		 return SXRET_OK;
	 }
	 /* Initialize internal components */
	 SyBlobInit(&sWorker,&pEngine->sAllocator);
	 SySetInit(&aNodes,&pEngine->sAllocator,sizeof(SyExpr *));
#ifndef __WINNT__
	 sStream.zText = sStream.zInput = sStream.zEnd = 0; /* Prevent cc -O6 warning */
#endif
	 SyLexStreamInit(&sStream,&aNodes,pExprText->zString,pExprText->nByte);
	 /* Tokenize input first */
	 while( sStream.zText < sStream.zEnd ){
		 rc = ExprExtractToken(&sStream,pEngine,pExpr,&pExpr);
		 if( rc != SXRET_OK ){
			 if( rc == SXERR_IGNORE ){
				 continue;
			 }
			 if( rc != SXERR_EOF ){
				 /* Syntax error or out-of-memory*/
				 *pResult = 0;
				 apTree = (SyExpr **)SySetBasePtr(&aNodes);
				 goto Release;
			 }
			 break;
		 }
		 /* Save the node for later processing */
		 SySetPut(&aNodes,(const void *)&pExpr);
	 }
	 /* Sanity check */
	 if( SySetUsed(&aNodes) <= 0 ){
		 /* Nothing to process [i.e: white space stream] */
		 *pResult = 0;
		 return SXRET_OK;
	 }
	/* Create an expression tree from the parsed list of tokens.If successful, apTree[0] is set
	 * to point to the root of the expression tree.
	 */
	 apTree = (SyExpr **)SySetBasePtr(&aNodes);
	 rc = ExprMakeTree(&pEngine->sAllocator,apTree,SySetUsed(&aNodes));
	 if( rc != SXRET_OK ){
		 *pResult = 0;
	 }else{
		 /* Evaluate the tree rooted at apTree[0] */
		 if( apTree[0] ){
			 rc = ExprEval(&(*pEngine),MacroBlobConsumer,&sWorker,apTree[0]);
		 }
		 /* Extract evaluation result */
		 SyStringInitFromBuf(&sResult,SyBlobData(&sWorker),SyBlobLength(&sWorker));
		 if( sResult.nByte > 0 ){
			 *pResult = ExprValueToInt(&sResult);
		 }else{
			 *pResult = 0;
		 }
	 }
Release:
	 /* Release expression nodes */
	 for( i = 0; i < SySetUsed(&aNodes) ; ++i ){
		 if( apTree[i] ){
			 ExprFreeTree(&pEngine->sAllocator,apTree[i]);
		 }
	 }
	 SyBlobRelease(&sWorker);
	 SySetRelease(&aNodes);
	 return rc;
 }
 /*
 * Symisc Run-Time API: A modern thread safe replacement of the standard libc
 * Copyright (C) Symisc Systems 2007-2011, http://www.symisc.net/
 *
 * The Symisc Run-Time API is an independent project developed by symisc systems
 * internally as a secure replacement of the standard libc.
 * The library is re-entrant,thread-safe and platform independent.
 */
 /* SyRunTimeApi: sxstr.c */
static sxsize SyStrlen(const char *zSrc)
{
	register const char *zIn = zSrc;
#if defined(UNTRUST)
	if( zIn == 0 ){
		return 0;
	}
#endif
	for(;;){
		if( !zIn[0] ){ break; } zIn++;
		if( !zIn[0] ){ break; } zIn++;
		if( !zIn[0] ){ break; } zIn++;
		if( !zIn[0] ){ break; } zIn++;	
	}
	return (sxsize)(zIn - zSrc);
}
static sxi32 SyStringGetNextToken(SyString *pCursor,SyString *pCurrent)
{
	const char *zIn,*zEnd;
	/* Jump leading white space */
	SyStringLeftTrim(pCursor);
	if( pCursor->nByte == 0 ){
		pCurrent->zString = 0;
		pCurrent->nByte = 0;
		return SXERR_EOF; /* End of the input */
	}
	zIn  = pCursor->zString;
	zEnd = &pCursor->zString[pCursor->nByte];
	/* Delimit the token */
	while( zIn < zEnd && zIn[0] != ' ' && zIn[0] != '\t' && zIn[0] != '\r' && zIn[0] != '\v' ){
		zIn++;
	}
	if( zIn == pCursor->zString ){
		pCurrent->zString = 0;
		pCurrent->nByte = 0;
  		return SXERR_NOTFOUND;
  	}
	SyStringInitFromBuf(pCurrent,pCursor->zString,zIn-pCursor->zString);
	SyStringRightTrim(pCurrent);
	/* Advance the cursor,so we can call this routine again */
	SyStringInitFromBuf(pCursor,zIn,zEnd-zIn);
	return SXRET_OK;
}
static sxi32 SyStrnicmp(const char *zLeft, const char *zRight,sxsize SLen)
{
  	register unsigned char *p = (unsigned char *)zLeft;
	register unsigned char *q = (unsigned char *)zRight;
	
	if( SX_EMPTY_STR(p) || SX_EMPTY_STR(q) ){
			return SX_EMPTY_STR(p)? SX_EMPTY_STR(q) ? 0 : -1 :1;
	}
	if( SLen <= 0 ){
		return 0;
	}
	for(;;){
		if( !SLen ){ return 0; }if( !*p || !*q || SyCharToLower(*p) != SyCharToLower(*q) ){ break; }p++;q++;--SLen;
		if( !SLen ){ return 0; }if( !*p || !*q || SyCharToLower(*p) != SyCharToLower(*q) ){ break; }p++;q++;--SLen;
		if( !SLen ){ return 0; }if( !*p || !*q || SyCharToLower(*p) != SyCharToLower(*q) ){ break; }p++;q++;--SLen;
		if( !SLen ){ return 0; }if( !*p || !*q || SyCharToLower(*p) != SyCharToLower(*q) ){ break; }p++;q++;--SLen;
		
	}
	return (sxi32)(SyCharToLower(p[0]) - SyCharToLower(q[0]));
}
static sxsize Systrcpy(char *zDest,sxsize nDestLen,const char *zSrc,sxsize nLen)
{
	unsigned char *zBuf = (unsigned char *)zDest;
	unsigned char *zIn = (unsigned char *)zSrc;
	unsigned char *zEnd;
#if defined(UNTRUST)
	if( zDest == 0 || nDestLen <= 0 || SX_EMPTY_STR(zSrc) ||
		zSrc == (const char *)zDest ){
			return 0;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}
	zEnd = &zBuf[nDestLen - 1]; /* reserve a room for the null terminator */
	for(;;){
		if( zBuf >= zEnd || nLen == 0 ){ break;} zBuf[0] = zIn[0]; zIn++; zBuf++; nLen--;
		if( zBuf >= zEnd || nLen == 0 ){ break;} zBuf[0] = zIn[0]; zIn++; zBuf++; nLen--;
		if( zBuf >= zEnd || nLen == 0 ){ break;} zBuf[0] = zIn[0]; zIn++; zBuf++; nLen--;
		if( zBuf >= zEnd || nLen == 0 ){ break;} zBuf[0] = zIn[0]; zIn++; zBuf++; nLen--;
	}
	zBuf[0] = 0;
	return (sxsize)(zBuf-(unsigned char *)zDest);
}
static sxi32 SyByteFind(const char *zStr,sxsize nLen,sxi32 c,sxu32 *pPos)
 {
	const char *zIn = zStr;
	const char *zEnd;
	if( nLen <= 0 ){
		nLen = SyStrlen(zStr);
	}
	zEnd = &zIn[nLen];
	for(;;){
		if( zIn >= zEnd ){ break; }if( zIn[0] == c ){ if( pPos ){ *pPos = (sxu32)(zIn - zStr); } return SXRET_OK; } zIn++;
		if( zIn >= zEnd ){ break; }if( zIn[0] == c ){ if( pPos ){ *pPos = (sxu32)(zIn - zStr); } return SXRET_OK; } zIn++;
		if( zIn >= zEnd ){ break; }if( zIn[0] == c ){ if( pPos ){ *pPos = (sxu32)(zIn - zStr); } return SXRET_OK; } zIn++;
		if( zIn >= zEnd ){ break; }if( zIn[0] == c ){ if( pPos ){ *pPos = (sxu32)(zIn - zStr); } return SXRET_OK; } zIn++;
	}
	return SXERR_NOTFOUND;
}
 /* SyRunTimeApi: sxmem.c */
static void SyZero(void *pSrc,sxsize nSize)
{
	register unsigned char *zSrc = (unsigned char *)pSrc;
	unsigned char *zEnd;
#if defined(UNTRUST)
	if( zSrc == 0 || nSize <= 0 ){
		return ;
	}
#endif
	zEnd = &zSrc[nSize];
	for(;;){
		if( zSrc >= zEnd ){break;} zSrc[0] = 0; zSrc++;
		if( zSrc >= zEnd ){break;} zSrc[0] = 0; zSrc++;
		if( zSrc >= zEnd ){break;} zSrc[0] = 0; zSrc++;
		if( zSrc >= zEnd ){break;} zSrc[0] = 0; zSrc++;
	}
}
static sxi32 SyMemcmp(const void *pB1,const void *pB2,sxsize nSize)
{
	sxi32 rc;
	if( nSize <= 0 ){
		return 0;
	}
	if( pB1 == 0 || pB2 == 0 ){
		return pB1 != 0 ? 1 : (pB2 == 0 ? 0 : -1);
	}
	SX_MACRO_FAST_CMP(pB1,pB2,nSize,rc);
	return rc;
}
static sxsize SyMemcpy(const void *pSrc,void *pDest,sxsize nLen)
{
#if defined(UNTRUST)
	if( pSrc == 0 || pDest == 0 || nLen <= 0 ){
		return 0;
	}
#endif
	if( pSrc == (const void *)pDest ){
		return nLen;
	}
	SX_MACRO_FAST_MEMCPY(pSrc,pDest,nLen);
	return nLen;
}
static sxi32 SyBlobSearch(const void *pBlob,sxu32 nLen,const void *pPattern,sxu32 pLen,sxu32 *pOfft)
{
	const char *zIn = (const char *)pBlob;
	const char *zEnd;
	sxi32 rc;
#if defined(UNTRUST)
	if( zIn == 0 || nLen <= 0 || pPattern == 0 || pLen <= 0 ){
		return SXERR_EMPTY;
	}
#endif	
	if( pLen > nLen ){
		return SXERR_NOTFOUND;
	}
	zEnd = &zIn[nLen-pLen];
	for(;;){
		if( zIn > zEnd ){break;} SX_MACRO_FAST_CMP(zIn,pPattern,pLen,rc); if( rc == 0 ){ if( pOfft ){ *pOfft = (sxu32)(zIn - (const char *)pBlob);} return SXRET_OK; } zIn++;
		if( zIn > zEnd ){break;} SX_MACRO_FAST_CMP(zIn,pPattern,pLen,rc); if( rc == 0 ){ if( pOfft ){ *pOfft = (sxu32)(zIn - (const char *)pBlob);} return SXRET_OK; } zIn++;
		if( zIn > zEnd ){break;} SX_MACRO_FAST_CMP(zIn,pPattern,pLen,rc); if( rc == 0 ){ if( pOfft ){ *pOfft = (sxu32)(zIn - (const char *)pBlob);} return SXRET_OK; } zIn++;
		if( zIn > zEnd ){break;} SX_MACRO_FAST_CMP(zIn,pPattern,pLen,rc); if( rc == 0 ){ if( pOfft ){ *pOfft = (sxu32)(zIn - (const char *)pBlob);} return SXRET_OK; } zIn++;
	}
	return SXERR_NOTFOUND;
}
#if defined(__WINNT__)
#include <Windows.h>
#else
#include <stdlib.h>
#endif
#if defined(XPP_ENABLE_THREADS)
/* SyRunTimeApi: sxmutex.c */
#if defined(__WINNT__)
struct SyMutex
{
	CRITICAL_SECTION sMutex;
	sxu32 nType; /* Mutex type,one of SXMUTEX_TYPE_* */
};
/* Preallocated static mutex */
static SyMutex aStaticMutexes[] = {
		{{0},SXMUTEX_TYPE_STATIC_1},
		{{0},SXMUTEX_TYPE_STATIC_2},
		{{0},SXMUTEX_TYPE_STATIC_3},
		{{0},SXMUTEX_TYPE_STATIC_4},
		{{0},SXMUTEX_TYPE_STATIC_5},
		{{0},SXMUTEX_TYPE_STATIC_6}
};
static BOOL winMutexInit = FALSE;
static LONG winMutexLock = 0;

static sxi32 WinMutexGlobaInit(void)
{
	LONG rc;
	rc = InterlockedCompareExchange(&winMutexLock,1,0);
	if ( rc == 0 ){
		sxu32 n;
		for( n = 0 ; n  < SX_ARRAYSIZE(aStaticMutexes) ; ++n ){
			InitializeCriticalSection(&aStaticMutexes[n].sMutex);
		}
		winMutexInit = TRUE;
	}else{
		/* Someone else is doing this for us */
		while( winMutexInit == FALSE ){
			Sleep(1);
		}
	}
	return SXRET_OK;
}
static void WinMutexGlobalRelease(void)
{
	LONG rc;
	rc = InterlockedCompareExchange(&winMutexLock,0,1);
	if( rc == 1 ){
		/* The first to decrement to zero does the actual global release */
		if( winMutexInit == TRUE ){
			sxu32 n;
			for( n = 0 ; n < SX_ARRAYSIZE(aStaticMutexes) ; ++n ){
				DeleteCriticalSection(&aStaticMutexes[n].sMutex);
			}
			winMutexInit = FALSE;
		}
	}
}
static SyMutex * WinMutexNew(int nType)
{
	SyMutex *pMutex = 0;
	if( nType == SXMUTEX_TYPE_FAST || nType == SXMUTEX_TYPE_RECURSIVE ){
		/* Allocate a new mutex */
		pMutex = (SyMutex *)HeapAlloc(GetProcessHeap(),0,sizeof(SyMutex));
		if( pMutex == 0 ){
			return 0;
		}
		InitializeCriticalSection(&pMutex->sMutex);
	}else{
		/* Use a pre-allocated static mutex */
		if( nType > SXMUTEX_TYPE_STATIC_6 ){
			nType = SXMUTEX_TYPE_STATIC_6;
		}
		pMutex = &aStaticMutexes[nType - 3];
	}
	pMutex->nType = nType;
	return pMutex;
}
static void WinMutexRelease(SyMutex *pMutex)
{
	if( pMutex->nType == SXMUTEX_TYPE_FAST || pMutex->nType == SXMUTEX_TYPE_RECURSIVE ){
		DeleteCriticalSection(&pMutex->sMutex);
		HeapFree(GetProcessHeap(),0,pMutex);
	}
}
static void WinMutexEnter(SyMutex *pMutex)
{
	EnterCriticalSection(&pMutex->sMutex);
}
static sxi32 WinMutexTryEnter(SyMutex *pMutex)
{
#ifdef _WIN32_WINNT
	BOOL rc;
	/* Only WindowsNT platforms */
	rc = TryEnterCriticalSection(&pMutex->sMutex);
	if( rc ){
		return SXRET_OK;
	}else{
		return SXERR_BUSY;
	}
#else
	return SXERR_NOTIMPLEMENTED;
#endif
}
static void WinMutexLeave(SyMutex *pMutex)
{
	LeaveCriticalSection(&pMutex->sMutex);
}
/* Export Windows mutex interfaces */
static const SyMutexMethods sWinMutexMethods = {
	WinMutexGlobaInit,  /* xGlobalInit() */
	WinMutexGlobalRelease, /* xGlobalRelease() */
	WinMutexNew,     /* xNew() */
	WinMutexRelease, /* xRelease() */
	WinMutexEnter,   /* xEnter() */
	WinMutexTryEnter, /* xTryEnter() */
	WinMutexLeave     /* xLeave() */
};
static const SyMutexMethods * SyMutexExportMethods(void)
{
	return &sWinMutexMethods;
}
#elif defined(__UNIXES__)
#include <pthread.h>
struct SyMutex
{
	pthread_mutex_t sMutex;
	sxu32 nType;
};
static SyMutex * UnixMutexNew(int nType)
{
	static SyMutex aStaticMutexes[] = {
		{PTHREAD_MUTEX_INITIALIZER,SXMUTEX_TYPE_STATIC_1},
		{PTHREAD_MUTEX_INITIALIZER,SXMUTEX_TYPE_STATIC_2},
		{PTHREAD_MUTEX_INITIALIZER,SXMUTEX_TYPE_STATIC_3},
		{PTHREAD_MUTEX_INITIALIZER,SXMUTEX_TYPE_STATIC_4},
		{PTHREAD_MUTEX_INITIALIZER,SXMUTEX_TYPE_STATIC_5},
		{PTHREAD_MUTEX_INITIALIZER,SXMUTEX_TYPE_STATIC_6}
	};
	SyMutex *pMutex;
	
	if( nType == SXMUTEX_TYPE_FAST || nType == SXMUTEX_TYPE_RECURSIVE ){
		pthread_mutexattr_t sRecursiveAttr;
  		/* Allocate a new mutex */
  		pMutex = (SyMutex *)malloc(sizeof(SyMutex));
  		if( pMutex == 0 ){
  			return 0;
  		}
  		if( nType == SXMUTEX_TYPE_RECURSIVE ){
  			pthread_mutexattr_init(&sRecursiveAttr);
  			pthread_mutexattr_settype(&sRecursiveAttr,PTHREAD_MUTEX_RECURSIVE);
  		}
  		pthread_mutex_init(&pMutex->sMutex,nType == SXMUTEX_TYPE_RECURSIVE ? &sRecursiveAttr : 0 );
		if(	nType == SXMUTEX_TYPE_RECURSIVE ){
   			pthread_mutexattr_destroy(&sRecursiveAttr);
		}
	}else{
		/* Use a pre-allocated static mutex */
		if( nType > SXMUTEX_TYPE_STATIC_6 ){
			nType = SXMUTEX_TYPE_STATIC_6;
		}
		pMutex = &aStaticMutexes[nType - 3];
	}
  pMutex->nType = nType;
  
  return pMutex;
}
static void UnixMutexRelease(SyMutex *pMutex)
{
	if( pMutex->nType == SXMUTEX_TYPE_FAST || pMutex->nType == SXMUTEX_TYPE_RECURSIVE ){
		pthread_mutex_destroy(&pMutex->sMutex);
		free(pMutex);
	}
}
static void UnixMutexEnter(SyMutex *pMutex)
{
	pthread_mutex_lock(&pMutex->sMutex);
}
static void UnixMutexLeave(SyMutex *pMutex)
{
	pthread_mutex_unlock(&pMutex->sMutex);
}
/* Export pthread mutex interfaces */
static const SyMutexMethods sPthreadMutexMethods = {
	0, /* xGlobalInit() */
	0, /* xGlobalRelease() */
	UnixMutexNew,      /* xNew() */
	UnixMutexRelease,  /* xRelease() */
	UnixMutexEnter,    /* xEnter() */
	0,                 /* xTryEnter() */
	UnixMutexLeave     /* xLeave() */
};
static const SyMutexMethods * SyMutexExportMethods(void)
{
	return &sPthreadMutexMethods;
}
#else
/* Host application must register their own mutex subsystem if the target platform is not 
 * an UNIX like or windows systems.
 */
struct SyMutex
{
	sxu32 nType;
};
static SyMutex * DummyMutexNew(int nType)
{
	static SyMutex sMutex;
	SXUNUSED(nType);
	return &sMutex;
}
static void DummyMutexRelease(SyMutex *pMutex)
{
	SXUNUSED(pMutex);
}
static void DummyMutexEnter(SyMutex *pMutex)
{
	SXUNUSED(pMutex);
}
static void DummyMutexLeave(SyMutex *pMutex)
{
	SXUNUSED(pMutex);
}
/* Export the dummy mutex interfaces */
static const SyMutexMethods sDummyMutexMethods = {
	0, /* xGlobalInit() */
	0, /* xGlobalRelease() */
	DummyMutexNew,      /* xNew() */
	DummyMutexRelease,  /* xRelease() */
	DummyMutexEnter,    /* xEnter() */
	0,                  /* xTryEnter() */
	DummyMutexLeave     /* xLeave() */
};
static const SyMutexMethods * SyMutexExportMethods(void)
{
	return &sDummyMutexMethods;
}
#endif /* __WINNT__ */
#endif /* XPP_ENABLE_THREADS */
static void * SyOSHeapAlloc(sxu32 nByte)
{
	void *pNew;
#if defined(__WINNT__)
	pNew = HeapAlloc(GetProcessHeap(),0,nByte);
#else
	pNew = malloc((size_t)nByte);
#endif
	return pNew;
}
static void * SyOSHeapRealloc(void *pOld,sxu32 nByte)
{
	void *pNew;
#if defined(__WINNT__)
	pNew = HeapReAlloc(GetProcessHeap(),0,pOld,nByte);
#else
	pNew = realloc(pOld,(size_t)nByte);
#endif
	return pNew;	
}
static void SyOSHeapFree(void *pPtr)
{
#if defined(__WINNT__)
	HeapFree(GetProcessHeap(),0,pPtr);
#else
	free(pPtr);
#endif
}
static void * MemOSAlloc(sxu32 nBytes)
{
	sxu32 *pChunk;
	pChunk = (sxu32 *)SyOSHeapAlloc(nBytes + sizeof(sxu32));
	if( pChunk == 0 ){
		return 0;
	}
	pChunk[0] = nBytes;
	return (void *)&pChunk[1];
}
static void * MemOSRealloc(void *pOld,sxu32 nBytes)
{
	sxu32 *pOldChunk;
	sxu32 *pChunk;
	pOldChunk = (sxu32 *)(((char *)pOld)-sizeof(sxu32));
	if( pOldChunk[0] >= nBytes ){
		return pOld;
	}
	pChunk = (sxu32 *)SyOSHeapRealloc(pOldChunk,nBytes + sizeof(sxu32));
	if( pChunk == 0 ){
		return 0;
	}
	pChunk[0] = nBytes;
	return (void *)&pChunk[1];
}
static void MemOSFree(void *pBlock)
{
	void *pChunk;
	pChunk = (void *)(((char *)pBlock)-sizeof(sxu32));
	SyOSHeapFree(pChunk);
}
static sxu32 MemOSChunkSize(void *pBlock)
{
	sxu32 *pChunk;
	pChunk = (sxu32 *)(((char *)pBlock)-sizeof(sxu32));
	return pChunk[0];
}
/* Export OS allocation methods */
static const SyMemMethods sOSAllocMethods = {
	MemOSAlloc,
	MemOSRealloc,
	MemOSFree,
	MemOSChunkSize,
	0,
	0,
	0
};
static void * MemBackendAlloc(SyMemBackend *pBackend,sxu32 nByte)
{
	SyMemBlock *pBlock;
	sxi32 nRetry = 0;

	/* Append an extra block so we can track allocated chunks and avoid memory
	 * leaks.
	 */
	nByte += sizeof(SyMemBlock);
	for(;;){
		pBlock = (SyMemBlock *)pBackend->pMethods->xAlloc(nByte);
		if( pBlock != 0 || pBackend->xMemError == 0 || nRetry > SXMEM_BACKEND_RETRY 
			|| SXERR_RETRY != pBackend->xMemError(pBackend->pUserData) ){
				break;
		}
		nRetry++;
	}
	if( pBlock  == 0 ){
		return 0;
	}
	pBlock->pNext = pBlock->pPrev = 0;
	/* Link to the list of already tracked blocks */
	MACRO_LD_PUSH(pBackend->pBlocks,pBlock);
#if defined(UNTRUST)
	pBlock->nGuard = SXMEM_BACKEND_MAGIC;
#endif
	pBackend->nBlock++;

	return (void *)&pBlock[1];
}
static void * SyMemBackendAlloc(SyMemBackend *pBackend,sxu32 nByte)
{
	void *pChunk;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return 0;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods,pBackend->pMutex);
	}
	pChunk = MemBackendAlloc(&(*pBackend),nByte);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods,pBackend->pMutex);
	}
	return pChunk;
}
static void * MemBackendRealloc(SyMemBackend *pBackend,void * pOld,sxu32 nByte)
{
	SyMemBlock *pBlock,*pNew,*pPrev,*pNext;
	sxu32 nRetry = 0;

	if( pOld == 0 ){
		/* Allocate a new one */
		return MemBackendAlloc(&(*pBackend),nByte);
	}
	pBlock = (SyMemBlock *)(((char *)pOld) - sizeof(SyMemBlock));
#if defined(UNTRUST)
	if( pBlock->nGuard != SXMEM_BACKEND_MAGIC ){
		return 0;
	}
#endif
	nByte += sizeof(SyMemBlock);
	pPrev = pBlock->pPrev;
	pNext = pBlock->pNext;
	for(;;){
		pNew = (SyMemBlock *)pBackend->pMethods->xRealloc(pBlock,nByte);
		if( pNew != 0 || pBackend->xMemError == 0 || nRetry > SXMEM_BACKEND_RETRY ||
			SXERR_RETRY != pBackend->xMemError(pBackend->pUserData) ){
				break;
		}
		nRetry++;
	}
	if( pNew == 0 ){
		return 0;
	}
	if( pNew != pBlock ){
		if( pPrev == 0 ){
			pBackend->pBlocks = pNew;
		}else{
			pPrev->pNext = pNew;
		}
		if( pNext ){
			pNext->pPrev = pNew;
		}
#if defined(UNTRUST)
		pNew->nGuard = SXMEM_BACKEND_MAGIC;
#endif
	}
	return (void *)&pNew[1];
}
static void * SyMemBackendRealloc(SyMemBackend *pBackend,void * pOld,sxu32 nByte)
{
	void *pChunk;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend)  ){
		return 0;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods,pBackend->pMutex);
	}
	pChunk = MemBackendRealloc(&(*pBackend),pOld,nByte);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods,pBackend->pMutex);
	}
	return pChunk;
}
static sxi32 MemBackendFree(SyMemBackend *pBackend,void * pChunk)
{
	SyMemBlock *pBlock;

	pBlock = (SyMemBlock *)(((char *)pChunk) - sizeof(SyMemBlock));
#if defined(UNTRUST)
	if( pBlock->nGuard != SXMEM_BACKEND_MAGIC ){
		return SXERR_CORRUPT;
	}
#endif
	/* Unlink from the list of active blocks */
	if( pBackend->nBlock > 0 ){
		/* Release the block */
#if defined(UNTRUST)
	pBlock->nGuard = 0x635B;
#endif
		MACRO_LD_REMOVE(pBackend->pBlocks,pBlock);
		pBackend->nBlock--;
		pBackend->pMethods->xFree(pBlock);
	}
	return SXRET_OK;
}
static sxi32 SyMemBackendFree(SyMemBackend *pBackend,void * pChunk)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) || pChunk == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods,pBackend->pMutex);
	}
	rc = MemBackendFree(&(*pBackend),pChunk);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods,pBackend->pMutex);
	}
	return rc;
}
/*
 * Memory pool allocator.
 */
#ifndef SXMEM_POOL_MAGIC
#define SXMEM_POOL_MAGIC		0xDEAD
#define SXMEM_POOL_MAXALLOC		(1<<(SXMEM_POOL_NBUCKETS+SXMEM_POOL_INCR)) 
#define SXMEM_POOL_MINALLOC		(1<<(SXMEM_POOL_INCR))
#endif
static sxi32 MemPoolBucketAlloc(SyMemBackend *pBackend,sxu32 nBucket)
{
	char *zBucket,*zBucketEnd;
	SyMemHeader *pHeader;
	sxu32 nBucketSize;
	
	/* Allocate one big block first */
	zBucket = (char *)MemBackendAlloc(&(*pBackend),SXMEM_POOL_MAXALLOC);
	if( zBucket == 0 ){
		return SXERR_MEM;
	}
	zBucketEnd = &zBucket[SXMEM_POOL_MAXALLOC];
	/* Divide the big block into mini bucket pool */
	nBucketSize = 1 << (nBucket + SXMEM_POOL_INCR);
	pBackend->apPool[nBucket] = pHeader = (SyMemHeader *)zBucket;
	for(;;){
		if( &zBucket[nBucketSize] >= zBucketEnd ){
			break;
		}
		pHeader->pNext = (SyMemHeader *)&zBucket[nBucketSize];
		/* Advance the cursors to the next available chunk */
		pHeader = pHeader->pNext;
		zBucket += nBucketSize;	
	}
	pHeader->pNext = 0;
	
	return SXRET_OK;
}
static void * MemBackendPoolAlloc(SyMemBackend *pBackend,sxu32 nByte)
{
	SyMemHeader *pBucket,*pNext;
	sxu32 nBucketSize;
	sxu32 nBucket;
	if( nByte + sizeof(SyMemHeader) >= SXMEM_POOL_MAXALLOC ){
		/* Allocate a big chunk directly */
		pBucket = (SyMemHeader *)MemBackendAlloc(&(*pBackend),nByte+sizeof(SyMemHeader));
		if( pBucket == 0 ){
			return 0;
		}
		/* Record as big block */
		pBucket->nBucket = (sxu32)(SXMEM_POOL_MAGIC << 16) | SXU16_HIGH;
		return (void *)(pBucket+1);
	}
	/* Locate the appropriate bucket */
	nBucket = 0;
	nBucketSize = SXMEM_POOL_MINALLOC;
	while( nByte + sizeof(SyMemHeader) > nBucketSize  ){
		nBucketSize <<= 1;
		nBucket++;
	}
	pBucket = pBackend->apPool[nBucket];
	if( pBucket == 0 ){
		sxi32 rc;
		rc = MemPoolBucketAlloc(&(*pBackend),nBucket);
		if( rc != SXRET_OK ){
			return 0;
		}
		pBucket = pBackend->apPool[nBucket];
	}
	/* Remove from the free list */
	pNext = pBucket->pNext;
	pBackend->apPool[nBucket] = pNext;
	/* Record bucket&magic number */
	pBucket->nBucket = (SXMEM_POOL_MAGIC << 16) | nBucket;
	return (void *)&pBucket[1];
}
static void * SyMemBackendPoolAlloc(SyMemBackend *pBackend,sxu32 nByte)
{
	void *pChunk;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return 0;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods,pBackend->pMutex);
	}
	pChunk = MemBackendPoolAlloc(&(*pBackend),nByte);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods,pBackend->pMutex);
	}
	return pChunk;
}
static sxi32 MemBackendPoolFree(SyMemBackend *pBackend,void * pChunk)
{
	SyMemHeader *pHeader;
	sxu32 nBucket;

	/* Get the corresponding bucket */
	pHeader = (SyMemHeader *)(((char *)pChunk) - sizeof(SyMemHeader));
	/* Sanity check to avoid misuse */
	if( (pHeader->nBucket >> 16) != SXMEM_POOL_MAGIC ){
		return SXERR_CORRUPT;
	}
	nBucket = pHeader->nBucket & 0xFFFF;
	if( nBucket == SXU16_HIGH ){
		/* Free the big block */
		MemBackendFree(&(*pBackend),pHeader);
	}else{
		/* Return to the free list */
		pHeader->pNext = pBackend->apPool[nBucket & 0x0f];
		pBackend->apPool[nBucket & 0x0f] = pHeader;
	}
	return SXRET_OK;
}
static sxi32 SyMemBackendPoolFree(SyMemBackend *pBackend,void * pChunk)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) || pChunk == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods,pBackend->pMutex);
	}
	rc = MemBackendPoolFree(&(*pBackend),pChunk);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods,pBackend->pMutex);
	}
	return rc;
}
#if defined(UNTRUST) || defined(XPP_ENABLE_THREADS)
static sxu8 SyMemBackendPoolValidChunk(SyMemBackend *pBackend,void * pChunk)
{
	SyMemHeader *pHeader;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return FALSE;
	}
#endif
	if( pChunk == 0 ){
		return FALSE;
	}
	SXUNUSED(pBackend);
	/* Get the corresponding bucket */
	pHeader = (SyMemHeader *)(((char *)pChunk) - sizeof(SyMemHeader));
	/* Sanity check to avoid misuse */
	if( (pHeader->nBucket >> 16) != SXMEM_POOL_MAGIC ){
		return FALSE;
	}
	return TRUE;
}
#endif
static sxi32 SyMemBackendInit(SyMemBackend *pBackend,ProcMemError xMemErr,void * pUserData)
{
#if defined(UNTRUST)
	if( pBackend == 0 ){
		return SXERR_EMPTY;
	}
#endif
	/* Zero the allocator first */
	SyZero(&(*pBackend),sizeof(SyMemBackend));
	pBackend->xMemError = xMemErr;
	pBackend->pUserData = pUserData;
	/* Switch to the OS memory allocator */
	pBackend->pMethods = &sOSAllocMethods;
	if( pBackend->pMethods->xInit ){
		/* Initialize the backend  */
		if( SXRET_OK != pBackend->pMethods->xInit(pBackend->pMethods->pUserData) ){
			return SXERR_ABORT;
		}
	}
#if defined(UNTRUST)
	pBackend->nMagic = SXMEM_BACKEND_MAGIC;
#endif
	return SXRET_OK;
}
static sxi32 SyMemBackendInitFromOthers(SyMemBackend *pBackend,const SyMemMethods *pMethods,ProcMemError xMemErr,void * pUserData)
{
#if defined(UNTRUST)
	if( pBackend == 0 || pMethods == 0){
		return SXERR_EMPTY;
	}
#endif
	if( pMethods->xAlloc == 0 || pMethods->xRealloc == 0 || pMethods->xFree == 0 || pMethods->xChunkSize == 0 ){
		/* mandatory methods are missing */
		return SXERR_INVALID;
	}
	/* Zero the allocator first */
	SyZero(&(*pBackend),sizeof(SyMemBackend));
	pBackend->xMemError = xMemErr;
	pBackend->pUserData = pUserData;
	/* Switch to the host application memory allocator */
	pBackend->pMethods = pMethods;
	if( pBackend->pMethods->xInit ){
		/* Initialize the backend  */
		if( SXRET_OK != pBackend->pMethods->xInit(pBackend->pMethods->pUserData) ){
			return SXERR_ABORT;
		}
	}
#if defined(UNTRUST)
	pBackend->nMagic = SXMEM_BACKEND_MAGIC;
#endif
	return SXRET_OK;
}
static sxi32 SyMemBackendInitFromParent(SyMemBackend *pBackend,SyMemBackend *pParent)
{
	sxu8 bInheritMutex;
#if defined(UNTRUST)
	if( pBackend == 0 || SXMEM_BACKEND_CORRUPT(pParent) ){
		return SXERR_CORRUPT;
	}
#endif
	/* Zero the allocator first */
	SyZero(&(*pBackend),sizeof(SyMemBackend));
	pBackend->pMethods  = pParent->pMethods;
	pBackend->xMemError = pParent->xMemError;
	pBackend->pUserData = pParent->pUserData;
	bInheritMutex = pParent->pMutexMethods ? TRUE : FALSE;
	if( bInheritMutex ){
		pBackend->pMutexMethods = pParent->pMutexMethods;
		/* Create a private mutex */
		pBackend->pMutex = pBackend->pMutexMethods->xNew(SXMUTEX_TYPE_FAST);
		if( pBackend->pMutex ==  0){
			return SXERR_OS;
		}
	}
#if defined(UNTRUST)
	pBackend->nMagic = SXMEM_BACKEND_MAGIC;
#endif
	return SXRET_OK;
}
#if defined(XPP_ENABLE_THREADS)
static sxi32 SyMemBackendMakeThreadSafe(SyMemBackend *pBackend,const SyMutexMethods *pMethods)
{
	SyMutex *pMutex;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) || pMethods == 0 || pMethods->xNew == 0){
		return SXERR_CORRUPT;
	}
#endif
	pMutex = pMethods->xNew(SXMUTEX_TYPE_FAST);
	if( pMutex == 0 ){
		return SXERR_OS;
	}
	/* Attach the mutex to the memory backend */
	pBackend->pMutex = pMutex;
	pBackend->pMutexMethods = pMethods;
	return SXRET_OK;
}
static sxi32 SyMemBackendDisbaleMutexing(SyMemBackend *pBackend)
{
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return SXERR_CORRUPT;
	}
#endif
	if( pBackend->pMutex == 0 ){
		/* There is no mutex subsystem at all */
		return SXRET_OK;
	}
	SyMutexRelease(pBackend->pMutexMethods,pBackend->pMutex);
	pBackend->pMutexMethods = 0;
	pBackend->pMutex = 0; 
	return SXRET_OK;
}
#endif
static sxi32 MemBackendRelease(SyMemBackend *pBackend)
{
	SyMemBlock *pBlock,*pNext;

	pBlock = pBackend->pBlocks;
	for(;;){
		if( pBackend->nBlock == 0 ){
			break;
		}
		pNext  = pBlock->pNext;
		pBackend->pMethods->xFree(pBlock);
		pBlock = pNext;
		pBackend->nBlock--;
	}
	if( pBackend->pMethods->xRelease ){
		pBackend->pMethods->xRelease(pBackend->pMethods->pUserData);
	}
	pBackend->pMethods = 0;
	pBackend->pBlocks  = 0;
#if defined(UNTRUST)
	pBackend->nMagic = 0x2626;
#endif
	return SXRET_OK;
}
static sxi32 SyMemBackendRelease(SyMemBackend *pBackend)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return SXERR_INVALID;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods,pBackend->pMutex);
	}
	rc = MemBackendRelease(&(*pBackend));
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods,pBackend->pMutex);
		SyMutexRelease(pBackend->pMutexMethods,pBackend->pMutex);
	}
	return SXRET_OK;
}
static void * SyMemBackendDup(SyMemBackend *pBackend,const void *pSrc,sxu32 nSize)
{
	void *pNew;
#if defined(UNTRUST)
	if( pSrc == 0 || nSize <= 0 ){
		return 0;
	}
#endif
	pNew = SyMemBackendAlloc(&(*pBackend),nSize);
	if( pNew ){
		SyMemcpy(pSrc,pNew,nSize);
	}
	return pNew;
}
static char * SyMemBackendStrDup(SyMemBackend *pBackend,const char *zSrc,sxu32 nSize)
{
	char *zDest;
	zDest = (char *)SyMemBackendAlloc(&(*pBackend),nSize + 1);
	if( zDest ){
		Systrcpy(zDest,nSize+1,zSrc,nSize);
	}
	return zDest;
}
static sxi32 SyBlobInitFromBuf(SyBlob *pBlob,void *pBuffer,sxsize nSize)
{
#if defined(UNTRUST)
	if( pBlob == 0 || pBuffer == 0 || nSize <= 0 ){
		return SXERR_EMPTY;
	}
#endif
	pBlob->pBlob = pBuffer;
	pBlob->mByte = nSize;
	pBlob->nByte = 0;
	
	pBlob->pAllocator = 0;
	pBlob->nFlags = SXBLOB_LOCKED|SXBLOB_STATIC;
	
	return SXRET_OK;
}
static sxi32 SyBlobInit(SyBlob *pBlob,SyMemBackend *pAllocator)
{
#if defined(UNTRUST)
	if( pBlob == 0  ){
		return SXERR_EMPTY;
	}
#endif
	pBlob->pBlob = 0;
	pBlob->mByte = pBlob->nByte	= 0;
	pBlob->pAllocator = &(*pAllocator);
	pBlob->nFlags = 0;
	
	return SXRET_OK;
}
#ifndef SXBLOB_MIN_GROWTH
#define SXBLOB_MIN_GROWTH 128
#endif
static sxi32 BlobPrepareGrow(SyBlob *pBlob,sxsize *pByte)
{
	sxsize nByte;
	void *pNew;
#if defined(UNTRUST)
	if( pBlob == 0 || pByte == 0){
		return SXERR_EMPTY;
	}
#endif
	nByte = *pByte;
	if( SyBlobFreeSpace(pBlob) >= nByte ){
		return SXRET_OK;
	}
	if( pBlob->nFlags & ( SXBLOB_LOCKED|SXBLOB_STATIC) ){
		if( SyBlobFreeSpace(pBlob) <= 0 ){
			return SXERR_SHORT;
		}else{
			*pByte = SyBlobFreeSpace(pBlob);
			return SXRET_OK;
		}
	}
	if( pBlob->pBlob != 0 ){
		nByte = nByte + pBlob->mByte * 2 + SXBLOB_MIN_GROWTH;
	}else if ( nByte < SXBLOB_MIN_GROWTH ){
		nByte = SXBLOB_MIN_GROWTH;
	}
	pNew = SyMemBackendRealloc(pBlob->pAllocator,pBlob->pBlob,nByte);
	if( pNew == 0 ){
		return SXERR_MEM;
	}
	pBlob->pBlob = pNew;
	pBlob->mByte = nByte;
	return SXRET_OK;
}
static sxi32 SyBlobAppend(SyBlob *pBlob,const void *pData,sxsize nSize)
{
	sxu8 *zBlob;
	sxi32 rc;
#if defined(UNTRUST)
	if( pData == 0 ){
		return SXERR_EMPTY;
	}
#endif
	if(  nSize <= 0 ){
		return SXRET_OK;
	}
	rc = BlobPrepareGrow(&(*pBlob),&nSize);
	if( SXRET_OK != rc ){
		return rc;
	}
	zBlob = (sxu8 *)pBlob->pBlob ;
	zBlob = &zBlob[pBlob->nByte];
	pBlob->nByte += nSize;
	SX_MACRO_FAST_MEMCPY(pData,zBlob,nSize);	
	return SXRET_OK;
}
static sxi32 SyBlobReset(SyBlob *pBlob)
{
#if defined(UNTRUST)
	if( pBlob == 0 ){
		return SXERR_EMPTY;
	}
#endif
	pBlob->nByte = 0;
	return SXRET_OK;
}
static sxi32 SyBlobRelease(SyBlob *pBlob)
{
#if defined(UNTRUST)
	if( pBlob == 0 ){
		return SXERR_EMPTY;
	}
#endif
	if( (pBlob->nFlags & SXBLOB_STATIC) == 0 && pBlob->pBlob ){
		SyMemBackendFree(pBlob->pAllocator,pBlob->pBlob);
		pBlob->pAllocator = 0;
	}
	pBlob->pBlob = 0;
	pBlob->nByte = pBlob->mByte = 0;
	pBlob->nFlags = 0;
	
	return SXRET_OK;
}
static sxi32 SyBlobTruncate(SyBlob *pBlob,sxsize nNewLen)
{
#if defined(UNTRUST)
	if( pBlob == 0 ){
		return SXERR_EMPTY;
	}
#endif
	if( nNewLen < pBlob->nByte ){
		pBlob->nByte = nNewLen;
	}
	return SXRET_OK;
}
static sxsize SyBlobLen(const void *pSrc,const char *zLimit)
{
	const char *zIn = (const char *)pSrc;
	for(;;){
		if( zIn[0] == 0 || (zLimit && zIn >= zLimit) ){ break; } zIn++;
		if( zIn[0] == 0 || (zLimit && zIn >= zLimit) ){ break; } zIn++;
		if( zIn[0] == 0 || (zLimit && zIn >= zLimit) ){ break; } zIn++;
		if( zIn[0] == 0 || (zLimit && zIn >= zLimit) ){ break; } zIn++;
	}
	return (sxsize)(zIn - (const char *)pSrc);
}
/* SyRunTimeApi: sxutils.c */
/* limits */
#define SXINT32_MIN_STR		"2147483648"
#define SXINT32_MAX_STR		"2147483647"
#define SXINT64_MIN_STR		"9223372036854775808"
#define SXINT64_MAX_STR		"9223372036854775807"
static sxi32 SyStrToInt32(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest)
{
	sxu8 isNeg = FALSE;
	const char *zEnd;
	sxi32 nVal = 0;
	sxi16 i;
	
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) ){
		if( pOutVal ){
			*(sxi32 *)pOutVal = 0;
		}
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}
	zEnd = &zSrc[nLen];
	while(zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zSrc < zEnd && ( zSrc[0] == '-' || zSrc[0] == '+' ) ){
		isNeg = (zSrc[0] == '-') ? TRUE :FALSE;
		zSrc++;
	}
	/* Skip leading zero */
	while(zSrc < zEnd && zSrc[0] == '0' ){
		zSrc++; 
	}
	i = 10;
	if( (sxu32)(zEnd-zSrc) >= 10 ){
		/* Handle overflow */
		i = SyMemcmp(zSrc,(isNeg == TRUE) ? SXINT32_MIN_STR : SXINT32_MAX_STR,nLen) <= 0 ? 10 : 9; 
	}
	for(;;){
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
	}
	/* Skip trailing spaces */
	while(zSrc < zEnd && SyisSpace(zSrc[0])){
		zSrc++;
	}
	if( zRest ){
		*zRest = (char *)zSrc;
	}	
	if( pOutVal ){
		if( isNeg == TRUE && nVal != 0){
			nVal = -nVal;
		}
		*(sxi32 *)pOutVal = nVal;
	}
	return (zSrc >= zEnd) ? SXRET_OK : SXERR_SYNTAX;
}
static sxi32 SyStrToInt64(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest)
{
	sxu8 isNeg = FALSE;
	const char *zEnd;
	sxi64 nVal;
	sxi16 i;

#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) ){
		if( pOutVal ){
			*(sxi32 *)pOutVal = 0;
		}
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}
	zEnd = &zSrc[nLen];
	while(zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zSrc < zEnd && ( zSrc[0] == '-' || zSrc[0] == '+' ) ){
		isNeg = (zSrc[0] == '-') ? TRUE :FALSE;
		zSrc++;
	}
	/* Skip leading zero */
	while(zSrc < zEnd && zSrc[0] == '0' ){
		zSrc++;
	}
	i = 19;
	if( (sxu32)(zEnd-zSrc) >= 19 ){
		i = SyMemcmp(zSrc,isNeg ? SXINT64_MIN_STR : SXINT64_MAX_STR,19) <= 0 ? 19 : 18 ;
	}
	nVal = 0;
	for(;;){
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
	}
	/* Skip trailing spaces */
	while(zSrc < zEnd && SyisSpace(zSrc[0])){
		zSrc++;
	}
	if( zRest ){
		*zRest = (char *)zSrc;
	}	
	if( pOutVal ){
		if( isNeg == TRUE && nVal != 0){
			nVal = -nVal;
		}
		*(sxi64 *)pOutVal = nVal;
	}
	return (zSrc >= zEnd) ? SXRET_OK : SXERR_SYNTAX;
}
static sxi32 SyHexStrToInt32(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest)
{
	sxu8 isNeg = FALSE;
	const char *zEnd;
	sxi32 nVal = 0;
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) ){
		if( pOutVal ){
			*(sxi32 *)pOutVal = 0;
		}
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}
	zEnd = &zSrc[nLen];
	while( zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zSrc < zEnd && ( *zSrc == '-' || *zSrc == '+' ) ){
		isNeg = (zSrc[0] == '-') ? TRUE :FALSE;
		zSrc++;
	}
	if( zSrc < &zEnd[-2] && zSrc[0] == '0' && (zSrc[1] == 'x' || zSrc[1] == 'X') ){
		/* Bypass hex prefix */
		zSrc += sizeof(char) * 2;
	}	
	/* Skip leading zero */
	while(zSrc < zEnd && zSrc[0] == '0' ){
		zSrc++;
	}	
	for(;;){
		if(zSrc >= zEnd || !SyisHex(zSrc[0]) ) break; nVal = nVal * 16 + SyHexToint(zSrc[0]);  zSrc++ ;
		if(zSrc >= zEnd || !SyisHex(zSrc[0]) ) break; nVal = nVal * 16 + SyHexToint(zSrc[0]);  zSrc++ ;
		if(zSrc >= zEnd || !SyisHex(zSrc[0]) ) break; nVal = nVal * 16 + SyHexToint(zSrc[0]);  zSrc++ ;
		if(zSrc >= zEnd || !SyisHex(zSrc[0]) ) break; nVal = nVal * 16 + SyHexToint(zSrc[0]);  zSrc++ ;
	}
	while( zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}	
	if( zRest ){
		*zRest = (char *)zSrc;
	}
	if( pOutVal ){
		if( isNeg == TRUE && nVal != 0 ){
			nVal = -nVal;
		}
		*(sxi32 *)pOutVal = nVal;
	}
	return zSrc >= zEnd ? SXRET_OK : SXERR_SYNTAX;
}
static sxi32 SyOctalStrToInt32(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest)
{
	sxu8 isNeg = FALSE;
	const char *zEnd;
	sxi32 nVal = 0;
	int c;
	
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) ){
		if( pOutVal ){
			*(sxi32 *)pOutVal = 0;
		}
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}
	zEnd = &zSrc[nLen];
	while(zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zSrc < zEnd && ( zSrc[0] == '-' || zSrc[0] == '+' ) ){
		isNeg = (zSrc[0] == '-') ? TRUE :FALSE;
		zSrc++;
	}
	/* Skip leading zero */
	while(zSrc < zEnd && zSrc[0] == '0' ){
		zSrc++; 
	}
	for(;;){
		if(zSrc >= zEnd || !SyisDigit(zSrc[0])){ break; } if( (c=zSrc[0]-'0') > 7 ){ break;} nVal = nVal * 8 +  c; zSrc++;
		if(zSrc >= zEnd || !SyisDigit(zSrc[0])){ break; } if( (c=zSrc[0]-'0') > 7 ){ break;} nVal = nVal * 8 +  c; zSrc++;
		if(zSrc >= zEnd || !SyisDigit(zSrc[0])){ break; } if( (c=zSrc[0]-'0') > 7 ){ break;} nVal = nVal * 8 +  c; zSrc++;
		if(zSrc >= zEnd || !SyisDigit(zSrc[0])){ break; } if( (c=zSrc[0]-'0') > 7 ){ break;} nVal = nVal * 8 +  c; zSrc++;
	}
	/* Skip trailing spaces */
	while(zSrc < zEnd && SyisSpace(zSrc[0])){
		zSrc++;
	}
	if( zRest ){
		*zRest = (char *)zSrc;
	}	
	if( pOutVal ){
		if( isNeg == TRUE && nVal != 0 ){
			nVal = -nVal;
		}
		*(sxi32 *)pOutVal = nVal;
	}
	return (zSrc >= zEnd) ? SXRET_OK : SXERR_SYNTAX;
}
#ifndef SX_OMIT_FLOATINGPOINT
static const sxreal aTab[] = {
	10,
	1.0e2,
	1.0e4,
	1.0e8,
	1.0e16,
	1.0e32,
	1.0e64,
	1.0e128,
	1.0e256
};
#define SXDBL_DIG        15
#define SXDBL_EPSILON    2.2204460492503131e-016
#define SXDBL_MANT_DIG   53
#define SXDBL_MAX        1.7976931348623158e+308
#define SXDBL_MAX_EXP    308
#define SXDBL_MIN        2.2250738585072014e-308
#define SXDBL_MIN_EXP    	(-307)
#define SXDBL_MIN_EXP_PLUS	307

static sxi32 SyStrToReal(const char *zSrc,sxsize nLen,void * pOutVal,char **zRest)
{
	sxi32 rc = SXRET_OK;
	sxu8 neg = FALSE;
	sxreal Val = 0.0;
	const char *zEnd;
	sxi32 Lim,exp;
	sxreal *p = 0;
#ifdef UNTRUST
	if( SX_EMPTY_STR(zSrc)  ){
		if( pOutVal ){
			*(sxreal *)pOutVal = 0.0;
		}
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ) { nLen = SyStrlen(zSrc); }
	zEnd = &zSrc[nLen];
	while( zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++; 
	}
	if( zSrc < zEnd && (zSrc[0] == '-' || zSrc[0] == '+' ) ){
		neg =  zSrc[0] == '-' ? TRUE : FALSE ;
		zSrc++;
	}
	Lim = SXDBL_DIG ;
	for(;;){
		if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; zSrc++ ; --Lim;
		if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; zSrc++ ; --Lim;
		if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; zSrc++ ; --Lim;
		if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; zSrc++ ; --Lim;
	}
	if( zSrc < zEnd && ( zSrc[0] == '.' || zSrc[0] == ',' ) ){
		sxreal dec = 1.0;
		zSrc++;
		for(;;){
			if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; dec *= 10.0; zSrc++ ;--Lim;
			if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; dec *= 10.0; zSrc++ ;--Lim;
			if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; dec *= 10.0; zSrc++ ;--Lim;
			if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; dec *= 10.0; zSrc++ ;--Lim;
		}
		Val /= dec;
	}
	if( neg == TRUE && Val != 0.0 ) {
		Val = -Val ; 
	}
	if( Lim <= 0 ){
		/* jump overflow digit */
		while( zSrc < zEnd ){
			if( zSrc[0] == 'e' || zSrc[0] == 'E' ){
				break;  
			}
			zSrc++;
		}
		rc = SXERR_ORANGE;	/* out of range */
	}
	neg = FALSE;
	if( zSrc < zEnd && ( zSrc[0] == 'e' || zSrc[0] == 'E' ) ){
		zSrc++;
		if( zSrc < zEnd && ( zSrc[0] == '-' || zSrc[0] == '+') ){
			neg = zSrc[0] == '-' ? TRUE : FALSE ;
			zSrc++;
		}
		exp = 0;
		while( zSrc < zEnd && SyisDigit(zSrc[0]) && exp < SXDBL_MAX_EXP ){
			exp = exp * 10 + (zSrc[0] - '0');
			zSrc++;
		}
		if( neg  ){
			if( exp > SXDBL_MIN_EXP_PLUS ) exp = SXDBL_MIN_EXP_PLUS ;
		}else if ( exp > SXDBL_MAX_EXP ){
			exp = SXDBL_MAX_EXP; 
		}		
		for( p = (sxreal *)aTab ; exp ; exp >>= 1 , p++ ){
			if( exp & 01 ){
				if( neg ){
					Val /= *p ;
				}else{
					Val *= *p;
				}
			}
		}
	}
	while( zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zRest ){
		*zRest = (char *)zSrc; 
	}
	if( pOutVal ){
		*(sxreal *)pOutVal = Val;
	}
	return zSrc >= zEnd ? SXRET_OK : SXERR_SYNTAX;
}
#endif /* SX_OMIT_FLOATINGPOINT */
static sxi32 SyHexToint(sxi32 hc)
{
	if( hc >= '0' && hc <= '9' ){
		return hc - '0';
	}
	if( hc >= 'A' && hc <= 'F') {
		return hc - 'A' + 10;
	}		
	if( hc >= 'a' && hc <= 'f' ){
		return hc - 'a' + 10 ;
	}
	return 0; 	
}
static sxi32 SyBinToHexString(const void *pIn,sxsize nLen,char *zBuf,sxsize *pOutLen)
{
	static const unsigned char zHexTab[] = "0123456789abcdef";
	unsigned char *zOut = (unsigned char *)zBuf;
	unsigned char *zIn = (unsigned char *)pIn;
	unsigned char *zBufEnd,*zInEnd;
#if defined(UNTRUST)
	if( zIn == 0 || zBuf == 0 || pOutLen == 0 ){
		return SXERR_EMPTY;
	}
#endif
	zInEnd  = &zIn[nLen];
	zBufEnd = &zOut[(*pOutLen)];

	for(;;){
		if( zIn >= zInEnd || zOut > &zBufEnd[-2] ){
			break;
		}
		 zOut[0] = zHexTab[zIn[0] >> 4];  zOut[1] = zHexTab[zIn[0] & 0x0F]; zIn++; zOut += 2; 
	}
	*pOutLen = (sxsize)(zOut-(unsigned char *)zBuf);

	return SXRET_OK;
}
 /* SyRunTimeApi: sxlib.c */
static sxi32 SyBase64Encode(const char *zSrc,sxsize nLen,ProcConsumer xConsumer,void *pUserData)
{
	static const unsigned char zBase64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	unsigned char *zIn = (unsigned char *)zSrc;
	unsigned char z64[4];
	sxsize i;
	sxi32 rc;
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) || xConsumer == 0){
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}

	for(i = 0; i + 2 < nLen; i += 3){
		z64[0] = zBase64[(zIn[i] >> 2) & 0x3F];
		z64[1] = zBase64[( ((zIn[i] & 0x03) << 4)   | (zIn[i+1] >> 4)) & 0x3F]; 
		z64[2] = zBase64[( ((zIn[i+1] & 0x0F) << 2) | (zIn[i + 2] >> 6) ) & 0x3F];
		z64[3] = zBase64[ zIn[i + 2] & 0x3F];
		
		rc = xConsumer((const void *)z64,sizeof(z64),pUserData);
		if( rc != SXRET_OK ){return SXERR_ABORT;}

	}	
	if ( i+1 < nLen ){
		z64[0] = zBase64[(zIn[i] >> 2) & 0x3F];
		z64[1] = zBase64[( ((zIn[i] & 0x03) << 4)   | (zIn[i+1] >> 4)) & 0x3F]; 
		z64[2] = zBase64[(zIn[i+1] & 0x0F) << 2 ];
		z64[3] = '=';
		
		rc = xConsumer((const void *)z64,sizeof(z64),pUserData);
		if( rc != SXRET_OK ){return SXERR_ABORT;}

	}else if( i < nLen ){
		z64[0] = zBase64[(zIn[i] >> 2) & 0x3F];
		z64[1]   = zBase64[(zIn[i] & 0x03) << 4];
		z64[2] = '=';
		z64[3] = '=';
		
		rc = xConsumer((const void *)z64,sizeof(z64),pUserData);
		if( rc != SXRET_OK ){return SXERR_ABORT;}
	}

	return SXRET_OK;
}
static sxi32 SyBase64Decode(const char *zB64,sxsize nLen,ProcConsumer xConsumer,void *pUserData)
{
	static const sxu32 aBase64Trans[] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,62,0,0,0,63,52,53,54,55,56,57,58,59,60,61,0,0,0,0,0,0,0,0,1,2,3,4,
	5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,0,0,0,0,0,0,26,27,
	28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,0,0,
	0,0,0
	};
	sxu32 n,w,x,y,z;
	sxi32 rc;
	unsigned char zOut[10];
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zB64) || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zB64);
	}
	while(nLen > 0 && zB64[nLen - 1] == '=' ){
		nLen--;
	}
	for( n = 0 ; n+3<nLen ; n += 4){
		w = aBase64Trans[zB64[n] & 0x7F];
		x = aBase64Trans[zB64[n+1] & 0x7F];
		y = aBase64Trans[zB64[n+2] & 0x7F];
		z = aBase64Trans[zB64[n+3] & 0x7F];
		zOut[0] = ((w<<2) & 0xFC) | ((x>>4) & 0x03);
		zOut[1] = ((x<<4) & 0xF0) | ((y>>2) & 0x0F);
		zOut[2] = ((y<<6) & 0xC0) | (z & 0x3F);

		rc = xConsumer((const void *)zOut,sizeof(unsigned char)*3,pUserData);
		if( rc != SXRET_OK ){ return SXERR_ABORT;}
	}
	if( n+2 < nLen ){
		w = aBase64Trans[zB64[n] & 0x7F];
		x = aBase64Trans[zB64[n+1] & 0x7F];
		y = aBase64Trans[zB64[n+2] & 0x7F];

		zOut[0] = ((w<<2) & 0xFC) | ((x>>4) & 0x03);
		zOut[1] = ((x<<4) & 0xF0) | ((y>>2) & 0x0F);

		rc = xConsumer((const void *)zOut,sizeof(unsigned char)*2,pUserData);
		if( rc != SXRET_OK ){ return SXERR_ABORT;}
	}else if( n+1 < nLen ){
		w = aBase64Trans[zB64[n] & 0x7F];
		x = aBase64Trans[zB64[n+1] & 0x7F];

		zOut[0] = ((w<<2) & 0xFC) | ((x>>4) & 0x03);

		rc = xConsumer((const void *)zOut,sizeof(unsigned char)*1,pUserData);
		if( rc != SXRET_OK ){ return SXERR_ABORT;}
	}

	return SXRET_OK;
}
static const char *azHtmlEscape[] = {
	"&lt;","<","&gt;",">","&amp;","&","&quot;","\"","&#39;","'",
	"&#33;","!","&#36;","$","&#35;","#","&#37;","%","&#40;","(",
	"&#41;",")","&#123;","{","&#125;","}","&#61;","=","&#43;","+",
	"&#63;","?","&#91;","[","&#93;","]","&#64;","@","&#44;","," 
};
static sxi32 SyHtmlEscape(const char *zSrc,sxsize nLen,ProcConsumer xConsumer,void *pUserData)
{	 
	unsigned char *zIn = (unsigned char *)zSrc;
	unsigned char *zCur,*zEnd;
	sxi32 rc = SXRET_OK;
	sxu32 n;
	
#ifdef UNTRUST
	if( SX_EMPTY_STR(zSrc) || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}
	zEnd = &zIn[nLen]; zCur = zIn;
	for(;;){
		if( zCur >= zEnd ){
			if( zCur != zIn ){
				rc = xConsumer(zIn,(sxsize)(zCur-zIn),pUserData);
				if( rc != SXRET_OK ){
					return SXERR_ABORT;
				}
			}
			break;
		}
		for( n = 1 ; n < SX_ARRAYSIZE(azHtmlEscape) ; n += 2 ){
			if( zCur[0] ==  azHtmlEscape[n][0] ){
				nLen = SyStrlen(azHtmlEscape[n - 1]);
				if( zCur != zIn ){
					rc = xConsumer(zIn,(sxsize)(zCur-zIn),pUserData);
					if( rc != SXRET_OK ){
						return SXERR_ABORT;
					}
				}
				rc = xConsumer(azHtmlEscape[n - 1],nLen,pUserData);
				if( rc != SXRET_OK ){
					return SXERR_ABORT;
				}
				zIn = &zCur[1];
				break;
			}			
		}
		zCur++;		
	}
	return SXRET_OK;
}
static sxi32 SyHtmlUnescape(const char *zSrc,sxsize nLen,ProcConsumer xConsumer,void *pUserData)
{
	unsigned char *zIn = (unsigned char *)zSrc;
	unsigned char zOut[2];
	unsigned char *zEnd;
	sxu32 n,nPos;
	sxi32 rc;
#ifdef UNTRUST
	if( SX_EMPTY_STR(zSrc) || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}
	zEnd = &zIn[nLen];
	rc = SXRET_OK;
	for(;;){
		if( zIn >= zEnd ){
			break;
		}
		rc = SyByteFind((const char *)zIn,(sxsize)(zEnd - zIn),'&',&nPos);
		if( rc != SXRET_OK ){
			rc = xConsumer((const void*)zIn,(sxsize)(zEnd-zIn),pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT;
			}
			break;
		}
		if( nPos > 0 ){
			rc = xConsumer(zIn,nPos,pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT;
			}
		}
		zIn += nPos + 1;
		for (n  = 0; n < SX_ARRAYSIZE(azHtmlEscape) ; n += 2){
			nLen = SyStrlen(azHtmlEscape[n]);
			if( SyStrnicmp((const char *)&zIn[-1],azHtmlEscape[n],nLen) == 0 ){
				 break;
			}
		}
		zOut[0] = (n >= SX_ARRAYSIZE(azHtmlEscape)) ? zIn[-1] : azHtmlEscape[n+1][0];
		rc = xConsumer((const void *)zOut,sizeof(unsigned char),pUserData);
		if( rc != SXRET_OK ){
			return SXERR_ABORT;
		}
		if( n < SX_ARRAYSIZE(azHtmlEscape) ){
			zIn += nLen - 1;
		}	
	}
	return SXRET_OK;	 
}
#if defined(UNTRUST)
#define INVALID_LEXER(LEX)	(  LEX == 0  || LEX->xTokenizer == 0 )
#endif
static sxi32 SyLexStreamInit(SyStream *pStream,SySet *pSet,const char *zInput,sxu32 nLen)
{
#if defined(UNTRUST)
	if( pStream == 0 || SX_EMPTY_STR(zInput) ){
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zInput);
	}
	pStream->nIgn = 0;
	pStream->nLine = 1;
	pStream->pSet  = pSet;
	pStream->zText = pStream->zInput = (const unsigned char *)zInput;
	pStream->zEnd = &pStream->zText[nLen];
	return SXRET_OK;
}
static sxi32 SyLexInit(SyLex *pLex,SySet *pSet,ProcTokenizer xTokenizer,void *pUserData)
{
	SyStream *pStream;
#if defined (UNTRUST)
	if ( pLex == 0 || xTokenizer == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	pLex->pTokenSet = 0;
	if( pSet ){
		if ( SySetElemSize(pSet) != sizeof(SyToken) ){
			return SXERR_INVALID;
		}
		pLex->pTokenSet = pSet;
	}
	pStream = &pLex->sStream;
	pLex->xTokenizer = xTokenizer;
	pLex->pUserData = pUserData;
	
	pStream->nLine = 1;
	pStream->nIgn  = 0;
	pStream->zText = pStream->zEnd = 0;
	pStream->pSet  = pSet;
	return SXRET_OK;
}
static sxi32 SyLexTokenizeInput(SyLex *pLex,const char *zInput,sxsize nLen,void *pCtxData,ProcSort xSort,ProcCmp xCmp)
{
	const unsigned char *zCur;
	SyStream *pStream;
	SyToken sToken;
	sxi32 rc;
#if defined (UNTRUST)
	if ( INVALID_LEXER(pLex) || zInput == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zInput);
	}
	pStream = &pLex->sStream;
	/* Point to the head of the input */
	pStream->zText = pStream->zInput = (const unsigned char *)zInput;
	/* Point to the end of the input */
	pStream->zEnd = &pStream->zInput[nLen];
	for(;;){
		if( pStream->zText >= pStream->zEnd ){
			/* End of the input reached */
			break;
		}
		zCur = pStream->zText;
		/* Call the tokenizer callback */
		rc = pLex->xTokenizer(pStream,&sToken,pLex->pUserData,pCtxData);
		if( rc != SXRET_OK && rc != SXERR_CONTINUE ){
			/* Tokenizer callback request an operation abort */
			break;
		}
		if( rc == SXERR_CONTINUE ){
			/* Request to ignore this token */
			pStream->nIgn++;
		}else if( pLex->pTokenSet  ){
			/* Put the token in the set */
			rc = SySetPut(pLex->pTokenSet,(const void *)&sToken);
			if( rc != SXRET_OK ){
				break;
			}
		}
		if( zCur >= pStream->zText ){
			/* Automatic advance of the stream cursor */
			pStream->zText = &zCur[1];
		}
	}
	if( xSort &&  pLex->pTokenSet ){
		SyToken *aToken = (SyToken *)SySetBasePtr(pLex->pTokenSet);
		/* Sort the extrated tokens */
		if( xCmp == 0 ){
			/* Use a default comparison function */
			xCmp = SyMemcmp;
		}
		xSort(aToken,SySetUsed(pLex->pTokenSet),sizeof(SyToken),xCmp);
	}
	return SXRET_OK;
}
static sxi32 SyLexRelease(SyLex *pLex)
{
	sxi32 rc = SXRET_OK;
#if defined (UNTRUST)
	if ( INVALID_LEXER(pLex) ){
		return SXERR_CORRUPT;
	}
#else
	SXUNUSED(pLex); /* Prevent compiler warning */
#endif
	return rc;
}
static sxu32 SyBinHash(const void *pSrc,sxsize nLen)
{
	register unsigned char *zIn = (unsigned char *)pSrc;
	unsigned char *zEnd;
	sxu32 nH = 5381;
	
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zIn) ){
		return nH;
	}
#endif
	if( nLen <= 0 ){ 
		nLen = SyStrlen((const char *)zIn);
	}
	zEnd = &zIn[nLen];
	for(;;){
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
	}	
	return nH;
}
/*
 * RC4 Psuedo Random Number Generator (PRNG)
 * @authors: SQLite authors <http://www.sqlite.org/>
 * @status: Public Domain
 */
#define SXRC4_MAGIC	0x13C4
#ifdef __UNIXES__
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#endif
static sxi32 SyOSUtilRandomSeed(void *pBuf,sxsize nLen,void *pUnused)
{
	char *zBuf = (char *)pBuf;
#ifdef __WINNT__
	DWORD nProcessID; /* Yes,keep it uninitialized when compiling using the MinGW32 builds tools */
#elif defined(__UNIXES__)
	pid_t pid;
	int fd;
#else
	char zGarbage[128]; /* Yes,keep this buffer uninitialized */
#endif
	SXUNUSED(pUnused);
#ifdef __WINNT__
#ifndef __MINGW32__
	nProcessID = GetProcessId(GetCurrentProcess());
#endif
	SyMemcpy((const void *)&nProcessID,zBuf,SXMIN(nLen,sizeof(DWORD)));
	if( &zBuf[nLen] - &zBuf[sizeof(DWORD)] >= (int)sizeof(SYSTEMTIME)  ){
		GetSystemTime((LPSYSTEMTIME)&zBuf[sizeof(DWORD)]);
	}
#elif defined(__UNIXES__)
	fd = open("/dev/urandom",O_RDONLY);
	if (fd >= 0 ){
		if( read(fd,zBuf,nLen) > 0 ){
			return SXRET_OK;
		}
		/* FALL THRU */
	}
	pid = getpid();
	SyMemcpy((const void *)&pid,zBuf,SXMIN(nLen,sizeof(pid_t)));
	if( &zBuf[nLen] - &zBuf[sizeof(pid_t)] >= (int)sizeof(struct timeval)  ){
		gettimeofday((struct timeval *)&zBuf[sizeof(pid_t)],0);
	}
#else
	/* Fill with uninitialized data */
	SyMemcpy(zGarbage,zBuf,SXMIN(nLen,sizeof(zGarbage)));
#endif
	return SXRET_OK;
}
static sxi32 SyRandomnessInit(SyRC4Ctx *pCtx,ProcRandomSeed xSeed,void * pUserData)
{
	char zSeed[256];
	sxu8 t;
	sxi32 rc;
	sxu32 i;
	
	if( pCtx->nMagic == SXRC4_MAGIC ){
		return SXRET_OK; /* Already initialized */
	}
 /* Initialize the state of the random number generator once,
  ** the first time this routine is called.The seed value does
  ** not need to contain a lot of randomness since we are not
  ** trying to do secure encryption or anything like that...
  **
  ** Nothing in this file or anywhere else in the library does any kind of
  ** encryption.The RC4 algorithm is being used as a PRNG (pseudo-random
  ** number generator) not as an encryption device.
  */	
	if( xSeed == 0 ){
		xSeed = SyOSUtilRandomSeed;
	}
	rc = xSeed(zSeed,sizeof(zSeed),pUserData);
	if( rc != SXRET_OK ){
		return rc;
	}
	pCtx->i = pCtx->j = 0;
	for(i=0; i < SX_ARRAYSIZE(pCtx->s) ; i++){
		pCtx->s[i] = (unsigned char)i;
    }
    for(i=0; i < sizeof(zSeed) ; i++){
      pCtx->j += pCtx->s[i] + zSeed[i];
      t = pCtx->s[pCtx->j];
      pCtx->s[pCtx->j] = pCtx->s[i];
      pCtx->s[i] = t;
    }
	pCtx->nMagic = SXRC4_MAGIC;
	
	return SXRET_OK;
}
/*
 * Get a single 8-bit random value using the RC4 PRNG.
 */
static sxu8 randomByte(SyRC4Ctx *pCtx)
{
  sxu8 t;
  
  /* Generate and return single random byte */
  pCtx->i++;
  t = pCtx->s[pCtx->i];
  pCtx->j += t;
  pCtx->s[pCtx->i] = pCtx->s[pCtx->j];
  pCtx->s[pCtx->j] = t;
  t += pCtx->s[pCtx->i];
  return pCtx->s[t];
}
static sxi32 SyRandomness(SyRC4Ctx *pCtx,void *pBuf,sxsize nLen)
{
	unsigned char *zBuf = (unsigned char *)pBuf;
	unsigned char *zEnd = &zBuf[nLen];
#if defined(UNTRUST)
	if( pCtx == 0 || pBuf == 0 || nLen <= 0 ){
		return SXERR_EMPTY;
	}
#endif
	if(pCtx->nMagic != SXRC4_MAGIC ){
		return SXERR_CORRUPT;
	}
	for(;;){
		if( zBuf >= zEnd ){break;}	zBuf[0] = randomByte(pCtx);	zBuf++;	
		if( zBuf >= zEnd ){break;}	zBuf[0] = randomByte(pCtx);	zBuf++;	
		if( zBuf >= zEnd ){break;}	zBuf[0] = randomByte(pCtx);	zBuf++;	
		if( zBuf >= zEnd ){break;}	zBuf[0] = randomByte(pCtx);	zBuf++;	
	}
	return SXRET_OK;  
}
/* SyRunTimeApi: sxio.c */
#if defined(__UNIXES__)
#include <sys/mman.h>
#endif
static sxi32 SyOSMemoryUnmap(SyMapHandle *pMap,sxu32 nSize)
{	
#if defined(__WINNT__)
	BOOL rc;
	SXUNUSED(nSize); /* Prevent compiler warning */
	rc = UnmapViewOfFile((LPCVOID)pMap->pAddr);
	CloseHandle((HANDLE)pMap->pHandle);
	return !rc ? SXERR_OS : SXRET_OK;
#elif defined(__UNIXES__)
	int rc;
	rc = munmap(pMap->pAddr,nSize);
    return rc < 0 ? SXERR_OS : SXRET_OK;
#else
	SXUNUSED(pMap);
	SXUNUSED(nSize);
	return SXERR_NOTIMPLEMENTED;
#endif /* __WINNT__ */
}
static sxi32 SyOSMemoryMap(SyFile *pFile,sxu32 nLen,sxofft nOfft,sxu32 nProt,SyMapHandle *pMap)
{
#if defined(__WINNT__)
	DWORD dwProt = 0;
	HANDLE hFile;
#if defined(UNTRUST)
	if( pMap == 0 || nLen <= 0 ){
		return SXERR_EMPTY;
	}
#endif
	hFile = (HANDLE)SyFileGetHandle(pFile);
	if( hFile == 0 ){
		return SXERR_INVALID; /* Invalid file handle */
	}
	/* Note that SXMMAP_EXEC is ignored */
	if( nProt & SXMMAP_WRITE ){
		nProt |= SXMMAP_READ;
	}
	if( nProt & SXMMAP_READ ){
		dwProt = PAGE_READONLY;
		if(nProt & SXMMAP_WRITE ){
			dwProt = PAGE_READWRITE;
		}
	}
	pMap->pHandle = (HANDLE)CreateFileMapping(hFile,0,dwProt,0,(DWORD)nLen,0);
	if( pMap->pHandle == 0 ){
		return SXERR_OS;
	}
	pMap->pAddr = MapViewOfFile(pMap->pHandle,FILE_MAP_READ,0,(DWORD)nOfft,(SIZE_T)nLen);
	if( pMap->pAddr == 0 ){
		CloseHandle((HANDLE)pMap->pHandle);
		return SXERR_OS;
	}
	return SXRET_OK;
#elif defined(__UNIXES__)
	int prot = 0;
	void *pAddr;
	int fd;
#if defined(UNTRUST)
	if( pFile == 0 || pMap == 0 || nLen <= 0 ){
		return SXERR_EMPTY;
	}
#endif
	if( nProt & SXMMAP_READ ){
		prot |= PROT_READ;
	}
	if( nProt & SXMMAP_WRITE ){
		prot |= PROT_WRITE;
	}
	if( nProt & SXMMAP_EXEC ){
		prot |= PROT_EXEC;
	}
	fd = (int)pFile->pHandle;
	pAddr = mmap(0,nLen,prot,MAP_SHARED,fd,nOfft);
	if( pAddr == MAP_FAILED ){
		return SXERR_OS;
	}
	pMap->pAddr = pAddr;
	pMap->pHandle = 0;
	return SXRET_OK;
#else
	SXUNUSED(pFile);
	SXUNUSED(nLen);
	SXUNUSED(nOfft);
	SXUNUSED(nProt);
	SXUNUSED(pMap);
	return SXERR_NOTIMPLEMENTED;
#endif /* __WINNT__ */
}
#if defined(__WINNT__)
#ifndef SXMAX_CLOSE_ATTEMPTS
#define SXMAX_CLOSE_ATTEMPTS 3
#endif
/* the following two routines are taken from the sqlite3 source tree
 * status: Public Domain
 *
 */
/*
** Convert a UTF-8 string to microsoft unicode (UTF-16?).
**
** Space to hold the returned string is obtained from HeapAlloc().
*/
static WCHAR *utf8ToUnicode(const char *zFilename){
  int nChar;
  WCHAR *zWideFilename;

  nChar = MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, 0, 0);
  zWideFilename = (WCHAR *)HeapAlloc(GetProcessHeap(),0,nChar*sizeof(zWideFilename[0]));
  if( zWideFilename == 0 ){
 	return 0;
  } 
  nChar = MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, zWideFilename, nChar);
  if( nChar==0 ){
    HeapFree(GetProcessHeap(),0,zWideFilename);
    return 0;
  }
  return zWideFilename;
}
/*
** Convert a UTF-8 filename into whatever form the underlying
** operating system wants filenames in.Space to hold the result
** is obtained from HeapAlloc() and must be freed by the calling
** function.
*/
static void *convertUtf8Filename(const char *zFilename){
  void *zConverted = 0;
  zConverted = utf8ToUnicode(zFilename);
  return zConverted;
}
/* END OF SQLITE3 CODE */
#endif /* __WINNT__ */
static sxi32 xPPvfsFileOpen(const void *pPath,sxi32 iFLags,void **pData)
{
#if defined(__WINNT__)
	DWORD dwType = FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS;
	DWORD dwShare = FILE_SHARE_READ;
	DWORD dwAccess = GENERIC_READ;
	DWORD dwCreate = OPEN_EXISTING;	
	void *zConverted;
	HANDLE pHandle;
	
	SXUNUSED(iFLags);
	zConverted = convertUtf8Filename((const char *)pPath);
	if( zConverted == 0 ){
		return SXERR_MEM;
	}
	pHandle = CreateFileW((WCHAR *)zConverted,dwAccess,dwShare,0,dwCreate,dwType,0);
	if( pHandle == INVALID_HANDLE_VALUE){
		return SXERR_IO;
	}
	*pData = (void *)pHandle;
	HeapFree(GetProcessHeap(),0,zConverted);
	return SXRET_OK;
#elif defined( __UNIXES__)
	int fd;
	SXUNUSED(iFLags);
	fd = open((const char *)pPath,O_RDONLY);
	if( fd < 0 ){
		return SXERR_IO;
	}
	*pData = (void *)fd;
	return SXRET_OK;
#else
	SXUNUSED(pPath);
	SXUNUSED(iFLags);
	SXUNUSED(pData);
	return SXERR_NOTIMPLEMENTED;
#endif /* __WINNT__ */
}
static sxi32 xPPvfsFileClose(void *pData)
{
#if defined(__WINNT__)
	int i = 0;
	BOOL rc;
	do{
		rc = CloseHandle((HANDLE)pData);
	}while( FALSE == rc && i++ < SXMAX_CLOSE_ATTEMPTS && (Sleep(100),1) );
	if( !rc ){
		return SXERR_IO;
	}
	return SXRET_OK;
#elif defined( __UNIXES__)
	int fd = (int)pData;
	close(fd);
	return SXRET_OK;
#else
	SXUNUSED(pData);
	return SXERR_NOTIMPLEMENTED;
#endif /* __WINNT__ */
}
static sxi32 xPPvfsFileRead(void *pBuffer,sxsize nSize,sxsize *pReaden,void *pData)
{
#if defined(__WINNT__)
	HANDLE pHandle = (HANDLE)pData;
	char *zIn = (char *)pBuffer;
	DWORD nAmt,nRd;
	char *zEnd;
	sxi32 rc;

	zEnd = &zIn[nSize];
	nAmt = nRd = 0;
	rc = SXRET_OK;
	for(;;){
		if( zIn >= zEnd ){
			break;
		}
		rc = ReadFile(pHandle,(LPVOID)zIn,(DWORD)(zEnd-zIn),&nAmt,0);
		if( !rc ){
			if( GetLastError() == ERROR_HANDLE_EOF ){
				rc = SXERR_EOF;
			}else{
				rc =  SXERR_IO;
			}
			goto End;
		}
		if( nAmt <= 0 ){
			rc = SXERR_EOF;
			break;
		}
		nRd += nAmt;
		zIn = &zIn[nAmt];
	}
	if( nRd > 0 ){
		rc = SXRET_OK;
	}
End:
	if( pReaden ){
		*pReaden = (sxsize)nRd;
	}
	return rc;
#elif defined( __UNIXES__)
	ssize_t nRd;
	int fd;
	fd  = (int)pData;
	while( (nRd = read(fd,pBuffer,nSize)) < 0 && errno == EINTR && (usleep(100),1));
	if( nRd <= 0 ){
		return nRd == 0 ? SXERR_EOF : SXERR_IO;
	}
 	if( pReaden ){
	 *pReaden = (sxsize)nRd;
	}
	return SXRET_OK;
#else
	SXUNUSED(pBuffer);
	SXUNUSED(nSize);
	SXUNUSED(pReaden);
	SXUNUSED(pData);
	return SXERR_NOTIMPLEMENTED;
#endif /* __WINNT__ */
}
#ifdef __WINNT__
static void WinFileToSyTime(LPFILETIME pIn,sytime *pOut)
{
	pOut->tm_sec =  pIn->dwLowDateTime;
	pOut->tm_msec = pIn->dwHighDateTime;
}
#endif
static sxi32 xPPVfsFileStat(SyStat *pStat,void *pData)
{
#if defined(__WINNT__)
	BY_HANDLE_FILE_INFORMATION sWinStat;

	if( FALSE == GetFileInformationByHandle((HANDLE)pData,&sWinStat) ){
		return SXERR_IO;
	}
	pStat->nDev	= (sxu32)sWinStat.dwVolumeSerialNumber;
	pStat->unID = (sxu32)sWinStat.nFileIndexLow;
	pStat->nSize = sWinStat.nFileSizeHigh;
	pStat->nSize <<= 32;
	pStat->nSize += sWinStat.nFileSizeLow;
	WinFileToSyTime(&sWinStat.ftCreationTime,&pStat->tmCreat);
	WinFileToSyTime(&sWinStat.ftLastWriteTime,&pStat->tmModif);
	return SXRET_OK;
#elif defined( __UNIXES__)
	struct stat uStat;
	sytime *pTm;
	int fd; 
	
	fd = (int)pData;
	if( fstat(fd,&uStat) != 0 ){
		return SXERR_IO;
	}
	pStat->nDev	 =  (sxu32)uStat.st_dev;
	pStat->unID  =  (sxu32)uStat.st_ino;
	pStat->nSize =  (sxi64)uStat.st_size;
	pTm = &pStat->tmModif;
	pTm->tm_sec  = (long)uStat.st_mtime;
	pTm->tm_msec = 0;
	pTm = &pStat->tmCreat;
	pTm->tm_sec = pTm->tm_msec = 0;
	return SXRET_OK;
#else
	SXUNUSED(pData);
	SyZero(pStat,sizeof(SyStat));
	return SXERR_NOTIMPLEMENTED;
#endif /* __WINNT__ */
}
#ifndef XPP_OMIT_BUILTIN
#ifdef __WINNT__
static void WinSystemTimeFormat(LPSYSTEMTIME pIn,Sytm *pOut)
{
	pOut->tm_sec    = pIn->wSecond;
	pOut->tm_min    = pIn->wMinute;
	pOut->tm_mon    = pIn->wMonth - 1;
	pOut->tm_mday   = pIn->wDay;
	pOut->tm_yday   = 0;		
	pOut->tm_year   = pIn->wYear;
	pOut->tm_wday   = pIn->wDayOfWeek;
	pOut->tm_hour   = pIn->wHour;
	pOut->tm_isdst  = 0;
	pOut->tm_zone	= 0; 
}
static sxi32 WinLocalTime(sytime *pTime,Sytm *pOut)
{
	SYSTEMTIME sSysTime;
	FILETIME sFt,sFtLocal;
	
	sFt.dwLowDateTime   = pTime->tm_sec ;
	sFt.dwHighDateTime  = pTime->tm_msec ; /* Fake */
	FileTimeToLocalFileTime(&sFt,&sFtLocal);
	FileTimeToSystemTime(&sFtLocal,&sSysTime);
	WinSystemTimeFormat(&sSysTime,&(*pOut));
	return SXRET_OK;
}
#endif /* __WINNT__ */

static sxi32 SyOSUtilFormatTimeToLocal(sytime *pIn,Sytm *pOut)
{
#ifdef __WINNT__
	sxi32 rc;
	rc = WinLocalTime(pIn,&(*pOut));
	pOut->tm_zone = 0;
	return rc;
#elif defined(__UNIXES__)
	struct tm *pTm;
	time_t tt;

	tt = (time_t)pIn->tm_sec +  pIn->tm_msec / (1000000);
	pTm = localtime(&tt);
#if defined(UNTRUST)
	if( pTm == 0 ){
		SyZero(&(*pOut),sizeof(Sytm));
		return SXRET_OK;
	}
#endif
	STRUCT_TM_TO_SYTM(pTm,pOut);
	return SXRET_OK;
#else
	SXUNUSED(pIn);
	SyZero(&(*pOut),sizeof(Sytm));
	rc = SXERR_NOTIMPLEMENTED;
	return rc;
#endif
}
static sxi32 SyOSUtilGetSystemTime(sytime *pTime)
{
#ifdef __WINNT__
	FILETIME sFt;
	GetSystemTimeAsFileTime(&sFt);
	pTime->tm_sec = sFt.dwLowDateTime;
	pTime->tm_msec = sFt.dwHighDateTime; /* Fake */
	return SXRET_OK;
#elif defined(__UNIXES__)
	struct timeval tv;
	gettimeofday(&tv,0);
	pTime->tm_sec  = tv.tv_sec;
	pTime->tm_msec = tv.tv_usec;
	return SXRET_OK;
#else
	SyZero(&(*pTime),sizeof(sytime));
	return SXERR_NOTIMPLEMENTED;
#endif
}
#endif /* XPP_OMIT_BUILTIN */
static const SyFileMethods xPPvfsFileMethods = {
	xPPvfsFileOpen,     /* xOpen() */
	xPPvfsFileClose,    /* xClose() */ 
	xPPvfsFileRead,     /* xRead() */
	0, /* xWrite() */
	0, /* xWriteVec() */
	0, /* xAtomicWrite() */
	0, /* xAtomicRead() */
	0, /* xSync() */
	0, /* xLock() */
	0, /* xUnlock() */
	xPPVfsFileStat,  /* xStat() */
	0, /* xSeek() */
	0, /* xSeek46() */
	0, /* xTruncate() */
	0, /* xTruncate64() */
	0 /* xConfigure() */
};	
static const SyFileMethods * SyExportFileMethods(void)
{
	return &xPPvfsFileMethods;
}
static sxi32 SyFileInit(SyFile *pFile)
{
#if defined(UNTRUST)
	if( pFile == 0 ){
		return SXERR_EMPTY;
	}
#endif
	pFile->pMethods = SyExportFileMethods();
#if defined(UNTRUST)
	if( pFile->pMethods == 0 ){
		return SXERR_EMPTY;
	}
#endif
	return SXRET_OK;
}
static sxi32 SyFileOpen(SyFile *pFile,const void *pFilename,sxi32 nFLags)
{	
	sxi32 rc;
#if defined(UNTRUST)
	if( pFile == 0 || pFile->pMethods == 0 || pFile->pMethods->xOpen == 0){
		return SXERR_INVALID;
	}
#endif
	rc = pFile->pMethods->xOpen(pFilename,nFLags,&pFile->pHandle);
	return rc;
}
static sxi32 SyFileRead(SyFile *pFile,void *pBuffer,sxsize nBufsize,sxsize *pReaden)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( pFile == 0 || pFile->pMethods == 0 || pFile->pMethods->xRead == 0){
		return SXERR_INVALID;
	}
#endif
	rc = pFile->pMethods->xRead(pBuffer,nBufsize,&(*pReaden),pFile->pHandle);
	return rc;
}
static sxi32 SyFileClose(SyFile *pFile)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( pFile == 0 || pFile->pMethods == 0 || pFile->pMethods->xClose == 0 ){
		return SXERR_INVALID;
	}
#endif
	rc = pFile->pMethods->xClose(pFile->pHandle);
	return  rc;
}
static sxi32 SyFileStat(SyFile *pFile,SyStat *pStat)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( pFile == 0 || pStat == 0 || pFile->pMethods == 0){
		return SXERR_INVALID;
	}
#endif
	if( pFile->pMethods->xStat == 0 ){
		return SXERR_NOOP;
	}
	rc = pFile->pMethods->xStat(&(*pStat),pFile->pHandle);
	return  rc;
}
#ifndef XPP_OMIT_BUILTIN
#ifdef __UNIXES__
#include <sys/utsname.h>
#endif
static sxi32 ExpandOsName(xpp_context *pCtx)
{
#if defined(__WINNT__)
	const char *zName = "Microsoft Windows";
	OSVERSIONINFOW sVer;
	
	sVer.dwOSVersionInfoSize = sizeof(sVer);
	if( TRUE != GetVersionExW(&sVer)){
		xpp_context_append(&(*pCtx),zName,SyStrlen(zName));
		return SXRET_OK;
	}
	if( sVer.dwPlatformId == VER_PLATFORM_WIN32_NT ){
		if( sVer.dwMajorVersion <= 4 ){
			zName = "Microsoft Windows NT";
		}else if( sVer.dwMajorVersion == 5 ){
			switch(sVer.dwMinorVersion){
				case 0:	zName = "Microsoft Windows 2000"; break;
				case 1: zName = "Microsoft Windows XP";   break;
				case 2: zName = "Microsoft Windows Server 2003"; break;
			}
		}else if( sVer.dwMajorVersion == 6){
				switch(sVer.dwMinorVersion){
					case 0: zName = "Microsoft Windows Vista"; break;
					case 1: zName = "Microsoft Windows 7"; break;
					case 2: zName = "Microsoft Windows Server 2008"; break;
					default: break;
				}
		}
	}
	xpp_context_append(&(*pCtx),zName,SyStrlen(zName));
#elif defined(__UNIXES__)
	struct utsname sInfo;
	if( uname(&sInfo) != 0 ){
		xpp_context_append(&(*pCtx),"Unix",sizeof("Unix")-1);
		return SXRET_OK;
	}
	xpp_context_format(&(*pCtx),"%s %s",sInfo.sysname,sInfo.release);
#else
	xpp_context_append(&(*pCtx),"Unknown Operating System",sizeof("Unknown Operating System")-1);
#endif
	return SXRET_OK;
}
static sxi32 ExpandSysCmd(xpp_context *pCtx,const SyString *pCmd)
{
#if defined(__WINNT__)
	PROCESS_INFORMATION sProcess;
	STARTUPINFOA sInfo;
	BOOL rc;

	SyZero(&sProcess,sizeof(sProcess));
	SyZero(&sInfo,sizeof(sInfo));
	sInfo.cb = sizeof(sInfo);
	rc = CreateProcess(pCmd->zString,0,0,0,FALSE,0,0,0,&sInfo,&sProcess);
	if( rc == FALSE ){
		xpp_context_append(&(*pCtx),"0",sizeof(char));
	}else{
		xpp_context_append(&(*pCtx),"1",sizeof(char));
		CloseHandle(sProcess.hProcess);
		CloseHandle(sProcess.hThread);
	}
#elif defined(__UNIXES__)
	int rc;
	rc = system(pCmd->zString);
	xpp_context_append(&(*pCtx),rc == 0 ? "1":"0",sizeof(char));
#else
	/* Expand zero */
	SXUNUSED(pCmd);
	xpp_context_append(&(*pCtx),"0",sizeof(char));
#endif
	return SXRET_OK;
}
#endif /* XPP_OMIT_BUILTIN */
/* SyRunTimeApi: sxhash.c */
/*
 * This code implements the MD5 message-digest algorithm.
 * The algorithm is due to Ron Rivest.This code was
 * written by Colin Plumb in 1993, no copyright is claimed.
 * This code is in the public domain; do with it what you wish.
 *
 * Equivalent code is available from RSA Data Security, Inc.
 * This code has been tested against that, and is equivalent,
 * except that you don't need to include two pages of legalese
 * with every copy.
 *
 * To compute the message digest of a chunk of bytes, declare an
 * MD5Context structure, pass it to MD5Init, call MD5Update as
 * needed on buffers full of bytes, and then call MD5Final, which
 * will fill a supplied 16-byte array with the digest.
 */

/*
 * Note: this code is harmless on little-endian machines.
 */
static void byteReverse (unsigned char *buf, unsigned longs)
{
	sxu32 t;
        do {
                t = (sxu32)((unsigned)buf[3]<<8 | buf[2]) << 16 |
                            ((unsigned)buf[1]<<8 | buf[0]);
                *(sxu32*)buf = t;
                buf += 4;
        } while (--longs);
}
/* The four core functions - F1 is optimized somewhat */

/* #define F1(x, y, z) (x & y | ~x & z) */
#ifdef F1
#undef F1
#endif
#ifdef F2
#undef F2
#endif
#ifdef F3
#undef F3
#endif
#ifdef F4
#undef F4
#endif

#define F1(x, y, z) (z ^ (x & (y ^ z)))
#define F2(x, y, z) F1(z, x, y)
#define F3(x, y, z) (x ^ y ^ z)
#define F4(x, y, z) (y ^ (x | ~z))

/* This is the central step in the MD5 algorithm.*/
#define SX_MD5STEP(f, w, x, y, z, data, s) \
        ( w += f(x, y, z) + data,  w = w<<s | w>>(32-s),  w += x )

/*
 * The core of the MD5 algorithm, this alters an existing MD5 hash to
 * reflect the addition of 16 longwords of new data.MD5Update blocks
 * the data and converts bytes into longwords for this routine.
 */
static void MD5Transform(sxu32 buf[4], const sxu32 in[16])
{
	register sxu32 a, b, c, d;

        a = buf[0];
        b = buf[1];
        c = buf[2];
        d = buf[3];

        SX_MD5STEP(F1, a, b, c, d, in[ 0]+0xd76aa478,  7);
        SX_MD5STEP(F1, d, a, b, c, in[ 1]+0xe8c7b756, 12);
        SX_MD5STEP(F1, c, d, a, b, in[ 2]+0x242070db, 17);
        SX_MD5STEP(F1, b, c, d, a, in[ 3]+0xc1bdceee, 22);
        SX_MD5STEP(F1, a, b, c, d, in[ 4]+0xf57c0faf,  7);
        SX_MD5STEP(F1, d, a, b, c, in[ 5]+0x4787c62a, 12);
        SX_MD5STEP(F1, c, d, a, b, in[ 6]+0xa8304613, 17);
        SX_MD5STEP(F1, b, c, d, a, in[ 7]+0xfd469501, 22);
        SX_MD5STEP(F1, a, b, c, d, in[ 8]+0x698098d8,  7);
        SX_MD5STEP(F1, d, a, b, c, in[ 9]+0x8b44f7af, 12);
        SX_MD5STEP(F1, c, d, a, b, in[10]+0xffff5bb1, 17);
        SX_MD5STEP(F1, b, c, d, a, in[11]+0x895cd7be, 22);
        SX_MD5STEP(F1, a, b, c, d, in[12]+0x6b901122,  7);
        SX_MD5STEP(F1, d, a, b, c, in[13]+0xfd987193, 12);
        SX_MD5STEP(F1, c, d, a, b, in[14]+0xa679438e, 17);
        SX_MD5STEP(F1, b, c, d, a, in[15]+0x49b40821, 22);

        SX_MD5STEP(F2, a, b, c, d, in[ 1]+0xf61e2562,  5);
        SX_MD5STEP(F2, d, a, b, c, in[ 6]+0xc040b340,  9);
        SX_MD5STEP(F2, c, d, a, b, in[11]+0x265e5a51, 14);
        SX_MD5STEP(F2, b, c, d, a, in[ 0]+0xe9b6c7aa, 20);
        SX_MD5STEP(F2, a, b, c, d, in[ 5]+0xd62f105d,  5);
        SX_MD5STEP(F2, d, a, b, c, in[10]+0x02441453,  9);
        SX_MD5STEP(F2, c, d, a, b, in[15]+0xd8a1e681, 14);
        SX_MD5STEP(F2, b, c, d, a, in[ 4]+0xe7d3fbc8, 20);
        SX_MD5STEP(F2, a, b, c, d, in[ 9]+0x21e1cde6,  5);
        SX_MD5STEP(F2, d, a, b, c, in[14]+0xc33707d6,  9);
        SX_MD5STEP(F2, c, d, a, b, in[ 3]+0xf4d50d87, 14);
        SX_MD5STEP(F2, b, c, d, a, in[ 8]+0x455a14ed, 20);
        SX_MD5STEP(F2, a, b, c, d, in[13]+0xa9e3e905,  5);
        SX_MD5STEP(F2, d, a, b, c, in[ 2]+0xfcefa3f8,  9);
        SX_MD5STEP(F2, c, d, a, b, in[ 7]+0x676f02d9, 14);
        SX_MD5STEP(F2, b, c, d, a, in[12]+0x8d2a4c8a, 20);

        SX_MD5STEP(F3, a, b, c, d, in[ 5]+0xfffa3942,  4);
        SX_MD5STEP(F3, d, a, b, c, in[ 8]+0x8771f681, 11);
        SX_MD5STEP(F3, c, d, a, b, in[11]+0x6d9d6122, 16);
        SX_MD5STEP(F3, b, c, d, a, in[14]+0xfde5380c, 23);
        SX_MD5STEP(F3, a, b, c, d, in[ 1]+0xa4beea44,  4);
        SX_MD5STEP(F3, d, a, b, c, in[ 4]+0x4bdecfa9, 11);
        SX_MD5STEP(F3, c, d, a, b, in[ 7]+0xf6bb4b60, 16);
        SX_MD5STEP(F3, b, c, d, a, in[10]+0xbebfbc70, 23);
        SX_MD5STEP(F3, a, b, c, d, in[13]+0x289b7ec6,  4);
        SX_MD5STEP(F3, d, a, b, c, in[ 0]+0xeaa127fa, 11);
        SX_MD5STEP(F3, c, d, a, b, in[ 3]+0xd4ef3085, 16);
        SX_MD5STEP(F3, b, c, d, a, in[ 6]+0x04881d05, 23);
        SX_MD5STEP(F3, a, b, c, d, in[ 9]+0xd9d4d039,  4);
        SX_MD5STEP(F3, d, a, b, c, in[12]+0xe6db99e5, 11);
        SX_MD5STEP(F3, c, d, a, b, in[15]+0x1fa27cf8, 16);
        SX_MD5STEP(F3, b, c, d, a, in[ 2]+0xc4ac5665, 23);

        SX_MD5STEP(F4, a, b, c, d, in[ 0]+0xf4292244,  6);
        SX_MD5STEP(F4, d, a, b, c, in[ 7]+0x432aff97, 10);
        SX_MD5STEP(F4, c, d, a, b, in[14]+0xab9423a7, 15);
        SX_MD5STEP(F4, b, c, d, a, in[ 5]+0xfc93a039, 21);
        SX_MD5STEP(F4, a, b, c, d, in[12]+0x655b59c3,  6);
        SX_MD5STEP(F4, d, a, b, c, in[ 3]+0x8f0ccc92, 10);
        SX_MD5STEP(F4, c, d, a, b, in[10]+0xffeff47d, 15);
        SX_MD5STEP(F4, b, c, d, a, in[ 1]+0x85845dd1, 21);
        SX_MD5STEP(F4, a, b, c, d, in[ 8]+0x6fa87e4f,  6);
        SX_MD5STEP(F4, d, a, b, c, in[15]+0xfe2ce6e0, 10);
        SX_MD5STEP(F4, c, d, a, b, in[ 6]+0xa3014314, 15);
        SX_MD5STEP(F4, b, c, d, a, in[13]+0x4e0811a1, 21);
        SX_MD5STEP(F4, a, b, c, d, in[ 4]+0xf7537e82,  6);
        SX_MD5STEP(F4, d, a, b, c, in[11]+0xbd3af235, 10);
        SX_MD5STEP(F4, c, d, a, b, in[ 2]+0x2ad7d2bb, 15);
        SX_MD5STEP(F4, b, c, d, a, in[ 9]+0xeb86d391, 21);

        buf[0] += a;
        buf[1] += b;
        buf[2] += c;
        buf[3] += d;
}
/*
 * Update context to reflect the concatenation of another buffer full
 * of bytes.
 */
static void MD5Update(SyMD5 *ctx, const unsigned char *buf, unsigned int len)
{
	sxu32 t;

        /* Update bitcount */
        t = ctx->bits[0];
        if ((ctx->bits[0] = t + ((sxu32)len << 3)) < t)
                ctx->bits[1]++; /* Carry from low to high */
        ctx->bits[1] += len >> 29;
        t = (t >> 3) & 0x3f;    /* Bytes already in shsInfo->data */
        /* Handle any leading odd-sized chunks */
        if ( t ) {
                unsigned char *p = (unsigned char *)ctx->in + t;

                t = 64-t;
                if (len < t) {
                        SyMemcpy(buf,p,len);
                        return;
                }
                SyMemcpy(buf,p,t);
                byteReverse(ctx->in, 16);
                MD5Transform(ctx->buf, (sxu32*)ctx->in);
                buf += t;
                len -= t;
        }
        /* Process data in 64-byte chunks */
        while (len >= 64) {
                SyMemcpy(buf,ctx->in,64);
                byteReverse(ctx->in, 16);
                MD5Transform(ctx->buf, (sxu32*)ctx->in);
                buf += 64;
                len -= 64;
        }
        /* Handle any remaining bytes of data.*/
        SyMemcpy(buf,ctx->in,len);
}

/*
 * Final wrapup - pad to 64-byte boundary with the bit pattern 
 * 1 0* (64-bit count of bits processed, MSB-first)
 */
static void MD5Final(unsigned char digest[16], SyMD5 *ctx){
        unsigned count;
        unsigned char *p;

        /* Compute number of bytes mod 64 */
        count = (ctx->bits[0] >> 3) & 0x3F;

        /* Set the first char of padding to 0x80.This is safe since there is
           always at least one byte free */
        p = ctx->in + count;
        *p++ = 0x80;

        /* Bytes of padding needed to make 64 bytes */
        count = 64 - 1 - count;

        /* Pad out to 56 mod 64 */
        if (count < 8) {
                /* Two lots of padding:  Pad the first block to 64 bytes */
               SyZero(p,count);
                byteReverse(ctx->in, 16);
                MD5Transform(ctx->buf, (sxu32*)ctx->in);

                /* Now fill the next block with 56 bytes */
                SyZero(ctx->in,56);
        } else {
                /* Pad block to 56 bytes */
                SyZero(p,count-8);
        }
        byteReverse(ctx->in, 14);

        /* Append length in bits and transform */
        ((sxu32*)ctx->in)[ 14 ] = ctx->bits[0];
        ((sxu32*)ctx->in)[ 15 ] = ctx->bits[1];

        MD5Transform(ctx->buf, (sxu32*)ctx->in);
        byteReverse((unsigned char *)ctx->buf, 4);
        SyMemcpy(ctx->buf,digest,0x10);
        SyZero(ctx,sizeof(ctx));    /* In case it's sensitive */
}
static sxi32 SyMD5Init(SyMD5 *pCtx)
{
#if defined(UNTRUST)
	if( pCtx == 0 ){
		return SXERR_EMPTY;
	}
#endif
	
	pCtx->buf[0] = 0x67452301;
    pCtx->buf[1] = 0xefcdab89;
    pCtx->buf[2] = 0x98badcfe;
    pCtx->buf[3] = 0x10325476;
    pCtx->bits[0] = 0;
    pCtx->bits[1] = 0;
   
   return SXRET_OK;
}
static sxi32 SyMD5Update(SyMD5 *pCtx,const void *pIn,sxsize nLen)
{
#if defined(UNTRUST)
	if( pCtx == 0 || pIn == 0 || nLen <= 0 ){
		return SXERR_INVALID;
	}
#endif
	MD5Update(&(*pCtx),(const unsigned char *)pIn,nLen);
	return SXRET_OK;
}
static sxi32 SyMD5Final(SyMD5 *pCtx,unsigned char *zDigest,sxu32 nLen)
{
#if defined(UNTRUST)
	if( pCtx ==0 || zDigest ==0 || nLen < SX_MD5_BINSZ ){
		return SXERR_INVALID;
	}
#endif
	SXUNUSED(nLen);
	MD5Final(zDigest,&(*pCtx));
	return SXRET_OK;
}
static sxi32 SyMD5ComputeSum(const void *pIn,sxsize nLen,unsigned char *zDigest,sxu32 oLen)
{
	SyMD5 sCtx;
	sxi32 rc;
	
	SyMD5Init(&sCtx);
	SyMD5Update(&sCtx,pIn,nLen);
	rc = SyMD5Final(&sCtx,zDigest,oLen);	
	return rc;
}
 /* SyRunTimeApi: sxds.c */
static sxi32 SySetGetNextEntry(SySet *pSet,void **ppEntry)
{
	register unsigned char *zSrc;
#if defined(UNTRUST)
	if( pSet == 0  ){
		return SXERR_EMPTY;
	}
#endif
	if( pSet->nCursor >= pSet->nUsed ){
		/* Reset cursor */
		pSet->nCursor = 0;
		return SXERR_EOF;
	}
	zSrc = (unsigned char *)SySetBasePtr(pSet);
	if( ppEntry ){
		*ppEntry = (void *)&zSrc[pSet->nCursor * pSet->eSize];
	}
	pSet->nCursor++;
	return SXRET_OK;
}	
static sxi32 SySetInit(SySet *pSet,SyMemBackend *pAllocator,sxu32 ElemSize)
{
#ifdef UNTRUST
	if( pSet == 0 || ElemSize <= 0 ){
		return SXERR_EMPTY;
	}
#endif
	pSet->nSize = 0 ;
	pSet->nUsed = 0;
	pSet->nCursor = 0;
	pSet->eSize = ElemSize;
	pSet->pAllocator = pAllocator;
	pSet->pBase =  0;

	return SXRET_OK;
}
static sxi32 SySetPut(SySet *pSet,const void *pItem)
{
	unsigned char *zbase;
#if defined(UNTRUST)
	if( pSet == 0 || pItem == 0 ){
		return SXERR_EMPTY;
	}
#endif
	if( pSet->nUsed >= pSet->nSize ){
		void *pNew;
		if( pSet->pAllocator == 0 ){
			return  SXERR_LOCKED;
		}
		if( pSet->nSize <= 0 ){
			pSet->nSize = 4;
		}
		pNew = SyMemBackendRealloc(pSet->pAllocator,pSet->pBase,pSet->eSize * pSet->nSize * 2);
		if( pNew == 0 ){
			return SXERR_MEM;
		}
		pSet->pBase = pNew;
		pSet->nSize *= 2;
	}
	zbase = (unsigned char *)pSet->pBase;
	SX_MACRO_FAST_MEMCPY(pItem,&zbase[pSet->nUsed * pSet->eSize],pSet->eSize);
	pSet->nUsed++;	
	return SXRET_OK;
}
static sxi32 SySetRemove(SySet *pSet,sxu32 nPos,void *pInfo)
{
	unsigned char *zBase ;
#if defined(UNTRUST)
	if( pSet == 0 ){
		return SXERR_INVALID;
	}
#endif
	if( nPos >= pSet->nUsed ){
		return SXERR_ORANGE;
	}	
	zBase = (unsigned char *)pSet->pBase;
	if( pInfo != 0 ){
		SyMemcpy(&zBase[nPos * pSet->eSize],pInfo,pSet->eSize);
	}
	pSet->nUsed--;
	for( ;; ){
		if( nPos >= pSet->nUsed){ break; } SX_MACRO_FAST_MEMCPY(&zBase[(nPos + 1) * pSet->eSize],&zBase[nPos * pSet->eSize],pSet->eSize); nPos++;
		if( nPos >= pSet->nUsed){ break; } SX_MACRO_FAST_MEMCPY(&zBase[(nPos + 1) * pSet->eSize],&zBase[nPos * pSet->eSize],pSet->eSize); nPos++;
		if( nPos >= pSet->nUsed){ break; } SX_MACRO_FAST_MEMCPY(&zBase[(nPos + 1) * pSet->eSize],&zBase[nPos * pSet->eSize],pSet->eSize); nPos++;
		if( nPos >= pSet->nUsed){ break; } SX_MACRO_FAST_MEMCPY(&zBase[(nPos + 1) * pSet->eSize],&zBase[nPos * pSet->eSize],pSet->eSize); nPos++;
	}		
	return  SXRET_OK ;
}
static sxi32 SySetAlloc(SySet *pSet,sxi32 nItem)
{
#if defined(UNTRUST)
	if( pSet == 0 ){
		return SXERR_INVALID;
	}
#endif
	if( pSet->nSize > 0 ){
		return SXERR_LOCKED;
	}
	if( nItem < 8 ){
		nItem = 8;
	}
	pSet->pBase = SyMemBackendAlloc(pSet->pAllocator,pSet->eSize * nItem);
	if( pSet->pBase == 0 ){
		return SXERR_MEM;
	}
	pSet->nSize = nItem;
	return SXRET_OK;
} 
static sxi32 SySetAccess(SySet *pSet,sxu32 nPos,void **ppInfo)
{
	const char *zBase;
#if defined(UNTRUST)
	if( pSet == 0  || ppInfo == 0 ){
		return SXERR_INVALID;
	}
#endif
	if( nPos >= pSet->nUsed ){
		return SXERR_ORANGE;
	}
	zBase = (const char *)pSet->pBase;
	*ppInfo = (void *)&zBase[nPos * pSet->eSize];
	return SXRET_OK;
}
static sxi32 SySetReset(SySet *pSet)
{
#if defined(UNTRUST)
	if( pSet == 0  ){
		return SXERR_EMPTY;
	}
#endif
	pSet->nUsed   = 0;
	pSet->nCursor = 0;
	return SXRET_OK;
}
static sxi32 SySetResetCursor(SySet *pSet)
{
#if defined(UNTRUST)
	if( pSet == 0  ){
		return SXERR_EMPTY;
	}
#endif
	pSet->nCursor = 0;
	return SXRET_OK;
}
static sxi32 SySetRelease(SySet *pSet)
{
	sxi32 rc = SXRET_OK;
#if defined(UNTRUST)
	if( pSet == 0  ){
		return SXERR_EMPTY;
	}
#endif
	if( pSet->pAllocator && pSet->pBase ){
		rc = SyMemBackendFree(pSet->pAllocator,pSet->pBase);
	}
	pSet->pAllocator = 0;
	pSet->pBase = 0;
	return rc;
}
#ifndef XPP_OMIT_BUILTIN
static sxi32 SySetTruncate(SySet *pSet,sxu32 nNewSize)
{
#if defined(UNTRUST)
	if( pSet == 0){
		return SXERR_EMPTY;
	}
#endif
	if( nNewSize < pSet->nUsed ){
		pSet->nUsed = nNewSize;
	}
	return SXRET_OK;
}
#endif
static void * SySetPeek(SySet *pSet)
{
	const char *zBase;
#if defined(UNTRUST)
	if( pSet == 0){
		return 0;
	}
#endif
	if( pSet->nUsed <= 0 ){
		return 0;
	}
	zBase = (const char *)pSet->pBase;
	return (void *)&zBase[(pSet->nUsed - 1) * pSet->eSize]; 
}
static void * SySetPop(SySet *pSet)
{
	const char *zBase;
	void *pData;
#if defined(UNTRUST)
	if( pSet == 0){
		return 0;
	}
#endif
	if( pSet->nUsed <= 0 ){
		return 0;
	}
	zBase = (const char *)pSet->pBase;
	pSet->nUsed--;
	pData =  (void *)&zBase[pSet->nUsed * pSet->eSize]; 
	return pData;
}
/* Private hash entry */
struct SyHashEntry_Pr
{
	const void *pKey; /* Hash key */
	sxu32 nKeyLen;    /* Key length */
	void *pUserData;  /* User private data */
	/* Private fields */
	SyHash *pHash;
	sxu32 nHash;
	SyHashEntry_Pr *pNext,*pPrev; /* Next and previous entry in the list */
	SyHashEntry_Pr *pNextCollide,*pPrevCollide; /* Collision list */
};
#define INVALID_HASH(H) ((H) == 0 || (H)->apBucket == 0)
static sxi32 SyHashInit(SyHash *pHash,SyMemBackend *pAllocator,ProcHash xHash,ProcCmp xCmp)
{
	SyHashEntry_Pr **apNew;
#if defined(UNTRUST)
	if( pHash == 0 ){
		return SXERR_EMPTY;
	}
#endif
	/* Allocate a new table */
	apNew = (SyHashEntry_Pr **)SyMemBackendAlloc(&(*pAllocator),sizeof(SyHashEntry_Pr *) * SXHASH_BUCKET_SIZE);
	if( apNew == 0 ){
		return SXERR_MEM;
	}
	SyZero((void *)apNew,sizeof(SyHashEntry_Pr *) * SXHASH_BUCKET_SIZE);
	pHash->pAllocator = &(*pAllocator);
	pHash->xHash = xHash ? xHash : SyBinHash;
	pHash->xCmp = xCmp ? xCmp : SyMemcmp;
	pHash->pCurrent = pHash->pList = 0;
	pHash->nEntry = 0;
	pHash->apBucket = apNew;
	pHash->nBucketSize = SXHASH_BUCKET_SIZE;
	return SXRET_OK;
}
static sxi32 SyHashRelease(SyHash *pHash)
{
	SyHashEntry_Pr *pEntry,*pNext;
#if defined(UNTRUST)
	if( INVALID_HASH(pHash)  ){
		return SXERR_EMPTY;
	}
#endif
	pEntry = pHash->pList;
	for(;;){
		if( pHash->nEntry == 0 ){
			break;
		}
		pNext = pEntry->pNext;
		SyMemBackendPoolFree(pHash->pAllocator,pEntry);
		pEntry = pNext;
		pHash->nEntry--;
	}
	if( pHash->apBucket ){
		SyMemBackendFree(pHash->pAllocator,(void *)pHash->apBucket);
	}
	pHash->apBucket = 0;
	pHash->nBucketSize = 0;
	pHash->pAllocator = 0;
	return SXRET_OK;
}
static SyHashEntry_Pr * HashGetEntry(SyHash *pHash,const void *pKey,sxu32 nKeyLen)
{
	SyHashEntry_Pr *pEntry;
	sxu32 nHash;

	nHash = pHash->xHash(pKey,nKeyLen);
	pEntry = pHash->apBucket[nHash & (pHash->nBucketSize - 1)];
	for(;;){
		if( pEntry == 0 ){
			break;
		}
		if( pEntry->nHash == nHash && pEntry->nKeyLen == nKeyLen && 
			pHash->xCmp(pEntry->pKey,pKey,nKeyLen) == 0 ){
				return pEntry;
		}
		pEntry = pEntry->pNextCollide;
	}
	/* Entry not found */
	return 0;
}
static SyHashEntry * SyHashGet(SyHash *pHash,const void *pKey,sxu32 nKeyLen)
{
	SyHashEntry_Pr *pEntry;
#if defined(UNTRUST)
	if( INVALID_HASH(pHash) ){
		return 0;
	}
#endif
	if( nKeyLen <= 0 ){
		nKeyLen = (sxu32)SyBlobLen(pKey,0);
	}
	pEntry = HashGetEntry(&(*pHash),pKey,nKeyLen);
	if( pEntry == 0 ){
		return 0;
	}
	return (SyHashEntry *)pEntry;
}
static sxi32 HashDeleteEntry(SyHash *pHash,SyHashEntry_Pr *pEntry,void **ppUserData)
{
	sxi32 rc;
	if( pEntry->pPrevCollide == 0 ){
		pHash->apBucket[pEntry->nHash & (pHash->nBucketSize - 1)] = pEntry->pNextCollide;
	}else{
		pEntry->pPrevCollide->pNextCollide = pEntry->pNextCollide;
	}
	if( pEntry->pNextCollide ){
		pEntry->pNextCollide->pPrevCollide = pEntry->pPrevCollide;
	}
	MACRO_LD_REMOVE(pHash->pList,pEntry);
	pHash->nEntry--;
	if( ppUserData ){
		/* Write a pointer to the user data */
		*ppUserData = pEntry->pUserData;
	}
	/* Release the entry */
	rc = SyMemBackendPoolFree(pHash->pAllocator,pEntry);
	return rc;
}
static sxi32 SyHashDeleteEntry(SyHash *pHash,const void *pKey,sxu32 nKeyLen,void **ppUserData)
{
	SyHashEntry_Pr *pEntry;
	sxi32 rc;
#if defined(UNTRUST)
	if( INVALID_HASH(pHash) ){
		return SXERR_CORRUPT;
	}
#endif
	if( nKeyLen <= 0 ){
		nKeyLen = (sxu32)SyBlobLen(pKey,0);
	}
	pEntry = HashGetEntry(&(*pHash),pKey,nKeyLen);
	if( pEntry == 0 ){
		return SXERR_NOTFOUND;
	}
	rc = HashDeleteEntry(&(*pHash),pEntry,ppUserData);
	return rc;
}
static sxi32 SyHashDeleteEntry2(SyHashEntry *pEntry)
{
	SyHashEntry_Pr *pPtr;
	sxi32 rc;
#if defined(UNTRUST)
	if( INVALID_HASH(pHash) || SyMemBackendPoolValidChunk(pHash->pAllocator,pEntry) == FALSE  ){
		return SXERR_CORRUPT;
	}
#endif
	pPtr = (SyHashEntry_Pr *)pEntry;
	rc = HashDeleteEntry(pPtr->pHash,pPtr,0);
	return rc;
}
static SyHashEntry * SyHashGetNextEntry(SyHash *pHash)
{
	SyHashEntry_Pr *pEntry;
#if defined(UNTRUST)
	if( INVALID_HASH(pHash) ){
		return 0;
	}
#endif
	if( pHash->pCurrent == 0 || pHash->nEntry <= 0 ){
		pHash->pCurrent = pHash->pList;
		return 0;
	}
	pEntry = pHash->pCurrent;
	/* Advance the cursor */
	pHash->pCurrent = pEntry->pNext;
	/* Return the current entry */
	return (SyHashEntry *)pEntry;
}
static sxi32 SyHashResetLoopCursor(SyHash *pHash)
{
#if defined(UNTRUST)
	if( INVALID_HASH(pHash)  ){
		return SXERR_CORRUPT;
	}
#endif
	pHash->pCurrent = pHash->pList;
	return SXRET_OK;
}
static sxi32 HashGrowTable(SyHash *pHash)
{
	sxu32 nNewSize = pHash->nBucketSize * 2;
	SyHashEntry_Pr *pEntry;
	SyHashEntry_Pr **apNew;
	sxu32 n,iBucket;

	/* Allocate a new larger table */
	apNew = (SyHashEntry_Pr **)SyMemBackendAlloc(pHash->pAllocator,nNewSize * sizeof(SyHashEntry_Pr *));
	if( apNew == 0 ){
		/* Not so fatal,simply a performance hit */
		return SXRET_OK;
	}
	/* Zero the new table */
	SyZero((void *)apNew,nNewSize * sizeof(SyHashEntry_Pr *));
	/* Rehash all entries */
	for( n = 0,pEntry = pHash->pList; n < pHash->nEntry ; n++  ){
		pEntry->pNextCollide = pEntry->pPrevCollide = 0;
		/* Install in the new bucket */
		iBucket = pEntry->nHash & (nNewSize - 1);
		pEntry->pNextCollide = apNew[iBucket];
		if( apNew[iBucket] != 0 ){
			apNew[iBucket]->pPrevCollide = pEntry;
		}
		apNew[iBucket] = pEntry;
		/* Point to the next entry */
		pEntry = pEntry->pNext;
	}
	/* Release the old table and reflect the change */
	SyMemBackendFree(pHash->pAllocator,(void *)pHash->apBucket);
	pHash->apBucket = apNew;
	pHash->nBucketSize = nNewSize;
	return SXRET_OK;
}
static sxi32 HashInsert(SyHash *pHash,SyHashEntry_Pr *pEntry)
{
	sxu32 iBucket = pEntry->nHash & (pHash->nBucketSize - 1);
	/* Insert the entry in its corresponding bcuket */
	pEntry->pNextCollide = pHash->apBucket[iBucket];
	if( pHash->apBucket[iBucket] != 0 ){
		pHash->apBucket[iBucket]->pPrevCollide = pEntry;
	}
	pHash->apBucket[iBucket] = pEntry;
	/* Link to the entry list */
	MACRO_LD_PUSH(pHash->pList,pEntry);
	if( pHash->nEntry == 0 ){
		pHash->pCurrent = pHash->pList;
	}
	pHash->nEntry++;
	return SXRET_OK;
}
static sxi32 HashTailInsert(SyHash *pHash,SyHashEntry_Pr *pEntry)
{
	SyHashEntry_Pr *pBucket;
	sxu32 iBucket;
	
	iBucket = pEntry->nHash & (pHash->nBucketSize - 1);
	pBucket = pHash->apBucket[iBucket];
	if( pBucket == 0 ){
		pHash->apBucket[iBucket] = pEntry;
	}else{
		/* Tail insert */
		while( pBucket->pNextCollide != 0 ){
			pBucket = pBucket->pNextCollide;
		}
		pBucket->pNextCollide = pEntry;
		pEntry->pPrevCollide = pBucket;
	}
	/* Link to the entry list */
	MACRO_LD_PUSH(pHash->pList,pEntry);
	if( pHash->nEntry == 0 ){
		pHash->pCurrent = pHash->pList;
	}
	pHash->nEntry++;
	return SXRET_OK;
}
static sxi32 SyHashInsert(SyHash *pHash,const void *pKey,sxu32 nKeyLen,void *pUserData)
{
	SyHashEntry_Pr *pEntry;
	sxi32 rc;
#if defined(UNTRUST)
	if( INVALID_HASH(pHash) || pKey == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	if( pHash->nEntry >= pHash->nBucketSize * SXHASH_FILL_FACTOR ){
		rc = HashGrowTable(&(*pHash));
		if( rc != SXRET_OK ){
			return rc;
		}
	}
	/* Allocate a new hash entry */
	pEntry = (SyHashEntry_Pr *)SyMemBackendPoolAlloc(pHash->pAllocator,sizeof(SyHashEntry_Pr));
	if( pEntry == 0 ){
		return SXERR_MEM;
	}
	/* Zero the entry */
	SyZero(pEntry,sizeof(SyHashEntry_Pr));
	pEntry->pHash = pHash;
	pEntry->pKey = pKey;
	pEntry->nKeyLen = nKeyLen;
	if( pEntry->nKeyLen <= 0 ){
		pEntry->nKeyLen = (sxu32)SyBlobLen(pKey,0);
	}
	pEntry->pUserData = pUserData;
	pEntry->nHash = pHash->xHash(pEntry->pKey,pEntry->nKeyLen);
	/* Finally insert the entry in its corresponding bucket */
	rc = HashInsert(&(*pHash),pEntry);
	return rc;
}
static sxi32 SyHashTailInsert(SyHash *pHash,const void *pKey,sxu32 nKeyLen,void *pUserData)
{
	SyHashEntry_Pr *pEntry;
	sxi32 rc;
#if defined(UNTRUST)
	if( INVALID_HASH(pHash) || pKey == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	if( pHash->nEntry >= pHash->nBucketSize * SXHASH_FILL_FACTOR ){
		rc = HashGrowTable(&(*pHash));
		if( rc != SXRET_OK ){
			return rc;
		}
	}
	/* Allocate a new hash entry */
	pEntry = (SyHashEntry_Pr *)SyMemBackendPoolAlloc(pHash->pAllocator,sizeof(SyHashEntry_Pr));
	if( pEntry == 0 ){
		return SXERR_MEM;
	}
	/* Zero the entry */
	SyZero(pEntry,sizeof(SyHashEntry_Pr));
	pEntry->pHash = pHash;
	pEntry->pKey = pKey;
	pEntry->nKeyLen = nKeyLen;
	if( pEntry->nKeyLen <= 0 ){
		pEntry->nKeyLen = (sxu32)SyBlobLen(pKey,0);
	}
	pEntry->pUserData = pUserData;
	pEntry->nHash = pHash->xHash(pEntry->pKey,pEntry->nKeyLen);
	/* Finally insert the entry in its corresponding bucket */
	rc = HashTailInsert(&(*pHash),pEntry);
	return rc;
}
/* SyRunTimeApi: sxfmt.c */
#define SXFMT_BUFSIZ 1024 /* Conversion buffer size */
/*
** Conversion types fall into various categories as defined by the
** following enumeration.
*/
#define SXFMT_RADIX       1 /* Integer types.%d, %x, %o, and so forth */
#define SXFMT_FLOAT       2 /* Floating point.%f */
#define SXFMT_EXP         3 /* Exponentional notation.%e and %E */
#define SXFMT_GENERIC     4 /* Floating or exponential, depending on exponent.%g */
#define SXFMT_SIZE        5 /* Total number of characters processed so far.%n */
#define SXFMT_STRING      6 /* Strings.%s */
#define SXFMT_PERCENT     7 /* Percent symbol.%% */
#define SXFMT_CHARX       8 /* Characters.%c */
#define SXFMT_ERROR       9 /* Used to indicate no such conversion type */
/* Extension by Symisc Systems */
#define SXFMT_BASE64     10 /* %b Base64 encoding and decoding */
#define SXFMT_HTML       11 /* %h Make input safe for HTML */
#define SXFMT_MD5        12 /* %m MD5 sum of a given input */
#define SXFMT_RAWSTR     13 /* %z Pointer to raw string (SyString *) */
#define SXFMT_OSERROR    14  /* Generate an strerror() like message */
#define SXFMT_UNUSED     15 
/*
** Allowed values for SyFmtInfo.flags
*/
#define SXFLAG_SIGNED	0x01
#define SXFLAG_UNSIGNED 0x02
/* Allowed values for SyFmtConsumer.nType */
#define SXFMT_CONS_PROC		1	/* Consumer is a procedure */
#define SXFMT_CONS_STR		2	/* Consumer is a managed string */
#define SXFMT_CONS_FILE		5	/* Consumer is an open File */
#define SXFMT_CONS_BLOB		6	/* Consumer is a BLOB */
/*
** Each builtin conversion character (ex: the 'd' in "%d") is described
** by an instance of the following structure
*/
typedef struct SyFmtInfo SyFmtInfo;
struct SyFmtInfo
{
  char fmttype;  /* The format field code letter [i.e: 'd','s','x'] */
  sxu8 base;     /* The base for radix conversion */
  int flags;    /* One or more of SXFLAG_ constants below */
  sxu8 type;     /* Conversion paradigm */
  char *charset; /* The character set for conversion */
  char *prefix;  /* Prefix on non-zero values in alt format */
};

typedef struct SyFmtConsumer SyFmtConsumer;
struct SyFmtConsumer
{
	sxsize nLen; /* Total output length */
	sxi32 nType; /* Type of the consumer see below */
	sxi32 rc;	/* Consumer return value;Abort processing if rc != SXRET_OK */
 union{
	struct{	
	ProcConsumer xUserConsumer;
	void *pUserData;
	}sFunc;  
	SyBlob *pBlob;
 }uConsumer;	
}; 
#ifndef SX_OMIT_FLOATINGPOINT
static int getdigit(sxlongreal *val,int *cnt)
{
  sxlongreal d;
  int digit;

  if( (*cnt)++ >= 16 ){
	  return '0';
  }
  digit = (int)*val;
  d = digit;
   *val = (*val - d)*10.0;
  return digit + '0' ;
}
#endif /* SX_OMIT_FLOATINGPOINT */
/*
 * The following routine was taken from the SQLITE2 source tree and was extended by symisc
 * systems to fit its need.
 * Status: Public Domain
 */
static sxi32 InternFormat(ProcConsumer xConsumer,void *pUserData,const char *zFormat,va_list ap)
{
	/*
	 * The following table is searched linearly, so it is good to put the most frequently
	 * used conversion types first.
	 */
static const SyFmtInfo aFmt[] = {
  {  'd', 10, SXFLAG_SIGNED, SXFMT_RADIX, "0123456789",0    },
  {  's',  0, 0, SXFMT_STRING,     0,                  0    },
  {  'c',  0, 0, SXFMT_CHARX,      0,                  0    },
  {  'x', 16, 0, SXFMT_RADIX,      "0123456789abcdef", "x0" },
  {  'X', 16, 0, SXFMT_RADIX,      "0123456789ABCDEF", "X0" },
         /* -- Extensions by Symisc Systems -- */
  {  'z',  0, 0, SXFMT_RAWSTR,     0,                   0   }, /* Pointer to a raw string (SyString *) */
  {  'b',  0, 0, SXFMT_BASE64,     0,                   0   }, /* Base64 Encoding and Decoding */
  {  'h',  0, 0, SXFMT_HTML,       0,                   0   }, /* Make input safe for HTML */
  {  'm',  0, 0, SXFMT_MD5,        0,                   0   }, /* MD5 sum */
         /* -- End of Extensions -- */
  {  'o',  8, 0, SXFMT_RADIX,      "01234567",         "0"  },
  {  'u', 10, 0, SXFMT_RADIX,      "0123456789",       0    },
#ifndef SX_OMIT_FLOATINGPOINT
  {  'f',  0, SXFLAG_SIGNED, SXFMT_FLOAT,       0,     0    },
  {  'e',  0, SXFLAG_SIGNED, SXFMT_EXP,        "e",    0    },
  {  'E',  0, SXFLAG_SIGNED, SXFMT_EXP,        "E",    0    },
  {  'g',  0, SXFLAG_SIGNED, SXFMT_GENERIC,    "e",    0    },
  {  'G',  0, SXFLAG_SIGNED, SXFMT_GENERIC,    "E",    0    },
#endif
  {  'i', 10, SXFLAG_SIGNED, SXFMT_RADIX,"0123456789", 0    },
  {  'n',  0, 0, SXFMT_SIZE,       0,                  0    },
  {  '%',  0, 0, SXFMT_PERCENT,    0,                  0    },
  {  'p', 10, 0, SXFMT_RADIX,      "0123456789",       0    }
};
  int c;                     /* Next character in the format string */
  char *bufpt;               /* Pointer to the conversion buffer */
  int precision;             /* Precision of the current field */
  int length;                /* Length of the field */
  int idx;                   /* A general purpose loop counter */
  int width;                 /* Width of the current field */
  sxu8 flag_leftjustify;   /* True if "-" flag is present */
  sxu8 flag_plussign;      /* True if "+" flag is present */
  sxu8 flag_blanksign;     /* True if " " flag is present */
  sxu8 flag_alternateform; /* True if "#" flag is present */
  sxu8 flag_zeropad;       /* True if field width constant starts with zero */
  sxu8 flag_long;          /* True if "l" flag is present */
  sxi64 longvalue;         /* Value for integer types */
  const SyFmtInfo *infop;  /* Pointer to the appropriate info structure */
  char buf[SXFMT_BUFSIZ];  /* Conversion buffer */
  char prefix;             /* Prefix character."+" or "-" or " " or '\0'.*/
  sxu8 errorflag = 0;      /* True if an error is encountered */
  sxu8 xtype;              /* Conversion paradigm */
  char *zExtra;    
  static char spaces[] = "                                                  ";
#define etSPACESIZE ((int)sizeof(spaces)-1)
#ifndef SX_OMIT_FLOATINGPOINT
  sxlongreal realvalue;    /* Value for real types */
  int  exp;                /* exponent of real numbers */
  double rounder;          /* Used for rounding floating point values */
  sxu8 flag_dp;            /* True if decimal point should be shown */
  sxu8 flag_rtz;           /* True if trailing zeros should be removed */
  sxu8 flag_exp;           /* True to force display of the exponent */
  int nsd;                 /* Number of significant digits returned */
#endif
  int rc;

  length = 0;
  bufpt = 0;
  for(; (c=(*zFormat))!=0; ++zFormat){
    if( c!='%' ){
      unsigned int amt;
      bufpt = (char *)zFormat;
      amt = 1;
      while( (c=(*++zFormat))!='%' && c!=0 ) amt++;
	  rc = xConsumer((const void *)bufpt,amt,pUserData);
	  if( rc != SXRET_OK ){
		  return SXERR_ABORT; /* Consumer routine request an operation abort */
	  }
      if( c==0 ){
		  return errorflag > 0 ? SXERR_FORMAT : SXRET_OK;
	  }
    }
    if( (c=(*++zFormat))==0 ){
      errorflag = 1;
	  rc = xConsumer("%",sizeof("%")-1,pUserData);
	  if( rc != SXRET_OK ){
		  return SXERR_ABORT; /* Consumer routine request an operation abort */
	  }
      return errorflag > 0 ? SXERR_FORMAT : SXRET_OK;
    }
    /* Find out what flags are present */
    flag_leftjustify = flag_plussign = flag_blanksign = 
     flag_alternateform = flag_zeropad = 0;
    do{
      switch( c ){
        case '-':   flag_leftjustify = 1;     c = 0;   break;
        case '+':   flag_plussign = 1;        c = 0;   break;
        case ' ':   flag_blanksign = 1;       c = 0;   break;
        case '#':   flag_alternateform = 1;   c = 0;   break;
        case '0':   flag_zeropad = 1;         c = 0;   break;
        default:                                       break;
      }
    }while( c==0 && (c=(*++zFormat))!=0 );
    /* Get the field width */
    width = 0;
    if( c=='*' ){
      width = va_arg(ap,int);
      if( width<0 ){
        flag_leftjustify = 1;
        width = -width;
      }
      c = *++zFormat;
    }else{
      while( c>='0' && c<='9' ){
        width = width*10 + c - '0';
        c = *++zFormat;
      }
    }
    if( width > SXFMT_BUFSIZ-10 ){
      width = SXFMT_BUFSIZ-10;
    }
    /* Get the precision */
	precision = -1;
    if( c=='.' ){
      precision = 0;
      c = *++zFormat;
      if( c=='*' ){
        precision = va_arg(ap,int);
        if( precision<0 ) precision = -precision;
        c = *++zFormat;
      }else{
        while( c>='0' && c<='9' ){
          precision = precision*10 + c - '0';
          c = *++zFormat;
        }
      }
    }
    /* Get the conversion type modifier */
	flag_long = 0;
    if( c=='l' || c == 'q' /* BSD quad (expect a 64-bit integer) */ ){
      flag_long = (c == 'q') ? 2 : 1;
      c = *++zFormat;
	  if( c == 'l' ){
		  /* Standard printf emulation 'lld' (expect a 64bit integer) */
		  flag_long = 2;
	  }
    }
    /* Fetch the info entry for the field */
    infop = 0;
    xtype = SXFMT_ERROR;
	for(idx=0; idx< (int)SX_ARRAYSIZE(aFmt); idx++){
      if( c==aFmt[idx].fmttype ){
        infop = &aFmt[idx];
		xtype = infop->type;
        break;
      }
    }
    zExtra = 0;

    /*
    ** At this point, variables are initialized as follows:
    **
    **   flag_alternateform          TRUE if a '#' is present.
    **   flag_plussign               TRUE if a '+' is present.
    **   flag_leftjustify            TRUE if a '-' is present or if the
    **                               field width was negative.
    **   flag_zeropad                TRUE if the width began with 0.
    **   flag_long                   TRUE if the letter 'l' (ell) or 'q'(BSD quad) prefixed
    **                               the conversion character.
    **   flag_blanksign              TRUE if a ' ' is present.
    **   width                       The specified field width.This is
    **                               always non-negative.Zero is the default.
    **   precision                   The specified precision.The default
    **                               is -1.
    **   xtype                       The class of the conversion.
    **   infop                       Pointer to the appropriate info struct.
    */
    switch( xtype ){
      case SXFMT_RADIX:
        if( flag_long > 0 ){
			if( flag_long > 1 ){
				/* BSD quad: expect a 64-bit integer */
				longvalue = va_arg(ap,sxi64);
			}else{
				longvalue = va_arg(ap,sxlong);
			}
		}else{
			if( infop->flags & SXFLAG_SIGNED ){
				longvalue = va_arg(ap,sxi32);
			}else{
				longvalue = va_arg(ap,sxu32);
			}
		}
		/* Limit the precision to prevent overflowing buf[] during conversion */
      if( precision>SXFMT_BUFSIZ-40 ) precision = SXFMT_BUFSIZ-40;
#if 1
        /* For the format %#x, the value zero is printed "0" not "0x0".
        ** I think this is stupid.*/
        if( longvalue==0 ) flag_alternateform = 0;
#else
        /* More sensible: turn off the prefix for octal (to prevent "00"),
        ** but leave the prefix for hex.*/
        if( longvalue==0 && infop->base==8 ) flag_alternateform = 0;
#endif
        if( infop->flags & SXFLAG_SIGNED ){
          if( longvalue<0 ){ 
            longvalue = -longvalue;
			/* Ticket 1433-003 */
			if( longvalue < 0 ){
				longvalue--;
			}
            prefix = '-';
          }else if( flag_plussign )  prefix = '+';
          else if( flag_blanksign )  prefix = ' ';
          else                       prefix = 0;
        }else                        prefix = 0;
        if( flag_zeropad && precision<width-(prefix!=0) ){
          precision = width-(prefix!=0);
        }
        bufpt = &buf[SXFMT_BUFSIZ-1];
        {
          register char *cset;      /* Use registers for speed */
          register int base;
          cset = infop->charset;
          base = infop->base;
          do{                                           /* Convert to ascii */
            *(--bufpt) = cset[longvalue%base];
            longvalue = longvalue/base;
          }while( longvalue>0 );
        }
        length = &buf[SXFMT_BUFSIZ-1]-bufpt;
        for(idx=precision-length; idx>0; idx--){
          *(--bufpt) = '0';                             /* Zero pad */
        }
        if( prefix ) *(--bufpt) = prefix;               /* Add sign */
        if( flag_alternateform && infop->prefix ){      /* Add "0" or "0x" */
          char *pre, x;
          pre = infop->prefix;
          if( *bufpt!=pre[0] ){
            for(pre=infop->prefix; (x=(*pre))!=0; pre++) *(--bufpt) = x;
          }
        }
        length = &buf[SXFMT_BUFSIZ-1]-bufpt;
        break;
      case SXFMT_FLOAT:
      case SXFMT_EXP:
      case SXFMT_GENERIC:
#ifndef SX_OMIT_FLOATINGPOINT
		realvalue = va_arg(ap,double);
        if( precision<0 ) precision = 6;         /* Set default precision */
        if( precision>SXFMT_BUFSIZ-40) precision = SXFMT_BUFSIZ-40;
        if( realvalue<0.0 ){
          realvalue = -realvalue;
          prefix = '-';
        }else{
          if( flag_plussign )          prefix = '+';
          else if( flag_blanksign )    prefix = ' ';
          else                         prefix = 0;
        }
        if( infop->type==SXFMT_GENERIC && precision>0 ) precision--;
        rounder = 0.0;
#if 0
        /* Rounding works like BSD when the constant 0.4999 is used.Wierd! */
        for(idx=precision, rounder=0.4999; idx>0; idx--, rounder*=0.1);
#else
        /* It makes more sense to use 0.5 */
        for(idx=precision, rounder=0.5; idx>0; idx--, rounder*=0.1);
#endif
        if( infop->type==SXFMT_FLOAT ) realvalue += rounder;
        /* Normalize realvalue to within 10.0 > realvalue >= 1.0 */
        exp = 0;
        if( realvalue>0.0 ){
          while( realvalue>=1e8 && exp<=350 ){ realvalue *= 1e-8; exp+=8; }
          while( realvalue>=10.0 && exp<=350 ){ realvalue *= 0.1; exp++; }
          while( realvalue<1e-8 && exp>=-350 ){ realvalue *= 1e8; exp-=8; }
          while( realvalue<1.0 && exp>=-350 ){ realvalue *= 10.0; exp--; }
          if( exp>350 || exp<-350 ){
            bufpt = "NaN";
            length = 3;
            break;
          }
        }
        bufpt = buf;
        /*
        ** If the field type is etGENERIC, then convert to either etEXP
        ** or etFLOAT, as appropriate.
        */
        flag_exp = xtype==SXFMT_EXP;
        if( xtype!=SXFMT_FLOAT ){
          realvalue += rounder;
          if( realvalue>=10.0 ){ realvalue *= 0.1; exp++; }
        }
        if( xtype==SXFMT_GENERIC ){
          flag_rtz = !flag_alternateform;
          if( exp<-4 || exp>precision ){
            xtype = SXFMT_EXP;
          }else{
            precision = precision - exp;
            xtype = SXFMT_FLOAT;
          }
        }else{
          flag_rtz = 0;
        }
        /*
        ** The "exp+precision" test causes output to be of type etEXP if
        ** the precision is too large to fit in buf[].
        */
        nsd = 0;
        if( xtype==SXFMT_FLOAT && exp+precision<SXFMT_BUFSIZ-30 ){
          flag_dp = (precision>0 || flag_alternateform);
          if( prefix ) *(bufpt++) = prefix;         /* Sign */
          if( exp<0 )  *(bufpt++) = '0';            /* Digits before "." */
          else for(; exp>=0; exp--) *(bufpt++) = (char)getdigit(&realvalue,&nsd);
          if( flag_dp ) *(bufpt++) = '.';           /* The decimal point */
          for(exp++; exp<0 && precision>0; precision--, exp++){
            *(bufpt++) = '0';
          }
          while( (precision--)>0 ) *(bufpt++) = (char)getdigit(&realvalue,&nsd);
          *(bufpt--) = 0;                           /* Null terminate */
          if( flag_rtz && flag_dp ){     /* Remove trailing zeros and "." */
            while( bufpt>=buf && *bufpt=='0' ) *(bufpt--) = 0;
            if( bufpt>=buf && *bufpt=='.' ) *(bufpt--) = 0;
          }
          bufpt++;                            /* point to next free slot */
        }else{    /* etEXP or etGENERIC */
          flag_dp = (precision>0 || flag_alternateform);
          if( prefix ) *(bufpt++) = prefix;   /* Sign */
          *(bufpt++) = (char)getdigit(&realvalue,&nsd);  /* First digit */
          if( flag_dp ) *(bufpt++) = '.';     /* Decimal point */
          while( (precision--)>0 ) *(bufpt++) = (char)getdigit(&realvalue,&nsd);
          bufpt--;                            /* point to last digit */
          if( flag_rtz && flag_dp ){          /* Remove tail zeros */
            while( bufpt>=buf && *bufpt=='0' ) *(bufpt--) = 0;
            if( bufpt>=buf && *bufpt=='.' ) *(bufpt--) = 0;
          }
          bufpt++;                            /* point to next free slot */
          if( exp || flag_exp ){
            *(bufpt++) = infop->charset[0];
            if( exp<0 ){ *(bufpt++) = '-'; exp = -exp; } /* sign of exp */
            else       { *(bufpt++) = '+'; }
            if( exp>=100 ){
              *(bufpt++) = (char)((exp/100)+'0');                /* 100's digit */
              exp %= 100;
            }
            *(bufpt++) = (char)(exp/10+'0');                     /* 10's digit */
            *(bufpt++) = (char)(exp%10+'0');                     /* 1's digit */
          }
        }
        /* The converted number is in buf[] and zero terminated.Output it.
        ** Note that the number is in the usual order, not reversed as with
        ** integer conversions.*/
        length = bufpt-buf;
        bufpt = buf;

        /* Special case:  Add leading zeros if the flag_zeropad flag is
        ** set and we are not left justified */
        if( flag_zeropad && !flag_leftjustify && length < width){
          int i;
          int nPad = width - length;
          for(i=width; i>=nPad; i--){
            bufpt[i] = bufpt[i-nPad];
          }
          i = prefix!=0;
          while( nPad-- ) bufpt[i++] = '0';
          length = width;
        }
#else
         bufpt = " ";
		 length = (int)sizeof(" ") - 1;
#endif /* SX_OMIT_FLOATINGPOINT */
        break;
      case SXFMT_SIZE:{
		 int *pSize = va_arg(ap,int *);
		 *pSize = ((SyFmtConsumer *)pUserData)->nLen;
		 length = width = 0;
					  }
        break;
      case SXFMT_PERCENT:
        buf[0] = '%';
        bufpt = buf;
        length = 1;
        break;
      case SXFMT_CHARX:
        c = va_arg(ap,int);
		buf[0] = (char)c;
		/* Limit the precision to prevent overflowing buf[] during conversion */
		if( precision>SXFMT_BUFSIZ-40 ) precision = SXFMT_BUFSIZ-40;
        if( precision>=0 ){
          for(idx=1; idx<precision; idx++) buf[idx] = (char)c;
          length = precision;
        }else{
          length =1;
        }
        bufpt = buf;
        break;
      case SXFMT_STRING:
        bufpt = va_arg(ap,char*);
        if( bufpt==0 ){
          bufpt = " ";
		  length = (int)sizeof(" ")-1;
		  break;
        }
		length = precision;
		if( precision < 0 ){
			/* Symisc extension */
			length = (int)SyStrlen(bufpt);
		}
        if( precision>=0 && precision<length ) length = precision;
        break;
	  case SXFMT_BASE64:
		/* Symisc extension */
		bufpt = va_arg(ap,char*);
        if( bufpt==0 ){
          bufpt = " ";
		  length = (int)sizeof(" ")-1;
		  break;
        }
		length = precision;
		if( precision < 0 ){
			length = (int)SyStrlen(bufpt);
		}
        if( precision>=0 && precision<length ){
			length = precision;
		}
		if( !flag_leftjustify ){
			/* Base64 Encoding */
			SyBase64Encode(bufpt,(sxsize)length,xConsumer,pUserData);
		}else{
			/* Base64 Decoding */
			SyBase64Decode(bufpt,(sxsize)length,xConsumer,pUserData);
		}
		length = 0;
		flag_leftjustify = 0;
		break;
	  case SXFMT_HTML:
		  /* Symisc extension */
		bufpt = va_arg(ap,char*);
        if( bufpt==0 ){
          bufpt = " ";
		  length = (int)sizeof(" ")-1;
		  break;
        }
		length = precision;
		if( precision < 0 ){
			length = (int)SyStrlen(bufpt);
		}
        if( precision>=0 && precision<length ){
			length = precision;
		}
		if( !flag_leftjustify ){
			/* Escape HTML */
			SyHtmlEscape(bufpt,(sxsize)length,xConsumer,pUserData);
		}else{
			/* Unescape HTML */
			SyHtmlUnescape(bufpt,(sxsize)length,xConsumer,pUserData);
		}
		length = 0;
		flag_leftjustify = 0;
		break;
	  case SXFMT_MD5: {
		  /* Symisc extension */
		unsigned char zDigest[16];
		bufpt = va_arg(ap,char*);
        if( bufpt==0 ){
          bufpt = " ";
		  length = (int)sizeof(" ")-1;
		  break;
        }
		length = precision;
		if( precision < 0 ){
			length = (int)SyStrlen(bufpt);
		}
        if( precision>=0 && precision<length ){
			length = precision;
		}
		SyMD5ComputeSum((const void *)bufpt,(sxsize)length,zDigest,sizeof(zDigest));
		/* Hexify the MD5 digest */
		length = SXFMT_BUFSIZ;
		SyBinToHexString((const void *)zDigest,sizeof(zDigest),buf,(sxsize *)&length);
		bufpt = buf;
		break;
					  }
	case SXFMT_RAWSTR:{
		/* Symisc extension */
		SyString *pStr = va_arg(ap,SyString *);
		if( pStr == 0 || pStr->zString == 0 ){
			 bufpt = " ";
		     length = (int)sizeof(" ")-1;
		     break;
		}
		bufpt = (char *)pStr->zString;
		if( pStr->nByte <= 0 ){
			/* Compute the length automatically */
			pStr->nByte = (sxu32)SyBlobLen(pStr->zString,&pStr->zString[1024]);
		}
		length = (int)pStr->nByte;
		break;
					  }
      case SXFMT_ERROR:
        buf[0] = '%';
        buf[1] = (char)c;
        errorflag = 0;
        idx = 1+(c!=0);
		rc = xConsumer("%",(unsigned int)idx,pUserData);
		if( rc != SXRET_OK ){
		  return SXERR_ABORT; /* Consumer routine request an operation abort */
		}
        if( c==0 ) zFormat--;
        break;
    }/* End switch over the format type */
    /*
    ** The text of the conversion is pointed to by "bufpt" and is
    ** "length" characters long.The field width is "width".Do
    ** the output.
    */
    if( !flag_leftjustify ){
      register int nspace;
      nspace = width-length;
      if( nspace>0 ){
        while( nspace>=etSPACESIZE ){
			rc = xConsumer(spaces,etSPACESIZE,pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT; /* Consumer routine request an operation abort */
			}
			nspace -= etSPACESIZE;
        }
        if( nspace>0 ){
			rc = xConsumer(spaces,(unsigned int)nspace,pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT; /* Consumer routine request an operation abort */
			}
		}
      }
    }
    if( length>0 ){
		rc = xConsumer(bufpt,(unsigned int)length,pUserData);
		if( rc != SXRET_OK ){
		  return SXERR_ABORT; /* Consumer routine request an operation abort */
		}
    }
    if( flag_leftjustify ){
      register int nspace;
      nspace = width-length;
      if( nspace>0 ){
        while( nspace>=etSPACESIZE ){
			rc = xConsumer(spaces,etSPACESIZE,pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT; /* Consumer routine request an operation abort */
			}
			nspace -= etSPACESIZE;
        }
        if( nspace>0 ){
			rc = xConsumer(spaces,(unsigned int)nspace,pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT; /* Consumer routine request an operation abort */
			}
		}
      }
    }
  }/* End for loop over the format string */
  return errorflag ? SXERR_FORMAT : SXRET_OK;
} 
/* ENDOF SQLITE CODE */
static sxi32 FormatConsumer(const void *pSrc,unsigned int nLen,void *pData)
{
	SyFmtConsumer *pConsumer = (SyFmtConsumer *)pData;
	sxi32 rc = SXERR_ABORT;
	switch(pConsumer->nType){
		case SXFMT_CONS_BLOB:
			/* Blob consumer */
			rc = SyBlobAppend(pConsumer->uConsumer.pBlob,pSrc,(sxsize)nLen);
			break;
		default: 
			/* Unknown consumer */
			break;
	}
	/* Update total number of bytes consumed so far */
	pConsumer->nLen += nLen;
	pConsumer->rc = rc;
	return rc;	
}
static sxi32 FormatMount(sxi32 nType,void *pConsumer,ProcConsumer xUserCons,void *pUserData,sxsize *pOutLen,const char *zFormat,va_list ap)
{
	SyFmtConsumer sCons;

	sCons.nType = nType;
	sCons.rc = SXRET_OK;
	sCons.nLen = 0;
	SXUNUSED(xUserCons); /* Prevent compiler warning */
	SXUNUSED(pUserData);
	if( pOutLen ){
		*pOutLen = 0;
	}
	switch(nType){
		case SXFMT_CONS_BLOB:
			sCons.uConsumer.pBlob = (SyBlob *)pConsumer;
			break;
		default: 
			return SXERR_UNKNOWN;
	}
	InternFormat(FormatConsumer,&sCons,zFormat,ap); 
	if( pOutLen ){
		*pOutLen = sCons.nLen;
	}
	return sCons.rc;
}
static sxsize SyBlobFormat(SyBlob *pBlob,const char *zFormat,...)
{
	va_list ap;
	sxsize n;
#if defined(UNTRUST)	
	if( SX_EMPTY_STR(zFormat) ){
		return 0;
	}
#endif			
	va_start(ap,zFormat);
	FormatMount(SXFMT_CONS_BLOB,&(*pBlob),0,0,&n,zFormat,ap);
	va_end(ap);
	return n;
}
static sxsize SyBlobFormatAp(SyBlob *pBlob,const char *zFormat,va_list ap)
{
	sxsize n;
#if defined(UNTRUST)	
	if( SX_EMPTY_STR(zFormat) ){
		return 0;
	}
#endif	
	FormatMount(SXFMT_CONS_BLOB,&(*pBlob),0,0,&n,zFormat,ap);
	return n;
}
static sxsize SyBufferFormatAp(char *zBuf,sxsize nLen,const char *zFormat,va_list ap)
{
	SyBlob sBlob;
	sxsize n;
#if defined(UNTRUST)	
	if( SX_EMPTY_STR(zFormat) ){
		return 0;
	}
#endif	
	if( SXRET_OK != SyBlobInitFromBuf(&sBlob,zBuf,nLen - 1) ){
		return 0;
	}
	FormatMount(SXFMT_CONS_BLOB,&sBlob,0,0,0,zFormat,ap);
	n = SyBlobLength(&sBlob);
	/* Append the null terminator */
	sBlob.mByte++;
	SyBlobAppend(&sBlob,"\0",sizeof(char));
	return n;
}
#ifndef XPP_OMIT_BUILTIN
/* SyRunTimeApi: sxfmt.c */
static sxsize SyBufferFormat(char *zBuf,sxsize nLen,const char *zFormat,...)
{
	SyBlob sBlob;
	va_list ap;
	sxsize n;
#if defined(UNTRUST)	
	if( SX_EMPTY_STR(zFormat) ){
		return 0;
	}
#endif	
	if( SXRET_OK != SyBlobInitFromBuf(&sBlob,zBuf,nLen - 1) ){
		return 0;
	}		
	va_start(ap,zFormat);
	FormatMount(SXFMT_CONS_BLOB,&sBlob,0,0,0,zFormat,ap);
	va_end(ap);
	n = SyBlobLength(&sBlob);
	/* Append the null terminator */
	sBlob.mByte++;
	SyBlobAppend(&sBlob,"\0",sizeof(char));
	return n;
}
/* SyRunTimeApi: sxlib.c */
static const char *zEngDay[] = { 
	"Sunday","Monday","Tuesday","Wednesday",
	"Thursday","Friday","Saturday"
};
static const char *zEngMonth[] = {
	"January","February","March","April",
	"May","June","July","August",
	"September","October","November","December"
};
static const char * GetDay(sxi32 i)
{
	return zEngDay[ i % 7 ];
}
static const char * GetMonth(sxi32 i)
{
	return zEngMonth[ i % 12 ];
}
static const char * SyTimeGetDay(sxi32 iDay)
{
	return GetDay(iDay);
}
static const char * SyTimeGetMonth(sxi32 iMonth)
{
	return GetMonth(iMonth);
}
#define SAFE_HTTP(C)	(SyisAlphaNum(c) || c == '_' || c == '-' || c == '$' || c == '.' )
static sxi32 SyUriEncode(const char *zSrc,sxsize nLen,ProcConsumer xConsumer,void *pUserData)
{
	unsigned char *zIn = (unsigned char *)zSrc;
	unsigned char zHex[3] = { '%',0,0 };
	unsigned char zOut[2];
	unsigned char *zCur,*zEnd;
	sxi32 c;
	sxi32 rc;
		
#ifdef UNTRUST
	if( SX_EMPTY_STR(zSrc) || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif
	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}
	rc = SXRET_OK;
	zEnd = &zIn[nLen]; zCur = zIn;
	for(;;){
		if( zCur >= zEnd ){
			if( zCur != zIn ){
				rc = xConsumer(zIn,(sxsize)(zCur-zIn),pUserData);
			}
			break;
		}
		c = zCur[0];
		if( SAFE_HTTP(c) ){
			zCur++; continue;
		}
		if( zCur != zIn && SXRET_OK != (rc = xConsumer(zIn,(sxsize)(zCur-zIn),pUserData))){
			break;
		}		
		if( c == ' ' ){
			zOut[0] = '+';
			rc = xConsumer((const void *)zOut,sizeof(unsigned char),pUserData);
		}else{
			zHex[1]	= "0123456789ABCDEF"[(c >> 4) & 0x0F];
			zHex[2] = "0123456789ABCDEF"[c & 0x0F];
			rc = xConsumer(zHex,sizeof(zHex),pUserData);
		}
		if( SXRET_OK != rc ){
			break;
		}				
		zIn = &zCur[1]; zCur = zIn ;
	}
	return rc == SXRET_OK ? SXRET_OK : SXERR_ABORT;
}
static sxi32 SyUriDecode(const char *zSrc,sxsize nLen,ProcConsumer xConsumer,void *pUserData,sxu8 bUTF8)
{
	static const sxu8 Utf8Trans[] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
		0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
		0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x00, 0x01, 0x02, 0x03, 0x00, 0x01, 0x00, 0x00
	};
	const char *zIn = zSrc;
	const char *zEnd;
	const char *zCur;
	sxu8 *zOutPtr;
	sxu8 zOut[10];
	sxi32 c,d;
	sxi32 rc;

#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif

	if( nLen <= 0 ){
		nLen = SyStrlen(zSrc);
	}
	rc = SXRET_OK;
	zEnd = &zSrc[nLen];
	zCur = zIn;
	for(;;){
		while(zCur < zEnd && zCur[0] != '%' && zCur[0] != '+' ){
			zCur++;
		}
		if( zCur != zIn ){
			/* Consume input */
			rc = xConsumer(zIn,(unsigned int)(zCur-zIn),pUserData);
			if( rc != SXRET_OK ){
				/* User consumer routine request an operation abort */
				break;
			}
		}
		if( zCur >= zEnd ){
			rc = SXRET_OK;
			break;
		}
		/* Decode unsafe HTTP characters */
		zOutPtr = zOut;
		if( zCur[0] == '+' ){
			*zOutPtr++ = ' ';
			zCur++;
		}else{
			if( &zCur[2] >= zEnd ){
				rc = SXERR_OVERFLOW;
				break;
			}
			c = (SyAsciiToHex(zCur[1]) <<4) | SyAsciiToHex(zCur[2]);
			zCur += 3;
			if( c < 0x000C0 ){
				*zOutPtr++ = (sxu8)c;
			}else{
				c = Utf8Trans[c-0xC0];
				while( zCur[0] == '%' ){
					d = (SyAsciiToHex(zCur[1]) <<4) | SyAsciiToHex(zCur[2]);
					if( (d&0xC0) != 0x80 ){
						break;
					}
					c = (c<<6) + (0x3f & d);
					zCur += 3;
				}
				if( bUTF8 == FALSE ){
					*zOutPtr++ = (sxu8)c;
				}else{
					SX_WRITE_UTF8(zOutPtr,c);
				}
			}
			
		}
		/* Consume the decoded characters */
		rc = xConsumer((const void *)zOut,(unsigned int)(zOutPtr-zOut),pUserData);
		if( rc != SXRET_OK ){
			break;
		}
		/* Synchronize pointers */
		zIn = zCur;
	}
	return rc;
}
/* SyRunTimeApi: sxutils.c */
static sxsize SySizeFormat(char *zBuf,sxsize nBufLen,sxi64 iSize)
{
	                             /*Kilo*/ /*Mega*/ /*Giga*/ /*Tera*/ /*Peta*/ /*Exa*/ /*Zeta*/
	static const char zUnit[] = {"KMGTPEZ"};
	sxi32 nRest,i_32;
	int c = -1; /* index in zUnit[] */
#if defined(UNTRUST)
	if( zBuf == 0 || iSize <= 0 ){
		return 0;
	}
#endif
	if( iSize < 100 /* Bytes */ ){
		/* Don't bother formatting,return immediately */
		return Systrcpy(zBuf,nBufLen,"0.1 KB",sizeof("0.1 KB")-1);
	}
	for(;;){
		nRest = (sxi32)(iSize & 0x3FF); 
		iSize >>= 10;
		c++;
		if( (iSize & (~0 ^ 1023)) == 0 ){
			break;
		}
	}
	nRest /= 100;
	if( nRest > 9 ){
		nRest = 9;
	}
	if( iSize > 999 ){
		c++;
		nRest = 9;
		iSize = 0;
	}
	i_32 = (sxi32)iSize;
	/* Format the size  */
	nBufLen = SyBufferFormat(zBuf,nBufLen,"%d.%d %cB",i_32,nRest,zUnit[c]);
	return nBufLen;
}
static sxi32 SyBinToHexConsumer(const void *pIn,sxsize nLen,ProcConsumer xConsumer,void *pConsumerData)
{
	static const unsigned char zHexTab[] = "0123456789abcdef";
	const unsigned char *zIn,*zEnd;
	unsigned char zOut[3];
	sxi32 rc;
#if defined(UNTRUST)
	if( pIn == 0 || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif
	zIn   = (const unsigned char *)pIn;
	zEnd  = &zIn[nLen];

	for(;;){
		if( zIn >= zEnd  ){
			break;
		}
		zOut[0] = zHexTab[zIn[0] >> 4];  zOut[1] = zHexTab[zIn[0] & 0x0F];
		rc = xConsumer((const void *)zOut,sizeof(char)*2,pConsumerData);
		if( rc != SXRET_OK ){
			return rc;
		}
		zIn++; 
	}
	return SXRET_OK;
}
static const sxu32 crc32_table[] = {
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
	0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
	0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
	0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
	0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
	0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
	0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
	0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
	0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
	0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
	0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
	0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
	0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
	0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
	0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
	0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
	0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
	0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
	0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
	0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
	0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
	0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
	0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
	0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
	0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
	0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
	0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
	0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
	0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
	0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
	0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
	0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
	0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
	0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
	0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
	0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
	0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
	0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
	0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
	0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
	0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d,
};
#define CRC32C(c,d) (c = ( crc32_table[(c ^ (d)) & 0xFF] ^ (c>>8) ) )
static sxu32 SyCrc32Update(sxu32 crc32,const void *pSrc,sxsize nLen)
{
	register unsigned char *zIn = (unsigned char *)pSrc;
	unsigned char *zEnd;
	if( zIn == 0 ){
		return crc32;
	}
	zEnd = &zIn[nLen];
	for(;;){
		if(zIn >= zEnd ){ break; } CRC32C(crc32,zIn[0]); zIn++;
		if(zIn >= zEnd ){ break; } CRC32C(crc32,zIn[0]); zIn++;
		if(zIn >= zEnd ){ break; } CRC32C(crc32,zIn[0]); zIn++;
		if(zIn >= zEnd ){ break; } CRC32C(crc32,zIn[0]); zIn++;
	}
		
	return crc32;
}
static sxu32 SyCrc32(const void *pSrc,sxsize nLen)
{
	return SyCrc32Update(SXU32_HIGH,pSrc,nLen);
}
#endif /* XPP_OMIT_BUILTIN */
/* END-OF-IMPLEMENTATION: xpp@embedded@symisc 310-19-46 */
/* 
 * Symisc xPP: An embeddable general purpose macro processor.
 * Copyright (C) 2011,Symisc Systems http://xpp.symisc.net/
 * Version 2.6.1432
 * For information on licensing,redistribution of this file,and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://www.symisc.net
 */
