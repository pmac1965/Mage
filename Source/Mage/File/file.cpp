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


#include <stdio.h>
//#include <cstring>
#include <string.h>
#include "file.h"
#include "../Debug/assert.h"
#include "../Debug/trace.h"
#include "../Core/macros.h"


namespace Page
{
    // File operation mode.
    enum FileMode
    {
        None,                                      // No file operation has been performed yet!
        Normal,                                    // The user opens, reads, closes the file. User also can optionally use their read buffer.
        Simple,                                    // Simply calls load. Data is held within file until the file is deleted.
    };


    // Implementation data
    typedef struct FileImplementation
    {
        // Ctor
        FileImplementation() 
            : m_FileData(nullptr)
            , m_pFile(nullptr)
            , m_FileMode(FileMode::None)
            , m_Filesize(0xFFFFFFFF)
            , m_FilePointer(0)
            , m_Opened(false)
            , m_Loaded(false)
            , m_Locked(false)            
        {
            //inArchive = false;
         //   memset(filenameArch, 0, sizeof(filenameArch));
            memset(m_FilenameDisk, 0, sizeof(m_FilenameDisk));
           // memset(filenameOrig, 0, sizeof(filenameOrig));
        }

        // Dtor
        ~FileImplementation()
        {
            SAFE_DELETE(m_FileData);
        }

        // Checks for file errors.
        bool WasThereAFileError()
        {
            bool result = false;

            if (m_pFile)
            {
                if (ferror(m_pFile))
                {
                    //const char* message = strerror(errno);
            //        size_t errmsglen = strerrorlen_s(errno) + 1;

                    char buffer[256];
                    strerror_s(buffer, sizeof(buffer), errno);

                    clearerr(m_pFile);

                    Trace(LogLevel::Error, "%s\n", buffer);
                    //if (message && *message)
//                    {
                       // PRWARN(message);
  //                  }

                    result = true;
                }
            }

            return result;
        }

        // Data
        u8*         m_FileData;                               // Pointer to the files data.
        FILE*       m_pFile;                                  // Internal file use.
        FileMode    m_FileMode;                               // Mode of operation.
        u32         m_Filesize;                               // Files size.
        s32         m_FilePointer;                            // prFile position pointer
        bool        m_Opened;                                 // Has the file been opened with Open()
        bool        m_Loaded;                                 // Files loaded/unloaded state.
        bool        m_Locked;                                 // Files locked/unlocked state.    
        //bool        inArchive;                              // Is the file in the archive?
        //char        filenameArch[FILE_MAX_FILENAME_SIZE];   // The files name. (Archive)
        char        m_FilenameDisk[FILE_MAX_FILENAME_SIZE];   // The files name. (With system path added)
        //char        filenameOrig[FILE_MAX_FILENAME_SIZE];   // The files name. (Original unaltered)

    } FileImplementation;


    // Ctor
    File::File(const char* filename)
        : m_pImpl(new FileImplementation())
        , m_Imp(*m_pImpl)
    {
        ASSERT(m_pImpl);
        ASSERT(filename && *filename);
        ASSERT(strlen(filename) < FILE_MAX_FILENAME_SIZE);

        // Ensures name is long enough to skip past 'data/'
/*        PRASSERT(strlen(filename) > 5);

        // Ensures we have a filemanager
        prFileManager* pFM = static_cast<prFileManager*>(prCoreGetComponent(PRSYSTEM_FILEMANAGER));
        PRASSERT(pFM)//*/


        if (strlen(filename) < FILE_MAX_FILENAME_SIZE)
        {
            // Creates file names. One for the disk, one for the archive and keeps the original
/*                prStringCopySafe(imp.filenameArch, filename + 5, FILE_MAX_FILENAME_SIZE);
            prStringCopySafe(imp.filenameDisk, pFM->GetSystemPath(filename), FILE_MAX_FILENAME_SIZE);
            prStringCopySafe(imp.filenameOrig, filename, FILE_MAX_FILENAME_SIZE);

            // Must be lowercase
            prStringToLower(imp.filenameArch);

            // And use forward slashes
            prStringReplaceChar(imp.filenameArch, '\\', '/');
            prStringReplaceChar(imp.filenameDisk, '\\', '/');
            //*/
            //prTrace(LogError, "ARC: %s\n", imp.filenameArch);
            //prTrace(LogError, "DSK: %s\n", imp.filenameDisk);
            //prTrace(LogError, "DRI: %s\n", imp.filenameOrig);
        }
        else
        {
            //PRWARN("Filename was too long: %s", filename);
            //imp.filenameArch[0] = 0;
            //imp.filenameDisk[0] = 0;
            //imp.filenameOrig[0] = 0;
        }
    }


    // Dtor
    File::~File()
    {
        Close();
        SAFE_DELETE(m_pImpl);
    }


    // Method: Size
    //      Gets the size of the file.
    u32 File::Size() const
    { 
        ASSERT(m_pImpl);
        return m_pImpl->m_Filesize;
    }


    // Method: Exists
    //      Determines if the file exists
    bool File::Exists()
    {
        return false;
    }


    // Method: Open
    //      Opens a file for reading.
    bool File::Open()
    {
        return true;
    }


    // Method: Close
    //      Closes a file
    void File::Close()
    {
    }


    // Method: Read
    //      Reads data from an open file
    u32 File::Read(void* pDataBuffer, u32 size)
    {
        return 0;
    }


    // Method: Seek
    //      Seek within an open file.
    void File::Seek(s32 offset, s32 origin)
    {
    }


    // Method: Tell
    //      Returns the file pointers position.
    s32 File::Tell() const
    {
        return 0;
    }


    // Method: Rewind
    //      Sets the file pointer back to the start of the file.
    void File::Rewind()
    {
    }
}
