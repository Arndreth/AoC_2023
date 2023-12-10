#include "Day1.h"
#include "../Utils.h"
#include <array>

/*
The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover.
On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.
*/

void Day1::Run()
{
    auto contents = fileManager->GetFileAsArray(_day);

    // for each line of the code, check first and last digit.
    std::array<int, contents.size()> rawCalibrations{};
    int lineIndex = 0;
    
    for(const std::string& line: contents)
    {
        VALIDATE_LINE(line)
        const int size = static_cast<int>(line.size());        
        const char a = GetDigit(line, 0, 1);
        const char b = GetDigit(line,  size - 1, -1);
        
        std::string calibration = std::string() + a + b;
        rawCalibrations[lineIndex++] = std::stoi(calibration);
    }

    // go back a line
    --lineIndex;

    // do some fucking MATH
    int finalOutput = 0;
    while (lineIndex >= 0)
    {
        finalOutput += rawCalibrations[lineIndex];
        lineIndex--;
    }

    ReportAnswer("Calibration Value", finalOutput);    
}

char Day1::GetDigit(const std::string& line, const int start, const int direction)
{
    const int size = static_cast<int>(line.length());
    for (int i = start; i >= 0 && i < size; i += direction)
    {
        // part one
        if (isdigit(line[i]))
        {
            return line[i];
        }
        // part two

        std::map<std::string, char> wordMap
        {
            {"one", '1'},
            {"two", '2'},
            {"three", '3'},
            {"four", '4'},
            {"five", '5'},
            {"six", '6'},
            {"seven", '7'},
            {"eight", '8'},
            {"nine", '9'},
        };

        // substring
        int len = 3;
        for (; len <= 5; ++len)
        {
            const int sub = direction * len;
            if (i + sub >= 0 && i + sub <= size)
            {
                std::string test;
                if (direction > 0)
                {
                    test = line.substr(i, sub);
                }
                else
                {
                    test = line.substr(i-(abs(sub)-1), abs(sub));
                }
                
                if (wordMap.count(test) == 1)
                {
                    return wordMap[test];
                }
            }
        }        
        
    }

    return -1;
}
