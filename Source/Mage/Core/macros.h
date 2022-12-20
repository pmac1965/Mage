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


#include "types.h"


// ------------------------------------------------------------------------------------------
// Range macros.
// ------------------------------------------------------------------------------------------

// Macro: BETWEEN
//      Used to test if a variable is between the minimum and maximum range specified.
#define BETWEEN(var, min, max)   ((var) >= (min)  &&  (var) <= (max))

// Macro:  CLAMP
//      Ensures a variable is between the minimum and maximum range specified.
#define CLAMP(var, min, max)     ((var) < (min) ? (min) : (var) > (max) ? (max) : (var))


// ------------------------------------------------------------------------------------------
// DirectX macros.
// ------------------------------------------------------------------------------------------

// Macro: SAFE_RELEASE
//      DirectX safe release macro.
#define SAFE_RELEASE(p) { if ((p)) { (p)->Release(); (p) = nullptr; } }


// ------------------------------------------------------------------------------------------
// Bit flag testing macros.
// ------------------------------------------------------------------------------------------

// Macro: TEST_FLAG
//      Tests if a bit flag is set.
#define TEST_FLAG(flag, bit)      ((flag)  &  (bit))

// Macro: SET_FLAG
//      Sets a bit flag.
#define SET_FLAG(flag, bit)       ((flag) |=  (bit))

// Macro: CLEAR_FLAG
//      Clears a bit flag.
#define CLEAR_FLAG(flag, bit)     ((flag) &= ~(bit))

// Macro: FLIP_FLAG
//      Flips a bit flag.
#define FLIP_FLAG(flag, bit)      ((flag) ^=  (bit))


// ------------------------------------------------------------------------------------------
// Text macros.
// ------------------------------------------------------------------------------------------

// Macro: IS_WHITESPACE
//      Determines if a character is whitespace.
#define IS_WHITESPACE(c)    ((c) ==' ' || (c) == '\r' || (c) == '\n' || (c) == '\t')


// ------------------------------------------------------------------------------------------
// Miscellaneous macros.
// ------------------------------------------------------------------------------------------

// Macro: SAFE_DELETE_ARRAY
//      Allows delete to be called only on valid pointers.
#define SAFE_DELETE_ARRAY(ptr)      if ((ptr) != nullptr) {delete [] (ptr); (ptr) = nullptr;}


// Macro: SAFE_DELETE
//      Allows delete to be called only on valid pointers.
#define SAFE_DELETE(ptr)            if ((ptr) != nullptr) {delete (ptr); (ptr) = nullptr;}

// Macro: SAFE_FREE
//      Allows free to be called only on valid pointers.
#define SAFE_FREE(ptr)              if ((ptr) != nullptr) {free((ptr)); (ptr) = nullptr;}

// Macro: ARRAY_SIZE
//      Used to find the size of an array.
#define ARRAY_SIZE(a)               (sizeof((a)) / sizeof(*(a)))

// Macro: UNUSED
//      Stops unused variables causing warnings.
#define UNUSED(var)                 ((void)(var))


// ------------------------------------------------------------------------------------------
// Math macros/defines
// ------------------------------------------------------------------------------------------

// Macro: EPSILON
//      EPSILON
#define EPSILON                 0.000001f

// Macro: MAX
//      Returns the largest number.
#define MAX(a, b)               (((a) > (b)) ? (a) : (b))

// Macro: MIN
//      Returns the smallest number.
#define MIN(a, b)               (((a) < (b)) ? (a) : (b))

// Macro: MINMIN
//      Returns the smallest number.
#define MINMIN(a,b,c)           ((a) < (b) ? MIN((a), (c)) : MIN((b), (c)))

// Macro: MAXMAX
//      Returns the largest number.
#define MAXMAX(a,b,c)           ((a) > (b) ? MAX((a), (c)) : MAX((b), (c)))

// Macro: ABS
//      Returns the absolute of a number.
#define ABS(a)                  (((a) < 0) ? -(a) : (a))

// Macro: FABS
//      Returns the absolute of a number.
#define FABS(a)                 (((a) < 0.0f) ? -(a) : (a))

// Macro: PRSAME_SIGNS
//      Determines if two numbers have the same sign.
#define SAME_SIGNS(a, b)        (((s32) ((u32)a ^ (u32)b)) >= 0)

// Macro: CUBE
//      Returns a number cubed.
#define CUBE(x)                 ((x) * (x) * (x))

// Macro: SQR
//      Returns a number squared.
#define SQR(x)                  ((x) * (x))

// Macro: DOUBLE
//      Returns the double of a number.
#define DOUBLE(x)               ((x) + (x))

// Macro: SIGN
//      Returns the sign of a number.
#define SIGN(a)                 (((a) < 0) ? -1 : 1)

// Macro: NUMBITS
//      Returns the number of bits for a type.
#define NUMBITS(a)              (sizeof(a) << 3)

// Macro: LERP
//      Performs linear interpolation.
#define LERP(time, from, to)    ( (from) + ( (time) * ((to) - (from)) ) )

// Macro: PI
// PI
#define PI                      3.14159265358979323846f

// Macro: RAD2DEG
//      Converts radians to degrees.
#define RAD2DEG(radians)        ((radians) * (180.0f / PI))

// Macro: DEG2RAD
//      Converts degrees to radians.
#define DEG2RAD(degrees)        ((degrees) * (PI / 180.0f))

// Macro: SWAP
//      Swaps two numbers.
#define SWAP(a, b) \
{                  \
    u64 tmp = b;   \
    b       = a;   \
    a       = tmp;  \
}

// Macro: FLOOR
//      Gems - Map 't' to the default integer
#define FLOOR(t)                ((t) < 0 ? (int) ((t)-1.0) : (int) (t))

// Macro: ROUND
//      Gems - Map 't' to the nearest integer
#define ROUND(t)                ((t) < 0 ? (int) ((t)-0.5) : (int) ((t)+0.5))

// Macro: SIZE2
//      Determines if a number is divisible by 2.
#define SIZE2(num)              ((((u32)num) & 1)==0)

// Macro: SIZE4
//      Determines if a number is divisible by 4.
#define SIZE4(num)              ((((u32)num) & 3)==0)


// ------------------------------------------------------------------------------------------
// Miscellaneous macros.
// ------------------------------------------------------------------------------------------

// Macro: ROUND_UP
//      Rounds a number up by the specified amount.
#define ROUND_UP(number, amount)      (((u32)(number) + (amount) - 1)  &  ~((amount) - 1))

// Macro: ROUND_DOWN
//      Rounds a number down by the specified amount.
#define ROUND_DOWN(number, amount)    ((u32)(number) & ~((amount)-1))

// Macro: EVEN
//      Determines if a number is even or odd.
#define EVEN(num)                     ((((u32)num) & 1)==0)

// Macro: ALIGNMENT2
//      Determines if the alignment is at a u16 boundary.
#define ALIGNMENT2(ptr)               ((((u32)ptr) & 1)==0)

// Macro: ALIGNMENT4
//      Determines if the alignment is at a u32 boundary.
#define ALIGNMENT4(ptr)               ((((u32)ptr) & 3)==0)

// Macro: BIT
//      Allows better looking bit setting code.
#define BIT(a)                        (1 << (a))

// Macro: BOOL_TO_STRING
//      Converts a bool to a string.
#define BOOL_TO_STRING(b)             ((b) ? "true" : "false")

// Macro: GB
//      Allows simple calculation of sizes.
#define GB(a)                         ((a) * 1024 * 1024 * 1024)

// Macro: MB
//      Allows simple calculation of sizes.
#define MB(a)                         ((a) * 1024 * 1024)

// Macro: KB
//      Allows simple calculation of sizes.
#define KB(a)                         ((a) * 1024)


// ------------------------------------------------------------------------------------------
// Allows for stringizing
// ------------------------------------------------------------------------------------------

// Macro: STRINGIZE
//      Allows for stringizing
#define STRINGIZE(L)                    #L 

// Macro: MAKESTRING
//      Allows for stringizing
#define MAKESTRING(M, L)                M(L) 

// Macro: CURRLINE
//      Allows for stringizing
#define CURRLINE                        MAKESTRING(STRINGIZE, __LINE__) 

// Macro: FILE_LINE
//      Allows for stringizing
#define FILE_LINE                       __FILE__ " (Line: " CURRLINE ")\n" 


// ------------------------------------------------------------------------------------------
// Miscellaneous PC only macros.
// ------------------------------------------------------------------------------------------

// Macro: KEY_DOWN
//      Simple key down macro.
#define KEY_DOWN(vk_code)             ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
