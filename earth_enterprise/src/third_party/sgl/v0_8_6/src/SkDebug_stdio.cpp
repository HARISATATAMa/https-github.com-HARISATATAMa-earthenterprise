/* libs/corecg/SkDebug_stdio.cpp
**
** Copyright 2006, Google Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License"); 
** you may not use this file except in compliance with the License. 
** You may obtain a copy of the License at 
**
**     http://www.apache.org/licenses/LICENSE-2.0 
**
** Unless required by applicable law or agreed to in writing, software 
** distributed under the License is distributed on an "AS IS" BASIS, 
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
** See the License for the specific language governing permissions and 
** limitations under the License.
*/

#include "SkTypes.h"

#if (defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_UNIX)) && defined(SK_DEBUG)

#include <stdarg.h>
#include <stdio.h>

void SkDebugf(const char format[], ...)
{
    static const size_t kBufferSize = 256;

    char    buffer[kBufferSize + 1];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, kBufferSize, format, args);
    va_end(args);
    fprintf(stderr, buffer);
}

#endif

