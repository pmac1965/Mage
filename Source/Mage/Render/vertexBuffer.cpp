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
#include "vertexBuffer.h"
#include "openGLUtils.h"


//
VertexBuffer::VertexBuffer(const void* data, unsigned int size)
    : m_vbo(0)
{
//    ERR_CHECK(glGenBuffers(1, &m_vbo));
 //   ERR_CHECK(glBindBuffer(GL_ARRAY_BUFFER, m_vbo));
   // ERR_CHECK(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}


//
VertexBuffer::~VertexBuffer()
{
    //ERR_CHECK(glDeleteBuffers(1, &m_vbo));
}


//
void VertexBuffer::Bind() const
{
  //  ERR_CHECK(glBindBuffer(GL_ARRAY_BUFFER, m_vbo));
}


//
void VertexBuffer::Unbind() const
{
  //  ERR_CHECK(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
