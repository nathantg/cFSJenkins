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
 * \ingroup adaptors
 *
 * Declarations and prototypes for ut-adaptor-console
 */

#ifndef UT_ADAPTOR_CONSOLE_H
#define UT_ADAPTOR_CONSOLE_H

#include "common_types.h"
#include "ut-adaptor-common.h"

extern void *const  UT_Ref_OS_impl_console_table;
extern size_t const UT_Ref_OS_impl_console_table_SIZE;

/**
 * Invokes the console helper task entry point
 */
extern int UT_ConsoleTest_TaskEntry(int arg);

#endif /* UT_ADAPTOR_CONSOLE_H */
