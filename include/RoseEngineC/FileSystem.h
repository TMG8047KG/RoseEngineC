#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <string>
#include <filesystem>

namespace RoseEngineC
{
    class FileSystem
    {
    public:
        //used during engine initialization to save the game's path
        static void saveCurrentPath();

        //sets the new working directory relative to the executable
        static void setWorkingDirectory(std::string &&path);

    private:
        //sets the executable path as the working directory
        static void resetWorkingDirectory();

        static std::filesystem::path gamePath;
    };
}

#endif 