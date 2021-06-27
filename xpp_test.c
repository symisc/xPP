/*
 * xPP usage sample.
 * ID: 45781-5626-52124
 * Copyright (C) Symisc Systems 2011, http://www.symisc.net/
 */
 /* $SymiscID: xpp_test.c v9.32.21.236 FreeBSD 2011-10-08 02:27 <devel@symisc.net> */

#include <stdio.h>
#include <stdlib.h>
#include "xpp.h"
#ifdef __WINNT__
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif
xpp * xpp_export_cpp(void)
{
	xpp *pCpp;
	int rc;
	/* Create a macro processor instance first */
	rc = xpp_init(&pCpp);
	if( rc != XPP_OK ){
		return 0;
	}
	/* Emulate the C Pre-Processor style */
	xpp_config(pCpp,XPP_CONFIG_COMMENT,"/*","*/"); /* C style comment */
	xpp_config(pCpp,XPP_CONFIG_COMMENT,"//","\n"); /* C++ style comment */
	xpp_config(pCpp,XPP_CONFIG_STRING_DELIMITER,"\"","\""); /* Constant litteral string are not expanded but processed
															 * for escape sequences */
	xpp_config(pCpp,XPP_CONFIG_STRING_DELIMITER,"'","'");
#ifdef __UNIXES__
	/* Register some known include path */
	xpp_config(pCpp,XPP_CONFIG_IMPORT_PATH,"/usr/include");
	xpp_config(pCpp,XPP_CONFIG_IMPORT_PATH,"/usr/local/include");
#endif
	/* Macro definition prefix */
	//xpp_config(pCpp,XPP_CONFIG_MACRO_PREFIX,"#");
	/* Stringing operator */
	xpp_config(pCpp,XPP_CONFIG_STRINGING_OPERATOR,"#");
	/* Rename some built-in macro to their equivalent in the C world */
	xpp_rename_macro(pCpp,"TIME","__TIME__");
	xpp_rename_macro(pCpp,"DATE","__DATE__");
	xpp_rename_macro(pCpp,"ISO_DATE","__ISO_DATE__");
	xpp_rename_macro(pCpp,"TIMESTAMP","__TIMESTAMP__");
	xpp_rename_macro(pCpp,"FILE","__FILE__");
	xpp_rename_macro(pCpp,"FILENAME","__FILENAME__");
	xpp_rename_macro(pCpp,"LINE","__LINE__");
	xpp_rename_macro(pCpp,"ERROR","error");
	/* Ready to emulate the C pre-processor */
	return pCpp;
}
#ifdef __WINNT__
#include <Windows.h>
#else

#endif
/* Output consumer routine */
static int Consumer(const void *pData,unsigned int nLen,void *pUserdata)
{
	/* TICKET: 9854-62 */
	const char *zOut = (const char *)pData;
pUserdata = 0;
	/* Redirect to stdout */
	printf("%.*s",nLen,zOut);
	return XPP_OK;
}
/* Output consumer routine2 */
static int Consumer2(const void *pData,unsigned int nLen,void *pUserdata)
{
	/* TICKET: 9854-65 */
	/* Redirect to a file */
#ifdef __WINNT__
	DWORD n;
	WriteFile((HANDLE)pUserdata,pData,nLen,&n,0);
#else
	write((int)pUserdata,pData,nLen);
#endif
	return XPP_OK;
}
static void Fatal(const char *zMsg)
{
	/* TICKET: 9854-63 */
	puts(zMsg);
	xpp_lib_shutdown();
	exit(0);
}
static int MacroTrace(void *pUnused,const char *zName,const char *zFilename,int nLine,int nArg,const SyString *azArg)
{
	pUnused = 0;
	azArg = 0;
	/* TICKET: 2710-22 */
	printf("%s ==> %s on line %d with %d arguments\n",zFilename,zName,nLine,nArg);
	return 0;
}
static void ErrorTrace(void *pUnused,const char *zFilename,int ErrCode,int Line,const char *zErr)
{
	pUnused = 0;
	ErrCode = 0;
	Line = 0;
	printf("Error: %s: %s",zFilename,zErr);
}
/* ALPHA-1 */
static void Alpha1(const char *zFile)
{
	int rc;
	/* TICKET: 9854-64 */
	xpp *pCpp;
	/* Emulate the C PreProcessor (cpp) */
	pCpp = xpp_export_cpp();
	if( pCpp == 0 ){
		Fatal(xpp_errmsg(SXERR_MEM));
	}
	/* Register the consumer routine */
	rc = xpp_config(pCpp,XPP_CONFIG_OUTPUT_CONSUMER,Consumer,0);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Register a trace callback */
	rc = xpp_config(pCpp,XPP_CONFIG_TRACE_CALLBACK,MacroTrace,0);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Register error trace callback */
	rc = xpp_config(pCpp,XPP_CONFIG_ERR_CALLBACK,ErrorTrace,0);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Insert additional include path */
#ifdef __WINNT__
	rc = xpp_config(pCpp,XPP_CONFIG_IMPORT_PATH,"C:\\Users\\xtremejames183\\Desktop\\sources\\sanos\\src\\include");
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
#endif
	/* Expand the given file */
	rc = xpp_expand_file(pCpp,zFile,-1);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	rc = xpp_release(pCpp);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
}
/* ALPHA-2 */
static void Alpha2(const char *zFile)
{
#ifdef __WINNT__
	HANDLE hFile;
#else
	int fd;
#endif
	int rc;
	/* TICKET: 9854-65 */
	xpp *pCpp;
	/* Emulate the C Pre-Processor (cpp) */
	pCpp = xpp_export_cpp();
	if( pCpp == 0 ){
		Fatal(xpp_errmsg(SXERR_MEM));
	}
#ifdef __WINNT__
	hFile = CreateFileA("C:\\users\\xtremejames183\\Desktop\\xpp.txt",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,
		0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	if( hFile == 0){
		Fatal(xpp_errmsg(SXERR_IO));
	}
#else
	fd = open("./xpp.txt",O_CREAT|O_RDWR|O_TRUNC,0644);
	if( fd < 0 ){
		Fatal(xpp_errmsg(SXERR_IO));
	}
#endif
	/* Register the consumer routine */
	rc = xpp_config(pCpp,XPP_CONFIG_OUTPUT_CONSUMER,Consumer2,
#ifdef __WINNT__
hFile
#else
(void *)fd
#endif
);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Insert additional include path */
#ifdef __WINNT__
	rc = xpp_config(pCpp,XPP_CONFIG_IMPORT_PATH,"C:\\Users\\xtremejames183\\Desktop\\sources\\sanos\\src\\include");
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
#endif
	/* Register a trace callback */
	rc = xpp_config(pCpp,XPP_CONFIG_TRACE_CALLBACK,MacroTrace,0);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Register error trace callback */
	rc = xpp_config(pCpp,XPP_CONFIG_ERR_CALLBACK,ErrorTrace,0);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Expand the given file */
	rc = xpp_expand_file(pCpp,zFile,/*XPP_IGNORE_WS|*/XPP_REDUCE_WS|XPP_UNESCAPE_STRING);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	xpp_reset(pCpp);
	rc = xpp_release(pCpp);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
#ifdef __WINNT__
	CloseHandle(hFile);
#else
	close(fd);
#endif
}
/* ALPHA-3 */
static void Alpha3(const char *zFile)
{
	unsigned int nLen;
	char *zOut;
	int rc;
	/* TICKET: 3322-92 */
	xpp *pCpp;
	/* Emulate the C PreProcessor (cpp) */
	pCpp = xpp_export_cpp();
	if( pCpp == 0 ){
		Fatal(xpp_errmsg(SXERR_MEM));
	}
	/* Register the output pointer */
	rc = xpp_config(pCpp,XPP_CONFIG_OUTPUT_DYNAMIC_BUFFER,&zOut,&nLen);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Register a trace callback */
	rc = xpp_config(pCpp,XPP_CONFIG_TRACE_CALLBACK,MacroTrace,0);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Register error trace callback */
	rc = xpp_config(pCpp,XPP_CONFIG_ERR_CALLBACK,ErrorTrace,0);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Insert additional include path */
#ifdef __WINNT__
	rc = xpp_config(pCpp,XPP_CONFIG_IMPORT_PATH,"C:\\Users\\xtremejames183\\Desktop\\sources\\sanos\\src\\include");
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
#endif
	/* Expand the given file */
	rc = xpp_expand_file(pCpp,zFile,-1);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Print output */
	puts(zOut);
	rc = xpp_release(pCpp);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
}
/* ALPHA-4 */
static void Alpha4(const char *zFile)
{
	unsigned int nLen;
	char zOut[20];
	int rc;
	/* TICKET: 3322-92 */
	xpp *pCpp;
	/* Emulate the C PreProcessor (cpp) */
	pCpp = xpp_export_cpp();
	if( pCpp == 0 ){
		Fatal(xpp_errmsg(SXERR_MEM));
	}
	nLen = sizeof(zOut);
	/* Register the static output pointer */
	rc = xpp_config(pCpp,XPP_CONFIG_OUTPUT_BUFFER,zOut,&nLen);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Register a trace callback */
	rc = xpp_config(pCpp,XPP_CONFIG_TRACE_CALLBACK,MacroTrace,0);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Register error trace callback */
	rc = xpp_config(pCpp,XPP_CONFIG_ERR_CALLBACK,ErrorTrace,0);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
	/* Insert additional include path */
#ifdef __WINNT__
	rc = xpp_config(pCpp,XPP_CONFIG_IMPORT_PATH,"C:\\Users\\xtremejames183\\Desktop\\sources\\sanos\\src\\include");
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
#endif
	/* Expand the given file */
	rc = xpp_expand_file(pCpp,zFile,-1);
	if( rc != XPP_OK && rc != SXERR_SHORT ){
		Fatal(xpp_errmsg(rc));
	}
	/* Print output */
	printf("Output length: %u\n",nLen);
	puts(zOut);
	{
		unsigned int n;
		xpp_query(pCpp,XPP_TOTAL_ACTIVE_MACRO,&n);
		printf("%u\n",n);
		xpp_query(pCpp,XPP_TOTAL_BUILTIN_MACRO,&n);
		printf("%u\n",n);
		xpp_query(pCpp,XPP_TOTAL_COMMENTS,&n);
		printf("%u\n",n);
		xpp_query(pCpp,XPP_TOTAL_ERR,&n);
		printf("%u\n",n);
		xpp_query(pCpp,XPP_TOTAL_IF_CONDITION,&n);
		printf("%u\n",n);
		xpp_query(pCpp,XPP_TOTAL_IGNORED,&n);
		printf("%u\n",n);
		xpp_query(pCpp,XPP_TOTAL_LINES,&n);
		printf("%u\n",n);
		xpp_query(pCpp,XPP_TOTAL_TOKENS,&n);
		printf("%u\n",n);
		xpp_query(pCpp,XPP_TOTAL_USER_MACRO,&n);
		printf("%u\n",n);
	}
	rc = xpp_release(pCpp);
	if( rc != XPP_OK ){
		Fatal(xpp_errmsg(rc));
	}
}
int main(int nArg,char *azArg[])
{
	char a[100];
	if( nArg != 2 ){
		Fatal("xPP [file.c] [file2.c]...");
	}
	xpp_snprintf(a,sizeof(a),"salut c %d",14541);
	puts(a);
	//Alpha1(azArg[1]);
	Alpha2(azArg[1]);
	//Alpha3(azArg[1]);
	Alpha4(azArg[1]);
	xpp_lib_shutdown();
	return 0;
}
