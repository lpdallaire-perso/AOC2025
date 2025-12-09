#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Puzzle9.h"


void Puzzle9::Solve1()
{
    std::ifstream inputFile("input9.txt");
    std::vector<std::pair<long long, long long>> redTiles;
    std::string line;
    long long coord1, coord2;
    char separator;
    
    while (inputFile >> coord1 >> separator >> coord2)
    {
		redTiles.push_back({ coord1, coord2 });
    }

    long long maxArea = 0;
    
    for (size_t i = 0; i < redTiles.size(); i++) 
    {
        for (size_t j = i + 1; j < redTiles.size(); j++) 
        {
            long long x1 = redTiles[i].first;
            long long y1 = redTiles[i].second;
            long long x2 = redTiles[j].first;
            long long y2 = redTiles[j].second;

            long long area = (long long)(abs(x2 - x1) + 1) * (abs(y2 - y1) + 1);
            maxArea = std::max(maxArea, area);
        }
    }
    std::cout << "Puzzle 9.1: " << maxArea << std::endl;
}

void Puzzle9::Solve2()
{

    std::cout << "Puzzle 9.2: " << std::endl;

}
