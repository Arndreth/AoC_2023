#pragma once
#include <string>

#include "../Interfaces/IFileReader.h"

class FileManager : public IFileReader
{
public:

    std::string GetFileContents(int dayNumber, bool testInput=false) const override;
    std::array<std::string, 1000> GetFileAsArray(int dayNumber, bool testInput=false) const override;
};
