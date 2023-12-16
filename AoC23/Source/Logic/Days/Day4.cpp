#include "Day4.h"

#include "../Utils.h"


void Day4::Run()
{
    auto contents = fileManager->GetFileAsArray(_day);

    int totalScore = 0;
    int totalLines = 0;
    for (const std::string& line : contents)
    {
        VALIDATE_LINE(line)
        Cards[lineNumber-1] = new Card(lineNumber, line);
        totalLines++;
    }

    // process afterwards
    int finalCardCount = 0;
    for (int i = 0; i < totalLines; ++i)
    {
        int cardScore, cardCount;
        for (int page = 0; page < Cards[i]->CardCount; ++page)
        {
            Cards[i]->Score(cardScore, cardCount);
            if (cardCount == 0)continue;
            for (int win = 0; win < cardCount; ++win)
            {
                // Duplicate cards.
                Cards[i+win+1]->CardCount++;
            }
        }

        // we're done with this card, add it's tally.
        totalScore += cardScore;
        finalCardCount += Cards[i]->CardCount;
    }

    ReportAnswer("Score Cards", totalScore);
    ReportAnswer("Count of Cards", finalCardCount);
}
