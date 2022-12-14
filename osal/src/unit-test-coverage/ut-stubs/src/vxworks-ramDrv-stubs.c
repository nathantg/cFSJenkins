/************************************************************************
 * NASA Docket No. GSC-18,719-1, and identified as “core Flight System: Bootes”
 *
 * Copyright (c) 2020 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

/* OSAL coverage stub replacement for ramDrv.h */
#include <string.h>
#include <stdlib.h>
#include "utstubs.h"

#include "OCS_ramDrv.h"

static OCS_BLK_DEV LOCAL_RAMDEV = {0};

OCS_BLK_DEV *OCS_ramDevCreate(char *ramAddr, int bytesPerSec, int secPerTrack, int nSectors, int secOffset)
{
    int32        Status;
    OCS_BLK_DEV *retval = NULL;

    Status = UT_DEFAULT_IMPL(OCS_ramDevCreate);
    if (Status == 0)
    {
        retval = &LOCAL_RAMDEV;
    }

    return retval;
}
