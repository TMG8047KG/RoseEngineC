#include "RoseEngineC/FileSystem.h"
#include "RoseEngineC/Debug.h"

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
        std::error_code error;
        std::filesystem::current_path(path, error);
        Debug::assertNoAbort(!error, "FileSystem::setWorkingDirectory:: invalid path");
    }

    std::filesystem::path FileSystem::gamePath;
}