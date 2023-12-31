﻿#pragma once
#include <iostream>
#include <map>
#include <memory>

#include "../Interfaces/IFileReader.h"

typedef std::map<std::string, class D> day_map; // fighter of the night_map

class Day
{
public:

    Day(int day, std::unique_ptr<IFileReader>&& file_man)
        : fileManager(std::move(file_man))
    {
        _day = day;
        // depending on logic, we run certain days.
    }

    virtual void Run() {}

protected:

    void ReportAnswer(const std::string& answerHeader, long answer) const;
    void ReportAnswerLL(const std::string& answerHeader, long long answer) const;

    int _day = -1;
    std::unique_ptr<IFileReader> fileManager;

    int lineNumber = 0;


};
