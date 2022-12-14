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

/*================================================================================*
** File:  ut_osnetwork_misc_test.c
** Owner: Tam Ngo
** Date:  April 2013
**================================================================================*/

/*--------------------------------------------------------------------------------*
** Includes
**--------------------------------------------------------------------------------*/

#include "ut_osnetwork_misc_test.h"

/*--------------------------------------------------------------------------------*
** Macros
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Data types
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** External global variables
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Global variables
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Local function prototypes
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Local function definitions
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Syntax: int32 OS_NetworkGetID(void)
** Purpose: Returns network ID of the machine it is on
** Parameters: None
** Returns: OS_ERROR if the OS call failed
**          OS_SUCCESS if succeeded
**          OS_ERR_NOT_IMPLEMENTED if not implemented
** -----------------------------------------------------
** Test #0: Not-implemented condition
**   1) Call this routine
**   2) If the returned value is OS_ERR_NOT_IMPLEMENTED, then exit test
**   3) Otherwise, continue
** -----------------------------------------------------
** Test #1: OS-call-failure condition
**   1) Cause the OS call to fail
**   2) Expect the returned value to be
**        (a) OS_ERROR
** -----------------------------------------------------
** Test #2: Nominal condition
**   1) Call this routine
**   2) Expect the returned value to be
**        (a) OS_ERR_NOT_IMPLEMENTED __or__
**        (b) host id of value greater than 0
**--------------------------------------------------------------------------------*/
void UT_os_networkgetid_test()
{
    /*-----------------------------------------------------*/
    /* API Not implemented */

    if (!UT_IMPL(OS_NetworkGetID()))
    {
        return;
    }

    /*-----------------------------------------------------*/
    /* #1 OS-call-failure */

    /*-----------------------------------------------------*/
    /* #2 Nominal */

    /* NOTE: This API does not return error codes.
     * Any return value could be valid */
    UT_MIR_STATUS(OS_NetworkGetID());
}

/*--------------------------------------------------------------------------------*
** Syntax: int32 OS_NetworkGetHostName(char *host_name, uint32 name_len)
** Purpose: Returns the network name of the machine it is on
** Parameters: *host_name - pointer that will hold the network name of the machine it is on
**             name_len - the maximum length of the memory address host_name points to
** Returns: OS_INVALID_POINTER if the pointer passed in is null
**          OS_ERROR if the OS call failed or name length passed in is 0
**          OS_SUCCESS if succeeded
**          OS_ERR_NOT_IMPLEMENTED if not implemented
** -----------------------------------------------------
** Test #0: Not-implemented condition
**   1) Call this routine
**   2) If the returned value is OS_ERR_NOT_IMPLEMENTED, then exit test
**   3) Otherwise, continue
** -----------------------------------------------------
** Test #1: Null-pointer-argument condition
**   - Call this routine with a null pointer as one of the arguments
**   - Expect the returned value to be
**       (a) OS_INVALID_POINTER
** -----------------------------------------------------
** Test #2: Zero-name-length-arg condition
**   - Call this routine with 0 as the argument for name length
**   - Expect the returned value to be
**       (a) OS_ERROR
** -----------------------------------------------------
** Test #3: OS-call-failure condition
**   - Cause the OS call to fail
**   - Expect the returned value to be
**       (a) OS_ERROR
** -----------------------------------------------------
** Test #4: Nominal condition
**   - Call this routine with all valid arguments
**   - Expect the returned value to be
**       (a) OS_SUCCESS, _and_
**       (b) the returned buffer to be non-empty
**--------------------------------------------------------------------------------*/
void UT_os_networkgethostname_test()
{
    char buffer[UT_OS_IO_BUFF_SIZE];

    /*-----------------------------------------------------*/
    /* API Not implemented */

    if (!UT_IMPL(OS_NetworkGetHostName(buffer, sizeof(buffer))))
    {
        return;
    }

    /*-----------------------------------------------------*/
    /* #1 Null-pointer-arg */

    UT_RETVAL(OS_NetworkGetHostName(NULL, sizeof(buffer)), OS_INVALID_POINTER);

    /*-----------------------------------------------------*/
    /* #2 Zero-name-length-arg */

    UT_RETVAL(OS_NetworkGetHostName(buffer, 0), OS_ERR_INVALID_SIZE);

    /*-----------------------------------------------------*/
    /* #3 OS-call-failure */

    /*-----------------------------------------------------*/
    /* #4 Nominal */

    UT_NOMINAL(OS_NetworkGetHostName(buffer, sizeof(buffer)));
}

/*================================================================================*
** End of File: ut_osnetwork_misc_test.c
**================================================================================*/
