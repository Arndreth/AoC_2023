#include "Day3.h"

#include "../Utils.h"
#include <array>
#include <list>

void Day3::Run()
{
    const auto contents = fileManager->GetFileAsArray(_day);

    for (const std::string& line : contents)
    {
        VALIDATE_LINE(line)

        // map our numbers.
        int offset = static_cast<int>(line.find_first_not_of('.'));
        while (offset != std::string::npos)
        {
            if (offset == line.length())
                break;
            
            if (isdigit(line[offset]))
            {
                std::string temp = std::string();
                // find the number.
                auto* part = new PartNumber();

                do
                {
                    temp += line[offset++];
                    part->NumberSize++;
                } while (isdigit(line[offset]));
                
                int val = std::stoi(temp);
                part->X  = offset-1;
                part->Y = lineNumber;
                part->PartValue = val;
                partPositions.push_back(part);

                continue;
            }
            
            if (isascii(line[offset]))
            {
                // has to be a symbol - check for .
                if (line[offset] == '.')
                {
                    ++offset;
                    continue;
                }

                if (line[offset] == '*')
                {
                    // c'est une gear.
                    Gear* gear = new Gear();
                    gear->X = offset;
                    gear->Y = lineNumber;
                    gear->partNumbers = {};                    
                    gears.push_back(gear);
                }

                if (symbolMap.count(offset) == 0)
                {
                    symbolMap.insert(std::make_pair(offset, std::list<int>()));                    
                }

                symbolMap[offset].push_back(lineNumber);
            }            
            // valid.
            offset = static_cast<int>(line.find_first_not_of('.', ++offset));
            
        }        
        
    } // end contents for

    int sum = 0;
    // check through our valid part-numbers
    for (PartNumber* part : partPositions)
    {
        IsValid(*part, sum);        
    }
    ReportAnswer("Sum of Parts", sum);

    int gearRatio = 0;

    for (const Gear* gear : gears)
    {
        if (gear->partNumbers.size() == 2)
        {
            // valid baybeee
            int ratio = 1;
            for (const PartNumber* part : gear->partNumbers)
            {
                ratio *= part->PartValue;
            }

            gearRatio += ratio;
        }        
    }
    ReportAnswer("Gear Ratio", gearRatio);
}


void Day3::IsValid(PartNumber& pos, int& sum)
{
    // take our position, and find if a symbol has been mapped to a pos.
    int x = pos.X;
    int y = pos.Y;    

    for (x = pos.X - pos.NumberSize; x <= pos.X+1; ++x)
    {
        auto it = symbolMap.find(x);
        if (it == symbolMap.end()) continue;

        auto list = it->second;
        for (y = pos.Y - 1; y <= pos.Y+1; ++y)
        {
            auto find = std::find(list.begin(), list.end(), y);
            if (find != list.end())
            {
                sum += pos.PartValue;
                // is it a gear?
                for (Gear* gear : gears)
                {
                    if (gear->X == x && gear->Y == y)
                    {
                        gear->partNumbers.push_back(&pos);
                    }
                }
                return;
            }
            
        }
    }
}
