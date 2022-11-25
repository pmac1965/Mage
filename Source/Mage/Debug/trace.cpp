#include "config.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include "Debug/trace.h"


/// ---------------------------------------------------------------------------
/// Defines
/// ---------------------------------------------------------------------------
#define MSG_BUFFER_SIZE     1024
#define RPT_BUFFER_SIZE     128
#define TRACE_LOG_NAME      "trace.txt"


//#define TRACE_TEST


/// ---------------------------------------------------------------------------
/// Locals
/// ---------------------------------------------------------------------------
namespace
{
#if (defined(_DEBUG) || defined(DEBUG))
    int         enabled = 1;// TRUE;                     // Is logging enabled?
    int         duplicates = 1;// TRUE;                     // Remove duplicate error messages?
    LogLevel  logLevel = LogLevel::Verbose;   // Default log level

#else
    int         enabled = 0;// FALSE;                    // Is logging enabled?
    int         duplicates = 1;// TRUE;                     // Remove duplicate error messages?
    LogLevel    logLevel = LogLevel::Error;     // Default log level

#endif

    int  outputted = 0;                                  // Specifies the number of unique messages output
    int  outputLength = 0;                                  // Length of the previously output message
    char output[MSG_BUFFER_SIZE] = { '\0' };                // Buffer to store the previously output message
}


// Outputs a debug string.
void Trace(LogLevel level, const char* fmt, ...)
{
    if (enabled)
    {
        if (fmt && *fmt)
        {
            if (level >= logLevel)
            {
                char bufferMsg[MSG_BUFFER_SIZE];
                char bufferRpt[RPT_BUFFER_SIZE];

                // Format the output.
                va_list args;
                va_start(args, fmt);
                vsnprintf(bufferMsg, MSG_BUFFER_SIZE - 1, fmt, args);
                va_end(args);

                // Duplicate removal?
                int repeat = 0;// FALSE;
                if (duplicates)
                {
                    if (strcmp(bufferMsg, output) == 0)
                    {
                        outputted++;
                        return;
                    }
                    else
                    {
                        repeat = (outputted > 0);

                        if (repeat)
                        {
                            // I know this is pedantic, but this ensures that the repeat message always starts on a new line by checking
                            // if the last character of the previous string was a carriage return.
                            const char* msg = (outputLength == 0) ? "(Repeat x %i)\n" : output[outputLength - 1] == '\n' ? "(Repeat x %i)\n" :
                                "\n(Repeat x %i)\n";

#ifdef PLATFORM_PC
                            sprintf_s(bufferRpt, RPT_BUFFER_SIZE, msg, outputted + 1);
#else
                            sprintf(bufferRpt, msg, outputted + 1);
#endif
                        }

                        // Reset
                        outputted = 0;

                        // Store string.
#ifdef PLATFORM_PC
                        strcpy_s(output, MSG_BUFFER_SIZE, bufferMsg);
#else
                        strcpy(output, bufferMsg);
#endif

                        // Store length
                        outputLength = (int)strlen(output);
                    }
                }

                // Write to console.
                //if (repeat)
                //{
                //    prOutputString(level, bufferRpt);
                //    prOutputString(level, bufferMsg);
                //}
                //else
                //{
                //    prOutputString(level, bufferMsg);
                //}
                printf_s(bufferMsg);

                // Write to a file?
                //prTraceWriteToFile(repeat, bufferRpt, bufferMsg);
            }
        }
    }
}
