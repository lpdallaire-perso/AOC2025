#include "Puzzle2.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

bool foundInvalidSequence(long long num)
{

	std::string s = std::to_string(num);
	size_t length = s.length();

	if (length % 2 != 0)
	{
		return false;
	}

	size_t half = length / 2;
	return s.substr(0, half) == s.substr(half, half);
}

void Puzzle2::Solve1()
{
	std::vector<std::pair<long long, long long>> ranges;
	std::ifstream inputFile("input2.txt");

	long long firstNumber;
	long long secondNumber;
	char separator1;
	char separator2;

	while (inputFile >> firstNumber >> separator1 >> secondNumber >> separator2)
	{
		ranges.push_back({ firstNumber, secondNumber });
	}

	long long finalCount = 0;

	for (auto& [start, end] : ranges) 
	{
		for (long long num = start; num <= end; num++) 
		{
			if (foundInvalidSequence(num))
			{
				finalCount += num;
			}
		}
	}

	std::cout << "Puzzle 2.1" << std::endl;
}

void Puzzle2::Solve2()
{
	std::cout << "Puzzle 2.2" << std::endl;
}