#include "Puzzle3.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void Puzzle3::Solve1()
{
	std::ifstream inputFile("input3.txt");

	std::string line;
	long long sum = 0;
	while (inputFile >> line)
	{
		int highPos1 = 0;
		int highPos2 = 0;
		const char* cLine = line.c_str();
		for (int i = 0; i < line.length()-1; i++) // find first highest number
		{
			if (cLine[i] > cLine[highPos1])
				highPos1 = i;
		}

		highPos2 = highPos1 + 1;

		for (int i = highPos2; i < line.length(); i++) // find first highest number
		{
			if (cLine[i] > cLine[highPos2])
				highPos2 = i;
		}

		std::string finalNumber{ cLine[highPos1] , cLine[highPos2] };
		sum += std::stoll(finalNumber);
	}

	std::cout << "Puzzle 3.1:" << sum << std::endl;
}

void Puzzle3::Solve2()
{
	std::ifstream inputFile("input3.txt");

	std::string line;
	long long sum = 0;
	const int cellSize = 12;
	

	while (inputFile >> line)
	{
		std::string finalNumber;
		int remainingNumbers = cellSize;
		int prevHighPos = 0;

		const char* cLine = line.c_str();
		
		for (int j = 0; j < cellSize; j++, remainingNumbers--)
		{
			int highPos = prevHighPos;

			for (int i = prevHighPos; i < line.length() - remainingNumbers + 1; i++)
			{
				if (cLine[i] > cLine[highPos])
					highPos = i;
			}
			finalNumber += cLine[highPos];
			prevHighPos = highPos + 1;
		}

		sum += std::stoll(finalNumber);
	}

	std::cout << "Puzzle 3.2:" << sum << std::endl;
}
