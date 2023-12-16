#pragma once
#include <list>

#include "../Day.h"

typedef long long aocNum;

struct RangeMap
{
    aocNum DestinationStart;
    aocNum SourceStart;
    aocNum RangeLength;

    aocNum Min;
    aocNum Max;
    
    void PushValue(aocNum value)
    {
        switch (idx)
        {
        case 0:
            DestinationStart = value;
            break;
        case 1:
            SourceStart = value;
            break;
        case 2:
            RangeLength = value;
            Max = DestinationStart + value;
            break;
        }

        idx++;
    }

private:
    int idx=0;
};

struct SeedRange
{
    aocNum SeedStart;
    aocNum SeedLength;

    aocNum Max;

    SeedRange(aocNum start, aocNum length)
    {
        SeedStart = start;
        SeedLength = length;

        Max = SeedStart+SeedLength;
    }
};

typedef std::list<RangeMap> range_map;

class Day5 : public Day
{
public:

    Day5(int dayNumber)
        : Day(dayNumber, get_file_reader()){}

    void Run() override;

private:
    inline void FindLocation(aocNum& location, const range_map& sector)const;
    inline void FindLocationR(aocNum& location, const range_map& sector) const;

    std::list<aocNum> seedNumbers{};
    std::list<SeedRange> seedRanges{};

    range_map seedToSoil{};
    range_map soilToFertiliser{};
    range_map fertToWater{};
    range_map waterToLight{};
    range_map lightToTemp{};
    range_map tempToHumidity{};
    range_map humidToLocation{};
    
};
