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


#include <string>
#include <unordered_map>// hash map
#include "../Core/types.h"


namespace Page {

    class Shader
    {
    public:
        Shader(const std::string& vertex, const std::string& fragment);
        ~Shader();

        void Bind() const;
        void Unbind() const;

    private:
        int GetUniformLocation(const std::string& name) const;

        unsigned int CompileShader(unsigned int type, const std::string& source);

        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

    private:
        mutable std::unordered_map<std::string, int> m_UniformLocationCache;

        u32 m_ID;
    };

}