#pragma once
#include <list>

#include "../Day.h"

struct PartNumber
{
    int PartValue = 0;
    int X = 0, Y = 0;
    int NumberSize = 0;
};

struct Gear
{
    int X = 0, Y = 0;
    std::list<PartNumber*> partNumbers = {};
};

typedef std::map<int,std::list<int>> symbol_map;

class Day3 : public Day
{
public:

    void Run() override;
    
    Day3(int dayNum)
        : Day(dayNum, get_file_reader()) {}


    void IsValid(PartNumber& pos, int& sum);

private:

    std::list<PartNumber*> partPositions=  {};

    symbol_map symbolMap = {};

    std::list<Gear*> gears = {};
};
