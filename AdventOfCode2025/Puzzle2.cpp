#include "Puzzle2.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

bool findInvalidIDSplit2(long long num)
{
	std::string s = std::to_string(num);
	size_t numLength = s.length();

	if (numLength % 2 != 0) // can't be split in 2
	{
		return false;
	}

	size_t half = numLength / 2;
	return s.substr(0, half) == s.substr(half, half); // compare the 2 halved
}

bool findInvalidIDSplitN(long long num)
{
	std::string s = std::to_string(num);
	size_t numLength = s.length();

	for (size_t splitSize = 1; splitSize <= numLength / 2; splitSize++)
	{
		if (numLength % splitSize == 0) // can be spit into that size
		{
			std::string split = s.substr(0, splitSize);
			bool allMatch = true;

			size_t numParts = numLength / splitSize;
			for (int i = 1; i < numParts; i++)
			{
				if (s.substr(i * splitSize, splitSize) != split)
				{
					allMatch = false;
					break;
				}
			}

			if (allMatch)
			{
				return true;
			}
		}
	}

	return false;
}

void Puzzle2::Solve1()
{
	std::vector<std::pair<long long, long long>> ranges;
	std::ifstream inputFile("input2.txt");

	long long firstNumber;
	long long secondNumber;
	char separator1;
	char separator2;

	while (inputFile >> firstNumber >> separator1 >> secondNumber)
	{
		ranges.push_back({ firstNumber, secondNumber });
		inputFile >> separator2;
	}

	long long finalCount = 0;

	for (auto& [start, end] : ranges) 
	{
		for (long long num = start; num <= end; num++) 
		{
			if (findInvalidIDSplit2(num))
			{
				finalCount += num;
			}
		}
	}

	std::cout << "Puzzle 2.1" << std::endl;
}

void Puzzle2::Solve2()
{
	std::vector<std::pair<long long, long long>> ranges;
	std::ifstream inputFile("input2.txt");

	long long firstNumber;
	long long secondNumber;
	char separator1;
	char separator2;

	while (inputFile >> firstNumber >> separator1 >> secondNumber)
	{
		ranges.push_back({ firstNumber, secondNumber });
		inputFile >> separator2;
	}

	long long finalCount = 0;

	for (auto& [start, end] : ranges)
	{
		for (long long num = start; num <= end; num++)
		{
			if (findInvalidIDSplitN(num))
			{
				finalCount += num;
			}
		}
	}

	std::cout << "Puzzle 2.2" << std::endl;
}
