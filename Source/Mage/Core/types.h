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


 // Basic types
typedef unsigned char       u8;
typedef   signed char       s8;
typedef unsigned short      u16;
typedef   signed short      s16;
typedef unsigned int        u32;
typedef   signed int        s32;
typedef unsigned long long  u64;
typedef   signed long long  s64;
typedef float               f32;
typedef double              f64;

// Volatile versions.
typedef volatile s8         vs8;
typedef volatile u8         vu8;
typedef volatile s16        vs16;
typedef volatile u16        vu16;
typedef volatile s32        vs32;
typedef volatile u32        vu32;
typedef volatile s64        vs64;
typedef volatile u64        vu64;
typedef volatile f32        vf32;
typedef volatile f64        vf64;

// Character types
typedef char                char8;
typedef wchar_t             char16;

// Fixed point types
typedef s16                 fx16;
typedef s32                 fx32;
typedef volatile fx16       vfx16;
typedef volatile fx32       vfx32;

// Macro: COMPILER_ASSERT
//      Checks type sizes at compile time.
#define COMPILER_ASSERT(check) typedef int COMPILER_ASSERT__[(check) ? 1 : -1]

// Assert the sizes of the types
COMPILER_ASSERT(sizeof(u8) == 1);
COMPILER_ASSERT(sizeof(s8) == 1);
COMPILER_ASSERT(sizeof(u16) == 2);
COMPILER_ASSERT(sizeof(s16) == 2);
COMPILER_ASSERT(sizeof(u32) == 4);
COMPILER_ASSERT(sizeof(s32) == 4);
COMPILER_ASSERT(sizeof(u64) == 8);
COMPILER_ASSERT(sizeof(s64) == 8);
COMPILER_ASSERT(sizeof(f32) == 4);
COMPILER_ASSERT(sizeof(f64) == 8);
