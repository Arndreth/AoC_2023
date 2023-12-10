#pragma once
#include "../Day.h"

class Day1 : public Day
{
public:
    void Run() override;
    static char GetDigit(const std::string& line, const int start, const int direction);

    Day1(int day)
        : Day(day, get_file_reader())
    {
        
    }
};
