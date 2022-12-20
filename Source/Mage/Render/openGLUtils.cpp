#include "Core/macros.h"
#include "Debug/assert.h"
#include "Debug/trace.h"
//#include "Display/openGLUtils.h"
#include <windows.h>
#include <gl/gl.h>


// Clears any unhandled opengl errors
void OpenGlClearErrors()
{
  //  while (glGetError() != GL_NO_ERROR);
}


// Checks if the previous action caused an error, If so its displayed
void OpenGLErrorCheck(const char *cmd, const char* file, const char* func, int line)
{
#if (defined(_DEBUG) || defined(DEBUG)) && defined(GAT)

    ASSERT(file && *file);
    ASSERT(func && *func);

    //// Don't print error messages if game is exiting
    //prRegistry* pReg = static_cast<prRegistry*>(prCoreGetComponent(PRSYSTEM_REGISTRY));
    //if (pReg)
    //{
    //    if (prStringCompare(pReg->GetValue("Exit"), "true") == 0)
    //    {
    //        return;
    //    }
    //}
    //else
    //{
    //    // No registry? Then lets get the hell out of here.
    //    return;
    //}

    // Write error message
    while (GLenum error = glGetError())
    {
        const char* err = nullptr;

        switch (error)
        {
        case GL_INVALID_ENUM:
            err = "GL_INVALID_ENUM";
            break;

        case GL_INVALID_VALUE:
            err = "GL_INVALID_VALUE";
            break;

        case GL_INVALID_OPERATION:
            err = "GL_INVALID_OPERATION";
            break;

        case GL_STACK_OVERFLOW:
            err = "GL_STACK_OVERFLOW";
            break;

        case GL_STACK_UNDERFLOW:
            err = "GL_STACK_UNDERFLOW";
            break;

        case GL_OUT_OF_MEMORY:
            err = "GL_OUT_OF_MEMORY";
            break;

        default:
            err = "UNKNOWN";
            break;
        }

        Trace(LogLevel::Error, "OpenGL error: %s\nInstruction %s\n", err, cmd);
        Trace(LogLevel::Error, "File: %s\nFunc: %s\nLine: %i\n", file, func, line);
    }
#else
    UNUSED(file);
    UNUSED(func);
    UNUSED(line);
#endif
}
