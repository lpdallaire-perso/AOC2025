#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Puzzle5.h"

struct Range 
{
    long long start, end;
};

bool IsFresh(long long id, const std::vector<Range>& ranges)
{
    for (const auto& range : ranges) 
    {
        if (id >= range.start && id <= range.end) 
        {
            return true;
        }
    }
    return false;
}

void Puzzle5::Solve1() 
{
    std::ifstream input("input5.txt");
    
    std::vector<Range> freshRanges;
    std::vector<long long> availableIds;
    std::string line;
    bool rangesDone = false;

    while (getline(input, line)) 
    {
        if (line.empty()) // find the blank line
        {
            rangesDone = true;
            continue;
        }

        if (!rangesDone)
        {
            size_t dashPos = line.find('-');
            if (dashPos != std::string::npos)
            {
                long long start = std::stoll(line.substr(0, dashPos));
                long long end = std::stoll(line.substr(dashPos + 1));
                freshRanges.push_back({ start, end });
            }
        }
        else 
        {
            availableIds.push_back(stoll(line));
        }
    }

    long long freshCount = 0;
    for (long long id : availableIds) 
    {
        if (IsFresh(id, freshRanges)) 
        {
            freshCount++;
        }
    }

    std::cout << "Puzzle 5.1: " << freshCount << std::endl;

    return;
}

void Puzzle5::Solve2() 
{
    std::ifstream input("input5.txt");

    std::vector<Range> freshRanges;
    std::string line;


    while (getline(input, line)) 
    {
        if (line.empty()) 
        {
            break;
        }

        size_t dashPos = line.find('-');
        if (dashPos != std::string::npos)
        {
            long long start = std::stoll(line.substr(0, dashPos));
            long long end = std::stoll(line.substr(dashPos + 1));
            freshRanges.push_back({ start, end });
        }
    }


    sort(freshRanges.begin(), freshRanges.end(),
        [](const Range& a, const Range& b) { return a.start < b.start; });

    std::vector<Range> merged;
    for (const auto& range : freshRanges) 
    {
        if (merged.empty() || merged.back().end < range.start - 1) // no overlap
        {
            merged.push_back(range);
        }
        else // Overlap or adjacent
        {
            merged.back().end = std::max(merged.back().end, range.end);
        }
    }

    long long freshCount = 0;
    for (const auto& range : merged) 
    {
        freshCount += (range.end - range.start + 1);
    }

    std::cout << "Puzzle 5.2: " << freshCount << std::endl;
}