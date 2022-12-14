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

/**
 * \file
 * \ingroup ut-stubs
 *
 * Declarations and prototypes for OCS_sys_select
 */

#ifndef OCS_SYS_SELECT_H
#define OCS_SYS_SELECT_H

#include "OCS_basetypes.h"
#include "OCS_time.h"

/* ----------------------------------------- */
/* constants normally defined in sys/select.h */
/* ----------------------------------------- */

#define OCS_FD_SETSIZE 10

/* ----------------------------------------- */
/* types normally defined in sys/select.h */
/* ----------------------------------------- */
typedef struct
{
    unsigned int fds;
} OCS_fd_set;

/* ----------------------------------------- */
/* prototypes normally declared in sys/select.h */
/* ----------------------------------------- */

extern int OCS_select(int nfds, OCS_fd_set *readfds, OCS_fd_set *writefds, OCS_fd_set *exceptfds,
                      struct OCS_timeval *timeout);

extern void OCS_FD_SET(int fd, OCS_fd_set *set);
extern int  OCS_FD_ISSET(int fd, OCS_fd_set *set);
extern void OCS_FD_CLR(int fd, OCS_fd_set *set);
extern void OCS_FD_ZERO(OCS_fd_set *set);

#endif /* OCS_SYS_SELECT_H */
