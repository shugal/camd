/*
    (C) 2001 AROS - The Amiga Research OS
    $Id: startclusternotify.c,v 1.1 2001/01/17 18:51:31 ksvalast Exp $

    Desc: 
    Lang: English
*/

#include <proto/exec.h>

#include "camd_intern.h"

/*****************************************************************************

    NAME */

	AROS_LH1(void, StartClusterNotify,

/*  SYNOPSIS */
	AROS_LHA(struct ClusterNotifyNode *,cn,A0),

/*  LOCATION */
	struct CamdBase *, CamdBase, 37, Camd)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS
		Not implemented.

    SEE ALSO

    INTERNALS

    HISTORY

	2001-01-12 ksvalast first created

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct CamdBase *,CamdBase)

	aros_print_not_implemented("StartClusterNotify");

	return;

   AROS_LIBFUNC_EXIT
}

