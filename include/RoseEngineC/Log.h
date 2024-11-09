#ifndef LOG_H
#define LOG_H

#include <string>

namespace RoseEngineC
{
    class Log
    {
        public:
        static void error(std::string &&message);
    };
}

#endif 