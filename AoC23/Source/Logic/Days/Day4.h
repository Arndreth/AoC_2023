#pragma once
#include <array>
#include <sstream>

#include "../Day.h"

#define PROCESS_NUMBERS(stream, outNumbers, num, idx) \
    idx = 0; \
    while (getline(stream, num, ' ')) \
    { \
        if (num.length() == 0) continue; \
        if (!isdigit(num[0])) continue; \
        outNumbers[idx]=(std::stoi(num)); \
        ++idx; \
    } \

    struct Card
    {
        int CardNumber;
        int CardCount = 1;
        std::array<int, 10> WinningNumbers;
        std::array<int, 25> MyNumbers{};


        Card(const int& cardNumber, const std::string& input)
        {
            CardNumber = cardNumber;

            const int index = static_cast<int>(input.find_first_of(':'));
            const int seperator = static_cast<int>(input.find_first_of('|'));
            auto temp = std::string();

            std::stringstream stream(input.substr(index+2, seperator-index-2));

            std::string num;
            int idx;
            PROCESS_NUMBERS(stream, WinningNumbers, num, idx)

            stream = std::stringstream(input.substr(seperator));
            PROCESS_NUMBERS(stream, MyNumbers, num, idx)
        
        }

        void Score(int& score, int& winningNumbers)        
        {
            score = 0;
            winningNumbers = 0;
            for (int winner : WinningNumbers)
            {
                if (std::find(MyNumbers.begin(), MyNumbers.end(), winner) != MyNumbers.end())
                {
                    
                    winningNumbers++;
                    if (score == 0)
                    {
                        score = 1;
                        continue;
                    }
                    score *= 2;
                }
            }

        }

        
    };

class Day4 : public Day
{
public:

    Day4(int dayNum)
        : Day(dayNum, get_file_reader()) {}

    void Run() override;

    Card* Cards[203];
    
};
