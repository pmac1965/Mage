#pragma once
#include "macros.h"


// Class: Singleton
//      Contains a simple singleton class for singletons that don't need to exist at startup.
template<typename T>
class Singleton
{
public:
    // Method: GetInstance
    //      Returns a reference to this instance.
    static T* GetInstance()
    {
        if (Instance() == nullptr)
        {
            SingletonCreate();
        }

        return Instance();
    }

    // Method: SingletonCreate
    //      Create the singleton.
    static void* SingletonCreate()
    {
        if (Instance() == nullptr)
        {
            Instance() = new T();
        }

        return Instance();
    }

    // Method: SingletonDestroy
    //      Destroy the singleton.
    static void SingletonDestroy()
    {
        SAFE_DELETE(Instance());
    }

    // Method: SingletonExists
    //      Determines if the singleton exists.
    static bool SingletonExists()
    {
        return (Instance() != nullptr);
    }

protected:
    // Method: Instance
    //      Returns a reference to this instance.
    static T*& Instance()
    {
        static T* instance = nullptr;
        return instance;
    }
};


// This macro protects a singleton from duplication.
#define MAKE_SINGLETON(cls)                                             \
private:                                                                \
    friend class Singleton<cls>;                                        \
                                                                        \
    /* Private ctor/dtor stops client from creating an instance. */     \
    cls();                                                              \
    ~cls();                                                             \
                                                                        \
    /* Stops passing by value and assignment. */                        \
    cls(const cls&);                                                    \
    const cls& operator = (const cls&);
