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
