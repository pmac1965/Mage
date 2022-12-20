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


//#include <gl/glew.h>
//#include <gl/GL.h>
//#include <stb_image/stb_image.h>

#include "texture.h"
#include "openGLUtils.h"



namespace Page
{
    Texture::Texture(const std::string& path)
        : m_RendererID(0)
        , m_FilePath(path)
        , m_LocalBuffer(nullptr)
        , m_Width(0)
        , m_Height(0)
        , m_BPP(0)

    {
        /*stbi_set_flip_vertically_on_load(1);
        m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

        ERR_CHECK(glGenTextures(1, &m_RendererID));
        ERR_CHECK(glBindTexture(GL_TEXTURE_2D, m_RendererID));

        //
        ERR_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        ERR_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        ERR_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
        ERR_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

        ERR_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));

        ERR_CHECK(glBindTexture(GL_TEXTURE_2D, 0));

        if (m_LocalBuffer)
            stbi_image_free(m_LocalBuffer);
        //*/
    }


    Texture::~Texture()
    {
   //     ERR_CHECK(glDeleteTextures(1, &m_RendererID));
    }


    void Texture::Bind(unsigned int slot) const
    {
   //     ERR_CHECK(glActiveTexture(GL_TEXTURE0 + slot));
      //  ERR_CHECK(glBindTexture(GL_TEXTURE_2D, m_RendererID));
    }


    void Texture::Unbind() const
    {
     //   ERR_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
    }

}
