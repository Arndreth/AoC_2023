#include <iostream>
#include "Source/Logic/Day.h"

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
    
    // Clean it up
    // delete workingDay;

    std::cout << "\nhave a nice day";
    
    return 0;
}
