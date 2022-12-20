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


//#include <GL/glew.h>
//#include <gl/GL.h>
#include "openGLUtils.h"
#include "shader.h"
#include "../Debug/trace.h"
#include "../Debug/assert.h"


namespace Page
{
    //
    Shader::Shader(const std::string& vertex, const std::string& fragment)
        : m_ID(0)
    {
        m_ID = CreateShader(vertex, fragment);
    }


    //
    Shader::~Shader()
    {
       // ERR_CHECK(glDeleteProgram(m_ID));
    }


    //
    void Shader::Bind() const
    {
      //  ERR_CHECK(glUseProgram(m_ID));
    }


    //
    void Shader::Unbind() const
    {
      //  ERR_CHECK(glUseProgram(0));
    }


    //
    int Shader::GetUniformLocation(const std::string& name) const
    {
        if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
            return m_UniformLocationCache[name];

      //  ERR_CHECK(int location = glGetUniformLocation(m_ID, name.c_str()));
     //   if (location == -1)
        {
            Trace(LogLevel::Information, "Warning! Uniform %s doesn't exist\n", name.c_str());
        }

  //      m_UniformLocationCache[name] = location;

        return 0;// location;
    }


    //
    unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
    {
//        ASSERT(type == GL_FRAGMENT_SHADER); // Add shader type

       // ERR_CHECK(unsigned int id = glCreateShader(type));

        const char* src = source.c_str();

    //    ERR_CHECK(glShaderSource(id, 1, &src, nullptr));
    //    ERR_CHECK(glCompileShader(id));

        int result=0;
  //      glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == 0)//GL_FALSE)
        {
            int length=0;
      //      glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
//
            char* message = (char*)_malloca(length * sizeof(char));
   //         glGetShaderInfoLog(id, length, &length, message);

//            Trace(LogLevel::Error, "Failed to compile %s shader\n", (type == GL_FRAGMENT_SHADER ? "fragment" : "vertex"));
            Trace(LogLevel::Error, "%s\n", message);

         //   glDeleteShader(id);
            return 0;
        }

        return 0;// id;
    }


    //
    unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
    {
    /*    unsigned int program = glCreateProgram();

        unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

        ERR_CHECK(glAttachShader(program, vs));
        ERR_CHECK(glAttachShader(program, fs));

        ERR_CHECK(glLinkProgram(program));
        ERR_CHECK(glValidateProgram(program));

        ERR_CHECK(glDeleteShader(vs));
        ERR_CHECK(glDeleteShader(fs));//*/

        return 0;// program;
    }

}
