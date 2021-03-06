/*
    (C) 2001 AROS - The Amiga Research OS
    $Id: midimsglen.c,v 1.1 2001/01/17 18:51:30 ksvalast Exp $

    Desc: 
    Lang: English
*/

#include "camd_intern.h"

/*****************************************************************************

    NAME */

	AROS_LH1(WORD, MidiMsgLen,

/*  SYNOPSIS */
	AROS_LHA(ULONG, msg, D0),

/*  LOCATION */
	struct CamdBase *, CamdBase, 32, Camd)

/*  FUNCTION
		Returns the length of a midimessage. sysex message leads to a
		length of zero.

    INPUTS
		msg - Message.

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY

	2001-01-12 ksvalast first created

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct CamdBase *,CamdBase)

	if(msg<0x80 || msg>0xff) return 0;

	if(msg&0x80 && msg&0x40){
		if(!(msg&0x20)){
			return 2;				//0xc0 or 0xb0
		}else{
			if(msg&0x10){	//0xfx
				switch(msg){
					case 0xf0:
						return 0;
					case 0xf1:
						return 2;
					case 0xf2:
						return 3;
					case 0xf3:
						return 2;
					case 0xf4:
						return 0;
					case 0xf5:
						return 0;
					case 0xf6:
						return 1;
					case 0xf7:
						return 0;
					default:
						return 1;		//Realtime message
						break;
				}
			}
		}
	}
	return 3;

   AROS_LIBFUNC_EXIT
}

