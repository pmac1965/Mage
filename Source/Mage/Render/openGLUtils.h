#pragma once


// Clears any unhandled opengl errors
void OpenGlClearErrors();


// Function: OpenGLErrorCheck
//      Checks if the previous action caused an error, If so its displayed
//
// Parameters:
//      cmd  - The instruction which caused the error
//      file - A char pointer to the file name
//      func - A char pointer to the functions name
//      line - Line number of the function that caused error
void OpenGLErrorCheck(const char* cmd, const char* file, const char* func, int line);


// Removeable calls
#if (defined(_DEBUG) || defined(DEBUG))// && defined(OPENGL_CHECK_CALLS) #x
#define ERR_CHECK(x)    OpenGlClearErrors();                                    \
                        x;                                                      \
                        //OpenGLErrorCheck(#x, __FILE__, __FUNCTION__, __LINE__)
#else
#define ERR_CHECK(x)    x;
#endif
