/*
    (C) 2001 AROS - The Amiga Research OS
    $Id: getsysex.c,v 1.1 2001/01/17 18:51:30 ksvalast Exp $

    Desc: 
    Lang: English
*/


#include <proto/exec.h>

#include "camd_intern.h"


/*****************************************************************************

    NAME */

	AROS_LH3(ULONG, GetSysEx,

/*  SYNOPSIS */
	AROS_LHA(struct MidiNode *, midinode, A0),
	AROS_LHA(UBYTE *, Buf, A1),
	AROS_LHA(ULONG, len, D0),

/*  LOCATION */
	struct CamdBase *, CamdBase, 27, Camd)

/*  FUNCTION
		Remind me to fill in things here later.

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS
		Not tested. SysEx receiving does probably have some bugs.

    SEE ALSO
		SkipSysEx, QuierySysEx

    INTERNALS

    HISTORY

	2001-01-12 ksvalast first created

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct CamdBase *,CamdBase)

	struct MyMidiNode *mymidinode=(struct MyMidiNode *)midinode;
	ULONG numread=0;
	UBYTE data;

	if(mymidinode->sysex_nextis0==TRUE){
		return 0;
	}

	ObtainSemaphore(&mymidinode->sysexsemaphore2);

		mymidinode->sysex_nextis0=FALSE;

		while(numread<len){
			data=*mymidinode->sysex_read;
			mymidinode->sysex_read++;
			if(mymidinode->sysex_read==mymidinode->sysex_end){
				mymidinode->sysex_read=mymidinode->sysex_start;
			}
			Buf[numread]=data;
			numread++;

			if(data==0xf7){
				mymidinode->sysex_nextis0=TRUE;
				break;
			}
		}

	ReleaseSemaphore(&mymidinode->sysexsemaphore2);


	return numread;


   AROS_LIBFUNC_EXIT
}



