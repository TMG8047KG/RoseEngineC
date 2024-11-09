#include "RoseEngineC/Log.h"
#include <iostream>

namespace RoseEngineC
{
    void Log::error(std::string &&message)
    {
        std::cout << "error : " << message << std::endl;
    }
}