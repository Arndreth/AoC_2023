#include "Day5.h"

#include <array>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <vector>

#include "../Utils.h"

using namespace std;

void Day5::Run()
{
    GET_FILE_ARRAY(false)
    range_map* activeMap = &seedToSoil;

    int mapOffset = -1;
    bool wantsToChangeMap = false;

    for (const auto& line: contents)
    {
        VALIDATE_LINE(line)
        
        // range mappings
        // get our seeds - first line        
        if (lineNumber == 1)
        {
            std::stringstream stream(line);
            std::string seed;
            std::vector<aocNum> tempSeeds{};
            while (getline(stream, seed, ' '))
            {
                if (!isdigit(seed[0])) continue;
                aocNum val = std::stoll(seed);                
                tempSeeds.push_back(val);                  
            }
            for (int i = 0; i < static_cast<int>(tempSeeds.size()); i+=2)
            {
                seedRanges.emplace_back(tempSeeds.at(i), tempSeeds.at(i+1));
            }
            continue;
        }

        wantsToChangeMap = !isdigit(line[0]);

        // keep going til we find our mappings and update activeMap;
        if (wantsToChangeMap)
        {
            mapOffset++;
            wantsToChangeMap = false;
            switch (mapOffset)
            {
            case 0: //"seed-to-soil map:":
                activeMap = &seedToSoil;
                continue;
            case 1:// "soil-to-fertilizer map:":
                activeMap = &soilToFertiliser;
                continue;
            case 2:// "fertilizer-to-water map:":
                activeMap = &fertToWater;
                continue;
            case 3://"water-to-light map:":
                activeMap = &waterToLight;
                continue;
            case 4://"light-to-temperature map:":
                activeMap = &lightToTemp;
                continue;
            case 5://"temperature-to-humidity map:":
                activeMap = &tempToHumidity;
                continue;
            case 6:// "humidity-to-location map:":
                activeMap = &humidToLocation;
                continue;
            default:            
                break;
            }
        }
        // process the line
        std::stringstream buffer(line);
        std::string idx;
        RangeMap map{};
        while (getline(buffer, idx, ' '))
        {
            map.PushValue(std::stoll(idx));
        }
        
        activeMap->push_back(map);   
    }
    // now go through our seeds.
    aocNum bestLocation = LONG_MAX;
    aocNum idx = -1;

    bool found = false;    
    while (!found)
    {
        // does the range fit into the next range.
        ++idx;
        aocNum location = idx;
        // right, here's the fun part.
        FindLocationR(location, humidToLocation);
        FindLocationR(location, tempToHumidity);
        FindLocationR(location, lightToTemp);
        FindLocationR(location, waterToLight);
        FindLocationR(location, fertToWater);
        FindLocationR(location, soilToFertiliser);
        FindLocationR(location, seedToSoil);

        for(const SeedRange& iter : seedRanges)
        {
            if (location >= iter.SeedStart && location <= iter.Max)
            {
                found = true;
                bestLocation = idx-1; // for some reason, this needs to go back 1 value.

                break;
            }
        }        
    }
    
    ReportAnswerLL("Best Location", bestLocation);    
}

inline void Day5::FindLocationR(aocNum& location, const range_map& sector) const
{
    for (const RangeMap& map : sector)
    {
        if (location >= map.DestinationStart && location <= map.Max)
        {            
            location = map.SourceStart + (location - map.DestinationStart);
            return;
        }
    }    
}
