#ifndef DEBUG_H
#define DEBUG_H

#include "RoseEngineC/Log.h"

namespace RoseEngineC
{
    class Debug
    {
    public:
        //writes an error message to the console if condition is false
        inline static void assertNoAbort(bool &&condition, std::string &&message)
        {
        #ifndef NDEBUG
            if(!condition)
                Log::error(std::move(message));
        #endif
        }
    };
}

#endif