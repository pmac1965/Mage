#pragma once
/**
 * Copyright 2022 Paul Michael McNab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


enum
{
    AssertResultIgnore,
    AssertResultAbort,
    AssertResultRetry,
};


#if defined(_DEBUG) || defined(DEBUG)
// Function: AssertPrint
//      Prints the assert message
//
// Parameters:
//      cond     - Condition description
//      file     - File nane
//      function - Function
//      line     - Line number
//      fmt      - Format text
//      ...      - Optional parameters
//
// Notes:
//      *Do not call this function directly*
int AssertPrint(const char* cond, const char* file, const char* function, int line, const char* fmt = 0, ...);


// This macro will trigger a breakpoint. I keep this here, so I can see how to do x86/x64 specific code
#ifdef _M_IX86
    // x86
#define BREAKPOINT()    \
            {                       \
                __debugbreak();     \
            }
#else
    // x64
#define BREAKPOINT()    \
            {                       \
                __debugbreak();     \
            }
#endif


// Assertion macro which allows additional information to be displayed if required.
#define ASSERT(cond, ...)                                                                   \
        if (!(cond))                                                                                \
        {                                                                                           \
            static bool ignore = false;                                                             \
            if (!ignore)                                                                            \
            {                                                                                       \
                int result = AssertPrint(#cond, __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__);     \
                if (result == AssertResultAbort)                                                    \
                {                                                                                   \
                    BREAKPOINT();                                                                   \
                }                                                                                   \
                else if (result == AssertResultIgnore)                                              \
                {                                                                                   \
                    ignore = true;                                                                  \
                }                                                                                   \
            }                                                                                       \
        }

#else
#define ASSERT(cond, ...)
#endif

