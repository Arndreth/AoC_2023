#include "Day.h"

#include "Days/Day1.h"
#include "Days/Day2.h"
#include "Days/Day3.h"
#include "Days/Day4.h"
#include "Days/Day5.h"

void Day::ReportAnswer(const std::string& answerHeader, long answer) const
{
    std::cout << "\nDay -> " + std::to_string(_day) + "\nPart: " << answerHeader << "\nAnswer: " + std::to_string(answer);
}

void Day::ReportAnswerLL(const std::string& answerHeader, long long answer) const
{
    std::cout << "\nDay -> " + std::to_string(_day) + "\nPart: " << answerHeader << "\nAnswer: " + std::to_string(answer);
}

