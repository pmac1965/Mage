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


#include "../config.h"
//#include "../Core/macros.h"


 // In code reminder messages.
#if !defined(HIDE_MESSAGES)
#if defined(PLATFORM_PC)
    // Reminder macro
#define REMINDER                __FILE__ "(" CURRLINE ") : Reminder: " 
#define TODO(msg)               __pragma(message(REMINDER msg))
//#elif defined(PLATFORM_ANDROID) || defined(PLATFORM_IOS) || defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
//    // Reminder macro
//    #define TODO(msg)               DO_PRAGMA(message ("TODO: " #msg))
#else
    // Default to release version.
#define TODO(msg)
#pragma message("No 'TODO' macro")
#endif
#else
    // Release version
#define TODO(msg)
#endif // HIDE_MESSAGES


//TODO("Example usage")
