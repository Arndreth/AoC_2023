#include <iostream>
#include "Source/Logic/Day.h"
#include "Source/Logic/FileManager.h"
#include "Source/Logic/Days/Day1.h"
#include "Source/Logic/Days/Day2.h"
#include "Source/Logic/Days/Day3.h"
#include "Source/Logic/Days/Day4.h"
#include "Source/Logic/Days/Day5.h"


std::unique_ptr<IFileReader> get_file_reader()
{
    return std::make_unique<FileManager>();
}


std::unique_ptr<Day> create_day(int day)
{
    switch (day)
    {
    case 1:    return std::make_unique<Day1>(day);
    case 2:    return std::make_unique<Day2>(day);
    case 3:    return std::make_unique<Day3>(day);
    case 4:    return std::make_unique<Day4>(day);
    case 5:    return std::make_unique<Day5>(day);
        // case 6:    return std::make_unique<Day1>(day);
        default: break;
    }

    return std::make_unique<Day>(day, get_file_reader());

}

int main(int argc, char* argv[])
{
    int dayNumber = -1;
    do
    {
        std::cout << "Enter a Day Number: ";
        std::cin >> dayNumber;
    } while (dayNumber == -1);

    // Get our day based on the day-number, or just create a new Day instance.
    const auto workingDay = create_day(dayNumber);

    workingDay->Run();
    

    std::cin >> dayNumber;
    std::cout << "\nHave a nice day!";
    
    return 0;
}

