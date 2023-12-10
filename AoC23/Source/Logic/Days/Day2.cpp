
#include "../Utils.h"
#include "Day2.h"

#include <array>
#include <regex>
#include <sstream>

void Day2::Run()
{
    // line by line again
    const auto contents = fileManager->GetFileAsArray(_day);

    // find all the days that don't breach the following:
    // only 12 red cubes, 13 green cubes, and 14 blue cubes?

    int validSum = 0;
    long validPower = 0;
    int blue = 0, red = 0, green = 0;
    for(const std::string& line: contents)
    {
        VALIDATE_LINE(line)              
        // get game id
        const std::string gameContents = line.substr(line.find(':')+1);
        // split
        std::stringstream stream(gameContents);
        std::string bag;
        std::string choice;

        bool gameValid = true;

            blue = red = green = 0;

        while (getline(stream, bag, ';'))
        {
            // split into colours2
            std::stringstream bagstream(bag);
            
            while (getline(bagstream, choice, ','))
            {
                // start to whitespace is our count
                int count = std::stoi(choice.substr(0, choice.find_last_of(' ')));

                if (choice.find("blue") != std::string::npos)
                {
                    blue = std::max(count, blue);
                }
                if (choice.find("green") != std::string::npos)
                {
                    green = std::max(count, green);
                }
                if (choice.find("red") != std::string::npos)
                {
                    red = std::max(count, red);
                }            
                
                if (count > 14)
                {
                    gameValid = false;
                }                
                if (count > 13 && (choice.find("green") != std::string::npos || choice.find("red") != std::string::npos))
                {                   
                    gameValid = false;
                }
                if (count > 12 && choice.find("red") != std::string::npos)
                {                  
                    gameValid = false;
                }
            }
        }
        
        if (gameValid)
        {            
            validSum += lineNumber;
        }
        validPower += (red*blue*green);       
    }

    
    ReportAnswer("Part One", validSum);
    ReportAnswer("Part Two", validPower);
}

    
