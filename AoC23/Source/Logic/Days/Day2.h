#pragma once
#include "../Day.h"

class Day2 : public Day
{
public:
    void Run() override;

    Day2(int day)
        : Day(day, get_file_reader())
    {
        
    }
};
