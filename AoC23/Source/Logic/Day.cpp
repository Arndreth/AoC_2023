#include "Day.h"

#include "Days/Day1.h"
#include "Days/Day2.h"

void Day::Run()
{
    switch (_day)
    {
        
    }
    
}

void Day::ReportAnswer(const std::string& answerHeader, long answer) const
{
    std::cout << "\nDay -> " + std::to_string(_day) + "\nPart: " << answerHeader << "\nAnswer: " + std::to_string(answer);
}

std::unique_ptr<Day> create_day(int day)
{
    switch (day)
    {
    case 1:    return std::make_unique<Day1>(day);
    case 2:    return std::make_unique<Day2>(day);
    // case 3:    return std::make_unique<Day1>(day);1
    // case 4:    return std::make_unique<Day1>(day);
    // case 5:    return std::make_unique<Day1>(day);
    // case 6:    return std::make_unique<Day1>(day);
    default: break;
    }

    return std::make_unique<Day>(day, get_file_reader());

}
