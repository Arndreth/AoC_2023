#include "FileManager.h"

#include <array>
#include <fstream>
#include <memory>

std::string FileManager::GetFileContents(int dayNumber, bool testInput) const
{
    std::ifstream inFile;

    std::string output;
    std::string path;

    if (testInput)
    {
        path = "DayInputs/Test/Day";
    }
    else
    {
        path = "DayInputs/Actual/Day";
    }
    inFile.open(path + std::to_string(dayNumber) + ".txt");
    while (inFile)
    {
        std::getline(inFile, output);
    }

    return output;
}

std::array<std::string, 1000> FileManager::GetFileAsArray(int dayNumber, bool testInput) const
{
    std::ifstream inFile;
    std::string path;
    if (testInput)
    {
        path = "DayInputs/Test/Day";
    }
    else
    {
        path = "DayInputs/Actual/Day";
    }
    
    std::array<std::string, 1000> output = {};
    std::string lineInput;
    
    inFile.open(path + std::to_string(dayNumber) + ".txt");
    int lineNumber = 0;
    
    while (inFile)
    {
        auto lineClean = std::string();
        std::getline(inFile, lineInput);

        // clean up any rogue chars from reading in input. Usually on first line but can't be sure.
        int i = 0;
        for (; i < static_cast<int>(lineInput.length()); ++i)
        {
            if (lineInput[i] >= ' ' && lineInput[i] <= '~') // ascii range.
            {
                lineClean += lineInput[i];
            }
        }
        if (lineClean.length() > 0)
        {
            output[lineNumber++] = lineClean;
            lineInput = "";
        }
    }

    return output;
}
