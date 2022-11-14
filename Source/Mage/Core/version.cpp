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


#include "config.h"
#include "Core/types.h"
#include "Core/version.h"
//#include "Debug/assert.h"
#include <cstdio>


namespace Page
{
    namespace Core
    {
        //
        static s32 _day = 27;
        static s32 _month = 5;
        static s32 _year = 2022;


        // Acquire engine version number.
        void VersionGet(s32& day, s32& month, s32& year)
        {
            day = _day;
            month = _month;
            year = _year;
        }


        // Acquire engine version number as a string.
        void VersionGetAsString(char* buffer, s32 bufferSize)
        {
    //        ASSERT(buffer && *buffer, "Buffer cannot be null.");
   //         ASSERT(bufferSize > 15 && bufferSize < 256, "Invalid buffer size");

            if (buffer && bufferSize > 15 && bufferSize < 256)
            {
#if defined(PLATFORM_PC)
                sprintf_s(buffer, bufferSize, "%i.%i.%i", _year, _month, _day);
#else
                sprintf(buffer, "%i.%i.%i", _year, _month, _day);
#endif
            }
        }
    }
}
