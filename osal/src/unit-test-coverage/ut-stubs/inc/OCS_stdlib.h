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
 * OSAL coverage stub replacement for stdlib.h
 */

#ifndef OCS_STDLIB_H
#define OCS_STDLIB_H

#include "OCS_basetypes.h"

/* ----------------------------------------- */
/* constants normally defined in stdlib.h */
/* ----------------------------------------- */

#define OCS_EXIT_SUCCESS 0x0100
#define OCS_EXIT_FAILURE 0x0101

/* ----------------------------------------- */
/* types normally defined in stdlib.h */
/* ----------------------------------------- */

/* ----------------------------------------- */
/* prototypes normally declared in stdlib.h */
/* ----------------------------------------- */

extern void              OCS_abort(void);
extern void              OCS_exit(int status);
extern unsigned long int OCS_strtoul(const char *nptr, char **endptr, int base);
extern int               OCS_system(const char *command);
extern void *            OCS_malloc(size_t sz);
extern void              OCS_free(void *ptr);

#endif /* OCS_STDLIB_H */
