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
#include "indexBuffer.h"
#include "openGLUtils.h"


IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : m_ID(0)
{
  //  ERR_CHECK(glGenBuffers(1, &m_ID));
  //  ERR_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
  //  ERR_CHECK(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}


IndexBuffer::~IndexBuffer()
{
   // ERR_CHECK(glDeleteBuffers(1, &m_ID));
}


void IndexBuffer::Bind() const
{
    //ERR_CHECK(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
}


void IndexBuffer::Unbind() const
{
    //ERR_CHECK(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

