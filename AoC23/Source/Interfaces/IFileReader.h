#pragma once
#include <memory>

struct IFileReader
{
protected:

public:
    virtual std::string GetFileContents(int dayNumber, bool testInput=false) const = 0;
    virtual std::array<std::string, 1000> GetFileAsArray(int dayNumber, bool testInput = false) const = 0;
};

std::unique_ptr<IFileReader> get_file_reader();
