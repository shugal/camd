/*
    (C) 2001 AROS - The Amiga Research OS
    $Id: getmidilinkattrsa.c,v 1.2 2001/01/20 22:07:07 ksvalast Exp $

    Desc: 
    Lang: English
*/


#include <proto/utility.h>
#include <proto/exec.h>

#include "camd_intern.h"

/*****************************************************************************

    NAME */

	AROS_LH2(ULONG, GetMidiLinkAttrsA,

/*  SYNOPSIS */
	AROS_LHA(struct MidiLink *, midilink, A0),
	AROS_LHA(struct TagItem *, tags, A1),

/*  LOCATION */
	struct CamdBase *, CamdBase, 17, Camd)

/*  FUNCTION
		Remind me to fill in things here later.

    INPUTS

    RESULT

    NOTES
		If you are not the owner of the midilink, you should lock
		Camd before calling to ensure that it wont go away.
		Theres no point in locking if you know it wont go away.

    EXAMPLE

    BUGS

    SEE ALSO
		SetMidiLinkAttrsA

    INTERNALS

    HISTORY

	2001-01-12 ksvalast first created

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct CamdBase *,CamdBase)

	struct TagItem *tag;
	const struct TagItem *tstate=tags;
	ULONG *where;
	ULONG ret=0;

	ObtainSemaphoreShared(CB(CamdBase)->CLSemaphore);

	while((tag=NextTagItem(&tstate))){
		ret++;
		where=(ULONG *)tag->ti_Data;
		switch(tag->ti_Tag){
			case MLINK_Name:
				*where=(ULONG)midilink->ml_Node.ln_Name;
				break;
			case MLINK_Location:
				*where=(ULONG)midilink->ml_Location->mcl_Node.ln_Name;
				break;
			case MLINK_ChannelMask:
				*where=(ULONG)midilink->ml_ChannelMask;
				break;
			case MLINK_EventMask:
				*where=(ULONG)midilink->ml_EventTypeMask;
				break;
			case MLINK_UserData:
				*where=(ULONG)midilink->ml_UserData;
				break;
			case MLINK_Comment:
				ret--;
				break;
			case MLINK_PortID:
				*where=(ULONG)midilink->ml_PortID;
				break;
			case MLINK_Private:
				*where=(ULONG)midilink->ml_Flags&MLF_PrivateLink;
				break;
			case MLINK_Priority:
				*where=(ULONG)midilink->ml_Node.ln_Pri;
				break;
			case MLINK_SysExFilter:
				*where=(ULONG)midilink->ml_SysExFilter.sxf_Packed;
				break;
			case MLINK_SysExFilterX:
				*where=(ULONG)midilink->ml_SysExFilter.sxf_Packed;
				break;
			case MLINK_Parse:
				*where=(ULONG)midilink->ml_ParserData==NULL?FALSE:TRUE;
				break;
			default:
				ret--;
				break;
		}
	}

	ReleaseSemaphore(CB(CamdBase)->CLSemaphore);

	return ret;


   AROS_LIBFUNC_EXIT
}


