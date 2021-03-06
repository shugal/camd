/*
    (C) 2001 AROS - The Amiga Research OS
    $Id: strings.c,v 1.3 2001/01/28 04:44:43 ksvalast Exp $

    Desc: 
    Lang: English
*/

#include <proto/exec.h>

#include "camd_intern.h"

ULONG mystrlen(char *string){
	ULONG ret=0;
	while(string[ret]!=0) ret++;
	return ret;
}

BOOL mystrcmp(char *one,char *two){
  while(*one==*two){
    if(*one==0) return TRUE;
    one++;
    two++;
  }
  return FALSE;
}

char *findonlyfilename(char *pathfile){
  char *temp=pathfile;
  while(*pathfile!=0){
    if(*pathfile=='/') temp=pathfile+1;
    if(*pathfile==':') temp=pathfile+1;
    pathfile++;
  }
  return temp;
}

ASM void stuffChar( REG(d0) UBYTE in,REG(a3) char **stream){
	stream[0]++;
	stream[0][-1]=in;
}


void mysprintf(struct CamdBase *CamdBase,char *string,char *fmt,...){
	void *start=&fmt+1;

	// You should change your proto-file, if there is a warning about const.
	CONST_STRPTR string2=string;

	RawDoFmt(
		 fmt,
		 start,
		 (VOID_FUNC)stuffChar,
		 (APTR)&string2
		 );
}

