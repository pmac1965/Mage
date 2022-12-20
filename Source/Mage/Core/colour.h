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
#include "macros.h"


namespace Core
{
    // Value to get floats from bytes
    #define RGB_ELE (1.0f / 255.0f)

    //
    struct RGBA
    {
        f32 r, g, b, a;
    };

    //
    class Colour
    {
    public:
        Colour() 
            : r(0.0f)
            , g(0.0f)
            , b(0.0f)
            , a(1.0f)
        {}

        Colour(f32 in_R, f32 in_G, f32 in_B, f32 in_A = 1.0f) 
            : r(CLAMP(in_R, 0.0f, 1.0f))
            , g(CLAMP(in_G, 0.0f, 1.0f))
            , b(CLAMP(in_B, 0.0f, 1.0f))
            , a(CLAMP(in_A, 0.0f, 1.0f))
        {}

        Colour(u8 in_R, u8 in_G, u8 in_B, u8 in_A = 255)
            : r(RGB_ELE * in_R)
            , g(RGB_ELE * in_G)
            , b(RGB_ELE * in_B)
            , a(RGB_ELE * in_A)
        {}

        //Colour(Colour& col) :r(col.r)// Maybe too similar to copy constuctor
        //{}

        void SetRGBA(RGBA col)
        {
            r = CLAMP(col.r, 0.0f, 1.0f);
            g = CLAMP(col.g, 0.0f, 1.0f);
            b = CLAMP(col.b, 0.0f, 1.0f);
            a = CLAMP(col.a, 0.0f, 1.0f);
        }

        void GetRGBA(RGBA &col) const 
        {
            col.r = r;
            col.g = g;
            col.b = b;
            col.a = a;
        }

    public:
        static const Colour White;        //  Pre-created colour values
        static const Colour Black;
        static const Colour Red;
        static const Colour Green;
        static const Colour Blue;
        static const Colour Yellow;
        static const Colour Cyan;
        static const Colour Magenta;
        static const Colour DarkGray;
        static const Colour Gray;
        static const Colour LiteGray;
        static const Colour Brown;
        static const Colour Orange;
        static const Colour PastelPink;
        static const Colour BarneyPurple;

    private:
        f32 r, g, b, a;
    };

}
