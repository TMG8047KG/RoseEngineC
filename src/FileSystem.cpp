#include "RoseEngineC/FileSystem.h"

namespace RoseEngineC
{
    void FileSystem::saveCurrentPath()
    {
        gamePath = std::filesystem::absolute(std::filesystem::current_path());
    }

    void FileSystem::resetWorkingDirectory()
    {
        std::filesystem::current_path(gamePath);
    }

    void FileSystem::setWorkingDirectory(std::string &&path)
    {
        resetWorkingDirectory();
        std::filesystem::current_path(path);
    }

    std::filesystem::path FileSystem::gamePath;
}